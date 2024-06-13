#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;

const int N = 2e7 + 10;

char pattern[N], s[N];
int lps[N];

int lenGet(char c, int len) {
    while (len && pattern[len] != c)
        len = lps[len - 1];
    if (pattern[len] == c)
        ++len;
    return len;
}

void calcPrefix() {
    lps[0] = 0;
    for (int i = 1; pattern[i]; ++i)
        lps[i] = lenGet(pattern[i], lps[i - 1]);

}

vector<int> match() {
    calcPrefix();
    int len = 0;
    vector<int> ans;
    for (int i = 0; s[i]; ++i) {
        len = lenGet(s[i], len);
        if (!pattern[len])
            ans.push_back(i - len + 1);
    }
    return ans;
}


void init(){
}

void solve() {
    unordered_map<string , bool>mp;
    scanf("%s" , s);
    int m ;
    scanf("%d" , &m);

    for (int i =0 ; i<m ; i++){
        scanf("%s" , pattern);
        if (mp.find(pattern) != mp.end())
        {
            if (mp[pattern])
            {
                printf("y\n");
                continue;
            }
            printf("n\n"); 
            continue;
        }

        vector<int>ans = match();
        if (ans.size())
        {
            mp[pattern] = true;
            printf("y\n");
            continue;
        }
        mp[pattern] = false;
        printf("n\n");
    }
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    scanf("%d", &t);
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}
