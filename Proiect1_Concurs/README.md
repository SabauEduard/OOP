# Proiect POO - Clase: Participant si Concurs 

Primul proiect de programare orientata pe obiecte. Proiectul contine definirile celor 2 clase cu metodele, functiile si constructorii lor, un concurs  deja construit cu 18 participanti deja introdusi pe care se poate testa utilitatea functiilor cu ajutorul meniului interactiv. De asemenea, desi supraincarcarea operatorilor nu este prezenta direct in meniul interactiv, acestia sunt folositi in diferite functii din clasa "Concurs" pentru a usura scrierea acestora si inainte de pornirea meniului interactiv cand se adauga participantii in concursul deja existent.

## Clasa Participant 

Clasa "Participant" contine numele, prenumele si punctajul unui participant din cadrul concursului. 

### Constructori

Aceasta clasa are 2 constructori, unul care primeste doua string-uri si un double, iar celalalt un alt obiect de tipul "Participant".

```C++
Participant A("Sabau", "Eduard", 400); // se creeaza obiectul A pentru care numele va fi Sabau, prenumele Eduard, iar punctajul 400
Participant B(A); // se creeaza obiectul B cu atributele obiectului A
Participant C(); // se creeaza obiectul C cu atributele: nume = Neintrodus, prenume = Neintrodus, punctaj = 0)
```

### Operatori supraincarcati

Toti operatorii supraincarcati in afara de cei pentru citire si afisare lucreaza doar cu punctajul participantului, astfel este permisa adunarea de 2 obiecte, un obiect cu un numar sau un numar cu un obiect, rezultatul fiind mereu primul obiect gasit ca termen cu punctajul schimbat aferent operatiei. Operatorul de afisare afiseaza pe ecran numele, prenumele si punctajul cu un spatiu intre ele si trece la linie noua. Operatorul de citire asteapta ca input un nume de tip string, prenume de tip string si un punctaj de tip double.

```C++
Participant A("Sabau", "Eduard", 400);
Participant B("Paun", "Tudor", 380);
Participant C("Stanescu", "Lata", 200);
A += B; // A va avea punctajul 780
A = B + C; // A va avea punctajul 580
A = A / 2; // A va avea punctajul 290
B = B * 2; // B va avea punctajul 1060
C += 2; // C va avea pucntajul 202
cin >> C; // Presupunem ca s-a introdus "Ionescu Sebastian 100"
cout << C; // Se vor afisa "Ionescu Sebastian 100" si va trece la linie noua dupa
```

### Set-eri si Get-eri

Avem functiile "set_nume", "set_prenume" si "set_punctaj" ce primesc string, string, respectiv double ca parametrii si functiile "get_nume", "get_prenume" "get_punctaj" ce returneaza string, string, respectiv double.

```C++
Participant A; // va avea nume = Neintrodus, prenume = Neintrodus, punctaj = 0
A.set_nume("Stelian"); // nume = Stelian
A.set_prenume("Iosif"); // prneume = Iosif
A.set_punctaj(400); // punctaj = 400
cout << A.get_nume() << " " << A.get_prenume() << " " << A.get_punctaj <<'\n'; // va afisa "Stelian Iosif 400" si va trece la linie noua
```

## Clasa Concurs

Clasa "Concurs" contine un vector cu elemente de tipul "Participant" si un string cu numele concursului. Pentru aceasta clasa nu am supraincarcat niciun operator.

### Constructori 

Aceasta clasa are 3 constructori unul neparametrizat, unul ce primeste un string, si unul ce primeste alt obiect de tipul "Concurs".

```C++
Concurs C1; // numele concursului va fi un string gol si vectorul de participanti va fi gol
Concurs C2("MateInfoUB") // numele concursului va fi string-ul "MateInfoUB" iar vectorul de participanti va fi gol
Concurs C3(C2) // concursul C3 va avea atributele concursului C2, se va copia doar numele in acest caz
```

### Metode si Functii

#### 1. void add_participant(string, string, double) sau void add_participant(Participant&)

Functia add_participant poate primi ca parametrii doua string-uri si un double sau un obiect de tipul Participant. Aceasta va adauga participantul cu datele respective in vectorul de participanti al concursului.

```C++
Participant A("Popescu", "Adrian", 116);
MateInfoUB.add_participant(A); 
MateInfoUB.add_participant("Stanescu", "Lata", 200);
```

#### 2. void remove_participant(string, string, double) sau  void remove_participant(Participant&) sau void remove_poz(int)

Functia remove_participant poate primi ca parametrii doua string-uri si un double sau un obiect de tipul Participant. Aceasta va cauta daca participantul cu datele respective exista si il va scoate din vectorul de participanti.

Functia remove_poz primeste ca parametru un integer si scoate participantul de pe pozitia respectiva din vectorul de participanti.

