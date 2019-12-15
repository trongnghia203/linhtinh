#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#define duongdan "D:\\file.txt"

void doc_file(int a[], int &n) {
	FILE *f;
	f = fopen(duongdan, "rt");
	if (f==NULL) {
		printf("File khong ton tai");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &n);
	printf("So phan tu trong chuoi la: %d\n", n);
	for (int i=0; i<n; i++) {
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
}

void ghi_them_vao_file(int a) {
	FILE *f;
	f = fopen(duongdan, "a");
	if (f==NULL) {
		printf("File khong ton tai");
		getch();
		exit(0);
	}
	fprintf(f, "%4d", a);
	fclose(f);
}

void xuat_mang_mot_chieu(int a[], int n) {
	for (int i=0; i<n; i++) {
		printf("%4d", a[i]);
	}
	printf("\n");
}

int ktra_so_nguyen_to(int a) {
	for (int i=2; i<=a/2; i++) {
		if (a%2 == 0)
			return 1;		
	}
	return 0;
}

void ghi_so_nguyen_to_vao_file(int a[], int n) {
	for (int i=0; i<n; i++) {
		if (ktra_so_nguyen_to(a[i]) == 0)
			ghi_them_vao_file(a[i]);
	}
}

main() {	
	int a[MAX], n;
	
	doc_file(a,n);
	xuat_mang_mot_chieu(a,n);
	ghi_so_nguyen_to_vao_file(a,n);
}