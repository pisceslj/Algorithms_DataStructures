#include <stdio.h>

int checkCPU()
{
	union
	{
		int a;
		char b;	
	}c;
	c.a = 1;
	
	return (c.b == 1);
}

int main(int argc,char *argv[])
{
	int result;
	result = checkCPU();
	if(result == 1)
		printf("大端模式\n");
	else
		printf("小端模式\n");
		
	return 0;
} 