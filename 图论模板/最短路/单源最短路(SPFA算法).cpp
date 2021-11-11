/*算法流程：
1.设立一个队列，保存待优化的节点，起点入队
2.每次取出队首元素u进行如下操作：
	用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作
	如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾
3.队列为空时最短路计算完毕

判断负环：一个点进入队列的次数超过N次则存在负环
	(存在负环则无最短路径，如果有负环则会无限松弛，而一个带N个点的图至多松弛N-1次)
	
期望时间复杂度：O(kE)，k为所有顶点进队的平均次数，一般小于等于2*/

//例题：VIJOS-P1053,JDFZOJ_1235 Easy sssp(原题爆int)
#include<cstdio>
#include<queue>
int n,m,beginP;
struct Edge;
struct Vertex
{
    int ti,dis,Num;//判断负环所需的入队次数统计，最短路长度
    bool isinQ,visited,canprint;//是否在队列中，是否被访问过，是否存在从起点到该点的最短路
    Edge *next;
    Vertex();
}V[1003];
Vertex::Vertex()
{
	dis=0x3f3f3f3f;
	Num=this-V;
}
struct Edge
{
    Vertex *to;
    Edge *next;
    int weight;
    Edge(Vertex *_to,Edge *_next,int _w)
    {to=_to,next=_next,weight=_w;}
    Edge(){}
    void* operator new(size_t);
}E[100003];
void* Edge::operator new(size_t)
{
    static Edge *P=E;
    return P++;
}
void addEdge(Vertex *A,Vertex *B,int w)
{
    A->next=new Edge(B,A->next,w);
}
bool spfa(Vertex *begin)//本题中函数返回布尔，返回true表示有负环
{
    std::queue<Vertex*> Q;
    begin->isinQ=true;
    begin->dis=0;
    Q.push(begin);
    while(!Q.empty())
    {
        Vertex *v=Q.front();
        Q.pop();
        v->isinQ=false;
        for(Edge *e=v->next;e;e=e->next)
            if(e->to->dis > v->dis+e->weight)//该点的最短路需要更新(有更优解)
            {
                e->to->dis=v->dis+e->weight;//更新
                ++e->to->ti;//更新次数+1(本题需要)
                e->to->visited=true;//一次SPFA已遍历过该点(本题需要)
                if(begin->Num==beginP)e->to->canprint=true;//如果本次SPFA计算的是题中给定的原点的最短路，则该点可以输出(本题需要)
                if(e->to->ti>n)return true;//发现负环(本题需要)
                if(!e->to->isinQ)Q.push(e->to),e->to->isinQ=true;//重新入队
            }
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&n,&m,&beginP);//点数，边数，原点
    int a,b,c;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        addEdge(V+a,V+b,c);
    }
    if(spfa(V+beginP))//原点所在连通分量有负环
    	{puts("-1");return 0;}
    for(int i=1;i<=n;++i)//对原点所在连通分量之外的，其他的连通分量用SPFA判负环
        if(!V[i].visited)
            if(spfa(V+i))//其他点所在连通分量有负环
            	{puts("-1");return 0;}
    V[beginP].canprint=true;
    for(int i=1;i<=n;++i)
   		if(V[i].canprint)//与原点同属一个连通分量
    		printf("%d\n",V[i].dis);
    	else puts("NoPath");//与原点在不同连通分量
}

/*补充习题：
VIJOS-P1391,JDFZOJ_1489 想越狱的小杉
VIJOS-P1635,JDFZOJ_1594 城市连接
NOIP2012普及组,VIJOS-P1794,JDFZOJ_1788 文化之旅
NOIP2001提高组,VIJOS-P1119,JDFZOJ_1288 CAR的旅行路线
