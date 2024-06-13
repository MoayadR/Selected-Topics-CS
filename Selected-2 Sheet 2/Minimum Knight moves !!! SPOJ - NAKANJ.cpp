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

vector<pair<int,int>> moves = {
    {-1 , -2}, {+1 , -2},
    {-2 , -1} , {-2 , +1},
    {+2 , -1} , {+2 , +1},
    { -1, +2} , {+1 , +2}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<vector<int>>dist(8 , vector<int>(8 , INF));

int dijkstra(int xend , int yend)
{
    while(!q.empty())
    {
        auto top = q.top();
        q.pop();

        for(auto move : moves)
        {
            int newX = top.first + move.first;
            int newY = top.second + move.second;

            if(inbound2D(newX , newY , 8 , 8) && dist[newX][newY] > dist[top.first][top.second] + 1 )
            {
                dist[newX][newY] = dist[top.first][top.second] + 1;
                q.emplace(newX , newY);
            }
            
        }
    }
   return dist[xend][yend]; 
}

void init(){
    dist.clear();
    dist.resize(8 , vector<int>(8 , INF));
}

 
void solve() {
    int xstart , ystart  , xend , yend;
    int n ;
    cin>> n;
    string s;
    cin.ignore();
    while(n--)
    {
        init();
        getline(cin, s);
        xstart = (int) (s[0]- 'a' );
        ystart = (int) (s[1] - '0') - 1;

        xend = (int) ( s[3] - 'a');
        yend = (int) ( s[4] - '0') - 1;

        q.push({xstart , ystart});
        dist[xstart][ystart] = 0;
        printf("%d\n" , dijkstra(xend , yend));
    }
}
 
 
 
int main() {
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
} 