#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void bubbleSort_inc(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

void bubbleSort_dec(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] < arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  


int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  long long int n;
  scanf("%lld", &n);

  int count = 0,i;
  int a[1000000];
  int b[1000000];
  int r[1000000];

  while(n!=0){
  	int y = n % 10;
  	n = n/10;
  	a[i] = y;
  	b[i] = y;
  	i++;
  	count++;
  }

  bubbleSort_inc(a,count);

  // for (i = 0; i < count; i++)
  // {
  // 	printf("%d ", a[i]);
  // }
  // printf("\n");

  bubbleSort_dec(b,count);

  //  for (i = 0; i < count; i++)
  // {
  // 	printf("%d ", b[i]);
  // }
  //   printf("\n");
    
    for (i = 0; i < count; i++)
  {
  	if(a[0] == 0){
  		for(int j = 1; j<count; j++){
  			if(a[j] != 0)
  				{
  					a[0] = a[j];
  					a[j] = 0;
  					break;
  				}
  				
  		}
  	}
  }

  // for (i = 0; i < count; i++)
  // {
  // 	printf("%d ", a[i]);
  // }
  // printf("\n");
  int carry = 0;

  for(i = count -1; i>=0; i--){
    int se = b[i] - a[i] + carry;
  	if(se < 0){
 	 	r[i] = 10 + se;
 	 	carry = -1;
  }
  else{
     
  	r[i] = se;
  	 carry = 0;
  	
  }
}

for(i = 0; i<count; i++){
	printf("%d",r[i]);
}

return 0;
}