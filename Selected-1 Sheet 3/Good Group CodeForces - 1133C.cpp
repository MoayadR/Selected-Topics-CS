#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main() {
    int n;
    vector<int> arr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int maxCnt = 1;

    int i = 0 , j =1;

    while(i<= j && j <= n)
    {
        if(arr[j] - arr[i] <= 5)
        {
            if(j == n)
                break;
            maxCnt = max(maxCnt , (j-i)+1);
            j++;
        }
        else
        {
            i++;
        }
    }

    cout<<maxCnt<<endl;

    return 0;
}