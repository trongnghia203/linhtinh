#include <stdio.h>
#include <conio.h>
#include <string.h>

struct DATE {
	unsigned char ngay;
	unsigned char thang;
	int nam;
};

typedef struct buu_kien {
	char ma[20];
	char ten_nguoi_gui[50];
	char ten_nguoi_nhan[50];
	float trong_luong;
	struct DATE ngay_gui;
	char noi_dung[100];
	float don_gia;
} bk;

void nhap_ngay_gui(DATE &d) {
	printf("\n");
	printf("  Ngay: ");
	scanf("%u", &d.ngay);
	printf("  Thang: ");
	scanf("%u", &d.thang);
	printf("  Nam: ");
	scanf("%d", &d.nam);
}

void xuat_ngay_gui(DATE d) {
	printf("%02u/%02u/%4d", d.ngay, d.thang, d.nam);
}

void nhap_buu_kien(bk &x) {
	printf("+ Nhap ma buu kien: ");
	scanf("%s", &x.ma);
	
	printf("+ Nhap ten nguoi gui: ");
	fflush(stdin);
	gets(x.ten_nguoi_gui);
	
	printf("+ Nhap ten nguoi nhan: ");
	fflush(stdin);
	gets(x.ten_nguoi_nhan);
	
	printf("+ Nhap trong luong: ");
	scanf("%f", &x.trong_luong);
	
	printf("+ Nhap vao ngay gui: ");
	nhap_ngay_gui(x.ngay_gui);
	
	printf("+ Nhap noi dung: ");
	fflush(stdin);
	gets(x.noi_dung);
	
	printf("+ Nhap don gia: ");
	scanf("%f", &x.don_gia);
}

void xuat_buu_kien(bk x) {
	printf("\n\n---------Thong Tin Buu Kien----------------");
	printf("\n- Ma buu kien: %s", x.ma);
	printf("\n- Ten nguoi gui: %s", x.ten_nguoi_gui);
	printf("\n- Ten nguoi nhan: %s", x.ten_nguoi_nhan);
	printf("\n- Trong luong: %.2f (ton)", x.trong_luong);
	printf("\n- Ngay gui: "); xuat_ngay_gui(x.ngay_gui);
	printf("\n- Noi dung: %s", x.noi_dung);
	printf("\n- Don gia: %.2f ty dong", x.don_gia);
	printf("\n\n");
}

void nhap_so_luong_buu_kien(int &n) {
	do {
		printf("Nhap so luong buu kien: ");
		scanf("%d", &n);
	} while (n <= 0 || n >20);
}

// A. Nhap thong tin cac buu kien
void nhap_danh_sach_buu_kien(bk a[], int n) {
	for (int i=0; i < n; i++) {
		printf(". . .\n");
		printf("Nhap buu tien thu %d\n", i+1);
		nhap_buu_kien(a[i]);
	}
}

// B. Xuat thong tin cac buu kien
void xuat_danh_sach_buu_kien(bk a[], int n) {
	printf("\n\n=== DANH SACH BUU KIEN ===");
	for (int i=0; i < n; i++) {
		xuat_buu_kien(a[i]);
	}
}

// C. Them mot buu kien vao danh sach
void them_buu_kien_vao_danh_sach(bk a[], int &n) {
	printf("*** Nhap thong tin buu kien can them ***\n");
	nhap_buu_kien(a[n]);
	n++;
}

// D. Sap xep buu kien theo ma buu kien
void swap_tu_viet(bk &a, bk &b) {
	bk temp;
	temp = a; a = b; b = temp;
}

void sap_xep_danh_sach_buu_kien(bk a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=1; j<n; j++) {
			if (strcmp(a[i].ma, a[j].ma) > 0)
				swap_tu_viet(a[i],a[j]);
		}
	}
}

// E. Tinh gia_tri_buu_kien = trong_luong * don_gia
void tinh_gia_tri_cac_buu_kien(bk a[], int n) {
	printf("=== Tinh gia tri cac buu kien ===\n\n");
	for (int i=0; i<n; i++) {
		printf("%d. Ma buu kien: %s \n", i+1, a[i].ma);
		printf("   Gia tri: %.2f ty dong \n", a[i].trong_luong * a[i].don_gia);
	}
}

// F. Dem so luong buu kien co trong luong lon nhat
float trong_luong_lon_nhat(bk a[], int n){
	float max_weight;
	max_weight = a[0].trong_luong;
	for (int i=1; i<n; i++) {
		if ( a[i].trong_luong > max_weight)
			max_weight = a[i].trong_luong;
	}
	return max_weight;
}

int so_luong_buu_kien_co_trong_luong_lon_nhat(bk a[], int n){
	int count = 0;
	float max_weight;
	max_weight = trong_luong_lon_nhat(a, n);
	for (int i=0; i<n; i++) {
		if (a[i].trong_luong == max_weight)
			count++;
	}
	return count;
}

main(){
	int so_luong_buu_kien;
	nhap_so_luong_buu_kien(so_luong_buu_kien);
	bk danh_sach_buu_kien[20]; // khai bao danh sao toi da 20 buu kien
	
	// A. Nhap thong tin cac buu kien
	nhap_danh_sach_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	
	// B. Xuat thong tin cac buu kien
	xuat_danh_sach_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	
	// C. Them mot buu kien vao danh sach va xuat ra danh sach buu kien
	them_buu_kien_vao_danh_sach(danh_sach_buu_kien, so_luong_buu_kien);
	xuat_danh_sach_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	
	// D. Sap xep buu kien theo ma buu kien
	sap_xep_danh_sach_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	printf("Danh sach buu kien sau khi sap xep \n");
	xuat_danh_sach_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	
	// E. Tinh gia_tri_buu_kien = trong_luong * don_gia
	tinh_gia_tri_cac_buu_kien(danh_sach_buu_kien, so_luong_buu_kien);
	
	// F. Dem so luong buu kien co trong luong lon nhat
	printf("So luong buu kien co trong luong lon nhat la: %d \n", so_luong_buu_kien_co_trong_luong_lon_nhat(danh_sach_buu_kien, so_luong_buu_kien));

	// G. Tim buu kien theo ten nguoi gui
	
	
	// H. Xuat ra cac bui kien gui vao thang 04/2014
}