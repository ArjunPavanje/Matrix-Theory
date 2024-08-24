#include <stdio.h>

int main() {
    // Define the points
    int Ax = 1, Ay = 2;
    int Ox = 0, Oy = 0;
    int Bx = 2, By = 4;

    // Open the file for writing
    FILE *file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the points to the file
    fprintf(file, "A %d %d\n", Ax, Ay);
    fprintf(file, "O %d %d\n", Ox, Oy);
    fprintf(file, "B %d %d\n", Bx, By);

    // Close the file
    fclose(file);

    printf("Points written to file successfully.\n");
    return 0;
}

