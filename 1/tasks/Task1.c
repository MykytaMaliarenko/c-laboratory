//
// Created by nam62 on 03.02.2020.
//
#include <stdio.h>
#include <math.h>

void CalculatePrismArea() {
    double a, b, h, area;

    printf("%s", "Input a:");
    scanf("%lf", &a);

    printf("%s", "Input b:");
    scanf("%lf", &b);

    printf("%s", "Input h:");
    scanf("%lf", &h);

    area = a * b + ((a + b + sqrt(a*a + b*b)) * h);
    printf("%s", "Result:");
    printf("%lf", area);
}

void CalculateParallelogramArea() {
    double a, h;

    printf("%s", "Input a:");
    scanf("%lf", &a);

    printf("%s", "Input h:");
    scanf("%lf", &h);

    printf("%s", "Result:");
    printf("%lf\n", a * h);
}