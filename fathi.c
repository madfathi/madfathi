


#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "fonction3.h"

void sous_menue(sousmenu *sm)
{
sm->im[0]=IMG_Load("sousmenu.png");
sm->im[1]=IMG_Load("play.png");
sm->im[2]=IMG_Load("soumenue.jpg");


sm->a=0;


}


void sousmenucontrolmouse(SDL_Event event ,sousmenu *sm)
{
if(event.motion.x>487 && event.motion.x<859 && event.motion.y >79  && event.motion.y <300  )
{
sm->a=1;
}


else if(event.motion.x>477 && event.motion.x<865 && event.motion.y >414  && event.motion.y <638 )
{
sm->a=2;
}

else
sm->a=0;





}




void initmenu(menu *m)
{
m->im[0]=SDL_LoadBMP("d.bmp");
m->im[1]=SDL_LoadBMP("d1.bmp");
m->im[2]=SDL_LoadBMP("d2.bmp");
m->im[3]=SDL_LoadBMP("d3.bmp");
m->im[4]=SDL_LoadBMP("d4.bmp");
m->im1[0]=SDL_LoadBMP("1234.bmp");
m->im1[1]=SDL_LoadBMP("789.bmp");
m->im1[2]=SDL_LoadBMP("55.BMP");
m->im1[3]=SDL_LoadBMP("78945.BMP");
m->animemenu=IMG_Load("feu.png");
m->rect.x=295;
m->rect.y=640;

m->rect1.x=850;
m->rect1.y=530;

m->asetting=0;
m->bsetting=0;
m->oksetting=0;
m->frame=0;
m->anime=0;
clipsmenu(m->rect2);

}

void clipsmenu(SDL_Rect *menu)
{

/*menu[0].x=19;
menu[0].y=0;
menu[0].w=124;
menu[0].h=241;
*/
menu[0].x=187;
menu[0].y=0;
menu[0].w=310-187;
menu[0].h=241;

menu[1].x=343;
menu[1].y=0;
menu[1].w=465-343;
menu[1].h=241;

}


void animermenu(menu *m)
{
if(m->frame==8)
{
if(m->anime<1)
{
m->anime++;
}
else
m->anime=0;

m->frame=0;
}
else
m->frame++;



}


void afficher(SDL_Surface *image,SDL_Surface *window)
{


SDL_BlitSurface(image,NULL,window,NULL);


}

void menucontrolmouse(SDL_Event event ,menu *m)
{
if(event.motion.x>205 && event.motion.x<430 && event.motion.y > 332 && event.motion.y < 363)
{
m->a=1;
}


else if(event.motion.x>205 && event.motion.x<412 && event.motion.y >427 && event.motion.y < 465)
{
m->a=2;
}


else if(event.motion.x>195 && event.motion.x<328 && event.motion.y > 507 && event.motion.y < 544)
{
m->a=3;
}

else if(event.motion.x>157 && event.motion.x<256 && event.motion.y >598  && event.motion.y <632)
{


m->a=4;

}
else
{
m->a=0;
}

}

void menucontrolekeyboard(SDL_Event event ,menu *m)
{


SDL_Delay(10);
if(event.key.keysym.sym==SDLK_DOWN)
{
if(m->a<4)
{
m->a++;

}
else
m->a=0;
}

if(event.key.keysym.sym==SDLK_UP)
{
if(m->a>0)
m->a--;
else
m->a=4;
}

}
void settings(SDL_Surface *window,menu *m)
{

int done =0;
SDL_Event event1;

while(done==0)
{
SDL_WaitEvent(&event1);

if(event1.type==SDL_KEYDOWN)
{
 if(event1.key.keysym.sym==SDLK_ESCAPE)
    {
       m->a=0;
       done=1;
    }
}
if(event1.button.button == SDL_BUTTON_LEFT)
{
if(event1.button.x>892 && event1.button.x<964 && event1.button.y >291 && event1.button.y <374  )
{
m->asetting=1;
}
if(event1.button.x>574 && event1.button.x<645 && event1.button.y >291 && event1.button.y <374  )
{
m->asetting=0;
}
if(event1.button.x>892 && event1.button.x<971 && event1.button.y >435 && event1.button.y <515  )
{
m->bsetting=1;
}
if(event1.button.x>574 && event1.button.x<645 && event1.button.y >433 && event1.button.y <514  )
{
m->bsetting=0;
}
}

if(m->asetting==0 && m->bsetting==0)
{
m->oksetting=0;
}
else if(m->asetting==1 &&m->bsetting==0)
{
m->oksetting=1;
}
else if(m->asetting==0 && m->bsetting==1)
{
m->oksetting=2;
}
else if(m->asetting==1 && m->bsetting ==1)
{
m->oksetting=3;
}



afficher(m->im1[m->oksetting],window);
SDL_Flip(window);





}

}


