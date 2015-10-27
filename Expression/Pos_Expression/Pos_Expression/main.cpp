#include"Definition.h"
#include"pos_Expression.h"
#include"BracketMatching.h"

int main()
{
	char p[30];                   //保存输入的中缀表达式
	DataType dat;                 //定义一个变量保存表达式计算结果
	PLinkStack OPRT=Creat();      //初始化一个空栈保存中缀表达式转成的后缀表达式
	cout<<"[-] [+] [*] [/] [0-9] [(] [)] are available!"<<endl;   //输入提示，表达式中可以输入的字符
	cout<<"Please enter an infix expression:"<<endl;              //输入提示
	cin>>p;                          //输入中缀表达式
	cout<<endl;
	BraketMatching(p);				 //检查字符串中是否括号匹配，以及字符串中是否有不可识别字符
	pos_Expression(OPRT,p);			 //中缀表达式转换成后缀表达式
	Pos_Print(OPRT);				 //输出后缀表达式
	pos_Expression(OPRT,p);			 //中缀表达式转换成后缀表达式
    dat=Pos_Calculate(OPRT);		 //后缀表达式计算并返回结果
	cout<<endl<<"The result is:		"<<dat<<endl;       //输出表达式计算结果
	return 0;
}
