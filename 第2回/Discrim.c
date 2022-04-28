/*--- discrim --- 判別分析法でしきい値を決定する ---------
  返値:   しきい値
  hist[]: ヒストグラム
----------------------------------------------------------*/
int discrim(int hist[LEVEL])
{
	int s, i;
	double n1, n2, m1, m2;
	double v[LEVEL], vmax;

	for (s=1; s<LEVEL; s++) {
		n1 = 0; m1 = 0;
		for (i=0; i<s; i++) {
			n1 += hist[i];
			m1 += i * hist[i];
		}
		if (n1 == 0.0) m1 = 0.0;
		else           m1 /= n1;
		n2 = 0; m2 = 0;
		for (i=s; i<LEVEL; i++) {
			n2 += hist[i];
			m2 += i * hist[i];
		}
		if (n2 == 0.0) m2 = 0.0;
		else           m2 /= n2;
		v[s] = n1*n2*(m1-m2)*(m1-m2);
	}

	vmax = 0; s = 0;
	for (i=1; i<LEVEL; i++) {
		if (v[i] > vmax) {
			vmax = v[i];
			s = i;
		}
	}

	return s;
}
