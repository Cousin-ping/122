#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define N 5
typedef struct 
{
	int data[N];
	int last;//last代表的是数组中最后一个有效元素的下标
}seqlist_t;
//1.创建一个空的顺序表
seqlist_t *CreateEpSeqlist();//返回的是申请空间的首地址
//2.向顺序表的指定位置插入数据
int InsertIntoSeqlist(seqlist_t *p, int post,int data);//post第几个位置，data插入的数据
//3.遍历顺序表sequence 顺序　list 表
void ShowSeqlist(seqlist_t *p);
//4.判断顺序表是否为满,满返回１　未满返回０
int IsFullSeqlist(seqlist_t *p);
//5.判断顺序表是否为空
int IsEpSeqlist(seqlist_t *p);
//6.删除顺序表中指定位置的数据post删除位置
int DeletePostSeqlist(seqlist_t *p, int post);
//7.清空顺序表
void ClearSeqList(seqlist_t *p);
//8.修改指定位置的数据
int ChangePostSeqList(seqlist_t *p,int post,int data);//post被修改的位置，data修改成的数据
//9.查找指定数据出现的位置
int SearchDataSeqList(seqlist_t *p,int data);//data代表被查找的数据
#endif