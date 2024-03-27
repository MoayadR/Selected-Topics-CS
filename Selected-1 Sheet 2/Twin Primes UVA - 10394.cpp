#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long



vector<bool>primes(2e7+1 , true);
vector<pair<int , int >>pairs;

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

void setPairs()
{
    for(int i =2 ; i<primes.size() ; i)
    {
        if(primes[i] && primes[i+2])
        {
            pairs.emplace_back(i , i+2);
            i+=2;
        }
        else
            i++;
    }
}


int main() {
    katafast


    seievePrimes();
    setPairs();

    int n ;
    while(cin>>n)
    {
        auto item = pairs[n-1];
        cout<<'('<<item.first << ", " << item.second<<')'<<endl;
    }


    return 0;
}
