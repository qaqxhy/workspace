/*该算法可计算有向图的强连通分量(SCC)，并收缩强连通分量
该算法运用了原图G和反图G'，两次DFS得到结果，容易理解，效率相比Tarjan,Gabow较低
算法思路：
	1.对原图进行DFS遍历所有点，形成搜索树或森林，记录每一个点的出栈时间(其实就是拓扑序)
	2.所有边反向，构建反图G'
	3.每次选择原图中出栈时间最大的点为起点进行DFS，每次DFS都删去遍历到的点，一次DFS计算出一个SCC，所有点都被DFS过则计算完毕
算法隐藏性质：如果我们把求出来的每个SCC收缩成一个点,并且用求出每个SCC的顺序来标记收缩后的结点,那么这个顺序其实就是SCC收缩成点后形成的DAG的拓扑序列。*/

//例题：JDFZOJ_1076 受欢迎的牛
#include<cstdio>
#include<cstring>
const int MAXV=10002,MAXE=100002;
int n,m;//点数，边数
bool marked[MAXV];//DFS中，记录每个节点是否被访问
int SCC[MAXV],DFN[MAXV];//SCC[i]:编号为i的点属于scc[i]号强连通分量，DFN[i]:离开时间为i的点
int cntSCC[MAXV];//cntSCC[i]:i号强连通分量对应几个点
struct Edge;
struct Vertex
{
	Edge *next;
}V1[MAXV],V2[MAXV];//V1为正图，V2为反图
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
inline void addEdge(Vertex *A,Vertex *B)
{
	A->next=new Edge(B,A->next);
}
void BuildGraph()
{
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		addEdge(V1+a,V1+b);//建正图
		addEdge(V2+b,V2+a);//建反图
	}
}
void dfs1(int v,int &sig)//正图DFS，求解DFN
{
	marked[v]=true;
	for(Edge *e=V1[v].next;e;e=e->next)
		if(!marked[e->to-V1])
			dfs1(e->to-V1,sig);
	DFN[++sig]=v;//统计出栈顺序
}
void dfs2(int v,int sig)//反图DFS，求解SCC
{
	marked[v]=true;
	SCC[v]=sig;//当前点属于sig号SCC
	++cntSCC[sig];//该SCC所包含的点的个数++
	for(Edge *e=V2[v].next;e;e=e->next)
		if(!marked[e->to-V2])
			dfs2(e->to-V2,sig);
}
int Kosaraju()//Kosaraju()返回强连通分量个数
{
	int sigma=0;//sigma表示时间戳
	memset(marked,0,sizeof(marked));
	for(int i=1;i<=n;++i)
		if(!marked[i])
			dfs1(i,sigma);//DFS第i号点，时间戳已经标记到了sigma
	memset(marked,0,sizeof(marked));
	sigma=0;//sigma表示已知的SCC个数
	for(int i=n;i>=1;--i)//按出栈顺序做第二遍DFS
		if(!marked[DFN[i]])
			dfs2(DFN[i],++sigma);//从剩余的点中时间戳最大的点DFS，统计到了第sigma个SCC
	return sigma;
}
int OutDegree[MAXV];//本题中统计每个SCC的出度
int main()
{
	BuildGraph();
	int count=Kosaraju();//SCC个数
	for(int i=1;i<=n;++i)//统计强连通子图出度
	{
		for(Edge *e=V1[i].next;e;e=e->next)
		{
			if(SCC[i]!=SCC[e->to-V1])
				++OutDegree[SCC[i]];
		}
	}
	int ans=0;
	for(int i=1;i<=count;++i)//考察缩点后所有的SCC
	{
		if(!OutDegree[i])//某点出度为0
		{
			if(ans){puts("0");return 0;}//多个点出度为0则无解
			else ans+=cntSCC[i];//该SCC中包含几个点
		}
	}
	printf("%d\n",ans);
}

//补充习题：USACO5.3.3,JDFZOJ_1833 Network of Schools 校园网
