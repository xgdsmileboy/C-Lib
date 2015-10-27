#ifndef DEF_HUFFMAN_TREE_H
#define DEF_HUFFMAN_TREE_H
#include<malloc.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct {
	char letter;               //叶子节点保存字母，内部节点初始化为‘#’
	unsigned int weight;       //权重
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char *HuffmanCode;
///=============================================================///
HuffmanTree Init_HuffmanTree(int n)  //Huffman树的初始化
{
	HuffmanTree Huff_T;
	n*=2;
	if(!(Huff_T=(HuffmanTree)malloc(n*sizeof(HTNode))))  //为Huffman树申请内存空间
	{
		cout<<"Init Error!"<<endl;
		exit(0);
	}
	return Huff_T;
}
///============================================================///
void HuffmanCoding(HuffmanTree Huff_T,HuffmanCode Huff_C,int w[],int n,int total_num)
{                           //w存放n种不同字符的权值，total_num保存读取的总字符个数构造哈夫曼树Huff_T，并求出n个字符的哈夫曼编码Huff_C
	int m=2*n-1;            //生成树的总节点数，其中有n个叶子节点，n-1个内部节点
	int i=1,j=0,s1=0,s2=0;
	void Push_Code_to_File(char *code);
	void Select(HuffmanTree Huff_T,int n,int &s1,int &s2);
	if(n<=1) return ;

	for(i=1,j=1;i<=n&&j<Max_num;j++)     //将n种字母依序存入Huffman树的前n个节点中，作为Huffman树的叶子节点
	{ 
		if(w[j]==0) continue;
		Huff_T[i].weight=w[j];           //权值
		Huff_T[i].lchild=0;              //初始状态左右孩子和父母置为零，0号不作为Huffman树存储
		Huff_T[i].rchild=0;
		Huff_T[i].parent=0;
		Huff_T[i].letter=(char)(j+'A'-1);     //将该权重所对应的字符还原到Huffman树中
		i++;
	}
	for(;i<=m;i++)                            //除去前n个叶子节点，剩下节点初始化
	{
		Huff_T[i].weight=0;
		Huff_T[i].lchild=0;
		Huff_T[i].rchild=0;
		Huff_T[i].parent=0;
		Huff_T[i].letter='#';
	}
	for(i=n+1;i<=m;i++)
	{
		Select(Huff_T,i-1,s1,s2);     //从前i-1个元素中选出两个最小权重节点，生成新节点
		Huff_T[s1].parent=i;          //用于生成的节点父母指针指向新生成的节点
		Huff_T[s2].parent=i;
		Huff_T[i].lchild=s1;          //新生成的节点的左右孩子指针修改
		Huff_T[i].rchild=s2;
		Huff_T[i].weight=Huff_T[s1].weight+Huff_T[s2].weight;   //新生成节点的权重为用于生成该节点的两节点的权重和
	}
	//=====================输出Huffman树===================================================//
	cout<<"adress  "<<"weight  "<<"parent  "<<"lchild  "<<"rchild  "<<"letter  "<<endl;
	for(int w=1;w<=m;w++)
	{
		cout<<w<<"	  "<<Huff_T[w].weight<<"   	  "<<Huff_T[w].parent<<"	  "
			<<Huff_T[w].lchild<<"	  "<<Huff_T[w].rchild<<"	  "<<Huff_T[w].letter<<endl;
	}
	cout<<endl;
	//======================================================================================//
	FILE *fp0;
	fp0=fopen("code.txt","w");                             //将code.txt文件中的内容清空
	if(fp0==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fclose(fp0);

	int c,f;                                               //以下部分对从文件中读入的字符进行编码，并将编码写入文件
	char cod[11]={'0'}, cods[11]={'0'};    
	for(i=1;i<=total_num;i++)                              //对所有字符遍历
	{
		for(j=1;Huff_C[i]!=Huff_T[j].letter;j++);          //找到将要编码的字母的位置
		cod[10]='\0';                                      //用于倒序保存字母的编码，因为编码过程是从叶子节点向根节点逆推
		int start=10;                                      //用于指示当前保存编码cod[]的位置
		for(c=j,f=Huff_T[j].parent;f!=0;c=f,f=Huff_T[f].parent) //用c保存当前逆推到的节点，f保存c的父母
		{
			
			if(Huff_T[f].lchild==c)    //判断c是f的左孩子还是有孩子
				cod[--start]='0';      //规定：左孩子编码为'0',右孩子编码为'1'
			else
				cod[--start]='1';

		}
		strcpy(cods,&cod[start]);     //将完整的字母编码保存到cods中
		Push_Code_to_File(cods);      //将编码写入文件函数
	}
}
///=======================================================================================///
void Push_Code_to_File(char *code)    //将一个字符串写入文件中
{
	FILE *fp;
	fp=fopen("code.txt","a");         //'a'为“追加”模式打开文件
	if(fp==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fprintf(fp,"%s",code);
	fclose(fp);
}
///==================================================================================///
void Trans_Coding(HuffmanTree Huff_T)      //将从文件中读取的代码翻译成字符
{
	FILE *fp,*fp2;
	char code;
	int threading;

	fp2=fopen("trans_code.txt","w");       //将trans_code.txt文件中的内容清空
	if(fp2==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	fclose(fp2);

	fp=fopen("code.txt","rt");             //文件指针fp指向编码文件
	fp2=fopen("trans_code.txt","a");       //文件指针fp2指向解码之后保存字母的文件
	if(fp==NULL||fp2==NULL)
	{
		cout<<"Open File Failed!"<<endl;
		exit(0);
	}
	if(feof(fp))                          //判断编码文件是否为空
	{
		cout<<"Empty !"<<endl;
		exit(0);
	}
	fscanf(fp,"%c",&code);               //从编码文件中读入0、1码
	while(!feof(fp))
	{
		for(threading=1;Huff_T[threading].parent;threading++);            //寻找根节点
		while(Huff_T[threading].rchild!=0 ||Huff_T[threading].lchild!=0)  //从根开始走到叶子
		{
			if(code=='1') threading=Huff_T[threading].rchild;             //读到的编码是'1'，rchild支路
			else threading=Huff_T[threading].lchild;                      //否则，走lchild支路
			fscanf(fp,"%c",&code);                                        //循环读入0、1码
		}
		fprintf(fp2,"%c",Huff_T[threading].letter);                       //走到叶子节点，将字符写入文件
	}
	fclose(fp);
	fclose(fp2);
}
///==========================================================================///
void Select(HuffmanTree Huff_T,int n,int &s1,int &s2) 
{                                               //从Huffman树的前n个节点中选出两个权重最小的节点，返回位置信息是s1、s2                                  
	int i=1,lit,lit1,lit2;
	HuffmanTree p;
	for(p=Huff_T+1,s1=1;p->parent;p=p++,s1++);  //选其中还没有父母的节点
	lit1=p->weight;
	for(p++,s2=s1+1;p->parent;p++,s2++);        //选其中还没有父母的节点
	lit2=p->weight;
	if(lit1>lit2)                               //保证lit1中保存的节点的权重不大于lit2的
	{
		lit=lit1;
		lit1=lit2;
		lit2=lit;
		lit=s1;s1=s2;s2=lit;
	}
	for(p=++Huff_T,i=1;i<=n;i++,p++)
	{
		if(i==s1 || i==s2) continue;      //s1，s2位置节点不再重选
		if(p->parent) continue;           //已经被选过节点，不再重选
		if(lit2<=p->weight) continue;     //当前节点的权重比lit1和lit2中的教大权重还大
		if(lit1<=p->weight)               //当前节点权重位于lit1和lit2之间
		{                                 //只需修改较大的
			lit2=p->weight;
			s2=i;	
			continue;
		}
		lit2=lit1;                        //将lit1和lit2全部更新
		s2=s1;
		lit1=p->weight;
		s1=i;
	}
}
///==========================================================================///
#endif