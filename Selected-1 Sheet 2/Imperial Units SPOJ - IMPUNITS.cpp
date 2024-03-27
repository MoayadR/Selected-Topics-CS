#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll gcd(ll a, ll b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return abs(a*b) /gcd(a , b);
}


int main() {
    katafast

    ll n ;
    while(cin>>n)
    {
        if(n == -1)
            break;

        ll left , right , temp;
        if(n == 2)
        {
            cin>> left >> right;
            ll GCD = gcd(left ,right);
            cout<<left/GCD <<' '<< right/GCD<<endl;
            continue;
        }

        vector<ll>nums;
        cin>>left;
        cin>> temp;
        nums.push_back(temp);
        for(ll i =1 ; i<n-1 ; i++)
        {
            if(i == n-2)
            {
                cin>>temp>>right;
                nums.push_back(temp);
            }
            else
            {
                cin>>temp;
                nums.push_back(temp);
                cin>>temp;
                nums.push_back(temp);
            }
        }
        ll mulLeft = 1 , mulRight = 1;
        for(int i =0 ;i<nums.size() ; i+=2)
        {
            if(nums[i] == nums[i+1])
                continue;
            mulLeft *= lcm(nums[i] , nums[i+1]) / nums[i];
            mulRight *= lcm(nums[i] , nums[i+1]) / nums[i+1];
        }

        left *= mulLeft;
        right *= mulRight;
        ll GCD = gcd(left ,right);
        cout<<left/GCD  << ' '<< right/GCD <<endl;
    }
    return 0;
}
