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

vector<bool>status;
int bfs(int f1 , int f2 , const vector<vector<int>>&graph)
{
    if (f1 == f2)
        return 0;
    queue<pair<int,int>>q;
    q.emplace(f1 , 0 );

    while(!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();

        for(int i =0 ;i <graph[top.first].size() ; i++)
        {
            if(graph[top.first][i] == f2)
                return top.second;
            if(!status[graph[top.first][i]])
            {
                status[graph[top.first][i]] = 1;
                q.emplace(graph[top.first][i] , top.second+1);
            }
        }
    }
    return -1;
}

void solve(int t) {
    int n ;
    cin>> n;
    cin.ignore();
    status.clear();
    status.resize(n , 0);
    vector<vector<int>>graph(n);
    for(int i =0 ;i <n ; i++)
    {
        int id , sz;
        cin>> id >> sz;
        vector<int>arr(sz);
        for(int i =0 ;i<sz ; i++)
            cin>>arr[i];

        graph[id] = arr;
    }

    int f1 , f2;
    cin>> f1 >> f2;

    if(t != 1)
    {
        cout<<f1 <<' '<<f2<<' '<<bfs(f1 , f2 , graph)<<'\n';
        cout<<'\n';
    }
    else
        cout<<f1 <<' '<<f2<<' '<<bfs(f1 , f2 , graph)<<'\n';

}



int main() {
    katafast
    int t ;
    cin>> t;
    cin.ignore();
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


