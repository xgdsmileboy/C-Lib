#ifndef EVALUATE_EXPRESSION_H
#define EVALUATE_EXPRESSION_H

#include <malloc.h>
#include <iostream>
using namespace std;

typedef  float  DataType;
typedef  char  OpraterType;
//typedef  int  DataType;
//typedef  int  OpraterType;
///////////=============操作数栈================////////////////////////
typedef struct Node          //定义结点类型
{
	DataType      data;
	struct Node * next;
}Node,*PNode;                //Node为结点类型，PNode为结点型指针      

typedef struct LinkStack     //定义栈
{
	PNode top;
}LinkStack,*PLinkStack;      //LinkStack为栈类型，PLinkStack为栈类型指针


///////////////////////////////========栈的基础功能=========//////////////////////////////////
///////=========================================================================////////////
PLinkStack Creat()                //初始化一个链型空栈
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
DataType isEmpty(PLinkStack ls)            //判断是否为空栈
{
	return(ls->top==NULL);
}
////////======================================================================/////////////
void Push(PLinkStack ls,DataType dat)       //元素dat进栈
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
DataType Pop(PLinkStack ls)    //从栈中删除一个元素，并返回删除元素值
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
DataType GetTop(PLinkStack ls)   //返回栈顶元素
{
	return (ls->top->data);
}
///////======================================================================////////////
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////=========实现两数计算=========/////////////////////////////////
DataType Oprate(DataType a,char theta,DataType b)    //参数为 Datatype char Datatype
{
	static int i=1;
	DataType dat;
	if(theta=='/'&&b==0)
	{  cout<<"Denominator can not be 0!"<<endl;      //判断除法运算时分母是否为0
		 exit(0);
	}
	if(i==1)
		cout<<"The computational processes are:"<<endl;  //过程输出提示
	cout<<"The "<<i<<" step is:		";
	i++;
	switch(theta)
	{
	case '+':dat=a+b; cout<<a;
				  if(b<0)
				  { cout<<"+("<<b<<")="<<dat<<endl; return dat;}   //格式化输出
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

