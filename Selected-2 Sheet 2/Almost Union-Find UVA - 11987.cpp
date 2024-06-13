#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


// vector<pair<int,int>>moves = {
//     {-1 , -1}, {+1 , +1},
//     {-1 , +1} , {+1 , -1},
//     {+1 , 0} , {-1 , 0},
//     {0 , +1} , {0 , -1}
// };
 
// bool inbound2D(int i , int j , int is , int js)
// {
//     if(i>=0 && i <is && j>=0 && j<js)
//         return true;
//     return false;
// }
 
// bool inbound(int i , int is)
// {
//     if(i>=0 && i <is)
//         return true;
//     return false;
// }

const int N = 2000010;

struct dSet{
    int sum , size;
    vector<int>element;

    dSet(){
        sum = 0;
        size = 0;
    }
    dSet(int i ){
        sum = i;
        size = 1;
        element.push_back(i);
    }

    void add(int i){
        sum += i;
        size++;
        element.push_back(i);
    }

    void remove(int i){
        sum -= i;
        size--;
        element.erase(std::remove(element.begin(), element.end(), i), element.end());
    }

    void joinSet(dSet &other){
        sum += other.sum;
        size += other.size;
        other.sum = 0;
        other.size = 0;
        
        for (auto e : other.element) element.push_back(e);
        other.element.clear();
    }

    bool isEmpty(){
        return size == 0;
    }
};

struct dsu{
    vector<dSet> sets;
    vector<int>par;
    int n;

    void init(int n){
        this->n = n;
        sets.clear();
        par.clear();
        sets.resize(n+1);
        par.resize(n+1);
        for(int i =1 ; i<=n ; i++){
            sets[i] = dSet(i);
            par[i] = i;
        }
    }

    int find(int u){
       return par[u]; 
    }

    bool join(int u , int v){
        u = find(u) , v = find(v);
        if(u==v) return false;
        if (sets[u].size < sets[v].size) swap(u , v);

        for (auto e : sets[v].element) par[e] = u;
        sets[u].joinSet(sets[v]);

        return true;
    }

    void disconnect(int u){
        int parent = find(u);
        sets[parent].remove(u);
    }

}dsu;

void init(){
}

void solve() {
    int n  , m;

    while(cin>> n>> m )
    {
        dsu.init(n);
        int op;
        while(m--){
            cin>> op;
            if(op==1){
                int u , v;
                cin>> u>> v;
                dsu.join(u , v);
            }
            else if(op==2){
                int u , v;
                cin>> u >> v;
                if (dsu.find(u) == dsu.find(v)) continue;

                dsu.disconnect(u);
                dsu.sets[dsu.find(v)].add(u);
                dsu.par[u] = dsu.find(v);
            }
            else{
                int u;
                cin>> u;

                int parent = dsu.find(u);
                cout << dsu.sets[parent].size << " " << dsu.sets[parent].sum << endl;
            }
        }
    }
 
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
}
