  #include <stdio.h>  
  #include <stdlib.h>  
    
  typedef int data_type;  
    
  typedef struct bst_node 
  {  
       data_type data;  
       struct bst_node *lchild, *rchild;  
  }bst_t, *bst_p; 


/********插入**********/
 static bst_p search_bst_for_insert(bst_p *root, data_type key)  
 {  
     bst_p s, p = *root;  
   
     while (p) 
     {  
	      s = p;  
	      if (p->data == key)  
	           return NULL;  
	       p = (key < p->data) ? p->lchild : p->rchild;  
      }     
      return s;  
 }  

 void insert_bst_node(bst_p *root, data_type data)  
 {  
      bst_p s, p;  

      s = malloc(sizeof(struct bst_node));  
      if (!s)  
      	perror("Allocate dynamic memory");  
    
       s -> data = data;  
  	    s -> lchild = s -> rchild = NULL;  
     
      if (*root == NULL)  
  		    *root = s;  
      else
      {  
	       	p = search_bst_for_insert(root, data);  
	       if (p == NULL) 
	       {  
	          fprintf(stderr, "The %d already exists.\n", data);  
	          free(s);  
	           return;  
      }  
     
       if (data < p->data)  
           p->lchild = s;  
       else  
           p->rchild = s;  
       }  
   }  

  /****************遍历**********************/
  static int print(data_type data)  
  {  
       printf("%d ", data);   
       return 1;  
   }  
    
  int pre_order_traverse(bst_p root, int (*visit(data_type data))   
  {  
       if (root) 
       {  
       if (visit(root->data))  
           if (pre_order_traverse(root->lchild, visit))  
               if (pre_order_traverse(root->rchild, visit))  
                   return 1;  
       return 0;  
       }  
       else  
       return 1;  
   }  
     
   int post_order_traverse(bst_p root, int (*visit(data_type data))  
   {  
       if (root)
       {  
	       if (post_order_traverse(root->lchild, visit))  
	           if (visit(root->data))  
	           if (post_order_traverse(root->rchild, visit))  
	               return 1;  
	       return 0;  
       }  
       else  
       return 1;  
   }  



  /********************删除******************/
  void delete_bst_node(bst_p *root, data_type data)  
  {  
       bst_p p = *root, parent, s;  
     
       if (!p) 
       {  
	      fprintf(stderr, "Not found %d.\n", data);  
	      return;  
      }  
     
       if (p->data == data) 
       {  
	       /* It's a leaf node */  
	       if (!p->rchild && !p->lchild)
	        {  
	           *root = NULL;  
	           free(p);  
	       }  
	       /* the right child is NULL */  
	       else if (!p->rchild) 
	       {  
	           *root = p->lchild;  
	          free(p);  
	      	}  
	       /* the left child is NULL */  
	       else if (!p->lchild) 
	       {  
	           *root = p->rchild;  
	           free(p);  
	       }  
	       /* the node has both children */  
	       else 
	       {  
	           s = p->rchild;  
	           /* the s without left child */  
	           if (!s->lchild)  
	           		s->lchild = p->lchild;  
	           /* the s have left child */  
	           else 
	           {  
		           /* find the smallest node in the left subtree of s */  
		           while (s->lchild) 
		           {  
		               /* record the parent node of s */  
		               parent = s;  
		               s = s->lchild;  
		           }  
		           parent->lchild = s->rchild;  
		          s->lchild = p->lchild;  
		           s->rchild = p->rchild;  
	         }  
	          *root = s;  
	           free(p);  
	       }  
       }   
       else if (data > p->data) 
       {  
       		delete_bst_node(&(p->rchild), data);  
       }   
      else if (data < p->data) 
      {  
       		delete_bst_node(&(p->lchild), data);  
       }  
   }  



  /*******************main***************/
  int main(int argc, char *argv[])  
  {  
       int i, num;  
       bst_p root = NULL;  
     
       if (argc < 2) 
       {  
	       fprintf(stderr, "Usage: %s num\n", argv[0]);  
	       exit(-1);  
       }  
     
       num = atoi(argv[1]);  
       data_type arr[num];  
       printf("Please enter %d integers:\n", num);  
       for (i = 0; i < num; i++) 
       {  
	       scanf("%d", &arr[i]);  
	       insert_bst_node(&root, arr[i]);  
       }  
     
       printf("\npre order traverse: ");  
       pre_order_traverse(root, print);  
       printf("\npost order traverse: ");  
       post_order_traverse(root, print);  
       printf("\n");  
     
       delete_bst_node(&root, 45);  
     
       printf("\npre order traverse: ");  
       pre_order_traverse(root, print);  
       printf("\npost order traverse: ");  
      post_order_traverse(root, print);  
       printf("\n");  
         
       return 0;  
   }  