void jeu(SDL_Surface *window)
{
SDL_Surface *photo=NULL,*masque=NULL;
photo=IMG_Load("19.bmp");
personne p,p1 ;
background b;
minimap m;
ennemi e;
SDL_Event event,event1;
int dt =20;  
int continuer = 0;
SDL_Surface *congrat=NULL;
congrat =IMG_Load("NBV.png"); 
masque=IMG_Load("ko2.png");
int walkdevant= 0;
int walkarriere= 0;
int saute = 0;
int walkdevant1 =0;
int walkarriere1 =0;
int saute1 =0;
int frappe = 0;
int rejouer=0;
int down=0;
int hit=0;
initennemie(&e);
initebackground(&b);
initminimap(&m);
int k=0;

int fps=15;
initperso(&p);
initperso1(&p1);
clips(p.rect1);
clips(p1.rect1);

SDL_EnableKeyRepeat(10,65);



while(continuer==0)
{


animerbackground(&b);
//animerbackground2(&b);
afficherbackground(b,window);



SDL_Delay(50);



SDL_PollEvent(&event);
if(event.type==SDL_QUIT)
exit(0);

if(event.type==SDL_KEYDOWN)
{
if(event.key.keysym.sym==SDLK_RIGHT)
{
walkdevant=1;

}
if(event.key.keysym.sym==SDLK_LEFT)
{
walkarriere=1;

}


if(event.key.keysym.sym ==SDLK_d)
{
walkdevant1=1;
}
if(event.key.keysym.sym==SDLK_q)
{
walkarriere1=1;
}
if(event.key.keysym.sym==SDLK_z)
{
saute1=1;
}
if(event.key.keysym.sym==SDLK_SPACE)
{

frappe=1;
}


if(event.key.keysym.sym ==SDLK_UP)
{
saute=1;
}
if(event.key.keysym.sym ==SDLK_e)
{
rejouer=1;
}
if(event.key.keysym.sym ==SDLK_DOWN)
{
down=1;
}
if(event.key.keysym.sym == SDLK_b)
{
hit=1;
}





if(walkdevant==1 && collisonparfaite(b.masque[b.k],p,b)==0)

{
p.direction=0;
deplacerperso(&p,dt,window,masque);
animer(&p);
SDL_Delay(20);


if(p.rect.x>=1382/2)
{
scrolling(&b,p.direction,b.pasavancement);
majminimap(&m,p.direction);

}

}
if(walkarriere==1)
{
p.direction=1;
SDL_Delay(20);
if(b.camera.x>=1382/2)
{
scrolling(&b,p.direction,b.pasavancement);
animer(&p);
majminimap(&m,p.direction);

}
else
{
deplacerperso(&p,dt,window,photo);
animer(&p);
}

}

if(saute==1)
{
if(p.on_ground==0)
{
while(p.saut.x<=50 && collisonparfaite(b.masque[b.k],p,b)!=1 )
{
b.rect2.x=b.rect2.x-6;
b.rect4.x=b.rect4.x-6;
b.rect5.x=b.rect5.x-6;

saut(&p,masque,b);
animerbackground(&b);
// animerbackground2(&b);
SDL_Delay(5);

scrolling(&b,2,b.pasavancement);
afficherbackground(b,window);
afficherperso(p,window);
afficherperso(p1,window);
SDL_Flip(window);

}

}
 if(p.on_ground==1)
{
while(collisonparfaite(b.masque[b.k],p,b)!=1 && p.rect.y<451 )
{
saut(&p,masque,b);
animerbackground(&b);
scrolling(&b,2,b.pasavancement);
afficherbackground(b,window);
afficherperso(p,window);
afficherperso(p1,window);
SDL_Flip(window);
}

}
p.saut.x=-50;
p.position_saut=p.rect.y;

}
if(p.rect.y>450 )
{
p.position_saut=450;
p.rect.y=450;
p.on_ground=0;
}
else if (p.rect.y<450)
{
p.on_ground=1;
}

if(hit==1)
{

p.direction=4;
deplacerperso(&p,dt,window,masque);
animer(&p);

}

if(walkdevant1==1)
{
p1.direction=0;
deplacerperso(&p1,dt,window,masque);
animer(&p1);




}


if(rejouer==1  )
{

while(k==0)
{
SDL_WaitEvent(&event1);
SDL_BlitSurface(photo,NULL,window,NULL);
SDL_Flip(window);

if(event1.type==SDL_MOUSEBUTTONUP)
{
if(event1.button.button == SDL_BUTTON_LEFT)
{
if(event1.button.x>289 && event1.button.x<532  && event1.button.y >269  && event1.button.y <384)
{

k=1;

}
else  if(event1.button.x>880 && event1.button.x<1150 && event1.button.y >265 && event1.button.y < 379)
{
k=2;
initebackground(&b);
initminimap(&m);
initperso(&p);
initperso1(&p1);
p.s.scr=100;
b.k=1;
m.k=1;
SDL_BlitSurface(congrat,NULL,window,NULL);
SDL_Flip(window);
SDL_Delay(5000);
}
}
}
}
}



if(walkarriere1==1)
{
p1.direction=1;
deplacerperso(&p1,dt,window,masque);
animer(&p1);
}
if(saute1==1)
{
while(p1.saut.x<=50)
{

//saut(&p1);
SDL_BlitSurface(photo,NULL,window,NULL);
afficherperso(p1,window);
afficherperso(p,window);
SDL_Flip(window);

}
p1.saut.x=-50;
}

if(frappe ==1)
{


p.direction =  2;
deplacerperso(&p,dt,window,masque);
animer(&p);

if(e.vie==0)
{
e.im=NULL;
e.rect.x=-1000;
e.max=-1000;

}
else
e.vie--;

}


}








if(event.type==SDL_KEYUP)
{
if(event.key.keysym.sym == SDLK_UP)
{
saute=0;

}
else if(event.key.keysym.sym == SDLK_LEFT)
{
walkarriere=0;
}
 else if(event.key.keysym.sym == SDLK_RIGHT)
{
walkdevant=0;
}
else if(event.key.keysym.sym==SDLK_d)
{
walkdevant1=0;
}
else if(event.key.keysym.sym==SDLK_q)
{
walkarriere1=0;
}
else if(event.key.keysym.sym==SDLK_z)
{
saute1=0;
}
else if(event.key.keysym.sym==SDLK_SPACE)
{
frappe=0;
}
else if(event.key.keysym.sym==SDLK_e)
{
rejouer=0;
k=0;
}

else if(event.key.keysym.sym==SDLK_b)
{
hit=0;
}


}//fin sdlk up



p.k=0;
 

animerbackground(&b);


animerennemie(&e);

afficherbackground(b,window);
afficherennemie(e,window);
afficherperso(p,window);


afficherperso(p1,window);
afficherminimap(m,window);
afficherennemie(e,window);
if(collisionBB(p,e)==0)
{
p.rect.x-=500;

}


//majminimap(&m);
SDL_Flip(window);







}
SDL_FreeSurface(b.im[0]);
SDL_FreeSurface(b.im[1]);
SDL_FreeSurface(p.im);
SDL_FreeSurface(p.s.image);
SDL_FreeSurface(p.s.texte);
SDL_FreeSurface(p.v.im);
SDL_FreeSurface(e.im);
SDL_FreeSurface(b.anime1);
SDL_FreeSurface(m.im[0]);
SDL_FreeSurface(m.im[1]);
SDL_FreeSurface(congrat);



}



