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

int n , k;
int DP[1001][101];
int values[(int)1e6+1];
int knapsack(int w , int i ){
    if (i>=n || w < 0)
        return 0;
    
    if (DP[w][i] != -1)
        return DP[w][i];
    
    if (values[i] <= w)
        return DP[w][i] = max(knapsack(w-values[i] , i+1) + values[i] , knapsack(w , i+1));
    
    return DP[w][i] = knapsack(w , i+1);
}

void init(){
 memset(DP , -1 , sizeof DP);
 memset(values , 0 , sizeof values);
}

void solve() {
    init();
    cin>> n >> k;

    for (int i =0 ; i<n ; i++)
    {
        int x , sum = 0;
        cin>> x;
        for(int j =0 ; j<x ; j++)
        {
            int temp ;
            cin>> temp;
            sum += temp;
        }
        values[i] = sum;
    }

   cout<<knapsack(k , 0)<<endl; 

}



int main() {
    katafast
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}