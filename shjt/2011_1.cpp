#include <iostream>  
#include <fstream>  
#include <string>  
#include <cmath>  
#include <algorithm>  
#include <iomanip>  
  
using namespace std;  
  
int main()  
{  
    string s;  
    string sop = "+-=";  
    size_t loc1, loc2;  
    float a, b, c;  
    bool bEqual, bMinus;  
  
	#ifndef ONLINE_JUDGE  
		ifstream cin("/home/algorithms/Algorithms_DataStructures/上交机试题/uva_in.txt");  //从标准输入读取二次式
	#endif // ONLINE_JUDGE  
  
    while (cin >> s)
	{  
        loc1 = -1;  
        loc2 = 0;  
        bEqual = false;  
        bMinus = false;  
        a = b = c = 0;  //ax^2 + bx + c = 0
  
        while (loc2 < s.length()) 
		{  
            loc2 = s.find_first_of(sop, loc1 + 1); //查找与字符串sop中某个字符相同的位置，并返回他的第一个出现的位置，如果没有则返回string::npos;即最后一个字符的后面一个位置
            if (loc2 == string::npos) 
			{  
                loc2 = s.length();  
            }  
  
            string sub = s.substr(loc1 + 1, loc2 - loc1 - 1);  //获得字符串s中 从第（loc1 + 1）位开始的长度为（loc2 - loc1 - 1）的字符串
            //cout << "sub:" << sub << endl;  
  
            if (sub.find('x') == string::npos) //没找到X
			{  
                if ((!bEqual && !bMinus) || (bEqual && bMinus))  
                    c += atoi(sub.c_str());  
                else  
                    c -= atoi(sub.c_str());  
            }
			else if (sub.find('^') == string::npos) //没找到^
			{  
                if ((!bEqual && !bMinus) || (bEqual && bMinus))
				{  
                    if (sub.length() == 1)
					{  
                        b += 1;  
                    }
					else
					{  
                        b += atoi(sub.c_str());  //string类对象的成员函数c_str()把string 对象转换成c中的字符串样式
                    }  
                } 
				else
				{  
                    if (sub.length() == 1)
					{  
                        b -= 1;  
                    } else {  
                        b -= atoi(sub.c_str());  
                    }  
                }  
            } 
			else
			{  
                if ((!bEqual && !bMinus) || (bEqual && bMinus)) {  
                    if (sub.length() == 3) {  
                        a += 1;  
                    } else {  
                        a += atoi(sub.c_str());  
                    }  
                } else {  
                    if (sub.length() == 3) {  
                        a -= 1;  
                    } else {  
                        a -= atoi(sub.c_str());  
                    }  
                }  
            }  
  
            loc1 = loc2;  
            if (loc2 < s.length() && s.at(loc2) == '-') bMinus = true;  
            else if (loc2 < s.length() && s.at(loc2) == '=') bEqual = true;  
            else bMinus = false;  
  
            //cout << "a:" << a << " b:" << b << " c:" << c << endl;  
        }  
  
        if (b * b - 4 * a * c < 0)  //b^2-4ac < 0 表示无实数解
		{  
            cout << "No Solution" << endl;  
        } 
		else 
		{  
            float result1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);  
            float result2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);  
			//按照从小到大顺序打印结果            
			if (result1 > result2) 
				swap(result1, result2);  
  
            cout.precision(2);  
            cout.setf(ios::fixed);  
            cout << result1 << " " << result2 << endl;  
        }  
    }  
    return 0;  
}  