SDL_Color getpixel(SDL_Surface *surface ,int x, int y)
{
SDL_Color color;
Uint32 col = 0;
Uint32* pixels=(Uint32*)surface->pixels;

char*position =(char *)surface->pixels;

position +=(surface->pitch*y);
position+=(surface->format->BytesPerPixel*x);
memcpy(&col,position,surface->format->BytesPerPixel);
SDL_GetRGB(col,surface->format,&color.r,&color.g,&color.b);
return (color);
}
int collisonparfaite(SDL_Surface *calque,personne p,background b)
{

SDL_Color col;
col=getpixel(calque,b.camera.x+787,p.rect.y+245);

if((col.r==0)&&(col.g==0) && (col.b==0))
return 1;
else
return 0;





}












void clips(SDL_Rect  *clip)
{
clip[0].x=6 ;
clip[0].w=152;
clip[0].y=0;
clip[0].h=255;

clip[1].x=159;
clip[1].w=149 ;
clip[1].y=0;
clip[1].h=255;

clip[2].x=358;
clip[2].w=159;
clip[2].y=0;
clip[2].h=255;

clip[3].x=553;
clip[3].w=155;
clip[3].y=0;
clip[3].h=255;

clip[4].x=791;
clip[4].w=935-791;
clip[4].y=0;
clip[4].h=255;

clip[5].x=976;
clip[5].w=1155-976;
clip[5].y=0;
clip[5].h=255;

clip[6].x=942;
clip[6].w=186;
clip[6].y=0;
clip[6].h=255;


clip[7].x=1395;
clip[7].w=139;
clip[7].y=0;
clip[7].h=255;

clip[8].x=1552;
clip[8].w=118;
clip[8].y=0;
clip[8].h=255;




}


