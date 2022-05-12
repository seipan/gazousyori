/* エッジの２値化 */
#include "image.h"
#include "bmp.c"
#include "Laplacian.c"
#include "Thresh.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* カラー画像 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* 濃淡画像 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* 濃淡画像 */

void main(void)
{
	char input[100];	/* ファイル名 */
	int thresh;

	printf("入力画像ファイル名(input.bmp)："); 
	scanf("%s", input);
	
	/* 画像の入力 */
	readBmp(input, Image); to256BW(Image, ImageBW);
	to24BMP(ImageBW, Image); writeBmp(Image, "mono.bmp");
	
	/* Laplacianによるエッジ抽出 */
	laplacian(ImageBW, ImageBW2, 1.0);

	/* エッジ強度画像の出力 */
	to24BMP(ImageBW2, Image); writeBmp(Image, "lapl.bmp");
	
	/* ２値化 */
	printf("しきい値(0～255)："); scanf("%d", &thresh);
	threshold(ImageBW2, ImageBW, thresh, 1);
	/* ２値画像の出力 */
	to24BMP(ImageBW, Image); writeBmp(Image, "bina.bmp");
}
