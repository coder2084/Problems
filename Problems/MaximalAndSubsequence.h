#pragma once
//https://www.hackerrank.com/contests/world-codesprint-10/challenges/maximal-and-subsequences

const int md = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= md) {
		a -= md;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % md;
}

inline int power(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

inline int inv(int x) {
	return power(x, md - 2);
}

inline int C(int n, int k) {
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = mul(ans, i);
	}
	for (int i = 1; i <= k; i++) {
		ans = mul(ans, inv(i));
	}
	for (int i = 1; i <= n - k; i++) {
		ans = mul(ans, inv(i));
	}
	return ans;
}

const int N = 100010;

int n;
long long a[N];

int calc(long long z) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] & z) == z) {
			ans++;
		}
	}
	return ans;
}

int main() {
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	long long x = 0;
	for (int bit = 60; bit >= 0; bit--) {
		long long nx = x + (1LL << bit);
		if (calc(nx) >= k) {
			x = nx;
		}
	}
	printf("%lld\n", x);
	printf("%d\n", C(calc(x), k));
	return 0;
}