#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100

using namespace std;

struct SegmentTree
{
	int *arvore;

	SegmentTree(int N = MAXN)
	{
		arvore = new int[N * 6];
		memset(arvore, 0, sizeof arvore);
	}

	void build(int no, int l, int r, string &S)
	{	
		if(l > r) return;
		if(l == r)
		{
			arvore[no] = (1 << (S[l - 1] - 'a'));
			return;
		}

		int e = 2 * no;
		int d = e + 1;
		int m = (l + r) >> 1;
		build(e, l    , m, S);
		build(d, m + 1, r, S);

		arvore[no] = (arvore[e] | arvore[d]);
	}

	void update(int no, int l, int r, int pos, int i)
	{
		//Fora do intervalo...
		if(pos < l || pos > r || l > r) return;
		if(l == r)
		{
			//liga o i-esimo bit...
			arvore[no] = (1 << i);
			return;
		}


		int e = 2 * no;
		int d = e + 1;
		int m = (l + r) >> 1;
		update(e, l, m, pos, i);
		update(d, m + 1, r, pos, i);

		arvore[no] = (arvore[e] | arvore[d]);
	}


	int query(int no, int l, int r, int a, int b)
	{
		if(l > r || b < l || a > r) return 0;
		if(a <= l && r <= b) return arvore[no];

		int e = 2 * no;
		int d = e + 1;
		int m = (l + r) >> 1;

		return (query(e, l, m, a, b) | query(d, m + 1, r, a, b));
	}
};

SegmentTree seg;

int main(int argc, char const *argv[])
{
	optimize;

	int N, Q, op, pos, l, r;

	string S;

	cin >> S;

	N = S.length();

	seg.build(1, 1, N, S);

	cin >> Q;

	char c;

	while(Q--)
	{
		cin >> op;

		if(op == 1)
		{
			cin >> pos >> c;

			seg.update(1, 1, N, pos, c - 'a');
		}
		else
		{
			cin >> l >> r;

			cout << __builtin_popcount(seg.query(1, 1, N, l, r)) << endl;
		}
	}

	return 0;
}