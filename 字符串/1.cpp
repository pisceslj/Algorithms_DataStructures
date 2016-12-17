#include <stdio.h>


int CountStr(char *str,char *s)
{
	int count = 0;
	char *s1,*s2;

	while(*str != '/0')	//还没有搜寻到母串末尾 
	{
		s1 = str;
		s2 = s;
		while(*s1 == *s2 && (*s1 != '/0') && (*s2 != '/0'))
		{
			s1++;
			s2++;	
		}
		if(*s2 == '/0')
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
	scanf("%s",&str);
	
	printf("输入待查子串:");
	scanf("%s",&s);
	
	count = CountStr(str,s);
	printf("待查子串个数为：%d\n",count);
	
	return 0; 
} 