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

int datas[4];
int hours;

int hoursCalc(int init, int finaly){
    if(init > finaly){
        return (24 * 60) - ((init - finaly));
    }else if(init < finaly){
        return finaly - init;
    }else{
        return 24 * 60;
    }
}

int main(int argc, char const *argv[]){
    optimize;

    for (int i = 0; i < 4; i++)
    {
        cin >> datas[i];
    }

    hours = hoursCalc((datas[0] * 60) + datas[1], (datas[2] * 60) + datas[3]);

    cout << "O JOGO DUROU "<< hours / 60 <<" HORA(S) E "<< hours % 60 <<" MINUTO(S)" << endl;

    return 0;
}