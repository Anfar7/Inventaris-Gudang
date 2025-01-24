#include <iostream>
#include <fstream>
#include <iomanip> 
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

data ktp[50];
int pilih[6];

void formulir_ktp() {
    cout << "Jumlah KTP yang akan dibuat: ";
    cin >> pilih[0];

    for (int x = 0; x < pilih[0]; x++) {
        cout << "\nData Ke-" << x + 1 << endl;
        cout << "NIK [MAX 16 DIGIT]: ";
        cin >> ktp[x].nik;
        cin.ignore();
        cout << "Nama: ";
        getline(cin, ktp[x].nama);
        cout << "Tempat Lahir: ";
        getline(cin, ktp[x].tempatLahir);
        cout << "Tanggal Lahir: ";
        getline(cin, ktp[x].tanggalLahir);
        cout << "Jenis Kelamin: ";
        getline(cin, ktp[x].jenisKelamin);
        cout << "Golongan Darah: ";
        getline(cin, ktp[x].golonganDarah);
        cout << "Alamat: ";
        getline(cin, ktp[x].alamat);
        cout << "RT/RW: ";
        getline(cin, ktp[x].rtrw);
        cout << "Kel/Desa: ";
        getline(cin, ktp[x].kelDesa);
        cout << "Kecamatan: ";
        getline(cin, ktp[x].kecamatan);
        cout << "Kabupaten: ";
        getline(cin, ktp[x].kabupaten);
        cout << "Provinsi: ";
        getline(cin, ktp[x].provinsi);
        cout << "Agama: ";
        getline(cin, ktp[x].agama);
        cout << "Status Perkawinan: ";
        getline(cin, ktp[x].statusPerkawinan);
        cout << "Pekerjaan: ";
        getline(cin, ktp[x].pekerjaan);
        cout << "Kewarganegaraan: ";
        getline(cin, ktp[x].kewarganegaraan);
    }

    ofstream file("data_ktp.txt");
    if (file.is_open()) {
        for (int x = 0; x < pilih[0]; x++) {
            int totalWidth = 40; // Lebar total kolom untuk perataan
            string provinsiLine = "PROVINSI " + ktp[x].provinsi;
            string kabupatenLine = "KABUPATEN " + ktp[x].kabupaten;

            file << "====================================================" << endl;

            // Cetak teks tengah menggunakan totalWidth dan panjang teks
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

int main() {
    formulir_ktp();
    return 0;
}

