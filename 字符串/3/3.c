#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void *my_memcpy(void *,const void *,unsigned int);


//没有考虑内存重叠的情况
char *my_strcpy(char *dst , const char *src)
{
	assert(dst != NULL);//断言变量非空
	assert(src != NULL);

	char *rst = dst;//备份一个指向dst的指针

	//写法一	
	/*while(*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}*/

	//写法一的简略写法
	//while((*dst++ = *src++) != '\0');

	//考虑内存重叠的情况
	my_memcpy(dst,src,strlen(src)+1);//完成指定大小的内存拷贝	
	
	return rst;//返回复制的值	
}

//考虑内存重叠的情况
void *my_memcpy(void *dst,const void *src,unsigned int count)
{
	assert(dst != NULL);//断言变量非空
	assert(src != NULL);
	
	void *rst = dst;//保存一个指针
	//源地址和目的地址不重叠，低字节向高字节复制
	if((dst <= src) || ((char *)dst >= ((char *)src + count)))
	{
		while(count--)
		{
			*(char *)dst = *(char *)src; //复制
			(char *)dst++;
			(char *)src++;
		}
	}
	else   //源地址和目的地址重叠，高字节向低字节拷贝
	{
		dst = (char *)dst + count - 1; //确定新的高位指针位置
		src = (char *)src + count - 1;
		
		while(count--)
		{
			*(char *)dst = *(char *)src;
			(char *)dst--;
			(char *)src--;
		}
	}

	return rst;//返回拷贝完成的结果
}

int my_strcmp(const char *str1,const char *str2)
{
	assert(str1);//断言变量非空
	assert(str2);

	while(*str1 == *str2 && (*str1 != '\0') && (*str2 != '\0'))
	{
		str1++;
		str2++;
	}
	if((*str1 == '\0') && (*str2 == '\0'))
	{
			return 1;
	}
	else
	{
			return 0;
	}

}

int main(int argc,char *argv[])
{
	char *str1 = "lujieA";
	char *str2 = "lujieA";
	char str[10] = "abc";
	char *result;

	if(!my_strcmp(str1,str2))
	{
		perror("strcmp failed!");
		exit(1);
	}
	else
	{
		printf("my_strcmp ok\n");
	}

	result = (char *)malloc(sizeof(char *)*10);
	result = my_strcpy(result,str1);
	printf("\n复制结果为:%s\n",result);

	return 0;
}
