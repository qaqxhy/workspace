/*Floyd算法为动态规划算法，用以求解每两点间的最短路
状态表示：f[i][j]:从点i到点j的最短距离
状态转移方程：f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
时间复杂度：O(n^3)，适用于几百个点的图*/
/*核心代码：(请熟读背诵)
for(int k=1;k<=N;++k)
for(int i=1;i<=N;++i)
for(int j=1;j<=N;++j)
G[i][j]=min(G[i][j],G[i][k]+G[k][j]);*/

//例题：USACO2.4.4 JDFZOJ_1691 Bessie Come Home
#include <cctype>
#include <cstdio>
#include <cstring>
int G[100][100];
bool havecow[100]; //某农场中是否有牛
int main()
{
	memset(G, 0x3f, sizeof(G));
	char str1[10], str2[10];
	int n, a, b, e;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) //处理读入数据，加边
	{
		scanf("%s%s%d", str1, str2, &a);
		if (isupper(*str1))
			havecow[*str1 - 'A'] = true;
		if (isupper(*str2))
			havecow[*str2 - 'A'] = true;
		b = *str1 - 'A';
		e = *str2 - 'A';
		if (G[b][e] > a)
			G[b][e] = G[e][b] = a; //处理平行边
	}
	havecow[25] = false;		  //题中的Z号牧场
	for (int k = 0; k < 100; ++k) //Floyd核心部分，一定将k写在最外层！！！！！！
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				if (G[i][k] + G[k][j] < G[i][j])
					G[i][j] = G[i][k] + G[k][j];
	int max = 0x7f7f7f7f, which;
	for (int i = 0; i < 100; ++i) //查询Z点到每一个有牛的牧场的最短路
		if (G[i][25] < max && havecow[i])
			max = G[i][25], which = i;
	printf("%c %d\n", which + 'A', max);
}

/*有向图的传递闭包
	定义：预处理之后，用O(1)时间复杂度查找一点到另一点是否存在通路(算出任意两点连通性)
	算法：Floyd,O(n^3)*/
bool f[MAXV][MAXV];			 //f[i][j]==true:i点到j点间存在通路
for (int i = 1; i <= N; ++i) //读图时预处理f数组
	for (int j = 1; j <= N; ++j)
		scanf("%d", G[i] + j), f[i][j] = (G[i][j] != INF);
for (int k = 1; k <= N; ++k)
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			f[i][j] = f[i][j] || (f[i][k] && f[k][j]);

//Floyd求最小环
/*算法思想; 
	Floyd算法是按照顶点的编号增加的顺序更新最短路径的; 
	如果存在最小环,则会在这个环中的点编号最大的那个点k更新最短路径之前发现这个环; 
	即当点k被拿来更新i到j的最短路径的时候,可以发现这个闭合环路; 
	发现的方法是,更新最短路径前,遍历i,j点对,一定会发现某对i到j的最短路径长度: 
	dis[i][j]+G[j][k]+G[k][i]!=INF,这时i和j是当前环中挨着点k的两个点; 
	因为在之前的最短路径更新过程中,k没有参与更新,所以dis[i][j]所表示的路径中不会有点k,即一定为一个环; 

	如果在每个新的点拿来更新最短路径之前遍历i和j验证上面的式子,虽然不能遍历到所有的环; 
	但是由于dis[i][j]是i到j点的最短路径m所以肯定可以遍历到最小的环; 

	如果有负权环,则该算法失效,因为包含负环的图上,dis[i][j]已经不能保证i到j的路径上不会经过同一个点多次了; */
//例题：VIJOS-P1046，JDFZOJ_1230 观光旅游
#include <cstdio>
#include <cstring>
int G[102][102], dis[102][102];
int main()
{
	int n, m, a, b, c, ans;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(G, 0x1f, sizeof(G));
		for (int i = 1; i <= m; ++i) //读图部分
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = G[b][a] = c;
		}
		for (int i = 1; i <= n; ++i)
			G[i][i] = 0;
		for (int i = 1; i <= n; ++i) //预处理dis
			for (int j = 1; j <= n; ++j)
				dis[i][j] = G[i][j];
		ans = 0x1f1f1f1f;			 //ans=INF
		for (int k = 1; k <= n; ++k) //在最外层循环做了k-1次之后，dis[i][j]则代表了i到j的路径中，所有结点编号都小于k的最短路径
		{
			for (int i = 1; i < k; ++i)
				for (int j = 1; j < i; ++j)
					if (dis[i][j] + G[i][k] + G[k][j] < ans)
						ans = dis[i][j] + G[i][k] + G[k][j];
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];
		}
		if (ans != 0x1f1f1f1f)
			printf("%d\n", ans);
		else
			puts("No solution.");
	}
}
