#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct nhan_vien {
	char ma_nhan_vien[20];
	char ten_nhan_vien[50];
	char gioi_tinh[2];
	char loai_nhan_vien[2];
	float luong_co_ban;
	float he_so_luong;
	int so_nam_lam_viec;
} nv;

void nhap_nhan_vien(nv &x) {
	printf("> Nhap ma nhan vien: ");
	fflush(stdin);
	gets(x.ma_nhan_vien);
	
	printf("> Nhap ten nhan vien: ");
	fflush(stdin);
	gets(x.ten_nhan_vien);
	
	printf("> Nhap gioi tinh (x: nu,  y: nam): ");
	fflush(stdin);
	gets(x.gioi_tinh);
	
	printf("> Nhap loai nhan vien (q: quan ly, v: nhan vien van phong):" );
	fflush(stdin);
	gets(x.loai_nhan_vien);
	
	printf("> Nhap luong co ban: ");
	scanf("%f", &x.luong_co_ban);
	
	printf("> Nhap he so luong: ");
	scanf("%f", &x.he_so_luong);
	
	printf("> Nhap so nam lam viec: ");
	scanf("%d", &x.so_nam_lam_viec);
}

void xuat_nhan_vien(nv x) {
	printf("\n- Ma nhan vien: %s", x.ma_nhan_vien);
	printf("\n- Ten nhan vien: %s", x.ten_nhan_vien);
	printf("\n- Gioi tinh: %s", x.gioi_tinh);
	printf("\n- Loai nhan vien: %s", x.loai_nhan_vien);
	printf("\n- Luong co ban: %.2f", x.luong_co_ban);
	printf("\n- He so luong: %.2f", x.he_so_luong);
	printf("\n- So nam lam viec: %d", x.so_nam_lam_viec);
	printf("\n\n");
}

void nhap_danh_sach_nhan_vien(nv a[], n) {
	
}

void xuat_danh_sach_nhan_vien() {
	
}

main() {
	int so_luong_nhan_vien;
	nv danh_sach_nhan_vien[20];
	nhap_danh_sach_nhan_vien(danh_sach_nhan_vien, so_luong_nhan_vien);
	xuat_danh_sach_nhan_vien(danh_sach_nhan_vien, so_luong_nhan_vien);
}
