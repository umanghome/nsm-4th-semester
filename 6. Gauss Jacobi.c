/* Develop a C Program for a linear equation using Gauss Jacobi
 * correct up to 3 decimal places
 * 27x +  6y -   z = 85
 *  6x + 15y +  2z = 72
 *   x +   y + 54z = 110
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
	float arr[3][4] = {{27, 6, -1, 85}, {6, 15, 2, 72}, {1, 1, 54, 110}};
	float prevX = 0, prevY = 0, prevZ = 0, x = 0, y = 0, z = 0, temp;
	int i;
	clrscr();
	printf("\n#\tx\t\ty\t\tz");
	printf("\n1\t%f\t%f\t%f", x, y, z);
	x = arr[0][3] / arr[0][0];
	y = arr[1][3] / arr[1][1];
	z = arr[2][3] / arr[2][2];
	printf("\n2\t%f\t%f\t%f", x, y, z);
	i = 3;
	while (checker(prevX, x, prevY, y, prevZ, z) != 1)
	{
		prevX = x;
		prevY = y;
		prevZ = z;
		x = (arr[0][3] - (arr[0][1] * prevY) - (arr[0][2] * prevZ)) / arr[0][0];
		y = (arr[1][3] - (arr[1][0] * prevX) - (arr[1][2] * prevZ)) / arr[1][1];
		z = (arr[2][3] - (arr[2][0] * prevX) - (arr[2][1] * prevY)) / arr[2][2];
		printf("\n%d\t%f\t%f\t%f", i, x, y, z);
		i++;
	}
	printf("\n\nx: %.3f\ny: %.3f\nz: %.3f", x, y, z);
	getch();
}

int checker (float prevX, float x, float prevY, float y, float prevZ, float z)
{
	prevX *= 1000;
	x *= 1000;
	prevY *= 1000;
	y *= 1000;
	prevZ *= 1000;
	z *= 1000;
	if (((int) prevX == (int) x) && ((int) prevY == (int) y) && ((int) prevZ == (int) z))
		return 1;
	return 0;
}