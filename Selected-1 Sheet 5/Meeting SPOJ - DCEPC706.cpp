#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

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

char grid[205][205];
bool visA[205][205];
bool visB[205][205];
bool visC[205][205];

int distA[205][205];
int distB[205][205];
int distC[205][205];

int n , m;

void bfs(pair<int,int>p , bool vis[][205] ,int dist[][205])
{
    queue<pair<int,int>>q;
    q.push(p);
    dist[p.first][p.second] = 0;
    while(!q.empty())
    {
        pair<int , int >top = q.front();
        q.pop();

        if(!inbound2D(top.first , top.second , n , m))
            continue;

        if(vis[top.first][top.second])
            continue;

        if(grid[top.first][top.second] == '#')
        {
            dist[top.first][top.second] = 1e5+1;
            continue;
        }

        vis[top.first][top.second] = 1;

        q.emplace(top.first+1 , top.second);
        if(inbound2D(top.first+1 , top.second , n , m) && !vis[top.first+1][top.second] && grid[top.first+1][top.second] != '#')
            dist[top.first+1][top.second] = dist[top.first][top.second] + 1 ;

        q.emplace(top.first-1 , top.second);
        if(inbound2D(top.first-1 , top.second , n , m) && !vis[top.first-1][top.second] && grid[top.first-1][top.second] != '#')
            dist[top.first-1][top.second] = dist[top.first][top.second] + 1 ;

        q.emplace(top.first , top.second+1);
        if(inbound2D(top.first , top.second+1 , n , m)&& !vis[top.first][top.second+1] && grid[top.first][top.second+1] != '#')
            dist[top.first][top.second+1] = dist[top.first][top.second] + 1 ;

        q.emplace(top.first , top.second-1);
        if(inbound2D(top.first , top.second-1 , n , m) && !vis[top.first][top.second-1] && grid[top.first][top.second-1] != '#')
            dist[top.first][top.second-1] = dist[top.first][top.second] + 1 ;

    }
}



void solve(int t) {
    cin>> n>> m;
    n+=2;m+=2;
    memset(grid , '.' , sizeof grid);

    pair<int,int>a;
    pair<int,int>b;
    pair<int,int>c;

    for(int i =1 ;i<n-1 ; i++)
    {
        for(int j =1 ; j<m-1; j++)
        {
            cin>> grid[i][j];
            if(grid[i][j] == '1')
            {a.first = i ; a.second = j;}
            if(grid[i][j] == '2')
            {b.first = i ; b.second = j;}
            if(grid[i][j] == '3')
            {c.first = i ; c.second = j;}
        }
    }


    memset(visA , 0 , sizeof visA);
    memset(visB , 0 , sizeof visB);
    memset(visC , 0 , sizeof visC);

    memset(distA , 10000 , sizeof distA);
    memset(distB , 10000 , sizeof distB);
    memset(distC , 10000 , sizeof distC);

    bfs(a , visA , distA);
    bfs(b , visB , distB);
    bfs(c,visC , distC);

    int best = 1e5+1;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int maxe = max(distA[i][j] , max(distC[i][j] , distB[i][j] ));
            if(maxe <= best)
            {
                best = maxe;
            }
        }
    }


    cout<<best<<'\n';

}


int main() {
    katafast
    int t =1;
    cin>> t;
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


