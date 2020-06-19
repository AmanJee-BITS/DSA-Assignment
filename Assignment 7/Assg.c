#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define int long long int

struct M_S_T {
	int f; 
	int d; 
	int e; 
};

void merge(int low, int mid, int high, struct M_S_T get[]) {

	struct M_S_T a1[mid-low+1];
	struct M_S_T a2[high-mid];
	struct M_S_T a3[high-low+1];

	for(int i = low; i <= mid; i++) {
		a1[i-low] = get[i];
	}

	for(int i = mid+1; i <= high; i++) {
		a2[i-mid-1] = get[i];
	}

	int x = 0, y = 0, z = 0;

	while(x < (mid - low + 1) && y < (high - mid)) {
		
		if(a1[x].f <= a2[y].f) {
			a3[z] = a1[x];
			z++;
			x++;
		}

		else {
			a3[z] = a2[y];
			z++;
			y++;
		}
	}

	while(x < (mid - low + 1)) { 
		a3[z] = a1[x];
		z++;
		x++;
	}

	while(y < (high - mid)) {
		a3[z] = a2[y];
		z++;
		y++;
	}

	for (int i = low; i <= high; i++) {
		get[i] = a3[i-low];
	}
}

void merge_sort(int low, int high, struct M_S_T get[]) {
	if(low == high) {
		return;
	}

	int mid = (low + high)/2;
	merge_sort(low, mid, get);
	merge_sort(mid+1, high, get);
	merge(low, mid, high, get);
}

void set(int a[], int n) {
	for(int i = 0; i < n; i++) {
		a[i] = i;
	}
}

int change(int j, int a[]) {
	while(j != a[j]) {
		a[j] = a[a[j]];
		j = a[j];
	}
	return j;
}

void match(int p, int q, int a[]) {
	int p1 = change(p, a);
	int q1 = change(q, a);
	a[p1] = a[q1];
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int N, M;
	scanf("%lld %lld", &N, &M);

	struct M_S_T get[M];

	for(int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		get[i].f = c;
		get[i].d = a;
		get[i].e = b;
	}

	merge_sort(0, M-1, get);
	int a[N];
	set(a, N);
	int ans = 0;

	for(int i = 0; i < M; i++) {
		if(change(get[i].d, a) != change(get[i].e, a)) {
			ans += get[i].f;
			match(get[i].d, get[i].e, a);
		}
	}
	
	printf("%lld", ans);
}