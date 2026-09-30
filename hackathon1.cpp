#include <stdio.h>

#define MAX_SIZE 50

int main(){
    // B1: Khoi tao bien
    int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
    int n = 5;
    int choice;
    int value;
    int pos;
    int found;

    // B2: Dung khung cho chuong trinh
    do {
        // B2.1: HIEN THI MENU
        printf("\n=============================\n");
        printf("CHUONG TRINH QUAN LI KHO MINIMART\n");
        printf("=============================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("=============================\n");

        // B2.2: Cho nguoi dung nhap chuc nang
        printf("Vui long nhap lua chon(0-4): ");
        scanf("%d", &choice);

        // B2.3: Dua vao lua chon --> dieu huong chuong trinh
        switch (choice) {
            case 1:
                printf("Them so luong ton kho\n");
                // B3: Tien hanh chen so luong vao vi tri bat ki
                // Kiem tra mang day chua
                if (n == MAX_SIZE){
                	printf("Mang da day");
                	break;
                }
                // Cho nhap so luong vao mang
                printf("Moi ban nhap so luong: \n");
                scanf("%d", &value);
                if(value < 0){
					printf("So luong khong hop le\n");
					break;
				}
				printf("Moi ban nhap vi tri muon chen(1- %d): ", n);
				scanf("%d", &pos);
				
				// kiem tra vi tri chen hop le khong
				if(pos <1 || pos > n+1){
					printf("Vi tri chen khong hop le\n");
					break;
				}
				// chen value vao vi tri pos
				for(int i =n; i >= pos; i--){
					stock[i] = stock[i-1];
				}
				stock[pos-1] = value;
				n++;
				printf("Chen thanh cong\n");
				for(int i =0; i<n; i++){
					printf("%d", stock[i]);
				}
                break;

            case 2:
                printf("Sua ton kho\n");
			
			    printf("Cac phan tu dang co trong mang: \n");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", stock[i]);
			    }
			    printf("\n");
			
			    // B4: Tien hanh sua ton kho
			    // B4.1: Cho nguoi dung nhap vi tri can sua
			    printf("Moi ban nhap vao vi tri muon sua (1 - %d): ", n);
			    scanf("%d", &pos);
			
			    // B4.2: Kiem tra vi tri
			    if (pos < 1 || pos > n) {
			        printf("Vi tri sua khong hop le\n");
			        break;
			    }
			
			    // B4.3: Nhap gia tri moi
			    printf("Moi ban nhap vao gia tri ton kho moi: ");
			    scanf("%d", &value);
			
			    // B4.4: Kiem tra gia tri
			    if (value < 0) {
			        printf("So luong ton kho khong hop le\n");
			        break;
			    }
			
			    // B4.5: Tien hanh sua
			    stock[pos - 1] = value;
			
			    printf("Sua thanh cong\n");
			
			    // B4.6: Hien thi mang sau khi sua
			    printf("Cac phan tu sau khi sua: \n");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", stock[i]);
			    }
			    printf("\n");
			
			    break;
            case 3:
                printf("Xoa ton kho\n");
			
			    printf("Cac phan tu dang co trong mang: \n");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", stock[i]);
			    }
			    printf("\n");
			
			    // B5: Tien hanh xoa ton kho
			    // B5.1: Kiem tra mang co phan tu hay khong
			    if (n == 0) {
			        printf("Mang dang rong, khong the xoa\n");
			        break;
			    }
			
			    // B5.2: Nhap vi tri can xoa
			    printf("Moi ban nhap vao vi tri muon xoa (1 - %d): ", n);
			    scanf("%d", &pos);
			
			    // B5.3: Kiem tra vi tri
			    if (pos < 1 || pos > n) {
			        printf("Vi tri xoa khong hop le\n");
			        break;
			    }
			
			    // B5.4: Dich cac phan tu sang ben trai
			    for (int i = pos - 1; i < n - 1; i++) {
			        stock[i] = stock[i + 1];
			    }
			
			    // B5.5: Giam so luong phan tu
			    n--;
			
			    printf("Xoa thanh cong\n");
			
			    // B5.6: Hien thi mang sau khi xoa
			    printf("Cac phan tu sau khi xoa: \n");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", stock[i]);
			    }
			    printf("\n");
			
			    break;

            case 4:
                printf("Tim kiem ton kho\n");

			    printf("Cac phan tu dang co trong mang: \n");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", stock[i]);
			    }
			    printf("\n");
			
			    // B6.1: Nhap gia tri can tim
			    printf("Moi ban nhap vao so luong ton kho can tim: ");
			    scanf("%d", &value);
			
			    // B6.2: Tim kiem tuyen tinh
			    found = 0;
			
			    for (int i = 0; i < n; i++) {
			        if (stock[i] == value) {
			            printf("Tim thay %d tai vi tri %d\n", value, i + 1);
			            found = 1;
			        }
			    }
			
			    // B6.3: Neu khong tim thay
			    if (found == 0) {
			        printf("Khong tim thay so luong ton kho %d\n", value);
			    }
			
			    break;

            case 0:
                printf("Thoat chuong trinh\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long nhap lai!\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
