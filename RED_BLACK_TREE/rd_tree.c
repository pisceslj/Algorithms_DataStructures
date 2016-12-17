struct rb_node  
{  
    unsigned long  rb_parent_color;  
  #define RB_RED      0  
  #define RB_BLACK    1  
    struct rb_node *rb_right;  
    struct rb_node *rb_left;  
} __attribute__((aligned(sizeof(long)))); 

//获得其双亲结点的首地址  
#define rb_parent(r)  ((struct rb_node *)((r)->rb_parent_color & ~3))  
//获得颜色属性
#define rb_color(r)   ((r)->rb_parent_color & 1)   
//判断颜色属性是否为红  
#define rb_is_red(r)   (!rb_color(r))   
//判断颜色属性是否为黑  
#define rb_is_black(r) rb_color(r) 
//设置红色属性 
#define rb_set_red(r)  do { (r)->rb_parent_color &= ~1; } while (0)   
//设置黑色属性
#define rb_set_black(r)  do { (r)->rb_parent_color |= 1; } while (0) 

static inline void rb_set_parent(struct rb_node *rb, struct rb_node *p)  //设置其双亲结点首地址的函数  
{  
     rb->rb_parent_color = (rb->rb_parent_color & 3) | (unsigned long)p;  
}   

//设置结点颜色属性的函数  
static inline void rb_set_color(struct rb_node *rb, int color) 
{  
    rb->rb_parent_color = (rb->rb_parent_color & ~1) | color;  
}

 初始化新结点： 
[cpp] view plain copy
  1. static inline void rb_link_node(struct rb_node * node, struct rb_node * parent,  
  2.                 struct rb_node ** rb_link)  
  3. {  
  4.     node->rb_parent_color = (unsigned long )parent;   //设置其双亲结点的首地址(根结点的双亲结点为NULL),且颜色属性设为黑色  
  5.     node->rb_left = node->rb_right = NULL;   //初始化新结点的左右子树  
  6.   
  7.     *rb_link = node;  //指向新结点  
  8. }   


  指向红黑树根结点的指针： 
[cpp] view plain copy
  1. struct rb_root  
  2. {  
  3.     struct rb_node *rb_node;  
  4. };  
  5.   
  6.   
  7. #define RB_ROOT (struct rb_root) { NULL, }  //初始化指向红黑树根结点的指针  
  8. #define rb_entry(ptr, type, member) container_of(ptr, type, member) //用来获得包含struct rb_node的结构体的首地址  
  9.   
  10. #define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL) //判断树是否为空  
  11. #define RB_EMPTY_NODE(node) (rb_parent(node) == node)  //判断node的双亲结点是否为自身  
  12. #define RB_CLEAR_NODE(node) (rb_set_parent(node, node)) //设置双亲结点为自身 