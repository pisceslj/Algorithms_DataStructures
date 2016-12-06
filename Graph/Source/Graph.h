#include "stdafx.h"  
#include "iostream"  
#include "queue"  
using namespace std;  
  
template<class DistType/*边的权值的类型*/>   
class Edge//边的定义  
{  
public:  
    Edge(int dest, DistType weight)  
    {  
        m_nposTable=dest;  
        m_distWeight=weight;   
        m_pnext=NULL;  
    }  
    ~Edge()  
    {  
  
    }  
public:  
    int m_nposTable;//该边的目的顶点在顶点集中的位置  
    DistType m_distWeight;//边的权重值  
    Edge<DistType> *m_pnext;//下一条边（注意不是下一个顶点，因为m_nposTable已经知道了这个顶点的位置）  
};  
//声明  
template<class NameType/*顶点集名字类型*/, class DistType/*距离的数据类型*/> class Graph;  
  
template<class NameType/*顶点集名字类型*/, class DistType/*距离的数据类型*/>   
class Vertex//顶点的定义  
{  
public:  
    Vertex()  
    {  
        padjEdge=NULL;  
        m_vertexName=0;  
    }  
    ~Vertex()  
    {  
        Edge<DistType> *pmove = padjEdge;  
        while (pmove)  
        {  
            padjEdge = pmove->m_pnext;  
            delete pmove;  
            pmove = padjEdge;  
        }  
    }  
  
private:  
    friend class Graph<NameType,DistType>;//允许Graph类任意访问  
    NameType m_vertexName;//顶点中的数据内容  
    Edge<DistType> *padjEdge;//顶点的邻边  
  
};  
  
  
template<class NameType/*顶点集名字类型*/, class DistType/*距离的数据类型*/>   
class Graph  
{  
public:  
    Graph(int size = m_nDefaultSize/*图顶点集的规模*/)  
    {  
        m_pVertexTable = new Vertex<NameType, DistType>[size];  //为顶点集分配内存  
        if (m_pVertexTable == NULL)  
        {  
            exit(1);  
        }  
        m_numVertexs=0;  
        m_nmaxSize=size;  
        m_nnumEdges=0;  
    }  
  
    ~Graph()  
    {  
        Edge<DistType> *pmove;  
        for (int i=0; i < this->m_numVertexs; i++)  
        {  
            pmove = this->m_pVertexTable[i].padjEdge;  
            if (pmove){  
                this->m_pVertexTable[i].padjEdge = pmove->m_pnext;  
                delete pmove;  
                pmove = this->m_pVertexTable[i].padjEdge;  
            }  
        }  
        delete[] m_pVertexTable;  
    }  
    int GetNumEdges()  
    {//获得边的数目  
        return m_nnumEdges/2;  
    }  
    int GetNumVertexs()  
    {//获得顶点数目  
        return m_numVertexs;  
    }  
  
    bool IsGraphFull() const  
    {     //图满的?  
        return m_nmaxSize == m_numVertexs;  
    }  
    //在顶点集中位置为v1和v2的顶点之间插入边  
    bool InsertEdge(int v1, int v2, DistType weight=m_Infinity);   
    //插入顶点名字为vertex的顶点  
    bool InsertVertex(const NameType vertex);    
    //打印图  
    void PrintGraph();     
    //顶点v到其他各个顶点的最短路径（包括自身）  
    void Dijkstra(int v, DistType *shotestpath);  
    //获取顶点集中位置为v1和v2的顶点之间边的权重值  
    DistType GetWeight(int v1, int v2);   
    //获得在顶点集中的位置为v的顶点的名字  
    NameType GetVertexValue(int v);  
    //用该顶点的名字来寻找其在顶点集中的位置  
    int GetVertexPosTable(const NameType vertex);    
  
  
    //深度搜索优先  
    void DFS(int v, int *visited);        
    void DFS();  
    //广度优先搜索  
    void BFS(int v, int *visited);  
    void BFS();  
    //获取第v个顶点的名字（或者说内容）  
    NameType GetVertexName(int v);     
    //获得顶点v的第一个相邻顶点，如果没有就返回-1  
    int GetFirst(int v);         
    //获得顶点v1的邻点v2后的邻点  
    int GetNext(int v1, int v2);  
  
private:  
    Vertex<NameType, DistType> *m_pVertexTable;   //顶点集  
    int m_numVertexs;//图中当前的顶点数量  
    int m_nmaxSize;//图允许的最大顶点数  
    static const int m_nDefaultSize = 10;       //默认的最大顶点集数目  
    static const DistType m_Infinity = 65536;  //边的默认权值（可以看成是无穷大）  
    int m_nnumEdges;//图中边的数目  
      
};  
  
  
//返回顶点vertexname在m_pVertexTable(顶点集)中的位置  
//如果不在顶点集中就返回-1  
template<class NameType, class DistType>   
int Graph<NameType, DistType>::GetVertexPosTable(const NameType vertexname)  
{  
    for (int i=0; i < this->m_numVertexs; i++)  
    {  
        if (vertexname == m_pVertexTable[i].m_vertexName)  
        {  
            return i;  
        }  
    }  
    return -1;  
}  
  
