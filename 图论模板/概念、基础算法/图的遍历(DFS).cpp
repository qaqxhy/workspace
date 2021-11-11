//case 1:邻接矩阵
bool marked[MAXV];//已被遍历的点标记为true
void dfs(int v)//当前点
{
	printf("%d ",v);
	marked[v]=true;//该点标记为已遍历
	for(int i=1;i<=N;++i)//枚举该点能到达的点
		if(G[v][i] && !marked[i])//两点间有边，且终点没有被遍历过
			dfs(i,N);
}
//调用:dfs(begin);
//如果不确定该图是否为连通图，欲统计连通分量个数
int cnt=0;
for(int i=1;i<=N;++i)
{
	if(!marked[i])
	++cnt,dfs(i);
}
printf("%d",cnt);//输出连通分量个数

//case 2:邻接链表
void dfs(Vertex *v)
{
	printf("%d ",v->Num);
	v->marked=true;//该点标记为已遍历
	for(Edge *e=v->next;e;e=e->next)//枚举该点下面的边
		if(!e->to->marked)
			dfs(e->to);
}
//调用:dfs(V+begin);
//统计连通分量:
int cnt=0;
for(int i=1;i<=N;++i)
{
	if(!V[i].marked)
	++cnt,dfs(V+i);
}
printf("%d",cnt);
