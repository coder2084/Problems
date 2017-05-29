#pragma once

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

//
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

//modular multiplicative inverse
//http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
inline int inv(int x) {
	return power(x, md - 2);
}

// computes nCk
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
