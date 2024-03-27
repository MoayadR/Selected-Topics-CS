#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int bs(const vector<int>&leaked , int value)
{
    int st = 0;
    int end = leaked.size() - 1;
    while(st <= end) {
        int mid = (st + end) / 2;
        if (leaked[mid] <= value) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return st;
}



int main() {
    katafast
    int t ;
    cin>> t;

    while(t--)
    {
        int n ;
        cin>> n;
        vector<int>leaked;
        vector<int>notLeaked;
        for(int i =0 ; i<n ; i++)
        {
            int d;
            bool s;
            char r;
            cin>> d>>s >> r;
            if(s == 1)
            {
                if (r== 'c')
                    leaked.push_back(d);
            }
            else
            {
                if (r == 'i')
                    notLeaked.push_back(d);
            }
        }

        sort(leaked.begin() , leaked.end());
        sort(notLeaked.begin() , notLeaked.end());

        int count = 0;
        for(int i = 0 ; i< notLeaked.size() ;i++)
        {
            count += (leaked.size() - bs(leaked , notLeaked[i]));
        }

        cout<<count<<endl;
    }
    return 0;
}