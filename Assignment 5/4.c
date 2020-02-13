#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    scanf("%d %d", &n, &k);

    int ar[n];

    for(int x=0; x<n; x++){
    	scanf("%d", &ar[x]);
    }

    int count=0;

    for(int x=0; x < n-2; x++){
    	for(int j=x+2; j<n; j++){
    		if (ar[j] - ar[x] <= k){
    			count = count + j - x -1;
    		}
    	}
    }

    printf("%d\n", count);
    return 0;
}