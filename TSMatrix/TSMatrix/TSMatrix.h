#ifndef TSMATRIX_H
#define TSMATRIX_H

#include<malloc.h>
#include<iostream>
#define Max_line 50                                //矩阵的最大存储行数
#define Maxsize 2500                               //矩阵中最大的存储元素个数
using namespace std;
//==============================================================================//
typedef int elemType;                             //定义数据类型
typedef struct                                    //每个元素用一个三元组存储
{
	int i,j;                                      //保存数据在矩阵中所在行和列
	elemType elem;
}Triple;

typedef struct                                    //定义矩阵结构体
{
	Triple data[Maxsize+1];                       //矩阵中的元素
	int rpos[Max_line+1];                         //矩阵中的每行元素的首地址
	int row,col,total_elem;                       //保存矩阵总行数、列数和总非0元素个数
}TSMatrix,*PTSMatrix;
//================================================================================//
PTSMatrix Init_TSMatrix()                         //初始化稀疏矩阵
{
	PTSMatrix TS;
	TS=(PTSMatrix )malloc(sizeof(TSMatrix));      //为新初始化的矩阵申请空间
	if(!TS)  
	{ 
		cout<<"Init error!"<<endl;                //空间申请失败
		exit(0);
	}
	for(int w1=1;w1<=Max_line+1;w1++)             //初始状态将矩阵的所有行首元素位置归零
		TS->rpos[w1]=0;
	for(int w2=1;w2<=Maxsize;w2++)                //将矩阵中的每个元素结点数据归零
		TS->data[w2].elem=0;
	TS->total_elem=0;                             //矩阵总元素、行数、列数初始为零
	TS->col=0;        
	TS->row=0;
	return TS;
}
//=================================================================================//
//========================================================================================//
void Print_TSMatrix(PTSMatrix TS)                 //输出存储的稀疏矩阵
{
	int k=1;
	for(int crow=1;crow<=TS->row;crow++)          //按行输出矩阵中的元素
	{
		for(int ccol=1;ccol<=TS->col;ccol++)      //对一行中的每个元素遍历
		{
			if(TS->data[k].i==crow && TS->data[k].j==ccol)
			{
				cout<<TS->data[k].elem<<" ";      //元素存在，输出元素
				k++;
			}//if
			else                                  //元素不存在，用空格填充
				cout<<"  "; 
		}//for
		cout<<endl;                               //换行输出
	}//for
	//cout<<"TSMatrix row="<<TS->row<<endl        //输出当前矩阵中的行数、列数和总数据数
	//	<<"TSMatrix col="<<TS->col<<endl
	//	<<"TSMatrix total_elem="<<TS->total_elem<<endl;
}
//===========================================================================================//
void Fast_Transpose_TSMatrix(PTSMatrix TS_1,PTSMatrix TS_2)    //稀疏矩阵转置
{
	int k,ccol;
	int num[Max_line]={0};                      //用于存储转置后的各行元素个数，便于计算转置后各行首元素的位置
	int TS_Pos[Max_line]={0};                   //用于存储转置后的各行首元素位置
	TS_2->row=TS_1->col;                        //转置后的矩阵行列数交换
	TS_2->col=TS_1->row;
	TS_2->total_elem=TS_1->total_elem;          //总元素不变
	if(TS_1->total_elem)                        //矩阵非空
	{
		for(k=1;k<=TS_1->total_elem;k++)        //对矩阵中的每行元素计数
			++num[TS_1->data[k].j];
		TS_Pos[1]=1;
		for(ccol=2;ccol<=TS_1->col;ccol++)      //计算转置后每行首元素的首位置
			TS_Pos[ccol]=TS_Pos[ccol-1]+num[ccol-1];
		for(ccol=1;ccol<=TS_1->col;ccol++)      //记录转置后的矩阵的每一行的行首位置
			TS_2->rpos[ccol]=TS_Pos[ccol];
		for(k=1;k<=TS_1->total_elem;k++)        //对将要转置的矩阵遍历
		{
			ccol=TS_1->data[k].j;
			TS_2->data[TS_Pos[ccol]].elem=TS_1->data[k].elem;    //将元素按照先前计算的位置直接放入转置后的矩阵中
			TS_2->data[TS_Pos[ccol]].i   =TS_1->data[k].j;       //转置后元素的行列坐标交换
			TS_2->data[TS_Pos[ccol]].j   =TS_1->data[k].i;
			TS_Pos[ccol]++;                                      //每行加入一个元素之后，记录该行下一个元素放入位置顺次后推
		}//for
	}//if
	TS_2->rpos[TS_2->row+1]=TS_2->total_elem+1;          //将矩阵的行数加一行位置定为矩阵结尾
	TS_2->data[TS_2->total_elem+1].i=TS_2->row+1;        //将矩阵行数加一的首元素的行数定为总行数加一
}                                                        //最后两个语句的目的是为以后的实现矩阵的加法和乘法建立基础，作为判断结束的条件
//==========================================================================================//
void TSMatrix_Add(PTSMatrix TS_1,PTSMatrix TS_2,PTSMatrix TS_Sum)  //稀疏矩阵求和
{
	if(!(TS_1->row==TS_2->row && TS_1->col==TS_2->col))            //判断矩阵是否为同型
	{
		cout<<"Matrix_2 can't be added to Matrix_1!"<<endl;
		exit(0);
	}//if
	TS_Sum->row=TS_1->row;                                         //相加后，矩阵的行列数不变
	TS_Sum->col=TS_1->col;
	for(int k1=1,k2=1,k=1;k1<=TS_1->total_elem || k2<=TS_2->total_elem;) 
	{                                                              //对两个矩阵都遍历
		if(TS_1->data[k1].i==TS_2->data[k2].i)                     //同一行元素
		{
			if(TS_1->data[k1].j<TS_2->data[k2].j)                  //同一行TS_1列数小，元素直接插入和矩阵中
			{
				TS_Sum->data[k].elem=TS_1->data[k1].elem;
				TS_Sum->data[k].i   =TS_1->data[k1].i;
				TS_Sum->data[k].j   =TS_1->data[k1].j;
				k++; k1++; TS_Sum->total_elem++;
				continue;
			}
			else if(TS_1->data[k1].j>TS_2->data[k2].j)             //同一行TS_2列数小，元素直接插入和矩阵中
			{
				TS_Sum->data[k].elem=TS_2->data[k2].elem;
				TS_Sum->data[k].i   =TS_2->data[k2].i;
				TS_Sum->data[k].j   =TS_2->data[k2].j;
				k++; k2++; TS_Sum->total_elem++;
				continue;
			}
			else                                                         //同一行，同一列
			{
				elemType sum=TS_1->data[k1].elem + TS_2->data[k2].elem;  //两元素求和
				if(sum==0)                                               //和为零，不插入和矩阵中否则插入
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
		else                                                //非同一行元素
		{  
			if(TS_1->data[k1].i<TS_2->data[k2].i)           //非同一行元素，TS_1的行数小，直接插入
			{
				if(TS_1->data[k1].elem==0)  continue;             
				TS_Sum->data[k].elem=TS_1->data[k1].elem;
				TS_Sum->data[k].i   =TS_1->data[k1].i;
				TS_Sum->data[k].j   =TS_1->data[k1].j;
				k++; k1++;
				TS_Sum->total_elem++;
			}
		    else                                           //非同一行元素，TS_1的行数小，直接插入
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
	for(int ccount=1;ccount<=TS_Sum->total_elem;ccount++)  //计算和矩阵中的每行元素个数
			++num[TS_Sum->data[ccount].i];
	TS_Poss[1]=1;
	for(rrow=2;rrow<=TS_Sum->row;rrow++)                   //计算每行元素的首元位置
		TS_Poss[rrow]=TS_Poss[rrow-1]+num[rrow-1]; 
	for(rrow=1;rrow<=TS_Sum->row;rrow++)                   //记录转置后的矩阵的每一行的行首位置
		TS_Sum->rpos[rrow]=TS_Poss[rrow];
	TS_Sum->rpos[TS_Sum->row+1]=TS_Sum->total_elem+1;      //将矩阵的行数加一行位置定为矩阵结尾
	TS_Sum->data[TS_Sum->total_elem+1].i=TS_Sum->row+1;    //将矩阵行数加一的首元素的行数定为总行数加一
}                                                          //最后两个语句的目的是为以后的实现矩阵的加法和乘法建立基础，作为判断结束的条件
//====================================================================================//

void TSMatrix_Multiply(PTSMatrix TS_1,PTSMatrix TS_2,PTSMatrix TS_Mult)  //稀疏矩阵乘法
{
	int arow,brow,ccol,p,q,t;
	elemType ctemp[Max_line];
	if(TS_1->col!=TS_2->row)                                 //判断两个矩阵能否相乘
	{                                                        //不能相乘则输出左矩阵的列数和又矩阵的行数
		cout<<"TS_1->col= "<<TS_1->col<<endl;
		cout<<"TS_2->row= "<<TS_2->row<<endl;
		cout<<"This two matrix can't multiply!"<<endl;
		exit(0);
	}
	TS_Mult->row=TS_1->row;                                  //相乘之后的矩阵的行数和列数
	TS_Mult->col=TS_2->col;
	TS_Mult->total_elem=0; 
	if(TS_1->total_elem*TS_2->total_elem)                    //判断是否有矩阵是空
	{
		for(arow=1;arow<=TS_1->row;arow++)                   //对左矩阵进行行遍历
		{
			for(int cot=1;cot<Max_line;cot++)                //将存储临时乘积变量归零
				ctemp[cot]=0;
			for(p=TS_1->rpos[arow]; p<TS_1->rpos[arow+1];p++)      //对矩阵中的一行中的每个元素遍历
			{
				brow=TS_1->data[p].j;                              //记录当前元素的列数，以便据此找到有矩阵中与此相乘的元素对应行
				for(q=TS_2->rpos[brow];q<TS_2->rpos[brow+1];q++)   //使右矩阵中的一行元素与左矩阵中的相应元素相乘
				{                                                  //并将乘积结果累加到临时保存乘积结果的变量中
					ccol=TS_2->data[q].j;
					ctemp[ccol]+=TS_1->data[p].elem*TS_2->data[q].elem;
				}//for q
			}//for p
			for(ccol=1;ccol<=TS_Mult->col;ccol++)        //左矩阵的一行运算结束，将乘积结果保存到乘积矩阵中
			{
				if(ctemp[ccol])                          //乘积对应列结果不为零，进入乘积结果矩阵
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
