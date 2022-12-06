#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <fstream>

void prosesPembelian();
void daftarPelanggan();
void qualityControl();
void newQC();
void listQC();
void transaction();
void status();

using namespace std;


string input;
int meja = 0;
int kursi = 0;
int lemari = 0;
int rejectMeja;
int rejectKursi;
int rejectLemari;
int ttlhg = 0;
int downPayment;
float kayu = 0;
float sisakayu = 0;
int hgmeja = 0;
int hgkursi = 0;
int hglemari = 0;
int stockkayu = 0;
int diskon;
float nilai = 0;
float skmeja = 0;
float skkursi = 0;
float sklemari = 0;
float kayuTambahan = 0;
string nama;
string alamat;

void main()
{
	string i = "\n\n\n\t\t\tMAIN MENU\n\t\t==========================================\n\t\t\t[1] Membuat Pesanan Baru \n\t\t\t[2] Daftar Pesanan \n\t\t\t[3] Quality Control\n\t\t\t[4] TRANSACTION\n\t\t\t[5] STATUS PEMBAYARAN\n\t\t\t[0] Exit\n\t\t==========================================\n\t\t:";

	cout << i;


	while (true) {

		cin >> input;

		if (input == "1")
		{
			system("cls");
			prosesPembelian();

		}
		else if (input == "2")
		{
			system("cls");
			daftarPelanggan();
		}
		else if (input == "3")
		{
			system("cls");
			qualityControl();
		}
		else if (input == "0")
		{
			exit(0);
			system("cls");
		}
		else if (input == "4")
		{
			system("cls");
			transaction();
		}
		else if (input == "5")
		{
			system("cls");
			status();
		}
		else
		{
			system("cls");
			cout << i;
			cout << "Masukan input sesuai yang ada di atas [1], [2], [3], [4], [0].\n\t\t:";
		}
	}
}


