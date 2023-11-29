#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

//untuk mendapatkan nilai maksimum(tak hingga) dari int
const int INF = numeric_limits<int>::max();

            //graph[pa].push_back({t, b}),                  0,               0;
void dijkstra(vector<vector<pair<int, int>>>& graph, int mulai, vector<int>& jarak){
    int n = graph.size();
    jarak.assign(n, INF);                               //di-assgin dengan nilai inf
    jarak[mulai] = 0;
    //inisiasi pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, mulai});                                //memasukkan nilai jarak dan awal

    while(!pq.empty()){
        int u = pq.top().second;                        //mengambil titik dengan jarak terkecil dari pq
        int jarak_u = pq.top().first;                   //mengambil nilai jarak terkecil
        pq.pop();                                       //hapus elemen dari pq

        if(jarak_u > jarak[u]){
            continue;                                   //jika nilai jarak lebih besar dari titik maka lanjut
        }

        for(const auto& edge : graph[u]){
            int v = edge.first;                         //deklarasi tujuan
            int beban_jaraknya = edge.second;           //beban jarak dari u ke v

            if(jarak[u] + beban_jaraknya < jarak[v]){
                jarak[v] = jarak[u] + beban_jaraknya;
                pq.push({jarak[v], v});                 //memasukkan nilai jarak dan titik v ke pq
            }
        }
    }
}

int main(){
    //jumlah node yang akan digunakan dari 0 sampai ke (n - 1)
    int n;
    cout << "masukkan jumlah titik: ";
    cin >> n;
    n = n + 1;
    //isisiasi graph
    vector<vector<pair<int, int>>> graph(n);    

    //graph[posisi sekarang] dipush {ke, dengan beban}
    int pa, t, b;
    cout << "masukkan: (posisi_awal) (tujuan) (beban)\n";
    while(true){
        cin >> pa;
        if(pa == -2) break;
        cin >> t >> b;
        graph[pa].push_back({t, b});
    }

    /*
input:
5
0 1 3
0 2 4
1 2 2
1 3 4
2 3 4
2 4 7
3 4 1
3 5 6
4 5 3
-2
    */

    int titik_awal = 0;
    vector<int> jarak;

    //masuk ke void
    dijkstra(graph, titik_awal, jarak);

    //ini adalah output 
    cout << "jarak terdekat dari " << titik_awal << ":\n";
    for(int i = 0; i < n; ++i){
        cout << "ketitik " << i << ": " << jarak[i] << endl;
    }

    return 0;
}
