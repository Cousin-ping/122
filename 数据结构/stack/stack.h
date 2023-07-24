#ifndef _STACK_H_
#define _STACK_H_

typedef int data_type;
typedef struct seqstack
{
	data_type* data;//指向栈的存储位置
	int maxlen;//保存栈的最大长度
	int top;//称为栈针，用的时候，心里面可以将按照顺序表里的last来使用
			//top 始终代表当前栈内最后一个有效元素的下标
}seqstack_t;
//1.创建一个空的栈
seqstack_t *CreateEpSeqStack(int len);//len代表的是创建栈的时候的最大长度
//2.判断是否为满,满返回1 未满返回0
int	 IsFullSeqStack(seqstack_t *p);
//3.入栈 
int  PushStack(seqstack_t *p, int data);//data代表入栈的数据
//4.判断栈是否为空
int IsEpSeqStack(seqstack_t *p);
//5.出栈 
int PopSeqStack(seqstack_t *p);
//6. 清空栈 
void ClearSeqStack(seqstack_t *p);
//7. 获取栈顶数据(注意不是出栈操作，如果出栈，相当于删除了栈顶数据，只是将栈顶的数据获取到，不需要移动栈针)
int GetTopSeqStack(seqstack_t *p);
//8. 求栈的长度
int LengthSeqStack(seqstack_t *p);






#endif