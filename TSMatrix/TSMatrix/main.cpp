#include"TSMatrix.h"
#include"Read_File.h"
int main()
{
	PTSMatrix Matrix_1=Init_TSMatrix();           //��֤�������ݶ�ȡ�ɹ���Matrix_1�����ʼ����
	TSMatrix_Storage(Matrix_1,"TSMatrix_1.txt");  //��TSMatrix_1.txt�ļ��ж������
	cout<<"The original Matrix is "<<endl;
	Print_TSMatrix(Matrix_1);                     //���
	cout<<endl;

	PTSMatrix Matrix_2=Init_TSMatrix();           //��֤ת�þ�����ȷ��Matrix_2����Matrix_1ת�ú�ľ���
	Fast_Transpose_TSMatrix(Matrix_1,Matrix_2);   //����ת��
	cout<<"The transpose Matrix is "<<endl;
	Print_TSMatrix(Matrix_2);                     //���
	cout<<endl;

	PTSMatrix Matrix_3=Init_TSMatrix();           //��֤�ӷ�������ȷ��Matrix_3������Matrix_1��ӵľ���
	PTSMatrix Matrix_4=Init_TSMatrix();           //Matrix_4�������Matrix_3������Matrix_1��ӵĺ�
	TSMatrix_Storage(Matrix_3,"TSMatrix_2.txt");
	TSMatrix_Add(Matrix_2,Matrix_3,Matrix_4);     //�������
	cout<<"The sum Matrix is "<<endl;
	Print_TSMatrix(Matrix_4);                   
	cout<<endl;

	
	PTSMatrix Matrix_5=Init_TSMatrix();               //�������ĳ˷����
    TSMatrix_Multiply(Matrix_1,Matrix_2,Matrix_5);    //Matrix_1��Matrix_2��Matrix_1��ת�ã���˱��浽Matrix_5��
	cout<<"The multiply of these two Matrix is "<<endl;
	Print_TSMatrix(Matrix_5);
    cout<<endl;
	system("pause");

	return 0;
}