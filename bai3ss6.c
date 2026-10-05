#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;
    int choice;

    do {
        printf("\n================ HỆ THỐNG QUẢN LÝ MƯỢN TRẢ SÁCH (LOGISTICS) ================\n");
        printf("1. Thêm mới phiếu mượn sách (Create)\n");
        printf("2. Hiển thị danh sách phiếu mượn & Tiền phạt quá hạn (Read)\n");
        printf("3. Cập nhật số ngày mượn sách (Update)\n");
        printf("4. Xác nhận trả sách / Xóa phiếu mượn (Delete)\n");
        printf("5. Thoát chương trình\n");
        printf("===========================================================================\n");
        printf("Lựa chọn của bạn (1-5): ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("Bộ nhớ danh sách đã đầy, không thể thêm mới!\n");
                    break;
                }

                char tempMa[20];
                printf("--- THÊM MỚI PHIẾU MƯỢN ---\n");
                printf("Nhập mã phiếu: ");
                scanf("%19s", tempMa);
                while (getchar() != '\n');

                int trungLap = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMa) == 0) {
                        trungLap = 1;
                        break;
                    }
                }

                if (trungLap) {
                    printf("Mã phiếu đã tồn tại trong hệ thống!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], tempMa);

                printf("Nhập mã sách: ");
                scanf("%19s", maSach[soLuong]);
                while (getchar() != '\n');

                int ngay;
                do {
                    printf("Nhập số ngày mượn: ");
                    if (scanf("%d", &ngay) != 1) {
                        ngay = 0;
                        while (getchar() != '\n');
                    }
                    while (getchar() != '\n');
                    if (ngay <= 0) {
                        printf("Số ngày mượn phải lớn hơn 0. Vui lòng nhập lại!\n");
                    }
                } while (ngay <= 0);

                soNgayMuon[soLuong] = ngay;
                soLuong++;
                printf("Thêm mới phiếu mượn thành công!\n");
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sách phiếu mượn hiện đang rỗng!\n");
                    break;
                }

                printf("\n================================ DANH SÁCH PHIẾU MƯỢN ================================\n");
                printf("%-3s | %-10s | %-12s | %-8s | %-12s | %-15s\n", "STT", "MÃ PHIẾU", "MÃ SÁCH", "SỐ NGÀY", "TRẠNG THÁI", "TIỀN PHẠT (VNĐ)");
                printf("--------------------------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = 0;
                    char* trangThai = "ĐÚNG HẠN";
                    if (soNgayMuon[i] > 14) {
                        tienPhat = (soNgayMuon[i] - 14) * 5000;
                        trangThai = "QUÁ HẠN";
                    }
                    printf("%-3d | %-10s | %-12s | %-8d | %-12s | %-15d\n", i + 1, maPhieu[i],