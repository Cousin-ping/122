#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node_t
{
    datatype data;
    struct node_t *next;
    struct node_t *prior;
} link_node_t, *link_list_t;

typedef struct doublelist
{
    link_list_t head;
    link_list_t tail;
    int len;
} double_node_t, *double_list_t;

//1.创建一个空的双向链表
double_list_t createEmptyDoubleLinkList()
{
    //1.申请保存头尾指针的结构体空间
    double_list_t p = (double_list_t)malloc(sizeof(double_node_t));
    if (p == NULL)
    {
        printf("p malloc err\n");
        return NULL;
    }
    //2.将头尾指针同时指向头节点,因为此时链表为空
    p->len = 0;
    p->head = p->tail = (link_list_t)malloc(sizeof(link_node_t));
    if (p->head == NULL)
    {
        printf("p->head malloc err\n");
        free(p);
        p = NULL;
        return NULL;
    }
    //3.双向链表的头节点初始化
    p->head->prior = NULL;
    p->head->next = NULL;
    return p;
}
//2.向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data)
{
    int i;
    link_list_t pnew = NULL;
    link_list_t temp = NULL;
    //1.容错判断
    if (post < 0 || post > p->len)
    {
        printf("insertIntoDoubleLinkList err\n");
        return -1;
    }
    //2.创建一个新节点，用来保存数据
    pnew = (link_list_t)malloc(sizeof(link_node_t));
    if (pnew == NULL)
    {
        printf("pnew malloc err\n");
        return -1;
    }
    pnew->data = data;
    pnew->next = NULL;
    pnew->prior = NULL;

    //3.将节点插入到链表中
    //对于位置分析有两种情况
    //3.1尾插post == p->len
    if (post == p->len)
    {
        p->tail->next = pnew;
        pnew->prior = p->tail;
        p->tail = pnew; // 移动尾指针
    }
    //3.2 post :0~p->len
    else
    {
        //3.2.1将temp移动到被插入的位置
        if (post < p->len / 2) //前半段，头指针遍历
        {
            temp = p->head;
            for (i = 0; i <= post; i++)
                temp = temp->next;
        }
        else //后半段，尾指针遍历
        {
            temp = p->tail;
            for (i = 0; i < p->len - post - 1; i++)
                temp = temp->prior;
        }
        //3.2.2连接（先连前面，再连后面）
        pnew->prior = temp->prior;
        temp->prior->next = pnew;
        pnew->next = temp;
        temp->prior = pnew;
    }
    //3.3长度++
    p->len++;
    return 0;
}
//3.遍历双向链表
void showDoubleLinkList(double_list_t p)
{
    printf("正向遍历\n");
    link_list_t temp = p->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n反向遍历：\n");
    temp = p->tail;
    while (temp != p->head)
    {
        printf("%d ", temp->data);
        temp = temp->prior;
    }
    printf("\n-----------------------\n");
}

//5.判断双向链表是否为空
int isEmptyDoubleLinkList(double_list_t p)
{
    return p->len == 0;
}

//4.删除双向链表指定位置的数据
int deletePostDoubleLinkList(double_list_t p, int post)
{
    int i;
    link_list_t temp = NULL;
    //1.容错判断
    if (post < 0 || post >= p->len || isEmptyDoubleLinkList(p))
    {
        printf("deletePostDoubleLinkList err\n");
        return -1;
    }
    //2.对删除的位置进行分析
    //2.1尾删
    if (post == p->len - 1)
    {
        p->tail = p->tail->prior; //跨过被删除节点
        free(p->tail->next);      //释放尾节点
        p->tail->next = NULL;
    }
    //2.2
    else
    {
        //2.2.1判断前半段还是后半段
        if (post < p->len / 2) //前半段，头指针遍历
        {
            temp = p->head;
            for (i = 0; i <= post; i++)
                temp = temp->next;
        }
        else //后半段，尾指针遍历
        {
            temp = p->tail;
            for (i = 0; i < p->len - post - 1; i++)
                temp = temp->prior;
        }
        //2.2.2删除
        temp->prior->next = temp->next;
        temp->next->prior = temp->prior;
        free(temp);
        temp = NULL;
    }
    //3.长度-1;
    p->len--;
    return 0;
}

//6.求双向链表的长度
int lengthDoubleLinkList(double_list_t p)
{
    return p->len;
}

//7.查找指定数据出现的位置 data被查找的数据
int searchPostDoubleLinkList(double_list_t p, datatype data)
{
    link_list_t temp = p->head;
    int post = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (data == temp->data)
            return post;
        post++;
    }
    return -1;
}

//8.修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_t p, int post, datatype data)
{
    link_list_t temp = NULL;
    int i;
    //1.容错判断
    if (post < 0 || post >= p->len || isEmptyDoubleLinkList(p))
    {
        printf("changeDataDoubleLinkList err\n");
        return -1;
    }
    //2.将temp移动到被修改的位置
    //2.2.1判断前半段还是后半段
    if (post < p->len / 2) //前半段，头指针遍历
    {
        temp = p->head;
        for (i = 0; i <= post; i++)
            temp = temp->next;
    }
    else //后半段，尾指针遍历
    {
        temp = p->tail;
        for (i = 0; i < p->len - post - 1; i++)
            temp = temp->prior;
    }
    //3.修改数据
    temp->data = data;
    return 0;
}

//9.删除双向链表中的指定数据 data代表删除所有出现的data数据
int deleteDataDoubleLinkList(double_list_t p, datatype data)
{
    link_list_t pdel = NULL;
    link_list_t h = p->head->next;
    while( h != NULL)
    {
        if(h->data == data)
        {
            if(h == p->tail)//尾删
            {
                p->tail = p->tail->prior;
                free(p->tail->next);
                p->tail->next=NULL;
            }
            else
            {
                h->prior->next = h->next;
                h->next->prior = h->prior;
                pdel = h;
                h=h->next;
                free(pdel);
                pdel=NULL;   
            }
            p->len--;
        }
        else
        {
            h=h->next;
        }  
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    double_list_t p = createEmptyDoubleLinkList();
    insertIntoDoubleLinkList(p, 0, 1);
    insertIntoDoubleLinkList(p, 1, 2);
    insertIntoDoubleLinkList(p, 2, 3);
    showDoubleLinkList(p);
    deletePostDoubleLinkList(p, 2);
    showDoubleLinkList(p);
    deleteDataDoubleLinkList(p,2);
    deleteDataDoubleLinkList(p,1);
    if(isEmptyDoubleLinkList(p))
    {
        printf("isEmptyDoubleLinkList\n");
    }
    free(p->head);
    p->head = p->tail = NULL;
    free(p);
    p = NULL;
    return 0;
}
