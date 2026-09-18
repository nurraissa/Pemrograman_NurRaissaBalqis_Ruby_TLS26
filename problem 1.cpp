#include <iostream>

int hitungUkuran(int N, bool tereliminasi[]) {
    int sisa = 0;
    for (int i = 0; i < N; i++) {
        if (!tereliminasi[i]) {
            sisa++;
        }
    }
    return sisa;
}

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

    bool* tereliminasi = new bool[N];
    for (int i = 0; i < N; i++) {
        tereliminasi[i] = false; 
    }

    int current_index = 0; 

    std::cout << "Urutan astronot yang dieliminasi: ";

    // PROSES ELIMINASI
    while (hitungUkuran(N, tereliminasi) > 1) {
        int ukuranSekarang = hitungUkuran(N, tereliminasi);
        
        current_index = (current_index + K - 1) % ukuranSekarang;
        
        int indeksRiil = dapatkanIndeksRiil(current_index, N, tereliminasi);
        int eliminated_astronaut = indeksRiil + 1; 
        
        std::cout << eliminated_astronaut << " ";
        
        tereliminasi[indeksRiil] = true;
        
        if (eliminated_astronaut % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        
        if (K < 2) {
            K = 2;
        }
        
        int ukuranBaru = hitungUkuran(N, tereliminasi);
        if (current_index == ukuranBaru) {
            current_index = 0;
        }
    }

    int astronotTerakhir = 0;
    for (int i = 0; i < N; i++) {
        if (!tereliminasi[i]) {
            astronotTerakhir = i + 1;
            break;
        }
    }

    std::cout << "\nAstronot terakhir yang bertahan: " << astronotTerakhir << std::endl;

    delete[] tereliminasi;

    return 0;
}