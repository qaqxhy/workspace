/*应用：知道一些依赖关系，求事物发生顺序的一种方案
	举例：4个变量a,b,c,d，a<b,c<b,d<c，求出这4个变量的排序
			(可能是a<d<c<b,也可能是d<a<c<b，拓扑排序只需找到一种方案即可)
存在拓扑排序的充分必要条件：图中不存在有向环
基本方法：
	1.从有向图中选择一个没有前驱(即入度为0)的顶点并且输出它
	2.从图中删去该顶点，并且删去从该顶点发出的全部有向边
	3.重复上述两步，直到剩余的网中不再存在没有前趋的顶点为止
实现方法：DFS、容器(一般用栈或队列，两者本质相同)*/

//拓扑排序DFS实现：
struct Vertex
{
	Edge *next;
	bool marked;//true表示该点从未被访问过
	bool visiting;//true表示正在访问该节点，false表示已访问过该节点及其子孙
};
int topo[MAXV],cnt;//保存拓扑排序结果
bool dfs(Vertex *v)
{
	v->marked=true;
	v->visiting=true;
	for(Edge *e=v->next;e;e=e->next)
	{
		if(e->to->marked && e->to->visiting)//存在有向环，拓扑排序失败
			return false;
		else if(!e->to->marked)//继续搜索
			dfs(e->to);
	}
	v->visiting=false;
	topo[cnt--]=v->Num;//保存拓扑排序结果，因为DFS的回溯，所以倒序存储
	return true;
}
bool toposort()
{
	cnt=n;
	for(int i=1;i<=n;++i)
		if(!V[i].marked)//多次DFS判断是否有有向环
			if(!dfs(V+i))return false;
	return true;//存在拓扑排序，topo数组保存最终结果(1~n)
}

//拓扑排序辅助队列实现：
struct Vertex
{
	Edge *next;
	int Num,indegree;//建图时需要统计每个点的入度
};
bool toposort()
{
    int cnt=0,t=1;//cnt统计当前已有多少个点在拓扑序列中
    std::queue<Vertex*> Q;
    for(int i=1;i<=n;++i)
    {
        if(!V[i].indegree)//将所有入度为0的点入队
        {
            ++cnt,Q.push(V+i);
        }
    }
    while(!Q.empty())
    {
        Vertex *v=Q.front();
        Q.pop();
        topo[t++]=v->Num;//将入度为0的点记录到拓扑序中
        for(Edge *e=v->next;e;e=e->next)
        {
            if(!--e->to->indegree)
            {
                ++cnt,Q.push(e->to);
            }
        }
    }
    return cnt!=n?false:true;//拓扑序中的cnt不足N个，证明有环
}
