/* �G������ */
/* ���f�B�A���t�B���^ */
#include "image.h"
#include "bmp.c"
#include "Median.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* �J���[�摜 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* �Z�W�摜 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* �Z�W�摜 */

void main(void)
{
	char input[100], filename[100];	/* �t�@�C���� */
	int i, n;

	printf("���͉摜�t�@�C����(input.bmp)�F"); 
	scanf("%s", input);
	
	/* �摜�̓��� */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* ���f�B�A���t�B���^�ɂ��G������ */
	printf("�񐔂� : "); scanf("%d", &n);
	for (i=0; i<n; i++) {
		median(ImageBW, ImageBW2);
		imageCopyBW(ImageBW2, ImageBW);
	}

	/* �摜�̏o�� */
	to24BMP(ImageBW2, Image);
	sprintf(filename, "median%d.bmp", n);
	writeBmp(Image, filename);
}
