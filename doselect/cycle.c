#include <stdio.h>
#include<stdlib.h>

int main()
{
    // Declare the variable
    int a,i,b;
    
    // Read the variable from STDIN
    scanf("%d", &a);
    int *arr=(int*)malloc(a*sizeof(int));
    for(i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
        scanf("%d", &b);
    int temp;
    for(i=0;i<a;i++){
        if(arr[i]==b){
            temp=i;
            break;
        }
    }
    for(i=temp;i<a;i++){
        printf("%d\t",arr[i]);
    }
    for(i=0;i<temp;i++){
        printf("%d\t",arr[i]);
    }
    // Output the variable to STDOUT
    
    // Note that you need to explicitly return 0 in main() function,
    // otherwise your solution won't get accepted
    return 0;
}

