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

struct Vez{
    int a, b;

    Vez(int a, int b): a(a), b(b) {};
};

int main(int argc, char const *argv[]){
    optimize;

    int T = 0, N;

    cin >> N;
    int a, b;
    int ant = -1;
    queue<Vez> aguarda;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;

        if(ant == -1){
            T = a + 10;
            ant = b;
        }else{
            if(b != ant){
                aguarda.push(Vez(a, b));
            }else{
                if(a < T){
                    T = a + 10;
                    ant = b;
                }else{
                    T = (a + 10 ) - 1;
                }
            }
        }

        
    }

    while(!aguarda.empty()){
        T += 10;
        aguarda.pop();
    }
    

    cout << T << endl;


    return 0;
}