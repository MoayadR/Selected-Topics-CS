#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ;
    string s;
    map<string , int> names;

    cin>>n ;
    for(int i =0 ; i<n ; i++)
    {
        cin>> s;
        if(names[s] == 0)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<s<<names[s]<<endl;
        }
        names[s]++;
    }
    return 0;
}