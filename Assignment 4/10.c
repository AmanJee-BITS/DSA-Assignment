#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long int
#define M 1000000000

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

	int q;

	scanf("%d", &q);

	while(q--){
		ll n;
		scanf ("%lld", &n);

		ll low = 0;
		ll high = M;

		while(low <= high) {
			ll mid = (low + high)/2;
			if (mid * mid > n) {
				high = mid -1;
			}
			else {
				low = mid + 1;
			}
		}
		printf("%lld\n", low-1);
	}

	return 0;
}