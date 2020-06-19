#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define int long long int

void max_choco(int a[], int x, int N) {

	int start = 2*x;
	int end = 2*x + 1;
	int largest = x;

	if(start <= N && a[start] > a[x]) {
		largest = start;
	}

	if(end <= N && a[end] > a[largest]) {
		largest = end;
	}

	if(largest != x) {
		int temp = a[x];
		a[x] = a[largest];
		a[largest] = temp;
		max_choco(a, largest, N);
	}
}

void choco(int a[], int N) {
	for(int i = N/2; i >= 1; i--) {
		max_choco(a, i, N);
	}
}

int32_t fun(int a[], int N) {
	int rem = a[1];
	a[1] = rem/3;
	max_choco(a, 1, N);
	return rem;
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
	int n, d;
	scanf("%lld %lld", &n, &d);
	int a[n+1];

	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}

	choco(a, n);
	int res = 0;
	int mod = 1000000007;

	for(int i = 0; i < d; i++) {
		res = (res + fun(a, n)) % mod;
	}
	printf("%lld ", res);
}