#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int main() {
    katafast

    priority_queue <int, vector<int>, greater<int>> pq;
    queue<string> operations;
    queue<int> operands;
    int n ;
    int x , op=0;
    string s;
    cin>>n;
    while(n--)
    {
        cin>> s;
        if(s == "insert")
        {
            cin>>x;
            operations.emplace("insert");
            operands.push(x);
            pq.push(x);
            op++;
        }
        else if(s== "getMin")
        {
            cin>>x;
            while(!pq.empty() && x > pq.top())
            {
                pq.pop(); // removeMin
                operations.emplace("removeMin");
                op++;
            }

            if(pq.empty() || x!= pq.top())
            {
                pq.push(x); // insert Min
                operations.emplace("insert");
                operands.push(x);
                op++;
            }

            op++; // getMin
            operations.emplace("getMin");
            operands.push(x);

        }
        else
        {
            // removeMin

            if(pq.empty())
            {
                operations.emplace("insert");
                operands.push(0);
                pq.push(0);
                op++;
            }

            if(!pq.empty())
            {
                operations.emplace("removeMin");
                pq.pop();
                op++;
            }


        }
    }

    cout<<op<<endl;
    while(!operations.empty())
    {
        if(operations.front() == "removeMin")
        {
            cout<<operations.front()<<endl;
            operations.pop();
            continue;
        }
        cout<<operations.front()<<' ';
        cout<<operands.front()<<endl;
        operations.pop();
        operands.pop();
    }

    return 0;
}


