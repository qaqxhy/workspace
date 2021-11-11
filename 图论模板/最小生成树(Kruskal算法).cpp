/*算法流程：
1.将边按照权值从小到大排序
2.从小到大考察每条边(u,v):(贪心)
	若加入这条边之前，u和v已经属于同一个连通分量，则不选择该边
	若加入这条边之前，u和v不连通，则加入边(u,v)一定是最优的
3.当加入了V-1条边后，算法结束，得到最小生成树

贪心部分的证明：
	对于情况1：加入该边会形成一个环，不符合最小生成树条件，故不选择
	对于情况2：反证法，如果不加该边能得到更优解T，则T加上(u,v)一定会形成一个环，且T中至少有一条边(u',v')的权值大于(u,v)权值，删除(u',v')后得到的新结果不会比T差

连通分量的合并与查询：并查集优化

例题:Agri-net(JDFZOJ_1696,USACO3.1.1)*/
#include<cstdio>
#include<algorithm>
struct Vertex//只求MST无需建立完整的图
{
	Vertex *father;//并查集的父节点
	int size;//并查集的启发式合并
	Vertex():size(1){}
};
struct Edge
{
	Vertex *from,*to;
	int weight;
	bool operator < (const Edge &s)const
	{
		return weight<s.weight;
	}
};
const int Vmax=101;
struct Kruskal
{
	Vertex V[Vmax];
	Edge E[(Vmax*(Vmax-1))>>1];
	int N,ans,cnt,Vn;//分别为边数，最终答案，已经加入的边数，点数
	void read(int n)//例题中，将邻接矩阵转换为边目录
	{
		N=0,Vn=n;int t;
		for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                scanf("%d",&t);
                if(i>j&&t)
                {
                    E[N].weight=t;
                    E[N].from=V+i;
                    E[N++].to=V+j;
                }
            }
	}
	Vertex* find(Vertex *p)//并查集查找函数
    {
        Vertex *root=p;
        while(root->father!=NULL&&root->father!=root)
            root=root->father;
        while(root!=p)
        {
            Vertex *tmp=p->father;
            p->father=root;
            p=tmp;
        }
        return root;
    }
    bool Union(Vertex *A,Vertex *B)//并查集合并函数，两点在同一连通分量返回false,否则返回true
    {
        Vertex *pA=find(A);
        Vertex *pB=find(B);
        if(pA==pB)return false;
        if(pA->size > pB->size)//启发式合并
        {
            pB->father=pA;
            pA->size+=pB->size;
        }
        else
        {
            pA->father=pB;
            pB->size+=pA->size;
        }
        return true;
    }
    void work()
    {
        ans=0;cnt=1;
        std::sort(E,E+N);
        for(int i=0;cnt<Vn&&i<N;++i)//考察每条边
        {
            if(Union(E[i].from,E[i].to))//两点不在一个连通分量中
            {
                ans+=E[i].weight;++cnt;//加入该边到结果树中
            }
        }
    }
    bool isMST(){return cnt==Vn;}//如需要可判断是否能构成一个MST
}K;
int main()
{
    int n;
    scanf("%d",&n);
    K.read(n);
    K.work();
    printf("%d",K.ans);
}

/*补充习题：VIJOS-P1045，JDFZOJ_1229 Kerry 的电缆网络
			VIJOS-P1234，JDFZOJ_1374 口袋的天空
			JDFZOJ_1044 Span
			JDFZOJ_1726 最小生成树*/
            
//JDFZOJ_1229 Kerry 的电缆网络
#include <bits/stdc++.h>
#define N 100100
using namespace std;
int fa[N], cnt;
int head[N];
double ans = 0;
struct node
{
    int be;
    int ed;
    double len;
} city[N];
double n;
int m;
int cmp(node a, node b)
{
    return a.len < b.len;
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int merge(int i, int j)
{
    fa[find(i)] = find(j);
}
int main()
{

    scanf("%lf%d", &n, &m);
    init(m);
    int a = 0, b = 0;
    double f = 0;
    while (scanf("%d%d%lf", &a, &b, &f) != EOF)
    {
        cnt++;
        city[cnt].be = a, city[cnt].ed = b, city[cnt].len = f;
    }
    sort(city + 1, city + cnt + 1, cmp);
    int edge = 0; //已经加进去的边数
    for (int i = 1; i <= cnt; i++)
    {
        int fbe = find(city[i].be);
        int fed = find(city[i].ed);
        if(fed!=fbe)//两个端点都没有被用过
        {
            merge(city[i].be, city[i].ed); //合并(标记用过)
            edge++;
            ans += city[i].len; // 长度加上去(加边) 最后要和线缆长度比较
        }
        if (edge == m - 1) //不能再加了
        {
            break;
        }
    }
    if (ans <= n && edge == m - 1) //只有e=v-1时才是MST
    {
        printf("Need %.2lf miles of cable", ans);
    }
    else
        printf("Impossible");
    return 0;
}