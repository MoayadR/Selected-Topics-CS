#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


// vector<pair<int,int>>moves = {
//     {-1 , -1}, {+1 , +1},
//     {-1 , +1} , {+1 , -1},
//     {+1 , 0} , {-1 , 0},
//     {0 , +1} , {0 , -1}
// };
 
// bool inbound2D(int i , int j , int is , int js)
// {
//     if(i>=0 && i <is && j>=0 && j<js)
//         return true;
//     return false;
// }
 
// bool inbound(int i , int is)
// {
//     if(i>=0 && i <is)
//         return true;
//     return false;
// }

const int N = 1e7;
int divs[(int)N+10];
int primes[(int)N+10];
void seive(){
   for (int i = 1; i <= N; i++) 
   {
        for (int j = i; j <= N; j+=i) 
        {
            primes[j] +=i;
        }

        if( primes[i] <= N)
            if(divs[primes[i]] == 0)
                divs[primes[i]] = i;
   }
}

void init(){
}

void solve() {
    int c;
    cin>> c;
    if (divs[c] == 0)
        cout << -1 << endl;
    else
        cout << divs[c] << endl; 
}


int main()
{
    katafast
    seive();
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
}
