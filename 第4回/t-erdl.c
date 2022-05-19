/* 膨張収縮による雑音除去（２値画像） */
#include "image.h"
#include "bmp.c"
#include "Erosion.c"
#include "Dilation.c"

unsigned char Image[Y_SIZE][X_SIZE][3];
unsigned char ImageBW[Y_SIZE][X_SIZE];
unsigned char ImageBW2[Y_SIZE][X_SIZE];

void main(void)
{
	char input[100];	/* ファイル名 */

	printf("入力画像ファイル名(input.bmp)："); 
	scanf("%s", input);
	
	/* 画像の入力 */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* 雑音除去 */
	erosion(ImageBW, ImageBW2);
	dilation(ImageBW2, ImageBW);
	dilation(ImageBW, ImageBW2);
	erosion(ImageBW2, ImageBW);

	/* 画像の出力 */
	to24BMP(ImageBW, Image); writeBmp(Image, "erdldler.bmp");
}
