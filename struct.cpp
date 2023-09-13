#include <iostream>
#include <string>  
#include <array>

using namespace std;

#define MAX 100 
int dataMhs = 0, index;

struct Mahasiswa {
    string nama;
    string nrp;
    string jurusan;
    float ipk;
};

void createData(Mahasiswa mhs[]) {
    if (dataMhs < MAX) {
        Mahasiswa *newMhs = new Mahasiswa();
        cout << "Nama: "; cin >> newMhs->nama;
        cout << "NRP: "; cin >> newMhs->nrp;
        cout << "Jurusan: "; cin >> newMhs->jurusan;
        cout << "IPK: "; cin >> newMhs->ipk;

        mhs[dataMhs++] = *newMhs;
        delete newMhs;

        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah maksimum data telah tercapai (100)" << endl;
    }
}

void readData(const Mahasiswa mhs[], int dataMhs) {
    cout << "Daftar Mahasiswa" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < dataMhs; i++) {
        cout << "No. Indeks: " << i << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Jurusan: " << mhs[i].jurusan << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << "----------------" << endl;
    }
}

void updateData(Mahasiswa mhs[]) {
    readData(mhs, dataMhs);

    cout << "Masukkan indeks data yang akan diubah: ";
    cin >> index;

    if(index >= 0 && index < dataMhs) {
        Mahasiswa* changeMhs = new Mahasiswa();
        
        cout << "Nama: "; cin >> changeMhs->nama;
        cout << "NRP: "; cin >> changeMhs->nrp;
        cout << "Jurusan: "; cin >> changeMhs->jurusan;
        cout << "IPK: "; cin >> changeMhs->ipk;

        *changeMhs = mhs[index];
        delete changeMhs;

        cout << "Data berhasil diperbarui!" << endl;
        readData(mhs, dataMhs);
    } else {
        cout << "Indeks tidak valid. Harap masukkan indeks yang sesuai!" << endl;
    }
}

void deleteData(Mahasiswa mhs[]) {
    readData(mhs, dataMhs);

    cout << "Masukkan indeks data yang akan dihapus: ";
    cin >> index;

    if(index >= 0 && index < dataMhs) {
        for(int i = 0; i < dataMhs - 1; i++){
            mhs[i] = mhs[i + 1];
        }
        dataMhs--;
    } else {
        cout << "Index tidak valid. Harap masukkan indeks yang sesuai!" << endl;
    }
}

int main()
{
    Mahasiswa mhs[MAX];

    int pilihan;

    while(true) {
        cout << "- PROGRAM DATA MAHASISWA -" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Tampilkan data mahasiwa" << endl;
        cout << "3. Perbarui data mahasiswa" << endl;
        cout << "4. Hapus data mahasiswa" << endl;
        cout << "5. Keluar" << endl << endl;
        
        cout << "Pilih menu (1/2/3/4/5): "; cin >> pilihan;

        if (pilihan == 1)
        {
            createData(mhs);
        } else if (pilihan == 2) {
            readData(mhs, dataMhs);
        } else if (pilihan == 3) {
            updateData(mhs);
        } else if (pilihan == 4) {
            deleteData(mhs);
        } else if (pilihan == 5) {
            break;
        } else {
            cout << "Input tidak valid. Silahkan masukkan lagi!" << endl;
        }
    }

    return 0;
}
