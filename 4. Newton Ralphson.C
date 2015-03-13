/* WAP to find the root of
 * (x * log(x)) - 1.2 = 0
 * using Newton Ralphson Method, correct up to 5 decimal places
 * Umang Galaiya
 * 130050131516
 * 24/2/2015
 * 12:05 - 2:05
 */
#include <stdio.h>
#include <conio.h>
#include <math.h>
float f (float x);
float fDashX (float x);
float getX (float x);
int checker (float x1, float x2);
void main()
{
	float positiveLimit = -100, negativeLimit = -100, fOfX;
	float xLastN, xN,temp;
	int i = 0;
	clrscr();
	while (positiveLimit == -100 || negativeLimit == -100) {
		fOfX = f(i);
		if (fOfX < 0)
			negativeLimit = i;
		else if (fOfX > 0)
			positiveLimit = i;
		i++;
	}
	xLastN = (positiveLimit + negativeLimit) / 2;
	xN = getX(xLastN);
	printf("\n#\tx\n");
	printf("1\t%f\n2\t%f\n", xLastN, xN);
	i = 3;
	while (checker(xLastN, xN) != 1) {
		temp = getX(xN);
		xLastN = xN;
		xN = temp;
		printf("%d\t%f\n", i, xN);
		i++;
	}
	printf("\nThe root of the equation is: %.5f", xN);
	getch();
}
float f (float x) {
	return ((x * log10(x)) - 1.2);
}
float fDashX (float x) {
	return (log10(x) + 0.43429);
}
float getX (float x) {
	return (x - (f(x) / fDashX(x)));
}
int checker (float x1, float x2) {
	x1 *= 100000;
	x2 *= 100000;
	if ((int) x1 == (int) x2)
		return 1;
	return 0;
}