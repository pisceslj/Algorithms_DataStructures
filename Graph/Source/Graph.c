#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 20   //图可以存储的最大节点数为20；
<<<<<<< HEAD
struct tnode
{
    struct tnode * next;//指向下一个临节点
    int data;//存放邻节点在数组中的位置
};
=======

struct tnode
{
    struct tnode * next;//指向下一个邻节点
    int post;//存放邻节点在数组中的位置
};

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
struct node
{
    int valu;//存放节点的值
    struct tnode * link;//指向邻节点
};
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
struct picture
{
    struct node nd[MAX];    //声明一个节点数组
    int count;  //图中的节点数
    char a; //建立的图的类型
};
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
struct picture * createpicture();
int search(struct picture *p,int value);//查找value在nd数组中的位置
void bfs(struct picture * q,int i,int visit[]); //广度优先遍历
void dfs(struct picture * q,int i,int visit[]);//深度优先遍历
void traversedfs(struct picture *p);
void traversebfs(struct picture *p);
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
int main()
{
    char a;
    struct picture *p;
<<<<<<< HEAD
    p=createpicture();
=======
    p=createpicture();//创建图

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
    while(1)
    {
        getchar();
        printf("现在将对图进行遍历，若使用广度优先遍历，请输入a,若使用深度优先遍历请输入b，清屏请输入c,退出请输入d:\n");
        scanf("%c",&a);
        if(a=='a')
        {
<<<<<<< HEAD
        printf("深度优先遍历如下：\n");
        traversebfs(p);
        }
        if(a=='b')
        {
        printf("广度优先遍历如下：\n");
        traversedfs(p);
        }
        if(a=='c')
        system("cls");
        if(a=='d')
        exit(0);
    }
    return 0;
}
=======
		    printf("深度优先遍历如下：\n");
		    traversebfs(p);
        }
        if(a=='b')
        {
		    printf("广度优先遍历如下：\n");
		    traversedfs(p);
        }
        if(a=='c')
        	system("cls");
        if(a=='d')
        	exit(0);
    }
    return 0;
}

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
struct picture * createpicture()
{
    int i,j,k,l;//l中存放返回的节点在数组中的位置
    char a;
    struct picture *p;
    p=(struct picture *)malloc(sizeof(struct picture));
    struct tnode * t;
    printf("请输入你要建立的图中的节点数以及图的类型(a表示无向图b表示有向图):\n");
    scanf("%d %c",&i,&a);
    p->count=i;
    p->a=a;
    printf("请依次输入各节点的值(每输完一个节点的值按回车结束)：\n");
    for(i=0;i<p->count;i++)
    {
        scanf("%d",&j);
        p->nd[i].valu=j;
        p->nd[i].link=NULL;
    }
    for(i=0;i<p->count;i++)
    {
        printf("输入与数据值为%d的节点相邻的节点的数据值(每输完一个节点的值按回车结束),若不再含有相邻的值请输入-1\n",p->nd[i].valu);
        while(1)
        {
            scanf("%d",&k);
            if(k==-1)
                break;
            l=search(p,k);
            if(l!=-1)
            {
                t=(struct tnode *)malloc(sizeof(struct tnode));
<<<<<<< HEAD
                t->data=l;
=======
                t->post=l;
>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
                t->next=p->nd[i].link;
                p->nd[i].link=t;
            }
            else
                printf("无此数据值!\n");
            //getchar();
        }
    }
    return p;
}
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
int search(struct picture *p,int value)
{
    int i;
    for(i=0;i<p->count;i++)
    {
        if(value==p->nd[i].valu)
        {
            return i;
        }
    }
    return -1;
}
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
void traversedfs(struct picture *p)
{
    int i;
    int visit[MAX];//申明一个标志数组,将其初始值置为0,0表示该节点未被访问过，1表示该节点被访问过
    for(i=0;i<p->count;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<p->count;i++)
    {
        if(visit[i]==0)
        {
            dfs(p,i,visit);
        }
    }
    //getchar();
}
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
void dfs(struct picture * q,int i,int visit[])//i表示数组的下标值visit的下标与p中的下标是一一对应的关系
{
    struct tnode * w;
    printf("%d\n",q->nd[i].valu);
    visit[i]=1;
    w=q->nd[i].link;
    while(w!=NULL)
    {
<<<<<<< HEAD
        if(visit[w->data]==0)
        {
            dfs(q,w->data,visit);
=======
        if(visit[w->post]==0)
        {
            dfs(q,w->post,visit);
>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
        }
        else
        {
            w=w->next;
        }
    }   
}
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
void traversebfs(struct picture *p)
{
    int i;
    int visit[MAX];//申明一个标志数组,将其初始值置为0,0表示该节点未被访问过，1表示该节点被访问过
    for(i=0;i<p->count;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<p->count;i++)
    {
        if(visit[i]==0)
        {
            bfs(p,i,visit);
        }
    }
    //getchar();
}
<<<<<<< HEAD
=======

>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
void bfs(struct picture * q,int i,int visit[])
{
    struct tnode *w;
    int a[MAX];//声明一个队列
    int f,r;
    int v;
    f=r=0;
    visit[i]=1;
    printf("%d\n",q->nd[i].valu);
    a[r]=i;
    r++;//进行入队操作
    while(f!=r)
    {
        v=a[f];
        f++;//岀队操作
        w=q->nd[v].link;
        while(w!=NULL)
        {
<<<<<<< HEAD
            if(visit[w->data]==0)
            {
            visit[w->data]=1;
            printf("%d\n",q->nd[w->data].valu);
            a[r]=w->data;
=======
            if(visit[w->post]==0)
            {
            visit[w->post]=1;
            printf("%d\n",q->nd[w->post].valu);
            a[r]=w->post;
>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
            r++;
            }
            w=w->next;
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 5f14e66bf164e71353b8f4e8a85ab5efa871eb1c
