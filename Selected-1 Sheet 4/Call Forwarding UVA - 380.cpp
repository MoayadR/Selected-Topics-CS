#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

struct phone{
    int source;int start , end ;int forward;
    phone(int source , int start , int end , int forward) {
        this->source = source;this->start = start;this->end = end;this->forward = forward;
    }
};

vector<phone>phones;
map<int,bool>numbers;

int findNumber(int phoneNumber , int time)
{
    if (numbers.find(phoneNumber) != numbers.end())
        return 9999;

    for(int i =0 ;i<phones.size(); i++)
    {
        if(phones[i].source == phoneNumber)
        {
            if (phones[i].start <= time && phones[i].end >= time)
            {
                numbers[phoneNumber] = 1;
                return findNumber(phones[i].forward , time);
            }
        }
    }
    return phoneNumber;
}

void solve() {
    int t ;
    printf("CALL FORWARDING OUTPUT\n");
    cin>> t;
    int count = 1;
    while(t--)
    {
        phones.clear();

        int source;
        while(cin>> source)
        {
            if(source == 0)
                break;
            int start , end;
            int forward;
            cin>>start >>end;
            cin>>forward;
            phones.emplace_back(source , start , start+end , forward);
        }

        printf("SYSTEM %d\n", count);
        count++;
        int qStart;
        int qNumber;
        while(cin>>qStart)
        {
            if(qStart == 9000)
                break;
            cin>>qNumber;
            numbers.clear();
            printf("AT %04d CALL TO %04d RINGS %04d\n",qStart , qNumber , findNumber(qNumber , qStart));
        }
    }

    printf("END OF OUTPUT\n");
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


