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
const int N = 1e6+1;
bool prime[N+1];
int primesInterval[N+1];

void SieveOfEratosthenes()
{
    prime[0] = prime[1] = false;
    for (int p = 2; p * p < N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i < N; i += p)
                prime[i] = false;
        }
    }

    primesInterval[0]=0;
    for (int i = 1; i <= N; i++)
    {
        primesInterval[i]=primesInterval[i-1] + prime[i-1];
    }
}

void init(){
    memset(prime, true, sizeof(prime));
}

int a, b, k;
bool valid(int mid){
    for(int i = a ; i<=b-mid+1 ; i++){
        if(primesInterval[i+mid] - primesInterval[i] < k)
            return false;
    }
    return true;
}

void solve() {
    init();
    cin >> a >> b >> k;
    SieveOfEratosthenes();

    int left = 1, right = b - a + 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (valid(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout<<ans <<endl;
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
}
