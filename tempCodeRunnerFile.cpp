#include <stdio.h>

double f(double t, double y) {
    return t + y;
}

double rungeKutta(double t0, double y0, double h, double tn) {
    double k1, k2, k3, k4;
    double y = y0;

    for (double t = t0; t < tn; t += h) {
        k1 = h * f(t, y);
        k2 = h * f(t + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(t + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(t + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }

    return y;
}

int main() {
    double t0, y0, h, tn;

    printf("Enter initial value of t (t0): ");
    scanf("%lf", &t0);

    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter step size (h): ");
    scanf("%lf", &h);

    printf("Enter final value of t (tn): ");
    scanf("%lf", &tn);

    double result = rungeKutta(t0, y0, h, tn);

    printf("The approximate value of y at t = %.2lf is: %.6lf\n", tn, result);

    return 0;
}
