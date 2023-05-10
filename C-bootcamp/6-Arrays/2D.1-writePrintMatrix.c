#include <stdio.h>

int main(){

    int matrix[3][3];
    int i,j;

        // 1. Write the matrix
    for (i=0; i<3; i++){
        
        printf("Write ROW n.%d \n", i+1);
        for (j=0; j<3; j++){
            printf("- Write value n.%d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

        // 2. Print the matrix
    for (i=0; i<3; i++){

        for (j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}







/* PROTOTYPE 2

#include <stdio.h>

int main(){


    int mat[3][3];
    int i;

    // Activate loop until matrix is complete (not automated)
    for (i=0; mat[3][3]!=0; i++){

        // First fill row 0
        printf("Fill row %d: \n", i+1);
        for (i=0; i<3; i++){
            printf("Enter numbers for column %d: ", i+1);
            scanf("%d", &mat[0][i]);
            printf("%d \n", mat[0][i]);
        }


        // Now fill row 1
        printf("Fill row %d: \n", i+1);
        for (i=0; i<3; i++){
            printf("Enter numbers for column %d: ", i+1);
            scanf("%d", &mat[1][i]);
            printf("%d \n", mat[1][i]);
        }


    }

    return 0;
}





PROTOTYPE 1
#include <stdio.h>

int main(){

    int mat[3][3];
    int i;

    printf("Enter numbers for row %d: ", i+1);
    for (i=0; i<3; i++){
        printf("Enter numbers for row %d: ", i+1);
        scanf("%d", &mat[0][i]);
        printf("%d \", mat[0][i]);
    }

    return 0;
}
*/
