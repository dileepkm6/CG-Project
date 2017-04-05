#include "declaration.cpp"
// drawing player
void drawman()
{
    glColor3f(1,0,0);              //set the color of Head
    float xc=player.head.Xc;       //set the center of head
    float yc=player.head.Yc;
    float r=player.head.radius;    // set the radius of head
    filledcircle(xc,yc,r);          //drawing head
    //set coordinate of player body
    player.body.left=xc-r;
    player.body.right=xc+r;
    player.body.top=yc-r;
    player.body.bottom=yc-3*r;
    glColor3f(0,0.3,0.1);           // set color of player body part
    rectang(player.body.left,player.body.right,player.body.top,player.body.bottom);
    // set leg part of body
    player.leg.left=xc-r/2;
    player.leg.right=xc+r/2;
    player.leg.top=yc-3*r;
    player.leg.bottom=yc-4*r;
    glColor3f(0,1,1);               // set leg color
    rectang(player.leg.left,player.leg.right,player.leg.top,player.leg.bottom);
}
// drawing different coins

void drawcoin1()
{
    glColor3f(1,0,0);
    filledcircle(c1.Xc,c1.Yc,c1.radius);
    glEnd();
}
void drawcoin2()
{
    glColor3f(0,1,0);
    filledcircle(c2.Xc,c2.Yc,c2.radius);

    glEnd();
}
void drawcoin3()
{
    glColor3f(0,0,1);
    filledcircle(c3.Xc,c3.Yc,c3.radius);

    glEnd();
}
void drawcoin4()
{

    glColor3f(1,1,0);
    filledcircle(c4.Xc,c4.Yc,c4.radius);
    glEnd();
}
void drawcoin5()
{
    glColor3f(0,1,1);
    filledcircle(c5.Xc,c5.Yc,c5.radius);

    glEnd();
}

