#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e6
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

char matrix[51][51];
int n , m;
int maxPath = 0;

vector<pair<int,int>>moves = {
    {-1 , -1}, {+1 , +1},
    {-1 , +1} , {+1 , -1},
    {+1 , 0} , {-1 , 0},
    {0 , +1} , {0 , -1}
};

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int DP[30][51][51];

void dfs(int index , pair<int,int> node , int pathLen = 1){

    if (DP[index][node.first][node.second] != -1)
    {
        maxPath = max(maxPath , DP[index][node.first][node.second]);
        return;
    }

    for( auto u : moves)
    {
        int newX = node.first + u.first;
        int newY = node.second + u.second;

        if (inbound2D(newX , newY,n , m) && matrix[newX][newY] == alpha[index])
        {
            dfs(index+1 , {newX , newY} , pathLen+1);
        }
    }

    maxPath = max(maxPath , pathLen);
    DP[index][node.first][node.second] = maxPath;
}

void init(){
    memset(DP , -1 , sizeof DP);
}

 
void solve() {
    int count = 1;
    while(cin>> n >> m && n != 0 && m != 0)
    {
        init();
        maxPath = 0;
        for(int i = 0 ; i<n ; i++)
            for(int j =0  ; j<m ; j++)
                cin>> matrix[i][j];


        for(int i = 0 ; i<n ; i++)
            for(int j =0  ; j<m ; j++)
                if(matrix[i][j] == 'A')
                    dfs(1 , {i , j});

        printf("Case %d: %d\n" , count , maxPath);
        count++;
    }
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