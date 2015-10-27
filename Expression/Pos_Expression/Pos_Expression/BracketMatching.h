#ifndef BRACKETMATCHING_H
#define BRACKETMATCHING_H

#include"Definition.h"

void BraketMatching(char *braket)          //�����ʽ�����Ƿ�ƥ��ĺ���
{
	PLinkStack openings=Creat();           //��ʼ��һ���յĴ洢������ջ
	cout<<"Examine the brackets matching..."<<endl;         //��ʾ
	for(bool is_matched=true;is_matched && *braket!='\0';)  //ѭ���������ƥ��
	{
		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
		{                                                       //����Ƿ��в���ʶ���ַ�
			if(*braket=='(')
				{Push(openings,*braket);braket++;continue;}     //������ֱ�ӽ�ջ
			if(*braket==')')                              
				if(isEmpty(openings))                           //����������������֮��Ӧ�������
				{
					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
						<<"detected."<<endl;
					exit(0);
				}//if
				else
				{
					char match;
					match=Pop(openings);                      //�Ӳ�����ջȡ��һ��Ԫ��
					is_matched=(*braket==')'&&match=='(');    //��������Ƿ�ƥ��
					if(!is_matched)                           //��ƥ�䣬��ʾ����
					{
						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
						exit(0);
					}//if
					braket++;
					continue;
				}//else
				braket++;
		}//if
		else
		{
			cout<<"The character ["<<*braket<<"] is not avialable"<<endl;   //�в������ַ��������ʾ
			exit(0);
		}
	}//for
	if(!isEmpty(openings))    //�ж��������Ƿ����
		cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl;
	else
		cout<<"Well matched!"<<endl<<endl;
}
#endif