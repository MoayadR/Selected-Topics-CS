#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll diff(ll a , ll b)
{
    return abs( b-a);
}
void solve(){
    int n , m ;
    cin>>n>>m;
    vector<ll>h(n);
    vector<ll>s(m);
    for(int i =0 ; i<n ; i++)
        cin>> h[i];
    for(int j =0; j<m ; j++)
        cin>> s[j];
    
    int ptrHouse=0 , ptrStation = 0;
    ll r= 0;
    while(ptrHouse < n && ptrStation < m)
    {
        if(ptrStation+1 < m && diff(h[ptrHouse] , s[ptrStation]) < diff(h[ptrHouse] , s[ptrStation+1]))
        {
            r = max(r , diff(h[ptrHouse] , s[ptrStation]));
            ptrHouse++;
        }
        else if(ptrStation == m -1)
        {
            r = max(r , diff(h[ptrHouse] , s[ptrStation]));
            ptrHouse++;
        }
        else
        {
            ptrStation++;
        }
    }
    cout<<r<<endl;
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


