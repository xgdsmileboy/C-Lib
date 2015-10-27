#include"Definition.h"

//DataType Evaluate_Expression(char *Exp)   ///��׺�����ʽ��ֵ������Ϊ�ַ�����
//{
//	DataType a,b;                    //a,b���ڴӲ�����ջ�ж�ȡ��������
//	char theta;                      //���ڴӲ�����ջ�ж�ȡ���������
//	OPLinkStack OPRT=OCreat();       //��ʼ��һ���յĲ�����ջ
//	PLinkStack OPND=Creat();         //��ʼ��һ���յĲ�����ջ
//	while(*Exp!='\0')                //��һ��ȡ�����е�Ԫ��
//	{
//		if(*Exp>='0' && *Exp<='9')   //��������ַ�������
//		{
//			float d=0;
//			while(*Exp>='0' && *Exp<='9')  //ѭ����ȡ���ݣ����ڶ������10����
//			{
//				d=d*10+*Exp-'0';
//				Exp++;
//			}
//			Push(OPND,d);                 //ʹ��������ջ
//			continue;
//		}
//		else
//		{
//			if(OisEmpty(OPRT))            //���������ջ�գ�ֱ�ӽ��������ջ
//			{
//					OPush(OPRT,*Exp);
//					Exp++;
//			}
//			else
//				switch(*Exp)      
//				{
//					case '(': OPush(OPRT,*Exp);Exp++;break;   //���������ţ�ֱ�ӽ�ջ
//					case ')': while(OGetTop(OPRT)!='(')       //������������ѭ����������ջ��������֮ǰ��������������
//							  {
//								  theta=OPop(OPRT);
//								  b=Pop(OPND); 
//								  a=Pop(OPND);
//								  Push(OPND,Oprate(a,theta,b));   //������Ľ�����浽������ջ��
//								  theta=OGetTop(OPRT);
//							  }
//							  theta=OPop(OPRT);                   //��������ɾ��
//							  Exp++; break;
//					case '+':
//					case '-':theta=OGetTop(OPRT);
//						while(theta!='(' && !OisEmpty(OPRT))      //������+����-������ǰ�ߵ������ȫ������ֱ�����������Ż���ջ��
//							 {
//								 theta=OPop(OPRT);
//								 b=Pop(OPND); 
//								 a=Pop(OPND);
//								 Push(OPND,Oprate (a,theta,b));
//								 if(!OisEmpty(OPRT))         //��������ջ���գ���ȡջ��Ԫ�������´�ѭ���ж�
//									 theta=OGetTop(OPRT);
//							 }//while
//							 OPush(OPRT,*Exp);               //����ǰ��ȡ���������ջ
//							 Exp++;
//							 break;
//					case '*':
//					case '/':theta=OGetTop(OPRT);            //�������*����/������ǰ�ߵ�*����/�������
//							while((theta=='*' || theta=='/') && !OisEmpty(OPRT))
//							{
//									theta=OPop(OPRT);
//									b=Pop(OPND); 
//									a=Pop(OPND);
//								    Push(OPND,Oprate (a,theta,b)); 
//									if(!OisEmpty(OPRT))
//										theta=OGetTop(OPRT);
//							}//while
//							OPush(OPRT,*Exp);
//							Exp++;
//				}//switch
//			}//else
//	}//while
//	while(!OisEmpty(OPRT))    //��ʣ��δ�����Ԥ���������
//	{
//		theta=OPop(OPRT);
//		b=Pop(OPND); 
//		a=Pop(OPND);
//		Push(OPND,Oprate (a,theta,b));
//	}
//	return (Pop(OPND));     //���ؼ�����
//}

DataType Evaluate_Expression(char *Exp)   //��׺�����ʽ��ֵ������Ϊ�ַ�����
{
	DataType a,b;                         //a,b���ڴӲ�����ջ�ж�ȡ��������
	char theta;                           //���ڴӲ�����ջ�ж�ȡ���������
	PLinkStack OPRT=Creat();              //��ʼ��һ���յĲ�����ջ
	PLinkStack OPND=Creat();              //��ʼ��һ���յĲ�����ջ
	while(*Exp!='\0')                     //��һ��ȡ�����е�Ԫ��
	{
		if(*Exp>='0' && *Exp<='9')        //��������ַ�������
		{
			float d=0;
			while(*Exp>='0' && *Exp<='9') //ѭ����ȡ���ݣ����ڶ������10����
			{
				d=d*10+*Exp-'0';
				Exp++;
			}
			Push(OPND,d);                 //ʹ��������ջ
			continue;
		}
		else
		{
			if(isEmpty(OPRT))             //���������ջ�գ�ֱ�ӽ��������ջ
			{
					Push(OPRT,*Exp);
					Exp++;
			}
			else
				switch(*Exp)      
				{
					case '(': Push(OPRT,*Exp);Exp++;break;   //���������ţ�ֱ�ӽ�ջ
					case ')': while(GetTop(OPRT)!='(')       //������������ѭ����������ջ��������֮ǰ��������������
							  {
								  theta=Pop(OPRT);
								  b=Pop(OPND); 
								  a=Pop(OPND);
								  Push(OPND,Oprate(a,theta,b));   //������Ľ�����浽������ջ��
								  theta=GetTop(OPRT);
							  }
							  theta=Pop(OPRT);                    //��������ɾ��
							  Exp++; break;
					case '+':
					case '-':theta=GetTop(OPRT);
						while(theta!='(' && !isEmpty(OPRT))       //������+����-������ǰ�ߵ������ȫ������ֱ�����������Ż���ջ��
							 {
								 theta=Pop(OPRT);
								 b=Pop(OPND); 
								 a=Pop(OPND);
								 Push(OPND,Oprate (a,theta,b));
								 if(!isEmpty(OPRT))         //��������ջ���գ���ȡջ��Ԫ�������´�ѭ���ж�
									 theta=GetTop(OPRT);
							 }//while
							 Push(OPRT,*Exp);               //����ǰ��ȡ���������ջ
							 Exp++;
							 break;
					case '*':
					case '/':theta=GetTop(OPRT);            //�������*����/������ǰ�ߵ�*����/�������
							while((theta=='*' || theta=='/') && !isEmpty(OPRT))
							{
									theta=Pop(OPRT);
									b=Pop(OPND); 
									a=Pop(OPND);
								    Push(OPND,Oprate (a,theta,b)); 
									if(!isEmpty(OPRT))
										theta=GetTop(OPRT);
							}//while
							Push(OPRT,*Exp);
							Exp++;
				}//switch
			}//else
	}//while
	while(!isEmpty(OPRT))    //��ʣ��δ�����Ԥ���������
	{
		theta=Pop(OPRT);
		b=Pop(OPND); 
		a=Pop(OPND);
		Push(OPND,Oprate (a,theta,b));
	}
	return (Pop(OPND));    //���ؼ�����
}
