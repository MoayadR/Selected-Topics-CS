#include <iostream>

using namespace std;

bool checkPalidrome(string s)
{
    int left = 0 , right = s.length()-1;
    while(left < right )
    {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }

    return true;
}

int main(){
    string s , newS ="";
    cin>> s;

    if(checkPalidrome(s))
    {
        cout<<"YES"<<endl;
        return 0;
    }


    int right = s.length()-1;
    while(s[right] == '0')
        right--;

    for(int i =0 ; i<=right; i++)
        newS+=s[i];

    if(checkPalidrome(newS))
    {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
}