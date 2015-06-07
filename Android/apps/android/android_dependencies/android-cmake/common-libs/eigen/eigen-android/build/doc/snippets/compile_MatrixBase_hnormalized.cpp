#include <Eigen/Eigen>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  Vector4d v = Vector4d::Random();
Projective3d P(Matrix4d::Random());
cout << "v                   = " << v.transpose() << "]^T" << endl;
cout << "v.hnormalized()     = " << v.hnormalized().transpose() << "]^T" << endl;
cout << "P*v                 = " << (P*v).transpose() << "]^T" << endl;
cout << "(P*v).hnormalized() = " << (P*v).hnormalized().transpose() << "]^T" << endl;
  return 0;
}
