/*  膨張処理(２値画像)  */
void dilation(
	unsigned char in[Y_SIZE][X_SIZE],		/* 入力画像配列 */
	unsigned char out[Y_SIZE][X_SIZE]		/* 出力画像配列 */
)
{
	int	i, j;

	for (i = 1; i < biHeight-1; i++) 
	for (j = 1; j < biWidth-1; j++) {
		out[i][j] = in[i][j];
	    if (in[i-1][j-1] == HIGH) out[i][j] = HIGH;
	    if (in[i-1][j  ] == HIGH) out[i][j] = HIGH;
	    if (in[i-1][j+1] == HIGH) out[i][j] = HIGH;
	    if (in[i  ][j-1] == HIGH) out[i][j] = HIGH;
	    if (in[i  ][j+1] == HIGH) out[i][j] = HIGH;
	    if (in[i+1][j-1] == HIGH) out[i][j] = HIGH;
	    if (in[i+1][j  ] == HIGH) out[i][j] = HIGH;
	    if (in[i+1][j+1] == HIGH) out[i][j] = HIGH;
	}
}
