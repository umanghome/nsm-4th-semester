/* Gauss Elimination
 * Umang Galaiya
 * 130050131516
 * 3/3/2015
 * 12:05 pm to 2:05 pm
 */
 
#include <stdio.h>
#include <conio.h>

void main()
{
	float matrix[3][3] = {{1, 4, -1}, {1, 1, -6}, {3, -1, -1}};
	float ans[3] = {-5, -12, 4};
	float x, y, z, temp;
	int i, j, k, l, m;
	clrscr();

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%f\t", matrix[i][j]);
		printf("| %f", ans[i]);
		printf("\n");
	}

	for (i = 0; i < 3; i++)
	{
		temp = matrix[i][i];
		if (temp != 1.0)
		{
			for (j = 0; j < 3; j++)
				matrix[i][j] = matrix[i][j] / temp;
			ans[i] /= temp;
		}

		for (j = i + 1; j < 3; j++)
		{
			while (matrix[j][i] != 0.0)
			{
				if (matrix[j][i] > 0.0)
				{
					for (k = 0; k < 3; k++)
						matrix[j][k] -= matrix[i][k];
					ans[j] -= ans[i];
				}
				else if (matrix[j][i] < 0.0)
				{
					for (k = 0; k < 3; k++)
						matrix[j][k] += matrix[i][k];
					ans[j] += ans[i];
				}
			}
		}
	}

	printf("\n\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%f\t", matrix[i][j]);
		printf("| %f ", ans[i]);
		printf("\n");
	}

	z = ans[2];
	y = ans[1] - (matrix[1][2] * z);
	x = ans[0] - (matrix[0][1] * y) - (matrix[0][2] * z);
	printf("\n\nx: %f\ny: %f\nz: %f\n", x, y, z);

	getch();
}