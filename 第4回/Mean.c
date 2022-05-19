/*--- mean --- ���ϖ@�ɂ��m�C�Y���� ---------------
	in:  ���͉摜�z��
	out: �o�͉摜�z��
-----------------------------------------------------*/
void mean(unsigned char in[Y_SIZE][X_SIZE], 
          unsigned char out[Y_SIZE][X_SIZE])
{
	int             i, j, buf;
                    
   	for (i = 1; i < biHeight-1; i++) {
		for (j = 1; j < biWidth-1; j++) {
			buf = (int)in[i-1][j-1]
				+ (int)in[i-1][j]
				+ (int)in[i-1][j+1]
				+ (int)in[i][j-1]
				+ (int)in[i][j]
				+ (int)in[i][j+1]
				+ (int)in[i+1][j-1]
				+ (int)in[i+1][j]
				+ (int)in[i+1][j+1];
			out[i][j] = buf / 9;
		}
	}
}
