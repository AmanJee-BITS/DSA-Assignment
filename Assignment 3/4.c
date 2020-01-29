#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{   

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  char a[1001];
  scanf("%s", a);

  int len_a = strlen(a);

  char w[1001];

  scanf("%s",w);

  int len_w = strlen(w);
  int count=0;

  for(int i=0; i <= len_a - len_w; i++){
    int c=0;

    for(int j=0; j < len_w; j++){
      if(a[i+j] != w[j])
        c++;
    }
    if(c <= 1)
      count++;
  }

  printf("%d\n", count);

return 0;
}







