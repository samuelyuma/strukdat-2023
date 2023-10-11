#include <iostream>

using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;

void insertData(int newData) {
   struct Node* newNode = new Node;
   newNode->data = newData;
   newNode->next = head;
   head = newNode;
}

void displayData() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout << ptr->data << " ";
      ptr = ptr->next;
   }
}

int main() {
   int input, data;

   while (true) {
      cout << endl << "====== MENU ======" << endl;
      cout << "1. Tambah Data" << endl;
      cout << "2. Tampilkan Data" << endl;
      cout << "3. Keluar" << endl;
      cout << "Pilih: ";
      cin >> input;

      switch (input) {
         case 1:
            cout << "Masukkan data: ";
            cin >> data;
            insertData(data);
            break;
         case 2:
            cout << "Linked list: ";
            displayData();
            cout << endl;
            break;
         case 3:
            return 0;
         default:
            cout << "Pilihan tidak valid.\n";
      }
   }

   return 0;
}