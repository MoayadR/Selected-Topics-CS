#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string keyboard  ="qwertyuiopasdfghjkl;zxcvbnm,./";

int main(){

    unordered_map<char , char> leftMap;
    unordered_map<char , char> rightMap;

    leftMap[keyboard[0]] = ' ';
    rightMap[keyboard[0]] = 'w';

    leftMap[keyboard[keyboard.length()-1]] = '.';
    rightMap[keyboard[keyboard.length()-1]] = ' ';

    for(int i =1 ; i<keyboard.length()-1; i++)
    {
            leftMap[keyboard[i]] = keyboard[i-1];
            rightMap[keyboard[i]] = keyboard[i+1];
    }

    char side;
    string input , res = "";

    cin>>side;
    cin>>input;

    if(side == 'L')
    {
        for(int i =0 ; i<input.length() ; i++)
        {
            if(rightMap[input[i]] != ' ')
                res += rightMap[input[i]];
        }
    }
    else
    {
        for(int i =0 ; i<input.length() ; i++)
        {
            if(leftMap[input[i]] != ' ')
                res += leftMap[input[i]];
        }
    }

    cout<<res<<endl;



    return 0;
}