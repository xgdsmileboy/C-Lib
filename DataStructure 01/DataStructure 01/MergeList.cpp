#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int DataType;   	/* 定义元素类型为整型，也可定义为其他类型 */
struct  Node 		        /* 单链表结点结构 */
{ 
	DataType	info;
	struct Node  	*link;
};

typedef struct Node  *PNode;	 /* 结点指针类型 */

struct LinkList			         /* 单链表类型定义 */
{
	PNode  head;		         /* 指向单链表中的第一个结点 */
	int len;				     /* 冗余余的一个属性，存储单链表数据元素的个数 */
};

/* 单链表类型的指针类型 */
typedef  struct LinkList  LinkList,*PLinkList;	

void  insert_link(PLinkList pllist, DataType x, PNode p)
/* 在单链表中ｐ所指结点的后面插入元素ｘ */
{ 	
	PNode 	q;
	q =(PNode)malloc(sizeof(struct Node));
	if(q == NULL)
		printf("Out of space!!!\n");
	else {	
		q->info = x;
		q->link = p->link;
		p->link = q;
		pllist->len++;
	}
}

void  pushback_link(PLinkList pllist, DataType x)
/* 在单链表尾部插入插入元素ｘ */
{ 	
	PNode 	p, q;
	p = pllist->head;
	/* 在pllist所指的带有头结点的单链表中找最后一个结点 */
	while(p->link != pllist->head)
		p = p->link;

	q =(PNode)malloc(sizeof(struct Node));
	if(q == NULL)
		printf("Out of space!!!\n");
	else {	
		q->info = x;
		q->link = p->link;
		p->link = q;
		pllist->len++;
	}
}

void  delete_link(PLinkList pllist, DataType x)
/* 在pllist所指的带有头结点的单链表中删除元素为x的结点 */
{ 	
	PNode 	p, q;      	
	p = pllist->head;		
	/* 在pllist所指的带有头结点的单链表中找元素为x的结点的前驱结点位置 */
	while(p->link != NULL && p->link->info != x)
		p = p->link;

	if(p->link == pllist->head) 		/* 没找到元素为x的结点 */
		printf("Not exist!\n ");
	else {		
		q = p->link;	  	            /* 找到元素为x的结点 */
		p->link = q->link;  
		free(q);  
		pllist->len--;
	}
}

PNode locate_link(PLinkList pllist, DataType x)
/* 在pllist所指的带有头结点的单链表中找元素为x的结点位置 */
{ 
	PNode 	p;
	p = pllist->head->link;
	while(p != pllist->head && p->info != x)
		p = p->link;
	return p;
}

DataType  retrieve_link(PNode p)
{
	return  p->info;
}

PNode previous_link(PLinkList pllist, DataType x)
/* 在pllist所指的带有头结点的单链表中找元素为x的结点的前驱结点位置 */
{ 	
	PNode 	p;
	p = pllist->head;
	while(p->link != pllist->head && p->link->info != x)
		p = p->link;
	if(p==pllist->head || p->link==pllist->head)
		/* x是第一个结点的值或者不存在值为x的结点*/
		return NULL;
	else  	return p;
}

PLinkList createNullList_link(void)
/* 创建一个带头结点的空链表 */
{   	
	PLinkList	pllist;
	PNode 		p;
	int templen=sizeof(int *);
	pllist =(PLinkList)malloc(sizeof(struct LinkList));
	if(pllist != NULL){	
		p =(PNode)malloc(sizeof(struct Node));
		if(p!=NULL)	{   
			pllist->head=p;
			p->info = -1;
			p->link = pllist->head;
		}
		else{	
			printf("Out of space!\n");
			pllist->head = NULL;
		}
	}
	else 
		printf("Out of space!\n");
	pllist->len=0;
  return pllist;
}


int isNullLink_link(PLinkList pllist)
/* 判断pllist所指的带有头结点的单链表是否是空链表 */
{     
	return pllist->head->link == pllist->head;
}

PNode find_link(PLinkList pllist, int i)
/* 在带有头结点的单链表pllist中求第i个结点的位置 */
/* 当表中无第i个元素时，返回值为NULL */
{ 	
	PNode p;
	int j;
	if(i<1){ 
		printf("The value of i=%d is not reasonable.\n",i);
		return NULL;
	}
	p=pllist ->head;
	for(j=0; j<i; j++){ 
		p = p->link;
		if(p == pllist->head)
			return NULL;
	}
	return p;
}

void print_link(PLinkList la)
{
	PNode curNode=NULL;
	curNode=la->head->link;
	while(curNode != la->head)
	{
		printf("%d",curNode->info);
		if(curNode->link != la->head)
			printf("-->");
			curNode=curNode->link;
	}
	printf("\n");
}

void MergeList_1(PLinkList la, PLinkList lb, PLinkList lc)
/* 输入：la, lb 从小到大的单链表
   输出：lc 合并为从小到大的单链表 */
{
	/* to do by yourself */             //尾插法

	PNode pa, pb, pc;                  //设置三个指针变量分别指向链表la、lb、lc
	pa = la->head->link;               //使pa指针指向链表la
	pb = lb->head->link;               //使pb指针指向链表lb
	lc->head=pc=la->head;              //lc与la的头结点公用
	lc->len=0;
	while (pa!=la->head && pb!=lb->head)  //遍历la和lb链表直至其中之一遍历结束
	{
		if (pa->info<= pb->info)          //判断la、lb链表中较小的元素插入到lc中
		{
			pc->link = pa; 
			pc = pa; 
			pa = pa->link;
			lc->len++;
		}
		else 
		{
			pc->link = pb; 
			pc = pb; 
			pb = pb->link;
			lc->len++;
		}
	}
	if(pa != la->head)                    //将未遍历完的链表剩余元素插入lc中，并计数
	{	
		while(pa!=la->head)
		{
			pc->link = pa;   pc=pa;
			pa = pa->link;   lc->len++;
		}
	}
	else
	{
		while(pb!=lb->head)
		{
			pc->link = pb;   pc=pb;
			pb = pb->link;   lc->len++;
		}
	}
	pc->link=lc->head;                          //形成循环链表
}

