#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;
    int N;
    cin >> N;

    int  balls[N];
    
    for (int i = 0; i < N; i++)
    {
        cin >> balls[i];
    }

    int v = N - 1, line[N - 1];
    while (v > 0)
    {
      for (int i = 0; i < v; i++)
      {
        if(balls[i] != balls[i+1]){
            line[i] = -1;
        }else{
            line[i] = 1;
        }
      }

      for (int i = 0; i < v; i++)
      {
        balls[i] = line[i];
      }

      v--;
    }

    cout << (balls[0] < 0 ? "branca" : "preta") << endl;
    
    return 0;
}