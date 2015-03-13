/* WAP to find the real roots of the equation
 * (x^3) - (4 * x) - 9 = 0
 * using Bisection Method correct up to three decimal places
 * Umang Galaiya
 * 130050131516
 * 3/2/2015
 * 12:05 pm to 2:05 pm
 */
#include <stdio.h>
#include <conio.h>
float f (float x);
int checker (float x1, float x2);
void main()
{
	float positiveLimit = -1, negativeLimit = -1, prevMiddleX, middleX, fOfX;
	int i = 0;
	clrscr();
	while (positiveLimit == -1 || negativeLimit == -1) {
		fOfX = f(i);
		printf("f(%d)\t = %f\n", i, fOfX);
		if (fOfX < 0)
			negativeLimit = i;
		else if (fOfX > 0)
			positiveLimit = i;
		i++;
	}
	printf("\nThe positive limit is: %f\nThe negative limit is: %f\n", positiveLimit, negativeLimit);
printf("\n#\tx1(+ve)\t\tx2(-ve)\t\tx\t\tf(x)\n");	
i = 1;
	middleX = (positiveLimit + negativeLimit) / 2;
	fOfX = f(middleX);
	if (fOfX < 0)
		negativeLimit = middleX;
	else if (fOfX > 0)
		positiveLimit = middleX;
	printf("%d\t%f\t%f\t%f\t%f\n", i, positiveLimit, negativeLimit, middleX, fOfX);
	i++;
	do {
		prevMiddleX = middleX;
		middleX = (positiveLimit + negativeLimit) / 2;
		fOfX = f(middleX);
		printf("%d\t%f\t%f\t%f\t%f\n", i, positiveLimit, negativeLimit, middleX, fOfX);
		if (fOfX < 0)
			negativeLimit = middleX;
		else if (fOfX > 0)
			positiveLimit = middleX;
	} while (checker(prevMiddleX, middleX) != 1);
	printf("\nThe root of the equation, correct up to three decimal places, is %.3f\n", middleX);
	getch();
}
float f (float x) {
	return ((x * x * x) - (4 * x) - 9);
}
int checker (float x1, float x2) {
	x1 *= 1000;
	x2 *= 1000;
	if ((int) x1 == (int) x2)
		return 1;
	return 0;
}
