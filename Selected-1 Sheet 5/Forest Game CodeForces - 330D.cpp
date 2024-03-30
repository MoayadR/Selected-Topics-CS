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

bool visited [1001][1001];
int r , c;

int bfs( vector<vector<char>>grid , int xs , int ys)
{
    int battles = 0;
    int stepsEnd = 1e6+1;
    queue<pair<int,int>>q;
    queue<int>steps;
    q.emplace(xs , ys);
    steps.push(0);

    while(!q.empty())
    {
        pair<int,int>top = q.front();
        int step = steps.front();
        steps.pop();
        q.pop();

        if(!inbound2D(top.first,top.second , r, c))
            continue;
        if(visited[top.first][top.second] )
            continue;
        if(grid[top.first][top.second] == 'T')
            continue;

        visited[top.first][top.second] = 1;
        if(grid[top.first][top.second] == 'S')
            stepsEnd = step;
        if(isdigit(grid[top.first][top.second]) && step <= stepsEnd)
        {
            battles += (grid[top.first][top.second] - '0');

        }

        q.emplace(top.first+1 , top.second);
        steps.push(step+1);

        q.emplace(top.first-1 , top.second);
        steps.push(step+1);

        q.emplace(top.first , top.second-1);
        steps.push(step+1);

        q.emplace(top.first , top.second+1);
        steps.push(step+1);
    }
    return battles;
}

void solve(int t) {
    memset(visited , 0 , sizeof visited);
    cin>> r >>c;
    vector<vector<char>>grid(r,vector<char>(c));

    int xs , ys ;
    for(int i =0 ;i <r ; i++)
    {
        for(int j = 0 ; j<c ; j++)
        {
            cin>> grid[i][j];
            if(grid[i][j] == 'E')
            {xs= i ; ys = j;}
        }
    }

    cout<<bfs(grid , xs , ys);
}



int main() {
    katafast
    int t =1;
//    cin>> t;
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


