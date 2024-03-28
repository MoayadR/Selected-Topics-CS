#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n  , x ;
    cin>> n >> x;
    vector<int>d;
    for(int i =0 ; i<n ; i++)
    {
        int temp;
        cin>> temp;
        d.push_back(temp);
    }

    long long i = 0 , j=0 , sum =0;
    long long maxSum = 0;

    while(i<=n && j <=n)
    {
        if (sum <= x)
        {
            if(j==n)
                break;
            maxSum = max(sum , maxSum);
            sum += d[j];
            j++;
        }
        else
        {
            sum -= d[i];
            if(sum <= x )
                maxSum = max(sum , maxSum);
            i++;
        }
    }

    cout<<maxSum<<endl;

    return 0;
}
