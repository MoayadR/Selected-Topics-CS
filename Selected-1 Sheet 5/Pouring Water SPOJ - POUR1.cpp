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

set<pair<int,int>>visited;
int bfs(int a ,int b , int c)
{
    queue<pair<int,int>>values;
    queue<int>steps;

    values.emplace(0 , 0);
    steps.push(0);

    while(!values.empty())
    {
        pair<int,int> it = values.front();
        values.pop();
        int step = steps.front();
        steps.pop();

        if(it.first == c || it.second == c)
        {
            return step;
        }

        if(visited.find(it) == visited.end())
        {
            visited.insert(it);
            values.emplace(it.first-it.first , it.second);
            steps.push(step+1);

            values.emplace(it.first , it.second-it.second);
            steps.push(step+1);

            values.emplace(a , it.second);
            steps.push(step+1);

            values.emplace(it.first , b);
            steps.push(step+1);

            values.emplace(max(it.first-(b-it.second) , 0) , min(it.first+it.second , b));
            steps.push(step + 1);

            values.emplace(min(it.first+it.second , a) , max(it.second-(a-it.first) , 0));
            steps.push(step+1);

        }
    }
    return -1;
}

void solve(int t) {
    int a , b , c;
    cin>> a >>b >> c;
    cout<<bfs(a,b,c)<<'\n';
    visited.clear();
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


