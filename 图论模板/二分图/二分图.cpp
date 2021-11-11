/*二分图定义：设G=(V,E)是一个无向图，如果顶点V可分割为两个互不相交的子集(A,B)，并且图中的每条边（i，j）所关联的两个顶点i和j分别属于这两个不同的顶点集(i in A,j in B)，则称图G为一个二分图。
无向图G为二分图的充要条件：G至少有两个顶点，且其所有回路的长度均为偶数
二分图判定：利用DFS进行二染色，相邻两个点染成不同的颜色，如果某一时刻发现一个点既可以染成黑色又可以染成白色，则G不是二分图*/

//例题：NOIP2010,JDFZOJ_1711 关押罪犯(二分答案+二分图判断)
#include<cstdio>
#include<cstring>
#include<algorithm>
struct Edge;
struct Vertex
{
    Edge *next;
    bool marked,color;//marked是否被染过色，color为当前的颜色
}V[20002];
struct Edge
{
    Vertex *to;
    Edge *next;
    Edge(Vertex *_to,Edge *_next):to(_to),next(_next){}
    Edge(){}
    void* operator new(size_t);
}E[200004];
Edge *P=E;
void* Edge::operator new(size_t)
{
    return P++;
}
inline void addEdge(Vertex *A,Vertex *B)
{
    A->next=new Edge(B,A->next);
    B->next=new Edge(A,B->next);
}
struct Anger
{
    int a,b,ang;
    void read()
    {
        scanf("%d%d%d",&a,&b,&ang);
    }
    bool operator < (const Anger &s)const
    {
        return ang>s.ang;
    }
}anger[200004];
bool isTwoColorAble=true;//是不是二分图
void dfs(Vertex *v)
{
    v->marked=true;
    for(Edge *e=v->next;e;e=e->next)
    {
        if(!e->to->marked)
        {
            e->to->color=!(v->color);//点a能通到点b，则应将b染成与a不同的颜色
            dfs(e->to);
        }
        else if(e->to->color==v->color)//颜色冲突
            isTwoColorAble=false;//不是二分图
    }
}
int main()
{
	/*将题中给定的边按照怒气值大小排序，可以发现，如果选择一条边，把所有比这条边权值大的边构建成一张图，能构成一个二分图则这个方案是可行的，不会引起冲突。而当选择一条边会导致构不成二分图(发生冲突)，则该边的权值就是答案，如果把所有的边建到一个图中，仍能保证构成二分图，则本年内没有任何冲突事件
	在选择出答案之前，能构成二分图；而当加入答案的那条边后，就构不成二分图，单调递减，符合二分答案的特点。
	二分图的特点：顶点集分割成的两个子集里面的点不互相连通，不会搞基。正符合两个监狱的性质。*/
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;++i)//读入边
        anger[i].read();
    std::sort(anger+1,anger+1+M);//权值大的排在前面
    int l=1,r=M,mid=(l+r)>>1;//二分答案的模板
    while(l<r)
    {
        for(int i=1;i<mid;++i)//每次选定一个中间值之后都重新构图
            addEdge(V+anger[i].a,V+anger[i].b);//两人积怨，则在这两人间连上一条边，表示二人不能同居
        for(int i=1;i<=N;++i)//DFS染色
            if(!V[i].marked)
                dfs(V+i);
        if(isTwoColorAble)l=mid+1;//能构成二分图
        else r=mid;//不能构成二分图
        mid=(l+r)>>1;
        memset(V,0,sizeof(V));
        P=E;isTwoColorAble=true;//清空原来的图
    }
    if(mid<M)printf("%d\n",anger[mid-1].ang);//有冲突
    else puts("0");//没有冲突
}
