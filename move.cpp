#include "drawing.cpp"
void backGround()
{
    glClearColor(0,0,0,0);
}
//Called when the window is resized
void reshape(int width, int height)
{
    w=(GLfloat)width;
    h=(GLfloat)height;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void drawScene()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawcoin1();
    drawcoin2();
    drawcoin3();
    drawcoin4();
    drawcoin5();
    //draw();
    glutSwapBuffers();
}
//check collision of coins from wall or player
void check_player_c1()
{
    if(coin_wall(c1))
    {

        c1.Yc=750;
        i=c1.radius+rand()%(int)(int)(w-2*c1.radius);
        c1.Xc=i;
        drawcoin2();
    }
    if(coin_player(c1))
    {
        c1.Yc=750;
        i=c1.radius+rand()%(int)(w-2*c1.radius);
        c1.Xc=i;
       drawcoin1();
        score++;
    }
}
void check_player_c2()
{
    if(coin_wall(c2))
    {

        c2.Yc=750;
        j=c2.radius+rand()%(int)(w-2*c2.radius);
        c2.Xc=j;
        drawcoin1();
    }
    if(coin_player(c2))
    {
        c2.Yc=750;
       j=c2.radius+rand()%(int)(w-2*c2.radius);
       c2.Xc=j;
        drawcoin2();
        score++;
    }
}
void check_player_c3()
{
    if(coin_wall(c3))
    {

        c3.Yc=750;
        k=c3.radius+rand()%(int)(w-2*c3.radius);
        c3.Xc=k;
        drawcoin4();
    }
    if(coin_player(c3))
    {
        c3.Yc=750;
        k=c3.radius+rand()%(int)(w-2*c3.radius);
        c3.Xc=k;
        drawcoin3();
        score++;
    }
}
void check_player_c4()
{
    if(coin_wall(c4))
    {

        c4.Yc=750;
        l=c4.radius+rand()%(int)(w-2*c4.radius);
        c4.Xc=l;
        drawcoin3();
    }
    if(coin_player(c4))
    {
        c4.Yc=750;
        l=c4.radius+rand()%(int)(w-2*c4.radius);
        c4.Xc=l;
       drawcoin4();
        score++;
    }
}
void check_player_c5()
{
    if(coin_wall(c5))
    {

        c5.Yc=750;
        m=c5.radius+rand()%(int)(w-2*c5.radius);
        c5.Xc=m;
        drawcoin5();
    }
    if(coin_player(c5))
    {
        c5.Yc=750;
        m=c5.radius+rand()%(int)(w-2*c5.radius);
        c5.Xc=m;
        drawcoin5();
        score++;
    }
}
//call all collision function to detect the collision
void checkCollision()
{
    check_player_c1();
    check_player_c2();
    check_player_c3();
    check_player_c4();
    check_player_c5();
}
// main display function
void display(void)
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clear the buffer
    glLoadIdentity();
    if(game_state==menu)
    {
        score=0;
        ttime=0;
        startMenu();
    }
    if(game_state==play)
    {
        t=ttime;
        glPushMatrix();
        glLoadIdentity();
        glColor3f(1,1,0);
        sprintf(str,"PLAYER SCORE: %d",score);
        drawText(str,0.03*w,0.94*h);
        sprintf(str,"Timer : %d",(int )ttime);
        drawText(str,0.03*w,0.88*h);
        sprintf(str,"p : pause");
        drawText(str,0.03*w,0.84*h);
        sprintf(str,"E/Q : exit");
        drawText(str,0.03*w,0.80*h);
        glPopMatrix();
        drawman();
        drawScene();
        checkCollision();
    }
    if((int)ttime==gameTime)
    {
        ttime=0;    //reset the timepassed
        game_state=over;
    }
    if(game_state==pause)
    {
        ttime=t;         //pause the timer
        pauseMenu();
    }
    if(game_state==over)
    {
        gameoverMenu();
    }
    if(game_state==gameexit)
    {
        exit(0);
    }
    glFlush();
}
