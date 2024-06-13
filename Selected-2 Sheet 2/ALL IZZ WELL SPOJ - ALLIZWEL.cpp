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

char matrix[101][101];
int n , m;
bool visited[101][101];
string word = "ALLIZZWELL";
bool ans = 0;

vector<pair<int,int>>moves = {
    {-1 , -1}, {+1 , +1},
    {-1 , +1} , {+1 , -1},
    {+1 , 0} , {-1 , 0},
    {0 , +1} , {0 , -1}
};

void dfs(int index , pair<int,int>node)
{
    if (index == word.length())
        ans = 1;

    visited[node.first][node.second] = 1;

    for(auto u : moves)
    {
        int newX = node.first + u.first;
        int newY = node.second + u.second;

        if(inbound2D(newX , newY , n , m) && !visited[newX][newY] && matrix[newX][newY] == word[index])
        {
            dfs(index+1 , {newX , newY});
            visited[newX][newY] = 0;
        } 
    }
}

void init(){
    memset(visited , 0 , sizeof visited);
}

 
void solve() {
    cin>> n >> m;
    for(int i =0 ; i<n ; i++)
        for(int j =0 ; j < m; j++)
            cin>> matrix[i][j];
    

    for(int i =0 ; i<n ; i++)
    {
        if (ans) break;
        for(int j =0 ; j < m; j++)
        {
            if (ans) break;
            if (matrix[i][j] == 'A')
            {
                init();
                dfs(1 , {i , j});
            }
        }
    }

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    ans = false;
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