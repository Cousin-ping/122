#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
	int data;
	struct node_t *next;
}link_node_t,*link_list_t;

int main(int argc, const char *argv[])
{
	int i;
	link_list_t pdel = NULL;//用于指向被删除节点
	link_list_t ptail = NULL;//永远指向当前链表的尾 
	link_list_t pnew = NULL;//永远指向新创建的节点
	link_list_t h = NULL;
	int all_num = 7;//猴子总数 
	int start_num = 2; //从几号猴子开始数
	int kill_num = 3;//数到几杀死猴
	//printf("请您入猴子总数 起始号码 数到几杀死:\n");
	//scanf("%d%d%d",&all_num,&start_num,&kill_num);
	//1.创建出一个单向循环链表
	//(1)创建有all_num个节点的单向链表
	h = (link_list_t)malloc(sizeof(link_node_t));
	if(NULL == h)
	{
		perror("malloc failed");
		return -1;
	}
	h->data = 1;
	h->next = NULL;
	ptail = h;//尾指针指向当前的第一个节点
	for(i = 2; i <= all_num; i++)
	{
		//创建新的节点
		pnew = (link_list_t)malloc(sizeof(link_node_t));
		if(NULL == pnew)
		{
			perror("malloc failed");
			return -1;
		}
		//将新节点装上数据
		pnew->data = i;
		pnew->next = NULL;
		//将新节点链接到链表尾 
		ptail->next = pnew;//链接到链表的尾
		ptail = pnew;//尾指针继续指向当前链表的尾 
	}
	//(2)将头指针保存到链表的尾形成单向循环链表
	ptail->next = h;//形成单向循环链表 
#if 0 //用于调试程序
	while(1)
	{
		printf("%d\n",h->data);
		h = h->next;
		sleep(1);
	}
#endif
	//2.开始杀猴子 
	//(1)将头指针移动到开始猴子的号码处 
	for(i = 0; i < start_num-1; i++)
		h = h->next;
	//(2)循环进行杀猴子
	while(h != h->next)//条件不成的时候，就剩一个猴子,只有一个节点
	{
		//将头指针移动到即将删除节点的前一个节点
		for(i = 0; i < kill_num-2; i++)
			h = h->next;

		pdel = h->next;
		//跨过删除节点
		h->next = pdel->next;
		printf("kill is -------------%d\n",pdel->data);
		free(pdel);
		pdel = NULL;
		//杀死猴子猴，从下一个节点开始继续开始数,将头指针移动到开始数的地方
		h = h->next;
	}
	printf("king is=================== %d\n",h->data);
	return 0;
}	