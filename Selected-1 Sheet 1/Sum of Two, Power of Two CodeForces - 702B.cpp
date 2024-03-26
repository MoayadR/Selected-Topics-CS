#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

vector<ll>diff(vector<ll>powers , ll num)
{
    for(int i =0 ;i<powers.size() ; i++)
    {
        powers[i] -= num;
    }
    return powers;
}

int main() {
    katafast

    vector<ll>powers;
    for(int i =1 ; i<=32 ; i++)
        powers.push_back(pow(2,i));

    int n ;
    cin>> n;
    unordered_map<ll , ll>freq;
    for(int i =0 ; i<n ; i++)
    {
        ll temp;
        cin>> temp;
        freq[temp]++;
    }

    ll count = 0;
    for(auto &it :freq)
    {
        vector<ll>D = diff(powers , it.first);
        while(it.second)
        {
            for(int i =0 ; i<D.size() ; i++)
            {
                if(D[i] <0)
                    continue;

                if(D[i] == it.first) // same element
                {
                    if(it.second > 1)
                        count+= (it.second - 1);
                }
                else if(freq.find(D[i])!= freq.end() && freq[D[i]])
                {
                    count += freq[D[i]];
                }
            }
            it.second--;
        }
    }

    cout<<count<<endl;

    return 0;
}
