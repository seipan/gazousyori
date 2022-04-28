/*--- histgram --- ヒストグラムを求める処理 -------------------------
	in:   入力画像配列
	hist: ヒストグラム
---------------------------------------------------------------------*/
void histgram(unsigned char in[Y_SIZE][X_SIZE], long hist[LEVEL])
{
	int	i,j,n;

	for (n = 0; n < LEVEL; n++) hist[n] = 0;
	for (i = 0; i < biHeight; i++) {
		for ( j = 0; j < biWidth; j++) {
			n = in[i][j];
			hist[n]++;
		}
	}
}

/*--- histsmooth --- ヒストグラムを平滑化する -----------------------
	in:	ヒストグラム 平滑化前
	out:ヒストグラム 平滑化後
---------------------------------------------------------------------*/
void histsmooth(int in[LEVEL], int out[LEVEL])
{
	int m, n, i;
	int sum;

	for (n = 0; n < LEVEL; n++) {
		sum = 0;
		for (m = -2; m <= 2; m++) {
			i = n + m;
			if (i <   0) i =   0;
			if (i > 255) i = 255;
			sum += in[i];
		}
		out[n] = (int)(sum / 5.0 + 0.5);
	}
}

/*--- histFile --- ヒストグラムをcsvファイルに出力 ------------------
	hist: ヒストグラム
	name: csvファイル名
---------------------------------------------------------------------*/
void histFile(int hist[LEVEL], char *name)
{
	char output[100];
	FILE *fp;
	int n;
	
	sprintf(output, "%s.csv", name);
	if ((fp=fopen(output, "w"))==NULL) {
		printf("Can't open file\n");
		exit(1);
	}
	printf("histgram file: %s\n", output);

	fprintf(fp, "画像%s.bmpのヒストグラム\n", name);
	fprintf(fp, "明度,頻度\n");
	for (n=0; n<LEVEL; n++) fprintf(fp, "%d,%d\n", n, hist[n]);

	fclose(fp);
}
