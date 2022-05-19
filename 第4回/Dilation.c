/*  �c������(�Q�l�摜)  */
void dilation(
	unsigned char in[Y_SIZE][X_SIZE],		/* ���͉摜�z�� */
	unsigned char out[Y_SIZE][X_SIZE]		/* �o�͉摜�z�� */
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
