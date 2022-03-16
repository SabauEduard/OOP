#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Participant {
public:
    Participant(string = "Neintrodus", string = "Neintrodus", double punctaj = 0);
    Participant(const Participant&);
    Participant& operator = (Participant&);
    Participant& operator += (Participant&);
    Participant& operator += (double);
    Participant& operator -= (double);
    Participant& operator -= (Participant&);
    Participant& operator *= (Participant&);
    Participant& operator *= (double);
    friend bool operator == (Participant&, Participant&);
    friend bool operator != (Participant&, Participant&);
    friend bool operator < (Participant&, Participant&);
    friend bool operator < (double, Participant&);
    friend bool operator < (Participant&, double);
    friend bool operator <= (Participant&, Participant&);
    friend bool operator <= (Participant&, double);
    friend bool operator <= (double, Participant&);
    friend bool operator > (Participant&, Participant&);
    friend bool operator > (Participant&, double);
    friend bool operator > (double, Participant&);
    friend bool operator >= (Participant&, Participant&);
    friend bool operator >= (Participant&, double);
    friend bool operator >= (double, Participant&);
    friend Participant& operator + (Participant, Participant&);
    friend Participant& operator + (Participant, double);
    friend Participant& operator + (double, Participant);
    friend Participant& operator - (Participant, Participant&);
    friend Participant& operator - (Participant, double);
    friend Participant& operator * (Participant, Participant&);
    friend Participant& operator * (Participant, double);
    friend Participant& operator * (double, Participant);
    friend Participant& operator / (Participant, Participant&);
    friend Participant& operator / (Participant, double);
    friend ifstream& operator >> (ifstream&, Participant&);
    friend istream& operator >> (istream&, Participant&);
    friend ofstream& operator << (ofstream&, Participant&);
    friend ostream& operator << (ostream&, Participant&);
    string get_nume();
    string get_prenume();
    double get_punctaj();
    void set_nume(string nume);
    void set_prenume(string prenume);
    void set_punctaj(double punctaj);
private:
    string _nume;
    string _prenume;
    double _punctaj;
};
