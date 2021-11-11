/*匹配的定义：
匹配:给定一个二分图G，在G的一个子图M中，M的边集中的任意两条边都不依附于同一个顶点，则称M是一个匹配。
最大匹配:图中包含边数最多的匹配称为图的最大匹配。
完美匹配:如果所有点都在匹配边上，称这个最大匹配为完美匹配。
二分图最大匹配的三个定理:
	1.最大匹配数+最大独立集数=n
	2.二分图的最小覆盖数=最大匹配数
	3.最小路径覆盖=最大独立集
最大独立集是指求一个二分图中最大的一个点集，该点集内的点互不相连。
最小顶点覆盖是指在二分图中，用最少的点，让所有的边至少和一个点有关联。
最小路径覆盖是指一个不含圈的有向图G中，G的一个路径覆盖是一个其结点不相交的路径集合P，图中的每一个结点仅包含于P中的某一条路径。路径可以从任意结点开始和结束，且长度也为任意值，包括0。

增广路(交错路)：增广路是一条由图中的边组成的路径，它的第一条边没有参与匹配，第二条边参与匹配，第三条边没有参与匹配……以此类推，最后一条边没有参与匹配，保证起点和终点没有在匹配中。
	通过增广路定义可知(设当前的匹配为M，增广路为P)：
		1.P的路径长度一定是奇数，第一条边和最后一条边都不属于M
		2.P取反能够得到一个更优的匹配M'
		3.M为G的最大匹配：当且仅当不存在相对于M的增广路

匈牙利算法：枚举二分图两部分中某一部分的节点，以该点为起点寻找增广路，该部分点找完之后得到最大匹配数
	时间复杂度：O(VE)
算法流程：
	1.依次从二分图的一个部分寻找增广路
	2.查找从这个点出发有没有增广路，如果有，则更新匹配数并换点继续查找，如果没有，则换下一个点继续查找
	3.如果已经遍历完这部分的点则结束*/

//例题：USACO4.2.2,JDFZOJ_1818 The Perfect Stall 完美的牛栏
#include<cstdio>
#include<cstring>
const int MAXV=402,MAXE=40002;
bool marked[MAXV];
int n,m,mat[MAXV];//mat[i]:记录增广路
struct Edge;
struct Vertex
{
	Edge *next;
}V[MAXV];
struct Edge
{
	Vertex *to;
	Edge *next;
	Edge(Vertex *_to,Edge *_next):to(_to),next(_next){}
	Edge(){}
	void* operator new(size_t);
}E[MAXE];
void* Edge::operator new(size_t)
{
	static Edge *P=E;
	return P++;
}
void addEdge(Vertex *A,Vertex *B)
{
	A->next=new Edge(B,A->next);
}
void BuildGraph()//建图
{
	scanf("%d%d",&n,&m);
	int cnt,a;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;++j)
		{
			scanf("%d",&a);
			addEdge(V+i,V+a);
		}
	}
}
bool crosspath(Vertex *v)
{
	for(Edge *e=v->next;e;e=e->next)//从该点找增广路
	{
		int e_to=e->to-V;//这条边指向的点的数组编号
		int &mto=mat[e_to];//记录增广路，定义成引用以方便修改
		if(!marked[e_to])
		{
			marked[e_to]=true;
			if(!mto || crosspath(V+mto))//e->to未匹配 或 从e->to出发有增广路
			{
				mto=v-V;//修改e->to对应项为v
				return true;
			}
		}
	}
	return false;
}
int Hungary()//返回最大匹配数
{
	int cnt=0;
	for(int i=1;i<=n;++i)//从点集n中的每个点寻找增广路
	{
		if(crosspath(V+i))//有增广路
			++cnt;
		memset(marked,0,sizeof(marked));//将标记数组清零以便下次寻找
	}
	return cnt;
}
int main()
{
	BuildGraph();
	printf("%d\n",Hungary());
}
