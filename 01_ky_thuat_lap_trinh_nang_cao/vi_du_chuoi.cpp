#include<stdio.h>
#include<string.h>
//char a =>1 ki tu=> c
//char c[20] chuoi toi da 19 ki tu => nguyen van a gets(c); scanf("%s",c[20])
void nhapChuoi(char c[30]){	
	printf("\nNhap chuoi voi gets: ");
	gets(c);	
}

void xuatChuoi(char c[30]){
	puts(c);
}

int doDai(char c[30]){
	return strlen(c);
}

void soSanh(char s1[30],char s2[30]){
	if(strcmp(s1,s2)==0)
		printf("\ns1 = s2");
	if(strcmp(s1,s2)>0)
		printf("\ns1 > s2");
	if(strcmp(s1,s2)<0)
		printf("\ns1 < s2");	
}
void xoa(char s[30],int vitrixoa)
{
	int n=strlen(s);//gán n= d? dài c?a chu?i
    for(int i=vitrixoa;i<n;i++)//duy?t chu?i t? v? trí c?n xóa
     s[i]=s[i+1];
	s[n-1]='\0'; //k?t thúc
}
void xoakt(char s[30])
{
    for(int i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		}
    if(s[0]==' ')
		xoa(s,0);
    if(s[strlen(s)-1]==' ')
		xoa(s,strlen(s)-1);
}

//strcat
//strstr
int main(){
	char s[30];
//	char s2[30];
	/*printf("\nNhap chuoi s1\n");
	nhapChuoi(s);
	xuatChuoi(s);
	printf("\nNhap chuoi s2\n");
	nhapChuoi(s2);
	xuatChuoi(s2);
	
	printf("\nDo dai chuoi s1 = %d",doDai(s));
	printf("\nDo dai chuoi s2 = %d",doDai(s2));
	
	printf("\n=======so sanh s1 voi s2========\n");
	soSanh(s,s2);
	
	printf("\n");*/
	
	printf("\nNhap chuoi: ");
	gets(s);
	printf("\nChuoi vua nhap: ");
	puts(s);
	printf("\n=========Cat khoang trang du=========\n");
	xoakt(s);
	puts(s);
		

	int n=strlen(s);
	//	nguyen van a
	for(int i=0;i<n;i++){
		if(s[0] != ' '){
			if(s[0]<='z' && s[0]>='a'){
				s[0]=s[0]-32;
			}			
		}
		//in hoa chu ki tu dau tien nguyen van a=> N V A		
		if(s[i] == ' ' && s[i+1] != ' ' && i<n){
			if(s[i+1]<='z' && s[i+1]>='a'){
				s[i+1]=s[i+1]-32;				
			}
							
		}
		//chuyen ki tu hoa thanh ki tu thuong nGUY => nguy
		if(s[i] != ' ' && s[i+1] != ' ' && i<n){
			if(s[i+1]<='Z' && s[i+1]>='A') {
				s[i+1]=s[i+1]+32;			
			}			
		}//KHOA =>Khoa
		if(s[i] != ' ' && s[i+1]!=' ' && i<n){
			if(s[i+1]<='Z' && s[i+1]>='A') {
				s[i+1]=s[i+1]+32;				
			}
		}//xet chu cuoi la chu hoa chuyen thanh chu thuong
		if(s[n-1] != ' ' && s[n-2] != ' ' && i<n) {
			if(s[n-1]<='Z' && s[n-1]>='A') {
				s[n-1]=s[n-1]+32;			
			}
		}
	}	
	printf("\nChuoi sau khi thay doi: ");
	puts(s);
	return 1;
}
