unsigned char median_value(unsigned char d[9]);

/*--- median --- メディアンフィルタによるノイズ除去 -----
	in:  入力画像配列
	out: 出力画像配列
---------------------------------------------------------*/
void median(unsigned char in[Y_SIZE][X_SIZE], 
            unsigned char out[Y_SIZE][X_SIZE])
{
	int             i, j;
  	unsigned char   d[9];

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
			out[i][j] = median_value(d);
		}
	}
}

/*--- median_value --- 9個の値の中央値（メディアン）を求める ----
	d:	画素値
-----------------------------------------------------------------*/
unsigned char median_value(unsigned char d[9])
{
	int     i, j, tmp;
    
	for (j = 0; j < 8; j++) {
		for (i = 0; i < 8; i++) {
			if (d[i+1] < d[i]) {
				tmp = d[i+1];
				d[i+1] = d[i];
				d[i] = tmp;
			}
		}
	}
	return d[4];
}
