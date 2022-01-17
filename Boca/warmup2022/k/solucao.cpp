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
    int N, A, B;
    double res = 1;
    
    cin >> N >> A >> B;
    int L = (B - A) + 1;
    int i = 1;
    int salve = N;
    while(i <= B){
        res += (1/L) * N - i;
        N = N - i;
        if(N == 0){
            i++;
            N = salve;
        }
    }

    cout << ((L/(L-1)) * res) << endl;

    

    return 0;
}