#include <iostream>

// Fungsi buatan sendiri untuk menghitung ukuran array yang tersisa
int hitungUkuran(int N, bool tereliminasi[]) {
    int sisa = 0;
    for (int i = 0; i < N; i++) {
        if (!tereliminasi[i]) {
            sisa++;
        }
    }
    return sisa;
}

// Fungsi buatan sendiri untuk mencari indeks riil berdasarkan indeks logis lingkaran
int dapatkanIndeksRiil(int indeksLogis, int N, bool tereliminasi[]) {
    int hitung = 0;
    for (int i = 0; i < N; i++) {
        if (!tereliminasi[i]) {
            if (hitung == indeksLogis) {
                return i;
            }
            hitung++;
        }
    }
    return -1;
}

int main() {
    int N, K;
    
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai hitungan awal (K): ";
    std::cin >> K;

    // ALOKASI MEMORI MANUAL: Membuat array boolean dinamis sesuai nilai N
    bool* tereliminasi = new bool[N];
    for (int i = 0; i < N; i++) {
        tereliminasi[i] = false; // Mengisi nilai awal false
    }

    int current_index = 0; 

    std::cout << "Urutan astronot yang dieliminasi: ";

    // PROSES ELIMINASI
    while (hitungUkuran(N, tereliminasi) > 1) {
        int ukuranSekarang = hitungUkuran(N, tereliminasi);
        
        // Hitung posisi astronot ke-K dalam lingkaran
        current_index = (current_index + K - 1) % ukuranSekarang;
        
        // Ambil nomor astronot yang dieliminasi
        int indeksRiil = dapatkanIndeksRiil(current_index, N, tereliminasi);
        int eliminated_astronaut = indeksRiil + 1; 
        
        std::cout << eliminated_astronaut << " ";
        
        // Hapus astronot tersebut dari lingkaran
        tereliminasi[indeksRiil] = true;
        
        // Perbarui nilai K berdasarkan aturan ganjil genap
        if (eliminated_astronaut % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        
        // Batas minimum K
        if (K < 2) {
            K = 2;
        }
        
        // Putar kembali ke indeks 0 jika menunjuk ke ujung ukuran baru
        int ukuranBaru = hitungUkuran(N, tereliminasi);
        if (current_index == ukuranBaru) {
            current_index = 0;
        }
    }

    // Mencari astronot terakhir yang bertahan
    int astronotTerakhir = 0;
    for (int i = 0; i < N; i++) {
        if (!tereliminasi[i]) {
            astronotTerakhir = i + 1;
            break;
        }
    }

    std::cout << "\nAstronot terakhir yang bertahan: " << astronotTerakhir << std::endl;

    // MENGHAPUS MEMORI MANUAL (Mencegah memory leak)
    delete[] tereliminasi;

    return 0;
}