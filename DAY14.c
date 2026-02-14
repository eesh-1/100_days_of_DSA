#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[100][100];
    int isIdentity = 1;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(i == j && matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }

            if(i != j && matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if(isIdentity == 0)
            break;
    }

    if(isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
