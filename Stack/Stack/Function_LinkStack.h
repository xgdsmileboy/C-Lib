#ifndef FUNCTION_H
#define FUNCTION_H

#include "LinkStruct_Define.h"
#include <malloc.h>
#include <iostream>
using namespace std;

///////=========================================================================////////////
PLinkStack Creat()                //��ʼ��һ�������ջ
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