
#if !defined partie_h
#define partie_h

#include "piece.hxx"
#include "plateau.hxx"
#include "joueur.hxx"
#include <string>

using namespace std;

class Partie
{
 protected:
    Echiquier e;
    JoueurBlanc jb;
    JoueurNoir jn;
    bool joueurActuel;
    int x;
    int y;


 public:
  Partie();
  ~Partie();
  void jouerPartie();
  void Acquisition(int* x, int* y);
  bool verifCoordonnees(int x, int y);
  int YaEchecAdv();
};


#endif