#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int ele;
	struct node *next;
}node;
void traverse(node *n,int N){
	int i=1;
	while(n->next !=NULL){
		n=n->next;
		i++;
		if(i>N){
			printf("ring topology\n");
			return;
		}
	}
	if(i==N){
		printf("line topology\n");
		return;
	}
	printf("unknown topology\n");
	return;
}
int main(){
	int M,N;
	scanf("%d",&N);
	scanf("%d",&M);
	node *n=(node*)malloc(N*(sizeof(node)));
	int i;
	for(i=0;i<N;i++){
		n[i].ele=i+1;
	}
	int z=0;
	node *temp;
	int n1,n2;
	for(i=0;i<M;i++){
		scanf("%d",&n1);
		scanf("%d",&n2);
		if(n[n1-1].next == NULL){
			z++;
		}
		n[n1-1].next=&n[n2-1];
	}
	if(z==1){
		printf("star topology\n");
		return 0;
	}
	traverse(&n[0],N);
	return 0;
}

