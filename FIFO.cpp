#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Item {
    string kodeItem;
    string tanggalMasuk;
};

struct Pembeli {
    string ktp;
    string waktuDatang;
    string kodeItem;
};

queue<Item> inventory;
queue<Pembeli> antrian;

void entriItem() {
    for (int i = 0; i < 5; i++) {
        Item item;
        cout << "Masukkan Kode Item: ";
        cin >> item.kodeItem;
        cout << "Masukkan Tanggal Masuk (YYYY-MM-DD): ";
        cin >> item.tanggalMasuk;
        inventory.push(item);
    }
}

void catatPembeli() {
    Pembeli pembeli;
    cout << "Masukkan KTP Pembeli: ";
    cin >> pembeli.ktp;
    cout << "Masukkan Waktu Datang (HH:MM): ";
    cin >> pembeli.waktuDatang;
    cout << "Masukkan Kode Item yang dibeli: ";
    cin >> pembeli.kodeItem;
    antrian.push(pembeli);
}

void jualItem() {
    if (antrian.empty()) {
        cout << "Tidak ada pembeli dalam antrian!" << endl;
        return;
    }

    Pembeli pembeli = antrian.front();
    antrian.pop();

    // Mengambil item pertama dari inventory (FIFO)
    if (!inventory.empty()) {
        Item item = inventory.front();
        inventory.pop();
        cout << "Pembeli dengan KTP " << pembeli.ktp << " membeli item " << item.kodeItem << " pada tanggal " << item.tanggalMasuk << endl;
    } else {
        cout << "Tidak ada item dalam inventori!" << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "Menu:" << endl;
		cout << "1. Entri Item." << endl;
		cout << "2. Catat Pembeli." << endl;
		cout << "3. Jual Item." << endl;
		cout << "4. Keluar." << endl;
		cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                entriItem();
                break;
            case 2:
                catatPembeli();
                break;
            case 3:
                jualItem();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
