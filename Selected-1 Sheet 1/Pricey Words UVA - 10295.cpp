#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int main() {
    fast
    int m , n;
    cin>> m >> n;
    unordered_map<string , ll> map;

    for (int i =0 ; i< m;  i++)
    {
        string temp; ll value;
        cin>> temp >> value;
        map[temp] = value;
    }

    for(int i =0 ; i<n ; i++)
    {
        string temp;
        ll value = 0;
        while(cin>>temp)
        {
            if (temp == ".")
            {
                break;
            }

            if(map.find(temp) != map.end())
            {
                value += map[temp];
            }
        }
        cout<< value<<endl;
    }

    return 0;
}
