#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct graph *Graph;//定义图

Graph graph_create(int n);//创建n个节点的图
void graph_destroy(Graph);//销毁图
void graph_add_edge(Graph,int source,int sink);//添加图的边

int graph_vertex_count(Graph);//统计图的节点数量
int graph_edge_count(Graph);//统计图的边的数量

int graph_out_degree(Graph,int source);
int graph_has_edge(Graph,int source,int sink);

void graph_foreach(Graph g,int source,
		void(*f)(Graph g,int source,int sink,void *data),
		void *data
);

#endif

