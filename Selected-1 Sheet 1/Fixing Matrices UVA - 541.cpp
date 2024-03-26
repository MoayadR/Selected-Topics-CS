#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
bool sumRowsEven( vector<vector<int>>matrix , int n)
{
    for(int i =0 ; i<n ; i++)
    {
        int sum = 0;
        for(int j =0 ; j<n ; j++)
        {
            sum+= matrix[i][j];
        }
        if(sum %2 != 0)
            return false;
    }
    return true;
}

bool sumColumnEven(vector<vector<int>>matrix , int n)
{
    for(int j =0 ; j<n ; j++)
    {
        int sum = 0;
        for(int i =0 ; i<n ; i++)
        {
            sum+= matrix[i][j];
        }
        if(sum %2 != 0)
            return false;
    }
    return true;
}

int main() {
    katafast
    int n;
    while(cin>>n)
    {
        if(n == 0)
            break;

        vector<vector<int>>matrix(n , vector<int>(n , 0));
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<n ; j++)
            {
                cin>>matrix[i][j];
            }
        }

        if(sumColumnEven(matrix , n) && sumRowsEven(matrix,n))
            cout<<"OK"<<endl;
        else
        {
            bool status = false;
            for(int i =0 ; i<n ; i++)
            {
                for(int j =0 ; j<n ; j++)
                {
                    matrix[i][j] = ~ matrix[i][j];
                    if(sumColumnEven(matrix , n) && sumRowsEven(matrix,n))
                    {
                        cout<<"Change bit ("<<i+1<<','<<j+1<<')'<<endl;
                        status = true;
                        break;
                    }
                    matrix[i][j] = ~ matrix[i][j];
                }
                if(status)
                    break;
            }

            if(!status)
                cout<<"Corrupt"<<endl;
        }
    }

    return 0;
}
