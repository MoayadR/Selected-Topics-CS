#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

int main() {
    fast
    int n ;
    cin>> n ;

    vector<int> customer(n);

    for(int i =0 ; i<n ; i++)
    {
        cin>>customer[i];
    }

    sort(customer.begin() , customer.end());

    int cnt = 0 , sum=0;

    for (int i =0 ; i<n ;i++)
    {
        if(sum <= customer[i])
        {
            sum+= customer[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
