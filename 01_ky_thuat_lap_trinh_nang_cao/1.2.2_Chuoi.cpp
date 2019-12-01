#include <stdio.h>
#include <string.h>

/* a) Nhập vào 2 chuỗi dữ liệu s1 và s2. */

void nhap_chuoi(char s[50]) {
    printf("Hay nhap vao mot chuoi: ");
    fgets(s, sizeof(s), stdin);
}

void xuat_chuoi(char s[50]) {
    puts(s);
}

main() {
    char s1[50];
    nhap_chuoi(s1);
    xuat_chuoi(s1);
}