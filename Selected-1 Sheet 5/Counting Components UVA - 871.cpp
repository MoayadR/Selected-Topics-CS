#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool inbound(vector<string>grid,  int i , int j)
{
    if(i>=0 && i <grid.size() && j>=0 && j<grid[i].size())
        return true;
    return false;
}

bool status [26][26];

int dfs(vector<string>grid , int i , int j )
{
    int res = 0;
    stack<pair<int,int>>stack;
    stack.emplace(i , j);
    while(!stack.empty())
    {
        pair<int , int>it = stack.top();
        stack.pop();

        if(!inbound(grid , it.first , it.second))
            continue;

        if(grid[it.first][it.second] == '1' && !status[it.first][it.second])
        {
            res++;

            status[it.first][it.second] = 1;

            stack.emplace(it.first-1 ,it.second ); // up
            stack.emplace(it.first+1 ,it.second ); // down
            stack.emplace(it.first ,it.second+1 ); // right
            stack.emplace(it.first ,it.second-1 ); // left

            stack.emplace(it.first-1 ,it.second-1 ); // up left
            stack.emplace(it.first-1 ,it.second+1 ); // up right
            stack.emplace(it.first+1 ,it.second-1 ); // down left
            stack.emplace(it.first+1 ,it.second+1 ); // down right
        }
    }
    return res;
}

void solve(int t) {
    vector<string>grid;
    memset(status, false, sizeof status);
    int best = 0;
    string temp ;

    while(getline(cin , temp) && !temp.empty())
    {
        grid.push_back(temp);
    }

    for(int i =0 ; i< grid.size(); i++)
    {
        for(int j = 0 ; j<grid[i].size() ;j++)
        {
            if(grid[i][j] == '1' && !status[i][j])
                best = max(best , dfs(grid,  i , j ));
        }
    }

    if(t != 1)
    {
        cout<<best<<'\n';
        cout<<'\n';
    }
    else
        cout<<best<<'\n';

}



int main() {
    katafast

    int t = 1;
    cin>> t;
    cin.ignore();
    string s ;
    getline(cin , s);
    while(t)
    {
        solve(t);
        t--;
    }



    return 0;
}


