/*Dijkstra算法：利用贪心算法，求解单源最短路，适用于没有负权边的图
算法思想：设置一个顶点的集合S,并不断地扩充这个集合,当且仅当从源点到某个点的路径已求出时它才属于集合S。开始时S中仅有源点,调整非S中点的最短路径长度,找当前最短路径点,将其加入到集合S,直到所有的点都在S中。
朴素算法时间复杂度：O(n^2)
堆优化的算法代码较复杂，请写SPFA*/

//例题：VIJOS-P1635,JDFZOJ_1594 城市连接
#include<cstdio>
#include<cstring>
const int Vmax=1001;
const int inf=0X3F3F3F3F;
bool used[Vmax];//哪些节点的最短路已经计算完毕
int G[Vmax][Vmax];//邻接矩阵
int dis[Vmax];//最短路长度
int prev[Vmax];//记录最短路径是什么(本题需要)
inline int min(int a,int b){return a>b?b:a;}
void print(int N)//递归输出最短路
{
    if(N==0)return;
    print(prev[N]);
    printf("%d ",N);
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    for(int j=1;j<=N;++j)
    scanf("%d",G[i]+j);
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<N;++i)
    {
        int tmp=0;
        for(int j=1;j<=N;++j)//在所有未被标号的节点中，选择一个dis值最小的点tmp
        if(!used[j] && dis[j] < dis[tmp])tmp=j;
        used[tmp]=1;
        for(int j=1;j<=N;j++)//对于所有从tmp出发的边(tmp,j)，更新一下dis[j]
        {
            if(G[tmp][j] && dis[j]>dis[tmp]+G[tmp][j])
            {
                dis[j]=dis[tmp]+G[tmp][j];
                prev[j]=tmp;//j点的最短路是从tmp走过来的
            }
        }
    }
    print(N);puts("");
    printf("%d\n",dis[N]);
    return 0;
}
