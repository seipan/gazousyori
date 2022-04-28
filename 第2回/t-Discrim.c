/* �������l�������I�ɔ��ʕ��͖@�Ō��߂āC�摜���Q�l������D*/
#include "image.h"
#include "bmp.c"
#include "Thresh.c"
#include "Histgram.c"
#include "Discrim.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* �J���[�摜 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* �Z�W�摜 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* �Z�W�摜 */

void main(void)
{
	int thresh;
	int hist[LEVEL];
	char input[100], output[100];	/* �t�@�C���� */

	printf("���͉摜�t�@�C����(input.bmp)�F"); scanf("%s", input);
	printf("�o�͉摜�t�@�C����(output.bmp)�F"); scanf("%s", output);
	
	/* �摜�̓��� */
	readBmp(input, Image); to256BW(Image, ImageBW);

	/* �Q�l�� */
	histgram(ImageBW, hist);
	thresh = discrim(hist);
	printf("thresh = %d\n", thresh);
	threshold(ImageBW, ImageBW2, thresh);

	/* �摜�̏o�� */
	to24BMP(ImageBW2, Image); writeBmp(Image, output);
}
