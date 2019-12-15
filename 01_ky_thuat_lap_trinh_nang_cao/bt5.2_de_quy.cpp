#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

void nhap_mang_1_chieu(int a [], int n) {
	if (n == 0)
		return;
	nhap_mang_1_chieu(a, n-1);
	printf("Nhap vao phan tu a[%d]: ", n-1);
	scanf("%d", &a[n-1]);
}

void xuat_mang_1_chieu(int a[], int n) {
	if (n == 0)
		return;
	xuat_mang_1_chieu(a, n-1);
	printf("%d\t", a[n-1]);
}

int tinh_tong_cac_phan_tu_trong_mang(int a[], int n, int tong) {
	if (n <= 0)
		return tong;
	else
		return tinh_tong_cac_phan_tu_trong_mang(a, n-1, tong+=a[n-1]);
}

int tinh_tong_cac_phan_tu_chan_trong_mang(int a[], int n, int tong) {
	if (n <= 0)
		return tong;
	else {
		if (a[n-1]%2 == 0)
			return tinh_tong_cac_phan_tu_chan_trong_mang(a, n-1, tong+=a[n-1]);
		else
			return tong;
	}
}

main() {
	int a[MAX], n = 4;
	// A) Nhap mang so nguyen to
	printf("\nA) Nhap mang mot chieu: \n");
	nhap_mang_1_chieu(a, n);
	
	// B) Xuat mang so nguyen to
	printf("\nB) Xuat mang mot chieu: \n");
	xuat_mang_1_chieu(a, n);
	printf("\n");
	
	// C) Tinh tong cac phan tu trong mang
	printf("\nC) Tong cac phan tu: %d", tinh_tong_cac_phan_tu_trong_mang(a, n, 0));
	printf("\n");
	
	// D) Tinh tong cac phan tu chan rong mang
	printf("\nD) Tong cac phan tu chan: %d", tinh_tong_cac_phan_tu_chan_trong_mang(a, n, 0));
	printf("\n");

	printf("\n");
}

