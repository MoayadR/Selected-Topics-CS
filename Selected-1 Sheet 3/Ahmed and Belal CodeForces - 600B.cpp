#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n  , m;
    cin>> n >> m;
    vector<int> a , b;

    for(int i =0 ; i<n ; i++)
    {
        int temp ;
        cin>> temp;
        a.push_back(temp);
    }
    for(int i =0 ; i<m ; i++)
    {
        int temp ;
        cin>> temp;
        b.push_back(temp);
    }

    sort(a.begin() , a.end());


    for (int i = 0; i < m; ++i) {
        int count = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << count << " ";
    }

    return 0;
}
