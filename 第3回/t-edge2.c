/* �G�b�W�̂Q�l�� */
#include "image.h"
#include "bmp.c"
#include "Laplacian.c"
#include "Thresh.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* �J���[�摜 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* �Z�W�摜 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* �Z�W�摜 */

void main(void)
{
	char input[100];	/* �t�@�C���� */
	int thresh;

	printf("���͉摜�t�@�C����(input.bmp)�F"); 
	scanf("%s", input);
	
	/* �摜�̓��� */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* Laplacian�ɂ��G�b�W���o */
	laplacian(ImageBW, ImageBW2, 1.0);

	/* �G�b�W���x�摜�̏o�� */
	to24BMP(ImageBW2, Image); writeBmp(Image, "lapl.bmp");
	
	/* �Q�l�� */
	printf("�������l(0�`255)�F"); scanf("%d", &thresh);
	threshold(ImageBW2, ImageBW, thresh, 1);
	/* �Q�l�摜�̏o�� */
	to24BMP(ImageBW, Image); writeBmp(Image, "bina.bmp");
}
