/* 雑音除去 */
/* メディアンフィルタ */
#include "image.h"
#include "bmp.c"
#include "Median.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* カラー画像 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* 濃淡画像 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* 濃淡画像 */

void main(void)
{
	char input[100], filename[100];	/* ファイル名 */
	int i, n;

	printf("入力画像ファイル名(input.bmp)："); 
	scanf("%s", input);
	
	/* 画像の入力 */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* メディアンフィルタによる雑音除去 */
	printf("回数は : "); scanf("%d", &n);
	for (i=0; i<n; i++) {
		median(ImageBW, ImageBW2);
		imageCopyBW(ImageBW2, ImageBW);
	}

	/* 画像の出力 */
	to24BMP(ImageBW2, Image);
	sprintf(filename, "median%d.bmp", n);
	writeBmp(Image, filename);
}
