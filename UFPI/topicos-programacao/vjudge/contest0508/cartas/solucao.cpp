#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, jg1, jg2;
    int jogadas = 0;
    int jogador = -1;

    deque<int> pilha1, pilha2;

    cin >> N;

    cin >> jg1;
    for (int i = 0; i < jg1; i++)
    {
        int c;
        cin >> c;
        pilha1.push_back(c);
    }
    cin >> jg2;
    for (int i = 0; i < jg2; i++)
    {
        int c;
        cin >> c;
        pilha2.push_back(c);
    }

    while(true){
        int c1 = pilha1.back();
        int c2 = pilha2.back();
        pilha1.pop_back();
        pilha2.pop_back();

        if(c1 > c2){
            pilha1.push_front(c1);
            pilha1.push_front(c2);
        }else{
            pilha2.push_front(c2);
            pilha2.push_front(c1);
        }

        jogadas++;

        if(pilha1.size() == 0){
            jogador = 2;
            break;
        }
        if(pilha2.size() == 0){
            jogador = 1;
            break;
        }

        if(jogadas > 100000000) {
            jogador = -1;
            break;
        }
    }
    

    if(jogador < 1){
        cout << jogadas << " " << jogador << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}
