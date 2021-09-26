#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long

using namespace std;

int N, difA = 100000000, difL = 1000000000;
vector<pair<int, int>> molduras;
int difere = 1000000;

int main(int argc, char const * argv[]){
    int A, L;
    cin>>A >>L;
    cin>>N;

    if(A > L) swap(A, L);
    int x, y;
    for (int i = 1; i <= N; i++)
    {
        cin>>x>>y;
        if(x, y) swap(x, y);
        molduras.emplace_back(x, y);
    }

    int res = -1, cont = 1;
    
    for(auto x : molduras)
    {
        if((x.first >= A) && (x.second >= L))
        {
            int a = (x.first - A);
            int b = (x.second - L);

            if(difere > (a + b))
            {
                difA = a;
                difL = b;
                res = cont;

                difere = a + b;
            }
        }

        cont++;

    }    

    cout<<res<<endl;
    

    return 0;
}