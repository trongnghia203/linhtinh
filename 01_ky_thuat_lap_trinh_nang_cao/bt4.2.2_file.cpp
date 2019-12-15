#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#define duongdan "D:\\test.inp"

void tao_mang_2_chieu(int a[][MAX], int d, int c) {
	for (int i=0; i<d; i++) {
		for (int j=0; j<c; j++) 
			a[i][j] = rand()%20;
	}
}

void xuat_mang_2_chieu(int a[][MAX], int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

void ghi_mang_2_chieu_vao_file(int a[][MAX], int d, int c) {
	FILE *f;
	f = fopen(duongdan, "wt");
	if (f==NULL) {
		printf("File khong ton tai");
		getch();
		exit(0);
	}
	fprintf(f, "%4d", d);
	fprintf(f, "%4d", c);
	fprintf(f, "\n");
	
	
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			fprintf(f, "%4d", a[i][j]);
		}
		fprintf(f, "\n");
	}
	
	fclose(f);
}

void doc_mang_2_chieu_tu_file(int a[][MAX], int &d, int &c) {
	FILE *f;
	f = fopen(duongdan, "rt");
	if (f==NULL) {
		printf("File khong ton tai");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &d);
	fscanf(f, "%d", &c);

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}
	fclose(f);
}

main() {
	int a[MAX][MAX], dong_a = 5, cot_a = 6;
	int b[MAX][MAX], dong_b, cot_b;
	
	tao_mang_2_chieu(a, dong_a, cot_a);
	printf("Mang da nhap vao la: \n");
	xuat_mang_2_chieu(a, dong_a, cot_a);
	ghi_mang_2_chieu_vao_file(a, dong_a, cot_a);
	doc_mang_2_chieu_tu_file(b, dong_b, cot_b);
	printf("Mang da ghi vao file la: \n");
	xuat_mang_2_chieu(b, dong_b, cot_b);	
}