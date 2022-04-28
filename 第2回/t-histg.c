/* �q�X�g�O���������߂� */
#include "image.h"
#include "bmp.c"
#include "Histgram.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* �J���[�摜 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* �Z�W�摜 */
long Hist[LEVEL], Hist2[LEVEL];	/* �q�X�g�O���� */

void main(void)
{
	char name[100], input[100];	/* �t�@�C���� */

	printf("���͉摜�t�@�C����(name)(�g���q�Ȃ���)�F"); 
	scanf("%s", name);
	sprintf(input, "%s.bmp", name);
	
	/* �摜�̓��� */
	readBmp(input, Image); to256BW(Image, ImageBW);

	printf("thresh = %d\n", ImageBW[75][62]);

	/* �q�X�g�O���������߂� */
	histgram(ImageBW, Hist);
	
	/* �q�X�g�O�����𕽊������� */
	histsmooth(Hist, Hist2);

	/* �q�X�g�O�������t�@�C���ɏo�� */
	histFile(Hist2, name);
}
