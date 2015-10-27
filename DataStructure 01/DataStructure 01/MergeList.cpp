#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int DataType;   	/* ����Ԫ������Ϊ���ͣ�Ҳ�ɶ���Ϊ�������� */
struct  Node 		        /* ��������ṹ */
{ 
	DataType	info;
	struct Node  	*link;
};

typedef struct Node  *PNode;	 /* ���ָ������ */

struct LinkList			         /* ���������Ͷ��� */
{
	PNode  head;		         /* ָ�������еĵ�һ����� */
	int len;				     /* �������һ�����ԣ��洢����������Ԫ�صĸ��� */
};

/* ���������͵�ָ������ */
typedef  struct LinkList  LinkList,*PLinkList;	

void  insert_link(PLinkList pllist, DataType x, PNode p)
/* �ڵ������У���ָ���ĺ������Ԫ�أ� */
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
/* �ڵ�����β���������Ԫ�أ� */
{ 	
	PNode 	p, q;
	p = pllist->head;
	/* ��pllist��ָ�Ĵ���ͷ���ĵ������������һ����� */
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
/* ��pllist��ָ�Ĵ���ͷ���ĵ�������ɾ��Ԫ��Ϊx�Ľ�� */
{ 	
	PNode 	p, q;      	
	p = pllist->head;		
	/* ��pllist��ָ�Ĵ���ͷ���ĵ���������Ԫ��Ϊx�Ľ���ǰ�����λ�� */
	while(p->link != NULL && p->link->info != x)
		p = p->link;

	if(p->link == pllist->head) 		/* û�ҵ�Ԫ��Ϊx�Ľ�� */
		printf("Not exist!\n ");
	else {		
		q = p->link;	  	            /* �ҵ�Ԫ��Ϊx�Ľ�� */
		p->link = q->link;  
		free(q);  
		pllist->len--;
	}
}

PNode locate_link(PLinkList pllist, DataType x)
/* ��pllist��ָ�Ĵ���ͷ���ĵ���������Ԫ��Ϊx�Ľ��λ�� */
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
/* ��pllist��ָ�Ĵ���ͷ���ĵ���������Ԫ��Ϊx�Ľ���ǰ�����λ�� */
{ 	
	PNode 	p;
	p = pllist->head;
	while(p->link != pllist->head && p->link->info != x)
		p = p->link;
	if(p==pllist->head || p->link==pllist->head)
		/* x�ǵ�һ������ֵ���߲�����ֵΪx�Ľ��*/
		return NULL;
	else  	return p;
}

PLinkList createNullList_link(void)
/* ����һ����ͷ���Ŀ����� */
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
/* �ж�pllist��ָ�Ĵ���ͷ���ĵ������Ƿ��ǿ����� */
{     
	return pllist->head->link == pllist->head;
}

PNode find_link(PLinkList pllist, int i)
/* �ڴ���ͷ���ĵ�����pllist�����i������λ�� */
/* �������޵�i��Ԫ��ʱ������ֵΪNULL */
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
/* ���룺la, lb ��С����ĵ�����
   �����lc �ϲ�Ϊ��С����ĵ����� */
{
	/* to do by yourself */             //β�巨

	PNode pa, pb, pc;                  //��������ָ������ֱ�ָ������la��lb��lc
	pa = la->head->link;               //ʹpaָ��ָ������la
	pb = lb->head->link;               //ʹpbָ��ָ������lb
	lc->head=pc=la->head;              //lc��la��ͷ��㹫��
	lc->len=0;
	while (pa!=la->head && pb!=lb->head)  //����la��lb����ֱ������֮һ��������
	{
		if (pa->info<= pb->info)          //�ж�la��lb�����н�С��Ԫ�ز��뵽lc��
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
	if(pa != la->head)                    //��δ�����������ʣ��Ԫ�ز���lc�У�������
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
	pc->link=lc->head;                          //�γ�ѭ������
}

void MergeList_2(PLinkList la, PLinkList lb, PLinkList lc)
///* ���룺la, lb �Ӵ�С�ĵ�����
//   �����lc �ϲ�Ϊ�Ӵ�С�ĵ����� */
{
//	/* to do by yourself */
//	PNode pc0, pc,curr_head;          //����ָ��ֱ�ָ��������ͷ��㣨cuur_head����������������ѭ����pc�����ͼ�¼pc��ǰ��(pc0)
//	MergeList_1(la, lb, lc);          //����MergList_1��������ʹla��lb������ϲ�Ϊlc
//	pc = lc->head->link;              //pcָ��ϲ��������lc�ĵ�һ��������
//	while(pc->link!=lc->head)         //����lc�����ҵ�β���
//	{
//		pc0=pc;
//		pc=pc->link;
//	}
//	curr_head=pc;                     //curr_head����lc��β���λ��
//	pc->link=pc0;                     //��β���ĵ�ַ��ָ������ǰ��
//    pc = lc->head->link;            //ʹpcָ��ϲ��������lc�ĵ�һ��������
//    while(pc->link->link!=pc)       //�ж��Ƿ��Ѿ�ѭ�����˵�һ���ڵ�
//	{
//		pc = lc->head->link;
//		while(pc->link->link!=pc)      //�жϸ������һ���ĵ�ַ���Ƿ��Ѿ�ָ��������ǰ��
//		{
//			pc0=pc;                     //��pc0��¼pc��ǰ��
//			pc=pc->link;                //ʹpc�ĵ�ַ��ָ������ǰ��
//		}
//		pc->link=pc0;
//		pc = lc->head->link;            //�ٴδ�ͷ��ʼѭ��
//	}
//	lc->head->link=curr_head;           //��ԭlcβ��㸳ֵ��lc��ͷָ�룬ʵ���������ȫ������
//	pc->link=lc->head;                  //��βָ��ָ��ͷ���γ�ѭ������

	////////////****��������*******ͷ�巨*****/////////////
	PNode pa,pb,pc,p,tail;          //paָ������la��pbָ������lb��pcָ������pc��pָ�������ڽ�Ԫ�ز���������
	int w=0;                        //ʱ���������Ԫ�ص���һ����ַ
	pa=la->head->link;             
	pb=lb->head->link;
	pc=la->head;
	lc->len=0;
	while(pa!=la->head && pb!=lb->head)    //ѭ����la��lb�����е�Ԫ����ȡ�������бȽϣ�����С��Ԫ�ز�������lc��
	{
		if(pa->info<=pb->info)
		{
			if(w==0)
			{
				tail=pa; w=1;                //ֻ�е�һ�ο��ܱ�ִ�е�������lc�����βָ��
			}
			p=pa->link;   pa->link=pc; 
			pc=pa;  pa=p;  lc->len++;
		}
		else
		{
			if(w==0)
			{
				tail=pb; w=1;                //ֻ�е�һ�ο��ܱ�ִ�е�������lc�����βָ��
			}
			p=pb->link;   pb->link=pc; 
			pc=pb;  pb=p;  lc->len++;
		}
	}
	if(pa!=la->head)                         //��δ������������е�ʣ��Ԫ�ذ�����뵽lc������
		while(pa!=la->head)
		{
			p=pa->link;  pa->link=pc;  pc=pa;  pa=p;  lc->len++;
		}
	else
		while(pb!=lb->head)
		{
			 p=pb->link;  pb->link=pc;  pc=pb;  pb=p;  lc->len++;
		} 
		lc->head->link=pc;              //����ǰpc��ֵ��lc��head����Ϊlc�е�һ��Ԫ��
		tail->link=lc->head;            //ʹ��ǰ�����lc�����βָ��lc��head�γ�ѭ������
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

/* д��MergeList_1��������������3�������֤ */

	PLinkList lc1=createNullList_link();
	MergeList_1(la1, lb1, lc1);	
	printf("The length of the list is %d\n",lc1->len);        //����ϲ����������
	print_link(lc1);                                          //����ϲ�������
	printf("\n");                                             //���ƻ���

	
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
	
/* д��MergeList_2��������������3�������֤ */

	PLinkList lc2=createNullList_link();	
	MergeList_2(la2, lb2, lc2);	
	printf("The length of the list is %d\n",lc2->len);      //����ϲ����������
	print_link(lc2);                                        //����ϲ����������
	printf("\n");                                           //���ƻ���

	printf("Please enter a random letter quit!\n");         //������ʾ

	getchar();      //����ϵ㣬ʹ��DataStructure 01.exe���к���ʱ��ͣ�����������˳����Ա�۲���
	
	return;
}
