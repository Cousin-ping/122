#include<stdio.h>
#include<stdlib.h>
#include"double_link_list.h"

//1.创建一个空的双向链表
double_list_t createEmptyDoubleLinkList()
{
    double_list_t p=(double_list_t)malloc(sizeof(double_node_t));
    if (NULL==p)
    {
        perror("double_list_t malloc err");
        return NULL;
    }
   
    p->head=(link_list_t)malloc(sizeof(link_node_t));
    if (NULL==p->head)
    {
        perror("link_node_t malloc err");
        return NULL;
    }else{
        p->tail=p->head;
        p->len=0;
        p->head->next=NULL;
        p->head->prior=NULL;
        return p;
    }
    
}
//2.向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data)
{
    link_list_t temp=NULL;
    if (post<0)
    {
        perror("insert Err");
        return -1;
    }
    link_list_t pnew=(link_list_t)malloc(sizeof(link_node_t));
    if (NULL==pnew)
    {
        perror("pnew malloc Err");
        return -1;
    }
    pnew->data=data;
    pnew->next=pnew->prior=NULL;
    //插入在尾部
    if (post==p->len)
    {
        p->tail->next=pnew;
        pnew->prior=p->tail;
        p->tail=pnew;
    }
    else
    {
        if (post<p->len/2)//post在前半段
        {
            temp=p->head;
            for (int i = 0; i < post+1; i++)
            {
                temp=temp->next;
            }
        }            
        else //post在后半段
        {
            temp=p->tail;
            for (int i = 0; i < p->len-post; i++)
            {
                temp=temp->prior;
            }
            
        }
        //插入
        pnew->prior=temp->next;
        pnew->next=temp->next->prior;
        temp->next=pnew;
        temp->next->prior=pnew->next;
        
        // pnew->prior=temp->prior;
        // temp->prior->next=pnew;
        // pnew->next=temp;
        // temp->prior=pnew;
    }
    p->len++;
    return 0;
}
//3.遍历双向链表
void showDoubleLinkList(double_list_t p)
{
    // double_list_t pt=p;
    int len=p->len;
    // printf("当前长度为%d\n",len);
    if (0==len)
    {
        perror("double_link is Empty");
        exit(1);
    }
    link_list_t pc=p->head->next;
    printf("开始输出链表内容\n");
    while (len)
    {
        printf("%d\n",pc->data);
        len--;
        pc=pc->next;
    }
    
}
//4.删除双向链表指定位置的数据
int deletePostDoubleLinkList(double_list_t p, int post)
{
    if (post<0||post>p->len||isEmptyDoubleLinkList(p))
    {
        perror("delete_post Err");
        return -1;
    }

    link_list_t pdel=NULL;
    //在尾部
    if (post==p->len-1)
    {
        printf("开始删除尾部\n");
        p->tail=p->tail->prior;
        free(p->tail->next);
        p->tail->next=NULL;
    }
    else
    {
        printf("开始删除\n");
        if (post<p->len/2)//post在前半段
        {
            pdel=p->head;
            for (int i = 0; i < post; i++)
            {
                pdel=pdel->next;
            }
        }            
        else //post在后半段
        {
            pdel=p->tail;
            for (int i = 0; i < p->len-post-1; i++)
            {
                pdel=pdel->prior;
            }
            
        }
        //真正开始删除
        pdel->prior->next=pdel->next;
        pdel->next->prior=pdel->prior;
       
        free(pdel);
        pdel=NULL;

    }
    p->len--;
    return 0;
}
//5.判断双向链表是否为空
int isEmptyDoubleLinkList(double_list_t p)
{
    return p->len==0;
}
//6.求双向链表的长度
int lengthDoubleLinkList(double_list_t p)
{
    return p->len;
}
//7.查找指定数据出现的位置 data被查找的数据
int searchPostDoubleLinkList(double_list_t p,datatype data)
{
    
    if (isEmptyDoubleLinkList(p))
    {
        perror("list is Empty");
        return -1;
    }
    int temp=0;
    link_list_t pt=p->head;
    while (pt->data!=data)
    {
        pt=pt->next;
        temp++;
    }
    return temp;
    
}
//8.修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_t p,int post, datatype data)
{
    if (post<0||post>p->len||isEmptyDoubleLinkList(p))
    {
        perror("change Err");
        return -1;
    }
    link_list_t temp=NULL;
    //在尾部
    if (post==p->len)
    {
        p->tail->data=data;
    }
    else
    {
        if (post<p->len/2)//post在前半段
        {
            temp=p->head;
            for (int i = 0; i <post+1; i++)
            {
                temp=temp->next;
            }
        }            
        else //post在后半段
        {
            temp=p->tail;
            for (int i = 0; i < p->len-post-1; i++)
            {
                temp=temp->prior;
            }
            
        }
        //修改
        temp->data=data;
    }
    return 0;
    
}
//9.删除双向链表中的指定数据 data代表删除所有出现的data数据
int deleteDataDoubleLinkList(double_list_t p, datatype data)
{
    if (isEmptyDoubleLinkList(p))
    {
        perror("delete_Data Err");
        return -1;
    }
    link_list_t pc=p->head->next;
    link_list_t pdel=NULL;
    int temp_len=0;
    while (pc)
    {
        
        pdel=pc;
        if (pc->data==data)
        {
            pdel->prior->next=pdel->next;
            pdel->next->prior=pdel->prior;
            free(pdel);
            pdel=NULL;
            p->len--;
            
        }
        else
        {
            pc=pc->next;
        }
        
    }
    
}