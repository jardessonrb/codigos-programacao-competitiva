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

    int T, D, M;

    cin >> T >> D >> M;
    vector<int> ref(M);

    for (int i = 0; i < M; i++)
    {
        cin >> ref[i];
    }

    bool flag = false;
    if(M != 0 and D >= T){
        if(ref[0]+1 > T){
            flag = true;
        }else{
            int resto = 0;
            for (int i = 0; i < M; i++)
            {
                resto = D - ref[i];

                if((i == M - 1) and resto >= T){
                    flag = true;
                    break;
                }

                if(((i != M - 1)) and (ref[i] + T) <= ref[i+1]){
                    flag = true;
                    break;
                }
            }        
        }
    }else if(M == 0 and D >= T){
        flag = true;
    }else if(D < T){
        flag = false;
    }
    
    cout << (flag ? "Y" : "N")  << endl;
    
    return 0;
}