#pragma once
//https://www.hackerrank.com/contests/world-codesprint-10/challenges/node-point-mappings

const int N = 1010;

vector <int> g[N];
int sz[N];
int x[N], y[N];
int ans[N];

void dfs(int v, int pr) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u == pr) {
			continue;
		}
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int xs, ys;

inline bool cmp(int i, int j) {
	int xi = x[i] - xs;
	int yi = y[i] - ys;
	int xj = x[j] - xs;
	int yj = y[j] - ys;
	return (xi * yj > xj * yi);
}

void solve(int v, int pr, vector <int> &a) {
	int low = a[0];
	for (int i : a) {
		if (y[i] < y[low] || (y[i] == y[low] && x[i] < x[low])) {
			low = i;
		}
	}
	ans[v] = low;
	a.erase(find(a.begin(), a.end(), low));
	xs = x[low];
	ys = y[low];
	sort(a.begin(), a.end(), cmp);
	for (auto u : g[v]) {
		if (u == pr) {
			continue;
		}
		vector <int> b;
		for (int j = 0; j < sz[u]; j++) {
			b.push_back(a.back());
			a.pop_back();
		}
		solve(u, v, b);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", x + i, y + i);
	}
	dfs(0, -1);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	solve(0, -1, a);
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			putchar(' ');
		}
		printf("%d", ans[i] + 1);
	}
	printf("\n");
	return 0;
}