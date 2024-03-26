#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

int main() {
    fast

    string s ;
    set<int> st;

    getline(cin , s);

    for(int i =0 ; i<s.size() ; i++)
    {
        if(isalpha(s[i]))
        {
            st.insert(s[i]);
        }
    }
    cout<<st.size();
}

