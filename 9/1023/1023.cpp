#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
	string num;
	string name;
	int score;
}s[100000];

int c;
bool cmp(stu a,stu b)
{
	cout<<"ok1"<<endl;
	if(c == 1)
	{
		cout<<"ok"<<endl;
		return a.num < b.num;
	}else if(c == 2){
		return a.name < b.name;
	}else{
		return a.score < b.score;
	}
}

int main()
{
	int n;
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
	
	//sort(s,s+n,cmp);
	
	for(j = 0;i<n; i++)
	{
		cout<<"Case:"<<c<<endl;
		cout<<s[j].num<<" "<<s[j].name<<" "<<s[j].score<<endl;
	}
	
	return 0;
}
