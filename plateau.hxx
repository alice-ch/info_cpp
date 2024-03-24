
#if !defined plateau_hxx
#define plateau_hxx

#include "piece.hxx"


// Declaration d'une classe modélisant une piece de jeu d'echec.

class Echiquier
{
private:

  //Les cases de l'echiquier
  Piece* m_cases[ 64 ];

public:

  //Constructeur par défaut.
  //Initialise à vide l'echiquier.
  Echiquier();


  //Recupere la piece situee sur une case.
  //x et y des entiers entre 1 et 8
  //Renvoie 0 si aucune piece n'est sur cette case et un pointeur * vers une piece sinon.
  Piece* getPiece( int x, int y );

  //Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece : p un pointeur vers une piece
  //Renvoie 'true' si le placement s'est bien passe, 'false' sinon (case occupee, coordonnées invalides, piece vide )
  bool placer( Piece* p );

  //Deplace une piece sur l'echiquier, des coordonnees specifiees dans la piece aux coordonnees x, y :
  // p un pointeur vers une piece
  // x un entier entre 1 et 8
  // y un entier entre 1 et 8
  // Renvoie 'true' si le placement s'est bien passe, 'false' sinon (case occupee, coordonnees invalides, piece vide, piece pas presente au bon endroit sur l'echiquier)
  bool deplacer( Piece* p, int x, int y );

  //Enleve la piece situee sur une case (qui devient vide).
  // x un entier entre 1 et 8
  // y un entier entre 1 et 8
  //Renvoie 0 si aucune piece n'est sur cette case et le pointeur vers la piece enlevee sinon.
  Piece* enleverPiece( int x, int y );

  //Affiche l'echiquier avec des # pour les cases noires et . pour les blanches si elles sont vides, et avec B pour les pieces blanches et N pour les pieces noires.
  void affiche();


};

#endif 