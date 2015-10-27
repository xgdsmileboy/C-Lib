#ifndef READ_FILE_H
#define READ_FILE_H
#include"TSMatrix.h"

void TSMatrix_Storage(PTSMatrix TS,char * file_name)     //从文件中读入矩阵，并实现稀疏矩阵的压缩存储
{                                                        //参数为保存矩阵元素的矩阵指针，和将要读取的文件名
	int i=1,j=1;
	elemType term;

	cout<<"Please enter the row_number and col_number of the TSMatrix!"<<endl;  //输入文件中矩阵的行、列数
	cout<<"row "<<"colum"<<endl;                        //提示语句
	cin>>TS->row>>TS->col;                              //读入矩阵的行数和列数
	TS->rpos[1]=1;
	FILE *fp;
	fp=fopen(file_name, "rt");
	if(fp==NULL)                                        //打开文件失败
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		if(j>TS->col)                                   //换行后，将下一行的首元素位置记录
		{
			i++;j=1;
			TS->rpos[i]=TS->total_elem+1;
		}
		if(term==' '||term==0) { j++; continue;}
		TS->data[TS->total_elem+1].elem=term;           //元素插入矩阵中
		TS->data[TS->total_elem+1].i=i;
		TS->data[TS->total_elem+1].j=j;
		TS->total_elem++;
		j++;
	}//while
	TS->rpos[TS->row+1]=TS->total_elem+1;               //将矩阵的行数加一行位置定为矩阵结尾
	TS->data[TS->total_elem+1].i=TS->row+1;             //将矩阵行数加一的首元素的行数定为总行数加一
	fclose(fp);                                         //关闭文件
}
//==========================================================================//
#endif