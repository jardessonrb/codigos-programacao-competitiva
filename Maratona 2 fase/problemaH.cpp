#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;
int N , M, A, B;
int main(int argc, char const *argv[]){
    optimize;
    int ans = 0;
    cin>> N >>M;

    ll val[N+1];

    for (int i = 0; i < N; i++)
    {
        cin>> val[i];
    }
    cin>> A >> B;
    for (int i = 0; i < N-1; i++)
    {
        ll soma = val[i];
        for (int j = i +1; j < N-1; j++)
        {
           soma += val[j+1];

           if(soma >= A && soma <= B)
           {
               ans++;
           }
        }
        
    }
      
    cout << ans <<endl;
    

    return 0;
}