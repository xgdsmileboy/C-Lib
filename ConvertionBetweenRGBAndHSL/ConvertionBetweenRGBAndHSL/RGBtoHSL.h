#define max(a,b,c)    ((a > ((b>c)?b:c)) ? a : ((b>c)?b:c))
#define min(a,b,c)    ((a < ((b<c)?b:c)) ? a : ((b<c)?b:c))


//RGB from 0 to 255;    HSL results from 0 to 240
void RGBtoHSL (double r, double g, double b, double* h, double* s, double* l)
{
	//转到RGB(1, 1, 1)的空间
	double var_R = r/255;
	double var_G = g/255;
	double var_B = b/255;

	double vmin = min(var_R, var_G, var_B);
	double vmax = max(var_R, var_G, var_B);
	double delta = vmax - vmin;

	double dr, dg, db;

	*l = (vmax+vmin) / 2;

	if (0 == delta)
	{
		*h = 0;
		*s = 0;
	}
	else
	{
		if (*l < 0.5)
			*s = delta / (vmax+vmin);
		else
			*s = delta / (2-vmax-vmin);

		dr = (((vmax-var_R)/6) + (delta/2))/delta;
		dg = (((vmax-var_G)/6) + (delta/2))/delta;
		db = (((vmax-var_B)/6) + (delta/2))/delta;

		if (var_R == vmax)
			*h = db - dg;
		else if (var_G == vmax)
			*h = (1.0/3.0) + dr - db;
		else if (var_B == vmax)
			*h = (2.0/3.0) + dg - dr;

		if (*h < 0)
			*h += 1;
		if (*h > 1)
			*h -= 1;
	}
	//转回到HSL(240, 240, 240)的空间
	*h *= 240;
	*s *= 240;
	*l *= 240;
}
