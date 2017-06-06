#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct stu {
     char name[101];
     int age;
     int score;
}buf[1000];

bool cmp(stu a, stu b)
{
      if(a.score == b.score)
      {
      		int tmp = strcmp(a.name,b.name);
            if(tmp == 0)
			{
				return a.age < b.age;
			}else{
				return tmp < 0;
			}
      }else{
            return a.score < b.score;
      }
}

int main()
{
     int n;
     while(scanf("%d",&n) != EOF)
     {
            for(int i=0;i <n;++i)
            {
                     scanf("%s%d%d", buf[i].name,&buf[i].age,&buf[i].score);
             }
             
             sort(buf,buf+n,cmp);

			for(int j=0;j< n;j++)
            {
              printf("%s %d %d\n",buf[j].name,buf[j].age,buf[j].score);
            }
     }

     

      return 0;
}

