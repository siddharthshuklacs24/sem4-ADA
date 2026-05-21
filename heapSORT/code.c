//heap sort using max heap
#include<stdio.h>


//a[]=array of numbers hat we want to sort 
//n=no of numbers in the array

void heapSort(int a[], int n);
void heapCons(int a[], int n);
void heapAdj(int a[], int n);


//1st function:heap sort
void  heapSort(int a[],int n) {
    heapCons(a,n);

    //keep switching first and last unsorted element and then stabilising
    for(int i=n-1;i>0;i--) {
         
        //switch
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;

        //stabilise
        heapAdj(a,i);
    }
}

//2nd function:heap construction(bottom to down approach) 
void heapCons(int a[],int n) {
    for(int i=1;i<n;i++) {
        //NEI=new element index
        //PI=parent index
        int NEI=i;
        int PI=(i-1)/2;
        //2 checks in while:new element>parent and we exclude the possibility that we at some point talk about the parent itself as the new element(to prevent out of bounds while shifting index up)
        while(NEI>0 && a[NEI]>a[PI]) { 

            //swap the values then shift indices up
            int temp=a[NEI];
            a[NEI]=a[PI];
            a[PI]=temp;

            //shift indices up
            NEI=PI;
            PI=(PI-1)/2;
        }

        }
    }

//3rd function:heap adjustment(top down approach)
void heapAdj(int a[],int n) {
    //PI=parent index
    //LCI=left child index
    int PI=0;
    int LCI=2*PI+1;
    //while left child exists
    while(LCI<=n-1) {
        //right child existence check
        int LARGERCI=LCI;
        if(LCI+1<=n-1) {
            //find larger child index
            LARGERCI=a[LCI]>a[LCI+1]?LCI:LCI+1;
        }

        //check if the larger child is larger than the parent
        if(a[LARGERCI]>a[PI]) {

            //swap 
            int temp=a[LARGERCI];
            a[LARGERCI]=a[PI];
            a[PI]=temp;

            //move indices downwards
            PI=LARGERCI;
            LCI=2*PI+1;
        }
        else {
            break;
        }
    }
}

void main() {
    printf("No of elements:");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("enter elements:");
        scanf("%d",&a[i]);
    }

    heapSort(a,n);
    printf("sorted heap:");
    for(int i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
}

