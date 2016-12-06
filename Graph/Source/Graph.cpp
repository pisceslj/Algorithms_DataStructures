#include "stdafx.h"  
#include "Graph.h"  
#include <iostream>  
using namespace std;  
int _tmain(int argc, _TCHAR* argv[])  
{  
      
    Graph<char *, int> graph(7);  
    char *vertex[7] = {"【地大】", "【武大】", "【华科】", "【交大】", "【北大】", "【清华】", "【复旦】"};//顶点集  
    for (int i=0; i<7; i++)  
    {  
        graph.InsertVertex(vertex[i]);  
    }  
    cout<<"一，图的初始化（邻结表存储）：======================================"<<endl;  
    graph.PrintGraph();  
    cout<<"图中顶点的数目:"<<graph.GetNumVertexs()<<endl;  
    cout <<endl;  
  
    int edge[][3] = {{0, 1, 43}/*地大到武大的距离*/, {0, 2, 12}, /*{1, 2, 38}*/ /*{2, 3 ,1325}*/   
    /*{3, 6, 55}*/ {4, 5, 34}, /*{4, 6, 248}*/{0,3,400},{2,6,314},{2,4,37}};    //分配距离   
    int len=sizeof(edge)/sizeof(edge[0]);  
    for (int i=0; i < len; i++)  
    {  
        graph.InsertEdge(edge[i][0], edge[i][1], edge[i][2]);  
        graph.InsertEdge(edge[i][1], edge[i][0], edge[i][2]);  
    }  
    cout<<"二，添加边后的图(无向图)：=================================="<<endl;  
    graph.PrintGraph();  
    cout<<"图中边的数目(实际上是所示边数的两倍，因为是双向的)："<<graph.GetNumEdges()<<endl;  
    cout <<endl;  
  
    cout<<"三，Dijkstra法最短路径为：=========================="<<endl;  
    int shortestPath[7];//存储Dijkstra算法最短路径值  
    graph.Dijkstra(0, shortestPath);  
    for (int i=0; i<7; i++)  
    {  
        cout << graph.GetVertexValue(0) << "--->" << graph.GetVertexValue(i)   
            << ":   " << shortestPath[i] <<endl;  
    }  
    cout<<endl;  
  
    cout<<"四，图的遍历：=========================="<<endl;  
    cout<<"1,DFS深度优先遍历结果："<<endl;  
    graph.DFS();  
    cout<<endl<<endl;  
    cout<<"2,BFS广度优先遍历结果："<<endl;  
    graph.BFS();  
    cout<<endl<<endl;  
  
    system("color 0A");  
    system("pause");  
    return 0;  
}  