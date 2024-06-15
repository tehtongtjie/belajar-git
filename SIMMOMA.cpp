#include <iostream>
#include <conio.h>
using namespace std;

string putih = "\033[0m";
string ungu = "\033[35m";

int jumlahMataKuliah = 0;

struct mataKuliah
{
    string namaMataKuliah;
    int kkm;
    int persentasePraktikum;
    int persentaseTugas;
    int persentasePosttest;
    int nilaiPraktikum;

    struct tugas
    {
        string judulTugas[20];
        string deadlineTugas[20];
        string catatanTugas[20];
        int nilaiTugas[20];
        bool tugasSelesai[20];
    } tgs;

    struct posttest
    {
        string judulPosttest[20];
        string deadlinePosttest[20];
        string catatanPosttest[20];
        int nilaiPosttest[20];
        bool posttestSelesai[20];
    } pts;
};
mataKuliah matkul[20];

struct nilai
{
    int totalNilaiPraktikum;
    int totalNilaiTugas;
    int totalNilaiPosttest;
    int totalNilaiMatkul;
};

void tambahMataKuliah(int &jumlahMataKuliah)
{
    system("cls");
    string mataKuliahBaru;
    cout << "  _____  _____  __  __   ____   __  __  __  __            " << endl
         << " / ____||_   _||  \\/  | / __ \\ |  \\/  ||  \\/  |    /\\    " << endl
         << "| (___    | |  | \\  / || |  | || \\  / || \\  / |   /  \\   " << endl
         << " \\___ \\   | |  | |\\/| || |  | || |\\/| || |\\/| |  / /\\ \\  " << endl
         << " ____) | _| |_ | |  | || |__| || |  | || |  | | / ____ \\ " << endl
         << "|_____/ |_____||_|  |_| \\____/ |_|  |_||_|  |_|/_/    \\_\\ " << endl
         << endl;

    cout << "Masukkan nama mata kuliah: ";
    cin >> ws;
    getline(cin, mataKuliahBaru);
    for (int i = 0; i < jumlahMataKuliah; i++)
    {
        if (matkul[i].namaMataKuliah == mataKuliahBaru)
        {
            cout << "Mata kuliah tersebut sudah ditambahkan!" << endl;
            system("pause");
            return;
        }
    }
    matkul[jumlahMataKuliah].namaMataKuliah = mataKuliahBaru;

    do
    {
        cout << "Masukkan nilai KKM mata kuliah: ";
        cin >> matkul[jumlahMataKuliah].kkm;
    } while (matkul[jumlahMataKuliah].kkm < 1 || matkul[jumlahMataKuliah].kkm > 100);
    cout << "Masukkan persentase untuk nilai praktikum (Jika tidak ada masukkan 0): ";
    cin >> matkul[jumlahMataKuliah].persentasePraktikum;
    cout << "Masukkan persentase untuk nilai tugas: ";
    cin >> matkul[jumlahMataKuliah].persentaseTugas;
    cout << "Masukkan jumlah persentase untuk nilai posttest: ";
    cin >> matkul[jumlahMataKuliah].persentasePosttest;
    if (matkul[jumlahMataKuliah].persentasePraktikum + matkul[jumlahMataKuliah].persentaseTugas + matkul[jumlahMataKuliah].persentasePosttest < 100 || matkul[jumlahMataKuliah].persentasePraktikum + matkul[jumlahMataKuliah].persentaseTugas + matkul[jumlahMataKuliah].persentasePosttest > 100)
    {
        cout << "Persentase nilai mata kuliah tidak valid!" << endl;
        system("pause");
        return;
    }
    cout << "Mata kuliah berhasil ditambahkan..." << endl;
    jumlahMataKuliah++;

    system("pause");
}

