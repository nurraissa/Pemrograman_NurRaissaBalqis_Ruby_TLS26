#include <iostream>

// Fungsi buatan sendiri untuk menghitung panjang string (char array)
int hitungPanjang(const char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Fungsi buatan sendiri untuk mengubah pesan ke dalam sandi alien
void enkripsiAlien(const char pesan[], char hasil[]) {
    int panjang = hitungPanjang(pesan);
    
    if (panjang == 0) {
        hasil[0] = '\0';
        return;
    }

    // Huruf pertama tidak mengalami perubahan
    hasil[0] = pesan[0];

    // Mengolah huruf kedua hingga terakhir
    for (int i = 1; i < panjang; i++) {
        // Menghitung nilai alfabet (A = 1, B = 2, ..., Z = 26)
        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;
        
        // Pergeseran nilai berdasarkan huruf sebelumnya
        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;
        
        // Jika hasil pergeseran melewati Z (26)
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }
        
        // Mengubah kembali nilai angka menjadi karakter huruf
        hasil[i] = nilaiBaru - 1 + 'A';
    }
    
    // Memberikan karakter null terminator di akhir string
    hasil[panjang] = '\0';
}

int main() {
    char pesan[1000];
    char hasilSandi[1000];

    std::cout << "Masukkan pesan asli (HURUF KAPITAL): ";
    std::cin >> pesan;

    // Memanggil fungsi enkripsi buatan sendiri
    enkripsiAlien(pesan, hasilSandi);

    std::cout << "Pesan hasil sandi: " << hasilSandi << std::endl;

    return 0;
}