#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool status[5] = {false , false, false , false , false};
bool possible(vector<int>a , int sum)
{
    if(status[0] && status[1] && status[2] && status[3] && status[4])
    {
        if(sum == 23)
            return true;
        return false;
    }

    for(int i =0 ;i<a.size() ;i++)
    {
        if(!status[i])
        {
            status[i] = true;
            if(possible(a , sum + a[i]))
                return true;
            if(possible(a , sum - a[i]))
                return true;
            if(possible(a , sum * a[i]))
                return true;
            status[i] = false;
        }
    }

    return false;
}


void solve() {
    vector<int>a(5);
    while(true)
    {
        for(int i =0 ;i <5; i++)
            cin>>a[i];

        if(!a[0] && !a[1] && !a[2] && !a[3] && !a[4])
            break;

        bool code = false;
        for(int i =0 ;i <5 ;i ++)
        {
            if(!status[i])
            {
                status[i] = true;
                if(possible(a , a[i]))
                {cout<<"Possible"<<endl;code = true;break;}
                status[i] = false;
            }
        }

        if(!code)
            cout<<"Impossible"<<endl;

        for(int i =0; i <5 ;i++)
            status[i] = false;
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


