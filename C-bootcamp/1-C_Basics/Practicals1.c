#include <stdio.h>

int main()
{
    // A) Asterisks Rectangle
    printf("**********\n**********\n**********\n**********\n**********\n\n");

    // B) Pattern
    printf("1*********\n12********\n123*******\n1234******\n12345*****\n\n");

    // C) X Shape
    printf("*   *\n * * \n  *  \n * * \n*   *\n\n");    // only 5 Col per line
    printf("*       *\n  *   * \n    *   \n  *   * \n*       *\n\n");

    // D) Print: Current Year - Age = Birth Year
    printf("We are in %d and I'm %d yo therefore I was born in %d \n\n", 2023, 27, 2023-27);
        // Hold on; this is not accurate cuz my age may change; should determine MONTHS aye!


    return 0;

}