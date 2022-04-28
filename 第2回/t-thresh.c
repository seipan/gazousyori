/* �������l���g���ĉ摜���Q�l������D*/
#include "image.h"
#include "bmp.c"
#include "Thresh.c"

unsigned char Image[Y_SIZE][X_SIZE][3];
unsigned char ImageBW[Y_SIZE][X_SIZE];
unsigned char ImageBW2[Y_SIZE][X_SIZE];

void main(void)
{
	int thresh;
	char input[100], output[100];

	printf("input(input.bmp)"); 
	scanf("%s", input);
	printf("output(output.bmp)"); 
	scanf("%s", output);
		readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");


	printf("閾値(0～255)"); scanf("%d", &thresh);
	threshold(ImageBW, ImageBW2, thresh);

	to24BMP(ImageBW2, Image); writeBmp(Image, output);
}