void anime(SDL_Rect *rect)
{
rect[0].x=7;
rect[0].w=61;
rect[0].y=0;
rect[0].h=58;

rect[1].x=67;
rect[1].w=57;
rect[1].y=0;
rect[1].h=58;

rect[2].x=127;
rect[2].w=53;
rect[2].y=0;
rect[2].h=58;

rect[3].x=182;
rect[3].w=57;
rect[3].y=0;
rect[3].h=58;

}

void ennemi1(SDL_Rect *rect1)
{

rect1[2].x=16;
rect1[2].w=139;
rect1[2].y=0;
rect1[2].h=192;

rect1[1].x=201;
rect1[1].w=168;
rect1[1].y=0;
rect1[1].h=302;

rect1[0].x=406;
rect1[0].w=121;
rect1[0].y=0;
rect1[0].h=302;

rect1[3].x=555;
rect1[3].w=122;
rect1[3].y=0;
rect1[3].h=302;

rect1[4].x=712;
rect1[4].w=169;
rect1[4].y=0;
rect1[4].h=302;

rect1[5].x=925;
rect1[5].w=140;
rect1[5].y=0;
rect1[5].h=302;

}

int collisionBB(personne p,ennemi e)
{

if(p.rect.x+120==e.rect.x ||p.rect.x==e.rect.x || p.rect.x+105==e.rect.x  )
return 0;
else
return 1;



}


void scrolling(background *b ,int direction , int pasavancement)
{
if(direction==0 && b->camera.x<9666-1382-10 )
{
b->camera.x+=pasavancement;
}
else if(direction==1)
{
b->camera.x-=pasavancement;

}
else if(direction==2)
{
b->camera.x+=2;


}

}
void initminimap(minimap *m)
{

m->im[0]=IMG_Load("78.png");
m->im[1]=IMG_Load("SNW1.png");

m->rect.x= 470;
m->rect.y = 0;


m->camera.x = 0;
m->camera.y = 0;
m->camera.h = 150;
m->camera.w = 400;
m->k=0;

}

