#include "move.cpp"
 void mainDisplay()
 {
     backGround();
     display();
 }
 //move player using keyboard
void key(int key,int x,int y)
{
 if(key==GLUT_KEY_RIGHT && player.head.Xc<(w-headRadius))
 {
        player.head.Xc += 0.26*Xspeed;
 }

    if(key==GLUT_KEY_LEFT && player.head.Xc>(headRadius))
    {
        player.head.Xc  -= 0.26*Xspeed;
    }
    glutPostRedisplay();
}
//Changing of gamestate using keyboard
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'S':
        case 's': if(game_state==menu){game_state=play;}
        break;
        case 'q':
        case 'Q':
        case 'E':
        case 'e': if(game_state==menu || game_state==play){game_state=gameexit;}
        break;
        case 'P':
        case 'p':if(game_state==play){game_state=pause;}
        break;
        case '1': if(game_state==pause){game_state=play;}
        break;
        case '2': if(game_state==pause || game_state==over){game_state=menu;}
        break;
        case '3': if(game_state==pause || game_state==over){game_state=gameexit;}
        break;
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1350,720);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("COIN COLLECTING GAME");
    glutDisplayFunc(mainDisplay);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16,Timer,0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
