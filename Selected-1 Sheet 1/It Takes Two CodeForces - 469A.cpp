#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

int main() {
    fast
    set<int> st;
    int n, p;

    cin >> n;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        st.insert(temp);
    }

    st.size() == n ? cout<<"I become the guy." : cout<<"Oh, my keyboard!";
}