void afficherminimap(minimap m,SDL_Surface *screen)
{
SDL_BlitSurface(m.im[m.k],&m.camera,screen,&m.rect);
}


void majminimap(minimap *m,int direction)
{
if(direction==0)
{
if(m->camera.x<1751-400)
m->camera.x+=2;
}
else
{
if(m->camera.x>0)
m->camera.x-=2;
}

}








void initebackground(background *b)
{
b->im[0] = IMG_Load("9999.png");
b->im[1] = IMG_Load("ji.png");
b->anime1 = IMG_Load("BIRD.png");
b->camera.x=0;
b->camera.w=1382;
b->camera.y=0;
b->camera.h=895;
b->masque[0]=IMG_Load("ko2.png");
b->masque[1]=IMG_Load("ko3.png");



b->rect2.x= 500;
b->rect2.y = 350;
b->rect4.x= 450;
b->rect4.y = 330;

b->rect5.x=-50;
b->rect5.y = 330;
anime(b->rect1);
b->pasavancement=15; 

int i=0;
b->k=0;
}


void initennemie(ennemi *e)
{
e->im = IMG_Load("made.png");
e->rect.x =600;
e->rect.y =500;
ennemi1(e->rect1);
e->mouvement[0] = 0;
e->mouvement[1] = 3;
e->direction = 1;
e->avancement=10; 
e->max=850;
e->min =600;
e->frame=0;
e->vie=3;

}



void animerennemie(ennemi *e)
{


if(e->frame==2)
{
e->frame=0;
if(e->direction==1)
{
if(e->rect.x>e->min)
{
e->rect.x-=10;
if(e->mouvement[e->direction]<5)
{
e->mouvement[e->direction]++;
SDL_Delay(19);

}
else
{
e->mouvement[e->direction]=3;
}
}
else
{
e->direction=0;

}

}

if(e->direction==0)
{
if(e->rect.x<e->max)
{
e->rect.x+=10;


if(e->mouvement[e->direction]<2)
{
e->mouvement[e->direction]++;
SDL_Delay(19);
}
else
{
e->mouvement[e->direction]=0;
}
}
else
{
e->direction=1;
e->mouvement[e->direction]=0;

}


}
}
e->frame++;


}


void deplacerennemie(ennemi *e)
{
if (e->rect.x <= (1382/2))
e->rect.x+=e->avancement;
else
e->rect.x = 0;
}

void afficherennemie(ennemi e,SDL_Surface *screen)

{
SDL_BlitSurface(e.im,&e.rect1[e.mouvement[e.direction]],screen,&e.rect);
}



void animerbackground(background *b)
{
if(b->i<3)
b->i++;
else
b->i = 0;

if(b->rect2.x<1382)
{
b->rect2.x = b->rect2.x+10;
}
else
{
b->rect2.x = 0;
}
if(b->rect4.x<1382)
{
b->rect4.x = b->rect4.x+10;
}
else
{
b->rect4.x = 0;
}
if(b->rect5.x<1382)
b->rect5.x = b->rect5.x+10;
else
b->rect5.x = 0;
 
}



/*void animerbackground2(background *b)
{
if(b->i<3)
{
b->i++;
}
else
{
b->i = 0;
}

if(b->rect4.x<1382)
{
b->rect4.x = b->rect4.x+10;
}
else
{
b->rect4.x = 0;
}
}*/








void afficherbackground(background b,SDL_Surface *screen)
{

SDL_BlitSurface(b.im[b.k],&b.camera,screen,NULL);
SDL_BlitSurface(b.anime1,&b.rect1[b.i],screen,&b.rect5);
SDL_BlitSurface(b.anime1,&b.rect1[b.i],screen,&b.rect4);
SDL_BlitSurface(b.anime1,&b.rect1[b.i],screen,&b.rect2);


}







