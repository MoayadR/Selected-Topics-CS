#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long


int main() {
    katafast

while(true)
{
    int W , H , N;
    cin>> W >> H >> N;

    if(W == 0 && H == 0 && N ==0)
        break;

    bool** rect = new bool*[W];

    for (int i = 0; i < W; i++)
        rect[i] = new bool[H];

    for(int i =0 ; i<W ; i++)
    {
        for(int j =0 ; j<H ; j++)
        {
            rect[i][j] = true;
        }
    }

    for(int i =0 ; i<N ; i++)
    {
        int x1 , x2 , y1 , y2;
        cin>> x1 >> y1 >> x2 >> y2;

        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                rect[x-1][y-1] = false;
            }
        }
    }
    ll counter = 0;
    for(int i =0 ; i<W ; i++)
    {
        for(int j =0 ; j<H ; j++)
        {
            if(rect[i][j])
                counter++;
        }
    }

    if(counter == 0)
        cout<<"There is no empty spots."<<endl;
    else if(counter == 1)
        cout<<"There is one empty spot."<<endl;
    else
        cout<<"There are "<<counter<<" empty spots."<<endl;

}





    return 0;
}
