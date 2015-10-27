#ifndef READ_FILE_H
#define READ_FILE_H
#include"TSMatrix.h"

void TSMatrix_Storage(PTSMatrix TS,char * file_name)     //���ļ��ж�����󣬲�ʵ��ϡ������ѹ���洢
{                                                        //����Ϊ�������Ԫ�صľ���ָ�룬�ͽ�Ҫ��ȡ���ļ���
	int i=1,j=1;
	elemType term;

	cout<<"Please enter the row_number and col_number of the TSMatrix!"<<endl;  //�����ļ��о�����С�����
	cout<<"row "<<"colum"<<endl;                        //��ʾ���
	cin>>TS->row>>TS->col;                              //������������������
	TS->rpos[1]=1;
	FILE *fp;
	fp=fopen(file_name, "rt");
	if(fp==NULL)                                        //���ļ�ʧ��
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp, "%d", &term);
		if(j>TS->col)                                   //���к󣬽���һ�е���Ԫ��λ�ü�¼
		{
			i++;j=1;
			TS->rpos[i]=TS->total_elem+1;
		}
		if(term==' '||term==0) { j++; continue;}
		TS->data[TS->total_elem+1].elem=term;           //Ԫ�ز��������
		TS->data[TS->total_elem+1].i=i;
		TS->data[TS->total_elem+1].j=j;
		TS->total_elem++;
		j++;
	}//while
	TS->rpos[TS->row+1]=TS->total_elem+1;               //�������������һ��λ�ö�Ϊ�����β
	TS->data[TS->total_elem+1].i=TS->row+1;             //������������һ����Ԫ�ص�������Ϊ��������һ
	fclose(fp);                                         //�ر��ļ�
}
//==========================================================================//
#endif