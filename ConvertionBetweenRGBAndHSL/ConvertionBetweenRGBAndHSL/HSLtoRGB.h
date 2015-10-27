

double Hue_2_RGB (double v1, double v2, double vH)
{
	if (vH < 0)
		vH += 1;
	if (vH > 1)
		vH -= 1;
	if ((6*vH) < 1)
		return (v1 + (v2-v1)*6*vH);
	if ((2*vH) < 1)
		return v2;
	if ((3*vH) < 2)
		return (v1 + (v2-v1)*((2.0/3.0)-vH)*6);

	return v1;
}

//HSL from 0 to 240;    RGB results from 0 to 255
void HSLtoRGB (double h, double s, double l, double* R, double* G, double* B)
{
	double v1, v2;
	//转到HSL(1, 1, 1)的空间
	double H = h/240;
	double S = s/240;
	double L = l/240;

	if (0 == S)
	{
		//转回到RGB(255, 255, 255)的空间
		*R = L * 255;
		*G = L * 255;
		*B = L * 255;
	}
	else
	{
		if (L < 0.5)
			v2 = L * (1+S);
		else
			v2 = (L+S) - (L*S);

		v1 = 2 * L - v2;

		//转回到RGB(255, 255, 255)的空间
		*R = 255 * Hue_2_RGB (v1, v2, H+(1.0/3.0));
		*G = 255 * Hue_2_RGB (v1, v2, H);
		*B = 255 * Hue_2_RGB (v1, v2, H-(1.0/3.0));
	}
}
