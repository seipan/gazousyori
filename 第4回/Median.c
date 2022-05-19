unsigned char median_value(unsigned char d[9]);

/*--- median --- ���f�B�A���t�B���^�ɂ��m�C�Y���� -----
	in:  ���͉摜�z��
	out: �o�͉摜�z��
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

/*--- median_value --- 9�̒l�̒����l�i���f�B�A���j�����߂� ----
	d:	��f�l
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
