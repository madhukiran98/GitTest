#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mypow(int base,int index){
	int i=0;
	int result=1;
	for(i=0;i<index;i++){
		result=result*base;
	}
	return result;
}

int main(){
	FILE *f=stdin;
	int T,i=0,z,K,B,result=0,j,tempa;
	char *str,par;
	char charater='a';
	int *arr;
	fscanf(f,"%d",&T);
	while(z<T){
		fscanf(f,"%d",&K);
		str=(char*)malloc((11)*sizeof(char));
		arr=(int*)malloc((K+1)*sizeof(int));
		
		fscanf(f,"%d",&B);
		for(i=0;i<K;i++){
			fscanf(f,"%d",&tempa);
			arr[i]=mypow(B,tempa);
		}
		for(i=0;i<K;i++){
			if(i!=0){
			fscanf(f,"%c",&par);
			if(par=='\n'){
				break;
			}
				
				printf("+");
			}
			fscanf(f,"%s",str);
			result=0;
			for(j=0;j<strlen(str);j++){
				result=result+((int)str[j]-(int)charater+1)*arr[j];	
			}
			printf("%d",result);
			
		}
		printf("\n");
		z++;
	}
	fclose(f);
	return 0;
}