```C++
Participant A("Popescu", "Adrian", 116);
MateInfoUB.add_participant(A); 
MateInfoUB.add_participant("Stanescu", "Lata", 200);
remove_participant(A); // va ramne doar "Stanescu Lata 200"
remove_index(0); // vectorul de participanti va fi gol
```

#### 3. int get_nr_participanti() si string get_nume() si double get_medie() si void set_nume_concurs(string) 

Cei 3 get-eri returneaza size-ul vectorului de participanti, numele concursului si ultimul calculeaza media participantilor.

Seter-ul schimba numele concursului.

```C++
Participant A("Popescu", "Adrian", 116);
C1.add_participant(A); 
C1.add_participant("Stanescu", "Lata", 200);
C1.set_nume_concurs("Ceva_la_urs"); // numele concursului devine "Ceva_la_urs"
cout << C1.get_nume() << " " << C1.get_nr_participanti() << " " << C1.get_medie(); // Ceva_la_urs 2 158
```

#### 4. void afisk_inceput(int k) si void afisk_sfarsit(int k) si void afis()

Primele doua functii afiseaza primii k sau ultimii k participanti din vector.

Ultima functia afiseaza toti participantii din vector.

```C++
Participant A("Popescu", "Adrian", 116);
C1.add_participant(A); 
C1.add_participant("Stanescu", "Lata", 200);
C1.add_participant("Paun", "Tudor", 100);
C1.afisk_inceput(2) // Popescu Adrian 116 '\n' Stanescu Lata 200 '\n'
C1.afisk_sfarsit(2) // Paun Tudor 100 '\n' Stanescu Lata 200 '\n'
C1.afis() // Popescu Adrian 116 '\n' Stanescu Lata 200 '\n' Paun Tudor 100 '\n'
```

#### 5. int admisi_p(double p)

Returneaza numarul participantilor care au punctajul mai mare sau egal cu p.

```C++
Participant A("Popescu", "Adrian", 116);
C1.add_participant(A); 
C1.add_participant("Stanescu", "Lata", 200);
C1.add_participant("Paun", "Tudor", 100);
cout << C1.admisi_p(116); // 2
```

#### 6. void sort (bool reverse = 0)

Sorteaza vectorul de participanti crescator sau descrescator dupa punctaj daca parametrul trimis are valoarea "true"

```C++
Participant A("Popescu", "Adrian", 116);
C1.add_participant(A); 
C1.add_participant("Stanescu", "Lata", 200);
C1.add_participant("Paun", "Tudor", 100);
C1.sort();
C1.afis() // Paun Tudor 100 '\n' Popescu Adrian 116 '\n' Stanescu Lata 200 '\n'
C1.sort(1);
C1.afis() // Stanescu Lata 200 '\n' Popescu Adrian 116 '\n' Paun Tudor 100 '\n'
```

#### 7. bool check_participant(string, string, double) sau bool check_participant(Participant&)

Verifica daca participantul cu atributele respective este in vectorul de participanti.

```C++
Participant A("Popescu", "Adrian", 116);
C1.add_participant(A); 
C1.add_participant("Stanescu", "Lata", 200);
C1.add_participant("Paun", "Tudor", 100);
cout << check_participant(A) // true
cout << check_participant("Johnny", "Nebunul", 100) // false
```

## Meniul Interactiv 

Primul meniu interactiv prezinta 4 optiuni initiale de la -1 la 2: </br>

-1 Programul se opreste. </br>
0 Se creeaza un nou concurs care va cere apoi introducerea unui nume. </br>
1 Se afiseaza concursurile existente </br>
2 Permite introducerea unui nume de concurs pe care apoi il va selecta din lista si va deschide noul meniu de optiuni </br>

Al doilea meniu interactiv prezinta optiuni de la 0 la 12: </br>

0 Se adauga un nou participant cu datele care urmeaza sa fie introduse. </br>
1 Sterge participantul cu datele care urmeaza sa fie introduse daca acesta exista. </br>
2 Permite schimbarea numelui concursului cu un nume care urmeaza sa fie introdus. </br>
3 Se afiseaza lista tuturor participantilor. </br>
4 Se sorteaza crescator participantii. </br>
5 Se sorteaza descrescator participantii. </br>
6 Se afiseaza primii k participanti, k se citeste de la tastatura. </br>
7 Se afiseaza ultimii k participanti, k se citeste de la tastatura. </br>
8 Se afiseaza numarul participantilor. </br>
9 Se afiseaza media tuturor participantilor </br>
10 Se afiseaza cati participanti au punctajul mai mare sau egal cu p, citit de la tastatura. </br>
11 Se verifica daca participantul a fost deja introdus in concurs. </br>
12 Se revine la primul meniu. </br>