//打印图中的各个顶点及其链接的边的权重  
template<class NameType, class DistType>   
void Graph<NameType, DistType>::PrintGraph()  
{  
    Edge<DistType> *pmove;  
    for (int i=0; i<this->m_numVertexs; i++)  
    {  
        cout << this->m_pVertexTable[i].m_vertexName << "->";  
        pmove = this->m_pVertexTable[i].padjEdge;  
        while (pmove)  
        {  
            cout << pmove->m_distWeight << "->" << this->m_pVertexTable[pmove->m_nposTable].m_vertexName << "->";  
            pmove = pmove->m_pnext;  
        }  
        cout << "NULL" << endl;  
    }  
}  
//获得在顶点集中的位置为v的顶点的名字  
template<class NameType, class DistType>   
NameType Graph<NameType, DistType>::GetVertexValue(int v)  
{  
    if (v<0 || v>=this->m_numVertexs)  
    {  
        cerr << "查找的顶点位置参数有误，请检查！" <<endl;  
        exit(1);  
    }  
    return m_pVertexTable[v].m_vertexName;  
  
}  
//返回顶点v1和v2之间的边权值，  
//如果没有直接相连（即不是一条边直接相连）则返回无穷大  
template<class NameType, class DistType>   
DistType Graph<NameType, DistType>::GetWeight(int v1, int v2)  
{  
    if (v1>=0 && v1<this->m_numVertexs && v2>=0 && v2<this->m_numVertexs)  
    {  
        if (v1 == v2)  
        {  
            return 0;  
        }  
        Edge<DistType> *pmove = m_pVertexTable[v1].padjEdge;  
        while (pmove)  
        {  
            if (pmove->m_nposTable == v2)  
            {  
                return pmove->m_distWeight;  
            }  
            pmove = pmove->m_pnext;  
        }  
    }  
      
    return m_Infinity;    
}  
  
//顶点依次插入到分配好的顶点集中  
template<class NameType, class DistType>   
bool Graph<NameType, DistType>::InsertVertex(const NameType vertexname)  
{  
    if (IsGraphFull())  
    {  
        cerr<<"图已经满，请勿再插入顶点！"<<endl;  
        return false;  
    }else  
    {  
        this->m_pVertexTable[this->m_numVertexs].m_vertexName = vertexname;  
        this->m_numVertexs++;  
    }  
      
    return true;  
}  
  
//在顶点集位置为v1和v2的顶点之间插入权值为weght的边（务必保持输入的准确性，否则.....）  
template<class NameType, class DistType>   
bool Graph<NameType, DistType>::InsertEdge(int v1, int v2, DistType weight)  
{  
    if (v1 < 0 && v1 > this->m_numVertexs && v2 < 0 && v2 > this->m_numVertexs)  
    {  
        cerr<<"边的位置参数错误，请检查！ "<<endl;  
        return false;  
    }  
    else  
    {  
        Edge<DistType> *pmove = m_pVertexTable[v1].padjEdge;  
        if (pmove == NULL)//如果顶点v1没有邻边  
        { //建立顶点v1的第一个邻边(该邻边指明了目的顶点)  
            m_pVertexTable[v1].padjEdge = new Edge<DistType>(v2, weight);  
            m_nnumEdges++;//图中边的数目  
            return true;  
        }else//如果有邻边  
        {  
            while (pmove->m_pnext)  
            {  
                pmove = pmove->m_pnext;  
            }  
                pmove->m_pnext = new Edge<DistType>(v2, weight);  
                m_nnumEdges++;//图中边的数目  
                return true;  
        }  
    }  
}  
  
  
template<class NameType, class DistType>  
void Graph<NameType, DistType>::Dijkstra(int v, DistType *shPath)  
{  
    int num =GetNumVertexs();  
    int *visited = new int[num];  
    for (int i=0; i < num; i++)  
    {//初始化  
        visited[i] = 0;//未访问  
        shPath[i] = this->GetWeight(v, i);//顶点v（当前中间点）到各个相邻顶点的边权值，其他情况返回无穷大  
    }  
  
    visited[v] = 1;//第v个顶点初始化为被访问，并以他为中点点开始找最短路径  
  
    for (int i = 1; i < num; i++)  
    {  
        DistType min = this->m_Infinity;  
        int u=0;  
          
        //寻找新的中间点u，依据就是数组中权值最小的那个点的位置（且没被访问过）  
        for (int j=0; j < num; j++)  
        {     
            if (!visited[j])  
            {  
                if (shPath[j]<min)  
                {  
                    min = shPath[j];//获得当前shPath数组中的最小边权重  
                    u = j;//用u来记录获取最小值时的顶点位置,即新的中间点  
                }  
            }  
        }  
  
        visited[u] = 1;//已经确定的最短路径  
  
        //以u为中间点寻找顶点v到顶点w的最短路径  
        for (int w=0; w < num; w++)  
        {    
            DistType weight = this->GetWeight(u, w);//顶点u（当前中间点）到各个相邻顶点的边权值，其他情况返回无穷大  
            if (!visited[w] && weight != this->m_Infinity )  
            {  
                if ( shPath[u]+weight < shPath[w] )  
                {  
                    shPath[w] = shPath[u] + weight;//更新顶点v到w的最短路径值  
                }  
            }  
        }  
    }  
    delete[] visited;  
}  
  
  
  
