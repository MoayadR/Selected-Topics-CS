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

int n , m;
char matrix[183][183];
int res[183][183];
bool visited[183][183];

void bfs(queue<pair<int,int>>q) {

    while(!q.empty())
    {
        auto top = q.front();
        q.pop();


        if(inbound2D(top.first-1 , top.second , n , m) &&!visited[top.first-1][top.second])
        {
            q.emplace(top.first-1 , top.second);
            res[top.first-1][top.second] = res[top.first][top.second] +1;
            visited[top.first-1][top.second] = 1;
        }
 
        if(inbound2D(top.first+1 , top.second , n , m) &&!visited[top.first+1][top.second])
        {
            q.emplace(top.first+1 , top.second);
            res[top.first+1][top.second] = res[top.first][top.second] +1;
            visited[top.first+1][top.second] = 1;
        }
 
        if(inbound2D(top.first , top.second-1 , n , m) &&!visited[top.first][top.second-1])
        {
            q.emplace(top.first , top.second-1);
            res[top.first][top.second-1] = res[top.first][top.second] +1;
            visited[top.first][top.second-1] = 1;
        }
 
        if(inbound2D(top.first , top.second+1 , n , m) &&!visited[top.first][top.second+1])
        {
            q.emplace(top.first , top.second+1);
            res[top.first][top.second+1] = res[top.first][top.second] +1;
            visited[top.first][top.second+1] = 1;
        }
        
    }
    return;
}

void init(){
    memset(matrix , '0' , sizeof matrix);
    memset(res , 0 , sizeof res);
    memset(visited , 0 , sizeof visited);
}

void solve() {
    init();
    cin>>n >> m;

    queue<pair<int,int>>ones;

    for(int i =0 ;i<n; i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j] == '1')
            {
                ones.emplace(i , j);
                visited[i][j] = 1;
            }
        }
    }

    bfs(ones);

    for(int i =0 ;i<n;i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            cout<<res[i][j]<< ' ';
        }
        cout<<endl;
    }
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