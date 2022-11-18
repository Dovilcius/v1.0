#include "funkcijos.h"

Studentas::Studentas() {
	vardas = "Null";
    pavarde = "Null";
	egzaminas = 1;
};
Studentas::Studentas(string Vardas, string Pavarde, deque<int>Balai, double Egzaminas) {
	vardas = Vardas;
	pavarde = Pavarde;
	balai = Balai;
	egzaminas = Egzaminas;
	double vidurkis = accumulate(balai.begin(), balai.end(), 0.0) / balai.size();
	double galutinis_vertinimas = (0.4 * vidurkis) + (0.6 * egzaminas);
	double egzaminas = galutinis_vertinimas;
};
Studentas::~Studentas() {
	balai.clear();
}
Studentas::Studentas(const Studentas& p1) {
	vardas = p1.vardas;
	pavarde = p1.pavarde;
	balai = p1.balai;
	egzaminas = p1.egzaminas;
}
void Studentas::DeleteGrades() {balai.clear();}
int Studentas::Menu() {
	int temp;
	cout << " ------------ Pasirinkite ka norite daryti ------------------- " << endl;
	cout << " 1 = Suvesti studento duomenis " << endl;
	cout << " 2 = Studentu galutinis vertinimas (med) " << endl;
	cout << " 3 = Studentu galutinis vertinimas (vid / med) " << endl;
	cout << " 4 = Sugeneruoti duomenis / trukme " << endl;
	cout << " 5 = Studentu duomenys is     1000 failo " << endl;
	cout << " 6 = Studentu duomenys is    10000 failo " << endl;
	cout << " 7 = Studentu duomenys is   100000 failo " << endl;
	cout << " 8 = Studentu duomenys is  1000000 failo " << endl;
	cout << " 9 = Studentu duomenys is 10000000 failo " << endl;
	cout << " 10 = Studentai virs 5 balu ir iki 5 balu " << endl;
	cin >> temp;
	system("CLS");
	return temp;

};

void Studentas::PrintMedian() {
	cout << left << setw(15) << pavarde << right << setw(15) << vardas << right << setw(25) << setprecision(2) << egzaminas << endl;
}
void Studentas::PrintFile() {
	double math = accumulate(balai.begin(), balai.end(), 0.0) / balai.size();
	nth_element(balai.begin(), balai.begin() + balai.size() / 2, balai.end());
	cout << left << setw(15) << pavarde << right << setw(15) << vardas << right << setw(28) << setprecision(2) << egzaminas << right << setw(5) << "/"<< right << setw(5) << setprecision(2) << math << endl;
};
    istream& operator >>(istream& input, Studentas& x) {
	int temp;
	cout << "------------------- Suveskite studento duomenis -----------------------" << endl;
	cout << " Studento vardas:  " << endl;
	cin >> x.vardas;
	cout << " Studento pavarde: " << endl;
	cin >> x.pavarde;
	cout << " Suveskite studento ivertinimus ( tarp ivertinimu dekite tarpus)" << endl;
	cout << " Norint suvesti egzamino ivertinima, suveskite 11 ir paspauskite enter " << endl;
	cin >> temp;
			while (temp != 11) {
				if (temp == 000) {
			for (int i = 0; i < 10; i++) {
				int random = rand() % 10 + 1;
				x.balai.push_back(random);
			}
			int random = rand() % 10 + 1;
			x.egzaminas = random;
			return	input;
		}
		else if (temp > 10 or temp < 0) {
			cout << " Blogai suvestas ivertinimas " << endl;
			cin >> temp;
		}
		else
				{
					x.balai.push_back(temp);
					cin >> temp;
				}
	};
	cout << endl << " Egzamino ivertinimas: ";
	cin >> x.egzaminas;
	system("CLS");
	cout << " Studento duomenys issaugoti" << endl;
	return input; 
	};
    ostream& operator <<(ostream& output, const Studentas& x) {
	double math = accumulate(x.balai.begin(), x.balai.end(), 0.0) / x.balai.size();
	double galutinis_vertinimas = (0.4 * math) + (0.6 * x.egzaminas);
	cout << right << setw(15) << x.pavarde  << setw(10) << x.vardas << setprecision(2) << galutinis_vertinimas << "/" << setprecision(2) << "(" << math << ")" << endl;
	return output;
    };
int wordnum(string wordnume) {
	int countinger = 0;
	string word;
	stringstream strm(wordnume);

	while (strm >> word) {
		++countinger;
	};
	return countinger;
};

double Studentas::GetFinal() {
	return egzaminas;
};