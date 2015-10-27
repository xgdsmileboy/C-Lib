#ifndef READ_FILE_H
#define READ_FILE_H
#define Max_num 27            //总的字母种类数，0号存储不用
#include"Def_Huffman_Tree.h"
#include<malloc.h>
///===================================================================///
int Read_File(int weight[],char Letter[],int &total_num)  //读取文件
{
	char ch;
	int i=0,j=0,term;
	int everyletter_num[27]={0};      //计数读取的不同字符的数量，用于生成树时叶子节点的权重
	total_num=0;                      //计数文件中的总字符个数
	FILE *fp;                         //文件指针
	fp=fopen("text.txt","rt");        //打开保存字符的文件
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%c",&ch);          //从文件中一次读取字符
		if(ch=='\n'||ch=='\0')continue;
		j++;total_num++;              //读取字母，总字符数自加一，
		Letter[j]=ch;                  //按照次序保存读取的字符
	//	cout<<Letter[j]<<"	"<<endl;
		everyletter_num[(int)(ch-'A'+1)]++;  //默认从1-26号分别保存字母A-Z的数量
	}
	total_num--;                          //由于在读取文件时最后一个字母总是被读入两次，在此做一修正    
	Letter[j]-=1;                         //修正量
	everyletter_num[(int)(ch-'A'+1)]--;   //修正量
	//cout<<"Total  "<<total_num<<endl;
	//for(int s=1;s<=26;s++)
	//	cout<<everyletter_num[s]<<"	";
	//cout<<endl;
	fclose(fp);                           //关闭文件
	for(j=1;j<Max_num;j++)
	{
		if(!everyletter_num[j]) continue;
		i++;
		weight[j]=everyletter_num[j];    //将权重赋给返回变量
	}
	//for(int i=1;i<Max_num;i++)
	//	cout<<weight[i]<<"	";
	//cout<<endl;
	return i;
}
//==========================================================================//
#endif