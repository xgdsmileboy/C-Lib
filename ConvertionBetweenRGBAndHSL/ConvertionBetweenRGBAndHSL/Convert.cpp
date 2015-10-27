#include <stdio.h>
#include "HSLtoRGB.h"
#include "RGBtoHSL.h"


int main (int argc, char* argv[])
{
	double r, g, b;
	double h, s, l;
	int funcSelect;

	printf("Please select the function that you want to use:\n");
	printf("1. func for RGB convert to HSL\n");
	printf("2. func for HSL convert to RGB\n");
	printf("3. exit func\n");
	printf("===================================================\n");

	scanf("%d", &funcSelect);

	while (3 != funcSelect)
	{
		switch (funcSelect)
		{
		case 1:
			{
				printf("Please input r g b :");
				scanf("%lf %lf %lf", &r, &g, &b);
				RGBtoHSL(r, g, b, &h, &s, &l);
				printf("\nHSL£º%f %f %f\n", h, s, l);
				break;
			}
		case 2:
			{
				printf("Please input h s l :");
				scanf("%lf %lf %lf",&h, &s, &l);
				HSLtoRGB(h, s, l, &r, &g, &b);
				printf("\nRGB£º%f %f %f\n", r, g, b);
				break;
			}
		default:
			printf("Erro input ,please select again!");
			break;
		}

		printf("\n===================================================\n");
		printf("Please select the function that you want to use:\n");
		printf("1. func for RGB convert to HSL\n");
		printf("2. func for HSL convert to RGB\n");
		printf("3. exit func\n");
		printf("===================================================\n");

		scanf("%d", &funcSelect);
	}

	return 0;
}