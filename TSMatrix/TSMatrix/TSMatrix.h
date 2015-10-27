#ifndef TSMATRIX_H
#define TSMATRIX_H

#include<malloc.h>
#include<iostream>
#define Max_line 50                                //��������洢����
#define Maxsize 2500                               //���������Ĵ洢Ԫ�ظ���
using namespace std;
//==============================================================================//
typedef int elemType;                             //������������
typedef struct                                    //ÿ��Ԫ����һ����Ԫ��洢
{
	int i,j;                                      //���������ھ����������к���
	elemType elem;
}Triple;

typedef struct                                    //�������ṹ��
{
	Triple data[Maxsize+1];                       //�����е�Ԫ��
	int rpos[Max_line+1];                         //�����е�ÿ��Ԫ�ص��׵�ַ
	int row,col,total_elem;                       //����������������������ܷ�0Ԫ�ظ���
}TSMatrix,*PTSMatrix;
//================================================================================//
PTSMatrix Init_TSMatrix()                         //��ʼ��ϡ�����
{
	PTSMatrix TS;
	TS=(PTSMatrix )malloc(sizeof(TSMatrix));      //Ϊ�³�ʼ���ľ�������ռ�
	if(!TS)  
	{ 
		cout<<"Init error!"<<endl;                //�ռ�����ʧ��
		exit(0);
	}
	for(int w1=1;w1<=Max_line+1;w1++)             //��ʼ״̬���������������Ԫ��λ�ù���
		TS->rpos[w1]=0;
	for(int w2=1;w2<=Maxsize;w2++)                //�������е�ÿ��Ԫ�ؽ�����ݹ���
		TS->data[w2].elem=0;
	TS->total_elem=0;                             //������Ԫ�ء�������������ʼΪ��
	TS->col=0;        
	TS->row=0;
	return TS;
}
//=================================================================================//
//========================================================================================//
void Print_TSMatrix(PTSMatrix TS)                 //����洢��ϡ�����
{
	int k=1;
	for(int crow=1;crow<=TS->row;crow++)          //������������е�Ԫ��
	{
		for(int ccol=1;ccol<=TS->col;ccol++)      //��һ���е�ÿ��Ԫ�ر���
		{
			if(TS->data[k].i==crow && TS->data[k].j==ccol)
			{
				cout<<TS->data[k].elem<<" ";      //Ԫ�ش��ڣ����Ԫ��
				k++;
			}//if
			else                                  //Ԫ�ز����ڣ��ÿո����
				cout<<"  "; 
		}//for
		cout<<endl;                               //�������
	}//for
	//cout<<"TSMatrix row="<<TS->row<<endl        //�����ǰ�����е���������������������
	//	<<"TSMatrix col="<<TS->col<<endl
	//	<<"TSMatrix total_elem="<<TS->total_elem<<endl;
}
//===========================================================================================//
void Fast_Transpose_TSMatrix(PTSMatrix TS_1,PTSMatrix TS_2)    //ϡ�����ת��
{
	int k,ccol;
	int num[Max_line]={0};                      //���ڴ洢ת�ú�ĸ���Ԫ�ظ��������ڼ���ת�ú������Ԫ�ص�λ��
	int TS_Pos[Max_line]={0};                   //���ڴ洢ת�ú�ĸ�����Ԫ��λ��
	TS_2->row=TS_1->col;                        //ת�ú�ľ�������������
	TS_2->col=TS_1->row;
	TS_2->total_elem=TS_1->total_elem;          //��Ԫ�ز���
	if(TS_1->total_elem)                        //����ǿ�
	{
		for(k=1;k<=TS_1->total_elem;k++)        //�Ծ����е�ÿ��Ԫ�ؼ���
			++num[TS_1->data[k].j];
		TS_Pos[1]=1;
		for(ccol=2;ccol<=TS_1->col;ccol++)      //����ת�ú�ÿ����Ԫ�ص���λ��
			TS_Pos[ccol]=TS_Pos[ccol-1]+num[ccol-1];
		for(ccol=1;ccol<=TS_1->col;ccol++)      //��¼ת�ú�ľ����ÿһ�е�����λ��
			TS_2->rpos[ccol]=TS_Pos[ccol];
		for(k=1;k<=TS_1->total_elem;k++)        //�Խ�Ҫת�õľ������
		{
			ccol=TS_1->data[k].j;
			TS_2->data[TS_Pos[ccol]].elem=TS_1->data[k].elem;    //��Ԫ�ذ�����ǰ�����λ��ֱ�ӷ���ת�ú�ľ�����
			TS_2->data[TS_Pos[ccol]].i   =TS_1->data[k].j;       //ת�ú�Ԫ�ص��������꽻��
			TS_2->data[TS_Pos[ccol]].j   =TS_1->data[k].i;
			TS_Pos[ccol]++;                                      //ÿ�м���һ��Ԫ��֮�󣬼�¼������һ��Ԫ�ط���λ��˳�κ���
		}//for
	}//if
	TS_2->rpos[TS_2->row+1]=TS_2->total_elem+1;          //�������������һ��λ�ö�Ϊ�����β
	TS_2->data[TS_2->total_elem+1].i=TS_2->row+1;        //������������һ����Ԫ�ص�������Ϊ��������һ
}                                                        //�����������Ŀ����Ϊ�Ժ��ʵ�־���ļӷ��ͳ˷�������������Ϊ�жϽ���������
//==========================================================================================//
void TSMatrix_Add(PTSMatrix TS_1,PTSMatrix TS_2,PTSMatrix TS_Sum)  //ϡ��������
{
	if(!(TS_1->row==TS_2->row && TS_1->col==TS_2->col))            //�жϾ����Ƿ�Ϊͬ��
	{
		cout<<"Matrix_2 can't be added to Matrix_1!"<<endl;
		exit(0);
	}//if
	TS_Sum->row=TS_1->row;                                         //��Ӻ󣬾��������������
	TS_Sum->col=TS_1->col;
	for(int k1=1,k2=1,k=1;k1<=TS_1->total_elem || k2<=TS_2->total_elem;) 
	{                                                              //���������󶼱���
		if(TS_1->data[k1].i==TS_2->data[k2].i)                     //ͬһ��Ԫ��
		{
			if(TS_1->data[k1].j<TS_2->data[k2].j)                  //ͬһ��TS_1����С��Ԫ��ֱ�Ӳ���;�����
			{
				TS_Sum->data[k].elem=TS_1->data[k1].elem;
				TS_Sum->data[k].i   =TS_1->data[k1].i;
				TS_Sum->data[k].j   =TS_1->data[k1].j;
				k++; k1++; TS_Sum->total_elem++;
				continue;
			}
			else if(TS_1->data[k1].j>TS_2->data[k2].j)             //ͬһ��TS_2����С��Ԫ��ֱ�Ӳ���;�����
			{
				TS_Sum->data[k].elem=TS_2->data[k2].elem;
				TS_Sum->data[k].i   =TS_2->data[k2].i;
				TS_Sum->data[k].j   =TS_2->data[k2].j;
				k++; k2++; TS_Sum->total_elem++;
				continue;
			}
			else                                                         //ͬһ�У�ͬһ��
			{
				elemType sum=TS_1->data[k1].elem + TS_2->data[k2].elem;  //��Ԫ�����
				if(sum==0)                                               //��Ϊ�㣬������;����з������
				{
					k1++; k2++;
					continue;
				}
				TS_Sum->data[k].elem=sum;
				TS_Sum->data[k].i   =TS_1->data[k1].i;
				TS_Sum->data[k].j   =TS_1->data[k1].j;
				k++; k1++; k2++; TS_Sum->total_elem++;
				continue;
			}
		}//if
		else                                                //��ͬһ��Ԫ��
		{  
			if(TS_1->data[k1].i<TS_2->data[k2].i)           //��ͬһ��Ԫ�أ�TS_1������С��ֱ�Ӳ���
			{
				if(TS_1->data[k1].elem==0)  continue;             
				TS_Sum->data[k].elem=TS_1->data[k1].elem;
				TS_Sum->data[k].i   =TS_1->data[k1].i;
				TS_Sum->data[k].j   =TS_1->data[k1].j;
				k++; k1++;
				TS_Sum->total_elem++;
			}
		    else                                           //��ͬһ��Ԫ�أ�TS_1������С��ֱ�Ӳ���
			{
				if(TS_2->data[k2].elem==0)  continue;
				TS_Sum->data[k].elem=TS_2->data[k2].elem;
				TS_Sum->data[k].i   =TS_2->data[k2].i;
				TS_Sum->data[k].j   =TS_2->data[k2].j;
				k++; k2++; TS_Sum->total_elem++;
			}
		}//else
 	}//for
	int ccount,rrow,num[50]={0},TS_Poss[50]={0};
	for(int ccount=1;ccount<=TS_Sum->total_elem;ccount++)  //����;����е�ÿ��Ԫ�ظ���
			++num[TS_Sum->data[ccount].i];
	TS_Poss[1]=1;
	for(rrow=2;rrow<=TS_Sum->row;rrow++)                   //����ÿ��Ԫ�ص���Ԫλ��
		TS_Poss[rrow]=TS_Poss[rrow-1]+num[rrow-1]; 
	for(rrow=1;rrow<=TS_Sum->row;rrow++)                   //��¼ת�ú�ľ����ÿһ�е�����λ��
		TS_Sum->rpos[rrow]=TS_Poss[rrow];
	TS_Sum->rpos[TS_Sum->row+1]=TS_Sum->total_elem+1;      //�������������һ��λ�ö�Ϊ�����β
	TS_Sum->data[TS_Sum->total_elem+1].i=TS_Sum->row+1;    //������������һ����Ԫ�ص�������Ϊ��������һ
}                                                          //�����������Ŀ����Ϊ�Ժ��ʵ�־���ļӷ��ͳ˷�������������Ϊ�жϽ���������
//====================================================================================//

