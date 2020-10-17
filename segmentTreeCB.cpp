#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define rep(i,a,b)  for(int i = a; i < b; i++)
#define Rep(i,a,b)  for(int i = a; i <= b; i++)
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


//*****************************************************************************


void buildTree(int *arr, int s, int e, int *tree, int idx) {
	//Base Case
	if (s == e) {
		tree[idx] = arr[s];
		return;
	}
	//Recursive Case
	int mid  = s + (e - s) / 2;
	buildTree(arr, s, mid, tree, 2 * idx);
	buildTree(arr, mid + 1, e, tree, 2 * idx + 1);
	// current node
	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}


int query(int *tree, int s, int e, int qs, int qe, int idx) {
	//Complete Overlap
	if (s >= qs and e <= qe) {
		return tree[idx];
	}
	//No overlap
	if (s > qe or e < qs) {
		return INT_MAX;
	}
	//Partial overlap - call both sides and update the current ans
	int mid  = s + (e - s) / 2;
	int leftAns = query(tree, s, mid, qs, qe, 2 * idx);
	int rightAns = query(tree, mid + 1, e, qs, qe, 2 * idx + 1);
	int ans = min(leftAns, rightAns);
	return ans;
}


// index update
void updateNode(int *tree, int s, int e, int idx, int pos, int increment) {
	//No overlap
	if (s > pos or e < pos) {
		return;
	}
	//leaf node - to be updated
	if (s == e) {
		tree[idx] += increment;
		return;
	}
	//Partial overlap - left and right call
	int mid  = s + (e - s) / 2;
	updateNode(tree, s, mid, 2 * idx, pos, increment);
	updateNode(tree, mid + 1, e, 2 * idx + 1, pos, increment);
	//updating current node
	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}


// range update
void updateRange(int *tree, int s, int e, int l, int r, int idx, int increment) {
	//out of bound
	if (e < l or s > r) {
		return;
	}
	// leaf node
	if (s == e) {
		tree[idx] += increment;
		return;
	}
	// both - partial and complete overlap
	int mid = s + (e - s) / 2;
	updateRange(tree, s, mid, l, r, 2 * idx, increment);
	updateRange(tree, mid + 1, e, l, r, 2 * idx + 1, increment);

	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}


//***********************************  LAZY PROPAGATION *******************************************


// LAZY UPDATE
int lazy[100002];
void updateRangeLazy(int *tree, int s, int e, int l, int r, int idx, int increment) {
	//First step - never go doen if you have a lazy value at node,
	//first resolve it(update current node and pass lazy value to child nodes)
	if (lazy[idx] != 0) {
		tree[idx] += lazy[idx];
		// if not a leaf node
		if (s != e) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	// out of bounds
	if (s > r or e < l) {
		return;
	}
	//complete overlap
	if (s >= l and e <= r) {
		tree[idx] += increment;
		if (s != e) {
			lazy[2 * idx] += increment;
			lazy[2 * idx + 1] += increment;
		}
		return;
	}
	int mid = s + (e - s) / 2;
	updateRangeLazy(tree, s, mid, l, r, 2 * idx, increment);
	updateRangeLazy(tree, mid + 1, e, l, r, 2 * idx + 1, increment);
	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}


int queryLazy(int *tree, int s, int e, int qs, int qe, int idx) {
	//Resolve Lazy values
	if (lazy[idx] != 0) {
		tree[idx] += lazy[idx];
		// if not a leaf node
		if (s != e) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	//No overlap
	if (s > qe or e < qs) {
		return INT_MAX;
	}
	//Complete overlap
	if (s >= qs and e <= qe) {
		return tree[idx];
	}
	int mid = s + (e - s) / 2;
	int leftAns = queryLazy(tree, s, mid, qs, qe, 2 * idx);
	int rightAns = queryLazy(tree, mid + 1, e, qs, qe, 2 * idx + 1);
	return min(leftAns, rightAns);

}


// 0 based indexing for arr and 1 based for segment tree array

main() {

	i_n();
	int arr[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(arr) / sizeof(int);
	int *tree = new int[4 * n + 1];
	buildTree(arr, 0, n - 1, tree, 1);
	// Rep(i, 1, 13) {
	// 	cout << tree[i] << " ";
	// }
	// cout << endl;

	// int i, increment;
	// cin >> i >> increment;
	// updateNode(tree, 0, n - 1, 1, i, increment);
	// int lx, rx, increment;
	// cin >> lx >> rx >> increment;
	// updateRange(tree, 0, n - 1, lx, rx, 1, increment);
	int lx, rx, increment;
	cin >> lx >> rx >> increment;
	updateRangeLazy(tree, 0, n - 1, lx, rx, 1, increment);

	int l, r;
	cin >> l >> r;
	cout << queryLazy(tree, 0, n - 1, l, r, 1) << endl;
  
}
