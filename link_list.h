#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef int elem_type;

typedef struct node
{
    elem_type data;
    struct node* next; 
}node;

typedef struct list
{
    node* head;
    node* tail;
    int size;
    int cap;
}*list;



list creat_l(void);  //创建链表
void push_front_l(list l , elem_type* data);  //头插
void push_back_l(list l , elem_type* data);   //尾插
void destory_l(list l);   //销毁
void clear_l(list l);     //清空
int empty_l(list l);     //判空
int size_l(list l);     //求长度
elem_type* at(list l, int pos);     //随机访问某个数据元素
void update_l(list l, elem_type* data, int pos);     //修改某个节点（pos从0开始）

#endif