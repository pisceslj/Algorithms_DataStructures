#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Bool int
#define true 1
#define false 0
static const int m_DefaultSize = 10;//默认的最大顶点集数目
static const int m_Infinity = 65536;//边的默认权值（无穷大）
struct Graph m_graph;
//定义边的结构体
struct Edge   
{
	int m_nposTable; //该边的目的顶点在顶点集中的位置
	int m_distWeight;//边的权重值
	struct Edge *m_pnext;//下一条边
};

//定义顶点的结构体
struct Vertex
{
	char *m_vertexName;//顶点中的数据内容
	struct Edge *padjEdge;//顶点的邻边
};

//定义图集的结构体
struct Graph
{
	struct Vertex *m_pVertexTable;//顶点集
	int m_numVertexs;//图中当前的顶点数量
	int m_numEdges;//图中边的数目
};

/*****************************************************************/
int GetNumEdges(struct Graph m_graph)
{
	return m_graph.m_numEdges/2;
}

/*******************************************************************/
int GetNumVertexs(struct Graph m_graph)
{
	return m_graph.m_numVertexs;
}

/****************获得顶点v的第一个相邻顶点，如果没有就返回-1  *******/
int GetFirst(struct Graph m_graph,int v)
{
	if(v<0 || v>=m_graph.m_numVertexs)
	{
		return -1;
	}
	struct Edge *ptemp = m_graph.m_pVertexTable[v].padjEdge;
	return m_graph.m_pVertexTable[v].padjEdge ? m_graph.m_pVertexTable[v].padjEdge->m_nposTable : -1;
}

/*******************************************************************/
Bool IsGraphFull(struct Graph m_graph)
{
	return m_DefaultSize == m_graph.m_numVertexs;
}

/*************返回顶点Vertexname在m_pVertexTable(顶点集)中的位置***********/
int GetVertexPosTable(struct Graph m_graph,const char *vertexname)
{
	int i;
	for(i=0; i<m_graph.m_numVertexs; i++)
	{
		if(vertexname == m_graph.m_pVertexTable[i].m_vertexName)
		{
			return i;
		}
	}
	return -1;
}

/************打印图中各个顶点及其链接的边的权重***********************/
void PrintGraph(struct Graph m_graph)
{
	int i;
	struct Edge *pmove;
	printf("\n顶点个数:%d\n",m_graph.m_numVertexs);
	for(i=0; i<m_graph.m_numVertexs; i++)
	{
		printf("%s ->",m_graph.m_pVertexTable[i].m_vertexName);
		pmove = m_graph.m_pVertexTable[i].padjEdge;
		while(pmove)
		{
			printf("%d -> %s ->",pmove->m_distWeight,m_graph.m_pVertexTable[pmove->m_nposTable].m_vertexName);
			pmove = pmove->m_pnext;
		}
		printf("NULL\n");
	}
}

/*****************获得在顶点集中的位置为v的顶点的名字****************/
char *GetVertexName(struct Graph m_graph,int v)
{
	if(v<0 || v>=m_graph.m_numVertexs)
	{
		perror("查找的顶点位置参数有误，请检查！\n");
		exit(1);
	}
	return m_graph.m_pVertexTable[v].m_vertexName;
}

/***************获得在顶点集中的位置为v的顶点的名字********************/
char *GetVertexvalue(struct Graph m_graph, int v)
{
	if(v<0 || v>=m_graph.m_numVertexs)
	{
		perror("查找的顶点位置参数有误，请检查！\n");
		exit(1);
	}
	return m_graph.m_pVertexTable[v].m_vertexName;
}

/**************返回顶点v1和v2之间的权值，如果无连接，返回无穷大************/
int GetWeight(struct Graph m_graph,int v1,int v2)
{
	if(v1>=0 && v1<m_graph.m_numVertexs && v2>=0 && v2<m_graph.m_numVertexs)
	{
		if(v1 == v2)
		{
			return 0;
		}

		struct Edge *pmove = m_graph.m_pVertexTable[v1].padjEdge;
		while(pmove)
		{
			if(pmove->m_nposTable == v2)
			{
				return pmove->m_distWeight;
			}
			pmove = pmove->m_pnext;
		}
	}
	return m_Infinity;
}

/**************顶点依次插入到分配好的顶点集中***********************/
Bool InsertVertex(struct Graph m_graph, char *vertexname)
{
	if(IsGraphFull(m_graph))
	{
		perror("图已满，请勿再插入顶点\n");
		return false;
	}else
	{
		m_graph.m_pVertexTable[m_graph.m_numVertexs].m_vertexName = vertexname;
		printf("%s\t",m_graph.m_pVertexTable[m_graph.m_numVertexs].m_vertexName);
		m_graph.m_numVertexs++;	
	}
	return true;
}

