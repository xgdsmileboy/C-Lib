#ifndef EVALUATE_EXPRESSION_H
#define EVALUATE_EXPRESSION_H

#include <malloc.h>
#include <iostream>
using namespace std;

typedef  float  DataType;
typedef  char  OpraterType;
//typedef  int  DataType;
//typedef  int  OpraterType;
///////////=============������ջ================////////////////////////
typedef struct Node          //����������
{
	DataType      data;
	struct Node * next;
}Node,*PNode;                //NodeΪ������ͣ�PNodeΪ�����ָ��      

typedef struct LinkStack     //����ջ
{
	PNode top;
}LinkStack,*PLinkStack;      //LinkStackΪջ���ͣ�PLinkStackΪջ����ָ��


///////////////////////////////========ջ�Ļ�������=========//////////////////////////////////
///////=========================================================================////////////
PLinkStack Creat()                //��ʼ��һ�����Ϳ�ջ
{
	PLinkStack ls;
	PNode p;
	ls=(PLinkStack)malloc(sizeof(struct LinkStack));
	if(ls)
		ls->top=NULL;
	else
			cout<<"Init_LinkStack Failed!"<<endl;
	return ls;
}
////////=======================================================================/////////////
DataType isEmpty(PLinkStack ls)            //�ж��Ƿ�Ϊ��ջ
{
	return(ls->top==NULL);
}
////////======================================================================/////////////
void Push(PLinkStack ls,DataType dat)       //Ԫ��dat��ջ
{
	PNode curr_top;
	curr_top=(PNode)malloc(sizeof(struct Node));
	if(!curr_top)
		cout<<"Insert Error!"<<endl;
	else
	{
		curr_top->data=dat;
		curr_top->next=ls->top;
		ls->top=curr_top;
	}
}
////////======================================================================/////////////
DataType Pop(PLinkStack ls)    //��ջ��ɾ��һ��Ԫ�أ�������ɾ��Ԫ��ֵ
{
	PNode p;
	DataType dat;
	if(isEmpty(ls))
		cout<<"Stack is Empty!"<<endl;
	else
	{
		p=ls->top;
		dat=p->data;
		ls->top=ls->top->next;
		free(p);
	}	
	return dat;
}
////////=====================================================================////////////
DataType GetTop(PLinkStack ls)   //����ջ��Ԫ��
{
	return (ls->top->data);
}
///////======================================================================////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////=========ʵ����������=========/////////////////////////////////
DataType Oprate(DataType a,char theta,DataType b)    //����Ϊ Datatype char Datatype
{
	static int i=1;
	DataType dat;
	if(theta=='/'&&b==0)
	{  cout<<"Denominator can not be 0!"<<endl;      //�жϳ�������ʱ��ĸ�Ƿ�Ϊ0
		 exit(0);
	}
	if(i==1)
		cout<<"The computational processes are:"<<endl;  //���������ʾ
	cout<<"The "<<i<<" step is:		";
	i++;
	switch(theta)
	{
	case '+':dat=a+b; cout<<a;
				  if(b<0)
				  { cout<<"+("<<b<<")="<<dat<<endl; return dat;}   //��ʽ�����
				  else
				  { cout<<"+"<<b<<"="<<dat<<endl; return dat;}
	case '-':dat=a-b; cout<<a;
		          if(b<0)
				  { cout<<"-("<<b<<")="<<dat<<endl; return dat;}
				  else
				  { cout<<"-"<<b<<"="<<dat<<endl; return dat;}
	case '*':dat=a*b; cout<<a;
		          if(b<0)
				  {cout<<"*("<<b<<")="<<dat<<endl; return dat;}
				  else
				  { cout<<"*"<<b<<"="<<dat<<endl; return dat;}
	case '/':dat=a/b;cout<<a;
		          if(b<0)
				  { cout <<"/("<<b<<")="<<dat<<endl; return dat;}
				  else
	              {cout <<"/"<<b<<"="<<dat<<endl; return dat;}
	}
}

#endif

