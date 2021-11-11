//头文件:#include<queue>
//case 1:邻接矩阵
void bfs(int v)
{
	queue<int> Q;
	Q.push(v);
	marked[v]=true;
	while(!Q.empty())
	{
		int x=Q.front();//当前点
		Q.pop();
		printf("%d ",x);
		for(int j=1;j<=N;++j)//枚举该点能到达的点
		{
			if(G[x][j] && !marked[j])//两点间有边，且终点没有被遍历过
			{
				Q.push(j);
				marked[j]=true;
			}
		}
	}
}
//统计连通分量:同DFS，将调用DFS(i)改为调用BFS(i)即可

//case 2:邻接链表
void bfs(Vertex *v)
{
	queue<Vertex*> Q;//指针队列，便于修改点的数据而不影响队列
	Q.push(v);
	v->marked=true;
	while(!Q.empty())
	{
		Vertex *x=Q.front();//当前点
		Q.pop();
		printf("%d ",x.Num);
		for(Edge *e=x->next;e;e=e->next)//枚举该点下面的边
		{
			if(!e->to->marked)
			{
				Q.push(e->to);
				e->to->marked=true;
			}
		}
	}
}
//统计连通分量:同上