/****************在顶点集位置为v1和v2的顶点之间插入权值为weght的边***********/
Bool InsertEdge(struct Graph m_graph,int v1,int v2,int weight)
{
	if(v1 < 0 && v1 > m_graph.m_numVertexs && v2 < 0 && v2 > m_graph.m_numVertexs)
	{
		perror("边的位置参数错误，请检查！\n");
		return false;
	}
	else
	{
		struct Edge *pmove = m_graph.m_pVertexTable[v1].padjEdge;
		if(pmove == NULL) //如果顶点v1没有邻边
		{	//建立顶点v1的第一个邻边(该邻边指明了目的顶点)
			printf("v1 has no near edge!\n");  
			m_graph.m_pVertexTable[v1].padjEdge = (struct Edge*)malloc(sizeof(struct Edge));
			m_graph.m_pVertexTable[v1].padjEdge->m_nposTable = v2;
			m_graph.m_pVertexTable[v1].padjEdge->m_distWeight = weight; 
			m_graph.m_numEdges++;//图中边的数目  
			return true;
		}else//如果有邻边
		{
			printf("v1 has near edge!\n");
			//printf("\n%s\n",pmove->m_distWeight);
			while(pmove->m_pnext != NULL)
			{
				pmove = pmove->m_pnext;
			}
				pmove->m_pnext = (struct Edge*)malloc(sizeof(struct Edge));
				pmove->m_pnext->m_nposTable = v2;
				pmove->m_pnext->m_distWeight = weight;
				m_graph.m_numEdges++;
				return true;			
		}
	}
}

/*******************迪斯特拉*************************/
void Dijkstra(struct Graph m_graph,int v,int *shPath)
{
	int i,j,w;
	int num = GetNumVertexs(m_graph);
	int *visited = (int*)malloc(num*sizeof(int));
	for(i=0; i<num; i++)
	{
		visited[i] = 0;//未访问
		shPath[i] = GetWeight(m_graph,v,i);
	} 
	visited[v] = 1; //第v个顶点初始化为被访问，并以他为中点点开始找最短路径

	for(i=1; i<num; i++)
	{
		int min = m_Infinity;
		int u = 0;

		for(j=0; j<num; j++)
		{
			if(!visited[j])
			{
				if(shPath[j]<min)
				{
					min = shPath[j];
					u = j;
				}
			}
		}
		
		visited[u] = 1;

		for(w=0; w<num; w++)
		{
			int weight = GetWeight(m_graph,u,w);
			if(!visited[w] && weight != m_Infinity)
			{
				if(shPath[u]+weight < shPath[w])
				{
					shPath[w] = shPath[w] + weight;
				}
			}
		}
	}
}

/*****************获得顶点v1的邻点v2后的邻点**********************/
int GetNext(struct Graph m_graph,int v1,int v2)
{
	if(-1 != v1)
	{
		struct Edge *pmove = m_graph.m_pVertexTable[v1].padjEdge;
		while(NULL != pmove->m_pnext)
		{
			if(pmove->m_nposTable == v2)
			{
				return pmove->m_pnext->m_nposTable;
			}
			pmove = pmove->m_pnext;
		}
	}
	return -1;
}

/****************从第v个顶点开始深度遍历*************************/
void DFS_v(struct Graph m_graph,int v,int *visited)
{
	printf("->%s",GetVertexName(m_graph,v));
	visited[v] = 1;
	int firstVertex = GetFirst(m_graph,v);
	while(-1 != firstVertex)
	{
		if(!visited[firstVertex])
		{
			printf("-> %d",GetWeight(m_graph,v,firstVertex));
			DFS_v(m_graph,firstVertex,visited);
		}
		firstVertex = GetNext(m_graph,v,firstVertex);
	}
}

/***************从第一个顶点开始深度遍历**************************/
void DFS_0(struct Graph m_graph)
{
	int i;
	int *visited = (int*)malloc((m_graph.m_numVertexs)*sizeof(int));
	for(i=0; i<m_graph.m_numVertexs; i++)
	{
		visited[i]=0;
	}
	printf("head");
	DFS_v(m_graph,0,visited);
	printf("---->end");
}

/************************主函数**********************/
int main(int argc,char *argv[])
{
	int i;
	
	char *vertex[7] = {"【地大】", "【武大】", "【华科】", "【交大】", "【北大】", "【清华】", "【复旦】"};
	m_graph.m_numVertexs = 0;
	m_graph.m_numEdges = 0;
	
	for(i=0; i<7; i++)
	{
		InsertVertex(m_graph,vertex[i]);
	}

	for(i=0;i<7;i++)
	{
		printf("%s\t",m_graph.m_pVertexTable[i].m_vertexName);
	}
	printf("一，图的初始化（邻结表存储）：======================================\n");
	PrintGraph(m_graph);
	printf("图中顶点的数目:%d\n",GetNumVertexs(m_graph));

	int edge[][3] = {{0,1,43},{0,2,12},{4,5,34},{0,3,400},{2,6,314},{2,4,37}};
	int len = sizeof(edge)/sizeof(edge[0]);

	for(i=0; i<len; i++)
	{
		//InsertEdge(graph,edge[i][0],edge[i][1],edge[i][2]);
		//InsertEdge(graph,edge[i][1],edge[i][0],edge[i][2]);
	}

	printf("二，添加边后的图(无向图)：==================================\n");
	PrintGraph(m_graph);
	printf("图中边的数目(实际上是所示边数的两倍，因为是双向的)：%d\n",GetNumEdges(m_graph));

	printf("三，Dijkstra法最短路径为：==========================\n");
	int shortestPath[7];
	Dijkstra(m_graph,0,shortestPath);
	for(i=0;i<7;i++)
	{
		printf("%s ----> %s:%d",GetVertexvalue(m_graph,0),GetVertexvalue(m_graph,i),shortestPath[i]);
	}
	printf("\n");

	printf("四，图的遍历：==========================\n");
	printf("1,DFS深度优先遍历结果：");
	DFS_0(m_graph);
	printf("\n\n");

	return 0;
}






















