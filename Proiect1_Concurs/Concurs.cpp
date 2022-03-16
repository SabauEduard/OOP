#include <string>
#include <iostream>
#include <vector>
#include "Participant.h"
#include "Concurs.h"

using namespace std;

void Concurs::add_participant(Participant& Object)
{
    Participanti.push_back(Object);
}
void Concurs::add_participant(string nume, string prenume, double punctaj)
{
    Participant A(nume, prenume, punctaj);
    Participanti.push_back(A);
}
void Concurs::set_nume_concurs(string nume)
{
    nume_concurs = nume;
}
Concurs::Concurs()
{
    nume_concurs = "";
}
Concurs::Concurs(string s)
{
    nume_concurs = s;
}
Concurs::Concurs(const Concurs& Object)
{
    for (auto index = Object.Participanti.begin(); index != Object.Participanti.end(); index++)
        Participanti.push_back(*index);
    nume_concurs = Object.nume_concurs;
}
double Concurs::get_medie()
{
    if (Participanti.size())
    {
        Participant Participant_mediu;
        for (auto index = Participanti.begin(); index != Participanti.end(); index++)
            Participant_mediu += *index;
        return (Participant_mediu.get_punctaj() / Participanti.size());
    }
    else return 0;
}
string Concurs::get_nume()
{
    return nume_concurs;
}
void Concurs::sort(bool reverse)
{
    if (reverse == 0)
    {
        for (int index1 = 0; index1 < Participanti.size() - 1; index1++)
            for (int index2 = index1 + 1; index2 < Participanti.size(); index2++)
                if (Participanti[index1].get_punctaj() > Participanti[index2].get_punctaj())
                {
                    Participant Obj(Participanti[index1]);
                    Participanti[index1] = Participanti[index2];
                    Participanti[index2] = Obj;
                }
    }
    else {
        for (int index1 = 0; index1 < Participanti.size() - 1; index1++)
            for (int index2 = index1 + 1; index2 < Participanti.size(); index2++)
                if (Participanti[index1].get_punctaj() < Participanti[index2].get_punctaj())
                {
                    Participant Obj(Participanti[index1]);
                    Participanti[index1] = Participanti[index2];
                    Participanti[index2] = Obj;
                }
    }

}
void Concurs::afis()
{
    for (auto index = Participanti.begin(); index != Participanti.end(); index++)
        cout << *index;
    cout << '\n';
}
void Concurs::afisk_inceput(int k)
{
    auto index = 0;
    while (k)
    {
        cout << Participanti[index];
        index++;
        k--;
    }
}
void Concurs::afisk_sfarsit(int k)
{
    auto index = Participanti.size() - 1;
    while (k)
    {
        cout << Participanti[index];
        index--;
        k--;
    }
}
int Concurs::admisi_p(double p)
{
    int nr = 0;
    for (auto index = Participanti.begin(); index != Participanti.end(); index++)
        if (*index >= p)
            nr++;
    return nr;
}
void Concurs::remove_poz(int k)
{
    for (int index = k; index <= Participanti.size() - 2; index++)
        Participanti[index] = Participanti[index + 1];
    Participanti.resize(Participanti.size() - 1);
}
void Concurs::remove_participant(Participant& Obj)
{
    int k = -1;
    for (auto index = 0; index <= Participanti.size() - 1; index++)
        if (Participanti[index].get_nume() == Obj.get_nume() && Participanti[index].get_prenume() == Obj.get_prenume() && Participanti[index].get_punctaj() == Obj.get_punctaj())
        {
            k = index;          
            break;
        }
    
    for (int index = k; index <= Participanti.size() - 2; index++)
        Participanti[index] = Participanti[index + 1];
    Participanti.resize(Participanti.size() - 1);
}
void Concurs::remove_participant(string nume, string prenume, double punctaj)
{
    int k = -1;

    for (auto index = 0; index <= Participanti.size() - 1; index++)
        if (Participanti[index].get_nume() == nume && Participanti[index].get_prenume() == prenume && Participanti[index].get_punctaj() == punctaj)
        {
            k = index;
            break;
        }
    for (int index = k; index <= Participanti.size() - 2; index++)
        Participanti[index] = Participanti[index + 1];
    Participanti.resize(Participanti.size() - 1);
}
bool Concurs::check_participant(Participant& Obj)
{
    for (auto index = 0; index < Participanti.size(); index++)
        if (Participanti[index].get_nume() == Obj.get_nume() && Participanti[index].get_prenume() == Obj.get_prenume() && Participanti[index].get_punctaj() == Obj.get_punctaj())
            return true;
    return false;
}
bool Concurs::check_participant(string nume, string prenume, double punctaj)
{
    for (auto index = 0; index <= Participanti.size() - 1; index++)
        if (Participanti[index].get_nume() == nume && Participanti[index].get_prenume() == prenume && Participanti[index].get_punctaj() == punctaj)
            return true;
    return false;
}
int Concurs::get_nr_participanti()
{
    return Participanti.size();
}