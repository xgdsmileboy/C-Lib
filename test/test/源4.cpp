#include<stdio.h>
#include<malloc.h>
int chh()
{
	return 0;
}

int main()
{
	int n,n1;
	int *p;
	scanf("%d",&n);
	n1=n;
	chh();
	p=(int *)malloc(n*sizeof(int ));
	for(int t=0;t<n;t++)scanf("%d",p+t);
	for(int k=0;k<n;k++)
		for(int f=k+1;f<n;f++)
		{
			int h;
			if(*(p+k)<*(p+f))
			{
				h=*(p+k);
				*(p+k)=*(p+f);
                *(p+f)=h;
			}
		}
		for(int y=0;y<n;y++)printf("%d ",*(p+y));
		putchar(10);
	free(p);
	return 0;
}
