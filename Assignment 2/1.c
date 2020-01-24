#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

  struct Node {
  	int num;
  	struct Node * next;
  	struct Node * prev;
  };

  struct Node * head = NULL;
  struct Node * tail = NULL;

  void printList(){
  	struct Node * temp = head;
  	while(temp != NULL){
  		printf("%d ",temp->num);
  		temp = temp->next;
  	}
  	printf("\n");
  }

  void insertBeg (int n){
  	struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
  	temp->num = n;
  	temp->next = head;
  	temp->prev = NULL;
  	head = temp;
  	if(tail == NULL){
  		tail = temp;
  	}
  }

  void insertEnd (int n){
  	struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
  	temp->num = n;
  	temp->next = NULL;
  	temp->prev = tail;
  	if(tail != NULL)
  		tail->next = temp;
  	tail = temp;
  	if(head == NULL){
  		head = temp;
  	}
  }

int main(int argc, char const *argv[])
{	
	// std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int count = 0;
  while(1) {
  	int a;
  	char ch;
  	scanf("%d%c",&a,&ch);
  	insertEnd(a);
  	count++;
  	if(ch == '\n')
  		break;
  }
  int n;
  char c;
  scanf("%d %c",&n,&c);
  n = n%count;
  // printf("%d\n",n);

  if (c == 'R') {
        struct Node * temp = tail;
        for (int x=0; x<n-1; x++) {
            temp = temp->prev;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        tail->next = head;
        head = temp;
        printList();
    } 
    else {
        struct Node * temp = head;
        for (int x=0; x<n-1; x++) {
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        printList();
    }

return 0;
}