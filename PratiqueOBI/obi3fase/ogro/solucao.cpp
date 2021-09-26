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
    string m1 = "", m2 = "";
    cin >> N;
    

    if(N == 0){
        cout << "*" << endl;
        cout << "*" << endl;
    }else if(N <= 5 and N != 0){
        for(int i = 0; i < N; i++){
            m1 += "I";
        }
        cout << m1 << endl;
        cout << "*" << endl;
    }else{
        for(int i = 0; i < 5; i++){
            m1 += "I";
        }
        int res = N - 5;
         for(int i = 0; i < res; i++){
            m2 += "I";
        }
        cout << m1 << endl;
        cout << m2 << endl;
    }

    return 0;
}