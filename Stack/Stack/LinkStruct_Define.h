#ifndef LINKSTRUCT_H
#define LINKSTRUCT_H

typedef  float  DataType;
//typedef  char  DataType;
typedef struct Node          //定义结点类型
{
	DataType      data;
	struct Node * next;
}Node,*PNode;                //Node为结点类型，PNode为结点型指针      

typedef struct LinkStack     //定义栈
{
	PNode top;
}LinkStack,*PLinkStack;      //LinkStack为栈类型，PLinkStack为栈类型指针

#endif