#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

unordered_map<ll , ll>m;

vector<vector<ll>>valid(ll k)
{
    vector<vector<ll>>res;
    vector<ll>nums;
    for(auto &it : m)
    {
        ll tempsecond = min(k , it.second);
        while(tempsecond)
        {
            nums.push_back(it.first);
            tempsecond--;
        }
    }
    sort(nums.begin() , nums.end());
    for(int i =0 ; i<nums.size() ; i++)
    {
        vector<ll>temp(3);
        if(res.size() < k && k+i < nums.size() && 2*k+i < nums.size())
        {
            temp[0] = nums[i];
            temp[1] = nums[k+i];
            temp[2] = nums[2*k+i];
            sort(temp.rbegin() , temp.rend());
            res.push_back(temp);
        }
    }

    return res;
}

void solve() {
    int n;
    cin>> n;
    for(int i =0 ; i<n ; i++)
    {
        ll temp ;
        cin>> temp;
        m[temp]++;
    }

    vector<vector<ll>>res;
    ll left =0 , right = n/3 +1;
    while(left <= right)
    {
        ll mid = left + (right-left)/2;
        auto temp = valid(mid);
        if(temp.size()>=mid)
        {
            if(res.size() < temp.size())
                res= temp;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    cout<<res.size()<<endl;
    for(int i =0 ; i<res.size() ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
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


