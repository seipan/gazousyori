void threshold(unsigned char in[Y_SIZE][X_SIZE], 
			   unsigned char out[Y_SIZE][X_SIZE], int thresh)
{
	int	i,j;

	for (i = 0; i < biHeight; i++) {
		for ( j = 0; j < biWidth; j++) {
				if ((int)in[i][j] >= thresh) out[i][j] = HIGH;
				else                         out[i][j] =  LOW;
		}
	}
}
