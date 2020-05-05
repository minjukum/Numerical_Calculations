//This program calculates Euler-Mascheroni constant
//using Euler-Maclaurin integration formula
//in double precision

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) {

  //variables
  int n;
  double sum = 0.;
  double c;
  double c1,c2;
  double b2 = (double)1/(double)6;
  double b4 = (double)(-1)/(double)30;

  //get the summation limit
  cout << "Enter n: ";
  cin >> n;

  for (int i = 1; i < n+1; i++) {
    sum += (double)1/(double)i;
  }

  //ok i know this double thing looks annoying but i had to
  //unless i get imprecise results
  c = sum - (double)log((double)n) - (double)1/((double)2*(double)n);
  c += b2*((double)1/(double)2)*((double)1/((double)n*(double)n));

  c1 = c;

  c += b4*(double)((double)1/(double)4)*((double)1/((double)n*(double)n*(double)n*(double)n));

  c2 = c;

  cout <<setprecision(15)<< "For N = 1, the gamma is " << c1 << endl;
  cout <<setprecision(15)<< "For N = 2, the gamma is " << c2 << endl;

  return 0;
}
