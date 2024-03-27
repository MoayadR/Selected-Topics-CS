#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    for(int i =2 ; i*i <=x ; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

vector<int> getDivisiors(int x)
{
    vector<int> divisors;
    for (int i =2 ; i*i <=x ; i++)
    {
        if(x%i==0)
        {
            divisors.push_back(i);
            divisors.push_back(x/i);
        }
    }
    return divisors;
}

int G(int x)
{
    if (x == 0 || x == 1 || x == 2)
        return x;
    if (x % 2 != 0 && isPrime(x))
        return 0;

    vector<int> divisors = getDivisiors(x);

    int a = 0 , b =0 , sum = 10000000;
    for(int i =0 ; i< divisors.size() ; i+=2)
    {
        if(divisors[i] + divisors[i+1] < sum)
        {
            a = divisors[i];
            b = divisors[i+1];
            sum = divisors[i] + divisors[i+1];
        }
    }

    return G(a) + G(b);
}

int main(){
    int x ;
    cin>> x ;
    cout<<G(x)<<endl;

    return 0;
}