void prosesPembelian()
{
	ofstream dataPelanggan;
	dataPelanggan.open("data.txt", ios::app);

	//const string y/n digunakan untuk menjawab opsi 
	const string y = "yes";
	const string n = "no";

	bool berhasilproduksimeja = false;
	bool berhasilproduksikursi = false;
	bool berhasilproduksilemari = false;

	int i;
	cout << "\n\n\n\t\tNOMOR PELANGGAN: "; cin >> i; // menambahkan nomer pelanggan dengan nomer 00000

	system("cls");

	for (; i <= 99999; i++) {
		cin.clear();
		cout << "\n\n\n\t\tNomor Pelanggan\t\t\t\t: ";
		cout << setfill('0') << setw(5);
		cout << i;


		dataPelanggan << "\n\t\tNOMOR PESANAN\t\t: " << setfill('0') << setw(5) << i;

		cout << "\n\t\tMasukan Nama Pelanggan\t\t\t: "; getline(cin, nama); getline(cin, nama); cout;
		cout << "\t\tMasukan Alamat Pelanggan\t\t: "; getline(cin, alamat);
		dataPelanggan << "\n\t\tNAMA PELANGGAN\t\t: " << nama << endl;
		dataPelanggan << "\t\tALAMAT PELANGGAN\t: " << alamat << endl;

		\
		//new fiture 
	anotherInput:

		system("cls");
		cout << "\n\n\n\t\t\LIST MABEL\n\t\t==========================================\n\t\t\t[1] KURSI \n\t\t\t[2] MEJA \n\t\t\t[3] LEMARI\n\t\t\t[0] ENTER\n\t\t==========================================\n\t\t:";



		cin >> input;
		if (input == "1") {
			cout << "\n\n\n\t\t[KURSI]";
			cout << "\n\t\tMasukan Jumlah Mabel\t\t: ";
			cin >> kursi;



			cout << "\t\tMasukan Jumlah Kayu\t\t: ";
			cin >> skkursi;
			cout << "\t\tMasukan Harga\t\t\t: Rp ";
			cin >> hgkursi;

			dataPelanggan << "\t\tJUMLAH KURSI\t\t: ";
			dataPelanggan << kursi << "  ( Rp " << hgkursi << " )" << endl;
			goto anotherInput;
		}
		else if (input == "2") {
			cout << "\n\n\n\t\t[MEJA]";
			cout << "\n\t\tMasukan Jumlah Mabel\t\t: ";
			cin >> meja;


			cout << "\t\tMasukan Jumlah Kayu\t\t: ";
			cin >> skmeja;
			cout << "\t\tMasukan Harga\t\t\t: Rp ";
			cin >> hgmeja;

			dataPelanggan << "\t\tJUMLAH MEJA\t\t: ";
			dataPelanggan << meja << " ( Rp " << hgmeja << " )" << endl;
			goto anotherInput;
		}
		else if (input == "3") {
			cout << "\n\n\n\t\t[LEMARI]";
			cout << "\n\t\tMasukan Jumlah Mabel\t\t: ";
			cin >> lemari;


			cout << "\t\tMasukan Jumlah Kayu\t\t: ";
			cin >> sklemari;
			cout << "\t\tMasukan Harga\t\t\t: Rp ";
			cin >> hglemari;

			dataPelanggan << "\t\tJUMLAH LEMARI\t\t: ";
			dataPelanggan << lemari << " ( Rp " << hglemari << " )" << endl;

			goto anotherInput;
		}
		else if (input == "0") {
			if (meja > 0 || kursi > 0 || lemari > 0) {
				goto skip;
			}
			else {
				goto anotherInput;
			}
		}
		else {
			goto anotherInput;
			cout << "value wrong";
		}

	skip:
		system("cls");

		float jumlahkayumeja = meja * skmeja;
		float jumlahkayulemari = lemari * sklemari;
		float jumlahkayukursi = kursi * skkursi;
		float jumlahproduksi = jumlahkayumeja + jumlahkayulemari + jumlahkayukursi;

		float jumlahJadiKursi;
		float jumlahJadiMeja;
		float jumlahJadiLemari;


		cout << "\t\tJumlah Kebutuhan Kayu\t\t: ";
		cout << jumlahproduksi << endl;

		do {
			cout << "\t\tJumlah Pembelian Kayu Jati\t: ";
			cin >> stockkayu;
			cout << "\t\tJumlah Stock Kayu\t\t: ";

			cout << stockkayu << endl << endl;

			if (stockkayu < jumlahproduksi)
			{
				cout << "\t\tKayu tidak memcukupi\t\t\n";
			}
			else
			{
				break;
			}

		} while (true);


		system("cls");



		cout << "\n\n\n\t\tStatus : ";


		if (jumlahkayumeja != 0 && stockkayu > jumlahkayumeja)
		{
			stockkayu -= jumlahkayumeja;
			berhasilproduksimeja = true;
			cout << "\n\t\tMeja Dalam Proses Pembuatan" << endl;
		}

		if (jumlahkayukursi > 0 && stockkayu >= jumlahkayukursi)
		{
			stockkayu -= jumlahkayukursi;
			berhasilproduksikursi = true;
			cout << "\t\tKursi Dalam Proses Pembuatan" << endl;
		}

		if (jumlahkayulemari > 0 && stockkayu >= jumlahkayulemari) {
			stockkayu -= jumlahkayulemari;
			berhasilproduksilemari = true;
			cout << "\t\tLemari Dalam Proses Pembuatan" << endl;
		}

		//quality controll

		cout << "\n\n\t\tSisa kayu\t\t: ";
		cout << stockkayu << endl << endl;
		cout << "\n\t\tTotal Harga Yang Harus dibayar: Rp ";
		ttlhg = meja * hgmeja + kursi * hgkursi + lemari * hglemari;

		//flag fiture

		dataPelanggan << "\t\tTOTAL HARGA\t\t: Rp ";
		dataPelanggan << ttlhg << endl;

		cout << ttlhg << endl;

		if ((ttlhg >= 50000000) && (ttlhg < 80000000) )
		{
			diskon = ttlhg - (0.1 * ttlhg);
			cout << "\n\n\t\tBELANJA MENCAPAI RP 50.000.000\n\t\tPOTONGAN HARGA SEBESAR 10% \n\n\n\t\tSPECIAL OFFER: Rp " << diskon;
			dataPelanggan << "\t\t10% OFF\t\t\t: " << diskon << endl << endl;
		}
		else if (ttlhg >= 80000000)
		{
			diskon = ttlhg - (0.3 * ttlhg);
			cout << "\n\n\t\tBELANJA MENCAPAI RP 80.000.000\n\t\tPOTONGAN HARGA SEBESAR 30% \n\n\n\t\tSPECIAL OFFER: Rp " << diskon;
			dataPelanggan << "\t\t30% OFF\t\t\t: " << diskon << endl << endl;
		}
		else
		{
			diskon = ttlhg;
		}

	
		cout << "\n\t\t[1] FULLPAMENT\n\t\t[2] DOWNPAYMENT\n\t\t:" ;
		cin >> input;
		system("cls");

		if (input == "1")
		{
			cout << "\n\n\n\t\t LUNAS\n";
			dataPelanggan << "\t\tLUNAS" << endl;
		}
		else if(input == "2")
		{
			downPayment = diskon - (0.5 * diskon) ;
			cout << "\n\n\n\t\tPEMBAYARAN DOWNPAYMENT SEBESAR 50%\n\t\tSISA YANG HARUS DIABAYAR\t\t: Rp " << downPayment;
			dataPelanggan << "\t\tLUNAS DOWNPAYMENT SEBESAR 50%\t\t: Rp " << downPayment << endl;
		}





		cout << "\n\n\n\n\t\tLanjut Menambahkan [Y/N]\t\t: ";
		tryinput:
		cin >> input;
		if (input == "n" || input == "N") {
			system("cls");
			main();
		}
		else if (input == "y" || input == "Y") {
			system("cls");
			continue;
		}
		else {
			cout << "INPUT VALUE WRONG TRY AGAIN";
			goto tryinput;
		}
	} //loping nomer pelanggan
}

