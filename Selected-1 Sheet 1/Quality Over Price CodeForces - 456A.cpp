#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ;
    cin>> n;
    vector<pair<int,int>> arr;
    for(int i=0 ; i< n ;i++)
    {
        int p , q;
        cin>> p >> q;
        arr.push_back(make_pair(p ,q));
    }

    sort(arr.begin() , arr.end());

    int qMax = 0;
    for(int i =0 ; i<n ; i++)
    {
        if(arr[i].second > qMax)
            qMax = arr[i].second;
        else
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<< "Poor Alex"<<endl;
    return 0;
}