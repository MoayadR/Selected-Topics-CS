#include <iostream>
//#include <bits/stdc++.h>

using namespace std;



int main(){
    int t ;
    cin>> t ;
    int N ;
    int cnt;
    while (t--)
    {
        cnt = 0;
        cin>> N ;
        while(N)
        {
            int temp = N;
            while(temp)
            {
                if (temp&1)
                {
                    cnt++;
                }
                temp = temp>>1;
            }
            N--;
        }
        cout<<cnt<<endl;
    }

    return 0;
}