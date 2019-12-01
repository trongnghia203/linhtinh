#include <stdio.h>
#include <stdlib.h>


/* a) Nhap mang so nguyen voi n phan tu */
void NhapN(int &n) {
	do {
		printf("Nhap so phan tu n (0<n<100): ");
		scanf("%d", &n);
	} while (n<=0 || n>100);
}

void NhapMang(int a[], int n) {
	printf("\na) Nhap mang so nguyen voi %d phan tu: \n", n);
	for (int i = 0; i < n; i++) {
		// printf("Nhap phan tu a[%d]: ", i);
		// scanf("%d", &a[i]);
		a[i] = rand()%20;
	}
}

/* b) Xuat mang vua nhap */
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%6d", a[i]);
	}
	printf("\n");
}

/* c) Tim so duong dau tien, xuat ra vi tri va gia tri cua no */
int TimDuongDauTien(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			return i;
		}
	}
	return -1;
}

/* d) Tim so duong cuoi cung, xuat ra vi tri va gia tri cua no */
int TimDuongCuoiCung(int a[], int n) {
	int vi_tri_duong_cuoi_cung = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			vi_tri_duong_cuoi_cung = i;
		}
	}
	return vi_tri_duong_cuoi_cung;
}

/* e) Tim gia tri phan tu lon nhat */
int TimPhanTuLonNhat(int a[], int n) {
	int max_pos = 0;
	int max_val = a[0];
	for (int i = 1; i < n; i++) {
		if ( a[i] > max_val ) {
			max_pos = i;
			max_val = a[i];
		}
	}
	return max_pos;
}

/* f) Dem so phan tu lon nhat */
int DemSoPhanTuLonNhat(int a[], int n, int max_val) {
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == max_val)
			max_count+=1;
	}
	return max_count;
}

/* g) Xuat vi tri cua cac phan tu lon nhat*/
void XuatCacPhanTuLonNhat(int a[], int n, int max_val) {
	int max_count = 0;
	printf("\ng) Vi tri cac phan tu lon nhat (gia tri = %d) la: ", max_val);
	for (int i = 0; i < n; i++) {
		if (a[i] == max_val)
			printf("%6d", i);
	}
	printf("\n");
}

/* h) Them mot phan tu moi vao dau mang */
void ThemPhanTuVaoDauMang(int a[], int &n) {
	int phan_tu_them_moi;
	printf("\nh) Nhap gia tri phan tu them vao dau mang: ");
	scanf("%d", &phan_tu_them_moi);
	
	for (int i = n; i > 0; i--) {
		a[i] = a[i-1];
	}
	a[0] = phan_tu_them_moi;
	n++;
}

/* i) Them mot phan tu vao vi tri k trong mang */
void ThemPhanTuVaoViTriK(int a[], int &n) {
	int gia_tri_phan_tu_moi, vi_tri_k;
	printf("\ni) Nhap gia tri phan tu can them vao mang: ");
	scanf("%d", &gia_tri_phan_tu_moi);
	
	do {
		printf("   Nhap vi tri can them vao mang: ");
		scanf("%d", &vi_tri_k);
	} while (vi_tri_k<0 || vi_tri_k>n);
	
	for (int i = n; i > vi_tri_k; i--) {
		a[i] = a[i-1];
	}
	a[vi_tri_k] = gia_tri_phan_tu_moi;		
	n++;
}

/* j) Xoa phan tu dau mang */
void XoaPhanTuDauMang(int a[], int &n) {
	printf("\nj) Xoa phan tu dau tien trong mang: ");
	for (int i = 0; i < n-1; i++) {
		a[i] = a[i+1];
	}
	n--;
}

/* k) Xoa phan tu tai vi tri k */
void XoaPhanTuViTriK(int a[], int &n) {
	int k;
	do {
		printf("\nk) Nhap vi tri phan tu can xoa: ");
		scanf("%d", &k);
	} while ( k < 0 || k > n);
	
	for (int i = k; i < n; i++) {
		a[i] = a [i+1];
	}
	n--;
}

/* l) Kiểm tra mảng có chứa số lẻ không */
int kiem_tra_mang_co_chua_so_le_khong(int a[], int n) {
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 1)
			return 1;
	return 0;
}

/* m) Tạo mảng mới chứa các phần tử chẵn của mảng đã nhập. */
void tao_mang_so_chan_tu_mang_da_nhap(int a[], int  n, int b[], int &m) {
	m = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) {
			b[m] = a[i];
			m++;
		}
}

main(){
	// a)
	int a[100], n;
	NhapN(n);
	NhapMang(a,n);
	
	// b) 
	printf("\nb) Mang da nhap la: ");
	XuatMang(a,n);
	
	// c)
	int vitriD = TimDuongDauTien(a,n);
	if (vitriD == -1)
		printf("\nc) Khong co phan tu duong trong mang. \n");
	else
		printf("\nc) Phan tu duong dau tien trong mang la a[%d]: %d \n", vitriD, a[vitriD]);
		
	// d)
	int vi_tri_duong_cuoi_cung = TimDuongCuoiCung(a,n);
	if (vi_tri_duong_cuoi_cung == -1)
		printf("\nd) Khong co phan tu duong trong mang. \n");
	else
		printf("\nd) Phan tu duong cuoi cung trong mang la a[%d]: %d \n", vi_tri_duong_cuoi_cung, a[vi_tri_duong_cuoi_cung]);
	
	// e)
	int max_pos = TimPhanTuLonNhat(a,n);
	printf("\ne) Gia tri lon nhat trong mang la a[%d]: %d \n", max_pos, a[max_pos]);
	
	// f)
	int max_count = DemSoPhanTuLonNhat(a, n, a[max_pos]);
	printf("\nf) So phan tu lon nhat (gia tri = %d) trong mang la: %d \n", a[max_pos], max_count);
	
	// g)
	XuatCacPhanTuLonNhat(a, n, a[max_pos]);
	
	// h)
	ThemPhanTuVaoDauMang(a,n);
	XuatMang(a,n);
	
	// i)
	ThemPhanTuVaoViTriK(a,n);
	XuatMang(a,n);
	
	// j)
	XoaPhanTuDauMang(a,n);
	XuatMang(a,n);
	
	// k)
	XoaPhanTuViTriK(a,n);
	XuatMang(a,n);

	// l)
	int kiem_tra_mang_co_so_le = kiem_tra_mang_co_chua_so_le_khong(a, n);
	if (kiem_tra_mang_co_so_le == 1)
		printf("\nl) Mang co chua so le \n");
	else
		printf("\nl) Mang khong chua so le \n");
	
	// m)
	int b[100], m;
	tao_mang_so_chan_tu_mang_da_nhap(a, n, b, m);
	printf("\nm) Mang moi chua cac phan tu chan: ");
	XuatMang(b, m);

}
