#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define LEN 50

typedef struct Node{
	char name[LEN]; //每行路径字串 
	int num;        // 
	struct Node *child[N]; //子孙节点 
}TreeNode;

void create(Node *root, char s[LEN])
{
	int i=0,j;
	char pathName[LEN];
	
	if(s[0] == '\0') //边界条件 
		return;
	//去掉字串中的 \ 
	while(s[i] != '\\' && s[i] != '\0')
	{
		pathName[i] = s[i];
		i++;
	}
	pathName[i] = '\0'; //结束新字串
 	if(s[i] == '\\') //遇见 \就 跳过 
		i++;
 	printf("s=%s, pathName=%s\n",s,pathName);
 	//匹配是否树中有相同节点 
	for(j=0;j<root->num;j++)
	{
		if(strcmp(root->child[j]->name,pathName) == 0)
			break;
	}
	if(j < root->num) //在num个节点中发现相同节点 
	{
		root = root->child[j];
	}else{            //没找到就新创建 
		TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
		strcpy(n1->name,pathName); //把新路径字串传给新节点
		n1->num = 0;
	    root->child[root->num++] = n1;
	    root = n1;
	}
	create(root,s+i);
}

int cmp(const void *a, const void *b)
{
	TreeNode **x = (TreeNode **)a;
	TreeNode **y = (TreeNode **)b;
	return strcmp((*x)->name,(*y)->name);
}

void DFS(Node *root, int addLen)
{
	int i;
	if(addLen >= 0)
	{
		for(i=0;i<addLen;i++)
			printf(" ");
		printf("%s\n",root->name);
	}
	qsort(root->child,root->num,sizeof(TreeNode *),cmp);
	for(i=0;i<root->num;i++)
	{
		DFS(root->child[i],addLen + strlen(root->name)+1);
	}
}

int main()
{
	int n;
	int i;
	char s[LEN];
	TreeNode root;
	
	while(scanf("%d",&n) != EOF && n)
	{
		root.name[0] = '\0';
		root.num = 0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			create(&root,s);
		}
		DFS(&root,-1);
		printf("\n");
	}
	return 0;
}

 