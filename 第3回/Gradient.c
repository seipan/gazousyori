/*--- gradient --- １次微分によるエッジ抽出 ---------------
	in:  入力画像配列
	out: 出力画像配列
	amp: 倍率
-----------------------------------------------------------*/
void gradient(unsigned char in[Y_SIZE][X_SIZE], 
              unsigned char out[Y_SIZE][X_SIZE], float amp)
{
	static int cx[9] = { -1, 0, 1,
						 -1, 0, 1,
						 -1, 0, 1};
	static int cy[9] = { -1, -1, -1,
						 0, 0, 0,
						 1,1, 1};
	int		d[9];
	int		i, j, dat;
	float	xx, yy, zz;

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
		    xx = (float)(cx[0]*d[0] + cx[1]*d[1] + cx[2]*d[2]
					   + cx[3]*d[3] + cx[4]*d[4] + cx[5]*d[5]
					   + cx[6]*d[6] + cx[7]*d[7] + cx[8]*d[8]);
			yy = (float)(cy[0]*d[0] + cy[1]*d[1] + cy[2]*d[2]
					   + cy[3]*d[3] + cy[4]*d[4] + cy[5]*d[5]
					   + cy[6]*d[6] + cy[7]*d[7] + cy[8]*d[8]);
			zz = (float)(amp*sqrt(xx*xx+yy*yy));
			dat = (int)zz;
			if(dat > 255) dat = 255;
			out[i][j] = (unsigned char)dat;
		}
	}
}
