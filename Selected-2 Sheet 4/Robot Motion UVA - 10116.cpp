#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


 vector<pair<int,int>>moves = {
     {-1 , -1}, {+1 , +1},
     {-1 , +1} , {+1 , -1},
     {+1 , 0} , {-1 , 0},
     {0 , +1} , {0 , -1}
 };

 bool inbound2D(int i , int j , int is , int js)
 {
     if(i>=0 && i <is && j>=0 && j<js)
         return true;
     return false;
 }

 bool inbound(int i , int is) {
     if (i >= 0 && i < is)
         return true;
     return false;
 }

int n , m  , s ;
char Board[15][15] ;
int vis[15][15] ;
int step = -1 ;
int total = -1 ;
void dfs(int x , int y , int count) {
    int nx , ny ;
    if(Board[x][y] == 'N') {
        nx = x - 1 ;
        ny = y ;
    }
    else if(Board[x][y] == 'S') {
        nx = x + 1 ;
        ny = y ;
    }
    else if(Board[x][y] == 'E') {
        nx = x ;
        ny = y + 1 ;
    }
    else if(Board[x][y] == 'W') {
        nx = x ;
        ny = y - 1 ;
    }
    if(inbound2D(nx , ny , n , m)) {
        if(vis[nx][ny] == -1) {
            count++ ;
            vis[nx][ny] = count ;
            dfs(nx , ny , count) ;
        }
        else {
            count++ ;
            total = vis[nx][ny] ;
            step = count ;
        }
    }
    else {
        count++ ;
        step = count ;
    }
}

void init(){
    memset(vis , -1 , sizeof vis) ;
}
void solve() {
    while(cin >> n >> m >> s) {
        if(n == 0 && m ==0 && s == 0)
            break ;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cin >> Board[i][j] ;
            }
        }
        init();
        step = -1 ;
        total = -1 ;
        vis[0][s - 1] = 0 ;
        dfs(0 , s - 1 , 0) ;

        if(total == -1) {
            cout << step << " step(s) to exit\n" ;
        }
        else {
            step -= total ;
            cout << total << " step(s) before a loop of " << step << " step(s)\n" ;
        }
    }
}


int main()
{
    katafast
    int t =1;
//    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}
