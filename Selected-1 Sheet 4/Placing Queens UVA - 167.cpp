#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

vector<vector<char>>board(8 , vector<char>(8 , ' '));
int maxValue = 0;
bool valid(int row , int column){
    for(int i = 0 ; i<row ; i++)
        if(board[i][column] == 'Q')
            return false;
    for(int i=row-1 , j =column+1 ; i>=0 && j<8;i--,j++)
        if(board[i][j] == 'Q')
            return false;
    for(int i=row-1 , j =column-1 ; i>=0 && j>=0;i--,j--)
        if(board[i][j] == 'Q')
            return false;
    return true;
}

void evalGrid(const vector<vector<int>>&grid)
{
    int res = 0;
    for(int i =0 ; i<8 ; i++)
    {
        for(int j = 0 ; j<8 ; j++) {
            if (board[i][j] == 'Q')
                res+=grid[i][j];
        }
    }
    maxValue = max(maxValue , res);
}

void placeQueens(int row , const vector<vector<int>>&grid)
{
    if(row == 8)
    {
        evalGrid(grid);
    }
    else
    {
        for(int i =0 ; i<8 ; i++)
        {
            if(valid(row , i))
            {
                board[row][i] = 'Q';
                placeQueens(row+1 , grid);
                board[row][i] = ' ';
            }
        }
    }
}

void solve() {
  vector<vector<int>>grid(8 , vector<int>(8));
  for(int i =0 ; i<8 ; i++)
  {
      for(int j = 0 ;j<8 ; j++)
          cin>>grid[i][j];
  }

    placeQueens(0 , grid);
    std::stringstream ss;
    ss << maxValue;
    std::string str = ss.str();
    if(str.size() == 5)
        cout<<str<<endl;
    else{
        for(int i =0 ;i<5-str.size(); i++)
            cout<<' ';
        cout<<str<<endl;
    }
    maxValue = 0;

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


