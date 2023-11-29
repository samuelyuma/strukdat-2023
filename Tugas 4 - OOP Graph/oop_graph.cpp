#include <iostream>
#include <stack>
#include <list>
#include <stdio.h>
using namespace std;

class Titik
{
public:
    int id;
    string tempat;
    int x;
    int y;

    Titik(int id, string tempat, int x, int y)
    {
        this->id = id;
        this->tempat = tempat;
        this->x = x;
        this->y = y;
    }
};

class Peta
{
private:
    int jumlahTitik;
    list<int> *adjacency_list;
    list<Titik> *adjacency_list_point;
    int **adjacency_matrix;

public: 
    Peta(int jumlahTitik)
    {
        this->jumlahTitik = jumlahTitik;
        this->inisialisasiAdjList(jumlahTitik);
        this->inisialisasiAdjListTitik(jumlahTitik);
        this->inisialisasiAdjMatrix(jumlahTitik);
    }

    ~Peta()
    {
        delete[] adjacency_list;
        delete[] adjacency_list_point;
    }

    void inisialisasiAdjList(int jumlahTitik)
    {
        adjacency_list = new list<int>[jumlahTitik];
    }

    void inisialisasiAdjListTitik(int jumlahTitik)
    {
        adjacency_list_point = new list<Titik>[jumlahTitik];
        adjacency_list_point[0].push_back(Titik(0, "Kos", 100, 100));
        adjacency_list_point[1].push_back(Titik(1, "BME", 200, 150));
        adjacency_list_point[2].push_back(Titik(2, "Sakinah", 300, 200));
        adjacency_list_point[3].push_back(Titik(3, "Pakuwon City", 400, 250));
        adjacency_list_point[4].push_back(Titik(4, "ITS Mart", 500, 300));
        adjacency_list_point[5].push_back(Titik(5, "Indomaret", 600, 350));
        adjacency_list_point[6].push_back(Titik(6, "Alfamart", 700, 400));
        adjacency_list_point[7].push_back(Titik(7, "Apotek K24", 800, 450));
        adjacency_list_point[8].push_back(Titik(8, "Bengkel AHASS", 900, 500));
        adjacency_list_point[9].push_back(Titik(9, "Perumdos Blok T", 1000, 550));
    }

    void inisialisasiAdjMatrix(int jumlahTitik)
    {
        adjacency_matrix = new int *[jumlahTitik];
        for (int i = 0; i < jumlahTitik; i++)
        {
            adjacency_matrix[i] = new int[jumlahTitik];
            for (int j = 0; j < jumlahTitik; j++)
            {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    void tambahLintasan(int titik_awal, int titik_tujuan)
    {
        adjacency_matrix[titik_awal][titik_tujuan] += 1;
        adjacency_matrix[titik_tujuan][titik_awal] += 1;

        adjacency_list[titik_awal].push_back(titik_tujuan);

        adjacency_list_point[titik_awal].push_back(adjacency_list_point[titik_tujuan].front());
    }

    void tampilkanAdjList()
    {
        list<int>::iterator i;

        for (int v = 0; v < jumlahTitik; v++)
        {
            cout << v << " -> ";
            for (i = adjacency_list[v].begin(); i != adjacency_list[v].end(); ++i)
            {
                cout << (*i);
                if (next(i, 1) != adjacency_list[v].end())
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjListTitik()
    {
        for (int v = 0; v < jumlahTitik; v++)
        {
            list<Titik> places = adjacency_list_point[v];
            for (const Titik &titik : places)
            {
                cout << titik.tempat;
                if (&titik != &places.back())
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjMatrix()
    {
        for (int i = 0; i < jumlahTitik; i++)
        {
            for (int j = 0; j < jumlahTitik; j++)
            {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int jumlahTitik = 10;
    Peta petaKu(jumlahTitik);

    petaKu.tambahLintasan(0, 5);
    petaKu.tambahLintasan(0, 6);
    petaKu.tambahLintasan(1, 5);
    petaKu.tambahLintasan(0, 7);
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(1, 3);
    petaKu.tambahLintasan(2, 1);
    petaKu.tambahLintasan(2, 4);
    petaKu.tambahLintasan(2, 6);
    petaKu.tambahLintasan(2, 9);
    petaKu.tambahLintasan(3, 1);
    petaKu.tambahLintasan(3, 8);
    petaKu.tambahLintasan(3, 9);
    petaKu.tambahLintasan(4, 2);
    petaKu.tambahLintasan(4, 9);
    petaKu.tambahLintasan(5, 0);
    petaKu.tambahLintasan(5, 1);
    petaKu.tambahLintasan(5, 7);
    petaKu.tambahLintasan(6, 0);
    petaKu.tambahLintasan(6, 2);
    petaKu.tambahLintasan(7, 0);
    petaKu.tambahLintasan(7, 5);
    petaKu.tambahLintasan(7, 8);
    petaKu.tambahLintasan(8, 3);
    petaKu.tambahLintasan(8, 7);
    petaKu.tambahLintasan(9, 2);
    petaKu.tambahLintasan(9, 3);
    petaKu.tambahLintasan(9, 4);

    cout << "\nAdjacency List\n";
    petaKu.tampilkanAdjList();

    cout << "\nAdjacency List Titik\n";
    petaKu.tampilkanAdjListTitik();

    cout << "\nAdjacency Matrix\n";
    petaKu.tampilkanAdjMatrix();

    return 0;
}