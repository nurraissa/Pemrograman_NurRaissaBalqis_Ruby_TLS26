#include <iostream>

int hitungPanjang(const char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

void enkripsiAlien(const char pesan[], char hasil[]) {
    int panjang = hitungPanjang(pesan);
    
    if (panjang == 0) {
        hasil[0] = '\0';
        return;
    }

    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;
        
        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;
        
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }
    
        hasil[i] = nilaiBaru - 1 + 'A';
    }

    hasil[panjang] = '\0';
}

int main() {
    char pesan[1000];
    char hasilSandi[1000];

    std::cout << "Masukkan pesan asli (HURUF KAPITAL): ";
    std::cin >> pesan;

    enkripsiAlien(pesan, hasilSandi);

    std::cout << "Pesan hasil sandi: " << hasilSandi << std::endl;

    return 0;
}
