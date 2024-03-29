#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int n ,  m;
vector<string>ans ;
const string& possible = "IEHOVA#";
void mazeSolver(const vector<vector<char>>&grid , int i , int j ,int p=0, vector<string>moves = {}) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    if (grid[i][j] == '#')
    {
        ans = moves;
        return ;
    }

    if (i - 1 >= 0 && grid[i - 1][j] == possible[p]) {
        moves.emplace_back("forth");
        return mazeSolver(grid, i-1, j, p + 1, moves);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == possible[p])
    {
        moves.emplace_back("left");
        return mazeSolver(grid, i, j-1, p + 1, moves);
    }
    if (j + 1 <m && grid[i][j + 1] == possible[p])
    {
        moves.emplace_back("right");
        return mazeSolver(grid, i, j+1, p + 1, moves);
    }

    return;
}


void solve() {
    cin>> n >> m ;
    vector<vector<char>>grid(n , vector<char>(m));
    int startx , starty;
    for(int i =0 ; i<n ; i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == '@')
            {
                startx = i;
                starty=j;
            }
        }
    }
    mazeSolver(grid , startx , starty);
    for(int i =0 ; i<ans.size()-1 ; i++)
        cout<<ans[i]<<' ';
    cout<<ans[ans.size()-1]<<endl;
}


int main() {
    katafast

    int t = 1;
    cin>> t;

    while(t--)
    {
        solve();
    }

    return 0;
}


