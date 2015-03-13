/* WAP to find the root of
 * cos(x) - (x(e ^ x) = 0
 * using Secant Method, correct up to four decimal places
 * Umang Galaiya
 * 130050131516
 * 24/2/2015
 * 12:05 pm to 2:05 pm
 */
#include <stdio.h>
#include <conio.h>
#include <math.h>
float f (float x);
float getX (float xLastN, float xN);
int checker (float x1, float x2);
void main()
{
	float positiveLimit = -100, negativeLimit = -100, fOfX;
	float xLastN, xN,temp;
	int i = 0;
	clrscr();
	while (positiveLimit == -100 || negativeLimit == -100) {
		fOfX = f(i);
		printf("f(%d) = %f\n", i, fOfX);
		if (fOfX < 0)
			negativeLimit = i;
		else if (fOfX > 0)
			positiveLimit = i;
		i++;
	}
	printf("\nThe positive limit is: %f\nThe negative limit is: %f\n", positiveLimit, negativeLimit);
	xLastN = negativeLimit;
	xN = positiveLimit;
	printf("\n#\tx\n");
	printf("1\t%f\n2\t%f\n", xN, xLastN);
	i = 3;
	while (checker(xLastN, xN) != 1) {
		temp = getX(xLastN, xN);
		xLastN = xN;
		xN = temp;
		printf("%d\t%f\n", i, xN);
		i++;
	}
	printf("\nThe root of the equation is: %.4f", xN);
	getch();
}
float f (float x) {
	return (cos(x) - (x * exp(x)));
}
float getX (float xLastN, float xN) {
	float fOfXLastN, fOfXN;
	fOfXLastN = f(xLastN);
	fOfXN = f(xN);
	return (((xLastN * fOfXN) - (xN * fOfXLastN)) / (fOfXN - fOfXLastN));
}
int checker (float x1, float x2) {
	x1 *= 10000;
	x2 *= 10000;
	if ((int) x1 == (int) x2)
		return 1;
	return 0;
}