#include"Read_File.h"
#include"Def_Huffman_Tree.h"


int main()
 {
	char chs[500];        //������ļ��ж������ĸ
	int weight[27]={0};   //���治ͬ��ĸ��Ȩ��
	int total_num;        //�����ܵĶ�����ĸ��
	int n;                //���������ĸ��������

	n=Read_File(&weight[0],chs,total_num);   //���ļ��ж���Ȩ�ء���ĸ������ĸ������������ĸ������
	HuffmanTree Huff_T=Init_HuffmanTree(n);  //��ʼ��Huffman��

	cout<<"The Huffman tree are here!"<<endl;
	HuffmanCoding(Huff_T,chs,&weight[0],n,total_num);  //���������ĸ���벢д���ļ�

	cout<<"The letters have been coded and written into file 'code.txt'!"<<endl<<endl;
	system("pause");

	cout<<endl<<"The codes in file 'code.txt' have been decoded "<<endl
		<<" and written into file 'Trans_code.txt'!"<<endl<<endl;
	Trans_Coding(Huff_T);                  //���ļ��еı�����벢д���ļ�
	return 0;
}