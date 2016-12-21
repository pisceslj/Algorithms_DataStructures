#include <stdio.h>
#include <string.h>

int CountStr(char *str,char *s)
{
	int count = 0;
	char *s1,*s2;

	while(*str != '\0')	//未搜索到母串尾部
	{
		s1 = str;
		s2 = s;
		while(*s1 == *s2 && (*s1 != '\0') && (*s2 != '\0'))
		{
			s1++;
			s2++;	
		}
		if(*s2 == '\0')
		{
			count++;
		}
		
		str++;	
	}
	
	return count;
}


int main(int argc,char *argv[])
{
	int count;
	char *str,*s;
	printf("输入母串:");
	scanf("%s",str);
	
	printf("输入子串:");
	scanf("%s",s);
	
	count = CountStr(str,s);
	printf("子串个数为%d\n",count);
	
	return 0; 
} 
