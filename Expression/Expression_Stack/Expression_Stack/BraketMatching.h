#ifndef BRACKETMATCHING_H
#define BRACKETMATCHING_H

#include"Definition.h"

//void BraketMatching(char *braket)          //�����ʽ�����Ƿ�ƥ��ĺ���
//{
//	OPLinkStack openings=OCreat();           //��ʼ��һ�����������ŵĿ�ջ
//	cout<<"Examine bracket matching..."<<endl;
//	for(bool is_matched=true;is_matched && *braket!='\0';)
//	{
//		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
//		{
//			if(*braket=='(')                 //�����������ֱ�ӽ�ջ
//			{OPush(openings,*braket);braket++;continue;}
//			if(*braket==')')
//   
//				if(OisEmpty(openings))      //�������һ��������ȴû�����������������
//				{
//					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
//						<<"detected."<<endl;
//					exit(0);
//				}
//				else
//				{
//					char match;
//					match=OPop(openings);
//					is_matched=(*braket==')'&&match=='(');  //��������Ƿ�ƥ��
//					if(!is_matched)        //����������Ų�ƥ�䣬���������Ϣ
//					{
//						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
//						exit(0);
//					}
//					braket++;
//					continue;
//				}
//				braket++;
//		}
//		else
//		{ cout<<"The character ["<<*braket<<"] is not avialable"<<endl;
//			exit(0);
//		}
//	}
//	if(!OisEmpty(openings))  //�ж��������Ƿ����
//	{cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl; exit(0);}
//	else
//		cout<<"Well matched!"<<endl<<endl;
//}
void BraketMatching(char *braket)          //�����ʽ�����Ƿ�ƥ��ĺ���
{
	PLinkStack openings=Creat();           //��ʼ��һ�����������ŵĿ�ջ
	cout<<"Examine bracket matching..."<<endl;
	for(bool is_matched=true;is_matched && *braket!='\0';)
	{
		if(*braket==')'||*braket=='('||(*braket<='9'&&*braket>='0')||*braket=='+'||*braket=='-'||*braket=='*'||*braket=='/')
		{
			if(*braket=='(')              //�����������ֱ�ӽ�ջ
			{Push(openings,*braket);braket++;continue;}
			if(*braket==')')
   
				if(isEmpty(openings))     //�������һ��������ȴû�����������������
				{
					cout<<"Unmatched closing bracket!"<<"	["<<*braket<<"]		"
						<<"detected."<<endl;
					exit(0);
				}
				else
				{
					char match;
					match=Pop(openings);
					is_matched=(*braket==')'&&match=='(');  //��������Ƿ�ƥ��
					if(!is_matched)                         //����������Ų�ƥ�䣬���������Ϣ
					{
						cout<<"Bad matched  "<<match<<"  "<<*braket<<endl;
						exit(0);
					}
					braket++;
					continue;
				}
				braket++;
		}
		else
		{ cout<<"The character ["<<*braket<<"] is not avialable"<<endl;
			exit(0);
		}
	}
	if(!isEmpty(openings))  //�ж��������Ƿ����
	{cout<<"Unmatched openings bracket(s) detected!"<<endl<<endl; exit(0);}
	else
		cout<<"Well matched!"<<endl<<endl;
}
#endif
