#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

double valid(double mid , vector<double>a , double k)
{
    double storage = 0.0;
    for(int i =0 ; i<a.size() ; i++)
    {
        if(a[i] < mid)
        {
            double needed = mid - a[i];
            storage -= needed;
            a[i] += needed;
        }
        else
        {
            double gain = a[i] - mid;
            a[i] -= gain;
            storage += (gain - (double)(gain*k)/100);
        }
    }
    if(storage >= -1e-6 && storage <= -1.22045e-18)
        return 0;
    return storage;
}


void solve() {
    int n ;double k;
    cin>> n>> k;
    vector<double>a(n);
    for(int i =0 ; i<n ; i++)
        cin>> a[i];

    sort(a.rbegin() , a.rend());

    double left =a[a.size()-1] , right = a[0];
    double ans = 0;
    while(left <= right)
    {
        double mid = (double)left + (double)(right-left)/2;
        double change = valid(mid, a, k);
        if (change >= 0)
        {
            left = min(mid , left + (change - (double)(change*k)/100));
            ans = mid;
            if (change == 0 )
                break;
        }
        else{
            right = max(mid , right + (change - (double)(change*k)/100));
        }


    }

    std::cout << std::setprecision(9) << ans << std::endl;

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


