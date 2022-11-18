#include "funkcijos.h"

int main()
{
	deque<Studentas> sarasas;
	deque<int> vertinimai = { 0 };
	Studentas pirmas;

	int turinys = 0;
	int pasirinkimas = 0;
	int nulinis = 0;

	double trukme_1000, trukme_10000, trukme_100000, trukme_1000000, trukme_10000000;
	double  laikas_1000, laikas_10000, laikas_100000, laikas_1000000, laikas_10000000;
	double x = 0;
	double y = 0;

	turinys = pirmas.Menu();
			while (turinys == 1) {
				cin >> pirmas;
				sarasas.push_back(pirmas);
				pirmas.DeleteGrades();
				system("CLS");
				cout << " Studento duomenys buvo prideti. " << endl;
				cout << endl << " 1 = Prideti kito studento duomenis: " << endl;
				cout << " 2 = Atgal i turini: " << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 2) {
					system("CLS"); turinys = pirmas.Menu();
				};
				system("CLS");
			};
				//-------------------------------------------------------------------------------------------------------------
			while (turinys == 2) {
				cout << left << setw(15) << "Pavarde " << right << setw(15) << " Vardas " << right << setw(35) << " Galutinis(Med.) " << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < sarasas.size(); i++) { sarasas[i].PrintMedian(); }
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << " 1 = Atgal i turini " << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
			};
			//---------------------------------------------------------------------------------------------------------
			while (turinys == 3) {
				static int checked = 0;
				if (checked == 0) {
					ifstream datafile;
					datafile.open("data.txt");
					string str = "null", vardasx = "null", pavardex = "null";
					double skaiciai = 0;
					string arr[50];
					getline(datafile, str);
					int counter = wordnum(str);
					while (datafile.peek() != EOF) {
						getline(datafile, str);
						stringstream ss(str);
						for (int i = 0; i < counter; i++) {
							ss >> arr[i];
							if (i == 0) { vardasx = arr[i]; }
							else if (i == 1) { pavardex = arr[i]; }
							else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
							else if (i + 1 == counter) { skaiciai = stoi(arr[i]); }
						};
						Studentas scholar(vardasx, pavardex, vertinimai, skaiciai);
						sarasas.push_back(scholar);
						vertinimai.clear();
					};
					checked++;
					sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs) {return lhs.vardas < rhs.pavarde; });
				};
				sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs) {return lhs.vardas < rhs.pavarde; });
				cout << left << setw(15) << "Pavarde " << right << setw(15) << " Vardas " << right << setw(50) << " Galutinis(vid) / Galutinis(med) " << endl;
				cout << "-----------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < sarasas.size(); i++) { sarasas[i].PrintFile(); }
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << endl << "1 = Atgal i turini" << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
			}
			//---------------------------------------------------------------------------------------------------------------
			while (turinys == 4) {
				if (nulinis == 0) {
					cout << " Generuojami duomenys... " << endl;
					cout << endl;

					ofstream pirmas("studentai1000.txt");
					auto pradzia = std::chrono::high_resolution_clock::now();
					pirmas << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
					for (int i = 0; i < 1000; i++) {
						pirmas << "\n" << "Name" << i << "\t";
						pirmas << "Surname" << i << "\t";
						int random = rand() % 10 + 1;
						pirmas << random << "\t";
						random = rand() % 10 + 1;
						pirmas << random << "\t";
						random = rand() % 10 + 1;
						pirmas << random << "\t";
						random = rand() % 10 + 1;
						pirmas << random << "\t";
						random = rand() % 10 + 1;
						pirmas << random << "\t";
						random = rand() % 10 + 1;
						pirmas << random;
					};
					auto pabaiga = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double>kiek_trunka = pabaiga - pradzia;
					laikas_1000 = kiek_trunka.count();
					pirmas.close();
					cout << "      1000 Studentu sugeneravo per: " << laikas_1000 << " sekundes. ";

					ofstream antras("studentai10000.txt");
					auto pradzia_antro = std::chrono::high_resolution_clock::now();
					antras << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
					for (int i = 0; i < 10000; i++) {
						antras << "\n" << "Name" << i << "\t";
						antras << "Surname" << i << "\t";
						int random = rand() % 10 + 1;
						antras << random << "\t";
						random = rand() % 10 + 1;
						antras << random << "\t";
						random = rand() % 10 + 1;
						antras << random << "\t";
						random = rand() % 10 + 1;
						antras << random << "\t";
						random = rand() % 10 + 1;
						antras << random << "\t";
						random = rand() % 10 + 1;
						antras << random;
					};
					auto pabaiga_antro = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double>kiek_trunkaaa = pabaiga_antro - pradzia_antro;
					laikas_10000 = kiek_trunkaaa.count();
					antras.close();
					cout << endl << "    10000 Studentu sugeneravo per: " << laikas_10000 << " sekundes. " << endl;

					ofstream trecias("studentai100000.txt");
					auto pradzia_trecio = std::chrono::high_resolution_clock::now();
					trecias << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
					for (int i = 10000; i < 110000; i++) {
						trecias << "\n" << "Name" << i << "\t";
						trecias << "Surname" << i << "\t";
						int random = rand() % 10 + 1;
						trecias << random << "\t";
						random = rand() % 10 + 1;
						trecias << random << "\t";
						random = rand() % 10 + 1;
						trecias << random << "\t";
						random = rand() % 10 + 1;
						trecias << random << "\t";
						random = rand() % 10 + 1;
						trecias << random << "\t";
						random = rand() % 10 + 1;
						trecias << random;
					};
					auto pabaiga_trecio = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> kiek_trunka_antras = pabaiga_trecio - pradzia_trecio;
					laikas_100000 = kiek_trunka_antras.count();
					trecias.close();
					cout << "   100000 Studentu sugeneravo per: " << laikas_100000 << " sekundes. " << endl;
					std::ofstream ketvirtas("studentai1000000.txt");
					auto pradzia_ketvirto = std::chrono::high_resolution_clock::now();
					ketvirtas << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
					for (int i = 110000; i < 1110000; i++) {
						ketvirtas << "\n" << "Name" << i << "\t";
						ketvirtas << "Surname" << i << "\t";
						int random = rand() % 10 + 1;
						ketvirtas << random << "\t";
						random = rand() % 10 + 1;
						ketvirtas << random << "\t";
						random = rand() % 10 + 1;
						ketvirtas << random << "\t";
						random = rand() % 10 + 1;
						ketvirtas << random << "\t";
						random = rand() % 10 + 1;
						ketvirtas << random << "\t";
						random = rand() % 10 + 1;
						ketvirtas << random;
					};
					auto pabaiga_ketvirto = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> kiek_truko_ketvirtas = pabaiga_ketvirto - pradzia_ketvirto;
					laikas_1000000 = kiek_truko_ketvirtas.count();
					ketvirtas.close();
					cout << "  1000000 studentu sugeneravo per: " << laikas_1000000 << " sekundes." << endl;

					std::ofstream penktas("studentai10000000.txt");
					auto pradzia_penkto = std::chrono::high_resolution_clock::now();
					penktas << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
					for (int i = 110000; i < 1110000; i++) {
						penktas << "\n" << "Name" << i << "\t";
						penktas << "Surname" << i << "\t";
						int random = rand() % 10 + 1;
						penktas << random << "\t";
						random = rand() % 10 + 1;
						penktas << random << "\t";
						random = rand() % 10 + 1;
						penktas << random << "\t";
						random = rand() % 10 + 1;
						penktas << random << "\t";
						random = rand() % 10 + 1;
						penktas << random << "\t";
						random = rand() % 10 + 1;
						penktas << random;
					};
					auto pabaiga_penkto = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> kiek_truko_penktas = pabaiga_penkto - pradzia_penkto;
					laikas_10000000 = kiek_truko_penktas.count();
					penktas.close();
					nulinis++;
					cout << " 10000000 studentu sugeneravo per: " << laikas_10000000 << " sekundes." << endl;
				}
				else if (nulinis == 1) {
					cout << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			};
			//----------------------------------------------------------------------------------------------------------------
			while (turinys == 5) {
				if (nulinis > 0) {
					cout << " Palaukite... Generuojami duomenys..." << endl;
					static int checked = 0;
					if (checked == 0) {
						ifstream datafile;
						datafile.open("studentai1000.txt");
						string str = "null", vardasx = "null", pavarde = "null";
						double balaix = 0;
						string arr[50];
						getline(datafile, str);
						int counter = wordnum(str);
						auto pradzia = std::chrono::high_resolution_clock::now();
						while (datafile.peek() != EOF) {
							getline(datafile, str);
							stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { vardasx = arr[i]; }
								else if (i == 1) { pavarde = arr[i]; }
								else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { balaix = stoi(arr[i]); }
							};
							Studentas scholar(vardasx, pavarde, vertinimai, balaix);
							sarasas.push_back(scholar);
							vertinimai.clear();
						};
						auto pabaiga = std::chrono::high_resolution_clock::now();
						std::chrono::duration<double>kiek_trunka = pabaiga - pradzia;
						trukme_1000 = kiek_trunka.count();
						checked++;
						datafile.close();
						sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs)
							{return lhs.egzaminas < rhs.egzaminas; });
					};
					cout << endl << " Trukme: " << trukme_1000 << " sekundes." << endl;

					cout << "---------------------------------------------" << endl;
					cout << " 1 = Rodyti ekrane rezultatus" << endl;
					cout << " 2 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = 2; };
					if (pasirinkimas == 2) { system("CLS"); turinys = pirmas.Menu(); };
				}
				else if (nulinis == 0) {
					cout << " Sugeneruokite duomenis " << endl;
					cout << endl << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			}
			//----------------------------------------------------------------------------------------------------------------
			while (turinys == 6) {
				if (nulinis > 0) {
					cout << " Palaukite... Generuojami duomenys..." << endl;
					static int checked = 0;
					if (checked == 0) {
						ifstream datafile;
						datafile.open("studentai10000.txt");
						string str = "null", vardasx = "null", pavarde = "null";
						double balaix = 0;
						string arr[50];
						getline(datafile, str);
						int counter = wordnum(str);
						auto pradzia = std::chrono::high_resolution_clock::now();
						while (datafile.peek() != EOF) {
							getline(datafile, str);
							stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { vardasx = arr[i]; }
								else if (i == 1) { pavarde = arr[i]; }
								else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { balaix = stoi(arr[i]); }
							};
							Studentas scholar(vardasx, pavarde, vertinimai, balaix);
							sarasas.push_back(scholar);
							vertinimai.clear();
						};
						auto pabaiga = std::chrono::high_resolution_clock::now();
						std::chrono::duration<double>kiek_trunka = pabaiga - pradzia;
						trukme_10000 = kiek_trunka.count();
						checked++;
						datafile.close();
						sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs) 
							{return lhs.egzaminas < rhs.egzaminas; });
					};
					cout << endl << " Trukme: " << trukme_10000 << " sekundes." << endl;

					cout << "---------------------------------------------" << endl;
					cout << " 1 = Rodyti ekrane rezultatus" << endl;
					cout << " 2 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = 2; };
					if (pasirinkimas == 2) { system("CLS"); turinys = pirmas.Menu(); };
				}
				else if (nulinis == 0) {
					cout << " Sugeneruokite duomenis " << endl;
					cout << endl << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			}
			//---------------------------------------------------------------------------------------------------------------
			while (turinys == 7) {
				if (nulinis > 0) {
					cout << " Palaukite... Generuojami duomenys..." << endl;
					static int checked = 0;
					if (checked == 0) {
						ifstream datafile;
						datafile.open("studentai100000.txt");
						string str = "null", vardasx = "null", pavardex = "null";
						double balaix = 0;
						string arr[50];
						getline(datafile, str);
						int counter = wordnum(str);
						auto pradziaa = std::chrono::high_resolution_clock::now();
						while (datafile.peek() != EOF) {
							getline(datafile, str);
							stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { vardasx = arr[i]; }
								else if (i == 1) { pavardex = arr[i]; }
								else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { balaix = stoi(arr[i]); }
							};
							Studentas scholar(vardasx, pavardex, vertinimai, balaix);
							sarasas.push_back(scholar);
							vertinimai.clear();
							auto pabaigaa = std::chrono::high_resolution_clock::now();
							std::chrono::duration<double>kiektrunka = pabaigaa - pradziaa;
							trukme_100000 = kiektrunka.count();
						};
						checked++;
						datafile.close();
						sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs)
							{return lhs.egzaminas < rhs.egzaminas; });
					};
					cout << endl << " Trukme: " << trukme_100000 << " sekundes." << endl;
					cout << "---------------------------------------------" << endl;
					cout << endl << " 1 = Rodyti rezultatus";
					cout << endl << " 2 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = 2; };
					if (pasirinkimas == 2) { system("CLS"); turinys = pirmas.Menu(); };
				}
				else if (nulinis == 0) {
					cout << " Sugeneruokite duomenis" << endl;
					cout << endl << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			};
			//---------------------------------------------------------------------------------------------------------
			while (turinys == 8) {
				if (nulinis > 0) {
					cout << " Palaukite... Generuojami duomenys..." << endl;
					static int checked = 0;
					if (checked == 0) {
						ifstream datafile;
						datafile.open("studentai1000000.txt");
						string str = "null", vardasx = "null", pavardex = "null";
						double balaix = 0;
						string arr[50];
						getline(datafile, str);
						int counter = wordnum(str);
						auto pradziaa = std::chrono::high_resolution_clock::now();
						while (datafile.peek() != EOF) {
							getline(datafile, str);
							stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { vardasx = arr[i]; }
								else if (i == 1) { pavardex = arr[i]; }
								else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { balaix = stoi(arr[i]); }
							};
							Studentas scholar(vardasx, pavardex, vertinimai, balaix);
							sarasas.push_back(scholar);
							vertinimai.clear();
							auto pabaigaa = std::chrono::high_resolution_clock::now();
							std::chrono::duration<double>kiektrunka = pabaigaa - pradziaa;
							trukme_1000000 = kiektrunka.count();
						};
						checked++;
						datafile.close();
						sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs) 
							{return lhs.egzaminas < rhs.egzaminas; });
					};
					cout << endl << " Trukme: " << trukme_1000000 << " sekundes." << endl;
					cout << "---------------------------------------------" << endl;
					cout << endl << " 1 = Rodyti rezultatus";
					cout << endl << " 2 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = 2; };
					if (pasirinkimas == 2) { system("CLS"); turinys = pirmas.Menu(); };
				}
				else if (nulinis == 0) {
					cout << " Sugeneruokite duomenis" << endl;
					cout << endl << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			};
			//-----------------------------------------------------------------------------------------------------------------------
			while (turinys == 9) {
				if (nulinis > 0) {
					cout << " Palaukite... Generuojami duomenys..." << endl;
					static int checked = 0;
					if (checked == 0) {
						ifstream datafile;
						datafile.open("studentai10000000.txt");
						string str = "null", vardasx = "null", pavardex = "null";
						double balaix = 0;
						string arr[50];
						getline(datafile, str);
						int counter = wordnum(str);
						auto pradziaa = std::chrono::high_resolution_clock::now();
						while (datafile.peek() != EOF) {
							getline(datafile, str);
							stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { vardasx = arr[i]; }
								else if (i == 1) { pavardex = arr[i]; }
								else if (i > 1 and i + 1 < counter) { vertinimai.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { balaix = stoi(arr[i]); }
							};
							Studentas scholar(vardasx, pavardex, vertinimai, balaix);
							sarasas.push_back(scholar);
							vertinimai.clear();
							auto pabaigaa = std::chrono::high_resolution_clock::now();
							std::chrono::duration<double>kiektrunka = pabaigaa - pradziaa;
							trukme_10000000 = kiektrunka.count();
						};
						checked++;
						datafile.close();
						sort(sarasas.begin(), sarasas.end(), [](const Studentas& lhs, const Studentas& rhs) 
							{return lhs.egzaminas < rhs.egzaminas; });
					};
					cout << endl << " Trukme: " << trukme_10000000 << " sekundes." << endl;
					cout << "---------------------------------------------" << endl;
					cout << endl << " 1 = Rodyti rezultatus";
					cout << endl << " 2 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = 2; };
					if (pasirinkimas == 2) { system("CLS"); turinys = pirmas.Menu(); };
				}
				else if (nulinis == 0) {
					cout << " Sugeneruokite duomens" << endl;
					cout << endl << " 1 = Atgal i turini" << endl;
					cin >> pasirinkimas;
					if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				};
			};
			//-----------------------------------------------------------------------------------------------------------------------
			while (turinys == 10) {
				auto Ppradzia = std::chrono::high_resolution_clock::now();
				cout << "Rusiuojami duomenys..." << endl;
				deque<Studentas>Geri;
				deque<Studentas>Blogi;
				partition_copy(sarasas.begin(), sarasas.end(), back_inserter(Geri), back_inserter(Blogi), [](Studentas& temper) 
					{return temper.GetFinal() >= 5; });
				auto Ppabaiga = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double>Ttrukme = Ppabaiga - Ppradzia;
				x = Ttrukme.count();
				cout << " Rusiavimo trukme: " << x << " sekundes." << endl;
				auto Ppradziaa = std::chrono::high_resolution_clock::now();
				ofstream blogas_galutinis("Blogi.txt");
				blogas_galutinis << "Name" << "\t" << "Surname" << "\t" << "FinalGrade" << "\n";
				for (int i = 0; i < Blogi.size(); i++) {
					blogas_galutinis << Blogi[i].vardas << "\t" << Blogi[i].pavarde << "\t" << Blogi[i].egzaminas << "\n";
				}
				blogas_galutinis.close();
				auto Ppabaigaa = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double>laikas_sek = Ppabaigaa - Ppradziaa;
				x = laikas_sek.count();
				cout << " Blogi sugeneruoti per: " << x << " sekundes." << endl;

				auto pradzia_geri = std::chrono::high_resolution_clock::now();
				ofstream geras_galutinis("Geri.txt");
				geras_galutinis << "Name" << "\t" << "Surname" << "\t" << "FinalGrade" << "\n";
				for (int i = 0; i < Geri.size(); i++) {
					geras_galutinis << Geri[i].vardas << "\t" << Geri[i].pavarde << "\t" << Geri[i].egzaminas << "\n";
				}
				geras_galutinis.close();
				auto pabaiga_geri = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double>kiek_trunka_geri = pabaiga_geri - pradzia_geri;
				y = kiek_trunka_geri.count();
				cout << " Geri sugeneruoti per: " << y << " sekundes." << endl;
				cout << endl << "1 = Atgal i turini" << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); turinys = pirmas.Menu(); };
				
	        };
	return 0;
};