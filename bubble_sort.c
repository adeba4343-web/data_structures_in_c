#include<stdio.h>

int main(){
    int n,i,j,a[100],temp;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The unsorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The sorted array(using bubble sort):\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
