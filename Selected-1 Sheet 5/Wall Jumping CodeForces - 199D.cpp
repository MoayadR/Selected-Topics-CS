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

bool visited[2][(int)1e5+1];
vector<string>grid(2);

int n , k;
bool bfs(){
    queue<pair<int,int>>q;
    q.emplace(0 , 0);
    queue<int>water;
    water.push(-1);
    while(!q.empty())
    {
        pair<int,int>top = q.front();
        q.pop();
        int flood = water.front();
        water.pop();

        if(top.second >= n)
            return true;
        if(flood >= top.second)
            continue;
        if(!inbound2D(top.first , top.second , 2 ,n))
            continue;
        if((grid[top.first][top.second] == 'X' || visited[top.first][top.second]))
            continue;


        visited[top.first][top.second] = 1;

        q.emplace(top.first, top.second-1);
        water.push(flood+1);
        q.emplace(top.first, top.second+1);
        water.push(flood+1);

        q.emplace((top.first+1)%2 , top.second+k);
        water.push(flood+1);

    }
    return false;
}


void solve(int t) {
    cin>> n >> k;
    cin>> grid[0]>>grid[1];
    memset(visited , 0 , sizeof visited);

    if(bfs())
        cout<<"YES\n";
    else
        cout<<"NO\n";

}



int main() {
    katafast
    int t =1;
//    cin>> t;
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


