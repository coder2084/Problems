#pragma once
//https://www.hackerrank.com/contests/world-codesprint-10/challenges/maximum-disjoint-subtree-product

using namespace std;

const long long inf = (long long) 1e18;

const int N = 1234567;

vector <int> gr[N];
long long f[N], g[N];
int cost[N];
long long ans;

void dfs(int v, int pr) {
	f[v] = cost[v];
	g[v] = -inf;
	for (int u : gr[v]) {
		if (u == pr) {
			continue;
		}
		dfs(u, v);
		f[v] += max(0LL, f[u]);
		g[v] = max(g[v], g[u]);
	}
	g[v] = max(g[v], f[v]);
}

void solve(int v, int pr, long long upf, long long upg) {
	if (pr != -1) {
		ans = max(ans, g[v] * upg);
	}
	vector <int> children;
	for (int u : gr[v]) {
		if (u == pr) {
			continue;
		}
		children.push_back(u);
	}
	long long total_f = cost[v];
	total_f += max(0LL, upf);
	for (int u : children) {
		total_f += max(0LL, f[u]);
	}
	long long g1 = -inf, g2 = -inf;
	for (int u : children) {
		if (g[u] > g1) {
			g2 = g1;
			g1 = g[u];
			continue;
		}
		if (g[u] > g2) {
			g2 = g[u];
		}
	}
	for (int u : children) {
		long long new_upf = total_f - max(0LL, f[u]);
		long long new_upg = max(upg, g1 == g[u] ? g2 : g1);
		new_upg = max(new_upg, new_upf);
		solve(u, v, new_upf, new_upg);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", cost + i);
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	ans = -inf;
	for (int it = 0; it < 2; it++) {
		dfs(0, -1);
		solve(0, -1, 0, 0);
		for (int i = 0; i < n; i++) {
			cost[i] = -cost[i];
		}
	}
	cout << ans << endl;
	return 0;
}
