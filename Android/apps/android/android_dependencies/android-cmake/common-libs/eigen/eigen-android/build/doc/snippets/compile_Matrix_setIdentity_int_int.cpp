#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  MatrixXf m;
m.setIdentity(3, 3);
cout << m << endl;

  return 0;
}
