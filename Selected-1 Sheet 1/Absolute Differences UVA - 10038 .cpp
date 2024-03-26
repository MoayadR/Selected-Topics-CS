#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    katafast
    int n ;
    while(cin>> n)
    {
        vector<int>nums(n);
        for(int i =0 ; i< n ; i++)
            cin>>nums[i];

        vector<bool>res(n , false);

        for(int i =0 ; i<n-1 ; i++)
        {
            int temp = abs(nums[i+1] - nums[i]);
            if (temp >=0 && temp <=n-1)
                res[temp] = true;
        }

        bool status = false;
        for(int i =1 ; i<n ; i++)
        {
            if(res[i] == false)
            {
                cout<<"Not jolly"<<endl;
                status = true;
                break;
            }
        }

        if(status)
            continue;

        cout<<"Jolly"<<endl;

    }

    return 0;
}
