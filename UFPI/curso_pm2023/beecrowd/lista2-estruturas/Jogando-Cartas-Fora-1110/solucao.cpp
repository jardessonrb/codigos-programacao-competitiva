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
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;

    int N;
    while(true){
        cin >> N;
        if(N == 0) break;

        deque<int> cartas;
        for (int i = N; i >= 1; i--)
        {
            cartas.push_back(i);
        }

        if(cartas.size() == 1){
            cout << "Discarded cards: " << cartas.back() << endl;
            cout << "Remaining card: " << endl;
            continue;
        }else if(cartas.size() == 2){
            cout << "Discarded cards: " << cartas.back() << endl;
            cartas.pop_back();
            cout << "Remaining card: " << cartas.back() << endl;
            continue;
        }else {
            queue<int> discartadas;
            while(cartas.size() > 2){
                discartadas.push(cartas.back());
                cartas.pop_back();
                int valor = cartas.back();
                cartas.pop_back();
                cartas.push_front(valor);
            }
            discartadas.push(cartas.back()); 
            cartas.pop_back();
            cout << "Discarded cards: ";
            while(!discartadas.empty()){
                int valor = discartadas.front();
                discartadas.pop();
                cout << valor << (discartadas.size() > 0 ? ", " : "");
            }
            cout << endl;
            cout << "Remaining card: " << cartas.back() << endl;
        }
        
    }

    return 0;
}