#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100 
int dataMhs = 0;
int indeks;

struct Mahasiswa {
    string nama;
    string nrp;
    int umur;
    float ipk;
};

void createData(Mahasiswa mhs[]) {
    if (dataMhs < MAX) {
        Mahasiswa *newMhs = new Mahasiswa();
        cout << "Nama: "; cin >> newMhs->nama;
        cin.ignore();
        cout << "NRP: "; cin >> newMhs->nrp;
        cin.ignore();
        cout << "Umur: "; cin >> newMhs->umur;
        cin.ignore();
        cout << "IPK: "; cin >> newMhs->ipk;
        cin.ignore();

        mhs[dataMhs++] = *newMhs;
        delete newMhs;

        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah maksimum data telah tercapai (100)" << endl;
    }
}

void readData(const Mahasiswa mhs[], int dataMhs) {
    cout << "--------------------------" << endl;
    cout << "---- Daftar Mahasiswa ----" << endl;
    
    for (int i = 0; i < dataMhs; i++) {
        cout << "--------------------------" << endl;
        cout << "No. Indeks: " << i << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << fixed << setprecision(1) << "IPK: " << mhs[i].ipk << endl;
    }
}

void updateData(Mahasiswa mhs[]) {
    readData(mhs, dataMhs);

    cout << endl << "Masukkan indeks data yang akan diubah: ";
    cin >> indeks;

    if(indeks >= 0 && indeks < dataMhs) {
        Mahasiswa* changeMhs = new Mahasiswa();
        
        cout << "Nama: "; cin >> changeMhs->nama;
        cin.ignore();
        cout << "NRP: "; cin >> changeMhs->nrp;
        cin.ignore();
        cout << "Umur: "; cin >> changeMhs->umur;
        cin.ignore();
        cout << "IPK: "; cin >> changeMhs->ipk;
        cin.ignore();

        mhs[indeks] = *changeMhs;

        cout << "Data berhasil diperbarui!" << endl;
        readData(mhs, dataMhs);

        delete changeMhs;
    } else {
        cout << "Indeks tidak valid. Harap masukkan indeks yang sesuai!" << endl;
    }
}

void deleteData(Mahasiswa mhs[]) {
    readData(mhs, dataMhs);

    cout << "Masukkan indeks data yang akan dihapus: ";
    cin >> indeks;

    if(indeks >= 0 && indeks < dataMhs) {
        for(int i = indeks; i < dataMhs - 1; i++){
            mhs[i] = mhs[i + 1];
        }
        dataMhs--;

        cout << "Indeks berhasil dihapus!" << endl;
        readData(mhs, dataMhs);
    } else {
        cout << "indeks tidak valid. Harap masukkan indeks yang sesuai!" << endl;
    }
}

int main()
{
    Mahasiswa mhs[MAX];

    int pilihan;

    while(true) {
        cout << "--------------------------" << endl;
        cout << "- PROGRAM DATA MAHASISWA -" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Tampilkan data mahasiwa" << endl;
        cout << "3. Perbarui data mahasiswa" << endl;
        cout << "4. Hapus data mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "--------------------------" << endl;
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
