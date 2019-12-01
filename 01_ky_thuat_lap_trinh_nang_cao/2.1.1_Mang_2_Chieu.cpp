#include <stdio.h>
#include <stdlib.h>

/* a) Nhap ma tran gom n dong va m cot */
void nhap_dong_cot(int &dong, int &cot) {
	printf("   Nhap so dong: ");
	scanf("%d", &dong);
	printf("   Nhap so cot: ");
	scanf("%d", &cot);
}

void nhap_matrix(int a[][10], int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			//printf("Nhap phan tu a[%d][%d]: ", i, j);
			//scanf("%d", &a[i][j]);
			a[i][j] = rand() % 10 ;
			printf("   Nhap phan tu a[%d][%d]: %d \n", i, j, a[i][j]);
		}
	}
}

/* b) Xuat ma tran da nhap */
void xuat_matrix(int a[][10], int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

/* c) Tinh tong cac phan tu da nhap */
int sum_matrix(int a[][10], int d, int c) {
	int sum = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}

/* e) Tinh trung binh cong cac phan tu duong */
int tbc_duong(int a[][10], int d, int c) {
	int tong_duong = 0, count_duong = 0;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c ; j++) {
			if (a[i][j] > 0) {
				count_duong++;
				tong_duong += a[i][j];
			}
		}
	}
	if (count_duong == 0)
		return 0;
	else
		return float(tong_duong)/count_duong;
}
/* f) Xuat cac phan tu nam tren dong k */
void xuat_cac_phan_tu_tren_dong_k(int a[][10], int d, int c) {
	int k;
	do {
		printf("\nf) Nhap dong k can xuat cac phan tu: ");
		scanf("%d", &k);
	} while (k<0 || k>d);
	printf("   Cac phan tu nam tren dong k la: ");
	for (int j = 0; j < c; j++) {
		printf("%6d",a[k][j]);
	}
	printf("\n");
}

/* g) Tinh tong cac phan tu nam tren cot k */
int tong_cac_phan_tu_tren_cot_k(int a[][10], int d, int c) {
	int k, tong_cot_k = 0;
	do {
		printf("\ng) Nhap cot k: ");
		scanf("%d", &k);
	} while(k < 0 || k > c);
	for (int i = 0; i < d; i++) {
		tong_cot_k += a[i][k];
	}
	return tong_cot_k;
}

/* h) Tim phan tu lon nhat trong ma tran */\
int phan_tu_lon_nhat(int a[][10], int d, int c) {
	int max_val = a[0][0];
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > max_val)
				max_val = a[i][j];
		}
	}
	return max_val;
}

main () {
	// a)
	printf("\na) Nhap ma tran \n");
	int a[10][10], d, c;
	nhap_dong_cot(d, c);
	nhap_matrix(a, d, c);
	
	// b)
	printf("\nb) Xuat ma tran da nhap: \n");
	xuat_matrix(a, d, c);
	
	// c)
	printf("\nc) Tong cua ma tran la: %d \n", sum_matrix(a, d, c));
	
	// d)
	printf("\nd) Trung binh cong cac phan tu cua ma tran la: %.2f \n", float(sum_matrix(a, d, c))/(d*c));
	
	// e)
	printf("\ne) Trung binh cong cac phan tu duong la: %.2f \n", tbc_duong(a, d, c));
	
	// f)
	xuat_cac_phan_tu_tren_dong_k(a, d, c);
	
	// g)
	printf("   Tong cac phan tu nam tren cot k la: %d \n", tong_cac_phan_tu_tren_cot_k(a, d, c));

	// h)
	printf("\nh) Phan tu lon nhat la: %d \n", phan_tu_lon_nhat(a, d, c));
}
