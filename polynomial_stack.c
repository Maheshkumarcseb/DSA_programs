#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k++] = poly2[j++];
        } else {
            result[k].exponent = poly1[i].exponent;
            result[k++].coefficient = poly1[i++].coefficient + poly2[j++].coefficient;
        }
    }

    // Copy remaining terms from the first polynomial
    while (i < size1) {
        result[k++] = poly1[i++];
    }

    // Copy remaining terms from the second polynomial
    while (j < size2) {
        result[k++] = poly2[j++];
    }

    *sizeResult = k;
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i < size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    // Example polynomials
    struct Term poly1[] = {{3, 4}, {2, 3}, {5, 1}, {4, 0}};
    int size1 = sizeof(poly1) / sizeof(poly1[0]);

    struct Term poly2[] = {{1, 3}, {3, 2}, {2, 1}, {6, 0}};
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    // Resultant polynomial
    struct Term result[100];
    int sizeResult = 0;

    // Add polynomials
    addPolynomials(poly1, size1, poly2, size2, result, &sizeResult);

    // Display polynomials and result
    printf("Polynomial 1: ");
    displayPolynomial(poly1, size1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, size2);

    printf("Sum: ");
    displayPolynomial(result, sizeResult);

    return 0;
}