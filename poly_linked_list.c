#include <stdio.h>
#include <stdlib.h>

        // Structure to represent a term in a polynomial
struct Term {
    int coefficient;  
    int exponent;
    struct Term* next;
};

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* currentResult = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
        newTerm->next = NULL;

        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->exponent > poly2->exponent) {
                newTerm->coefficient = poly1->coefficient;
                newTerm->exponent = poly1->exponent;
                poly1 = poly1->next;
            } else if (poly1->exponent < poly2->exponent) {
                newTerm->coefficient = poly2->coefficient;
                newTerm->exponent = poly2->exponent;
                poly2 = poly2->next;
            } else {
                newTerm->coefficient = poly1->coefficient + poly2->coefficient;
                newTerm->exponent = poly1->exponent;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            newTerm->coefficient = poly1->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else {
            newTerm->coefficient = poly2->coefficient;
            newTerm->exponent = poly2->exponent;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = newTerm;
            currentResult = result;
        } else {
            currentResult->next = newTerm;
            currentResult = currentResult->next;
        }
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory allocated for a polynomial
void freePolynomial(struct Term* poly) {
    while (poly != NULL) {
        struct Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    // Example polynomials
    struct Term* poly1 = NULL;
    struct Term* term1 = (struct Term*)malloc(sizeof(struct Term));
    term1->coefficient = 3;
    term1->exponent = 3;
    term1->next = NULL;
    poly1 = term1;

    struct Term* term2 = (struct Term*)malloc(sizeof(struct Term));
    term2->coefficient = 2;
    term2->exponent = 2;
    term2->next = NULL;
    term1->next = term2;

    // poly1 represents 3x^3 + 2x^2

    struct Term* poly2 = NULL;
    struct Term* term3 = (struct Term*)malloc(sizeof(struct Term));
    term3->coefficient = 1;
    term3->exponent = 2;
    term3->next = NULL;
    poly2 = term3;

    struct Term* term4 = (struct Term*)malloc(sizeof(struct Term));
    term4->coefficient = 2;
    term4->exponent = 1;
    term4->next = NULL;
    term3->next = term4;

    struct Term* term5 = (struct Term*)malloc(sizeof(struct Term));
    term5->coefficient = 4;
    term5->exponent = 0;
    term5->next = NULL;
    term4->next = term5;

    // poly2 represents x^2 + 2x + 4

    // Add polynomials
    struct Term* result = addPolynomials(poly1, poly2);

    // Print result
    printf("Result: ");
    printPolynomial(result);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}