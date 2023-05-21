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

inline int binarySearch(int* nums, int inicio, int fim, int busca){
    int ans = -1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if(nums[meio] >= busca){
            ans = meio;
            fim = meio - 1;
        }else {
            inicio = meio + 1;
        }
    }

    if(nums[ans] != busca && ans != -1)
        return -1;
    
    return ans;
    
}

int main(int argc, char const *argv[]){
    // optimize;

    int N, Q;

    // cin >> N  >> Q;

    scanf("%d %d", &N, &Q);

    int nums[N];

        // cin >> nums[i];
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);

    while (Q--)
    {
        int x;
        // cin >> x;
        scanf("%d", &x);

        // cout << binarySearch(nums, 0, N - 1, x) << endl;
        printf("%d\n", binarySearch(nums, 0, N - 1, x));
    }
    
    return 0;
}