void MergeList_2(PLinkList la, PLinkList lb, PLinkList lc)
///* 输入：la, lb 从大到小的单链表
//   输出：lc 合并为从大到小的单链表 */
{
//	/* to do by yourself */
//	PNode pc0, pc,curr_head;          //定义指针分别指向有序表的头结点（cuur_head）、用于在链表中循环（pc）、和记录pc的前驱(pc0)
//	MergeList_1(la, lb, lc);          //调用MergList_1函数，先使la、lb按升序合并为lc
//	pc = lc->head->link;              //pc指向合并后的链表lc的第一个数据项
//	while(pc->link!=lc->head)         //遍历lc链表找到尾结点
//	{
//		pc0=pc;
//		pc=pc->link;
//	}
//	curr_head=pc;                     //curr_head保存lc的尾结点位置
//	pc->link=pc0;                     //将尾结点的地址域指向他的前驱
//    pc = lc->head->link;            //使pc指向合并后的链表lc的第一个数据项
//    while(pc->link->link!=pc)       //判断是否已经循环到了第一个节点
//	{
//		pc = lc->head->link;
//		while(pc->link->link!=pc)      //判断该项的下一结点的地址域是否已经指向了他的前驱
//		{
//			pc0=pc;                     //用pc0记录pc的前驱
//			pc=pc->link;                //使pc的地址域指向他的前驱
//		}
//		pc->link=pc0;
//		pc = lc->head->link;            //再次从头开始循环
//	}
//	lc->head->link=curr_head;           //将原lc尾结点赋值给lc的头指针，实现了链表的全部逆置
//	pc->link=lc->head;                  //将尾指针指回头，形成循环链表

	////////////****修正程序*******头插法*****/////////////
	PNode pa,pb,pc,p,tail;          //pa指向链表la，pb指向链表lb，pc指向链表pc，p指针用于在将元素插入链表中
	int w=0;                        //时保存待插入元素的下一结点地址
	pa=la->head->link;             
	pb=lb->head->link;
	pc=la->head;
	lc->len=0;
	while(pa!=la->head && pb!=lb->head)    //循环将la和lb链表中的元素提取出来进行比较，将较小的元素插入链表lc中
	{
		if(pa->info<=pb->info)
		{
			if(w==0)
			{
				tail=pa; w=1;                //只有第一次可能被执行到，保存lc链表的尾指针
			}
			p=pa->link;   pa->link=pc; 
			pc=pa;  pa=p;  lc->len++;
		}
		else
		{
			if(w==0)
			{
				tail=pb; w=1;                //只有第一次可能被执行到，保存lc链表的尾指针
			}
			p=pb->link;   pb->link=pc; 
			pc=pb;  pb=p;  lc->len++;
		}
	}
	if(pa!=la->head)                         //将未遍历完的链表中的剩余元素按序插入到lc链表中
		while(pa!=la->head)
		{
			p=pa->link;  pa->link=pc;  pc=pa;  pa=p;  lc->len++;
		}
	else
		while(pb!=lb->head)
		{
			 p=pb->link;  pb->link=pc;  pc=pb;  pb=p;  lc->len++;
		} 
		lc->head->link=pc;              //将当前pc赋值给lc的head，作为lc中第一个元素
		tail->link=lc->head;            //使先前保存的lc链表的尾指回lc的head形成循环链表
}

void main()
{
	PLinkList la1=createNullList_link();
	PLinkList lb1=createNullList_link();
	DataType term;
	
	FILE *fp;
	fp=fopen("la.txt", "rt");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		pushback_link(la1, term);	
	}
	fclose(fp);
	printf("The length of the list is %d\n",la1->len);
	print_link(la1);
	printf("\n");
	
	fp=fopen("lb.txt", "rt");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		pushback_link(lb1, term);	
	}	
	fclose(fp);
	printf("The length of the list is %d\n",lb1->len);
	print_link(lb1);
	printf("\n");

/* 写好MergeList_1函数后调用下面的3行语句验证 */

	PLinkList lc1=createNullList_link();
	MergeList_1(la1, lb1, lc1);	
	printf("The length of the list is %d\n",lc1->len);        //输出合并后的链表长度
	print_link(lc1);                                          //输出合并后链表
	printf("\n");                                             //控制换行

	
	PLinkList la2=createNullList_link();
	PLinkList lb2=createNullList_link();
	
	fp=fopen("la.txt", "rt");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		pushback_link(la2, term);	
	}
	fclose(fp);
	printf("The length of the list is %d\n",la2->len);
	print_link(la2);
	printf("\n");
	
	fp=fopen("lb.txt", "rt");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		pushback_link(lb2, term);	
	}	
	fclose(fp);
	printf("The length of the list is %d\n",lb2->len);
	print_link(lb2);
	printf("\n");
	
/* 写好MergeList_2函数后调用下面的3行语句验证 */

	PLinkList lc2=createNullList_link();	
	MergeList_2(la2, lb2, lc2);	
	printf("The length of the list is %d\n",lc2->len);      //输出合并后的链表长度
	print_link(lc2);                                        //输出合并后的新链表
	printf("\n");                                           //控制换行

	printf("Please enter a random letter quit!\n");         //输入提示

	getchar();      //输入断点，使得DataStructure 01.exe运行后有时间停留不会立即退出，以便观察结果
	
	return;
}
