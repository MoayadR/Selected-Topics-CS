#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
string s;
int getEmpty(int index)
{
    index++;
    while(index <s.size() && s[index] != '0')
        index++;
    return index;
}

void solve() {
    int n , k;
    cin>> n >> k;
    cin>>s;

    int left = getEmpty(-1) , right = getEmpty(-1);
    int reserved = 1;
    int maxDistance = n+1;

    while(left <= right)
    {
        if(reserved < k+1)
        {
            right = getEmpty(right);
            reserved++;
            if(right == s.size())
                break;
        }
        else
        {
            int mid = left + (right-left)/2;
            if(s[mid] == '0')
                maxDistance = min(maxDistance ,max(mid-left , right-mid) );
            else
            {
                int midleft = mid-1 , midright = mid+1;
                while(true)
                {
                    if(s[midleft] == '0' && s[midright] == '0')
                    {
                        maxDistance = min(min(maxDistance ,max(midleft-left , right-midleft) ) , min(maxDistance ,max(midright-left , right-midright) ));
                        break;
                    }
                    if(s[midleft] == '0')
                    {
                        maxDistance = min(maxDistance ,max(midleft-left , right-midleft) );
                        break;
                    }
                    if(s[midright] == '0')
                    {
                        maxDistance = min(maxDistance ,max(midright-left , right-midright) );
                        break;
                    }

                    if(midleft>0)
                        midleft--;
                    if(midright<n-1)
                        midright++;
                }
            }

            left = getEmpty(left);
            reserved--;
        }
    }

    cout<<maxDistance<<endl;

}


int main() {
    katafast

    int t = 1;
//    cin>> t;

    while(t--)
    {
        solve();
    }

    return 0;
}


