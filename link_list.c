#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

//创建链表
list creat_l(void)
{
    node* p = (node*)malloc(sizeof(node));

    if (NULL == p)
    {
        perror("malloc");
        return NULL;
    }

    p -> next = NULL;

    list l = NULL;

    l = (list)malloc(sizeof(*l));

    if(NULL == l)
    {
        perror("malloc");
        return NULL;
    }

    l -> head  = l -> tail = p;
    l -> size = 0;

    return l;
}



//销毁
void destory_l(list l)
{
    node* p = NULL;
    while(l -> head)
    {
        p = l -> head -> next;
        free(l -> head);
        l -> head = p;
    }
    free(l);    //释放链表信息结构体
}



//清空
void clear_l(list l)     
{
    node* p = l -> head -> next;
    
    node* k = NULL; //中间节点

    l -> head -> next = NULL;   //头节点指向空，保存下来

    while (p -> next)
    {
        k = p -> next;
        free(p);
        p = k;
    }
    l -> tail = l -> head;
    l -> size  = 0;
}



//头插
void push_front_l(list l , elem_type* data)
{
    //创建一个新节点
    node* p = (node*)malloc(sizeof(node));

    if(NULL == p)
    {
        perror("malloc");
        return ;
    }

    p -> data = *data;

    // 将新节点插入到链表中，原来的第一个节点变为该节点的后继，该节点成为第一个节点
    p -> next = l -> head -> next;
    l -> head -> next = p;

    if(l -> size == 0) l -> tail = p;

    l -> size++; 
}



//尾插
void push_back_l(list l , elem_type* data)
{
    //创建一个新节点
    node* p = (node*)malloc(sizeof(node));

    if(NULL == p)
    {
        perror("malloc");
        return ;
    }

    p -> data = *data;

    // 将新节点插入到链表中，它将成为尾节点，而原来的尾节点的后继为该节点
    p -> next = NULL;
    l -> tail -> next = p;
    l -> tail = p;  //更新链表的尾指针，使其指向新插入的节点p
    l -> size++;
}



//删除某个节点



//修改某个节点（pos从0开始）
void update_l(list l, elem_type* data, int pos)
{
    node* p = l -> head -> next;

    for(int i = 0; i < pos; i++)    p = p -> next;

    p -> data = *data;
}



//查找某个节点



//判空
int empty_l(list l)
{
    return !(l -> size);  //链表非为空返回0
}



//求长度
int size_l(list l)
{
    return l -> size;
}



//随机访问某个数据元素
elem_type* at(list l, int pos)
{
    node* p = l -> head -> next;

    while(pos--) p = p -> next;

    return &(p -> data);
}