/* �c�����k�ɂ��G�������i�Q�l�摜�j */
#include "image.h"
#include "bmp.c"
#include "Erosion.c"
#include "Dilation.c"

unsigned char Image[Y_SIZE][X_SIZE][3];
unsigned char ImageBW[Y_SIZE][X_SIZE];
unsigned char ImageBW2[Y_SIZE][X_SIZE];

void main(void)
{
	char input[100];	/* �t�@�C���� */

	printf("���͉摜�t�@�C����(input.bmp)�F"); 
	scanf("%s", input);
	
	/* �摜�̓��� */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* �G������ */
	erosion(ImageBW, ImageBW2);
	dilation(ImageBW2, ImageBW);
	dilation(ImageBW, ImageBW2);
	erosion(ImageBW2, ImageBW);

	/* �摜�̏o�� */
	to24BMP(ImageBW, Image); writeBmp(Image, "erdldler.bmp");
}
