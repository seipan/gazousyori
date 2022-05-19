#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 最大画像サイズ */
#define Y_SIZE 1500
#define X_SIZE 2000

/* BMPファイル用 */
typedef short INT2;
typedef long INT4;

INT2 bfType;
INT4 bfSize;
INT2 bfReserved1, 
     bfReserved2;
INT4 bfOffBits;
INT4 biSize, 
     biWidth, biHeight;
INT2 biPlanes,
     biBitCount;
INT4 biCompression, 
     biSizeImage,
     biXPelsPerMeter,
     biYPelsPerMeter,
     biClrUsed, 
     biClrImportant;

#define HIGH   255	/* ２値画像の白 */
#define LOW      0	/* ２値画像の黒 */
#define LEVEL  256	/* 濃度レベル数 */
