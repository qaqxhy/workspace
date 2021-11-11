#include<cstdio>

const int MAXV=10000;

bool G[MAXV][MAXV];//邻接矩阵,如需要保存权值则将数组类型变为int

int main()
{
	//多组数据的处理:G数组清零即可
	/*邻接矩阵加边：
		有向边A指向B:G[A][B]=weight;
		无向图:G[A][B]=G[B][A]=weight;*/
	//找到两点间的边的权值:G[A][B]
	//删边:G[A][B]=0
	return 0;
}
