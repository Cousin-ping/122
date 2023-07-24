#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// 有头节点
link_node_t *CreateEpLinkList()
{
    link_node_list p=(link_node_list)malloc(sizeof(link_node_t));
    if (NULL==p)
    {
        perror("node malloc err!!!");
        return NULL;
    }
    p->next=NULL;
    return p;
}
//p保存链表的头指针 post 插入的位置 data插入的数据
int InsertIntoPostLinkList(link_node_t *p,int post, datatype data)
{
    if (post<0)
    {
        printf("post err\n");
        return -1;
    }
    
    link_node_list p_new=CreateEpLinkList();
    p_new->next=NULL;

    for (size_t i = 0; i < post; i++)
    {
        if (NULL==p->next)
        {
            p->next=p_new;
            p_new->data=data;
            p_new->next=NULL;
            return 0;
        }
        p=p->next;
    }
    p_new->data=data;
    p_new->next=p->next;
    p->next=p_new;
    return 0;

}

//3.遍历单向链表
void ShowLinkList(link_node_t *p)
{
    p=p->next;
    while (p!=NULL)
    {
        printf("%c\n",p->data);
        p=p->next;
    }
    
}
//4.求单向链表长度的函数
int LengthLinkList(link_node_t *p)
{
    int len=0;
    while (p->next!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
//5.删除单向链表中指定位置的数据 post 代表的是删除的位置
int DeletePostLinkList(link_node_t *p, int post)
{
    link_node_list pdel=NULL;
    if (post<0 || post>=LengthLinkList(p)||IsEpLinkList(p))
    {
        printf("Delete post err\n");
        return -1;
    }

    for (size_t i = 0; i < post; i++)
    {
        p=p->next;
    }
    pdel=p->next;
    p->next=pdel->next;
    free(pdel);
    pdel=NULL;
    return 0;
}
//6.判断单向链表是否为空 1代表空 0代表非空
int IsEpLinkList(link_node_t *p)
{
        return NULL==p->next;
}
//7.修改指定位置的数据 post 被修改的位置 data修改成的数据
int ChangePostLinkList(link_node_t *p, int post, datatype data)
{
    if(p->next==NULL)
        printf("该链表无有效数据\n");
    if (p==NULL)
        printf("请输入有效参数\n");
    for (size_t i = 0; i < post; i++)
    {
        p=p->next;
    }
    p->data=data;
    
}
//8.查找指定数据出现的位置 data被查找的数据 //search 查找
int SearchDataLinkList(link_node_t *p, datatype data)
{
    int num=0;
    if(p->next==NULL)
        printf("该链表无有效数据\n");
    if (p==NULL)
        printf("请输入有效参数\n");
    while (p->next!=NULL)
    {
        p=p->next;
        num++;
        if (p->data==data)
        {
            return num;
        }
        
    }
        
}
//9.删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
int DeleteDataLinkList(link_node_t *p, datatype data)
{
    link_node_list pdel=NULL;
    link_node_list temp=p;
    // link_node_list temp_t=NULL;
    int count=0;
    if(p->next==NULL)
        printf("该链表无有效数据\n");
    if (p==NULL)
        printf("请输入有效参数\n");
    while (temp->next!=NULL)
    {
        if (temp->data==data)
            count++;
        temp=temp->next;
    }
    if (temp->data==data)
    {
        count++;
    }
    printf("重复次数为%d\n",count);

        temp=p;
        while (temp->next!=NULL)
        {
            if (temp->next->data==data)
            {
                pdel=temp->next;
                temp->next=pdel->next;
                free(pdel);
                pdel=NULL;
                
            }
            else
            temp=temp->next;
        

    }  
}
//10.转置链表 简单粗暴版本
// void ReverseLinkList(link_node_t *p)
// {
//     link_node_list head=p;
//     int len=LengthLinkList(p);
//     datatype temp[16]={};
//     link_node_list pre=NULL;
//     link_node_list pnew=CreateEpLinkList();
//     for (size_t i = len; i>0; i--)
//     {
//         temp[i]=p->data;
//         p=p->next;
//     }
//     temp[0]=p->data;
//     head->next=NULL;
//     for (size_t i = 0; i <len; i++)
//     {
//         head_insert(head,temp[i]);
//     }
//     ClearLinkList(p);
// }

void ReverseLinkList(link_node_t *p)
{
    link_node_list temp=NULL;

    link_node_list q=p->next;
    p->next=NULL;
    while (q!=NULL)
    {
        temp=q->next;
        q->next=p->next;
        p->next=q;

        q=temp;
    }
    
}
//11.清空单向链表
void ClearLinkList(link_node_t *p)
{   
    link_node_list pdel=NULL;
    while (p->next!=NULL)
    {
        pdel = p->next;
        p->next=pdel->next;
        free(pdel);
        pdel=NULL;
    }
    
}
//头插法
link_node_list head_insert(link_node_list p,datatype data)
{
    link_node_list head=p;
    link_node_list p_new=CreateEpLinkList();
    p_new->next=NULL;

        if (NULL==p->next)
        {
            p->next=p_new;
            p_new->data=data;
            p_new->next=NULL;
        }
        else
        {
            while (p->next!=NULL)
            {
                p=p->next;
            }
            p_new->data=data;
            p->next=p_new;
        }
        

        
    
}
