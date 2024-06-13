#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e6
int const MOD = 1e9+7;
 
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
 
bool inbound(int i , int is)
{
    if(i>=0 && i <is)
        return true;
    return false;
}


class DSU { 
    int* parent; 
    int* rank; 
  
public: 
    DSU(int n) 
    { 
        parent = new int[n]; 
        rank = new int[n]; 
  
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
  
    // Find function 
    int find(int i) 
    { 
        if (parent[i] == -1) 
            return i; 
  
        return parent[i] = find(parent[i]); 
    } 
  
    // Union function 
    void unite(int x, int y) 
    { 
        int s1 = find(x); 
        int s2 = find(y); 
  
        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    } 
}; 

vector<int>mocha(1001);
vector<int>diana(1001);

void init(){

}

void solve() {
    DSU mSet(1001);
    DSU dSet(1001);

    int n , m1 , m2;
    cin>> n>> m1 >> m2;

    for(int i =0 ; i<m1 ; i++)
    {
        int x , y ;
        cin>> x >> y;
        mSet.unite(x , y);
    }
    for(int i =0 ; i<m2 ; i++)
    {
        int x , y ;
        cin>> x >> y;
        dSet.unite(x , y);
    }

    int count = 0;
    vector<pair<int,int>>res;
    for(int i =1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            if (mSet.find(i) != mSet.find(j) && dSet.find(i) != dSet.find(j))
            {
                mSet.unite(i , j);
                dSet.unite(i , j);
                count++;
                res.emplace_back(i , j);
            }
        }
    }

    cout<<count<<endl;
    for(int i =0 ; i<count ; i++)
        cout<< res[i].first << ' '<< res[i].second<<endl;

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