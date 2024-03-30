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

int N = 1e6+7;
bool visited[(int)1e6+7];
vector<vector<int>>adj(N);
vector<int>indecies;

void dfs(int i)
{
    visited[i] = 1;
    indecies.push_back(i);
    for(int& j : adj[i]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}

void solve(int t) {
    adj.clear();
    adj.resize(N);
    memset(visited , 0 , sizeof visited);

    string s;
    cin>> s;
    int n;
    cin>>n;

    vector<pair<int,int>>moves;
    for(int i =0 ; i<n ; i++)
    {
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    string res = string(s.size() , '0');
    for(int i =0 ; i<s.size() ; i++)
    {
        if(!visited[i])
        {
            indecies.clear();
            dfs(i);
            string temp = "";
            for(int j = 0 ;j<indecies.size() ; j++)
                temp+=s[indecies[j]];


            sort(temp.begin() , temp.end());
            sort(indecies.begin() , indecies.end());

            for(int j =0 ;j<indecies.size() ;j++)
                res[indecies[j]] = temp[j];


            indecies.clear();
        }
    }
    cout<<res<<'\n';
}


int main() {
    katafast
    int t =1;
    cin>> t;
    while(t)
    {
        solve(t);
        t--;
    }

    return 0;
}


