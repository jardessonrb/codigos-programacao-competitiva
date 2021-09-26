#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 2000020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int floors[MAXN], tree[4 * MAXN], N, Q;

void build(int no, int l, int r)
{
    //no é o primeiro nó, uma folha, l é o inicio, r é o final

    if(l == r)
    {
        //se l == r é por que é do tipo [1,1] que é uma folha e acabou
        tree[no] = floors[l];
        return;
    } 

    int filhoEsquerdo = (2 * no);
    int filhoDireito  = filhoEsquerdo + 1;
    int meioIntervalo         = (l + r)/2;

    //continuo com recursão p/ dar o build nos filhos

    build(filhoEsquerdo, l, meioIntervalo);
    build(filhoDireito, meioIntervalo + 1, r);

    //Junta as informações dos dois filhos, esquerdo e direito.
    //aqui que são feitas as operações de filho máximo, minimo as 4 operações
    
    tree[no] = tree[filhoEsquerdo] + tree[filhoDireito];
}

void update(int no, int l, int r, int floor, int valor)
{
    //floor == andar, e aqui vejo se ele está fora do intervalo;
    if(floor < l or floor > r) return;

    if(l == r)
    {
        tree[no] = valor;
        return;
    }

    int filhoE = (2 * no);
    int filhoD = filhoE + 1;
    int intervalo = (l + r)/2;

    //continuo a recursão em meus filhos
    update(filhoE, l, intervalo, floor, valor);
    update(filhoD, intervalo+1, r, floor, valor);

    //como atualizei um nó folha, tenho que atualizar minha arvore
    tree[no] = tree[filhoE] + tree[filhoD];

}

int query(int no, int l, int r, int a, int maxFloor)
{
    //Esse maxFloor, é o andar maximo que eu quero chegar somando do 1 a ele

    if(maxFloor < l or r < a) return 0;

    if(a <= l && r <= maxFloor) return tree[no];

    //agora eu vou pegar os filhos e o intevalo
    int e = 2 * no;
    int d = e + 1;
    int intervalo = (l + r)/2;


    return query(e, l, intervalo, a, maxFloor) + query(d, intervalo + 1, r, a, maxFloor);
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        cin >> floors[i];
    }

    build(1, 1, N);

    int K, P, opcao;
    while(Q--)
    {
        cin >> opcao;

        if(opcao == 0)
        {
            cin >> K >> P;

            update(1, 1, N, K, P);
            //O 1° 1 é o nó principal, que possui todos os outros
            //O 2° 1 é o inicio do vetor de segmentos, indexado no 1010
            //O N é o maior index de nó, que vai sempre de 1 a N;
            //K aí é o index que ele quer alterar, o P o valor

        }
        else
        {
            cin >> K;

            cout << query(1, 1, N, 1, K) << endl;
            //O 1° 1 é o nó principal
            //O 2° 1 é o inicio do vetor de segmentos, indexado no 1010
            //O N é o maior index de nó, que vai sempre de 1 a N;
            //O 3° 1 é o numero necessario para manter um intervalo de numeros
            //K aí é o index máximo que eu quero somar, ou seja, somar de 1 a K
        }

    }
    

    return 0;
}