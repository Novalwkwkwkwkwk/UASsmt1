#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

struct Mahasiswa {
    char nim[50];
    char nama[50];
    char prodi[50];  
};

void membersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void tampilkanMahasiswa(struct Mahasiswa mahasiswa[], int jumlahMahasiswa) {
    printf("\nDaftar Mahasiswa:\n");
    printf("NIM\tNama\tProdi\n");

    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("%s\t%s\t%s\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].prodi);
    }
}

int cariMahasiswa(struct Mahasiswa mahasiswa[], int jumlahMahasiswa, char targetNIM[50]) {
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (strcmp(mahasiswa[i].nim, targetNIM) == 0) {
            return i; 
        }
    }
    return -1;
}

void hapusMahasiswa(struct Mahasiswa mahasiswa[], int *jumlahMahasiswa, int index) {
    
    for (int i = index; i < *jumlahMahasiswa - 1; i++) {
        strcpy(mahasiswa[i].nim, mahasiswa[i + 1].nim);
        strcpy(mahasiswa[i].nama, mahasiswa[i + 1].nama);
        strcpy(mahasiswa[i].prodi, mahasiswa[i + 1].prodi);
    }
    (*jumlahMahasiswa)--;
}

int main() {
    struct Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;
    int pilihan;
    char targetNIM[50];

    while (1) {
        printf("\nProgram Pendataan Mahasiswa\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus Mahasiswa\n");
        printf("3. Edit Mahasiswa\n");
        printf("4. Tampilkan Mahasiswa\n");
        printf("5. Cari Mahasiswa\n");
        printf("6. Keluar\n");
        printf("Pilih menu (1-6): ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            
            if (jumlahMahasiswa < MAX_MAHASISWA) {
                printf("Masukkan NIM: ");
                scanf("%s", mahasiswa[jumlahMahasiswa].nim);

                printf("Masukkan Nama: ");
                scanf("%s", mahasiswa[jumlahMahasiswa].nama);

                printf("Masukkan Prodi: ");
                scanf("%s", mahasiswa[jumlahMahasiswa].prodi);  
                jumlahMahasiswa++;
            } else {
                printf("Kuota mahasiswa penuh. Tidak dapat menambahkan lebih banyak mahasiswa.\n");
            }

        
            membersihkanBuffer();
        } else if (pilihan == 2) {
          
            printf("Masukkan NIM mahasiswa yang akan dihapus: ");
            scanf("%s", targetNIM);

            int index = cariMahasiswa(mahasiswa, jumlahMahasiswa, targetNIM);
            if (index != -1) {
                hapusMahasiswa(mahasiswa, &jumlahMahasiswa, index);
                printf("Mahasiswa dengan NIM %s telah dihapus.\n", targetNIM);
            } else {
                printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", targetNIM);
            }

            
            membersihkanBuffer();
        } else if (pilihan == 3) {
           
            printf("Fitur ini belum diimplementasikan.\n");
        } else if (pilihan == 4) {

            tampilkanMahasiswa(mahasiswa, jumlahMahasiswa);
        } else if (pilihan == 5) {
           
            printf("Masukkan NIM yang dicari: ");
            scanf("%s", targetNIM);

            int index = cariMahasiswa(mahasiswa, jumlahMahasiswa, targetNIM);
            if (index != -1) {
                printf("\nMahasiswa ditemukan:\n");
                printf("NIM\tNama\tProdi\n");
                printf("%s\t%s\t%s\n", mahasiswa[index].nim, mahasiswa[index].nama, mahasiswa[index].prodi);
            } else {
                printf("\nMahasiswa dengan NIM %s tidak ditemukan.\n", targetNIM);
            }

            
            membersihkanBuffer();
        } else if (pilihan == 6) {
           
            printf("Program selesai.\n");
            break;
        } else {
            
            printf("Pilihan tidak valid. Silakan masukkan pilihan 1-6.\n");

            
            membersihkanBuffer();
        }
    }

    return 0;
}
