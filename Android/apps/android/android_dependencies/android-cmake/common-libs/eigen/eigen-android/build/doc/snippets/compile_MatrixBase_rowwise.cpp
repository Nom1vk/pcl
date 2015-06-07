#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  Matrix3d m = Matrix3d::Random();
cout << "Here is the matrix m:" << endl << m << endl;
cout << "Here is the sum of each row:" << endl << m.rowwise().sum() << endl;
cout << "Here is the maximum absolute value of each row:"
     << endl << m.cwiseAbs().rowwise().maxCoeff() << endl;

  return 0;
}
