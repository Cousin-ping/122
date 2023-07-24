#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree
{
    datatype data;
    struct tree *lchild;
    struct tree *rchild;
} bitree_node_t, *bitree_list_t;

//创建二叉树,用递归函数创建
bitree_list_t CreateBitree(int n, int i) //n:节点数，i：节点的编号
{
    bitree_list_t r = (bitree_list_t)malloc(sizeof(bitree_node_t));
    if (NULL == r)
    {
        perror("r malloc err");
        return NULL;
    }
    r->data = i;
    if (2 * i <= n) //有左孩子
    {
        r->lchild = CreateBitree(n, 2 * i);
    }
    else
    {
        r->lchild = NULL;
    }
    if (2 * i + 1 <= n) //有右孩子
    {
        r->rchild = CreateBitree(n, 2 * i + 1);
    }
    else
    {
        r->rchild = NULL;
    }
    return r;
}

//前序：
void PreOrder(bitree_list_t r)
{
    if (r == NULL)
        return;
    printf("%d ", r->data);
    PreOrder(r->lchild);
    PreOrder(r->rchild);
}

//中序：
void InOrder(bitree_list_t r)
{
    if (r == NULL)
        return;
    InOrder(r->lchild);
    printf("%d ", r->data);
    InOrder(r->rchild);
}

//后序：
void PostOrder(bitree_list_t r)
{
    if (r == NULL)
        return;
    PostOrder(r->lchild);
    PostOrder(r->rchild);
    printf("%d ", r->data);
}

//释放
void Delete(bitree_list_t r)
{
    if (r == NULL)
        return;
    Delete(r->lchild);
    Delete(r->rchild);
    free(r);
    r = NULL;
}

int main(int argc, char const *argv[])
{
    bitree_list_t r = CreateBitree(5, 1);
    printf("前序遍历：");
    PreOrder(r);
    printf("\n");
    printf("中序遍历：");
    InOrder(r);
    printf("\n");
    printf("后序遍历：");
    PostOrder(r);
    printf("\n");
    Delete(r);
    return 0;
}
