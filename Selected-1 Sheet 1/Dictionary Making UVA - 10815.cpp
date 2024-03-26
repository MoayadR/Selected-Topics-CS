#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    fast
    string s ;
    set<string>dict;
    string temp = "";
    while(cin>>s)
    {
        for(int i =0 ; i<s.size() ; i++)
        {
            if(isalpha(s[i]))
            {
                temp += s[i];
            }
            else
            {
                if(temp.size())
                {
                    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                    dict.insert(temp);
                }
                temp = "";
            }
        }

        if(temp.size())
        {
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            dict.insert(temp);
            temp = "";
        }
    }


    for(auto it : dict)
    {
        cout<<it<<endl;
    }
    return 0;
}
