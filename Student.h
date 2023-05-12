#include <string>

class Student
{
   private:
      std::string Matrikelnummer;
      std::string Vorname;
      std::string Nachname;
      double NotenSumme;
      int AnzahlNoten;
      double NotenDurchschnitt;  
   public:
      Student(std::string n, std::string vn, std::string nn, double nd);
      void VorlesungsNote(double note);
      void print();
      std::string getMatrikelNr();
      double getSchnitt();
};