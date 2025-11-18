#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

vector<vector<string>> dataBuku = {
    {"The Hobbit", "J.R.R. Tolkien", "1937", "Fantasy", "9"},
    {"1984", "George Orwell", "1949", "Dystopian", "8"},
    {"The Lord of the Rings", "J.R.R. Tolkien", "1954", "Fantasy", "10"}
}; //data awal buku

void tambahBuku(const string judul, const string author, const string tahun, const string genre, const string rating) {
    dataBuku.push_back({judul, author, tahun, genre, rating});
} 

void tampilBukuJudul() {
    if (dataBuku.empty()) {
        cout << "Tidak ada data buku!" << endl;
        return;
    }

    for (int i = 0; i < dataBuku.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < dataBuku.size(); j++) {
            if (dataBuku[j][0] < dataBuku[minIndex][0]) { 
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(dataBuku[i], dataBuku[minIndex]);
        }
    }

    cout << "\nDaftar Buku Berdasarkan Judul (A-Z):" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < dataBuku.size(); i++) {
        cout << "Judul : " << dataBuku[i][0] << endl;
        cout << "Author: " << dataBuku[i][1] << endl;
        cout << "Tahun : " << dataBuku[i][2] << endl;
        cout << "Genre : " << dataBuku[i][3] << endl;
        cout << "Rating: " << dataBuku[i][4] << endl;
        cout << "-------------------------------------" << endl;
    }
}

void tampilBukuTahunRating(int z) {
    int index = z; 
    if (dataBuku.empty()) {
        cout << "Tidak ada data buku!" << endl;
        return;
    }

    for (int i = 0; i < dataBuku.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < dataBuku.size(); j++) {
            if (stoi(dataBuku[j][z]) > stoi(dataBuku[maxIndex][z])) { 
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(dataBuku[i], dataBuku[maxIndex]);
        }
    }

    cout << "\nDaftar Buku Berdasarkan Tahun Terbit:" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < dataBuku.size(); i++) {
        cout << "Judul : " << dataBuku[i][0] << endl;
        cout << "Author: " << dataBuku[i][1] << endl;
        cout << "Tahun : " << dataBuku[i][2] << endl;
        cout << "Genre : " << dataBuku[i][3] << endl;
        cout << "Rating: " << dataBuku[i][4] << endl;
        cout << "-------------------------------------" << endl;
    }
}

void cariBuku(const string keyword) {

}

int validasiInput(const string pesan) {
    int nilai;
    
    while (true) {
        cout << pesan;
        cin >> nilai;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka! Coba lagi." << endl;
            continue;
        }
        return nilai;
    }
}

int main() {
    string judul, author, tahun, genre, rating;
    int a, b, pilihan;
    do {
        cout << "\nProgram Koleksi Buku Pribadi" << endl;
        cout << "=============================" << endl;
        cout << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Cari Buku" << endl;
        cout << "4. Edit Buku" << endl;
        cout << "5. Hapus Buku" << endl;
        cout << "6. Keluar" << endl;
        while (true) {
            pilihan = validasiInput("Pilih menu (1-6): ");
            if (pilihan < 1 || pilihan > 6) {
                cout << "Pilih dari pilihan menu yang tersedia (1-6)!" << endl;
                continue;
            }
            break;
        }
        
        if (pilihan == 1) {
            cin.ignore();
            
            while (true) {
                cout << "Masukan judul buku: ";
                getline(cin, judul);
                if (judul == "") {
                    cout << "Judul buku tidak boleh kosong!" << endl;
                    continue;
                }
                break;
            }
            while (true) {
                cout << "Masukan author buku: ";
                getline(cin, author);
                if (author == "") {
                    cout << "Author buku tidak boleh kosong!" << endl;
                    continue;
                }
                break;
            }

            a = validasiInput("Masukan tahun terbit buku: ");
            cin.ignore();

            while (true) {
                cout << "Masukan genre buku: ";
                getline(cin, genre);
                if (genre == "") {
                    cout << "Genre buku tidak boleh kosong!" << endl;
                    continue;
                }
                break;
            }

            while (true) {
                b = validasiInput("Masukan rating buku: ");
                if (b < 1 || b > 10) {
                cout << "Rating harus antara 1 sampai 10!" << endl;
                continue;
                }
                break;
            }

            tahun = to_string(a);
            rating = to_string(b);
            tambahBuku(judul, author, tahun, genre, rating);
            cout << "Buku berhasil ditambahkan!" << endl;
        }
        if (pilihan == 2) {
            int pilihanTampil;
            cout << "\nPilihan Tampilkan Buku:" << endl;
            cout << "1. Tampilkan berdasarkan Judul"<< endl;
            cout << "2. Tampilkan berdasarkan Tahun Terbit" << endl;
            cout << "3. Tampilkan berdasarkan Rating" << endl;
            while (true) {
                pilihanTampil = validasiInput("Pilih menu (1-3): ");
                if (pilihanTampil == 1) {
                    tampilBukuJudul();
                    break;
                } else if (pilihanTampil == 2) {
                    tampilBukuTahunRating(2);
                    break;
                } else if (pilihanTampil == 3) {
                    tampilBukuTahunRating(4);
                    break;
                } else {
                cout << "Pilih dari pilihan menu yang tersedia (1-3)!" << endl;
                }
            }
        }
        if (pilihan == 3) {
            
        }
        if (pilihan == 4) {
            cout << "Fitur Edit Buku belum tersedia." << endl;
        }
        if (pilihan == 5) {
            cout << "Fitur Hapus Buku belum tersedia." << endl;
        }
        if (pilihan == 6) {
            cout << "Program berakhir king." << endl;
            break;
        }
    } while (pilihan != 6);
        
    return 0;
}