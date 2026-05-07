#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

int getMobile(int perm[], int dir[], int n) {

    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        if(dir[perm[i]] == LEFT && i != 0) {

            if(perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        if(dir[perm[i]] == RIGHT && i != n - 1) {

            if(perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

int main() {

    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int perm[n];
    int dir[n + 1];

    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    for(int i = 1; i <= n; i++) {
        dir[i] = LEFT;
    }

    printf("Permutations:\n");

    printPermutation(perm, n);

    while(1) {

        int mobileIndex = getMobile(perm, dir, n);

        if(mobileIndex == -1)
            break;

        int mobile = perm[mobileIndex];

        // Swap according to direction
        if(dir[mobile] == LEFT) {

            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex - 1];
            perm[mobileIndex - 1] = temp;

            mobileIndex--;
        }
        else {

            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex + 1];
            perm[mobileIndex + 1] = temp;

            mobileIndex++;
        }

        // Reverse direction of larger elements
        for(int i = 0; i < n; i++) {
            if(perm[i] > mobile) {
                dir[perm[i]] *= -1;
            }
        }

        printPermutation(perm, n);
    }

    return 0;
}
