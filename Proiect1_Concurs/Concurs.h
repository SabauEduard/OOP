#pragma once
#include "Participant.h"
#include <vector>
#include <iostream>
#include <string>


using namespace std;

class Concurs {
public:
    Concurs();
    Concurs(const Concurs&);
    Concurs(string);
    void add_participant(Participant&);
    void add_participant(string, string, double);
    void set_nume_concurs(string);
    void remove_participant(Participant&);
    void remove_participant(string, string, double);
    void remove_poz(int);
    double get_medie();
    void sort(bool reverse = 0);
    void afis();
    void afisk_sfarsit(int);
    void afisk_inceput(int);
    int admisi_p(double);
    string get_nume();
    bool check_participant(Participant&);
    bool check_participant(string, string, double);
    int get_nr_participanti();
private:
    vector <Participant> Participanti;
    string nume_concurs;
};
