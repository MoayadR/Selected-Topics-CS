#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

int main() {
    katafast
    string s;
    cin >> s;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    long long low = 0, high = 1e15, result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        long long neededB = max(0LL, mid * count(s.begin(), s.end(), 'B') - nb);
        long long neededS = max(0LL, mid * count(s.begin(), s.end(), 'S') - ns);
        long long neededC = max(0LL, mid * count(s.begin(), s.end(), 'C') - nc);

        long long cost = neededB * pb + neededS * ps + neededC * pc;

        if (cost <= r) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}