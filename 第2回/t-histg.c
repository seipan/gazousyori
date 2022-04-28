/* ヒストグラムを求める */
#include "image.h"
#include "bmp.c"
#include "Histgram.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* カラー画像 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* 濃淡画像 */
long Hist[LEVEL], Hist2[LEVEL];	/* ヒストグラム */

void main(void)
{
	char name[100], input[100];	/* ファイル名 */

	printf("入力画像ファイル名(name)(拡張子なしで)："); 
	scanf("%s", name);
	sprintf(input, "%s.bmp", name);
	
	/* 画像の入力 */
	readBmp(input, Image); to256BW(Image, ImageBW);

	printf("thresh = %d\n", ImageBW[75][62]);

	/* ヒストグラムを求める */
	histgram(ImageBW, Hist);
	
	/* ヒストグラムを平滑化する */
	histsmooth(Hist, Hist2);

	/* ヒストグラムをファイルに出力 */
	histFile(Hist2, name);
}
