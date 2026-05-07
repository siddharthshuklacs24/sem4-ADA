#include <stdio.h>

#define MAX 100

int main() {

    int n;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("Topological Order:\n");

    int processed = 0;

    while(processed < n) {

        int found = 0;

        for(int i = 0; i < n; i++) {

            // Source vertex
            if(indegree[i] == 0 && visited[i] == 0) {

                printf("%d ", i);

                visited[i] = 1;
                found = 1;
                processed++;

                // Remove outgoing edges
                for(int j = 0; j < n; j++) {

                    if(adj[i][j] == 1) {
                        indegree[j]--;
                    }
                }
            }
        }

        // Cycle detection
        if(!found) {
            printf("\nCycle detected. Topological ordering not possible.\n");
            return 0;
        }
    }

    return 0;
}
