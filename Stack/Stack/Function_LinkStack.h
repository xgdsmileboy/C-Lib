#ifndef FUNCTION_H
#define FUNCTION_H

#include "LinkStruct_Define.h"
#include <malloc.h>
#include <iostream>
using namespace std;

///////=========================================================================////////////
PLinkStack Creat()                //初始化一个链表空栈
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
DataType isEmpty(PLinkStack ls)
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
////////=====================================================================/////////////
DataType GetTop(PLinkStack ls)
{
	return (ls->top->data);
}
///////======================================================================////////////
DataType Oprate(DataType a,char theta,DataType b)
{
	DataType dat;
	switch(theta)
	{
	case '+':
		dat=a+b;
		return dat;
	case '-':dat=a-b;return dat;
	case '*':dat=a*b;return dat;
	case '/':dat=a/b;return dat;
	}
}

#endif