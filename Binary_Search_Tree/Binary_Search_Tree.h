#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

typedef struct tNode
{
	int value;
	struct tNode *left;
	struct tNode *right;
}BinaryNode;

//创建二叉搜索树
void create_tree(void);


//寻找插入点
static BinaryNode Bianry_Search();

//插入
void Binary_Insert();

//遍历


//删除













#endif
