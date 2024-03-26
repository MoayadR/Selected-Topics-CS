#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    katafast

    int n ;
    while(true)
    {
        cin>>n;
        if(n == 0)
            break;

        priority_queue <int, vector<int>, greater<int>> q;
        int cost = 0;
        for(int i =0 ; i<n ; i++)
        {
            int temp;
            cin>> temp;
            q.push(temp);
        }

        while(q.size() != 1)
        {
            int first =q.top();
            q.pop();
            int second = q.top();
            q.pop();
            cost += (first + second);
            q.push(first+second);
        }

        cout<<cost<<endl;

    }

    return 0;
}
