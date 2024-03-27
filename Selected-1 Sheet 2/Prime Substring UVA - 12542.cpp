#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


vector<bool>primes(1e5+1 , true);

void seievePrimes(){
    primes[0] = false;
    primes[1] = false;

    for (int i = 2 ; i * i < primes.size() ; i++)
    {
        if (primes[i])
        {
            for (int j = i * i ; j < primes.size() ; j+= i)
                primes[j]=false;
        }
    }
}




int main() {
    katafast
    seievePrimes();
    string n;
    while(cin>>n)
    {
        if (n == "0")
            break;
        ll maxPrime = 0;
        for(ll i =0 ; i<n.size() ; i++)
        {
            ll value = 0;
            for(ll j = i ; j<n.size(); j++)
            {
                value = value * 10 +(n[j] - '0');
                if(value > 1e5)
                    break;
                if(primes[value])
                    maxPrime = max(maxPrime , value);
            }
        }
        if (maxPrime == 0)
            cout<< " "<<endl;
        else
            cout<<maxPrime<<endl;
    }

    return 0;
}
