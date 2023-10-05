#include <iostream>
#include <map>

using namespace std;

map<string, map<string, string> > account;

int hashingFunction(string password) {
    int hash = 0;

    for (char ch : password) {
        hash = (hash * 31) + static_cast<int>(tolower(ch));
    }

    hash = abs(hash);

    return hash;
}

void registerNow() {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    cout << endl;

    string hashThis = to_string(hashingFunction(password));

    map<string, string> dataDetail;
    dataDetail["username"] = username;

    account[hashThis] = dataDetail;
}

void loginNow() {
    string username, password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    string hashThis = to_string(hashingFunction(password));

    cout << endl;

    if (account.find(hashThis) != account.end()) {
        cout << "Login berhasil. Welcome," << account[hashThis]["username"] << "!\n\n";
    } else {
        cout << "Login gagal!\n\n";
    }
}

int main()
{
    while(true) {
        int input;

        cout << "\nPILIH MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Pilih menu: ";
        cin >> input;

        switch (input)
        {
        case 1:
            registerNow();
            break;
        case 2:
            loginNow();
            break;
        case 3:
            break;
        default:
            cout << "Masukkan angka dari 1-3!" << endl;
            break;
        }
    }
    return 0;
}
