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
int dfs(vector<string>grid , int i , int j)
{
    int res = 0;
    stack<pair<int,int>>stk;
    stk.emplace(i , j);

    while(!stk.empty())
    {
        pair<int,int>pr = stk.top();
        stk.pop();
        if(!inbound2D(pr.first , pr.second , grid.size() , grid[0].size()))
            continue;

        if(grid[pr.first][pr.second] == '0' && !visited[pr.first][pr.second])
        {
            visited[pr.first][pr.second] = 1;
            res++;

            stk.emplace(pr.first-1 ,pr.second ); // up
            stk.emplace(pr.first+1 ,pr.second ); // down
            stk.emplace(pr.first ,pr.second+1 ); // right
            stk.emplace(pr.first ,pr.second-1 ); // left

//            stk.emplace(pr.first-1 ,pr.second-1 ); // up left
//            stk.emplace(pr.first-1 ,pr.second+1 ); // up right
//            stk.emplace(pr.first+1 ,pr.second-1 ); // down left
//            stk.emplace(pr.first+1 ,pr.second+1 ); // down right
        }
    }
    return res;
}

void solve(int t) {
    int i , j;
    cin>> i >> j;
    cin.ignore();

    string temp ;
    vector<string>grid;
    while(getline(cin, temp) && !temp.empty())
    {
        grid.push_back(temp);
    }
    visited.clear();
    visited.resize(100 , vector<bool>(100, 0));

    cout<<dfs(grid , i-1 , j-1)<<'\n';
    if(t != 1)
    {
        cout<<'\n';
    }
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


