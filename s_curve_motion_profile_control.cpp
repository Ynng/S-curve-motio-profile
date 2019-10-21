/* S-shape motion control */
#include <iostream>
#include <iomanip>
#include <cmath>
//desmos for visualizing and testing this
//https://www.desmos.com/calculator/cinzpicvjx
using namespace std;

int main()
{
  double mn = 0; /*  starting time in seconds */
  double mx = 5; /*  ending time in seconds */
  double a1 = 8;
  double a2 = 8; /* accel and decel slope  */
  double c1 = 0.8;
  double c2 = 4.2; /* half point of slope  */
  double y1;
  double y2;
  double y; /* output */
  double temp;             /* delta t per loop */
  double f[1000];         /* this is static allocation */
  int n = 1000;            /*  number of points to plot */
  int i;

  for (i = 0; i < n; i++)
  {
    temp = double((mx - mn) / (n));
    f[i] = mn + temp * i; // f[i] is current time in seconds
    {
      y1 = 1 / (1 + std::exp(-a1 * (f[i] - c1))); /* S-curve acceleration */
      y2 = 1 / (1 + std::exp(-a2 * (f[i] - c2))); /* S-curve deceleration */
      y = std::abs((y1)-y2) * 255;                /* absolute and *255 for scale up to PWM */

      /*print stuffs */
      printf("y:%f\ty1:%f\tt:%f\n", y/256, y1, f[i]);
    }
  }
}
