#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define MOD (ll)1000000007

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

vector<int> primeNums;
vector<bool>primes(1e4+1 , 1);

void seievePrimes(){
    primes[0] = false;
    primes[1] = false;

    for (int i = 2 ; i * i <1200 ; i++)
    {
        if (primes[i])
        {
            for (int j = i * i ; j < 1200 ; j+= i)
                primes[j]=false;
        }
    }
    for(int i =2 ; i<1200 ; i++)
    {
        if(primes[i])
            primeNums.push_back(i);
    }
}
int n ;
int k;
int dp[200][1121][15];
int dpSolve(int i ,int sum , int step ){
    if(sum == n && step == k)
        return 1;
    else if(step == k)
        return 0;
    if(primeNums[i] > n || sum > n)
        return 0;

    if(dp[i][sum][step] != -1)
        return dp[i][sum][step];

    int op1 = dpSolve( i+1, sum + primeNums[i] , step+1);
    int op2 = dpSolve(i+1 , sum , step);
    return dp[i][sum][step] = op1 + op2;
}

void solve(int t) {
    while(cin>> n>> k && n!=0 && k !=0)
    {
        memset(dp , -1 , sizeof dp);
        cout<<dpSolve(0 , 0 , 0)<<'\n';
    }
}


int main() {
    katafast
    int t =1;
//    cin>> t;
    seievePrimes();
    for(int i =1 ; i<=t ; i++)
    {
        solve(t);
    }

    return 0;
}

