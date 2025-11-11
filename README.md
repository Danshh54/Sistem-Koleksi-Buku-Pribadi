# Sistem-Koleksi-Buku-Pribadi

 readme

Program ini untuk mengelola koleksi buku pribadi. Program ini memungkinkan pengguna untuk menambahkan, menampilkan, mencari, mengedit, dan menghapus data buku dengan mudah. Selain itu, sistem juga menyediakan fitur pengurutan (sorting) berdasarkan judul, genre, dan rating buku. Untuk menjalankan program ini pada VSCode, lakukan ini:

- Buka Visual Studio Code
- Tekan Ctrl + Shift + P (atau Cmd + Shift + P di Mac) untuk membuka Command Palette.Ketik dan pilih “Git: Clone”.
- Ketika diminta untuk URL repositori, tempelkan ini:
https://github.com/Danshh54/Sistem-Koleksi-Buku-Pribadi.git 
- Pilih folder lokal tempat Anda ingin menyimpan proyek
- Setelah kloning, VS Code akan menanyakan apakah Anda ingin membuka repositori. klik “Open”.

Program ini memiliki struktur daftar menu:

[1] Tampilkan Daftar Buku
    [1] Berdasarkan Judul (A–Z)
    [2] Berdasarkan Genre (A–Z)
    [3] Berdasarkan Rating (Tertinggi–Terendah)
    [4] Kembali ke Menu Utama
[2] Tambahkan Buku  
[3] Pencarian Buku  
[4] Pengeditan Buku  
[5] Penghapusan Buku  
[6] Keluar Program

Penjelasan pilihan daftar menu:

1. Menampilkan Daftar Buku
Menampilkan seluruh koleksi buku yang tersimpan dalam array dua dimensi dengan opsi pengurutan:
- Berdasarkan judul (A–Z)
- Berdasarkan genre (A–Z)
- Berdasarkan rating (descending)

2. Menambahkan Buku
Pengguna dapat menambahkan buku baru dengan data:
Judul:
Author:
Genre:
Rating:
Data yang dimasukkan akan langsung disimpan oleh program.

3. Pencarian Buku
Mencari buku berdasarkan judul atau author menggunakan metode Sequential Search. Pencarian mendukung substring, jadi pengguna cukup memasukkan sebagian kata dari judul atau nama penulis.

4. Pengeditan Buku
Mengubah data buku yang sudah ada, termasuk:
Judul
Author
Genre
Rating
Setelah konfirmasi, data buku diperbarui langsung dalam array.

5. Penghapusan Buku
Menghapus data buku dari daftar dengan konfirmasi pengguna terlebih dahulu.

6. Keluar Program
Opsi untuk menutup program atau kembali ke menu utama.

Catatan, Program ini ditujukan untuk pengelolaan koleksi buku pribadi, bukan untuk skala besar. Algoritma dipilih berdasarkan kemudahan implementasi dan efisiensi untuk jumlah data kecil.

JANGAN, memasukan input yang tidak sesuai pada daftar menu, pilihan metode penampilan daftar buku, atau konfirmasi pengeditan dan penghapusan. Melakukan hal tersebut akan membuat program akan menampilkan pesan error.