void daftarPelanggan()
{
	system("cls");

	ifstream myFile;
	string  buffer;
	string input;

	myFile.open("data.txt");

	while (!myFile.eof())
	{

		getline(myFile, buffer);

		cout << buffer << endl;

	}
	
	cout << "\n\t\t[0] BACK : ";

	tryinput:
	cin >> input;
	if ( input == "0")
	{
		system("cls");
		main();
	}
	else {
		cout << "INPUT VALUE WRONG, TRY ENTERING AGAIN";
		goto tryinput;
	}
}

void qualityControl()
{
	cout << "\n\n\n\t\t\tQUALITY CONTROL MENU\n\t\t==========================================\n\t\t\t[1] Menambah Barang Reject \n\t\t\t[2] Daftar Barang Reject \n\t\t\t[0] Back\n\t\t==========================================\n\t\t:";

	tryinput:

	string input;

	while (true) {
		cin >> input;

		if (input == "1")
		{
			system("cls");
			newQC();
		}
		else if (input == "2")
		{
			system("cls");
			listQC();
		}
		else if (input == "0")
		{
			system("cls");
			main();
		}
		else
		{
			cout << "VALUE WRONG, TRY INPUT AGAIN ";
			goto tryinput;
		}
	}
}

void listQC()
{
	ifstream record;
	string buffer;

	record.open("recordQC.txt");

	while (!record.eof())
	{
		getline(record, buffer);
		cout << buffer << endl;
	}

	cout << "\n\t\t[0] BACK : ";

	tryinput:

	cin >> input;
	if (input == "0")
	{
		system("cls");
		main();
	}
	else {
		cout << "INPUT VALUE WRONG, TRY ENTERING AGAIN";
		goto tryinput;
	}

}

