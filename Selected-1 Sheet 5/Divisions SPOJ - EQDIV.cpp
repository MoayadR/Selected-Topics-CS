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

bool visited[101][101];
int grid[101][101];
int n ;
int cnt;

void dfs(int i , int j , int clusterType)
{
    stack<pair<int , int>>stk;
    stk.emplace(i , j);
    cnt = 0;

    while(!stk.empty())
    {
        pair<int,int> top = stk.top();
        stk.pop();

        if(!inbound2D(top.first ,top.second ,n , n))
            continue;
        if(visited[top.first][top.second] || grid[top.first][top.second] != clusterType)
            continue;

        visited[top.first][top.second] =1;
        cnt++;

        stk.emplace(top.first-1 , top.second);
        stk.emplace(top.first+1 , top.second);
        stk.emplace(top.first , top.second-1);
        stk.emplace(top.first , top.second+1);
    }
}


void solve(int t) {
    while(cin>> n && n != 0)
    {
        cin.ignore();
        memset(visited , 0 , sizeof visited);
        memset(grid , 0 , sizeof grid);

        int sets = 0;

        for(int i=1;i<n;i++)
        {
            string temp;
            getline(cin,temp);
            stringstream ss(temp);
            int x, y;
            while(ss>>x>>y)
            {
                grid[x-1][y-1] = i;
            }
        }

        bool status = 0;
        for(int i =0 ;i<n && !status ; i++)
        {
            for(int j = 0 ; j<n && !status ; j++)
            {
                if(!visited[i][j])
                {
                    dfs(i ,j , grid[i][j]);
                    sets++;
                    if(sets > n || cnt != n )
                    {
                        status = 1;
                    }
                }
            }
        }

        if(status)
            cout<<"wrong"<<endl;
        else
            cout<<"good"<<endl;

    }
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


