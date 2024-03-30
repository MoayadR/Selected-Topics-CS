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

vector<vector<bool>>visited;
void dfs(vector<vector<char>>grid , int i , int j)
{
    stack<pair<int,int>>stk;
    stk.emplace(i , j);

    while(!stk.empty())
    {
        pair<int,int>pr = stk.top();
        stk.pop();
        if(!inbound2D(pr.first , pr.second , grid.size() , grid[0].size()))
            continue;

        if(grid[pr.first][pr.second] == '1' && !visited[pr.first][pr.second])
        {
            visited[pr.first][pr.second] = 1;

            stk.emplace(pr.first-1 ,pr.second ); // up
            stk.emplace(pr.first+1 ,pr.second ); // down
            stk.emplace(pr.first ,pr.second+1 ); // right
            stk.emplace(pr.first ,pr.second-1 ); // left

            stk.emplace(pr.first-1 ,pr.second-1 ); // up left
            stk.emplace(pr.first-1 ,pr.second+1 ); // up right
            stk.emplace(pr.first+1 ,pr.second-1 ); // down left
            stk.emplace(pr.first+1 ,pr.second+1 ); // down right
        }
    }
}

void solve(int t) {
    int n;
    int count = 1;
    while(cin>>n) {
        int res = 0;
        visited.clear();
        visited.resize(n, vector<bool>(n, 0));
        vector<vector<char>> grid(n, vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            for(int j =0 ;j<n ; j++)
            {
                cin>>grid[i][j];
            }
        }

        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ;j<n ; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(grid , i , j);
                    res++;
                }
            }
        }

        cout<<"Image number "<<count++<<" contains "<<res<<" war eagles."<<endl;
        res= 0;
    }
}



int main() {
    katafast
    int t =1;
//    cin>> t;
//    cin.ignore();
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