void animer(personne *p)
{
if(p->direction==0)
{
if(p->mouvement[p->direction] <1)
{
p->mouvement[p->direction]++;
}
else
p->mouvement[p->direction] = 0 ;
}
else if(p->direction==1)
{
if(p->mouvement[p->direction] <3)
{
p->mouvement[p->direction]++;
}
else
p->mouvement[p->direction] = 2 ;
}
else if(p->direction==2)
{
if(p->mouvement[p->direction] <5)
{
p->mouvement[p->direction]++;
}
else
p->mouvement[p->direction] = 4 ;
}
else if(p->direction == 4  )
{
if(p->mouvement[p->direction] <8)
{
p->mouvement[p->direction]++;
}
else
p->mouvement[p->direction] = 7 ;

}
p->frame++;
}






void initperso(personne *p)
{

p->im =IMG_Load("jo.png");
p->rect.x=0;
p->rect.y =450;
p->direction=0;
p->mouvement[0] =0;
p->mouvement[1]=2;
p->mouvement[2]=4;
p->mouvement[3]=10;
p->mouvement[4]=7;
p->frame=0;
p->v.im=IMG_Load("HEALTH.png");
p->v.rect.x=1000;
p->v.rect.y=0;
p->saut.x=-50;
p->saut.y=0;
p->s.rect.x=91;
p->s.rect.y=91;
p->s.scr=100;
p->s.image =IMG_Load("bureau.png");
p->k=0;
p->position_saut=450;
p->on_ground=0;

}


void initperso1(personne *k)
{
k->im =IMG_Load("MARCHE.png");
k->rect.x=0;
k->rect.y =514;
k->direction=0;
k->mouvement[0] =0;
k->mouvement[1] =2;
k->saut.x=-50;
k->saut.y=0;



}









void afficherperso(personne p,SDL_Surface *screen)
{
SDL_BlitSurface(p.v.im,NULL,screen,&p.v.rect);
SDL_BlitSurface(p.s.image,NULL,screen,NULL);
SDL_BlitSurface(p.s.texte,NULL,screen,&p.s.rect);
SDL_BlitSurface(p.im,&p.rect1[p.mouvement[p.direction]],screen,&p.rect);
}

void deplacerperso(personne *p ,int dt,SDL_Surface *surface,SDL_Surface *im)
{
int x=200;
int y=200;

SDL_Color color  ={0,0,0};
TTF_Init();
TTF_Font *font = TTF_OpenFont("angelina.TTF",68);


if(p->direction == 0 && p->rect.x <=1382/2 /*&&( getpixel(im,p->rect.x-58,p->rect.y).r!=0 || getpixel(im,p->rect.x-58,p->rect.y).g!=0 || getpixel(im,p->rect.x-58,p->rect.y).b!=0)*/)
//SDL_MapRGB(im->format,getpixel(im,p->rect.x,p->rect.y).r,getpixel(im,p->rect.x,p->rect.y).g,getpixel(im,p->rect.x,p->rect.y).b)!=SDL_MapRGB(im->format,0,0,0)) 
{
p->rect.x+=dt;

}


else if(p->direction == 1 && p->rect.x >=0)
{
p->rect.x-=dt;
}
else if(p->direction == 4 && p->rect.x <=1382/2)
{
p->rect.x+=dt*1.2;
}


else if(p->direction == 2 && p->rect.x <=1382/2 )
{

SDL_Delay(10);
}


p->s.scr++;
sprintf(p->s.temp,"%d",p->s.scr);
p->s.texte =TTF_RenderText_Solid(font,p->s.temp,color);
}

void saut(personne *p,SDL_Surface *screen, background b)
{
//p->mouvement[p->direction] = 1;
int dt = 2;

p->saut.x++;
p->rect.y=p->position_saut;
p->saut.y =(-0.04*(p->saut.x*p->saut.x)+100)*dt;
//dt=dt*3;
p->rect.y=p->rect.y-p->saut.y;


}




