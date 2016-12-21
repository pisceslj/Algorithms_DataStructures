/****给定字符串A和B,输出A和B中的最大公共子串。比如A="aocdfe" B="pmcdfa" 则输出"cdf"***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MaxCommonStr(char *str1,char *str2)
{
	char *s1;
	char *s2;
	char temp[1024];
	int max = 0,sum = 0;

	while(*str1 != '\0')
	{
		s1 = str1;
		s2 = str2;		
		sum = 0;
		memset(temp,0,sizeof(temp));

		while(*s2 != '\0')
		{
			if(*s1 == *s2 && (*s1 != '\0') && (*s2 != '\0'))
			{
				temp[sum++] = *s1;
				s1++;
				s2++;
			}else
			{
				s2++;		
			}					
		}
		if(max < sum)
		{			
			max = sum;			
			printf("\n%d\n",max);
			//printf("\n%s\n",temp);
		}			
		
		str1++;
	}	
}

int main(int argc,char *argv[])
{
	char *str1;
	char *str2;

	printf("输入字符串A：");
	scanf("%s",str1);
	printf("输入字符串B：");
	scanf("%s",str2);

	MaxCommonStr(str1,str2);

	return 0;
}




