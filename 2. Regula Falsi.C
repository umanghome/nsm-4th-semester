/* WAP to find the real roots of a given function
 * f(x) = (x ^ 3) - (2 * x) - 5 = 0
 * correct up to 3 decimal places using Regula Falsi
 * Umang Galaiya
 * 130050131516
 * 3/2/2015
 * 12:05 pm to 2:05 pm
 */
#include <stdio.h>
#include <conio.h>
float f (float x);
float getX (float x1, float x2);
int checker (float x1, float x2);
void main()
{
	float positiveLimit = -100, negativeLimit = -100, prevMiddleX, middleX, fOfX;
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
	printf("\n#\tx1 (+ve)\tx2 (-ve)\tx\t\tf(x)\n");
	i = 1;
	middleX = getX(positiveLimit, negativeLimit);
	fOfX = f(middleX);
	if (fOfX < 0)
		negativeLimit = middleX;
	else if (fOfX > 0)
		positiveLimit = middleX;
	printf("%d\t%f\t%f\t%f\t%f\n", i, positiveLimit, negativeLimit, middleX, fOfX);
	i++;
	do {
		prevMiddleX = middleX;
		middleX = getX(positiveLimit, negativeLimit);
		fOfX = f(middleX);
		printf("%d\t%f\t%f\t%f\t%f\n", i, positiveLimit, negativeLimit, middleX, fOfX);
		if (fOfX < 0)
			negativeLimit = middleX;
		else if (fOfX > 0)
			positiveLimit = middleX;
		i++;
	} while (checker(prevMiddleX, middleX) != 1);
	printf("\nThe root of the equation, correct up to three decimal places is %.3f.\n", middleX);
	getch();
}
float f (float x) {
	return ((x * x * x) - (2 * x) - 5);
}
float getX (float x1, float x2) {
	float fOfX1, fOfX2;
	fOfX1 = f(x1);
	fOfX2 = f(x2);
	return (((x1 * fOfX2) - (x2 * fOfX1)) / (fOfX2 - fOfX1));
}
int checker (float x1, float x2) {
	x1 *= 1000;
	x2 *= 1000;
	if ((int) x1 == (int) x2)
		return 1;
	return 0;
}