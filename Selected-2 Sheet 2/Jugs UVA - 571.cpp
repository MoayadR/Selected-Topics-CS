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

set<pair<int,int>>visited;
vector<string> bfs(int a ,int b , int c)
{
    queue<pair<int,int>>values;
    values.emplace(0 , 0);

    queue<vector<string>>seqQueue;
    vector<string>initSeq;

    vector<string>temp ;

    seqQueue.emplace(initSeq);


    while(!values.empty())
    {
        pair<int,int> it = values.front();
        vector<string>seq = seqQueue.front();
        seqQueue.pop();
        values.pop();

        if(it.second == c)
        {
            seq.push_back("success");
            return seq;
        }

        if(visited.find(it) == visited.end())
        {
            visited.insert(it);
            values.emplace(it.first-it.first , it.second);
            temp= seq;
            temp.push_back("empty A");
            seqQueue.push(temp);

            values.emplace(it.first , it.second-it.second);
            temp = seq;
            temp.push_back("empty B");
            seqQueue.push(temp);

            values.emplace(a , it.second);
            temp = seq;
            temp.push_back("fill A");
            seqQueue.push(temp);

            values.emplace(it.first , b);
            temp = seq;
            temp.push_back("fill B");
            seqQueue.push(temp);

            values.emplace(max(it.first-(b-it.second) , 0) , min(it.first+it.second , b));
            temp = seq;
            temp.push_back("pour A B");
            seqQueue.push(temp);

            values.emplace(min(it.first+it.second , a) , max(it.second-(a-it.first) , 0));
            temp = seq;
            temp.push_back("pour B A");
            seqQueue.push(temp);
        }
    }
    return {};
}

void init(){
    visited.clear();
}

 
void solve() {

    int a , b , c;
    while(cin>> a >> b >> c)
    {
        init();
        vector<string>res = bfs(a,b,c);
        for(int i =0 ; i<res.size() ; i++)
            cout<<res[i]<<endl;
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