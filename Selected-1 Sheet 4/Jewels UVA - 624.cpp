#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int cap = 0;
int size = 0;
vector<int> res;
int knapsack(int w , vector<int>jw , int sz , vector<int>bag = {} , int currentCap = 0){
    if (w == 0 || sz == 0)
    {
        if(cap < currentCap || (cap<=currentCap && bag.size() > size))
        {
            cap = currentCap;
            res = bag;
        }
        return 0;
    }
    if(jw[sz-1] > w)
        return knapsack(w , jw , sz-1 , bag  , currentCap);
    else
    {
        vector<int>newBag = bag;
        bag.push_back(jw[sz-1]);
        return max( jw[sz-1] + knapsack(w-jw[sz-1] , jw , sz-1 , bag , currentCap +jw[sz-1] )
                    , knapsack(w , jw , sz-1 , newBag , currentCap ));
    }
}

void solve() {
    int n ,m;
    while(cin>> n>>m)
    {
        vector<int>jw(m);
        for(int i =0 ; i<m ; i++)
            cin>> jw[i];

        int sum = knapsack(n , jw , m);
        for(int i =res.size()-1 ; i>=0 ; i--)
            cout<<res[i] << ' ';
        cout<<"sum:"<<sum<<endl;
        res.clear();
        cap = 0;
        size = 0;
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


