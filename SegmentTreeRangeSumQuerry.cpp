#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ff          first
#define ss          second
#define int         long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector <int>
#define mii         map <int,int>
#define mxhi        priority_queue<int>
#define mnhi        priority_queue<int,vi,greater<int> >
#define mod         1000000007
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)   //no of zero bits befor the first set bits
#define inf         1e18
#define ps(x,y)     fixed<<setprecision(y)<<x
#define w(x)        int x; cin>>x; while(x--)
#define endl        '\n'
int fp(int a, int n)
{
	int ans = 1;
	while (n > 0)
	{
		bool lb = n & 1;
		if (lb)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n = n >> 1;
	}
	return ans;
}
int countSetBits(int x)
{
	int count = 0;
	while (x)
	{
		x &= (x - 1);
		count++;
	}
	return count;
}
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        PBDS;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
void i_n()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct segtree {
	int size;
	vi sums;

	void init(int n) {
		size = 1;
		while (size < n) {
			size *= 2;
		}
		sums.assign(2 * size, 0);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(int i, int v) {
		return set(i, v, 0, 0, size);
	}

	void build(vi &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void build(vi &a) {
		build (a, 0, 0, size);
	}

	int sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r or l >= rx) return 0;
		if (lx >= l and rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		return sum(l , r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
	}
	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};
main() {
	i_n();
	segtree st;
	int n, m;
	cin >> n >> m;
	st.init(n);
	vi a(n);
	// for (int i = 0; i < n; i++) {
	// 	int i ,v;
	// 	cin >> i >> v;
	// 	set(i, v);
	// }
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	st.build(a);

	for (int i = 0; i < m; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << endl;
		}
	}
}
