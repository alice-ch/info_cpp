
#if !defined piece_hxx
#define piece_hxx

class Echiquier;

//Declaration d'une classe modélisant une piece de jeu d'echec.

class Piece
{
protected:
  int m_x;  // coordonnée x de la pièce
  int m_y;  // coordonnée y de la pièce
  bool m_white; // dit si la pièce est blanche ou non
public:
  Piece(); //
  virtual ~Piece(); //
  Piece(const Piece & autre); //
  Piece & operator=(const Piece & autre); //
  Piece( int x, int y, bool white ); //
  void init( int x, int y, bool white ); //
  void move( int x, int y ); //
  int x(); //
  int y(); //
  bool isWhite(); //
  bool isBlack(); //
  void affiche(); //
  virtual bool mouvementValide(Echiquier &e, int x, int y); //= 0; //Le =0 permet de déclarer la méthode mouvementValide pour les pièces dérivées (roi, reine...) mais pas pour la pièce elle-même
  virtual char codePiece(); //
};


class Roi : public Piece
{
  public:
   Roi(bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Fou : virtual public Piece
{
  public:
   Fou(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Tour : virtual public Piece
{
  public:
   Tour(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Reine : public Fou, public Tour
{
  public:
   Reine(bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Cavalier : virtual public Piece
{
  public:
   Cavalier(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Pion :  virtual public Piece
{
  public:
   Pion(int x, bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};
#endif 