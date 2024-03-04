#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream> // istringstream funkcijai
#include <cstdlib> // random number generacijai
#include <ctime>
#include <vector>
#include <fstream>
#include <chrono>  //Laiko matavimui
#include "studentas.h"
#include "funkcijos.h"

using namespace std;

int m, n, menu; // m - studentu skaicius, n - namu darbu skaicius
int variantas_namu_darbas, variantas_studentas, pasirinkimas; 
double suma, vidurkis;
int MAX_ND = 30;
int MAX_STUDENTU = 30;
string raide;
                
int main() {

    vector <Studentas> studentai;

    while (true) {

        // Menu
        cout << "Isrinkite programos eigos buda paspaudus nurodyta skaiciu." << endl;
        cout << "1. Visi duomenys ivedami ranka. " << endl;
        cout << "2. Studento duomenys ivedami ranka, o pazymiai generuojami programos. " << endl;
        cout << "3. Visa informacija yra programos generuojama." << endl;
        cout << "4. Nuskaityti duomenis is failo. " << endl;
        cout << "5. Baigti darba." << endl;
        cout << "Jusu pasirinkimas: "; 
        int menu = Menu();

        switch (menu) {

            // Menu 1
            case 1:
            {
                
            vector<Studentas> studentai;

            int m = 0;
            int variantas_studentas = 1;

            // Pridedami studentai
            while (variantas_studentas != 0) {
                m++;

                Studentas naujas_studentas;

                cout << "Irasykite " << m << " studento varda: "; cin >> naujas_studentas.vardas;
                cout << "Irasykite " << m << " studento pavarde: "; cin >> naujas_studentas.pavarde;

                cout << "Iveskite kiek namu darbu pazymiu norite ivesti. ";

                while (true) {
                try {

                    cin >> n;
                    
                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik namu darbu skaiciu.");
                    }

                    if(n < 0) {
                        throw invalid_argument("Netinkamas namu darbu skaicius. Bandykite ivesti kita skaiciu.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& n_klaida) {
                    cout << n_klaida.what() << endl;
                }
            }

                for (int j = 0; j < n; j++) {
                int pazymiai;
                

                do {
                    try {
                        cout << "Studento pazymis uz " << j + 1 << " namu darba: ";
                        cin >> pazymiai;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu.");
                        }

                        if (pazymiai > 10 || pazymiai < 1) {
                            throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10.");
                        }

                        break;

                    } catch (const invalid_argument& pazymis_klaida) {
                        cout << pazymis_klaida.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                } while (pazymiai > 10 || pazymiai < 1);

                naujas_studentas.pazymiai.push_back(pazymiai); // Pazymis pridedamas prie pazymiu vektoriu
            }


            do {

                cout << "Ar norite ivesti dar vieno namu darbo pazymi?\nJeigu ne, spauskite 0.\nJeigu taip, spauskite 1. ";
                variantas_studentas = VariantasNamuDarbas(); 

                while (variantas_studentas != 0 && variantas_studentas != 1) {                        
                cout << "Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1). ";
                variantas_studentas = VariantasNamuDarbas();

                    }

                // Pridedamas dar vienas studentas
                if (variantas_studentas == 1) {
                    n++;
                    int pazymiai;

                    
            while (true) {
                try {

                    cout << "Studento pazymis uz " << n << " namu darba: ";   
                    cin >> pazymiai;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu.");
                    }

                    if (pazymiai > 10 || pazymiai < 1) {
                        throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10.");
                    }

                    naujas_studentas.pazymiai.push_back(pazymiai); // Pazymis pridedamas prie pazymiu vektoriu
                    suma += pazymiai;
                    break;

                } catch (const invalid_argument& pazymiai_klaida) {
                    cout << pazymiai_klaida.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                }   
            }
        }

                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);
                    
                    
                } while (variantas_studentas != 0);

                // Egzamino rezultatas
                cout << "Studento egzamino rezultatas: ";
                int rezultatas;

                while (true) {
                try {

                    cin >> rezultatas;

                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik studentu skaiciu.");
                    }

                    if (rezultatas > 10 || rezultatas < 1) {
                        throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& egz_klaida) {
                    cout << egz_klaida.what() << endl;
                }
            }

                naujas_studentas.egzamino_rezultatas = rezultatas;

                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio ir medianos skaiciavimai
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);

                cout << "--------------------------------------------------" << endl;
                cout << "Ar norite prideti dar vieno studento duomenis?" << endl;
                cout << "Jeigu ne, spauskite 0. Jeigu taip, spauskite bet koki kita skaiciu. ";
                variantas_studentas = VariantasStudentas();

                if (variantas_studentas == 0)
                    break;
                }

            // Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail()) {
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            } 

            // Menu 2
            case 2:
            {

            srand(time(NULL));

            vector<Studentas> studentai;
            cout << "Kiek yra studentu? ";

            while (true) {
                try {

                    cin >> m;

                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik studentu skaiciu.");
                    }

                    if(m <= 0) {
                        throw invalid_argument("Netinkamas studentu skaicius. Bandykite ivesti kita skaiciu.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& m_klaida) {
                    cout << m_klaida.what() << endl;

                }
            }

            int n = rand() % (MAX_ND + 1);
            
            for (int i = 0; i < m; i++) {

                Studentas naujas_studentas;                
                cout << "Irasykite " << i + 1 << " studento varda: "; cin >> naujas_studentas.vardas;
                cout << "Irasykite " << i + 1 << " studento pavarde: "; cin >> naujas_studentas.pavarde;

                for (int j = 0; j < n; j++) {
            
                    int pazymiai = (rand() % 10) + 1;
                    naujas_studentas.pazymiai.push_back(pazymiai);
                }

                naujas_studentas.egzamino_rezultatas = rand() % 10 + 1;
            
                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio ir medianos skaiciavimai
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);
            
            }

            // Vartotojas pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            }

            // Menu 3
            case 3:
            {

            srand(time(NULL));

            vector<string> vardai = {"Adriana", "Emil", "Milana", "Diana", "Andrej", "Marta", "Paulius", "Edita", "Gabriele", "Dominikas"};
            vector<string> pavardes = {"Sirokyte", "Voisvilo", "Demesko", "Pipilevic", "Machnicka", "Voitkevic", "Podgaiska", "Sakson", "Juneviciute", "Petkeviciene"};

            vector<Studentas> studentai;
            int m = rand() % (MAX_STUDENTU + 1);
            

            for (int i = 0; i < m; i++) {

                Studentas naujas_studentas;   
                naujas_studentas.vardas = vardai[rand() % vardai.size()];             
                naujas_studentas.pavarde = pavardes[rand() % vardai.size()];
                int n = rand() % (MAX_ND + 1);

                for (int j = 0; j < n; j++) {
            
                    int pazymiai = (rand() % 10) + 1;
                    naujas_studentas.pazymiai.push_back(pazymiai);
                }

                naujas_studentas.egzamino_rezultatas = rand() % 11;
            
                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio skaiciavimas
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);

                // Mediana
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);
            
            }

                //Pasirinkimas
                // Vartotojas pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            }

            // Menu 4
            case 4: 
            {
            int skaicius = 0;
            string smth;
            string failas;                
            vector<double> laikai;
            int pasirinkimas2 = 0;

            do {

            cout << "Koki faila programa turi nuskaityti?" << endl;
            cout << "1. studentai10000.txt" << endl;
            cout << "2. studentai100000.txt" << endl;
            cout << "3. studentai1000000.txt" << endl;
            cout << "4. kursiokai.txt" << endl;
            cout << "0. Pabaigti." << endl;
            cout << "Jusu pasirinkimas: "; 
            pasirinkimas2 = Pasirinkimas2();

            if(pasirinkimas2 == 1) {
                failas = "studentai10000.txt";
            }

            if(pasirinkimas2 == 2) {
                failas = "studentai100000.txt";
            }

            if(pasirinkimas2 == 3) {
                failas = "studentai1000000.txt";
            }

            if(pasirinkimas2 == 4) {
                failas = "kursiokai.txt";
            }

            if(pasirinkimas2 == 0) {
                break;
            }

            vector<Studentas> studentai;
            ifstream fileName(failas);
            string eilute;

            // Exception handling 1
            try {
                if (!fileName.is_open()) 
                throw runtime_error("Nepavyko atidaryti failo. Bandykite dar karta.");
            
            } catch (const runtime_error& klaida) {
                cout << klaida.what() << endl;
                break;
            }

            auto start = chrono::steady_clock::now();

            while (smth != "Egz.") {
                fileName >> smth;

                skaicius++;
            }

            skaicius = skaicius - 3;

            // Exception handling 2
            try {

                // Neskaitoma pirma eilute is failo
                getline(fileName, eilute);

                while (getline(fileName, eilute)) {
                    stringstream ss(eilute);
                    Studentas naujas_studentas;
                    int pazymiai, suma = 0;
                    ss >> naujas_studentas.vardas >> naujas_studentas.pavarde;

                    for (int i = 0; i < skaicius; i++) {
                        // Exception jeigu vietoj namu darbu pazymio bus kitas simbolis
                        if (!(ss >> pazymiai)) {
                            throw runtime_error("Netinkamas duomenu formatas.");
                            break;
                        }
                        naujas_studentas.pazymiai.push_back(pazymiai);
                        suma += pazymiai;
                    }

                    // Egzamino rezultatas
                    // Exception jeigu vietoj egzamino pazymio bus kitas simbolis
                    if(!(ss >> naujas_studentas.egzamino_rezultatas)) {
                        throw runtime_error("Netinkamas duomenu formatas.");
                        break;
                    }

                    // Galutinio vidurkio ir medianos skaiciavimai
                    naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;
                    naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                    // Pridedamas studentas
                    studentai.push_back(naujas_studentas);
                }

                fileName.close();
            } catch (const runtime_error& fail) {
                cout << fail.what() << endl;
            }

                // Pasirenkame pagal kokia kriterija ruosiosime
                int pasirinkimas3;

                do {
                
                    cout << "Pasirinkite kriterija, pagal kuria norite rusiuoti duomenis:" << endl;
                    cout << "1. Rusiuoti pagal vardus." << endl;
                    cout << "2. Rusiuoti pagal pavardes." << endl;
                    cout << "3. Rusiuoti pagal galutini vidurki." << endl;
                    cout << "4. Rusiuoti pagal mediana." << endl;
                    cout << "Jusu pasirinkimas: ";
                    pasirinkimas3 = Pasirinkimas3();

                    if (pasirinkimas3 == 1) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_varda);
                    } else if (pasirinkimas3 == 2 ) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_pavarde);
                    } else if (pasirinkimas3 == 3) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki);
                    } else if (pasirinkimas3 == 4) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_mediana);
                    }
                
                  } while (pasirinkimas3 != 1 && pasirinkimas3 != 2 && pasirinkimas3 != 3 && pasirinkimas3 != 4);

                // Duomenu irasymas i faila "kursiokai.txt"
                ofstream fileName1("isvedimas.txt");

                fileName1 << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
                fileName1 << "-----------------------------------------------------------------" << endl;

                // Duomenu isvedimas
                for (const auto& studentas : studentai) {
                    fileName1 << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                    fileName1 << fixed << setprecision(2) << studentas.galutinis_vid << setw(30);
                    fileName1 << fixed << setprecision(2) << studentas.mediana << endl;
                }

                fileName1.close();

                auto end = chrono::steady_clock::now();
                double laikas = chrono::duration <double> (end - start).count();
                laikai.push_back(laikas);
                cout << "Trukme: " << laikas << " s" << endl;   
              
        } while (pasirinkimas2 != 0);

        // Skaiciuojama vidutine trukme
                double laiku_suma = 0.0;
                for (auto laikas : laikai) {
                    laiku_suma += laikas;
                }
        
        double laiku_vidurkis = (laikai.size() > 0) ? (laiku_suma / laikai.size()) : 0.0;
        cout << "Vidutine trukme: " << laiku_vidurkis << " s" << endl;

        break;
            }

            // Menu 5
            case 5:
            {
                cout << "Darbas baigtas." << endl;
                return 0;
            }
            default :
            {

                cout << "Ivyko klaida. Bandykite ivesti kita skaiciu. " << endl;
                break;
            }
        }
    }
}