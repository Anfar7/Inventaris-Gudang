#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string kodeItem;
    string tanggalMasuk;
};

vector<Item> inventory;

void entriItem() {
    for (int i = 0; i < 5; i++) {
        Item item;
        cout << "Masukkan Kode Item: ";
        cin >> item.kodeItem;
        cout << "Masukkan Tanggal Masuk (YYYY-MM-DD): ";
        cin >> item.tanggalMasuk;
        inventory.push_back(item);
    }
}

void jualItem() {
    if (inventory.empty()) {
        cout << "Tidak ada item dalam inventori!" << endl;
        return;
    }

    // Mengambil item terakhir dari inventory (LIFO)
    Item item = inventory.back();
    inventory.pop_back();
    cout << "Item yang dijual: " << item.kodeItem << " pada tanggal " << item.tanggalMasuk << endl;
}

int main() {
    int pilihan;
    do {
        cout << "Menu:\n1. Entri Item\n2. Jual Item\n3. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                entriItem();
                break;
            case 2:
                jualItem();
                break;
            case 3:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}
