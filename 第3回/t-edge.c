/* グラディエントによるエッジ抽出
   ラプラシアンによるエッジ抽出    */
#include "image.h"
#include "bmp.c"
#include "Gradient.c"
#include "Laplacian.c"

unsigned char Image[Y_SIZE][X_SIZE][3];	/* カラー画像 */
unsigned char ImageBW[Y_SIZE][X_SIZE];	/* 濃淡画像 */
unsigned char ImageBW2[Y_SIZE][X_SIZE]; /* 濃淡画像 */

void main(void)
{
	char input[100];	/* ファイル名 */

	printf("入力画像ファイル名(input.bmp)："); 
	scanf("%s", input);
	
	/* 画像の入力 */
	readBmp(input, Image);
	to256BW(Image, ImageBW);
	/* 濃淡画像の出力 */
	to24BMP(ImageBW, Image);
	writeBmp(Image, "mono.bmp");
	printf("thresh = %d\n", ImageBW[91][121]);

	
	/* グラディエントによる輪郭抽出 */
	gradient(ImageBW, ImageBW2, 1.0);
	/* 輪郭画像の出力 */
	to24BMP(ImageBW2, Image);
	writeBmp(Image, "grad.bmp");
	printf("thresh = %d\n", ImageBW2[91][121]);

	/* ラプラシアンによる輪郭抽出 */
	laplacian(ImageBW, ImageBW2, 1.0);
	/* 輪郭画像の出力 */
	to24BMP(ImageBW2, Image);
	writeBmp(Image, "lapl.bmp");
	printf("thresh = %d\n", ImageBW2[91][121]);
}
