#include <bits/stdc++.h>

using namespace std;
ifstream fin("PCTV.INP");
ofstream fout("PCTV.OUT");
typedef long long ll;
typedef pair<int,int> ii;
const int SIZE=  2*1E5+5;
int check[SIZE];
int n;
ii a[SIZE];
void Input()
{
    fin>>n;

    n*=2;

    int x,y;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        a[i]=ii(x,y);
    }
}

void Solve()
{
    int A=0;
    int B=0;
    ll S=0;
    deque<ii> Q;
    for(int i=1;i<=n;i++)
    {
        if(S+a[i].first < S+a[i].second)
        {
            S+=a[i].first;
            check[i]=1;
            A++;
        }
        else
        {
            S+=a[i].second;
            check[i]=2;
            B++;
        }
    }
    do {
        int k=abs(A-B);
        if(A>B)
        {
            for(int i=1;i<=n;i++)
                if(check[i]==1)

            {
                Q.push_back(ii(abs(a[i].first-a[i].second),i));
            }
            sort(Q.begin(),Q.end());
            while(k>=1)
            {
                int x=Q.front().second;
                Q.pop_front();
                S+=a[x].second - a[x].first;
                B++;
                A--;
                k=abs(A-B);
            }
            Q.clear();
        }
        else if( B > A)
        {

            for(int i=1;i<=n;i++)
                if(check[i]==2)

            {
                Q.push_back(ii(abs(a[i].first-a[i].second),i));
            }
            sort(Q.begin(),Q.end());

            while(k>=1)
            {
                int x=Q.front().second;
                Q.pop_front();
                S+=a[x].first - a[x].second;

                A+=1;
                B--;
                k=abs(A-B);
            }
            Q.clear();
        }
    }while (A!=B);
    fout<<S;
}
int main()
{
    Input();
    Solve();
    return 0;
}
