#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[500];

void merge( int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
   
    int L[n1], R[n2]; 
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort( int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 

        mergeSort( l, m); 
        mergeSort( m+1, r); 
        merge( l, m, r); 
    } 
} 

int main()
{   

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  scanf("%d", &n);
  for(int x=0; x<n; x++){
    scanf("%d", &arr[x]);
  }

  mergeSort(0,n-1);

  // for (int i = 0; i < n; ++i)
  // {
  //   printf("%d ",arr[i]);
  // }

  // printf("\n");

  int r = n/2;
  int c1 = 0, c2=0;

  for(int x=0; x<n; x++){
    if(arr[x] == arr[r])
        c1++;
    if(arr[x] == arr[r-1])
        c2++;
  }

  if(c1 >= (n+1)/2)
    printf("%d",arr[r]);
  else if(c2 >= (n+1)/2)
    printf("%d",arr[r-1]);
  else
    printf("NO MAJORITY ELEMENT");

  printf("\n");
    
return 0;
}







