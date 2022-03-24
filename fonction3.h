#ifndef FONCTION1_H_
#define FONCTION1_H_


typedef struct
{
SDL_Surface *im;
SDL_Rect rect;

}vie;


typedef struct
{

SDL_Surface *image;
SDL_Surface *texte;
int scr;
char temp[100];
SDL_Rect rect ;

}score;


typedef struct
{
SDL_Surface *im;
SDL_Rect rect;
SDL_Rect rect1[10];
SDL_Rect saut;
int direction;
int mouvement[4];
vie v;
score s;
int k;
int position_saut;
int on_ground;
int frame;
}personne;

typedef struct 
{
SDL_Surface *im[2];
SDL_Surface *anime1;
SDL_Surface *anime2;
SDL_Rect rect1[4],rect2;
SDL_Rect rect4,rect5,camera,rect6;
SDL_Rect rect3[4];
int i,pasavancement;
int k;
SDL_Surface *masque[2];
int etat_anime;
}background;

typedef struct 
{

SDL_Surface *im;
SDL_Rect rect;
SDL_Rect rect1[6];
int direction;
int mouvement[2];
int avancement;  
int max;
int min;
int frame;
int vie;
}ennemi;

typedef struct
{
SDL_Surface *im[3];
SDL_Rect rect;
SDL_Rect camera;
int redimensionnement;
int k;
}minimap;


typedef struct
{
SDL_Surface *im[5];
SDL_Surface *im1[4];
SDL_Surface *animemenu;
int a;
int asetting;
int bsetting;
int oksetting;
int anime;
SDL_Rect rect;
SDL_Rect rect1;
SDL_Rect rect2[2];
int frame;
}menu;


typedef struct
{

SDL_Surface *im[3];
int a;

}sousmenu;







void animermenu(menu *m);
void initmenu(menu *m);
void  menucontrolmouse(SDL_Event event,menu *m);
void afficher(SDL_Surface *image,SDL_Surface *window);
void menucontrolekeyboard(SDL_Event event ,menu *m);
void settings(SDL_Surface *window,menu *m);
void initperso(personne *p);
void initperso1(personne *k);
void afficherperso(personne p,SDL_Surface *screen);
void deplacerperso(personne *p ,int dt,SDL_Surface *screen,SDL_Surface *im);
void animer(personne *p);
void afficherminimap(minimap m,SDL_Surface *screen);
void clips(SDL_Rect  *clip);
void scrolling(background *b ,int direction , int pasavancement);
void initebackground(background *b);
void animerbackground(background *b);
void majminimap(minimap *m,int direction);
void ennemi1(SDL_Rect *rect1);
int collisionBB(personne p,ennemi e);
void initminimap(minimap *m);
void animerbackground2(background *b);
void initennemie(ennemi *e);
void deplacerennemie(ennemi *e);
void afficherennemie(ennemi e,SDL_Surface *screen);
void animerennemie(ennemi *e);
void afficherbackground(background b,SDL_Surface *screen);
void anime(SDL_Rect *rect);
void saut(personne *p,SDL_Surface *screen ,background b);
SDL_Color getpixel(SDL_Surface *surface ,int x, int y);
int collisonparfaite(SDL_Surface *calque,personne p,background b);
void jeu(SDL_Surface *window);
void clipsmenu(SDL_Rect *menu);
void sous_menue(sousmenu *sm);
void sousmenucontrolmouse(SDL_Event event ,sousmenu *sm);
void gestionsousmenu(SDL_Surface *window,sousmenu *sm);





#endif
