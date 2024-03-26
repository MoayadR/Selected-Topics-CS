#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

int main() {
    fast
    int r ,n ;
    vector<pair<int,int>> enemy;
    cin>>r >> n ;
    for(int i=0; i <n ; i++)
    {
        int temp1 , temp2;
        cin>> temp1 >> temp2;
        enemy.emplace_back(temp1 , temp2);
    }
    sort(enemy.begin() , enemy.end());
    for(auto & it : enemy)
    {
        if(it.first < r)
        {
            r += it.second;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<< "YES"<<endl;
    return 0;
}
