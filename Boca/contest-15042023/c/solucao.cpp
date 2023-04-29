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

int sub(int num){
    return num <= 0 ? INT32_MAX : num;
}

struct Coord {
    int x, y;

    Coord(int x, int y, int p, int v) : x(x), y(y) {}

    bool operator < (const Coord &c) const
    {
        return c.x > x && c.y > y;
    }
};

int main(int argc, char const *argv[]){
    optimize;

    ll n, m, k;

    cin >> n >> m >> k;

    vector<Coord> coords;

    if(k >= (n * m) ){
        cout << -1 << endl;
    } else {

        while(k--){
            int x, y;

            cin >> x >> y;

            Coord coord(x, y, 0, 0);

            coords.push_back(coord);
        }

        sort(ALL(coords));

        int tamanho = INT32_MAX;
        
        for (int i = 0; i < coords.size(); i++)
        {
            int minPared =  min({sub(n - coords[i].x), sub(n - (n - coords[i].x + 1)), sub(m - coords[i].y), sub(m - (m - coords[i].y + 1))});
            int minVisinho = 2147483647;
            if(i != coords.size() - 1){
                int linha = (coords[i + 1].x - coords[i].x) - 1;
                int coluna = (coords[i + 1].y - coords[i].y) - 1;

                minVisinho = min(sub(linha), sub(coluna));
            }

            tamanho = min({tamanho, minPared, minVisinho});
        }

        cout << tamanho << endl;
    }
        
        return 0;
}