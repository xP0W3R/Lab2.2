#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comput_integral_trapez (double left_boundary_a, double right_boundary_b, unsigned int intervals);
double num_comput_integral_Simps (double left_boundary_a, double right_boundary_b, unsigned int intervals);
double integrand_expression( double x );

double integrand_expression( double x ) // основна функція
        {
            return (1+sqrt(x))/pow(x,2);
        }


int main() //інтерфейс
{
    double left_boundary_a=0, right_boundary_b=0;
    double measurement_error=0, I1=0, I2=0;
    int intervals, var, i;
    double integral_s=0;
    double par1 = 20;
    double par2 = 3;
    double min_variable;


while(1)
    {
    printf("\n\tEnter the left boundary \n X(first)=");
    scanf("%lf", &left_boundary_a);
    printf("\n\tEnter the right boundary \n X(last)=");
    scanf("%lf", &right_boundary_b);
    do{
            printf("\tEnter the number of partition intervals (N>0)\nN=");
            scanf("%u", &intervals);
      }
    while(intervals <= 0);

    do
    {
            printf("\n\tEnter the measurment error of integration\n Measurment error=");
            scanf("%lf", &measurement_error);
    }
    while(measurement_error >= 0.001 || measurement_error <= 0.00001);


    do {
        printf("\nChoose the method of calculating:\n");
        printf("\t1. By Left Rectangles :\n");
        printf("\t2. By Right Rectangles:\n");
        printf("\t3. By Trapezium method:\n");
        printf("\t4. By Simps's method (parabola method):\n");
        scanf("%u", &var);
        if (var!=1 && var!=2 &&var!=3 &&var!=4 )
            printf("\nYou are mistaken\n");
        }
    while (var!=1 &&var!=2 &&var!=3 &&var!=4 );

system("cls");
    switch(var)
      {
          case 1:
              {
                  integral_s = num_comput_integral_l_re(left_boundary_a, right_boundary_b, intervals);
                  printf("\n\n\t======*Left Rectangles method*======\n");
                  printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d\n\n",left_boundary_a, right_boundary_b, integral_s, intervals);
              }
          break;


          case 2:
              {
                  integral_s = num_comput_integral_l_re(left_boundary_a, right_boundary_b, intervals);
                  printf("\n\n\t======*Right Rectangles method*======\n");
                  printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d\n\n",left_boundary_a, right_boundary_b, integral_s, intervals);
              }
          break;


          case 3:
              {
                  integral_s = num_comput_integral_trapez(left_boundary_a, right_boundary_b, intervals);
                  printf("\n\n\t======*Trapezium method *======\n");
                  printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d\n\n",left_boundary_a, right_boundary_b, integral_s, intervals);
              }
          break;


          case 4:
              {
                  integral_s = num_comput_integral_Simps(left_boundary_a, right_boundary_b, intervals);
                  printf("\n\n\t======*Simps's method*======\n");
                  printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d\n\n",left_boundary_a, right_boundary_b, integral_s, intervals);
              }
          break;
            }
        return 0;
        }
}


double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)//метод лівих прямокутників
        {
            double integral_s=0, x=0, h;
            unsigned int i;
            h = (right_boundary_b - left_boundary_a) / intervals;
            x = left_boundary_a;
            for (i = 0; i < intervals; i++)
                {
                    x += h;
                    integral_s += integrand_expression(x);
                }
            return integral_s*h;
        }

double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)//метод правих прямокутників
        {
            double integral_s = 0, x = 0, h;
            unsigned int i;
            h = (right_boundary_b - left_boundary_a) / intervals;
            x = left_boundary_a + h;
            for (i = 0; i <= intervals; i++)
                {   x += h;
                    integral_s += integrand_expression(x);
                }
            return integral_s * h;

        }

double num_comput_integral_trapez (double left_boundary_a, double right_boundary_b, unsigned int intervals)//метод трапецій
        {
            double integral_s = 0, x = 0, h;
            unsigned int i;
            h = (right_boundary_b - left_boundary_a) / intervals;
            x = left_boundary_a + h;
            for (i = 0; i <= (intervals - 1); i++)
                {
                    x += h;
                    integral_s += (integrand_expression(x) + integrand_expression(x + h)) / 2;
                }
            return integral_s * h;
        }

double num_comput_integral_Simps (double left_boundary_a, double right_boundary_b, unsigned int intervals)//метод Сімпса
        {
            double integral_s = 0, sum1 = 0, sum2 = 0, h = 0;
            h = (right_boundary_b - left_boundary_a) / intervals;
            for (int i = 1; i <= (intervals - 1); i++)
                {
                    if (i%2!=0)
                    sum1 += integrand_expression(left_boundary_a + h * i);
                    else
                    sum2 += integrand_expression(left_boundary_a+ h * i);
                }
  return (integrand_expression(left_boundary_a) + integrand_expression(right_boundary_b) + 4 * sum1 + 2 * sum2) * h / 3;
        }


