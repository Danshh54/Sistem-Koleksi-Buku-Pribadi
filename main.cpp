#include <iostream>
#include <string> 
using namespace std;

const int jmlBaris = 20;
const int jmlKolom = 5;

string dataBuku[jmlBaris][jmlKolom] = {
    {"The Hobbit", "J.R.R. Tolkien", "1937", "Fantasy", "9"},
    {"1984", "George Orwell", "1949", "Dystopian", "8"},
    {"The Lord of the Rings", "J.R.R. Tolkien", "1954", "Fantasy", "10"}
}; //data awal buku

int jmlDataBuku = 3; 

void tambahBuku(const string judul, const string author, const string tahun, const string genre, const string rating) {
    if (jmlDataBuku >= jmlBaris) {
        cout << "Kapasitas penyimpanan buku penuh!" << endl;
        return;
    }
    dataBuku[jmlDataBuku][0] = judul;
    dataBuku[jmlDataBuku][1] = author;
    dataBuku[jmlDataBuku][2] = tahun;
    dataBuku[jmlDataBuku][3] = genre;
    dataBuku[jmlDataBuku][4] = rating;
    jmlDataBuku++;
} 

void tampilBukuJudul() {
    if (jmlDataBuku == 0) {
        cout << "Tidak ada data buku!" << endl;
        return;
    }

    for (int i = 0; i < jmlDataBuku - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jmlDataBuku; j++) {
            if (dataBuku[j][0] < dataBuku[minIndex][0]) { 
                minIndex = j;
            }
        }
        if (minIndex != i) {
            for (int k = 0; k < jmlKolom; k++) {
                swap(dataBuku[i][k], dataBuku[minIndex][k]);
            }
        }
    }
    cout << "\nDaftar Buku Berdasarkan Judul (A-Z):" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < jmlDataBuku; i++) {
        cout << "Judul : " << dataBuku[i][0] << endl;
        cout << "Author: " << dataBuku[i][1] << endl;
        cout << "Tahun : " << dataBuku[i][2] << endl;
        cout << "Genre : " << dataBuku[i][3] << endl;
        cout << "Rating: " << dataBuku[i][4] << endl;
        cout << "-------------------------------------" << endl;
    }
}

void tampilBukuTahunRating(int z) {
    if (jmlDataBuku == 0) {
        cout << "Tidak ada data buku!" << endl;
        return;
    }

    for (int i = 0; i < jmlDataBuku - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < jmlDataBuku; j++) {
            if (stoi(dataBuku[j][z]) > stoi(dataBuku[maxIndex][z])) { 
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            for (int k = 0; k < jmlKolom; k++) {
                swap(dataBuku[i][k], dataBuku[maxIndex][k]);
            }
        }
    }

    if (z == 2)
        cout << "\nDaftar Buku Berdasarkan Tahun Terbit:" << endl;
    else {
        cout << "\nDaftar Buku Berdasarkan Rating:" << endl;
    }
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < jmlDataBuku; i++) {
        cout << "Judul : " << dataBuku[i][0] << endl;
        cout << "Author: " << dataBuku[i][1] << endl;
        cout << "Tahun : " << dataBuku[i][2] << endl;
        cout << "Genre : " << dataBuku[i][3] << endl;
        cout << "Rating: " << dataBuku[i][4] << endl;
        cout << "-------------------------------------" << endl;
    }
}
void cariBuku(const string keyword) {
    bool ditemukan = false;

    cout << "\nHasil Pencarian: \"" << keyword << "\"\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < jmlDataBuku; i++) {
        if (dataBuku[i][0].find(keyword) != string::npos ||
            dataBuku[i][1].find(keyword) != string::npos)
        {
            ditemukan = true;
            cout << "Judul : " << dataBuku[i][0] << endl;
            cout << "Author: " << dataBuku[i][1] << endl;
            cout << "Tahun : " << dataBuku[i][2] << endl;
            cout << "Genre : " << dataBuku[i][3] << endl;
            cout << "Rating: " << dataBuku[i][4] << endl;
            cout << "-------------------------------------\n";
        }
    }

    if (!ditemukan)
        cout << "Tidak ada buku yang cocok!\n";
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

void editBuku(const string keyword) {
    int index = -1;

    for (int i = 0; i < jmlDataBuku; i++) {
        if (dataBuku[i][0] == keyword || dataBuku[i][1] == keyword) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Buku tidak ditemukan!\n";
        return;
    }

    cin.ignore();

    string judul, author, tahun, genre, rating;

    cout << "Masukan Judul baru: ";
    getline(cin, judul);

    cout << "Masukan Author baru: ";
    getline(cin, author);

    int t = validasiInput("Masukan Tahun terbit baru: ");
    cin.ignore();

    cout << "Masukan Genre baru: ";
    getline(cin, genre);

    int r = validasiInput("Masukan Rating baru (1–10): ");

    dataBuku[index][0] = judul;
    dataBuku[index][1] = author;
    dataBuku[index][2] = to_string(t);
    dataBuku[index][3] = genre;
    dataBuku[index][4] = to_string(r);

    cout << "Data buku berhasil diperbarui!\n";
}

void hapusBuku(const string keyword) {
    int index = -1;

    for (int i = 0; i < jmlDataBuku; i++) {
        if (dataBuku[i][0] == keyword || dataBuku[i][1] == keyword) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Buku tidak ditemukan!\n";
        return;
    }

    for (int i = index; i < jmlDataBuku - 1; i++) {
        for (int k = 0; k < jmlKolom; k++) {
            dataBuku[i][k] = dataBuku[i + 1][k];
        }
    }

    jmlDataBuku--;
    cout << "Buku berhasil dihapus!\n";
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
            while (true) {
                a = validasiInput("Masukan tahun terbit buku: ");
                cin.ignore();
                if (a < 1000 || a > 2024) {
                    cout << "Tahun terbit tidak valid! Masukkan antara 1000 sampai 2024." << endl;
                    continue;
                }
                break;
            }
            
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
            cin.ignore();
            string key;
            cout << "Masukkan judul/author buku: ";
            getline(cin, key);
            cariBuku(key);
        }
        if (pilihan == 4) {
            cout << "Fitur Edit Buku belum tersedia." << endl;
        }
        if (pilihan == 5) {
            cin.ignore();
            string key;
            cout << "Masukkan judul/author yang ingin dihapus: ";
            getline(cin, key);
            hapusBuku(key);
        }
        if (pilihan == 6) {
            cout << "Program berakhir king." << endl;
            break;
        }
    } while (pilihan != 6);
        
    return 0;
}