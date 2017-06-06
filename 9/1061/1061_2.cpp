#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct stu {
	char name[101];
	int age;
	int score;
	
	bool operator <(const stu &b)const{
	if(score == b.score)
	{
		int tmp = strcmp(name,b.name);
		if(tmp == 0)
		{
			return age < b.age;
		}else {
			return tmp < 0;
		}
	}else{
		return score < b.score;
	}	
  }
}buf[1000];


int main()
{
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>buf[i].name>>buf[i].age>>buf[i].score;
		}
		
		sort(buf,buf+n);
		
		for(int j=0 ;j<n; j++)
		{
			cout<<buf[j].name<<" "<<buf[j].age<<" "<<buf[j].score<<endl;
		}
	}
	return 0;
}