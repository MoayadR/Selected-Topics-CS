#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    katafast

    vector<int> n ;
    while(true)
    {
        int temp;
        cin>> temp;
        if(temp == 0)
            break;
        n.push_back(temp);
    }
    for(int j = 0 ; j<n.size() ; j++)
    {
        int s = n[j];
        queue<int>q;
        vector<int>dis;
        for(int i=1 ; i<=s ; i++)
        {
            q.push(i);
        }

        while(q.size() > 1)
        {
            dis.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }

        if(dis.size() == 0)
        {
            cout<<"Discarded cards:";
        }
        else
        {
            cout<<"Discarded cards: ";
        }

        for(int i =0 ; i<dis.size() ; i++)
        {
            if(i == dis.size()-1)
            {
                cout<<dis[i];
                break;
            }
            cout<<dis[i]<<", ";
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
    }

    return 0;
}
