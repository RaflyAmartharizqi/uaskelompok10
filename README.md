# uaskelompok10

# Deskripsi Program 
    Terdapat sebuah blok di pelabuhan yang berisi tiga tumpukan (stack). Tiap tumpukan berisi lima kontainer. Masing- masing kontainer memiliki kode kontainer yang
  berbeda. Tumpukan pertama berisi kontainer tujuan Surabaya dengan kode tujuan ‘s’. Tumpukan kedua berisi kontainer tujuan Lombok dengan kode tujuan ‘l’. Tumpukan 
  terakhir berisi kontainer tujuan Papua dengan kode tujuan ‘p’. Tiap tumpukan didapatkan dari proses bongkar muat dari truk yang datang sesuai dengan antrian (Queue). 
  Sedangkan untuk truk sendiri memiliki nopol, kode kontainer, dan tujuan yang berbeda. Prosesnya adalah truk datang sesuai antrian (Queue) lalu menginputkan nopol, kode 
  kontainer, dan kode tujuan. Selanjutnya akan diproses di dequeue (dikeluarkan) nanti data kode kontainer dan kode tujuan akan masuk ke proses stack menurut dengan 
  tujuannya masing-masing. 

# Materi yang Digunakan 
  1. Queue
	Queue atau antrean adalah sekumpulan data yang penambahan elemennya melalui sebuah ujung yang disebut sisi belakang (rear), dan penghapusannya (pengambilan elemen) 
  dilakukan dari ujung lain yang disebut sisi depan (front). Prinsip kerja dari Queue adalah “First In First Out” yang artinya “masuk pertama keluar pertama”.      
  Struktur 
  data queue disusun secara horizontal dan terbuka di kedua ujungnya. Ujung pertama (head) digunakan untuk menghapus data sedangkan ujung lainnya (tail) digunakan 
  untuk 
  menyisipkan data. Operasi-operasi dasar pada Queue adalah :
      •	Enqueue	: Menambahkan elemen ke akhir antrian
      •	Dequeue	: Menghapus elemen dari depan antrian
      •	IsEmpty	: Memeriksa apakah antrian kosong
      •	IsFull		: Memeriksa apakah antrian sudah penuh
      •	Peek		: Mendapatkan nilai bagian depan antrian tanpa menghapusnya
      •	Initialize	: Membuat antrian baru tanpa elemen data (kosong)
  Namun, secara umum antrian memiliki 2 operasi utama, yaitu enqueue dan dequeue.
  Dalam program ini Queue diimplementasikan untuk membuat antrean pada truk
  
  2.	Stack
	Stack atau tumpukan adalah sebuah kumpulan elemen yang menggunakan prinsip LIFO (Last In First Out), yaitu data yang terakhir kali dimasukkan akan pertama kali 
  keluar dari stack tersebut. Stack dapat diibaratkan sebuah tumpukan barang dalam sebuah tempat yang hanya memiliki satu pintu diatasnya (memasukan dan mengambil 
  barang hanya dapat dilakukan melalui pintu itu). Sehingga barang yang akan dikeluarkan pertama kali adalah barang yang terakhir kali dimasukan. Maka, operasi insert 
  dan delete dilakukan di bagian puncak tumpukan.  Jenis-jenis operasi stack yaitu :
        •	Pop		: Operasi yang berguna untuk penghapusan elemen.
        •	Push		: Operasi yang berguna untuk memasukkan elemen ke dalam stack atau tumpukan.
        •	isFull		: Operasi yang berguna untuk mengetahui apakah tumpukan sudah penuh atau belum.
        •	isEmpty 	: Operasi yang berguna untuk memeriksa apakah tumpukan kosong atau tidak.
        •	Peek 		: Operasi yang digunakan untuk mengetahui data teratas dari tumpukan tanpa harus menghapusnya.
  Dalam program ini Stack diimplementasikan untuk membuat tmpukan kontainer.

# Algoritma Program 
  
  1. Memasukkan  data truk dan container (nopol, kode_kontainer, tujuan(s,l,p) ke antrian (queue)
  2. Saat Truk dikeluarkan dari antrian (queue) maka data kode_kontainer dan tujuan akan masuk ke tumpukan kontainer (stack) sesuai dengan pengelompokkan tujuannya.  
     Hal ini karena saat truk dikeluarkan dari antrian maka kontainer diangkat ke tumpukan kontainer sesuai tujuannya.
  3. Apabila tumpukan kontainer penuh maka truk dikeluarkan bersama dengan kontainernya tanpa menambahkannya ke tumpukan kontainer.
  4. Kemudian terdapat pilihan untuk menampilkan tumpukan kontainer dan mengeluarkan kontainernya.
