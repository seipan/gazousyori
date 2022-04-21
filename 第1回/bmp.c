
void writeBmp(unsigned char image[Y_SIZE][X_SIZE][3], char *filename)
{
	FILE *fp;
	int i, j, k;
	
	if ((fp = fopen(filename, "wb"))==NULL) {
		printf("writeBmp: Open error!\n");
		exit(1);
	}
	printf("output file : %s\n", filename);

	fwrite(&bfType, sizeof(bfType), 1, fp);
	fwrite(&bfSize, sizeof(bfSize), 1, fp);
	fwrite(&bfReserved1, sizeof(bfReserved1), 1, fp);
	fwrite(&bfReserved2, sizeof(bfReserved2), 1, fp);
	fwrite(&bfOffBits, sizeof(bfOffBits), 1, fp);

	fwrite(&biSize, sizeof(biSize), 1, fp);
	fwrite(&biWidth, sizeof(biWidth), 1, fp);
	fwrite(&biHeight, sizeof(biHeight), 1, fp);
	fwrite(&biPlanes, sizeof(biPlanes), 1, fp);
	fwrite(&biBitCount, sizeof(biBitCount), 1, fp);
	fwrite(&biCompression, sizeof(biCompression), 1, fp);
	fwrite(&biSizeImage, sizeof(biSizeImage), 1, fp);
	fwrite(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, fp);
	fwrite(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, fp);
	fwrite(&biClrUsed, sizeof(biClrUsed), 1, fp);
	fwrite(&biClrImportant, sizeof(biClrImportant), 1, fp);

	for (i=0; i<biHeight; i++)
	for (j=0; j<biWidth; j++) {
		for (k=0; k<3; k++) {
			fwrite(&image[biHeight-1-i][j][2-k], 1, 1, fp);
		}
	}
	
	fclose(fp);
}

void readBmp(char *filename, unsigned char image[Y_SIZE][X_SIZE][3])
{
	FILE *fp;
	int i, j, k;
	
	if ((fp = fopen(filename, "rb"))==NULL) {
		printf("readBmp: Open error!\n");
		exit(1);
	}
	printf("input file : %s\n", filename);

	fread(&bfType, sizeof(bfType), 1, fp);
	fread(&bfSize, sizeof(bfSize), 1, fp);
	fread(&bfReserved1, sizeof(bfReserved1), 1, fp);
	fread(&bfReserved2, sizeof(bfReserved2), 1, fp);
	fread(&bfOffBits, sizeof(bfOffBits), 1, fp);

	fread(&biSize, sizeof(biSize), 1, fp);
	fread(&biWidth, sizeof(biWidth), 1, fp);
	fread(&biHeight, sizeof(biHeight), 1, fp);
	fread(&biPlanes, sizeof(biPlanes), 1, fp);
	fread(&biBitCount, sizeof(biBitCount), 1, fp);
	fread(&biCompression, sizeof(biCompression), 1, fp);
	fread(&biSizeImage, sizeof(biSizeImage), 1, fp);
	fread(&biXPelsPerMeter, sizeof(biXPelsPerMeter), 1, fp);
	fread(&biYPelsPerMeter, sizeof(biYPelsPerMeter), 1, fp);
	fread(&biClrUsed, sizeof(biClrUsed), 1, fp);
	fread(&biClrImportant, sizeof(biClrImportant), 1, fp);

	for (i=0; i<biHeight; i++)
	for (j=0; j<biWidth; j++) {
		for (k=0; k<3; k++) {
			fread(&image[biHeight-1-i][j][2-k], 1, 1, fp);
		}
	}
	
	fclose(fp);
}

void to256BW(
		unsigned char image[Y_SIZE][X_SIZE][3],
		unsigned char image_bw[Y_SIZE][X_SIZE]  )
{
	int y, x, a;
	for (y=0; y<biHeight; y++)
	for (x=0; x<biWidth; x++) {
		a = (int)(0.3*image[y][x][0] + 0.59*image[y][x][1] + 0.11*image[y][x][2]);
		if (a<LOW) a = LOW;
		if (a>HIGH) a = HIGH;
		image_bw[y][x] = a;
	}
}

void to24BMP(
		unsigned char image_bw[Y_SIZE][X_SIZE],
		unsigned char image[Y_SIZE][X_SIZE][3] )
{
	int y, x, a;
	for (y=0; y<biHeight; y++)
	for (x=0; x<biWidth; x++) {
		a = image_bw[y][x];
		image[y][x][0] = a;
		image[y][x][1] = a;
		image[y][x][2] = a;
	}
}

void imageCopyBW(
		unsigned char image1[Y_SIZE][X_SIZE],
		unsigned char image2[Y_SIZE][X_SIZE] )
{
	int x, y;
	for (y=0; y<biHeight; y++)
	for (x=0; x<biWidth; x++)
		image2[y][x] = image1[y][x];
}
