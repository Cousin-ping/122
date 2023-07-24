#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
//1.创建一个空的单向链表(有头单向链表)
link_node_t *CreateEpLinkList()
{
    //思想：创建一个节点作为头节点
    link_list_t p = (link_list_t)malloc(sizeof(link_node_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    p->next = NULL;
    return p;
}
//4.求单向链表长度的函数
int LengthLinkList(link_node_t *p)
{
    int len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
//2.向单向链表的指定位置插入数据
//p保存链表的头指针 post 插入的位置 data插入的数据
int InsertIntoPostLinkList(link_node_t *p, int post, datatype data)
{
    int i;
    link_list_t pnew = NULL;
    //1.容错处理
    if (post < 0 || post > LengthLinkList(p))
    {
        printf("InsertIntoPostLinkList err\n");
        return -1;
    }
    //2.将头指针移动到插入位置的前一个节点
    for (i = 0; i < post; i++)
        p = p->next;
    //3.创建一个新节点，保存插入的数据
    pnew = (link_list_t)malloc(sizeof(link_node_t));
    if (NULL == pnew)
    {
        perror("pnew malloc err");
        return -1;
    }
    pnew->data = data;
    pnew->next = NULL;
    //4.将新节点插入链表（先连后面，再连前面）
    pnew->next = p->next; //后
    p->next = pnew;       //前

    return 0;
}
//3.遍历单向链表
void ShowLinkList(link_node_t *p)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d  ", p->data);
    }
    printf("\n");
}
//6.判断单向链表是否为空 1代表空 0代表非空
int IsEpLinkList(link_node_t *p)
{
    return p->next == NULL;
}
//5.删除单向链表中指定位置的数据 post 代表的是删除的位置
int DeletePostLinkList(link_node_t *p, int post)
{
    int i;
    link_list_t pdel = NULL;
    //1.容错处理
    if (IsEpLinkList(p) || post < 0 || post >= LengthLinkList(p))
    {
        printf("DeletePostLinkList err\n");
        return -1;
    }
    //2.将头节点指向被删除节点的前一个位置
    for (i = 0; i < post; i++)
        p = p->next;
    //3.进行删除操作
    //1）定义pdel指针指向被删除节点
    pdel = p->next;
    //2）跨过被删除节点
    p->next = pdel->next;
    //3）释放被删除节点
    free(pdel);
    pdel = NULL;
    return 0;
}
//7.修改指定位置的数据 post 被修改的位置 data修改成的数据
int ChangePostLinkList(link_node_t *p, int post, datatype data)
{
    int i;
    //1.容错判断
    if (post < 0 || post >= LengthLinkList(p))
    {
        printf("ChangePostLinkList err\n");
        return -1;
    }
    //2.将头指针移动到被修改的节点位置
    for (i = 0; i <= post; i++)
    {
        p = p->next;
    }
    //3.修改数据
    p->data = data;
    return 0;
}
//8.查找指定数据出现的位置 data被查找的数据 //search 查找
int SearchDataLinkList(link_node_t *p, datatype data)
{
    int post = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data == data)
            return post;
        post++;
    }
    return -1; //无数据
}

//9.删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
int DeleteDataLinkList(link_node_t *p, datatype data)
{
    link_list_t pdel = NULL;
    //1.定义一个指针指向p的下一个节点
    link_list_t q = p->next;
    //2.遍历无头单项链表
    while (q != NULL)
    {
        if (q->data == data)
        {
            //1)定义pdel指向删除节点
            pdel = q;
            //2）跨过被删除节点
            p->next = pdel->next;
            //3）释放删除节点
            free(pdel);
            pdel = NULL;
            //4）将q重新指向p的下一个节点
            q = p->next;
        }
        else
        {
            p = p->next;
            q = p->next;
        }
    }
    return 0;
}
//11.清空单向链表
void ClearLinkList(link_node_t *p)
{
    link_list_t pdel = NULL;
    while (p->next != NULL)
    {
        //1)将pdel指向被删除节点,也就是头节点的下一个节点
        pdel = p->next;
        //2)跨过被删除节点
        p->next = pdel->next;
        //3）释放节点
        free(pdel);
        pdel = NULL;
    }
}

//10.转置链表
void ReverseLinkList(link_node_t *p)
{
    link_list_t temp = NULL; //暂时保存q的下一个节点
    //1.断头前保存头节点的下一个节点的地址
    link_list_t q = p->next; //相当于无头单项链表的头指针
    //2.断开链表
    p->next = NULL;
    //3.遍历无头单项链表
    while (q != NULL)
    {
        temp = q->next;//提前将q的下一个节点保存一下
        //先连后面，再连前面
        q->next = p->next;//q已经无法找到之前的下一个节点
        p->next = q;

        q=temp;//将q移动，指向无头单项链表的下一个节点
    }
}
