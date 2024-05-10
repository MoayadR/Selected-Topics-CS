#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
int const MOD = 1e9+7;


bool inbound2D(int i , int j , int is , int js)
{
    if(i>=0 && i <is && j>=0 && j<js)
        return true;
    return false;
}

bool inbound(int i , int is)
{
    if(i>=0 && i <is)
        return true;
    return false;
}

vector<int>sizes;
vector<int>values;
int DP[2001][2001];

int knapsack(int w , int i)
{
    if (i>=sizes.size() || w < 0)
        return 0;
    
    if(DP[i][w] != -1)
        return DP[i][w];
    
    if(sizes[i] <= w )
        return DP[i][w] = max(knapsack(w-sizes[i] , i+1) + values[i] , knapsack(w , i+1));
    else
        return DP[i][w] = knapsack(w , i+1);
}

void init(){
   memset(DP , -1 , sizeof DP); 
}


void solve() {
    init();

    int s , n;
    cin>> s>> n;

    sizes.resize(n);
    values.resize(n);

    for (int i =0 ; i<n ; i++)
    {
        cin>>sizes[i] >> values[i];
    }

    cout<<knapsack(s , 0)<<endl;
}



int main() {
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}