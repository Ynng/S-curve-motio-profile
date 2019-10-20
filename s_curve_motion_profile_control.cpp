/* S-shape motion control */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  while (true)
  {
    double mn = 0; /*  start point seconds. */
    double mx = 5; /*  time seconds */
    double a1 = 8;
    double a2 = 8; /* accel and decel slope  */
    double c1 = 0.8;
    double c2 = 4.2; /* half point of slope  */
    double y1;
    double y2;
    double y;
    double temp;             /* temp variable for calculation */
    double x[1000], f[1000]; /* this is static allocation */
    int n = 1000;            /*  assign No. of point plot. */
    int i;

    for (i = 0; i < n; i++)
    {
      temp = double((mx - mn) / (n));
      f[i] = mn + temp * i;
      {
        y1 = 1 / (1 + std::exp(-a1 * (f[i] - c1))); /* S-curve acceleration */
        y2 = 1 / (1 + std::exp(-a2 * (f[i] - c2))); /* S-curve deceleration */
        y = std::abs((y1)-y2) * 255;                /* absolute and *255 for scale up to PWM */

        /*PWM analog output pin 9 from y value 0 - 255 */
        // analogWrite(9, y);
        // analogWrite(10, y);
        // analogWrite(11, y);

        /*print labels */
        cout << "y " << i << " = " << setprecision(3) << y << endl;
        // Serial.print("y ");
        // Serial.print(i); /* prints a label */
        // Serial.print(" = ");
        // Serial.println(y, 3); /* print the number */
      }
    }
  }
}
