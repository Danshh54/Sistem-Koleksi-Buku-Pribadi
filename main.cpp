#include <iostream>
#include <string> 
using namespace std;

const int jmlBaris = 20;
const int jmlKolom = 5;

string dataBuku[jmlBaris][jmlKolom] = {
    {"The Hobbit", "J.R.R. Tolkien", "1937", "Fantasy", "9"},
    {"1984", "George Orwell", "1949", "Dystopian", "8"},
    {"The Lord of the Rings", "J.R.R. Tolkien", "1954", "Fantasy", "10"},
    {"Hoblit", "Harper Lee", "1960", "Fiction", "9"},
    {"The Silent Archive", "Marion Graves", "2018", "Mystery", "8"},
    {"Echoes of the Fallen", "Ronan Hale", "2021", "Fantasy", "9"},
    {"Digital Souls", "Ari Nakamura", "2019", "Sci-Fi", "7"},
    {"Winds of Yesterday", "Clara Montrose", "2015", "Drama", "6"},
    {"Ironbound Oath", "Gareth Voss", "2022", "Adventure", "9"},
    {"Painted Horizons", "Lina Marquez", "2020", "Romance", "7"},
    {"Fragments of Dawn", "Elio Hartmann", "2016", "Philosophy", "8"},
    {"The Clockmaker’s Paradox", "Sylvia Kerr", "2023", "Sci-Fi", "9"},
    {"Ashes and Remnants", "Dara Kingsley", "2017", "Post-Apocalyptic", "8"}
}; //data awal buku

int jmlDataBuku = 13; 
int arrID[jmlBaris];

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

string keKecil(string text) {
    for (char &c : text) {
        c = tolower(c);
    }
    return text;
}

void cariBuku(const string keyword) {
    bool ditemukan = false;
    int count = 0;
    string kecil = keKecil(keyword);
    for (int i = 0; i < jmlBaris; i++) arrID[i] = -1;

    cout << "\nHasil Pencarian: \"" << keyword << "\"\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < jmlDataBuku; i++) {
        string judulKecil = keKecil(dataBuku[i][0]);
        string authorKecil = keKecil(dataBuku[i][1]);

        if (judulKecil.find(kecil) != string::npos ||
            authorKecil.find(kecil) != string::npos)
        {
            ditemukan = true;
            arrID[count] = i;
            count++;
            cout << "ID    : " << i << endl;
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

int editBuku(int id, const string judul, const string author,
             const string tahun, const string genre, const string rating) 
{
    bool valid = false;
    int pos = -1;

    for (int i = 0; i < jmlBaris; i++) {
        if (arrID[i] == id) {
            valid = true;
            pos = id;
            break;
        }
    }

    if (!valid) {
        return -1; 
    }

    dataBuku[pos][0] = judul;
    dataBuku[pos][1] = author;
    dataBuku[pos][2] = tahun;
    dataBuku[pos][3] = genre;
    dataBuku[pos][4] = rating;

    cout << "Data buku berhasil diperbarui!\n";
    return 0;
}


int hapusBuku(const int id) {
    bool valid = false;
    string bukuNama;
    int pos = -1;

    for (int i = 0; i < jmlBaris; i++) {
        if (arrID[i] == id) {
            valid = true;
            pos = id;
            break;
        }
    }

    if (!valid) {
        return -1;
    }

    bukuNama = dataBuku[pos][0];

    for (int i = pos; i < jmlDataBuku - 1; i++) {
        for (int j = 0; j < jmlKolom; j++) {
            dataBuku[i][j] = dataBuku[i + 1][j];
        }
    }

    jmlDataBuku--;
    cout << "Buku " << bukuNama << " berhasil dihapus!\n";
    return 0;
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
                if (a > 2024) {
                    cout << "Tahun terbit harus maksimal 2024!" << endl;
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
            cin.ignore();
            string key;

            cout << "Masukkan judul/author buku yang ingin diedit: ";
            getline(cin, key);

            cariBuku(key); 

            int id;
            while (true) {
                id = validasiInput("Masukkan ID buku yang ingin diedit: ");

                bool valid = false;
                for (int i = 0; i < jmlBaris; i++) {
                    if (arrID[i] == id) {
                        valid = true;
                        break;
                    }
                }

                if (!valid) {
                    cout << "ID tidak sesuai dengan hasil pencarian!\n";
                    continue;
                }
                break;
            }

            cin.ignore();

            string judul, author, genre;
            int tahunBaru, ratingBaru;

            cout << "Masukkan judul baru: ";
            getline(cin, judul);

            cout << "Masukkan author baru: ";
            getline(cin, author);

            while (true) {
                tahunBaru = validasiInput("Masukkan tahun terbit baru: ");
                cin.ignore();
                if (tahunBaru < 2000 || tahunBaru > 2024) {
                    cout << "Tahun harus 2000 - 2024!\n";
                    continue;
                }
                break;
            }

            cout << "Masukkan genre baru: ";
            getline(cin, genre);

            while (true) {
                ratingBaru = validasiInput("Masukkan rating baru (1–10): ");
                if (ratingBaru < 1 || ratingBaru > 10) {
                    cout << "Rating harus 1–10!\n";
                    continue;
                }
                break;
            }

            editBuku(id, judul, author, to_string(tahunBaru), genre, to_string(ratingBaru));
        }




        if (pilihan == 5) {
            cin.ignore();
            string key;
            cout << "Cari judul yang ingin dihapus: ";
            getline(cin, key);
            int a;
            cariBuku(key);
            while (true) {
                int id;
                id = validasiInput("Masukan ID buku yang ingin dihapus: ");
                a = hapusBuku(id);
                if (a == -1) {
                    cout << "ID tidak sesuai dengan hasil pencarian!\n";
                    continue;
                }
                else {
                    break;
                }
            }
        }
        if (pilihan == 6) {
            cout << "Program berakhir king." << endl;
            break;
        }
    } while (pilihan != 6);
        
    return 0;
}