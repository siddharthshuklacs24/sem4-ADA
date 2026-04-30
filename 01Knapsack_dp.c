//this is 0/1 knapsack problem using dynamic programming
#include<stdio.h>

int max(int a,int b) {
   return  a>b? a:b;
}

//knapsack function-takes total capacity,weights and profits of all objects and total number of objects available

int knapsack(int CAP,int wt[],int profit[],int n) {
    int dp[n+1][CAP+1];//dp table has number of objects+1 rows and total capacity+1 columns

    //note:the rows represent no of objects taken and columns represent the capacity used 
    //dp[i][w]=maximum profit in taking 1st i items with capacity used w

    //for loop for considering all 4 cases possible when considering about taking an object or not:
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=CAP;j++) {

            //case 1:we have no item OR we have no capacity
            if(i==0 || j==0) {
                dp[i][j]=0;
            }

            //case 2:the item in consideration has more weight than the capacity
            else if(wt[i-1]>j) {
                dp[i][j]=dp[i-1][j];//dont take the item,ie keep the profit same as taking previous items
            }

            //case 3:the item in consideration has less weight than the total capacity
            else {
                //we have 2 possibilities:either dont take the item or take it,and we choose the one with maximum profit
                dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }

    //now return the optimal solution:maximum profit
    return dp[n][CAP];
}

int main() {
    printf("enter the no of objects:");
    int n;
    scanf("%d",&n);
    printf("enter the total capacity:");
    int CAP;
    scanf("%d",&CAP);
    printf("enter weights of value respectively:");
    int wt[n];
    int profit[n];

    //loop for inputting the weights and profits of all objects
    for(int i=0;i<n;i++) {
        printf("object %d:",i+1);
        scanf("%d %d",&wt[i],&profit[i]);
    }

    int max_profit;
    max_profit=knapsack(CAP,wt,profit,n);
    printf("maximum profit is:%d",max_profit);

    return 0;
}
