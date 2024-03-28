#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll twoPtr(vector<pair<ll,ll>>ab , ll d){
    ll value = 0 , maxValue = -1;

    int left= 0 , right = 0;
    while(left <= right)
    {
        if( abs(ab[right].first - ab[left].first) < d)
        {
            if(right >= ab.size() )
                break;

            value += ab[right].second;

            maxValue = max(maxValue , value);

            right++;
        }
        else
        {
            value -= ab[left].second;
            maxValue = max(maxValue , value);
            left++;
        }
    }
    return maxValue;
}

void solve() {
    int n ;
    ll d;
    vector<pair<ll,ll>>ab;
    cin>> n >> d;
    for(int i =0 ;i<n ; i++)
    {
        ll a ,b;
        cin>>a>>b;
        ab.emplace_back(a, b);
    }

    sort(ab.begin() , ab.end());


    cout<<twoPtr(ab , d)<<endl;
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


