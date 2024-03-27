#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

vector<ll> getDivisors(ll n){
    vector<ll> divs;
    for(ll i =2 ; i*i <= n ; i++)
    {
        if(n%i == 0)
        {
            divs.push_back(i);
            if(i!= n/i)
                divs.push_back(n/i);
        }
    }
    return divs;
}

int main() {
    katafast
    ll t;
    ll n ;
    cin>> t;
    while(t--)
    {
        cin>> n;
        vector<ll>divs(n);
        for(ll i =0 ; i<n ; i++)
            cin>>divs[i];

        sort(divs.begin() , divs.end());

        ll left = 0 , right = divs.size()-1;
        ll mul = divs[left] * divs[right];

        vector<ll> mulDivs = getDivisors(mul);
        sort(mulDivs.begin() , mulDivs.end());

        if(mulDivs.size() != divs.size())
        {
            mul = -1;
            cout<<mul<<endl;
            continue;
        }

        for(int i =0 ; i<n ; i++)
            if(mulDivs[i] != divs[i])
                mul = -1;

        cout<<mul<<endl;
    }

    return 0;
}
