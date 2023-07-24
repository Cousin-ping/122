#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

//1.创建一个空的顺序表
seqlist_t *CreateEpSeqlist() //返回的是申请空间的首地址
{
    //动态开辟一个结构体空间
    seqlist_t *p = (seqlist_t *)malloc(sizeof(seqlist_t));
    if (NULL == p)
    {
        perror(" malloc err");
        return NULL;
    }
    //对last进行初始化
    p->last = -1; //数据为空
    return p;
}
//4.判断顺序表是否为满,满返回１　未满返回０
int IsFullSeqlist(seqlist_t *p)
{
    return p->last + 1 == N; //满返回1,未满返回0
}
//2.向顺序表的指定位置插入数据
int InsertIntoSeqlist(seqlist_t *p, int post, int data) //post第几个位置，data插入的数据
{
    int i;
    //1.容错判断
    if (IsFullSeqlist(p) || post > p->last + 1 || post < 0)
    {
        printf("InsertIntoSeqlist err\n");
        return -1;
    }
    //2.将last~post位置向后移动一个位置
    for (i = p->last; i >= post; i--)
    {
        p->data[i + 1] = p->data[i];
    }
    //3.将数据放到顺序表中
    p->data[post] = data;
    //4.最后一个元素的下标+1，因为插入了一个数据
    p->last++;
    return 0;
}
//3.遍历顺序表sequence 顺序　list 表
void ShowSeqlist(seqlist_t *p)
{
    int i;
    for (i = 0; i <= p->last; i++)
        printf("%d  ", p->data[i]);
    printf("\n");
}
//5.判断顺序表是否为空  空返回1,非空返回0
int IsEpSeqlist(seqlist_t *p)
{
    return p->last == -1;
}
//6.删除顺序表中指定位置的数据post删除位置
int DeletePostSeqlist(seqlist_t *p, int post)
{
    int i;
    //1.容错判断
    if (post < 0 || post > p->last || IsEpSeqlist(p))
    {
        printf("DeletePostSeqlist err\n");
        return -1;
    }
    //2.将post+1～last位置数据整体向前移动一个位置
    for (i = post + 1; i <= p->last; i++)
        p->data[i - 1] = p->data[i];
    //3.有效元素个数-1;
    p->last--;
    return 0;
}
//7.清空顺序表
void ClearSeqList(seqlist_t *p)
{
    p->last = -1;
}
//8.修改指定位置的数据
int ChangePostSeqList(seqlist_t *p, int post, int data) //post被修改的位置，data修改成的数据
{
    //1.容错判断
    if (post < 0 || post > p->last)
    {
        printf("ChangePostSeqList err\n");
        return -1;
    }
    //2.修改数据
    p->data[post] = data;
    return 0;
}
//9.查找指定数据出现的位置
int SearchDataSeqList(seqlist_t *p, int data) //data代表被查找的数据
{
    int i;
    for (i = 0; i <= p->last; i++)
    {
        if (p->data[i] == data)
            return i; //返回下标
    }
    return -1; //没找到
}