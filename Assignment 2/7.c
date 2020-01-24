#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define M 1000000

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

	char s[501];
	scanf("%s",s);
	int l = strlen(s);

	int ians =0;
	int jans =0;
	int c = 1;
	
	for(int i=0; i<l; i++){
		for(int j=i+1; j<l; j++){
			int flag = 0;
			for(int k = i; k<=j; k++){
				if(s[k] != s[j-k+i])
					flag = -1;
			}
			if(flag == 0 && (j-i+1)>c){
				c = j-i+1;
				ians = i;
				jans = j;
			}
		}
	}

	printf("%d\n",c);
	for(int i=ians; i<=jans; i++){
		printf("%c",s[i]);
	}
	return 0;
}