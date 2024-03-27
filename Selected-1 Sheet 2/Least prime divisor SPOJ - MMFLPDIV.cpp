#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int getPrimeDivisor(int x)
{
    int smallest = 100000000;
    for (int i =2 ; i*i <= x ; i++)
    {
        int power= 0;
        while(x % i == 0)
        {
            power++;
            x /= i;
            if (i< smallest)
                smallest = i;
        }
    }
    if (x != 1)
        if(x < smallest)
            smallest = x;
    return smallest;
}


int main(){
    while(true)
    {
        int x ;
        cin>> x ;
        if (x == 0)
            return 0;
        cout<<getPrimeDivisor(x)<<endl;

    }
    return 0;
}
