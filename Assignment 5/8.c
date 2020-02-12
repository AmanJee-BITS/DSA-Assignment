#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n,m;
	scanf("%d %d", &n, &m);

	int ar[n][m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &ar[i][j]);
		}
	}

	int r;
	scanf("%d", &r);

	int loc_i = 0;
	int loc_j = 0;
	int c = 0;

	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if (ar[i][j] == r){
				c++;
				loc_i = i;
				loc_j = j;
				break;
			}
		}
	}

	if(c == 0)
		printf("MISSING\n");
	else
		printf("YES\n%d %d",loc_i, loc_j);
}