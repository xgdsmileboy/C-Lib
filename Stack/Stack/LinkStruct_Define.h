#ifndef LINKSTRUCT_H
#define LINKSTRUCT_H

typedef  float  DataType;
//typedef  char  DataType;
typedef struct Node          //����������
{
	DataType      data;
	struct Node * next;
}Node,*PNode;                //NodeΪ������ͣ�PNodeΪ�����ָ��      

typedef struct LinkStack     //����ջ
{
	PNode top;
}LinkStack,*PLinkStack;      //LinkStackΪջ���ͣ�PLinkStackΪջ����ָ��

#endif