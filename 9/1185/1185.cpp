#include <stdio.h>
#include <algorithm>
using namespace std;

int main() 
{
     int n,i;
     int r[1000];
     while(scanf("%d",&n) != EOF)
     {
          if(n >= 1 && n <= 1000){
           for(i=0; i<n; i++)
           {
                 scanf("%d", &r[i]);
           }
           sort(r, r+n);
          if(n == 1)
         {
                 printf("%d\n",r[0]);
                 printf("-1\n");
         }else{
                printf("%d\n",r[n-1]);
                  for(i=0; i<n-1; i++)
                 {
                           printf("%d ",r[i]);
                  }
                  printf("\n"); 
         }
      }
    }
     return 0;
}