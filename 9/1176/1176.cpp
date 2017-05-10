#include <stdio.h>

struct Node{
	Node *lchild;
	Node *rchild;
	int num;
}Tree[1000];

int loc;
Node *create(){
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

Node *insert(Node *T,int number[1000]){
	T.num = number[];
	T.lchild.num = number
	
}

void order(Node *T,int n){
	if(n > 0){
		if(T->lchild != NULL){
			order(T->lchild);
		}
		if(T->rchild != NULL){
			order(T->rchild);
		}
		
		n--;
	}
	
}

int main(){
	int n;
	Node *ret = create();
	while(scanf("%d",n) != EOF){
		for(int i=0;i<n;i++){
			
			ret.num = 		
		}
	}
}