//获得顶点v1的邻点v2后的邻点  
template<class NameType, class DistType>   
int Graph<NameType, DistType>::GetNext(int v1, int v2)  
{  
    if (-1 != v1)  
    {  
        Edge<DistType> *pmove = this->m_pVertexTable[v1].padjEdge;  
        while (NULL != pmove->m_pnext)  
        {  
            if (pmove->m_nposTable==v2)  
            {  
                return pmove->m_pnext->m_nposTable;  
            }  
            pmove = pmove->m_pnext;  
        }          
    }  
    return -1;  
}  
  
//从第v个顶点开始深度遍历  
template<class NameType, class DistType>   
void Graph<NameType, DistType>::DFS(int v, int *visited)  
{  
    cout << "->" << this->GetVertexName(v);  
    visited[v] = 1;  
    int firstVertex = this->GetFirst(v);//获得顶点v的第一个相邻顶点，若没有则返回-1  
    while (-1 != firstVertex)  
    {  
        if (!visited[firstVertex])//如果没有访问过  
        {  
            cout << "->" << this->GetWeight(v, firstVertex);//获得顶点v及其邻点firstVertex之间的权值  
            DFS(firstVertex, visited);  
        }  
        firstVertex = this->GetNext(v, firstVertex);//获得顶点v的邻点firstVertex后的邻点，如果没有就返回-1  
    }  
}  
  
template<class NameType, class DistType>   
void Graph<NameType, DistType>::DFS()  
{  
    int *visited = new int[this->m_numVertexs];  
    for (int i=0; i<this->m_numVertexs; i++)  
    {  
        visited[i] = 0;  
    }  
    cout << "head";  
    DFS(0, visited);//从第一个顶点开始遍历  
    cout << "--->end";  
}  
  
template<class NameType, class DistType>   
void Graph<NameType, DistType>::BFS()  
{  
    int *visited = new int[this->m_numVertexs];  
    for (int i=0; i<this->m_numVertexs; i++)  
    {  
        visited[i] = 0;  
    }  
    cout << "head";  
    BFS(0, visited);//从第一个顶点开始遍历  
    cout << "--->end";  
}  
  
//从第v个顶点开始广度遍历  
template<class NameType, class DistType>   
void Graph<NameType, DistType>::BFS(int v, int *visited)  
{  
    cout << "->" << this->GetVertexName(v);  
    visited[v]=1;  
    queue<int> que;//=new queue<int>[this->GetNumVertexs()];  
    que.push(v);//进队（队列的末端）  
    while (!que.empty())  
    {  
        v=que.front();//出队首元素  
        que.pop();//删除队首元素  
        int firstvertex=GetFirst(v);  
        while(firstvertex != -1)  
        {  
            if (!visited[firstvertex])  
            {  
                cout << "->" << this->GetWeight(v, firstvertex);//获得顶点v及其邻点firstVertex之间的权值  
                que.push(firstvertex);  
                visited[firstvertex]=1;  
                cout << "->" << this->GetVertexName(firstvertex);  
            }  
            firstvertex=GetNext(v,firstvertex);  
        }  
    }  
}  
  
//获得在顶点集中的位置为v的顶点的名字  
template<class NameType, class DistType>   
NameType Graph<NameType, DistType>::GetVertexName(int v)  
{  
    if (v<0 || v>=this->m_numVertexs)  
    {  
        cerr << "查找的顶点位置参数有误，请检查！" <<endl;  
        exit(1);  
    }  
    return m_pVertexTable[v].m_vertexName;  
  
}  
  
//获得顶点v的第一个相邻顶点，如果没有就返回-1  
template<class NameType, class DistType>   
int Graph<NameType, DistType>::GetFirst(int v)  
{  
    if (v<0 || v>=this->m_numVertexs)  
    {  
        return -1;  
    }  
    Edge<DistType> *ptemp = this->m_pVertexTable[v].padjEdge;  
    return m_pVertexTable[v].padjEdge ? m_pVertexTable[v].padjEdge->m_nposTable : -1;  
}  