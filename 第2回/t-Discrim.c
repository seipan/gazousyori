/* しきい値を自動的に判別分析法で決めて，画像を２値化する．*/
#include "image.h"
#include "bmp.c"
#include "Thresh.c"
#include "Histgram.c"
#include "Discrim.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* カラー画像 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* 濃淡画像 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* 濃淡画像 */

void main(void)
{
	int thresh;
	int hist[LEVEL];
	char input[100], output[100];	/* ファイル名 */

	printf("入力画像ファイル名(input.bmp)："); scanf("%s", input);
	printf("出力画像ファイル名(output.bmp)："); scanf("%s", output);
	
	/* 画像の入力 */
	readBmp(input, Image); to256BW(Image, ImageBW);

	/* ２値化 */
	histgram(ImageBW, hist);
	thresh = discrim(hist);
	printf("thresh = %d\n", thresh);
	threshold(ImageBW, ImageBW2, thresh);

	/* 画像の出力 */
	to24BMP(ImageBW2, Image); writeBmp(Image, output);
}
