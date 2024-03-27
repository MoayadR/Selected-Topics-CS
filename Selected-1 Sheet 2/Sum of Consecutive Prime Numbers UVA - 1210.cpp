#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


vector<bool>primes(10000+1 , true);

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
    int n ;
    while(true)
    {
        cin>>n;
        if (n == 0)
            break;
        int sum = 0 ,count = 0;
        queue<int>q;

        if (primes[n])
            count = 1;
        for(int i =2 ; i< n ; i++)
        {
            while(sum > n)
            {
                sum -= q.front();
                if(sum == n)
                    count++;
                q.pop();
            }
            if(primes[i])
            {
                sum+= i;
                if(sum == n)
                    count++;
                q.push(i);
            }

        }

        cout<<count<<endl;
    }
    return 0;
}


