#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct data {
    string nama;
    string nik;
    string jenisKelamin;
    string golonganDarah;
    string tempatLahir;
    string tanggalLahir;
    string agama;
    string statusPerkawinan;
    string kewarganegaraan;
    string pekerjaan;
    string alamat;
    string rtrw;
    string kelDesa;
    string kecamatan;
    string provinsi;
    string kabupaten;
};

struct Item {
    string kodeItem;
    string tanggalMasuk;
};

struct Pembeli {
    string ktp;
    string waktuDatang;
    string kodeItem;
};

vector<data> ktp;          
vector<Item> inventory;    
queue<Pembeli> antrian;    
stack<Item> riwayatPenjualan; 

void formulir_ktp() {
    int jumlahKTP;
    cout << "Jumlah KTP yang akan dibuat: ";
    cin >> jumlahKTP;
    cin.ignore(); 
    
    for (int x = 0; x < jumlahKTP; x++) {
        data temp;
        cout << "\nData Ke-" << x + 1 << endl;
        cout << "NIK [MAX 16 DIGIT]: ";
        cin >> temp.nik;
        cin.ignore();
        cout << "Nama: ";
        getline(cin, temp.nama);
        cout << "Tempat Lahir: ";
        getline(cin, temp.tempatLahir);
        cout << "Tanggal Lahir: ";
        getline(cin, temp.tanggalLahir);
        cout << "Jenis Kelamin: ";
        getline(cin, temp.jenisKelamin);
        cout << "Golongan Darah: ";
        getline(cin, temp.golonganDarah);
        cout << "Alamat: ";
        getline(cin, temp.alamat);
        cout << "RT/RW: ";
        getline(cin, temp.rtrw);
        cout << "Kel/Desa: ";
        getline(cin, temp.kelDesa);
        cout << "Kecamatan: ";
        getline(cin, temp.kecamatan);
        cout << "Kabupaten: ";
        getline(cin, temp.kabupaten);
        cout << "Provinsi: ";
        getline(cin, temp.provinsi);
        cout << "Agama: ";
        getline(cin, temp.agama);
        cout << "Status Perkawinan: ";
        getline(cin, temp.statusPerkawinan);
        cout << "Pekerjaan: ";
        getline(cin, temp.pekerjaan);
        cout << "Kewarganegaraan: ";
        getline(cin, temp.kewarganegaraan);
        
        ktp.push_back(temp);  
    }

    ofstream file("data_ktp.txt");
    if (file.is_open()) {
        for (int x = 0; x < jumlahKTP; x++) {
            int totalWidth = 40; 
            string provinsiLine = "PROVINSI " + ktp[x].provinsi;
            string kabupatenLine = "KABUPATEN " + ktp[x].kabupaten;

            file << "====================================================" << endl;
            file << setw((totalWidth + provinsiLine.length()) / 2) << provinsiLine << endl;
            file << setw((totalWidth + kabupatenLine.length()) / 2) << kabupatenLine << endl;
            file << "====================================================" << endl;
            file << "NIK             : " << ktp[x].nik << endl;
            file << "Nama            : " << ktp[x].nama << endl;
            file << "Tempat/Tgl Lahir: " << ktp[x].tempatLahir << ", " << ktp[x].tanggalLahir << endl;
            file << "Jenis Kelamin   : " << ktp[x].jenisKelamin;
            file << "     Gol. Darah: " << ktp[x].golonganDarah << endl;
            file << "Alamat          : " << ktp[x].alamat << endl;
            file << "    RT/RW       : " << ktp[x].rtrw << endl;
            file << "    Kel/Desa    : " << ktp[x].kelDesa << endl;
            file << "    Kecamatan   : " << ktp[x].kecamatan << endl;
            file << "Agama           : " << ktp[x].agama << endl;
            file << "Status Kawin    : " << ktp[x].statusPerkawinan << endl;
            file << "Pekerjaan       : " << ktp[x].pekerjaan << endl;
            file << "Kewarganegaraan : " << ktp[x].kewarganegaraan << endl;
            file << "Berlaku Hingga  : SEUMUR HIDUP" << endl;
            file << "====================================================" << endl;
        }
        file.close();
        cout << "\nData berhasil disimpan ke file data_ktp.txt!" << endl;
    } else {
        cout << "\nGagal menyimpan data ke file!" << endl;
    }
}

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

    if (!inventory.empty()) {
        Item item = inventory.front();
        inventory.erase(inventory.begin()); 
        riwayatPenjualan.push(item);

        cout << "Pembeli dengan KTP " << pembeli.ktp << " membeli item " << item.kodeItem << " pada tanggal " << item.tanggalMasuk << endl;
    } else {
        cout << "Tidak ada item dalam inventori!" << endl;
    }
}

void lihatRiwayatPenjualan() {
    if (riwayatPenjualan.empty()) {
        cout << "Belum ada riwayat penjualan!" << endl;
    } else {
        Item terakhir = riwayatPenjualan.top(); 
        cout << "Riwayat Penjualan Terakhir:" << endl;
        cout << "Kode Item: " << terakhir.kodeItem << " | Tanggal Masuk: " << terakhir.tanggalMasuk << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "Menu:\n";
        cout << "1. Admin sign-in\n";
        cout << "2. Entri Item Barang\n";
        cout << "3. Catat Pembeli\n";
        cout << "4. Jual Item Barang\n";
        cout << "5. Cetak Daftar Barang\n";
        cout << "6. Lihat Riwayat Penjualan Terakhir\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                formulir_ktp();
                break;
            case 2:
                entriItem();
                break;
            case 3:
                catatPembeli();
                break;
            case 4:
                jualItem();
                break;
            case 5:
                cout << "Daftar Barang di Gudang:" << endl;
                for (int i = 0; i < inventory.size(); i++) {
                    cout << "Kode Item: " << inventory[i].kodeItem << " | Tanggal Masuk: " << inventory[i].tanggalMasuk << endl;
                }
                break;
            case 6:
                lihatRiwayatPenjualan();
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}

