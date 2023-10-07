#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXV 1010
#define ll long long
#define ld long double
#define pii pair<int, int>
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

const int MOD = 1e9 + 3;
const int base = 101;
const int MAXN = 2e5 + 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return nullptr;
    }
};


int main(int argc, char const *argv[])
{
    Solution solucao;

    ListNode list(1);
    for (int i = 0; i < 4; i++)
    {
       ListNode node(i);
       list.next = &node;
       list = node;
    }


    int cont = 0;
    ListNode vis;
    while (true)
    {
       cout << (list.val) << endl;
       vis = *list.next;

       if(&list == nullptr){
         break;
       }

    //    if(cont > 3) break;

    //    cont++;
    }
    
    

    return 0;
}
