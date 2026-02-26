#include<stdio.h>
#include<stdbool.h>
int main() {
    int arr[]={1,2,3,4,5,6753,5426,78};
    printf("enter target:");
    int target;
    scanf("%d",&target);
    bool found=false;
    int length=sizeof(arr)/sizeof(0);
    int i;
    for( i=0;i<length;i++) {
        if(arr[i]==target) {
            found=1;
            break;
        }


    }
    if(found) {
        printf("target found at index %d",i);
    }
    else {
        printf("target not found");
    }

}

