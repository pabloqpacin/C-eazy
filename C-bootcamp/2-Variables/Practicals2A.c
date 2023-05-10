#include <stdio.h>

// [ a1=2.5 | a2=5 | a3=7.5 | d=2.5 | n=15 | an=? | Sn=? ]

int main(){

    // 1. n-th of Arithmetic Sequence
    double a1, d, an;
    int n;
    
    printf("Enter the Initial Term (a1): ");
    scanf("%lf", &a1);

    printf("Enter the Total number of elements (n): ");
    scanf("%d", &n);

    printf("Enter the Difference in in Arithmetic Sequence (d): ");
    scanf("%lf", &d);

    an = a1 + (n - 1) * d;
    printf("\nThe n-th (an) Term of your Arithmetic Sequence is %.2lf \n", an);

    // 2. Sum of Arithmetic Sequence
    double Sn = (a1+an) * n / 2;
    printf("The Sum (Sn) of your Arithmetic Sequence is %.2lf \n\n", Sn);

    // 3. Employee Salary Calculation
    double hourSalary, monthHours;
    printf("Salary [€/hour]: ");
    scanf("%lf", &hourSalary);
    printf("Hours worked per month: ");
    scanf("%lf", &monthHours);

    double monthSalary = hourSalary * monthHours;
    printf("Salary per Month: %.2lf € \n\n", monthSalary);


    return 0;

}