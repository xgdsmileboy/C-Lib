//#include<stdio.h>
//int fun(int n)
//{
//	if(n==1)return 0;
//	for(int t=2;t<n;t++)
//		if(n%t==0)return 0;
//	return 1;
//}
//int main()
//{
//	int n,n1;
//	scanf("%d",&n);
//	n1=n;
//	n1--;
//	if(n>0&&n%2==0)
//	{
//		int m;
//        L:
//		while(n1--)if(fun(n1)==1){m=fun(n1);break;}
//		if(fun(n-m)==1){printf("%d=%d+%d\n",n,n-m,m);return 0;}
//		else {
//		      goto L;
//		}
//	}
//	else puts("error in input\n");
//	return 0;
//}