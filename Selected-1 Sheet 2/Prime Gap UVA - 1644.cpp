#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

void seievePrimes(vector<bool>& primes){
    primes[0] = false;
    primes[1] = false;

    for (int i = 2 ; i * i < 1299710 ; i++)
    {
        if (primes[i])
        {
            for (int j = i * i ; j < 1299710 ; j+= i)
                primes[j]=false;
        }
    }
}

int main() {
    katafast
    vector<bool>primes(1299710 , true);
    seievePrimes(primes);
    int n;
    while(true)
    {
        cin>>n;
        if(n == 0)
            break;

        if(primes[n])
        {
            cout<<0<<endl;
            continue;
        }

        int left= n , right=n;
        while(!primes[left])
            left--;
        while(!primes[right])
            right++;

        cout<<right - left<<endl;
    }



    return 0;
}
