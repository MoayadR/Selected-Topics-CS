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

int comb[8][3] = {{0, 1, 2},{3, 4, 5},{6, 7, 8},{0, 3, 6},{1, 4, 7},{2, 5, 8},{0, 4, 8},{2, 4, 6}};

char board[9];
 
void init(){
    
}

bool win(char symbol)
{
    for (int i =0 ; i<8 ; i++)
    {
        int index1 = comb[i][0];
        int index2 = comb[i][1];
        int index3 = comb[i][2];
        if(board[index1] == symbol && board[index2] == symbol && board[index3] == symbol)
            return true;
    }
    return false;
}
 
void solve() {
    init();

    for(int i =0 ; i< 9; i++)
        cin>> board[i];
    
    int countX = 0 , countO = 0;

    for(int i =0 ; i< 9; i++)
        if(board[i] == 'X')
            countX++;
        else if(board[i] == 'O')
            countO++;

    if (countO > countX)
    {
        cout<<"no"<<endl;
        return;
    } 

    if (countX == countO +1 || countX == countO)
    {
        if (win('X'))
        {
            if (win('O'))
            {
                cout<<"no"<<endl;
                return;
            }

            if (countX == countO+1)
            {
                cout<<"yes"<<endl;
                return;
            } 
            cout<<"no"<<endl;
            return; 
        }

        if(win('O'))
        {
            if(countO == countX)
            {
            cout<<"yes"<<endl;
            return; 
            }
            cout<<"no"<<endl;
            return; 
        }

        cout<<"yes"<<endl;
        return;
    }

    cout<<"no"<<endl;
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