#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

ofstream outfile;

//integrand functions
double F(double, double);
double E(double, double);
void writefile(double,double,double,double);

int main(int argc, char const *argv[]) {

  //common variables
  long int n;
  double x_ini,x_fin,dx,x;
  double phi_ini,phi_fin,dphi,phi;
  double k_ini,k_fin,dk,k;
  double sum_F, sum_E;

  //time
  clock_t start, finish;

  outfile.open("elliptic_int.txt");

  //read in integration step size
  cout << "Enter dx: ";
  cin >> dx;

  n = 100;

  phi_ini = 0.;
  phi_fin = 2*M_PI;
  dphi = (phi_fin-phi_ini)/n;

  k_ini = 0.;
  k_fin = 1.;
  dk = (k_fin-k_ini)/n;

  x_ini = 0.;
//dx is set already

  //INTEGRATION with k,phi loop
  start = clock();

  k = k_ini;
  while (k<=k_fin) {
    phi = phi_ini;
    while (phi<=phi_fin) {
      sum_F = 0.0;
      sum_E = 0.0;
      x_fin = phi;
      x = x_ini;
      while (x<=x_fin) {
        sum_F += F(x,k)*dx;
        sum_E += E(x,k)*dx;
        x += dx;
      }
      writefile(k,phi,sum_F,sum_E);
      phi += dphi;
    }
    k += dk;
  }

  finish = clock();
  outfile.close();

  //print CPU time
  cout <<setprecision(4)<< "CPU time: " << (float(finish-start)/CLOCKS_PER_SEC) << " s" << endl;

  return 0;
}

//define integrand functions

double F(double x, double k)
{
  double f;
  f = 1/sqrt(1-k*k*sin(x)*sin(x));
  return f;
}

double E(double x, double k)
{
  double g;
  g = sqrt(1-k*k*sin(x)*sin(x));
  return g;
}

void writefile(double k, double phi, double sum_F, double sum_E)
{
  outfile << setiosflags(ios::showpoint);
  outfile << setw(15) << setprecision(8) << k;
  outfile << setw(15) << setprecision(8) << phi;
  outfile << setw(15) << setprecision(8) << sum_F;
  outfile << setw(15) << setprecision(8) << sum_E << endl;
}
