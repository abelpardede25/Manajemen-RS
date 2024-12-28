#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan informasi pasien
typedef struct {
    int id;
    char nama[100];
    char alamat[200];
    char jenisPenyakit[100];
    char spesialis[100];
    int lamaMenginap;
    char jenisKamar[50];
} Pasien;

// Struktur untuk menyimpan informasi kamar
typedef struct {
    int nomorKamar;
    char status[20];  // "kosong" atau "terisi"
    char fasilitas[100];
    int lamaInap;
} Kamar;

// Struktur untuk menyimpan informasi dokter
typedef struct {
    int idDokter;
    char nama[100];
    char spesialisasi[100];
    char jadwal[100];  // Hari dan jam praktek
} Dokter;

// Daftar Pasien, Kamar, dan Dokter
Pasien pasien[100];
Kamar kamar[50];
Dokter dokter[20];

// Jumlah entri data
int jumlahPasien = 0;
int jumlahKamar = 0;
int jumlahDokter = 0;

// Fungsi untuk menambahkan pasien baru
void tambahPasien() {
    Pasien p;
    printf("Masukkan ID Pasien: ");
    scanf("%d", &p.id);
    getchar();  // Mengosongkan buffer
    printf("Masukkan Nama Pasien: ");
    fgets(p.nama, sizeof(p.nama), stdin);
    p.nama[strcspn(p.nama, "\n")] = '\0';  // Menghapus newline
    printf("Masukkan Alamat Pasien: ");
    fgets(p.alamat, sizeof(p.alamat), stdin);
    p.alamat[strcspn(p.alamat, "\n")] = '\0';
    printf("Masukkan Jenis Penyakit: ");
    fgets(p.jenisPenyakit, sizeof(p.jenisPenyakit), stdin);
    p.jenisPenyakit[strcspn(p.jenisPenyakit, "\n")] = '\0';
    printf("Apakah butuh dokter spesialis (ya/tidak): ");
    fgets(p.spesialis, sizeof(p.spesialis), stdin);
    p.spesialis[strcspn(p.spesialis, "\n")] = '\0';
    printf("Masukkan Lama Menginap (dalam hari): ");
    scanf("%d", &p.lamaMenginap);
    getchar();
    printf("Masukkan Jenis Kamar (VIP/Reguler/dll): ");
    fgets(p.jenisKamar, sizeof(p.jenisKamar), stdin);
    p.jenisKamar[strcspn(p.jenisKamar, "\n")] = '\0';

    pasien[jumlahPasien++] = p;
    printf("Pasien berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar pasien
void tampilkanPasien() {
    printf("Daftar Pasien Rawat Inap:\n");
    for (int i = 0; i < jumlahPasien; i++) {
        printf("%d. %s - %s, Kamar: %s, Lama Menginap: %d hari\n", pasien[i].id, pasien[i].nama, pasien[i].jenisPenyakit, pasien[i].jenisKamar, pasien[i].lamaMenginap);
    }
}

// Fungsi untuk mencari pasien berdasarkan nama
void cariPasien() {
    char namaCari[100];
    printf("Masukkan Nama Pasien yang ingin dicari: ");
    fgets(namaCari, sizeof(namaCari), stdin);
    namaCari[strcspn(namaCari, "\n")] = '\0';

    for (int i = 0; i < jumlahPasien; i++) {
        if (strcmp(pasien[i].nama, namaCari) == 0) {
            printf("Pasien ditemukan:\n");
            printf("ID: %d\nNama: %s\nAlamat: %s\nJenis Penyakit: %s\nSpesialis: %s\nLama Menginap: %d hari\nJenis Kamar: %s\n", 
                   pasien[i].id, pasien[i].nama, pasien[i].alamat, pasien[i].jenisPenyakit, pasien[i].spesialis, pasien[i].lamaMenginap, pasien[i].jenisKamar);
            return;
        }
    }
    printf("Pasien dengan nama %s tidak ditemukan.\n", namaCari);
}

// Fungsi untuk menghapus data pasien
void hapusPasien() {
    int id;
    printf("Masukkan ID Pasien yang ingin dihapus: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahPasien; i++) {
        if (pasien[i].id == id) {
            for (int j = i; j < jumlahPasien - 1; j++) {
                pasien[j] = pasien[j + 1];
            }
            jumlahPasien--;
            printf("Pasien dengan ID %d berhasil dihapus.\n", id);
            return;
        }
    }
    printf("Pasien dengan ID %d tidak ditemukan.\n", id);
}

// Fungsi untuk menambahkan data kamar
void tambahKamar() {
    Kamar k;
    printf("Masukkan Nomor Kamar: ");
    scanf("%d", &k.nomorKamar);
    getchar();
    printf("Masukkan Status Kamar (kosong/terisi): ");
    fgets(k.status, sizeof(k.status), stdin);
    k.status[strcspn(k.status, "\n")] = '\0';
    printf("Masukkan Fasilitas Kamar: ");
    fgets(k.fasilitas, sizeof(k.fasilitas), stdin);
    k.fasilitas[strcspn(k.fasilitas, "\n")] = '\0';
    printf("Masukkan Lama Inap Kamar (dalam hari): ");
    scanf("%d", &k.lamaInap);

    kamar[jumlahKamar++] = k;
    printf("Kamar berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar kamar
void tampilkanKamar() {
    printf("Daftar Kamar Rumah Sakit:\n");
    for (int i = 0; i < jumlahKamar; i++) {
        printf("Nomor Kamar: %d, Status: %s, Fasilitas: %s, Lama Inap: %d hari\n", kamar[i].nomorKamar, kamar[i].status, kamar[i].fasilitas, kamar[i].lamaInap);
    }
}

// Fungsi untuk memperbarui status kamar
void perbaruiStatusKamar() {
    int nomorKamar;
    printf("Masukkan Nomor Kamar yang ingin diperbarui statusnya: ");
    scanf("%d", &nomorKamar);

    for (int i = 0; i < jumlahKamar; i++) {
        if (kamar[i].nomorKamar == nomorKamar) {
            printf("Status Kamar saat ini: %s\n", kamar[i].status);
            printf("Masukkan Status Baru (kosong/terisi): ");
            getchar();  // Mengosongkan buffer
            fgets(kamar[i].status, sizeof(kamar[i].status), stdin);
            kamar[i].status[strcspn(kamar[i].status, "\n")] = '\0';
            printf("Status kamar telah diperbarui.\n");
            return;
        }
    }
    printf("Kamar dengan nomor %d tidak ditemukan.\n", nomorKamar);
}

// Fungsi untuk menampilkan dashboard
void tampilkanDashboard() {
    printf("\n=== Dashboard Rumah Sakit ===\n");

    // Tampilkan kapasitas kamar
    int totalKamarKosong = 0, totalKamarTerisi = 0;
    for (int i = 0; i < jumlahKamar; i++) {
        if (strcmp(kamar[i].status, "kosong") == 0) {
            totalKamarKosong++;
        } else {
            totalKamarTerisi++;
        }
    }

    printf("Jumlah Kamar Kosong: %d\n", totalKamarKosong);
    printf("Jumlah Kamar Terisi: %d\n", totalKamarTerisi);

    // Tampilkan jumlah pasien
    printf("Jumlah Pasien Rawat Inap: %d\n", jumlahPasien);

    // Tampilkan jumlah dokter
    printf("Jumlah Dokter: %d\n", jumlahDokter);

    // Tampilkan jadwal dokter
    printf("\nJadwal Dokter:\n");
    for (int i = 0; i < jumlahDokter; i++) {
        printf("%s - Spesialis: %s, Jadwal: %s\n", dokter[i].nama, dokter[i].spesialisasi, dokter[i].jadwal);
    }
}

// Fungsi untuk menghitung biaya perawatan
void hitungBiaya() {
    int id;
    printf("Masukkan ID Pasien yang ingin dihitung biayanya: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahPasien; i++) {
        if (pasien[i].id == id) {
            int biayaPerHari = 500000;  // Asumsi biaya per hari
            int biayaTotal = pasien[i].lamaMenginap * biayaPerHari;

            if (strcmp(pasien[i].jenisKamar, "VIP") == 0) {
                biayaTotal += 1000000;  // Biaya tambahan untuk kamar VIP
            }

            printf("Biaya total untuk pasien %s (ID: %d) adalah: Rp %d\n", pasien[i].nama, pasien[i].id, biayaTotal);
            return;
        }
    }
    printf("Pasien dengan ID %d tidak ditemukan.\n", id);
}

// Fungsi untuk menambah dokter
void tambahDokter() {
    Dokter d;
    printf("Masukkan ID Dokter: ");
    scanf("%d", &d.idDokter);
    getchar();
    printf("Masukkan Nama Dokter: ");
    fgets(d.nama, sizeof(d.nama), stdin);
    d.nama[strcspn(d.nama, "\n")] = '\0';
    printf("Masukkan Spesialisasi Dokter: ");
    fgets(d.spesialisasi, sizeof(d.spesialisasi), stdin);
    d.spesialisasi[strcspn(d.spesialisasi, "\n")] = '\0';
    printf("Masukkan Jadwal Dokter: ");
    fgets(d.jadwal, sizeof(d.jadwal), stdin);
    d.jadwal[strcspn(d.jadwal, "\n")] = '\0';

    dokter[jumlahDokter++] = d;
    printf("Dokter berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar dokter
void tampilkanDokter() {
    printf("Daftar Dokter Rumah Sakit:\n");
    for (int i = 0; i < jumlahDokter; i++) {
        printf("ID: %d, Nama: %s, Spesialisasi: %s, Jadwal: %s\n", dokter[i].idDokter, dokter[i].nama, dokter[i].spesialisasi, dokter[i].jadwal);
    }
}

// Menu utama
void menu() {
    int pilihan;

    while (1) {
        printf("\n=== Sistem Manajemen Rumah Sakit ===\n");
        printf("1. Tambah Pasien\n");
        printf("2. Tampilkan Pasien\n");
        printf("3. Cari Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Tambah Kamar\n");
        printf("6. Tampilkan Kamar\n");
        printf("7. Perbarui Status Kamar\n");
        printf("8. Hitung Biaya\n");
        printf("9. Tambah Dokter\n");
        printf("10. Tampilkan Dokter\n");
        printf("11. Tampilkan Dashboard\n");
        printf("12. Keluar\n");
        printf("Pilih menu (1-12): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahPasien(); break;
            case 2: tampilkanPasien(); break;
            case 3: cariPasien(); break;
            case 4: hapusPasien(); break;
            case 5: tambahKamar(); break;
            case 6: tampilkanKamar(); break;
            case 7: perbaruiStatusKamar(); break;
            case 8: hitungBiaya(); break;
            case 9: tambahDokter(); break;
            case 10: tampilkanDokter(); break;
            case 11: tampilkanDashboard(); break;
            case 12: printf("Terima kasih! Program selesai.\n"); return;
            default: printf("Pilihan tidak valid.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