void tambahTugasDanPosttest()
{
    system("cls");
    string namaMataKuliahBaru;
    bool selesai = false;
    int pilihan = 1;
    int indeksMatkul;

    cout << " ___  ____  __  __  _____  __  __  __  __    __   " << endl
         << "/ __)(_  _)(  \\/  )(  _  )(  \\/  )(  \\/  )  /__\\ " << endl
         << "\\__ \\ _)(_  )    (  )(_)(  )    (  )    (  /(__)\\ " << endl
         << "(___/(____)(_/\\/\\_)(_____)(_/\\/\\_)(_/\\/\\_)(__)(__)" << endl
         << endl;

    if (jumlahMataKuliah == 0)
    {
        cout << "Belum ada mata kuliah yang ditambahkan..." << endl;
        system("pause");
        return;
    }

    cout << "Masukkan nama mata kulah: ";
    cin >> ws;
    getline(cin, namaMataKuliahBaru);

    bool mataKuliahDitemukan = false;
    for (int i = 0; i < jumlahMataKuliah; i++)
    {
        if (matkul[i].namaMataKuliah == namaMataKuliahBaru)
        {
            mataKuliahDitemukan = true;
            indeksMatkul = i;
            break;
        }
    }

    if (!mataKuliahDitemukan)
    {
        cout << "Tidak ada mata kuliah bernama " << namaMataKuliahBaru << " yang ditambahkan sebelumnya!" << endl;
        system("pause");
        return;
    }
    while (!selesai)
    {
        system("cls");
        cout << "-----------------------------" << endl
             << "|      Jenis Pekerjaan       |" << endl
             << "------------------------------" << endl
             << (pilihan == 1 ? ungu : putih)
             << ">> Tugas " << putih << endl
             << (pilihan == 2 ? ungu : putih)
             << ">> Posttest" << putih << endl;
        char tombol = _getch();
        switch (tombol)
        {
        case 'w':
        case 'W':
        case 72:
            if (pilihan > 1)
                pilihan--;
            else
                pilihan = 2;
            break;
        case 's':
        case 'S':
        case 80:
            if (pilihan < 2)
                pilihan++;
            else
                pilihan = 1;
            break;
        case 13:
            switch (pilihan)
            {
            case 1:
                for (int i = 0; i < 20; i++)
                {
                    if (matkul[indeksMatkul].tgs.judulTugas[i] == "")
                    {
                        cout << "Masukkan judul tugas: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].tgs.judulTugas[i]);
                        cout << "Masukkan deadline tugas: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].tgs.deadlineTugas[i]);
                        cout << "Masukkan catatan tugas: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].tgs.catatanTugas[i]);
                        cout << "Tugas " << matkul[indeksMatkul].tgs.judulTugas[i] << " berhasil ditambahkan..." << endl;
                        system("pause");
                        return;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 20; i++)
                {
                    if (matkul[indeksMatkul].pts.judulPosttest[i] == "")
                    {
                        cout << "Masukkan judul posttest: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].pts.judulPosttest[i]);
                        cout << "Masukkan deadline posttest: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].pts.deadlinePosttest[i]);
                        cout << "Masukkan catatan posttest: ";
                        cin >> ws;
                        getline(cin, matkul[indeksMatkul].pts.catatanPosttest[i]);
                        cout << "Posttest " << matkul[indeksMatkul].pts.judulPosttest[i] << " berhasil ditambahkan..." << endl;
                        system("pause");
                        return;
                    }
                }
                break;
            }
            break;
        default:
            break;
        }
    }
    system("pause");
}

void tampilkanTugasDanPosttest()
{
    system("cls");
    cout << " _______  _______  _______  _______  _______  _______  _______ " << endl
         << "|     __||_     _||   |   ||       ||   |   ||   |   ||   _   |" << endl
         << "|__     | _|   |_ |       ||   -   ||       ||       ||       |" << endl
         << "|_______||_______||__|_|__||_______||__|_|__||__|_|__||___|___|" << endl
         << endl;

    if (jumlahMataKuliah <= 0)
    {
        cout << "Belum ada mata kuliah yang ditambahkan..." << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < jumlahMataKuliah; i++)
    {
        if (matkul[i].namaMataKuliah != "")
        {
            cout << "--------------------------------------------------------------------------------------------------------------------" << endl
                 << "Mata Kuliah: " << matkul[i].namaMataKuliah << endl
                 << "--------------------------------------------------------------------------------------------------------------------" << endl
                 << "Judul Tugas\t\tDeadline\t\tCatatan\t\tStatus" << endl
                 << "--------------------------------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < 20; j++)
            {
                if (matkul[i].tgs.judulTugas[j] != "")
                {
                    cout << j + 1 << ". " << matkul[i].tgs.judulTugas[j] << "\t\t"
                         << matkul[i].tgs.deadlineTugas[j] << "\t\t"
                         << matkul[i].tgs.catatanTugas[j] << "\t\t";
                    if (matkul[i].tgs.tugasSelesai[j] == true)
                    {
                        cout << "[ ]Belum Selesai   [X]Selesai";
                    }
                    else
                    {
                        cout << "[X]Belum Selesai   [ ]Selesai";
                    }
                    cout << endl;
                }
            }
            cout << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------" << endl
                 << "Judul Posttest\t\tDeadline\t\tCatatan\t\tStatus" << endl
                 << "--------------------------------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < 20; j++)
            {
                if (matkul[i].pts.judulPosttest[j] != "")
                {
                    cout << j + 1 << ". " << matkul[i].pts.judulPosttest[j] << "\t\t"
                         << matkul[i].pts.deadlinePosttest[j] << "\t\t"
                         << matkul[i].pts.catatanPosttest[j] << "\t\t";
                    if (matkul[i].pts.posttestSelesai[j] == true)
                    {
                        cout << "[ ]Belum Selesai   [X]Selesai";
                    }
                    else
                    {
                        cout << "[X]Belum Selesai   [ ]Selesai";
                    }
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
    cout << "Tekan F untuk mencentang pekerjaan, Tekan enter untuk kembali..." << endl;
    string namaMataKuliahBaru;
    int indeksCentang, pilihan, pilihanPekerjaan;
    char tombol = _getch();
    switch (tombol)
    {
    case 'F':
    case 'f':
        cout << "Masukkan nama mata kuliah dari pekerjaan yang ingin dicentang: ";
        cin >> ws;
        getline(cin, namaMataKuliahBaru);
        for (int i = 0; i < jumlahMataKuliah; i++)
        {
            if (namaMataKuliahBaru == matkul[i].namaMataKuliah)
            {
                indeksCentang = i;
                break;
            }
            if (i == jumlahMataKuliah - 1)
            {
                cout << "Tidak ada mata kuliah bernama " << namaMataKuliahBaru << " yang ditambahkan sebelumnya!";
                return;
            }
        }
        cout << "Pilih pekerjaan yang ingin dicentang: " << endl
             << "1. Tugas" << endl
             << "2. Posttest" << endl
             << ">> ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            for (int i = 0; i < 20; i++)
            {
                if (matkul[indeksCentang].tgs.judulTugas[i] != "")
                {
                    cout << i + 1 << ". " << matkul[indeksCentang].tgs.judulTugas[i] << endl;
                }
            }
            do
            {
                cout << "Pilih nomor yang ingin dicentang: ";
                cin >> pilihanPekerjaan;
            } while (matkul[indeksCentang].tgs.judulTugas[pilihanPekerjaan - 1] == "");
            cout << "Masukkan Nilai: ";
            cin >> matkul[indeksCentang].tgs.nilaiTugas[pilihanPekerjaan - 1];
            matkul[indeksCentang].tgs.tugasSelesai[pilihanPekerjaan - 1] = true;
            cout << "Berhasil dicentang..." << endl;
            system("pause");
            break;
        case 2:
            for (int i = 0; i < 20; i++)
            {
                if (matkul[indeksCentang].pts.judulPosttest[i] != "")
                {
                    cout << i + 1 << ". " << matkul[indeksCentang].pts.judulPosttest[i] << endl;
                }
            }
            do
            {
                cout << "Pilih nomor yang ingin dicentang: ";
                cin >> pilihanPekerjaan;
            } while (matkul[indeksCentang].pts.judulPosttest[pilihanPekerjaan - 1] == "");
            cout << "Masukkan Nilai: ";
            cin >> matkul[indeksCentang].pts.nilaiPosttest[pilihanPekerjaan - 1];
            matkul[indeksCentang].pts.posttestSelesai[pilihanPekerjaan - 1] = true;
            cout << "Berhasil dicentang..." << endl;
            system("pause");
            break;
        }
        break;
    case 13:
        system("pause");
        break;
    }
}

void sistemManajemenTugas()
{
    int pilihan = 1;
    bool selesai = false;

    while (!selesai)
    {
        system("cls");
        cout << "-----------------------------" << endl
             << "|      Manajemen Tugas      |" << endl
             << "-----------------------------" << endl
             << (pilihan == 1 ? ungu : putih)
             << "-----------------------------" << endl
             << "|  Tambah Tugas & Posttest  |" << endl
             << "-----------------------------" << putih << endl
             << (pilihan == 2 ? ungu : putih)
             << "-----------------------------" << endl
             << "|      Tampilkan Tugas      |" << endl
             << "-----------------------------" << putih << endl
             << (pilihan == 3 ? ungu : putih)
             << "-----------------------------" << endl
             << "|          Kembali          |" << endl
             << "-----------------------------" << putih << endl;

        char tombol = _getch();

        switch (tombol)
        {
        case 'w':
        case 'W':
        case 72:
            if (pilihan > 1)
                pilihan--;
            else
                pilihan = 3;
            break;
        case 's':
        case 'S':
        case 80:
            if (pilihan < 3)
                pilihan++;
            else
                pilihan = 1;
            break;
        case 13:
            switch (pilihan)
            {
            case 1:
                tambahTugasDanPosttest();
                break;
            case 2:
                tampilkanTugasDanPosttest();
                break;
            case 3:
                selesai = true;
                break;
            }
            break;
        }
    }
}

void sistemManajemenNilai()
{
    system("cls");
    cout << " ___  _  __ __  ___  __ __  __ __  ___ " << endl
         << "/ __>| ||  \\  \\| . ||  \\  \\|  \\  \\| . |" << endl
         << "\\__ \\| ||     || | ||     ||     ||   |" << endl
         << "<___/|_||_|_|_|`___'|_|_|_||_|_|_||_|_|" << endl
         << endl;

    int totalNilaiTugas[20] = {0};
    int totalNilaiPosttest[20] = {0};
    int TotalNilai;

    if (jumlahMataKuliah <= 0)
    {
        cout << "Belum ada mata kuliah yang ditambahkan..." << endl;
        system("pause");
        return;
    }

    cout << "Apakah Anda ingin menambahkan nilai praktikum? (y/n): ";
    char pilihan;
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y')
    {
        string namaMataKuliah;
        int nilaiPraktikum;

        cout << "Masukkan nama mata kuliah: ";
        cin >> ws;
        getline(cin, namaMataKuliah);

        bool mataKuliahDitemukan = false;
        for (int i = 0; i < jumlahMataKuliah; i++)
        {
            if (matkul[i].namaMataKuliah == namaMataKuliah)
            {
                mataKuliahDitemukan = true;
                if (matkul[i].persentasePraktikum > 0)
                {
                    cout << "Masukkan nilai praktikum: ";
                    cin >> nilaiPraktikum;
                    matkul[i].nilaiPraktikum = nilaiPraktikum;
                    cout << "Nilai praktikum berhasil ditambahkan!" << endl;
                }
                else
                {
                    cout << "Mata kuliah ini tidak memiliki praktikum." << endl;
                }
                break;
            }
        }
        if (!mataKuliahDitemukan)
        {
            cout << "Mata kuliah tidak ditemukan." << endl;
        }
    }

    for (int i = 0; i < jumlahMataKuliah; i++)
    {
        if (matkul[i].namaMataKuliah != "")
        {
            cout << "-----------------------------------------------------" << endl
                 << matkul[i].namaMataKuliah << endl
                 << "-----------------------------------------------------" << endl
                 << "Tugas\t\tPosttest" << endl
                 << "-----------------------------------------------------" << endl;
            for (int j = 0; j < 20; j++)
            {
                if (matkul[i].tgs.nilaiTugas[j] != -1)
                {
                    cout << matkul[i].tgs.nilaiTugas[j] << "\t\t";
                    totalNilaiTugas[i] += matkul[i].tgs.nilaiTugas[j];
                }
                else
                {
                    cout << "-\t\t";
                }

                if (matkul[i].pts.nilaiPosttest[j] != -1)
                {
                    cout << matkul[i].pts.nilaiPosttest[j] << endl;
                    totalNilaiPosttest[i] += matkul[i].pts.nilaiPosttest[j];
                }
                else
                {
                    cout << "-\t\t" << endl;
                }
            }

            cout << "-----------------------------------------------------" << endl
                 << "Nilai Praktikum: ";
            if (matkul[i].persentasePraktikum > 0)
            {
                cout << matkul[i].nilaiPraktikum << endl;
            }
            else
            {
                cout << "-" << endl;
            }

            TotalNilai = (totalNilaiPosttest[i] * matkul[i].persentasePosttest / 100) +
                         (totalNilaiTugas[i] * matkul[i].persentaseTugas / 100) +
                         (matkul[i].nilaiPraktikum * matkul[i].persentasePraktikum / 100);

            cout << "---------------------------------------------------------------" << endl
                 << "Total Nilai Tugas = " << totalNilaiTugas[i] << endl
                 << "Total Nilai Posttest = " << totalNilaiPosttest[i] << endl
                 << "Total Nilai Praktikum = " << matkul[i].nilaiPraktikum << endl
                 << "Total Nilai = " << TotalNilai << endl;

            if (TotalNilai >= matkul[i].kkm)
            {
                cout << "Nilai Anda di atas KKM" << endl;
            }
            else
            {
                cout << "Nilai Anda di bawah KKM" << endl;
            }

            cout << endl
                 << endl;
        }
    }
    system("pause");
}

int main()
{
    int pilihan = 1;
    bool selesai = false;

    while (!selesai)
    {
        system("cls");
        cout << "--------------------------" << endl
             << "|        SIMOMMA         |" << endl
             << "--------------------------" << endl
             << (pilihan == 1 ? ungu : putih)
             << "--------------------------" << endl
             << "|   Tambah Mata Kuliah   |" << endl
             << "--------------------------" << putih << endl
             << (pilihan == 2 ? ungu : putih)
             << "--------------------------" << endl
             << "| Sistem Manajemen Tugas |" << endl
             << "--------------------------" << putih << endl
             << (pilihan == 3 ? ungu : putih)
             << "--------------------------" << endl
             << "| Sistem Manajemen Nilai |" << endl
             << "--------------------------" << putih << endl
             << (pilihan == 4 ? ungu : putih)
             << "--------------------------" << endl
             << "|          Keluar        |" << endl
             << "--------------------------" << putih << endl;

        char tombol = getch();

        switch (tombol)
        {
        case 'w':
        case 'W':
        case 72:
            if (pilihan > 1)
                pilihan--;
            else
                pilihan = 4;
            break;
        case 's':
        case 'S':
        case 80:
            if (pilihan < 4)
                pilihan++;
            else
                pilihan = 1;
            break;
        case 13:
            switch (pilihan)
            {
            case 1:
                tambahMataKuliah(jumlahMataKuliah);
                break;
            case 2:
                sistemManajemenTugas();
                break;
            case 3:
                sistemManajemenNilai();
                break;
            case 4:
                selesai = true;
                break;
            }
            break;
        }
    }
    return 0;
}