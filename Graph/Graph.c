#include <stdio.h>
#include <string.h>
#define DistType int	//边的权值类型定义
#define NameType char
#define Bool int
#define true 1
#define false 0

//定义边的结构体
struct Edge   
{
	int m_nposTable; //该边的目的顶点在顶点集中的位置
	DistType m_distWeight;//边的权重值
	struct Edge *m_pnext;//下一条边
};

//定义顶点的结构体
struct Vertex
{
	NameType m_vertexName;//顶点中的数据内容
	struct Edge *padjEdge;//顶点的邻边
};

//定义图集的结构体
struct Graph
{
	struct Vertex *m_pVertexTable;//顶点集
	int m_numVertexs;//图中当前的顶点数量
	int m_nmaxSize;//图允许的最大顶点数
	int m_nnumEdges;//图中边的数目
};

static const int m_nDefaultSize = 10;//默认的最大顶点集数目
static const DistType m_Infinity = 65536;//边的默认权值（无穷大）

/*************返回顶点Vertexname在m_pVertexTable(顶点集)中的位置***********/
int GetVertexPosTable(struct Graph m_graph,const NameType vertexname)
{
	int i;
	for(i=0; i<m_graph.m_numVertexs; i++)
	{
		if(vertexname == m_pVertexTable[i].m_vertexName)
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
	for(i=0; i<m_graph->m_numVertexs; i++)
	{
		printf("%s ->",m_graph->m_pVertexTable[i].m_vertexName);
		pmove = m_graph->m_pVertexTable[i].padjEdge;
		while(pmove)
		{
			printf("%d -> %s ->",pmove->m_distWeight,m_graph->m_pVertexTable[pmove->m_nposTable].m_vertexName);
			pmove = pmove->m_pnext;
		}
		printf("NULL\n");
	}
}

/***************获得在顶点集中的位置为v的顶点的名字********************/、
NameType GetVertexvalue(struct Graph m_graph, int v)
{
	if(v<0 || v>=m_graph->m_numVertexs)
	{
		perror("查找的顶点位置参数有误，请检查！\n");
		exit(1);
	}
	return m_graph->m_pVertexTable[v].m_vertexName;
}

/**************返回顶点v1和v2之间的权值，如果无连接，返回无穷大************/
DistType GetWeight(struct Graph m_graph,int v1,int v2)
{
	if(v1>=0 && v1<m_graph->m_numVertexs && v2>=0 && v2<m_graph->m_numVertexs)
	{
		if(v1 == v2)
		{
			return 0;
		}

		struct Edge *pmove = m_graph->m_pVertexTable[v1].padjEdge;
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
Bool InsertVertex(struct Graph m_graph,const NameType vertexname)
{
	if(IsGraphFull())
	{
		perror("图已满，请勿再插入顶点\n");
		return false;
	}else
	{
		m_graph->m_pVertexTable[m_graph->m_numVertexs].m_vertexName = vertexname;
		m_graph->m_numVertexs++;	
	}
	return true;
}

/****************在顶点集位置为v1和v2的顶点之间插入权值为weght的边***********/


/************************主函数**********************/
int main(int argc,char *argv[])
{

	return 0;
}






















