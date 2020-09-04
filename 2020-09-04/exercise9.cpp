/* Exercise 9.
    Write a program to print a table of the function f(x) = 5 - sqrt(25+ x^2) for x= 0 to 1 with steps of 0.01.
    Be sure that your program yields mull machine precision, but do not program the problem in double precision. Explain the results.
*/

#include <iostream>
#include <cmath>

using namespace std;

//typedef REAL float;

void set();
void functions(float xmin, float xmax, float step);
float compute_f(float x);
float compute_f_mod(float x);

int main(int argc, char *argv[])
{
  set();
  functions(atoi(argv[1]), atoi(argv[2]), atof(argv[3]));
  return 0;
}

void set()
{
  cout.precision(8);
  cout.setf(ios::scientific);
}

void functions(float xmin, float xmax, float step)
{  
  // Print parameters
  cout << "Students: Yul E. Villalba, Wilson A. Estacio.\n"
       << "The input parameters are:\n"
       << "xmin = " << xmin << "\n"
       << "xmax = " << xmax << "\n"
       << "step = " << step << "\n";

  // Print table's names
  cout << "x" << "\t\t\t\t"
       << "f(x)" << "\t\t\t"
       << "g(x)" << "\n";

  // Compute functions
  int N = (xmax - xmin)/step;
  for (int i=0; i <= N; i++)  
  {
    float x = xmin + i*step;
    float f = compute_f(x);
    float g = compute_f_mod(x);

    cout << x << "\t" << f << "\t" << g << "\n";  
  }  
}

float compute_f(float x)
{
  float f = 5 - sqrt(25 + x*x);  
  return f;
}

/*
  since f(x) = 5 - sqrt(25 + x*x), if you multiply and divide by his conjugate, then
  f(x) = (5 - sqrt(25 + x*x))*(5 + sqrt(25 + x*x))/(5 + sqrt(25 + x*x)),
       = (25 - (25 + x*x))/(5 + sqrt(25 + x*x),
       = - x*x/(5 + sqrt(25 + x*x).
   i.e., you suprime the substraction. Let see this in the method compute_f_mod().
  */
float compute_f_mod(float x)
{
  float f = -(x*x)/(5 + sqrt(25 + x*x));  
  return f;
}
