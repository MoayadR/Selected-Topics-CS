#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void prefix_sum(vector<int>&prefixSum , const vector<int>&deq)
{
    int n = prefixSum.size();
    prefixSum[0] = deq[0];
    for(int i = 1 ; i<n ; i++)
    {
        prefixSum[i] = deq[i] + prefixSum[i-1];
    }
}

int main(){
    int N ;
    cin>> N;

    vector<int> arr;
    vector<int>prefix(N , 0);

    for(int i =0 ; i<N; i++)
    {
        int temp ;
        cin>> temp;
        arr.push_back(temp);
    }

    prefix_sum(prefix , arr);

    int Q;
    cin>> Q;
    int l , r;
    while(Q--)
    {
        cin>> l >> r;

        if(l)
            cout<<prefix[r] - prefix[l-1]<<endl;
        else
            cout<<prefix[r]<<endl;
    }

    return 0;
}