#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  cout << VectorXi::LinSpaced(Sequential,4,7,10).transpose() << endl;
cout << VectorXd::LinSpaced(Sequential,5,0.0,1.0).transpose() << endl;

  return 0;
}
