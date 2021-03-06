#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "Participant.h"
#include "Concurs.h"

using namespace std;
void afis_concursuri(vector <Concurs>& v)
{
    for (int index = 0; index < v.size(); index++)
        cout << v[index].get_nume() << '\n';
}
int find_concurs(string nume, vector <Concurs> &v)
{
    for (int index = 0; index < v.size(); index++)
        if (v[index].get_nume() == nume)
            return index;
    return -1;
}
bool IsFloat(string s)
{
    int nr_puncte = 0;
    for (int index = 0; index < s.length(); index++)
        if (strchr("0123456789.", s[index]) == NULL)
            return false;
        else if (s[index] == '.')
        {
            nr_puncte++;
            if (nr_puncte > 1)
                return false;
        }

    return true;
}
bool IsInt(string s)
{
    for (int index = 0; index < s.length(); index++)
        if (strchr("0123456789", s[index]) == NULL)
            return false;
    return true;
}
int main()
{
    Concurs MateInfoUB("MateInfoUB");
    MateInfoUB.add_participant("Stelian", "Cristian", 230);
    Participant A("Popescu", "Adrian", 116);
    MateInfoUB.add_participant(A);
    MateInfoUB.add_participant("Stanescu", "Lata", 200);
    MateInfoUB.add_participant("Antal", "Eduard", 333);
    MateInfoUB.add_participant("Anton", "Beton", 350);
    MateInfoUB.add_participant("Stanescu", "Codrin", 200);
    MateInfoUB.add_participant("Popescu", "Andrei", 378);
    MateInfoUB.add_participant("Maftei", "Benjamin", 124);
    MateInfoUB.add_participant("Patrascu", "Andrei", 179);
    MateInfoUB.add_participant("Stelian", "Iosif", 110);
    MateInfoUB.add_participant("Marcescu", "Carol", 200);
    Participant B;
    B.set_nume("Rosu");
    B.set_prenume("Ilinca");
    B.set_punctaj(400);
    B -= A;
    MateInfoUB.add_participant(B);
    Participant C("Paun", "Tudor", 400);
    C = C / 2;
    C *= 1.5;
    MateInfoUB.add_participant(C);
    MateInfoUB.add_participant("Anghel", "Ferdinand", 312);
    MateInfoUB.add_participant("Bidon", "Ion", 157);
    MateInfoUB.add_participant("Aurelian", "Marcel", 160);
    MateInfoUB.add_participant("Ionescu", "Stefan", 200);
    vector <Concurs> v;
    v.push_back(MateInfoUB);

    while (true)
    {
        cout << "Pentru a crea un nou concurs introduceti 0" << '\n';
        cout << "Pentru a vedea concursurile existente introduceti 1" << '\n';
        cout << "Pentru a selecta un concurs din lista existenta introduceti 2" << '\n';
        cout << "Pentru a opri programul introduceti -1" << '\n';
        cout << "Introduceti comanda dorita: ";
        
            string request1 = "";
            cin >> request1;
            cout << '\n';

            if (request1 == "0")
            {
                cout << "Introduceti numele concursului = ";
                string nume;
                cin >> ws;
                getline(cin, nume);
                Concurs C(nume);
                v.push_back(C);
                cout << '\n';
                cout << "Concursul a fost creat cu succes!" << '\n' << '\n';
                continue;
            }
            else if (request1 == "1")
            {
                afis_concursuri(v);
                cout << '\n';
                continue;
            }
            else if (request1 == "2")
            {
                cout << "Introduceti numele concursului = ";
                string nume;
                cin >> ws;
                getline(cin, nume);
                int poz_concurs = find_concurs(nume, v);
                if (poz_concurs == -1)
                    cout << "Concursul nu a fost gasit." << '\n';
                else
                    while (true)
                    {
                        cout << "Concursul cu numele " << nume << " este selectat." << '\n' << '\n';
                        cout << "Pentru a adauga un nou participant introduceti 0" << '\n';
                        cout << "Pentru a sterge un participant introduceti 1" << '\n';
                        cout << "Pentru a schimba numele concursului introduceti 2" << '\n';
                        cout << "Pentru a afisa lista tututror participantilor introduceti 3" << '\n';
                        cout << "Pentru a sorta crescator participantii introduceti 4" << '\n';
                        cout << "Pentru a sorta descrescator participantii introduceti 5" << '\n';
                        cout << "Pentru a afisa primii k participanti introduceti 6" << '\n';
                        cout << "Pentru a afisa ultimii k participanti introduceti 7" << '\n';
                        cout << "Pentru a afisa numarul participantilor introduceti 8" << '\n';
                        cout << "Pentru a afisa media tutror participantilor introduceti 9" << '\n';
                        cout << "Pentru a afisa cati participanti au cel putin p puncte introduceti 10" << '\n';
                        cout << "Pentru a verifica daca un participant a fost inscris in concurs introduceti 11" << '\n';
                        cout << "Pentru a reveni la meniul anterior introduceti 12" << '\n';
                        cout << "Introduceti comanda dorita: ";
                        string request2 = "";
                        cin >> request2;
                        cout << '\n';

                        if (request2 == "0")
                        {
                        cout << "Introduceti numele participantului: ";
                        string nume_participant;
                        cin >> ws;
                        getline(cin, nume_participant);
                        cout << '\n' << "Introduceti prenumele participantului: ";
                        string prenume_participant;
                        cin >> ws;
                        getline(cin, prenume_participant);
                        cout << '\n' << "Introduceti punctajul participantului: ";                            
                        string punctaj_participant_placeholder;
                        double punctaj_participant;
                        cin >> ws;
                        getline(cin, punctaj_participant_placeholder);
                        if (!IsFloat(punctaj_participant_placeholder))
                        {
                            cout << '\n' << "Punctajul introdus nu este in formatul acceptat(double)." << '\n' << '\n';
                            continue;
                        }
                        punctaj_participant = stod(punctaj_participant_placeholder);
                        v[poz_concurs].add_participant(nume_participant, prenume_participant, punctaj_participant);
                        cout << '\n' << "Participantul a fost adaugat cu succes!" << '\n' << '\n';                                                                            
                        }
                        else if (request2 == "1")
                        {
                            cout << "Introduceti numele participantului: ";
                            string nume_participant;
                            cin >> ws;
                            getline(cin, nume_participant);
                            cout << '\n' << "Introduceti prenumele participantului: ";
                            string prenume_participant;
                            cin >> ws;
                            getline(cin, prenume_participant);
                            cout << '\n' << "Introduceti punctajul participantului: ";
                            
                            string punctaj_participant_placeholder;
                            double punctaj_participant;
                            cin >> ws;
                            getline(cin, punctaj_participant_placeholder);
                            if (!IsFloat(punctaj_participant_placeholder))
                            {
                                cout << '\n' << "Punctajul introdus nu este in formatul acceptat(double)." << '\n' << '\n';
                                continue;
                            }
                            punctaj_participant = stod(punctaj_participant_placeholder);
                            v[poz_concurs].remove_participant(nume_participant, prenume_participant, punctaj_participant);
                            cout << '\n' << "Participantul a fost sters cu succes!" << '\n' << '\n';                                                 
                        }
                        else if (request2 == "2")
                        {
                            cout << "Introduceti noul nume: ";
                            string new_name;
                            cin >> ws;
                            getline(cin, new_name);
                            v[poz_concurs].set_nume_concurs(new_name);
                            cout << '\n' << "Numele concursului a fost schimbat cu succes!" << '\n' << '\n';
                        }
                        else if (request2 == "3")
                        {
                            v[poz_concurs].afis();
                            cout << '\n';
                        }
                        else if (request2 == "4")
                        {
                            v[poz_concurs].sort();
                            cout << '\n' << "Participantii au fost sortati cu succes!" << '\n' << '\n';
                        }
                        else if (request2 == "5")
                        {
                            v[poz_concurs].sort(1);
                            cout << '\n' << "Participantii au fost sortati cu succes!" << '\n' << '\n';
                        }
                        else if (request2 == "6")
                        {
                        cout << '\n' << "k = ";
                        unsigned int k;
                        string k_placeholder;
                        cin >> ws;
                        getline(cin, k_placeholder);
                        if (!IsInt(k_placeholder))
                        {
                            cout << '\n' << "Punctajul introdus nu este in formatul acceptat(unsigned integer)." << '\n' << '\n';
                            continue;
                        }
                        k = stoi(k_placeholder);
                        v[poz_concurs].afisk_inceput(k);                        
                        cout << '\n';
                        }
                        else if (request2 == "7")
                        {
                            cout << '\n' << "k = ";
                            unsigned int k;
                            string k_placeholder;
                            cin >> ws;
                            getline(cin, k_placeholder);
                            if (!IsInt(k_placeholder))
                            {
                                cout << '\n' << "Punctajul introdus nu este in formatul acceptat(unsigned integer)." << '\n' << '\n';
                                continue;
                            }
                            k = stoi(k_placeholder);
                            v[poz_concurs].afisk_sfarsit(k);                               
                            cout << '\n';
                        }
                        else if (request2 == "8")
                        {
                            cout << '\n' << "Numarul de participanti este: " << v[poz_concurs].get_nr_participanti() << '\n' << '\n';
                        }
                        else if (request2 == "9")
                        {
                            cout << '\n' << "Media participantilor la acest concurs este: " << v[poz_concurs].get_medie() << '\n' << '\n';
                        }
                        else if (request2 == "10")
                        {
                        cout << '\n' << "p = ";
                        string punctaj_min_placeholder;
                        double punctaj_min;
                        cin >> ws;
                        getline(cin, punctaj_min_placeholder);
                        if (!IsFloat(punctaj_min_placeholder))
                        {
                            cout << '\n' << "Punctajul introdus nu este in formatul acceptat." << '\n' << '\n';
                            continue;
                        }
                        punctaj_min = stod(punctaj_min_placeholder);
                        cout << '\n' << "Numarul participantilor cu punctajul mai mare sau egal cu " << punctaj_min << " este de " << v[poz_concurs].admisi_p(punctaj_min) << '\n' << '\n';
                        
                        }
                        else if (request2 == "11")
                        {
                            cout << "Introduceti numele participantului: ";
                            string nume_participant;
                            cin >> ws;
                            getline(cin, nume_participant);
                            cout << '\n' << "Introduceti prenumele participantului: ";
                            string prenume_participant;
                            cin >> ws;
                            getline(cin, prenume_participant);
                            cout << '\n' << "Introduceti punctajul participantului: ";
                            string punctaj_participant_placeholder;
                            double punctaj_participant;
                            cin >> ws;
                            getline(cin, punctaj_participant_placeholder);
                            if (!IsFloat(punctaj_participant_placeholder))
                            {
                                cout << '\n' << "Punctajul introdus nu este in formatul acceptat(double)." << '\n' << '\n';
                                continue;
                            }
                            punctaj_participant = stod(punctaj_participant_placeholder);
                            Participant Temp(nume_participant, prenume_participant, punctaj_participant);
                            if (v[poz_concurs].check_participant(Temp))
                                 cout << '\n' << "Participantul este deja introdus in sistem." << '\n' << '\n';
                            else cout << '\n' << "Participantul nu este introdus in sistem." << '\n' << '\n';
                        }
                        else if (request2 == "12")
                        {
                            break;
                        }
                        else {
                            cout << '\n' << "Comanda introdusa nu se regaseste in lista." << '\n' << '\n';
                            continue;
                        }
                    }
            }
            else if (request1 == "-1")
            {
                break;
            }
            else {
                cout << '\n' << "Comanda introdusa nu se regaseste in lista." << '\n' << '\n';
                continue;

            }        
        
    }
    
}

