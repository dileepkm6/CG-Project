#include <time.h>
#include <windows.h>
#include <iostream>
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PI 3.14
int gameTime=60;
//different  gameState of game
int menu=1,play=2,pause=3,over=4,gameexit=5;
GLfloat headRadius=35;                                     //player head radius
GLfloat coinRadius=50;                                    //coin radius
char str [100];
int game_state=menu;                                           //store the game state
float c1Speed=6,c2Speed=8,c3Speed=10,c4Speed=12,c5Speed=13;//Speed of  Five balls
float ttime;                                                //store time passes
int t=0;                                                    //storing previous time
int i=0,j=0,k=0,l=0,m=0;                                     // use to set random position
int score=0;                                                 //store score
int w=1350,h=720;                                                    //World Size
//double Yspeed=10.0f;                                        //speed of Coins
double Xspeed=60.0f;                                        //speed of player
//float y=0;
struct Cir
{
    float Xc,Yc,radius;
};
struct Rect
{
    float left,right,top,bottom;
};
//structer of player
struct Pl
{

    Pl()
    {
      head={0.5*w,0.20*h,headRadius};
    }
  struct Cir head;
  struct Rect body;//={625,725,100,50};
  struct Rect leg;
};
struct Cir c1={75,720,coinRadius}; //first ball
struct Cir c2={300,720,coinRadius}; //second balls
struct Cir c3={550,720,coinRadius}; //third balls
struct Cir c4={800,720,coinRadius}; //second balls
struct Cir c5={1250,720,coinRadius}; //third balls
struct Pl player;
struct Rect wall={0,w,h,0};
//timer function
void Timer(int value)
{
    c1.Yc-=c1Speed;
    c2.Yc-=c2Speed;
    c3.Yc-=c3Speed;
    c4.Yc-=c4Speed;
    c5.Yc-=c5Speed;

    glutPostRedisplay();
    glutTimerFunc(16,Timer,0);
    ttime+=0.016;
}
//check Collision between coin and player
 int coin_player(struct Cir c)
 {
     float d1=(c.Xc-player.head.Xc);
     float d2=(c.Yc-player.head.Yc);
     float d=sqrt(d1*d1+d2*d2);
     if(d<=c.radius+player.head.radius)
        return 1;
     return 0;
 }
//Check collision between Coins and balls
int coin_wall(struct Cir c)
{
    if(c.Yc<=wall.bottom)
        return 1;
    return 0;
}
//Fuction to Draw Text
void drawText(char *string,int x,int y)
{
    char *c;
    c=string;
    glPushMatrix();
    glTranslatef(x,y,0);
    glScalef(.1,.2,.1);
    for(int i=0;c[i]!='\0';i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN,c[i]);
    }
    glPopMatrix();
}
//function to draw FilledCircle
void filledcircle(GLfloat x,GLfloat y,GLfloat r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    int seg=1000;
    for(int i=0;i<=seg;i++)
    {
        double angle=i*2*3.14/seg;
        glVertex2f(x+r*cos(angle),y+r*sin(angle));
    }
    glEnd();
}
//Function to Draw Circle
void Circle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
//function to draw Line
void line(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
    glBegin(GL_LINES);
    glVertex3f(x1,y1,0.0);
    glVertex3f(x2,y2,0.0);
    glEnd();
}
//function to draw rectangle
void rectang(GLfloat x1,GLfloat x2,GLfloat y1,GLfloat y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);
    glEnd();
}
//display startMenu
void startMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(w,0);
    glVertex2f(w,h);
    glVertex2f(0,h);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    int wx=w/4;
    int hy=h/4;
    line(wx,3*hy,3*wx,3*hy);
    line(wx,hy,3*wx,hy);
    line(wx,3*hy,wx,hy);
    line(3*wx,hy,3*wx,3*hy);
    glPopMatrix();
    char str[100];
    glColor3f(1,0,0);
    sprintf(str,"press S/s for Start E/Q for Quit");
    drawText(str,1.6*wx,2.7*hy);
    glColor3f(1,1,1);
    sprintf(str," START GAME");
    drawText(str,1.8*wx,2.2*hy);
    sprintf(str," QUIT GAME");
    drawText(str,1.8*wx,1.9*hy);
    glutSwapBuffers();

}
// display pauseMenu
void pauseMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(w,0);
    glVertex2f(w,h);
    glVertex2f(0,h);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    int wx=w/4;
    int hy=h/4;
    line(wx,3*hy,3*wx,3*hy);
    line(wx,hy,3*wx,hy);
    line(wx,3*hy,wx,hy);
    line(3*wx,hy,3*wx,3*hy);
    glPopMatrix();
    char str[100];
    glColor3f(1,0,0);
    //sprintf(str,"press /s for Start E/e for Quit");
    //drawText(str,635,500);
    glColor3f(1,1,1);
    sprintf(str,"1. RESUME");
    drawText(str,1.8*wx,2.2*hy);
    sprintf(str,"2. NEW GAME");
    drawText(str,1.8*wx,1.9*hy);
    sprintf(str,"3. QUIT GAME");
    drawText(str,1.8*wx,1.6*hy);
    glutSwapBuffers();

}
//display gameoverMenu
void gameoverMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(w,0);
    glVertex2f(w,h);
    glVertex2f(0,h);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    int wx=w/4;
    int hy=h/4;
    line(wx,3*hy,3*wx,3*hy);
    line(wx,hy,3*wx,hy);
    line(wx,3*hy,wx,hy);
    line(3*wx,hy,3*wx,3*hy);
    glPopMatrix();
    char str[100];
    glColor3f(1,0,0);
    sprintf(str,"--------GAME OVER--------");
    drawText(str,1.6*wx,2.7*hy);
    glColor3f(1,1,1);
    sprintf(str," SCORE : %d",score);
    drawText(str,1.8*wx,2.2*hy);
    sprintf(str,"2. NEW GAME");
    drawText(str,1.8*wx,1.9*hy);
    sprintf(str,"3. QUIT GAME");
    drawText(str,1.8*wx,1.6*hy);
    glutSwapBuffers();
}

