#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

void solve() {
    short n , p;
    cin>> n >> p;
    p--;

    vector<short>cities(n);
    for(int i =0 ; i< n ;i++)
    {
        cin>>cities[i];
    }


    short left =p-1 , right = p+1 , count =0;
    if(cities[p] == 1)
        count++;

    while(left>=0 || right < n)
    {
        if(left < 0 && right<n)
        {
            if(cities[right] == 1)
            {
                count++;
            }
            right++;
        }
        else if(right >= n && left>=0)
        {
            if(cities[left] == 1)
            {
                count++;
            }
            left--;
        }
        else
        {
            if(cities[left] ==1 && cities[right]){
                count+=2;
            }
            left--;
            right++;
        }
    }
    cout<<count<<endl;
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


