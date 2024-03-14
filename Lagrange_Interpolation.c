#include <stdio.h>
#include <math.h> // For handling division by zero

int main() {
    int n, i, j;
    float x, v = 0.0, dataPoints[10], fxValues[10], L[10];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Invalid number of points.\n");
        return 1;
    }

    printf("Enter the value of x: ");
    scanf("%f", &x);

    for (i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i=%d: ", i);
        scanf("%f%f", &dataPoints[i], &fxValues[i]);
    }

    for (i = 0; i < n; i++) {
        // Check for division by zero and handle it gracefully
        L[i] = 1.0;
        for (j = 0; j < n; j++) {
            if (i != j) {
                if (fabs(dataPoints[i] - dataPoints[j]) < 1e-6) {
                    // Handle coincidence: use corresponding fx value
                    L[i] = 1.0;
                } else {
                    L[i] *= (x - dataPoints[j]) / (dataPoints[i] - dataPoints[j]);
                }
            }
        }
        v += fxValues[i] * L[i];
    }

    printf("Interpolated value at x = %.2f: %.4f\n", x, v);

    return 0;
}
