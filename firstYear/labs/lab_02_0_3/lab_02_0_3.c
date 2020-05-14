#include <stdio.h>
#include <math.h> 
#define R_RT 0
#define R_WG 1

double func_exact_value(double x)
{
    return (exp(x));
}

double func_approx_value(double x, double eps)
{
    double value = 0;
    double el = 1;
    double fact = 1;

    while (fabs(el) > eps)
    {
        value += el;
        el = (el * x) / fact;
        fact += 1;
    }

    return value;
}

double func_abs_error(double ex_val, double app_val)
{
    return fabs(ex_val - app_val);
}

double func_rel_error(double abs_err, double app_val)
{
    return fabs(abs_err / app_val);
}

int main(void)
{
    double x;
    double eps;
    double exact_value, approx_value, abs_error, rel_error;
    int rc;

    rc = scanf("%lf %lf", &x, &eps);

    if ((rc == 2) && (eps > 0) && (eps < 1))
    {
        exact_value = func_exact_value(x);
        approx_value = func_approx_value(x, eps);
        abs_error = func_abs_error(exact_value, approx_value);
        rel_error = func_rel_error(abs_error, approx_value);	

        printf("Approximate value = %f\n", approx_value);
        printf("Exact value = %f\n", exact_value);
        printf("Absolute value = %f\n", abs_error);
        printf("Relative value = %f\n", rel_error);

        return R_RT;
    }

    return R_WG;
}
