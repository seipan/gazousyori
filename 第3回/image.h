#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* �ő�摜�T�C�Y */
#define Y_SIZE 1500
#define X_SIZE 2000

/* BMP�t�@�C���p */
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

#define HIGH   255	/* �Q�l�摜�̔� */
#define LOW      0	/* �Q�l�摜�̍� */
#define LEVEL  256	/* �Z�x���x���� */
