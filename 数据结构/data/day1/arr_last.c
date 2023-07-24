#include <stdio.h>
int last=7;//代表数组中最后一个有效元素的下标//last  + 1 == n
//插入数据
void insertIntoA(int *p, int post, int data)
{
    //1.从last~post整体向后移动一个位置
    int i;
    for (i = last; i >= post; i--)
    {
        p[i + 1] = p[i];
    }
    //2.放数据
    p[post] = data;
    //3.last++
    last++;
}
//查看数据
void showA(int *p)
{
    int i;
    for (i = 0; i <= last; i++)
    {
        printf("%d  ", p[i]);
    }
    printf("\n");
}
//删除数组指定位置的数据
void deleteFromA(int *p, int post)
{
    int i;
    //1.将post+1位置~last位置所有数据向前移动一格位置，覆盖删除
    for (i = post + 1; i <= last; i++)
    {
        p[i - 1] = p[i];
    }
    //2.last--,有效数据减少1
    last--;
}
int main(int argc, char const *argv[])
{
    int a[100] = {1, 2, 3, 4, 5, 6, 7, 8};
    showA(a);
    insertIntoA(a, 2, 100);
    showA(a);
    deleteFromA(a,2);
    showA(a);
    return 0;
}
