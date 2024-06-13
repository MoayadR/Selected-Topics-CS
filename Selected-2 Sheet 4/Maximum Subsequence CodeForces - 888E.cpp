#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


 vector<pair<int,int>>moves = {
     {-1 , -1}, {+1 , +1},
     {-1 , +1} , {+1 , -1},
     {+1 , 0} , {-1 , 0},
     {0 , +1} , {0 , -1}
 };

 bool inbound2D(int i , int j , int is , int js)
 {
     if(i>=0 && i <is && j>=0 && j<js)
         return true;
     return false;
 }

 bool inbound(int i , int is) {
     if (i >= 0 && i < is)
         return true;
     return false;
 }

const int MAX_1=40;
const int MAX_2=1010000;

int n,m,sequence[MAX_1];
int n1,n2,nums_1[MAX_2],nums_2[MAX_2];

void init(){
}
void solve() {
    cin>> n >> m;
    for (int i=1;i<=n;i++)
        cin>> sequence[i];

    int mid=n/2;

    for (int j=0; j < (1 << mid); j++){
        int total=0;
        for (int i=0;i<mid;i++)
            if (j & (1 << i))
                total= (total + sequence[i + 1]) % m;
        nums_1[++n1]=total;
    }

    for (int j=0; j < (1 << (n - mid)); j++){
        int total=0;
        for (int i=0;i<n-mid;i++)
            if (j & (1 << i))
                total= (total + sequence[i + mid + 1]) % m;
        nums_2[++n2]=total;
    }

    sort(&nums_1[1], &nums_1[n1 + 1]);
    n1= unique(&nums_1[1], &nums_1[n1 + 1]) - nums_1 - 1;

    sort(&nums_2[1], &nums_2[n2 + 1]);
    n2= unique(&nums_2[1], &nums_2[n2 + 1]) - nums_2 - 1;

    int mx=max(nums_1[n1], nums_2[n2]);

    for (int i=1;i<=n1;i++){
        int res= lower_bound(&nums_2[1], &nums_2[n2 + 1], m - 1 - nums_1[i]) - nums_2;

        if (nums_2[res] > m - 1 - nums_1[i])
            res--;
        mx=max(mx, nums_1[i] + nums_2[res]);
        mx=max(mx, (nums_1[i] + nums_2[n2]) % m);
    }

    cout<< mx<<endl;
}


int main()
{
    katafast
    int t =1;
//    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}
