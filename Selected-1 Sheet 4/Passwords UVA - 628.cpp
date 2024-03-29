#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

vector<string>passwords;
void generatePasswords(const vector<string>&words ,string rule , int idx , string password = "")
{
    if(idx >= rule.size())
    {
        passwords.emplace_back(password);
        return;
    }
    if(rule[idx] == '#')
    {
        for(int i =0 ;i <words.size() ; i++)
            generatePasswords(words , rule , idx+1 , password + words[i]);
    }
    else
    {
        for(char i ='0' ;i<='9' ; i++)
            generatePasswords(words , rule , idx+1 ,password+i);
    }
    return;
}

void solve() {
    int n , m;
    while(cin>>n)
    {
        vector<string>words(n);
        for(int i=0 ;i <n ;i++)
            cin>>words[i];

        cin>>m;
        vector<string>rules(m);
        for(int i=0 ;i <m ;i++)
            cin>>rules[i];

        for(int i=0 ;i <m ;i++)
        {
            generatePasswords(words , rules[i] , 0);
            cout<<"--"<<endl;
            for(int i =0 ; i<passwords.size();i++)
                cout<<passwords[i]<<endl;
            passwords.clear();
        }
    }

}


int main() {
    katafast

    int t = 1;
//    cin>> t;

    while(t--)
    {
        solve();
    }



    return 0;
}


