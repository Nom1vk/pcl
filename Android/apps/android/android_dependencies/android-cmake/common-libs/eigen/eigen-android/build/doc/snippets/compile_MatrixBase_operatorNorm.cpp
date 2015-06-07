#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  MatrixXd ones = MatrixXd::Ones(3,3);
cout << "The operator norm of the 3x3 matrix of ones is "
     << ones.operatorNorm() << endl;

  return 0;
}
