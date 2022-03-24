#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "fonction3.h"

int main(int argc ,char *argv[])
{


SDL_Surface *window= NULL;
int continuer =1;
int f=0;
menu m;
sousmenu sm;
putenv("SDL_VIDEO_CENTERED=1");
SDL_Init(SDL_INIT_VIDEO);
window = SDL_SetVideoMode(1382,828,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
initmenu(&m);
sous_menue(&sm);
SDL_Event event,event1;
SDL_EnableKeyRepeat(1,1);
int  i;

while(continuer==1)
{
//continuer1=1;
animermenu(&m);
afficher(m.im[m.a],window);
SDL_BlitSurface (m.animemenu,&m.rect2[m.anime],window,&m.rect);
SDL_BlitSurface(m.animemenu,&m.rect2[m.anime],window,&m.rect1);
SDL_Flip(window);




SDL_PollEvent(&event);



switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;
case SDL_MOUSEMOTION:
menucontrolmouse(event,&m);
break;
case SDL_KEYDOWN:

if(f==5)
{
menucontrolekeyboard(event,&m);
f=0;
}
else 
f++;
break;
case SDL_MOUSEBUTTONUP:
if(event.button.button == SDL_BUTTON_LEFT)
{
if(event.button.x>205 && event.button.x<412 && event.button.y >427 && event.button.y <465  )
{
settings(window,&m);

}

if(event.button.x>205 && event.button.x<430 && event.button.y >332 && event.button.y <363)
{

gestionsousmenu(window,&sm);


/*while(continuer1==1)
{
SDL_PollEvent(&event1);
switch(event1.type)
{

case SDL_MOUSEMOTION:
sousmenucontrolmouse(event1,&sm);
break;


case SDL_MOUSEBUTTONUP:
if(event1.button.button == SDL_BUTTON_LEFT)
{

if(event1.button.x>487 && event1.button.x<866 && event1.button.y >78 && event1.button.y <297 )
{
jeu(window);
}

if(event1.button.x>487 && event1.button.x<866 && event1.button.y >601 && event1.button.y <755 )
{
continuer1=0;
break;
}


}
break;



}//fin switch2



SDL_BlitSurface(sm.im[sm.a],NULL,window,NULL);
SDL_Flip(window);


}//fin while 2*/ 





}
}
break;
}




}


for(i=0;i<5;i++)
{
SDL_FreeSurface(m.im[i]);
}
for(i=0;i<4;i++)
{
SDL_FreeSurface(m.im1[i]);
}

SDL_FreeSurface(sm.im[0]);
SDL_FreeSurface(sm.im[1]);
SDL_FreeSurface(sm.im[2]);

SDL_FreeSurface(m.animemenu);





return 0;

}
