#include"Definition.h"
#include"pos_Expression.h"
#include"BracketMatching.h"

int main()
{
	char p[30];                   //�����������׺���ʽ
	DataType dat;                 //����һ������������ʽ������
	PLinkStack OPRT=Creat();      //��ʼ��һ����ջ������׺���ʽת�ɵĺ�׺���ʽ
	cout<<"[-] [+] [*] [/] [0-9] [(] [)] are available!"<<endl;   //������ʾ�����ʽ�п���������ַ�
	cout<<"Please enter an infix expression:"<<endl;              //������ʾ
	cin>>p;                          //������׺���ʽ
	cout<<endl;
	BraketMatching(p);				 //����ַ������Ƿ�����ƥ�䣬�Լ��ַ������Ƿ��в���ʶ���ַ�
	pos_Expression(OPRT,p);			 //��׺���ʽת���ɺ�׺���ʽ
	Pos_Print(OPRT);				 //�����׺���ʽ
	pos_Expression(OPRT,p);			 //��׺���ʽת���ɺ�׺���ʽ
    dat=Pos_Calculate(OPRT);		 //��׺���ʽ���㲢���ؽ��
	cout<<endl<<"The result is:		"<<dat<<endl;       //������ʽ������
	return 0;
}
