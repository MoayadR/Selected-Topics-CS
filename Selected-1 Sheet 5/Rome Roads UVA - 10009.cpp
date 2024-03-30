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

set<char>visited;
string bfs(unordered_map<char , vector<char>>grid , char start , char end)
{
    queue<char>q;
    q.push(start);
    queue<string>results;
    string resTemp = "";
    resTemp += start;
    results.push(resTemp);

    while(!q.empty()){
        char top = q.front();
        q.pop();
        string res = results.front();
        results.pop();

        if(top == end)
        {
            return res;
        }

        if(visited.find(top) == visited.end())
        {
            visited.insert(top);

            vector<char> cities = grid[top];
            for(char city : cities)
            {
                q.push(city);
                results.push(res+city);
            }
        }
    }
    return "";
}

void solve(int t) {
    int n ,q ;
    cin>> n >> q;
    string st1 , st2;
    unordered_map<char , vector<char> >grid;
    for(int i =0; i<n ; i++)
    {
        cin>> st1 >> st2;
        grid[st1[0]].push_back(st2[0]);
        grid[st2[0]].push_back(st1[0]);
    }

    for(int i =0 ;i<q ; i++)
    {
        cin>>st1 >> st2;
        cout<<bfs(grid , st1[0] , st2[0])<<'\n';
        visited.clear();
    }

    if(t != 1)
        cout<<'\n';
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


