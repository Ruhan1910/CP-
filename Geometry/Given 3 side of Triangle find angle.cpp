const double PI = 3.14159265358979323846;

double todeg(double rad){
    return rad * 180.0 / PI;
}
void find_angle(double a, double b, double c){
  double A = acos(((double)b * b + c * c - a * a) / (2.0 * b * c));
  double B = acos(((double)a * a + c * c - b * b) / (2.0 * a * c));
  double C = acos(((double)a * a + b * b - c * c) / (2.0 * a * b));

  A = todeg(A);
  B = todeg(B);
  C = todeg(C);
}
