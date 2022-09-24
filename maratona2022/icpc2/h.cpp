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

struct Player {
    int numero;
    int itens;

    Player(int x = 0, int y = 0) : numero(x), itens(y) {}
};


int main(int argc, char const *argv[]){
    optimize;
    int T, N;

    cin >> T;
    while(T--){
        queue<Player> players;
        players.push(Player(1, 2));
        players.push(Player(2, 1));
        players.push(Player(3, 2));
        players.push(Player(4, 1));

        string itens;
        cin >> N;
        cin >> itens;
        bool bobWinner = true;
        int jogada = 1;
        for (int i = 0; i < itens.size(); i++)
        {

            Player player = players.front();
            players.pop();
            int p = 0;
            bool eliminado = false;
            int temp = i;
            if(player.numero == 1){
                if(itens[i] == 'H'){
                    bobWinner = false;
                    break;
                }

                if(itens[i] == 'F'){
                    int s = itens.size() - (i + 1);
                    if(s == 1 && itens[i = 1] == 'F'){
                        bobWinner = true;
                        break;
                    }

                    if(s == 1 && itens[i = 1] == 'H'){
                        continue;
                    }

                }
            }
            while (p < player.itens){
                if(itens[i + p] == 'F'){
                    p++;
                    temp++;
                    continue;
                }else {
                    eliminado = true;
                    temp++;
                    break;
                }
            }

            i += temp;

            if(player.numero == 4){
                player.itens = player.itens == 1 ? 2 : 1;
            }

            if(!eliminado) {
                players.push(player);
            }
        }

        if(!bobWinner){
            if(players.back().numero == 1){
                bobWinner = true;
            }
        }

        cout << (bobWinner ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        
    }

    return 0;

}
