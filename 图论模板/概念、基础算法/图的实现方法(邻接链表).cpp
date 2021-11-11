#include<cstdio>

const int MAXV=10000;
const int MAXE=(MAXV*(MAXV-1))>>1;

struct Edge;
struct Vertex
{
	int Num;//快速把该边的指针编号转换成数组序号
	Edge *next;//该点连接的第一条边
	/*bool marked;根据需要定义的数值，如出入度，颜色等
	int in_degree,out_degree;
	int cnt;*/
	Vertex();
}V[MAXV];
Vertex::Vertex()
{
	Num = this-V;
}

struct Edge
{
	Vertex *to;//该边终点
	Edge *next;//该边起点的下一条边
	/*int weight;根据需要定义的数值，如权值等
	bool marked;*/
	Edge(Vertex *_to,Edge *_next,int _weight):to(_to),next(_next),weight(_weight){}//插入新边时，构造一条新的边
	Edge(){}//静态数组优化需定义一个空的构造函数
	void* operator new(size_t);//静态数组优化，重载new函数
}E[MAXE];
void* Edge::operator new(size_t)
{
	static Edge *P=E;//如果有多组数据，请把该变量定义成全局变量并及时重新指向E
	return P++;
}

void addEdge(Vertex *A,Vertex *B,int w)//添加一条从点A指向点B的边,权值为w
{
	A->next=new Edge(B,A->next,w);//在点A的后面连上一条新边，该边以B为终点，链表连接着原来A点下面连着的边，权值为w
}

int main()
{
	//多组数据的处理:点数组清零，边数组无需清零，静态数组优化定义的指针重新指向E
	/*邻接表加边:
		有向边A指向B，权值为C:addEdge(V+A,V+B,C);
		无向图:addEdge(V+A,V+B,C),addEdge(V+B,V+A,C);
		如果图不是带权图，所有函数的第三个参数可省略*/
	/*找到两点间的权值:遍历链表
	int getweight;
	Vertex *begin,*end;
	for(Edge *e=begin->next;e;e=e->next)
		if(e->to==end){getweight=e->to->weight;break;}*/
	//删边操作较复杂且不常用，不再赘述
	return 0;
}
