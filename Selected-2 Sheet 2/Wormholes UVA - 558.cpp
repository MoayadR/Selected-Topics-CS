#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e6
int const MOD = 1e9+7;
 
// vector<pair<int,int>>moves = {
//     {-1 , -1}, {+1 , +1},
//     {-1 , +1} , {+1 , -1},
//     {+1 , 0} , {-1 , 0},
//     {0 , +1} , {0 , -1}
// };
 
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

vector<tuple<int,int,int>>edges;
vector<int>dist(1001);
int n ;

bool worm(int src)
{
    dist[src] = 0;
    for(int i = n ; i>=0 ; i--)
    {
        for(auto e : edges)
        {
            int x , y , c;
            tie(x , y , c) = e;
            if(dist[y] > dist[x] + c)
            {
                dist[y] = dist[x] + c;
                if(!i)
                    return 1;
            }
        }
    }
    return 0;
}

void init(){
    edges.clear();
    fill(dist.begin() , dist.end() , INF);
}

 
void solve() {
    init();
    int m ;
    cin>> n >> m;
    for(int i =0 ; i<m ; i++)
    {
        int x,  y , c;
        cin>> x >> y >> c;
        edges.emplace_back(x , y ,c);
    }

     for (int i = 0; i < n; i++)
            edges.emplace_back(n, i, 0);

    bool res = worm(n++);
    if(res)
        cout<<"possible"<<endl;
    else
        cout<<"not possible"<<endl;
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