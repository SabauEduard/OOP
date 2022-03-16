#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Participant.h"
#include "Concurs.h"


using namespace std;

Participant::Participant(string nume, string prenume, double punctaj)
{
    _nume = nume;
    _prenume = prenume;
    _punctaj = punctaj;

}
Participant::Participant(const Participant& Object)
{
    _nume = Object._nume;
    _prenume = Object._prenume;
    _punctaj = Object._punctaj;
}
Participant& Participant:: operator =(Participant& Object)
{
    _punctaj = Object._punctaj;
    _nume = Object._nume;
    _prenume = Object._prenume;
    return *this;
}
Participant& Participant:: operator +=(Participant& Object)
{
    _punctaj += Object._punctaj;
    return *this;
}
Participant& Participant:: operator +=(double number)
{
    _punctaj += number;
    return *this;
}
Participant& Participant:: operator -=(Participant& Object)
{
    _punctaj -= Object._punctaj;
    return *this;
}
Participant& Participant:: operator -=(double number)
{
    _punctaj -= number;
    return *this;
}
Participant& Participant:: operator *=(Participant& Object)
{
    _punctaj *= Object._punctaj;
    return *this;
}
Participant& Participant:: operator *=(double number)
{
    _punctaj *= number;
    return *this;
}
string Participant::get_nume()
{
    return _nume;
}
string Participant::get_prenume()
{
    return _prenume;
}
double Participant::get_punctaj()
{
    return _punctaj;
}
void Participant::set_nume(string nume)
{
    _nume = nume;
}
void Participant::set_prenume(string prenume)
{
    _prenume = prenume;
}
void Participant::set_punctaj(double punctaj)
{
    _punctaj = punctaj;
}
bool operator ==(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj == Object2._punctaj)
        return true;
    return false;
}
bool operator !=(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj != Object2._punctaj)
        return true;
    return false;

}
bool operator >(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj > Object2._punctaj)
        return true;
    return false;
}
bool operator >(Participant& Object, double p)
{
    if (Object._punctaj > p)
        return true;
    return false;
}
bool operator >(double p, Participant& Object)
{
    if (p > Object._punctaj)
        return true;
    return false;
}
bool operator >=(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj >= Object2._punctaj)
        return true;
    return false;
}
bool operator >=(Participant& Object, double p)
{
    if (Object._punctaj >= p)
        return true;
    return false;
}
bool operator >=(double p, Participant& Object)
{
    if (p >= Object._punctaj)
        return true;
    return false;
}
bool operator <(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj < Object2._punctaj)
        return true;
    return false;
}
bool operator < (Participant& Object, double p)
{
    if (Object._punctaj < p)
        return true;
    return false;
}
bool operator < (double p, Participant& Object)
{
    if (p < Object._punctaj)
        return true;
    return false;
}
bool operator <=(Participant& Object1, Participant& Object2)
{
    if (Object1._punctaj <= Object2._punctaj)
        return true;
    return false;
}
bool operator <=(Participant& Object, double p)
{
    if (Object._punctaj <= p)
        return true;
    return false;
}
bool operator <=(double p, Participant& Object)
{
    if (p <= Object._punctaj)
        return true;
    return false;
}
Participant& operator +(Participant Object1, Participant& Object2)
{
    Object1 += Object2;
    return Object1;
}
Participant& operator +(double number, Participant Object)
{
    Object += number;
    return Object;
}
Participant& operator +(Participant Object, double number)
{
    Object += number;
    return Object;
}
Participant& operator -(Participant Object1, Participant& Object2)
{
    Object1 -= Object2;
    return Object1;
}
Participant& operator -(Participant Object, double number)
{
    Object -= number;
    return Object;
}
Participant& operator *(Participant Object1, Participant& Object2)
{
    Object1 *= Object2;
    return Object1;
}
Participant& operator *(double number, Participant Object)
{
    Object *= number;
    return Object;
}
Participant& operator *(Participant Object, double number)
{
    Object *= number;
    return Object;
}
Participant& operator /(Participant Object1, Participant& Object2)
{
    Object1._punctaj = Object1._punctaj / Object2._punctaj;
    return Object1;
}
Participant& operator /(Participant Object, double number)
{
    Object._punctaj = Object._punctaj / number;
    return Object;
}
ifstream& operator >>(ifstream& stream, Participant& Object)
{
    stream >> Object._nume >> Object._prenume >> Object._punctaj;
    return stream;
}
istream& operator >>(istream& stream, Participant& Object)
{
    stream >> Object._nume >> Object._prenume >> Object._punctaj;
    return stream;
}
ofstream& operator <<(ofstream& stream, Participant& Object)
{
    stream << Object._nume << " " << Object._prenume << ": " << Object._punctaj << '\n';
    return stream;
}
ostream& operator <<(ostream& stream, Participant& Object)
{
    stream << Object._nume << " " << Object._prenume << ": " << Object._punctaj << '\n';
    return stream;
}