#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll ans = -1;
bool status = 0;
void Y2k(int s , int d , int sum = 0 , vector<int>month={} , int i=0)
{
    if(i == 12)
    {
        ans = 0;
        for(int i =0 ; i<12 ; i++)
            ans += month[i];
        status = 1;
        return;
    }
    else
    {
        if(i > 4)
            sum -= month[i-5];
        if(i<4 || sum + s < 0)
        {
            month.push_back(s);
            Y2k(s , d , sum+s , month , i+1);
            if(status)
                return;
            month.pop_back();
        }
        if(i<4 || sum -d<0)
        {
            month.push_back(-d);
            Y2k(s , d , sum-d , month , i+1);
            if(status)
                return;
            month.pop_back();
        }
    }
}

void solve() {
    int s , d;
    while(cin>>s >> d)
    {
        Y2k(s , d);
        if(ans <0)
            cout<<"Deficit"<<endl;
        else
            cout<<ans<<endl;

        ans = -1;
        status = 0;
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


