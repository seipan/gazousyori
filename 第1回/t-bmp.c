#include "image.h"
#include "bmp.c"

unsigned char image_in[Y_SIZE][X_SIZE][3];
unsigned char image_out[Y_SIZE][X_SIZE][3];

void mirror(
	unsigned char in[Y_SIZE][X_SIZE][3],
	unsigned char out[Y_SIZE][X_SIZE][3])
{
	int i,j,k;
	for (i=0; i<biHeight; i++)
	for (j=0; j<biWidth; j++)
	for (k=0; k<3; k++)
		out[i][j][k] = in[biHeight-i-1][j][k];
}

void main(void)
{
	char input[100], output[100];

	printf("nyuuryoku(input.bmp) : "); scanf("%s", input);
	printf("syuturyoku(output.bmp) : "); scanf("%s", output);

	readBmp(input, image_in);

	mirror(image_in, image_out);

	writeBmp(image_out, output);
}
