#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int convert(ll n)
{
    int bitmask=0;
    int digit;
    while(n)
    {
        digit = n%10;
        n/=10;
        bitmask |= (1 << (digit));
    }
    return bitmask;
}

int main() {
    katafast

    int n ;
    cin>> n;
    vector<ll>nums;
    unordered_map<int , int>freq;
    ll num;
    for(int i =0 ; i<n  ;i++)
    {
        cin>> num;
        nums.push_back(num);
        freq[convert(num)]++;
    }

    ll count = 0;
    for (int i = 1; i < (1 << 10); i++) {
        count += (ll)(freq[i] * (freq[i] - 1) / 2);
        for (int j = i + 1; j < (1 << 10); j++) {
            if((i & j)){
                count += (ll)(freq[i] * freq[j]);
            }
        }
    }
    cout<<count<<endl;

    return 0;
}


