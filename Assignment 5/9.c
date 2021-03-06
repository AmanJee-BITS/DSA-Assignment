#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int ar[100000];

void merge(int ar[], int l, int mid, int h){
    int ar1[mid-l+1];
    int ar2[h-mid];
    int ar3[h-l+1];

    for(int x=l; x<=mid; x++){
        ar1[x-l] = ar[x]; 
    }

    for(int x=mid+1; x<=h; x++){
        ar2[x-mid-1] = ar[x];
    }

    int i=0, j=0, k=0;

    while( i <= (mid-l) && j <= (h-mid-1)){
        if (ar1[i] <= ar2[j]){
            ar3[k] = ar1[i];
            k++;
            i++;
        }
        else {
            ar3[k] = ar2[j];
            k++;
            j++;
        }
    }

    while (i <= (mid-l)){
        ar3[k] = ar1[i];
        k++;
        i++;
    }

    while (j <= (h-mid-1)){
        ar3[k] = ar2[j];
        k++;
        j++;
    }

    for(int x=l; x<=h; x++){
        ar[x] = ar3[x-l];
    }
}

void merge_sort(int ar[], int l, int h){
    if (l >= h){
        return;
    }

    int mid = (l+h)/2;
    merge_sort(ar, l, mid);
    merge_sort(ar, mid+1, h);
    merge(ar, l, mid, h);
} 

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int ar[n];
    for(int x =0; x<n; x++){
        scanf("%d", &ar[x]);
    }

    merge_sort(ar, 0, n-1);

    int r;
    scanf("%d", &r);

    int i = 0;
    int j = n-1;

    int ansl, ansh;
    int min = 1000;

    while(i < j){
        int s = ar[i] + ar[j];
        if (s == r){
            if (ar[j] - ar[i] <= min){
                ansl = i;
                ansh = j;
                min = ar[j] - ar[i];
            }
            i++;
            j++;
        }
        else if (s < r){
            i++;
        }
        else {
            j--;
        }
    }
    if(min != 1000){
        printf("YES\n%d %d\n",ar[ansl], ar[ansh]);
    }
    else
        printf("NO\n");
	return 0;
}