void newQC() {



	ofstream recordQC;
	recordQC.open("recordQC.txt", ios::app);

	int i = 0;
	cout << "\n\n\n\t\tNOMOR PELANGGAN\t\t: "; cin >> i; // menambahkan nomer pelanggan dengan nomer 00000
			
		system("cls");
		cout << "\n\n\n\t\tNomor Pelanggan\t\t\t\t: ";
		cout << setfill('0') << setw(5);
		cout << i << endl;

		recordQC << "\n\n\n\t\tNOMOR PESANAN\t\t\t: " << setfill('0') << setw(5) << i << endl;



	anotherInput:
		system("cls");

		cout << "\n\n\n\t\t[1] " <<rejectKursi ;
		cout << "\t[2] " <<rejectMeja ;
		cout << "\t[3] " <<rejectLemari ;


		cout << "\n\t\t==========================================\n\t\t\t[1] KURSI \n\t\t\t[2] MEJA \n\t\t\t[3] LEMARI\n\t\t\t[0] BACK\n\t\t==========================================\n\t\t:";


		cin >> input;
		if (input == "1") {
			system("cls");
			cout << "\n\n\n\t\t[KURSI]";
			cout << "\n\t\tMASUKAN JUMLAH YANG DIPESAN\t\t: ";
			cin >> kursi;
			cout << "\t\tMASUKAN JUMLAH BARANG REJECT\t\t: ";
			cin >> rejectKursi;
			
			recordQC << "\t\t[KURSI] JUMLAH PESANAN\t\t: " << kursi << endl;
			recordQC << "\t\t[KURSI] JUMLAH REJECT\t\t: " << rejectKursi << endl << endl;

			goto anotherInput;
		}
		else if (input == "2") {
			system("cls");
			cout << "\n\n\n\t\t[MEJA]";
			cout << "\n\t\tMASUKAN JUMLAH YANG DIPESAN\t\t: ";
			cin >> meja;
			cout << "\t\tMasukan Jumlah Barang Reject\t\t: ";
			cin >> rejectMeja;

			recordQC << "\t\t[MEJA] JUMLAH PESANAN\t\t: " << meja << endl;
			recordQC << "\t\t\[MEJA] JUMLAH REJECT\t\t: " << rejectMeja << endl << endl;
			goto anotherInput;
		}
		else if (input == "3") {
			system("cls");
			cout << "\n\n\n\t\t[LEMARI]";
			cout << "\n\t\tMASUKAN JUMLAH YANG DIPESAN\t\t: ";
			cin >> lemari;
			cout << "\t\tMasukan Jumlah Barang Reject\t\t: ";
			cin >> rejectLemari;

			recordQC << "\t\t[LEMARI] JUMLAH PESANAN\t\t: " << lemari << endl;
			recordQC << "\t\t[LEMARI] JUMLAH REJECT\t\t: " << rejectLemari << endl << endl;
			goto anotherInput;
		}
		else if (input == "0") {
			system("cls");
			qualityControl();
		}
		else {
			
			cout << "VALUE WRONG TRY INPUT AGAIN";
			goto anotherInput;
		}
		recordQC.close();


}

void transaction()
{
	string input;
	ofstream transaksi;
	transaksi.open("transaction.txt", ios::app);
	
	cout << "\n\n\n\t\t\tTRANSACTION\n\t\t==========================================\n\t\t\t[1] LANJUT \n\t\t\t[2] BATAL\n\t\t==========================================\n\t\t:";
	tryinput:
	cin >> input;
	if (input == "1")
	{
		int i = 0;
		cout << "\n\n\n\t\tNOMOR PELANGGAN\t\t: "; cin >> i; // menambahkan nomer pelanggan dengan nomer 00000

		system("cls");
		cout << "\n\n\n\t\tNomor Pelanggan\t\t\t\t: ";
		cout << setfill('0') << setw(5);
		cout << i << endl;

		cout << "\t\tMasukan Nama Pelanggan\t\t\t: "; getline(cin, nama); getline(cin, nama);
		cout << "\t\tLUNAS";
	

		transaksi << "\n\n\n\t\tNOMOR PESANAN\t\t: " << setfill('0') << setw(5) << i << endl;
		transaksi << "\t\tNAMA PELANGGAN\t\t: " << nama << endl;
		transaksi << "\t\tLUNAS" << endl << endl;

		system("cls");
		main();
	}
	else if (input == "2")
	{
		system("cls");
		main();
	}
	else
	{
		cout << "VALUE WRONG TRY ANOTHER INPUT";
		goto tryinput;
	}
}

void status()
{
	string buffer;

	ifstream dataTransaksi;
	dataTransaksi.open("transaction.txt");
	
	while (!dataTransaksi.eof())
	{
		getline(dataTransaksi, buffer);
		cout << buffer << endl;
	}
	cout << "\n\t\t[0] BACK : ";
tryinput:
	
	cin >> input;
	if (input == "0")
	{
		system("cls");
		main();
	}
	else {
		cout << "INPUT VALUE WRONG, TRY ENTERING AGAIN";
		goto tryinput;
	}
}