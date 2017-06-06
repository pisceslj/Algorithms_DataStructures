#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int DivideNum(int num)
{
      int m[5]={0};
      int i = 0;
      int j,result=0;
     
      while(num > 10)
      {
           m[i] = num%10;
           num = num/10;
           i++;
      }
      if(num < 10)
      {
            m[i] = num;
      }
      for(j=0;j<=i;++j)
	  {
         result = result + m[j]*pow(10,(i-j));
  	  } 
      return result;
}

int main()
{
       int n,a[100],b[100];
	   int tmp_a,tmp_b,tmp_c,tmp_d;
	   char tmp[100];
       int i =0,j,k;
       while(scanf("%d",&n) != EOF)
	   {
	   		for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
			}
			
			for(j=0;j<n;j++)
	   		{
				tmp_a = DivideNum(a[j]); //21
				tmp_b = DivideNum(b[j]); //43
				tmp_c = tmp_a + tmp_b;   //64
			    tmp_d = DivideNum(a[j]+b[j]); //46 to 64
			    if(tmp_c == tmp_d)
			    {
			    	printf("%d\n",a[j]+b[j]);
    			}else{
			    	printf("NO\n");
			    }
   	   		}
	   }
	   
	   return 0;
}