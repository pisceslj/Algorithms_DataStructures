#include <stdio.h>


int CountStr(char *str,char *s)
{
	int count = 0;
	char *s1,*s2;

	while(*str != '/0')	//��û����Ѱ��ĸ��ĩβ 
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
	printf("����ĸ��:");
	scanf("%s",&str);
	
	printf("��������Ӵ�:");
	scanf("%s",&s);
	
	count = CountStr(str,s);
	printf("�����Ӵ�����Ϊ��%d\n",count);
	
	return 0; 
} 