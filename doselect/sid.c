#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bulb{
	char ele;
	int c;
}bulb;



void update(bulb *b,int num,FILE *f){
	int i;
	char *s=(char *)malloc(2*sizeof(char));
	//printf("%d,update\n",num);
	fscanf(f,"%s",s);
	char c=s[0];
	//printf("%d,update\n",num);
	for(i=0;i<num;i++){
		if(b[i].ele==c){
			if(b[i].c==0){
				b[i].c=1;
			}
			else{
				b[i].c=0;
			}
		}
	}
}

int check(bulb *b,int num,FILE *f){
	int start,stop,i;
	char *str=(char*)malloc(4*sizeof(char));

	fscanf(f,"%d",&start);
	fscanf(f,"%d",&stop);
	//printf("str=%d,stp=%d\n",start,stop);
	fscanf(f,"%s",str);
	//fscanf(f,"%d",&i);
	int con;
	if(strlen(str)==2){
		con=1;
	}
	else{
		con=0;
	}
	int ans=0;
	for(i=start-1;i<stop;i++){
		if(b[i].c==con){
			ans+=1;
		}
	}
	return ans;
}

int main(){
	int num,q,i;
	FILE *f=stdin;
	fscanf(f,"%d",&num);
	bulb *b=(bulb*)malloc((num)*sizeof(bulb));
	char *str=(char*)malloc(num*sizeof(char));
	fscanf(f,"%d",&q);
	fscanf(f,"%s",str);
	int *arr=(int *)malloc(q*sizeof(int));
	for(i=0;i<num;i++){
		b[i].ele=str[i];
		b[i].c=0;
		//printf("bulbno%d=ele-%c,c=%d\n",i,b[i].ele,b[i].c);
	}
	
	
	
	int temp;
	int j=0;
	for(i=0;i<q;i++){
		
		fscanf(f,"%d",&temp);
		//printf("-----------%d-temp\n",temp);

		switch(temp){
			case 1:
				//printf("going\n");
				update(b,num,f);
				//printf("coming\n");
				break;		
			case 2:
				arr[j]=check(b,num,f);
				j++;
				break;
			default:
				break;
		}
	}
	for(i=0;i<j;i++){
		printf("%d\n",arr[i]);
	}
	fclose(f);
	return 0;
	}
