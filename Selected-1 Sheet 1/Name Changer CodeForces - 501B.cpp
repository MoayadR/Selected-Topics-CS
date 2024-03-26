#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    katafast
    int n ;
    cin>> n ;
    unordered_map<string ,string> map;
    for(int i =0 ; i<n ; i++)
    {
        bool status = true;
        string name1 , name2;
        cin>> name1 >> name2;
        for(const auto& it : map)
        {
            if(it.second == name1)
            {
                map[it.first] = name2;
                status = false;
                break;
            }
        }
        if (status)
            map[name1] = name2;
    }

    cout<<map.size()<<endl;
    for(const auto& it : map)
    {
        cout<<it.first << ' ' << it.second<<endl;
    }


    return 0;
}
