/*--- laplacian --- ２次微分によるエッジ抽出 ---------------
	in:	 入力画像配列
	out: 出力画像配列
	amp: 倍率
------------------------------------------------------------*/
void laplacian(unsigned char in[Y_SIZE][X_SIZE], 
               unsigned char out[Y_SIZE][X_SIZE], float amp)
{
	static int c[9] = {1, -2, 1,
					   -2,  -4, -2,	
					   1, -2, 1};	
	int	d[9];
	int	i, j, dat;
	float	z, zz;

	for (i = 1; i < biHeight-1; i++) {
		for (j = 1; j < biWidth-1; j++) {
			d[0] = in[i-1][j-1];
			d[1] = in[i-1][j];
			d[2] = in[i-1][j+1];
			d[3] = in[i][j-1];
			d[4] = in[i][j];
			d[5] = in[i][j+1];
			d[6] = in[i+1][j-1];
			d[7] = in[i+1][j];
			d[8] = in[i+1][j+1];
			z =  (float)(c[0]*d[0] + c[1]*d[1] + c[2]*d[2]
					   + c[3]*d[3] + c[4]*d[4] + c[5]*d[5]
					   + c[6]*d[6] + c[7]*d[7] + c[8]*d[8]);
			zz = amp*z;
			dat = (int)(zz);
			if (dat <   0) dat = -dat;
			if (dat > 255) dat =  255;
			out[i][j] = (unsigned char)dat;
		}
	}
}
