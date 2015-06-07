#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  MatrixXd m(2,3);
m << 2, -4, 6,   
     -5, 1, 0;
cout << m.cwiseAbs() << endl;

  return 0;
}
