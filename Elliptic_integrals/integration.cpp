#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

ofstream outfile;

//integrand functions
double K_k(double, double);
double E_k(double, double);

int main(int argc, char const *argv[]) {

  //common variables
  long int n;
  double x_ini,x_fin,dx,x;
  double sum_K, sum_E;

  //required constants
  double k;

  //time
  clock_t start, finish;

/*
  //read in the integration conditions
  cout << "Enter the initial x and final x";
  cin >> x_ini >> x_fin;
  cout << "Enter the number of integration points";
  cin >> n;
*/
  x_ini = 0;
  x_fin = M_PI/2;
  n = 1000;

  cout << "Enter k: ";
  cin >> k;

  //step size
  dx = (x_fin-x_ini)/n;

  //INTEGRATION
  x = x_ini;
  sum_K = 0.0;
  sum_E = 0.0;

  start = clock();

  while (x<=x_fin) {
    sum_K += K_k(x,k)*dx;
    sum_E += E_k(x,k)*dx;
    x += dx;
  }

  finish = clock();

  //print results
  cout << "K(" << k << ") is " << sum_K << endl;
  cout << "E(" << k << ") is " << sum_E << endl;
  cout <<setprecision(4)<< "CPU time: " << (float(finish-start)/CLOCKS_PER_SEC) << " s" << endl;

  return 0;
}

//define integrand functions

double K_k(double x, double k)
{
  double f;
  f = 1/sqrt(1-k*k*sin(x)*sin(x));
  return f;
}

double E_k(double x, double k)
{
  double g;
  g = sqrt(1-k*k*sin(x)*sin(x));
  return g;
}
