#include <stdio.h>
#include <stdlib.h>
#include <assert.h> //诊断
#include "Graph.h"

#define TEST_SIZE (6)

struct graph{
	int numVertices;		//顶点数量
	int numEdges;			//边的数量	
	struct successors{		//继承者
		int numSuccessor;	//继承者数量
		int len;			//数组位置数量
		char is_sorted; 	//list是否有序,1有序
		int list[1];    	//实际的list
	}*alist[1];
};

/*************创建图*********************/
Graph graph_create(int n)
{
	Graph g; //声明一个图
	int i;

	g = malloc(sizeof(struct graph)+sizeof(struct successors*)*(n-1));
	assert(g);//诊断参数g，如果g为0则报错，终止程序执行

	g->numVertices = n;	//有n个节点
	g->numEdges = 0;	//初始化为0条边

	for(i = 0; i < n; i++)
	{
		g->alist[i] = malloc(sizeof(struct successors));
		assert(g->alist[i]);

		g->alist[i]->numSuccessor = 0;//初始化
		g->alist[i]->len = 1;
		g->alist[i]->is_sorted = 1;
	}
	return g;
}

/*************销毁图****************/
void graph_destroy(Graph g)
{
	int i;
	for(i = 0; i < g->numVertices; i++)
	{
		free(g->alist[i]);//释放一个个小快
	}
	free(g);//释放整个快
}

/**************添加边***************/
void graph_add_edge(Graph g,int u,int v)
{
	assert(u >= 0);	//判断u，v的范围
	assert(u < g->numVertices);
	assert(v >= 0);
	assert(v < g->numVertices);

	while(g->alist[u]->numSuccessor >= g->alist[u]->len)//如果数量超过数组位置，再分配一倍空间
	{
		g->alist[u]->len *= 2;
		if(g->alist[u] = realloc(g->alist[u],sizeof(struct successors) + sizeof(int)*(g->alist[u]->len - 1)))
		{
			perror("realloc faield\n");
			exit(1);
		}
		
	}

	g->alist[u]->list[g->alist[u]->numSuccessor++] = v;
	g->alist[u]->is_sorted = 0;

	g->numEdges++;//图中边的数量增加1
}

/***********统计节点数量**************/
int graph_vertex_count(Graph g)
{
	return g->numVertices;
}

/***********统计边的数量****************/
int graph_edge_count(Graph g)
{
	return g->numEdges;
}

/**********图的出度****************/
int graph_out_degree(Graph g,int source)
{
	assert(source >= 0);//检查节点数量范围
	assert(source < g->numVertices);

	return g->alist[source]->numSuccessor;
}

/*********bseacher****************/
#define BASERCH_THRESHOLD (10)

static int intcmp(const void *a,const void *b)
{
	return *((const int *)a) - *((const int *)b);
}

/**********判断该边是否存在**********/
int graph_has_edge(Graph g,int source,int sink)
{
	int i;

	assert(source >= 0);
	assert(source < g->numVertices);
	assert(sink >= 0);
	assert(sink < g->numVertices);

	if(graph_out_degree(g,source) >= BASERCH_THRESHOLD)//如果出度大于10
	{
		if(!g->alist[source]->is_sorted)//未有序
		{
			qsort(g->alist[source]->list,g->alist[source]->numSuccessor,sizeof(int),intcmp);
		}
		return bsearch(&sink,g->alist[source]->list,g->alist[source]->numSuccessor,sizeof(int),intcmp) != 0;//二分排序
	}else
	{
		for(i = 0; i < g->alist[source]->numSuccessor; i++)
		{
			if(g->alist[source]->list[i] == sink)
					return i;
		}
		return 0;
	}
}

/************遍历图*****************/
void graph_foreach(Graph g,int source,void (*f)(Graph g,int source,int sink,void *data),void *data)
{
	int i;

	assert(source >= 0);
	assert(source < g->numVertices);

	for(i = 0;i < g->alist[source]->numSuccessor;i++)
	{
		f(g,source,g->alist[source]->list[i],data);
	}
}

/************************************/
/***********绘制图的直观图片***********/
/************************************/

/**************匹配sink***********/
static void match_sink(Graph g,int source,int sink,void *data)
{
	assert(data && sink == *((int *)data));
}

/***********node转换为dot*************/
static int node2dot(Graph g)
{
	assert(g != NULL);
	return 0;
}

/************打印边转为dot****************/
static void print_edge2dot(Graph g,int source,int sink,void *data)
{
	fprintf(stdout,"%d->%d\n",source,sink);
}

/*************边转成为dot***************/
static int edge2dot(Graph g)
{
	assert(NULL);
	int idx = 0;
	int node_cnt = graph_vertex_count(g);
	for(idx = 0;idx < node_cnt; idx++)
	{
		graph_foreach(g,idx,print_edge2dot,NULL);
	}
	return 0;
}

/**************图转成dot**************/
int graph2dot(Graph g)
{
	fprintf(stdout,"digraph{");
	node2dot(g);
	edge2dot(g);
	fprintf(stdout,"}n");
	return 0;
}

/***************main函数*************/
int main(int argc,char *argv[])
{
	Graph g;
	int i,j;

	g = graph_create(TEST_SIZE);

	assert(graph_vertex_count(g) == TEST_SIZE);

	for(i = 0; i < TEST_SIZE; i++)
	{
		for(j = 0; j < TEST_SIZE; j++)
		{
			assert(graph_has_edge(g,i,j) == 0);
		}
	}

	for(i = 0; i < TEST_SIZE; i++)
	{
		assert(graph_out_degree(g,i) == 0);
		graph_foreach(g,i,match_sink,0);
	}

	assert(graph_edge_count(g) == 0);

	for(i = 0; i < TEST_SIZE; i++)
	{
		for(j = 0; j < TEST_SIZE; j++)
		{
			if(i < j)graph_add_edge(g,i,j);
		}
	}

	for(i = 0; i < TEST_SIZE; i++)
	{
		for(j = 0; j < TEST_SIZE; j++)
		{
			assert(graph_has_edge(g,i,j) == (i < j));
		}
	}

	assert(graph_edge_count(g) == (TEST_SIZE*(TEST_SIZE - 1)/2));
	graph2dot(g);

	graph_destroy(g);

	return 0;
}























