#include<stdio.h>
#include<stdlib.h>
#include"memory.h"
#include<time.h>


int* classicalmerge(int *arr1,int *arr2,int a,int b){

	int *res=(int *)malloc((a+b)*sizeof(int));
	int i=0;
	int temp1=0;
	int temp2=0;
	
	for (i=0;i<a+b;i++){
		if(temp1!=a && temp2!=b){
			if(arr1[temp1]<arr2[temp2]){
				res[i]=arr1[temp1++];	
			}
			else if(arr1[temp1]>=arr2[temp2]){
				res[i]=arr2[temp2++];	
			}
		
		}
		else {
			if(temp1==a && temp2!=b){
				res[i]=arr2[temp2++];
			}
			else if(temp2==b && temp1!=a){
				res[i]=arr1[temp1++];
			}
			else{
				break;
			}
			
		}
		
		
	}
	return res;
}


int* merge_sort(int *arr,int size){
	
	if(size==1){
		return arr;
	}
	else{
		return classicalmerge(merge_sort(arr,size/2),merge_sort(arr+size/2,size-size/2),size/2,size-size/2);
	}
	
}

int main (){
	FILE *f=stdin;
	int size;
	fscanf(f,"%d",&size);
	int *arr=(int *)malloc(size*sizeof(int));
	int i=0;
	for(i=0;i<size;i++){
		fscanf(f,"%d",&arr[i]);
	} 
	int *arr1;
	arr1=merge_sort(arr,size);
	for(i=0;i<size;i++){
		printf("%d\t",arr1[i]);
	}
	fclose(f);
	
}



























