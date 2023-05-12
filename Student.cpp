#include "Student.h"
#include <iostream>

Student::Student(std::string n, std::string vn, std::string nn, double nd)
{
   Matrikelnummer = n;
   Vorname = vn;
   Nachname = nn;
   double NotenSumme = 0;
   int AnzahlNoten = 0;
   NotenDurchschnitt = nd;
}

void Student::VorlesungsNote(double note)
{
   NotenSumme += note;
   AnzahlNoten++;
   NotenDurchschnitt = NotenSumme / (double) AnzahlNoten;
}

void Student::print()
{
   std::cout << "Der Student hat folgende Daten:" << std::endl
             << " Matrikelnummer: " << Matrikelnummer << std::endl
             << " Vorname: " << Vorname << std::endl
             << " Nachname: " << Nachname << std::endl
             << " Noten-Durchschnitt: " << NotenDurchschnitt << std::endl;
}

std::string Student::getMatrikelNr()
{
   return Matrikelnummer;
}
 
double Student::getSchnitt()
{
   return NotenDurchschnitt;
}

