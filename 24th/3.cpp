#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int w, s1;
string str;

vector<int> num;
vector<int> res;

int judge(int t)
{
    if(t >= 48 && t <= 57) return 0;    //数字
    if(t >= 65 && t <= 90) return 1;   //大写
    else return -1;         //小写
}


int main()
{
    cin >> w >> s1;
    cin >> str;
    
    int flag = 1;  // 1 大写； 0 数字； -1 手写

    for(int i = 0; i < str.length(); i ++)
    {
        int t = str[i];
        int s = judge(t);
        
        if(s == 1)
        {
            t = t - 65;
            if(flag == 1) num.push_back(t);
            if(flag == 0) num.push_back(28), num.push_back(t);
            if(flag == -1) num.push_back(28), num.push_back(28), num.push_back(t);
            flag = 1;
        }

        if(s == 0)
        {
            if(flag == 1) num.push_back(28), num.push_back(t);
            if(flag == 0) num.push_back(t);
            if(flag == -1) num.push_back(27), num.push_back(t);
            flag = 0;
        }

        if(s == -1)
        {
            t = t - 97;
            if(flag == 1 || flag == 0) num.push_back(27), num.push_back(t);
            if(flag == -1) num.push_back(t);
            flag = -1;
        }
    }

    if(num.size() % 2 != 0 ) num.push_back(29);

    for(int i = 0; i < num.size(); i += 2)
    {
        int m = 30 * num[i] + num[i + 1];
        res.push_back(m);
    }

    int count = 0;
    count = res.size() + 1;
    
    if(w)
    {
        if(count % w == 0) cout << count << endl;
        else cout << (count / w  + 1) * w << endl;
        
        while(count % w != 0)
        {
            count ++;
            res.push_back(900);
        }
    }
    for(int i = 0; i < res.size(); i ++)
        cout << res[i] << endl;
    
    return 0;
}