void TSMatrix_Multiply(PTSMatrix TS_1,PTSMatrix TS_2,PTSMatrix TS_Mult)  //ϡ�����˷�
{
	int arow,brow,ccol,p,q,t;
	elemType ctemp[Max_line];
	if(TS_1->col!=TS_2->row)                                 //�ж����������ܷ����
	{                                                        //�������������������������־��������
		cout<<"TS_1->col= "<<TS_1->col<<endl;
		cout<<"TS_2->row= "<<TS_2->row<<endl;
		cout<<"This two matrix can't multiply!"<<endl;
		exit(0);
	}
	TS_Mult->row=TS_1->row;                                  //���֮��ľ��������������
	TS_Mult->col=TS_2->col;
	TS_Mult->total_elem=0; 
	if(TS_1->total_elem*TS_2->total_elem)                    //�ж��Ƿ��о����ǿ�
	{
		for(arow=1;arow<=TS_1->row;arow++)                   //�����������б���
		{
			for(int cot=1;cot<Max_line;cot++)                //���洢��ʱ�˻���������
				ctemp[cot]=0;
			for(p=TS_1->rpos[arow]; p<TS_1->rpos[arow+1];p++)      //�Ծ����е�һ���е�ÿ��Ԫ�ر���
			{
				brow=TS_1->data[p].j;                              //��¼��ǰԪ�ص��������Ա�ݴ��ҵ��о����������˵�Ԫ�ض�Ӧ��
				for(q=TS_2->rpos[brow];q<TS_2->rpos[brow+1];q++)   //ʹ�Ҿ����е�һ��Ԫ����������е���ӦԪ�����
				{                                                  //�����˻�����ۼӵ���ʱ����˻�����ı�����
					ccol=TS_2->data[q].j;
					ctemp[ccol]+=TS_1->data[p].elem*TS_2->data[q].elem;
				}//for q
			}//for p
			for(ccol=1;ccol<=TS_Mult->col;ccol++)        //������һ��������������˻�������浽�˻�������
			{
				if(ctemp[ccol])                          //�˻���Ӧ�н����Ϊ�㣬����˻��������
				{
					TS_Mult->total_elem++;
					TS_Mult->data[TS_Mult->total_elem].i=arow;
					TS_Mult->data[TS_Mult->total_elem].j=ccol;
					TS_Mult->data[TS_Mult->total_elem].elem=ctemp[ccol];
				}//if (ctemp[])
			}//for(ccol)
		}//for(arow)
	}//if(TS_1)
}
//================================================================================================//
#endif
