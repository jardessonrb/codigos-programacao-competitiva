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

//Achar X dentro do array

int main(int argc, char const *argv[]){
    optimize;
    int N, Q;

    cin >> N >> Q;
    vector<int> array(N);

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    while(Q--){
        int op;
        cin >> op;

        int l = 0;
        int r = N - 1;
        bool ok = false;
        while(r >= l){
            int c = (l + r) / 2;
            if(array[c] == op){
                ok = true;
                break;
            }
            if(array[c] > op){
                r = c - 1;
            }else{
                l = c + 1;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
    
    

    return 0;
}