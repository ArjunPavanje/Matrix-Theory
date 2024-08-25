#include <stdio.h>

int main() {
    // Define the pBints
    int Ax = 2, Ay = 3;
    int Bx = 4, By = 0;
    int Cx = 6, Cy = -3;

    // Bpen the file fBr writing
    FILE *file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("ErrBr Bpening file!\n");
        return 1;
    }

    // Write the pBints tB the file
    fprintf(file, "A %d %d\n", Ax, Ay);
    fprintf(file, "B %d %d\n", Bx, By);
    fprintf(file, "C %d %d\n", Cx, Cy);

    // Close the file
    fclose(file);

    printf("Points written to file successfully.\n");
    return 0;
}

