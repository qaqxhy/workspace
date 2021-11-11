/*该算法可计算有向图的强连通分量(SCC)，并收缩强连通分量
算法进行了一次DFS，维护了一个栈，效率高于两遍DFS的Kosaraju
基于对图深度优先搜索的算法，每个强连通分量为搜索树中的一棵子树
搜索时，把当前搜索树中未处理的节点加入一个堆栈，回溯时可以判断栈顶到栈中的节点是否为一个强连通分量
算法流程详见https://www.byvoid.com/zhs/blog/scc-tarjan/

例题：JDFZOJ_1076 受欢迎的牛*/
#include<cstdio>
inline int min(int a,int b){return a<b?a:b;}
const int MAXV=10002,MAXE=50002;
int n,m,stackp,Index,count;//stackp:栈大小，Index:出栈顺序，count强连通图的数目
int SCC[MAXV];
struct Edge;
struct Vertex
{
	Edge *next;
	bool marked,isinS;
	int DFN,LOW;//DFN时间戳，LOW该点或该点的子树能追溯到的最早的栈中节点的时间戳
}V[MAXV],*S[MAXV];//S是一只栈
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
	int a,b;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		addEdge(V+a,V+b);
	}
}
void Tarjan(Vertex *p)
{
	p->marked=true;
	p->isinS=true;
	S[++stackp]=p;//当前点入栈
	p->DFN=p->LOW=++Index;//更新当前点次序
	for(Edge *e=p->next;e;e=e->next)
	{
		if(!e->to->marked)//遍历该点子树
		{
			Tarjan(e->to);
			p->LOW=min(p->LOW,e->to->LOW);//当前点的子树更新完毕后需更新当前点的LOW值
		}
		else if(e->to->isinS)//发现环路
		{
			p->LOW=min(p->LOW,e->to->DFN);//LOW可能被更新为后向边的时间戳
		}
	}
	if(p->DFN==p->LOW)//拿出强连通分量
	{
		++count;
		do//弹出栈直到算完一个强连通分量
		{
			SCC[S[stackp]-V]=count;
			S[stackp]->isinS=false;
		}
		while(S[stackp--]!=p);
	}
}
int OutDegree[MAXV];
int main()
{
	BuildGraph();
	for(int i=1;i<=n;++i)
		if(!V[i].marked)Tarjan(V+i);
	for(int i=1;i<=n;++i)//统计强连通子图出度
		for(Edge *e=V[i].next;e;e=e->next)
			if(SCC[i]!=SCC[e->to-V])
				++OutDegree[SCC[i]];
	int ans=0;
    for(int i=1;i<=count;++i)//考察缩点后所有的SCC，统计出度
        if(!OutDegree[i])//某点出度为0
        {
            if(ans){puts("0");return 0;}//多个点出度为0则无解
            else for(int j=1;j<=n;++j)
					if(SCC[j]==i)++ans;//该SCC中包含几个点
        }
    printf("%d\n",ans);
}
