#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct stu {
	string num;
	string name;
	int score;
}s[100000];

bool cmp1(stu a,stu b)
{
	return a.num.compare(b.num) < 0;
}
bool cmp2(stu a,stu b)
{
	return a.name.compare(b.name) < 0;
}
bool cmp3(stu a,stu b)
{
	return a.score > b.score;
}

int main()
{
	int n,c;
	int i,j;
	while(cin>>n>>c)
	{
		if(n>=1 && n<=10000 && c>=1 && c <=3)
		{
			for(i=0; i<n; i++)
			{
				int score;
				string num,name;
	            cin>>num>>name>>score;
				s[i].num = num;
				s[i].name = name;
				s[i].score = score;			
			}	
		}
		if(n == 0)
			break;
	}
	
	if(c == 1)
	{
		sort(s,s+n,cmp1);
	}else if(c == 2)
	{
		sort(s,s+n,cmp2);
	}else{
		sort(s,s+n,cmp3);	
	}
	
	for(j = 0;i<n; i++)
	{
		cout<<"Case:"<<c<<endl;
		cout<<s[j].num<<" "<<s[j].name<<" "<<s[j].score<<endl;
	}
	
	return 0;
}
