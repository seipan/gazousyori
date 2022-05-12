/* �O���f�B�G���g�ɂ��G�b�W���o
   ���v���V�A���ɂ��G�b�W���o    */
#include "image.h"
#include "bmp.c"
#include "Gradient.c"
#include "Laplacian.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* �J���[�摜 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* �Z�W�摜 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* �Z�W�摜 */

void main(void)
{
	char input[100];	/* �t�@�C���� */

	printf("���͉摜�t�@�C����(input.bmp)�F"); 
	scanf("%s", input);
	
	/* �摜�̓��� */
	readBmp(input, Image);
	to256BW(Image, ImageBW);
	/* �Z�W�摜�̏o�� */
	to24BMP(ImageBW, Image);
	writeBmp(Image, "mono.bmp");
	printf("thresh = %d\n", ImageBW[91][121]);

	
	/* �O���f�B�G���g�ɂ��֊s���o */
	gradient(ImageBW, ImageBW2, 1.0);
	/* �֊s�摜�̏o�� */
	to24BMP(ImageBW2, Image);
	writeBmp(Image, "grad.bmp");
	printf("thresh = %d\n", ImageBW2[91][121]);

	/* ���v���V�A���ɂ��֊s���o */
	laplacian(ImageBW, ImageBW2, 1.0);
	/* �֊s�摜�̏o�� */
	to24BMP(ImageBW2, Image);
	writeBmp(Image, "lapl.bmp");
	printf("thresh = %d\n", ImageBW2[91][121]);
}
