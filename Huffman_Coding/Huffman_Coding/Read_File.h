#ifndef READ_FILE_H
#define READ_FILE_H
#define Max_num 27            //�ܵ���ĸ��������0�Ŵ洢����
#include"Def_Huffman_Tree.h"
#include<malloc.h>
///===================================================================///
int Read_File(int weight[],char Letter[],int &total_num)  //��ȡ�ļ�
{
	char ch;
	int i=0,j=0,term;
	int everyletter_num[27]={0};      //������ȡ�Ĳ�ͬ�ַ�������������������ʱҶ�ӽڵ��Ȩ��
	total_num=0;                      //�����ļ��е����ַ�����
	FILE *fp;                         //�ļ�ָ��
	fp=fopen("text.txt","rt");        //�򿪱����ַ����ļ�
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%c",&ch);          //���ļ���һ�ζ�ȡ�ַ�
		if(ch=='\n'||ch=='\0')continue;
		j++;total_num++;              //��ȡ��ĸ�����ַ����Լ�һ��
		Letter[j]=ch;                  //���մ��򱣴��ȡ���ַ�
	//	cout<<Letter[j]<<"	"<<endl;
		everyletter_num[(int)(ch-'A'+1)]++;  //Ĭ�ϴ�1-26�ŷֱ𱣴���ĸA-Z������
	}
	total_num--;                          //�����ڶ�ȡ�ļ�ʱ���һ����ĸ���Ǳ��������Σ��ڴ���һ����    
	Letter[j]-=1;                         //������
	everyletter_num[(int)(ch-'A'+1)]--;   //������
	//cout<<"Total  "<<total_num<<endl;
	//for(int s=1;s<=26;s++)
	//	cout<<everyletter_num[s]<<"	";
	//cout<<endl;
	fclose(fp);                           //�ر��ļ�
	for(j=1;j<Max_num;j++)
	{
		if(!everyletter_num[j]) continue;
		i++;
		weight[j]=everyletter_num[j];    //��Ȩ�ظ������ر���
	}
	//for(int i=1;i<Max_num;i++)
	//	cout<<weight[i]<<"	";
	//cout<<endl;
	return i;
}
//==========================================================================//
#endif