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
	return a.score < b.score;
}

int main()
{
	int n,c;
	int i,j;
	int cnt=1;
	while(cin>>n>>c)
	{
		if(n == 0)
			break;
		for(i=0; i<n; i++)
		{
			int score;
			string num,name;
	        cin>>num>>name>>score;
			s[i].num = num;
			s[i].name = name;
			s[i].score = score;			
		}			
		
		sort(s,s+n,cmp1);
		switch(c)
		{
			case 1:
			   break;	
			case 2:
				stable_sort(s,s+n,cmp2);
				break;
			case 3:
				stable_sort(s,s+n,cmp3);
				break;
		}
	
	    cout<<"Case:"<<cnt<<endl;
        cnt++;
		for(j = 0;j<n; j++)
		{	
			cout<<s[j].num<<" "<<s[j].name<<" "<<s[j].score<<endl;
		}
	}
	return 0;
}
