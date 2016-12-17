#include <stdio.h>
#include <stdlib.h>

//暴力解法 
void Mul(int **matrixA,int **matrixB,int **matrixC,int N)
{
	int i,j,k;
	for(i = 0;i<N;++i)
	{
		for(j = 0;j<N;++j)
		{
			matrixC[i][j] = 0;
			for(k = 0;k<N;++k)
			{
				matrixC[i][j] = matrixA[i][k]*matrixB[k][j];
			}
		}
	}
}

int main(int argc,char *argv[])
{
		int n;
		int i,j;
		int **matrixA;
		int **matrixB;
		int **matrixC;
		
		printf("请输入矩阵阶数：");
		scanf("%d",&n);
		printf("请输入矩阵A的值：");
		matrixA = (int **)malloc(sizeof(int *)*n);
		for(i = 0;i<n;++i)
		{
			for(j = 0;j<n;++j)
			{
				scanf("%d\n",&matrixA[i][j]);
			}
		}
		printf("请输入矩阵B的值：");
		for(i = 0;i<n;++i)
		{
			for(j = 0;j<n;++j)
			{
				scanf("%d",&matrixB[i][j]);
			}
		}
		
		Mul(matrixA,matrixB,matrixC,n);
		printf("矩阵C的值为：");
		for(i = 0;i<n;++i)
		{
			printf("\n");
			for(j = 0;j<n;++j)
			{
				printf("%d",matrixC[i][j]);
			}
		}
		 
		return 0;	
}

