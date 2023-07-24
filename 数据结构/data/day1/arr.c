#include <stdio.h>
//插入数据
void insertIntoA(int *p, int n, int post, int data)
{
    //1.从n-1~post整体向后移动一个位置
    int i;
    for (i = n - 1; i >= post; i--)
    {
        p[i + 1] = p[i];
    }
    //2.放数据
    p[post] = data;
}
//查看数据
void showA(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", p[i]);
    }
    printf("\n");
}
//删除数组指定位置的数据
void deleteFromA(int *p, int n, int post)
{
    int i;
    //将post+1位置~n-1位置所有数据向前移动一格位置，覆盖删除
    for (i = post + 1; i <= n - 1; i++)
    {
        p[i - 1] = p[i];
    }
}
int main(int argc, char const *argv[])
{
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    showA(a, 8);
    insertIntoA(a, 8, 2, 100);
    showA(a, 9);
    deleteFromA(a,9,2);
    showA(a,8);
    return 0;
}
