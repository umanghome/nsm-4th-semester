/* Gauss Seidel
 * Umang Galaiya
 * 130050131516
 * 3/3/2015
 * 12:05 pm to 2:05 pm
 */

#include <stdio.h>
#include <conio.h>

int checker (float prevX, float x, float prevY, float Y, float prevZ, float z);

void main ()
{
	float arr[3][4] = {{10, -5, -2, 3}, {4, -10, 3, -3}, {1, 6, 10, -3}};
	float prevX = 0, prevY = 0, prevZ = 0, x = 0, y = 0, z = 0, temp;
	int i;
	clrscr();

	printf("\n#\tx\t\ty\t\tz");

	printf("\n1\t%f\t%f\t%f", x, y, z);
	i = 2;
	do {
		prevX = x;
		prevY = y;
		prevZ = z;

		x = (arr[0][3] - (arr[0][1] * prevY) - (arr[0][2] * prevZ)) / arr[0][0];
		y = (arr[1][3] - (arr[1][0] * x) - (arr[1][2] * prevZ)) / arr[1][1];
		z = (arr[2][3] - (arr[2][0] * x) - (arr[2][1] * y)) / arr[2][2];
		printf("\n%d\t%f\t%f\t%f", i, x, y, z);
		i++;
	}
	while (checker(prevX, x, prevY, y, prevZ, z) != 1);

	printf("\n\nx: %f\ny: %f\nz: %f", x, y, z);

	getch();
}

int checker (float prevX, float x, float prevY, float y, float prevZ, float z)
{
	prevX *= 100;
	x *= 100;
	prevY *= 100;
	y *= 100;
	prevZ *= 100;
	z *= 100;

	if (((int) prevX == (int) x) && ((int) prevY == (int) y) && ((int) prevZ == (int) z))
		return 1;
	return 0;
}