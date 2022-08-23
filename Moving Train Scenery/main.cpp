#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.141516
#include<math.h>
#include<time.h>


float angle = 0.0, x=-4;
bool night = false;


float xpos,ypos,prex,prey,nex,ney,radius=0.04f;//cloud
GLfloat poisitionCloud1=0.0f,poisitionCloud2=0.0f,poisitionCloud3=0.0f,poisitionCloud4=0.0f,positionplane=0.0f;
GLfloat speedcloud1=-0.002f,speedcloud2=-0.002f,speedcloud3=-0.002f,speedcloud4=-0.002f,speedplane=-0.02f;

GLfloat position3 = -1.3f; //birds
GLfloat speed3 = 0.01f;

int steps=200;
float angle1=3.1415426*2.f/steps;

//Sun
void drawCircle(GLfloat xpos, GLfloat ypos, GLfloat radius)
{

glBegin(GL_TRIANGLE_FAN);
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
    if(night){
    glColor3ub(192, 192, 192);
    }
    else
        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);


   glVertex2d(
    xpos+ (radius * cos(i * angle1)),
     ypos + (radius * sin(i * angle1))
    );
}
glEnd();
}




void Cloud1(){
    glPushMatrix();
    glTranslatef(poisitionCloud2,0.0f, 0.0f);

   drawCircle(-0.65f,0.85f,0.09f);
   drawCircle(-0.55f,0.85f,0.08f);
   drawCircle(-0.60f,0.88f,0.06f);
   glPopMatrix();
}




void Cloud2(){

  glPushMatrix();
  glTranslatef(poisitionCloud1,0.0f, 0.0f);

   drawCircle(-0.85f,0.85f,0.08f);
   drawCircle(-0.80f,0.86f,0.09f);
   drawCircle(-0.90f,0.88f,0.08f);
   glPopMatrix();
}



void Cloud3(){
    glPushMatrix();
    glTranslatef(poisitionCloud3,0.0f, 0.0f);

   drawCircle(-0.15f,0.85f,0.06f);
   drawCircle(-0.05f,0.85f,0.05f);
   drawCircle(-0.10f,0.88f,0.07f);
   glPopMatrix();
}



void Cloud4(){
   glPushMatrix();
   glTranslatef(poisitionCloud4,0.0f, 0.0f);

   drawCircle(0.35f,0.85f,0.06f);
   drawCircle(0.40f,0.86f,0.05f);
   drawCircle(0.30f,0.88f,0.07f);
   drawCircle(0.37f,0.83f,0.06f);

  glPopMatrix();

}

///Sun
void Sun(GLfloat xpos, GLfloat ypos, GLfloat radius)
{

glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
    if(night){
         glEnable(GL_LIGHTING);
         GLfloat global_ambient4[] = {4.0,4.0,4.0, 0.1};
         glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient4);
         glColor3f(1.0f, 1.0f, 1.0f);
         glDisable(GL_LIGHTING);
    }
    else{
         glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    }



glVertex2d(
 xpos+ (radius * cos(i * angle)),
ypos + (radius * sin(i * angle))
);
}
glEnd();
}



  void update(int value) {



    if(poisitionCloud1 <-1.2f)
        poisitionCloud1 = 1.3f;

    poisitionCloud1 += speedcloud1;



	if(poisitionCloud2 <-1.2f)
        poisitionCloud2 = 1.3f;

    poisitionCloud2 += speedcloud2;

    if(poisitionCloud3 <-1.2f)
        poisitionCloud3 = 1.3f;

    poisitionCloud3 += speedcloud3;

    if(poisitionCloud4 <-1.2f)
        poisitionCloud4 = 1.3f;

    poisitionCloud4 += speedcloud4;


      if(position3 <-2.0)
        position3 = 1.8f;

     position3 -= speed3;

     if(positionplane < -4.0f){
    positionplane = 1.9f;
    }
    positionplane += speedplane;


	glutPostRedisplay();

	glutTimerFunc(100, update, 0);
}

void handleKeypress(unsigned char key, int x, int y) {


switch (key)
 {

   case 'n':
    night = true;
    break;

   case 'd':
    night = false;
    break;

   default:
   break;
  }
}


void Star(){
    if(night){
      ///star..1

      glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.86f, 0.86f);
      glVertex2f( -0.86f, 0.85f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.83f,  0.86f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.86f, 0.86f);
      glVertex2f( -0.855f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.85f, 0.86f);
      glVertex2f( -0.88f,  0.858f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.85f, 0.85f);
      glVertex2f( -0.86f, 0.85f);
      glVertex2f( -0.855f,  0.83f);
      glEnd();


///star2

      glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.66f, 0.86f);
      glVertex2f( -0.66f, 0.85f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.63f,  0.86f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.66f, 0.86f);
      glVertex2f( -0.655f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.65f, 0.86f);
      glVertex2f( -0.68f,  0.858f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.65f, 0.85f);
      glVertex2f( -0.66f, 0.85f);
      glVertex2f( -0.655f,  0.83f);
      glEnd();

   ///star 3..........

      glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.66f, 0.86f);
      glVertex2f( 0.66f, 0.85f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.63f,  0.86f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.66f, 0.86f);
      glVertex2f( 0.655f,  0.88f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.65f, 0.86f);
      glVertex2f( 0.68f,  0.858f);
      glEnd();

      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( 0.65f, 0.85f);
      glVertex2f( 0.66f, 0.85f);
      glVertex2f( 0.655f,  0.83f);
      glEnd();

      ///star 3

      glBegin(GL_QUADS);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.45f, 0.75f);
      glVertex2f( -0.45f, 0.76f);
      glVertex2f( -0.46f, 0.76f);
      glVertex2f( -0.46f, 0.75f);
      glEnd();



      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.45f, 0.75f);
      glVertex2f( -0.45f, 0.76f);
      glVertex2f( -0.43f, 0.76f);
      glEnd();



      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.45f, 0.76f);
      glVertex2f( -0.46f, 0.76f);
      glVertex2f( -0.455f, 0.78f);
      glEnd();



      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.45f, 0.75f);
      glVertex2f( -0.45f, 0.76f);
      glVertex2f( -0.48f, 0.758f);
      glEnd();



      glBegin(GL_TRIANGLES);
      glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
      glVertex2f( -0.45f, 0.75f);
      glVertex2f( -0.46f, 0.75f);
      glVertex2f( -0.455f, 0.73f);
      glEnd();

///star 4

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.55f, 0.65f);
    glVertex2f( -0.55f, 0.66f);
    glVertex2f( -0.56f, 0.66f);
    glVertex2f( -0.56f, 0.65f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.55f, 0.65f);
    glVertex2f( -0.55f, 0.66f);
    glVertex2f( -0.53f, 0.66f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.55f, 0.66f);
    glVertex2f( -0.56f, 0.66f);
    glVertex2f( -0.555f, 0.68f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.55f, 0.65f);
    glVertex2f( -0.55f, 0.66f);
    glVertex2f( -0.58f, 0.658f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.55f, 0.65f);
    glVertex2f( -0.56f, 0.65f);
    glVertex2f( -0.555f, 0.63f);
    glEnd();


///star 5

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.25f, 0.95f);
    glVertex2f( -0.25f, 0.96f);
    glVertex2f( -0.26f, 0.96f);
    glVertex2f( -0.26f, 0.95f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.25f, 0.95f);
    glVertex2f( -0.25f, 0.96f);
    glVertex2f( -0.23f, 0.96f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.25f, 0.96f);
    glVertex2f( -0.26f, 0.96f);
    glVertex2f( -0.255f, 0.98f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.25f, 0.95f);
    glVertex2f( -0.25f, 0.96f);
    glVertex2f( -0.28f, 0.958f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.25f, 0.95f);
    glVertex2f( -0.26f, 0.95f);
    glVertex2f( -0.255f, 0.93f);
    glEnd();


///star 6

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.35f, 0.55f);
    glVertex2f( -0.35f, 0.56f);
    glVertex2f( -0.36f, 0.56f);
    glVertex2f( -0.36f, 0.55f);
    glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( -0.35f, 0.55f);
   glVertex2f( -0.35f, 0.56f);
   glVertex2f( -0.33f, 0.56f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( -0.35f, 0.56f);
   glVertex2f( -0.36f, 0.56f);
   glVertex2f( -0.355f, 0.58f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( -0.35f, 0.55f);
   glVertex2f( -0.35f, 0.56f);
   glVertex2f( -0.38f, 0.558f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( -0.35f, 0.55f);
   glVertex2f( -0.36f, 0.55f);
   glVertex2f( -0.355f, 0.53f);
   glEnd();



///star 7

   glBegin(GL_QUADS);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( -0.05f, 0.85f);
   glVertex2f( -0.05f, 0.86f);
   glVertex2f( -0.06f, 0.86f);
   glVertex2f( -0.06f, 0.85f);
   glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.05f, 0.85f);
    glVertex2f( -0.05f, 0.86f);
    glVertex2f( -0.03f, 0.86f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.05f, 0.86f);
    glVertex2f( -0.06f, 0.86f);
    glVertex2f( -0.055f, 0.88f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.05f, 0.85f);
    glVertex2f( -0.05f, 0.86f);
    glVertex2f( -0.08f, 0.858f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( -0.05f, 0.85f);
    glVertex2f( -0.06f, 0.85f);
    glVertex2f( -0.055f, 0.83f);
    glEnd();





    ///star 8

   glBegin(GL_QUADS);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.65f, 0.85f);
   glVertex2f( 0.65f, 0.86f);
   glVertex2f( 0.66f, 0.86f);
   glVertex2f( 0.66f, 0.85f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.65f, 0.85f);
   glVertex2f( 0.65f, 0.86f);
   glVertex2f( 0.63f, 0.86f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.65f, 0.86f);
   glVertex2f( 0.66f, 0.86f);
   glVertex2f( 0.655f, 0.88f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.65f, 0.85f);
   glVertex2f( 0.65f, 0.86f);
   glVertex2f( 0.68f, 0.858f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.65f, 0.85f);
   glVertex2f( 0.66f, 0.85f);
   glVertex2f( 0.655f, 0.83f);
   glEnd();



///star 9
   glBegin(GL_QUADS);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.45f, 0.75f);
   glVertex2f( 0.45f, 0.76f);
   glVertex2f( 0.46f, 0.76f);
   glVertex2f( 0.46f, 0.75f);
   glEnd();



   glBegin(GL_TRIANGLES);
   glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
   glVertex2f( 0.45f, 0.75f);
   glVertex2f( 0.45f, 0.76f);
   glVertex2f( 0.43f, 0.76f);
   glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.45f, 0.76f);
    glVertex2f( 0.46f, 0.76f);
    glVertex2f( 0.455f, 0.78f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.45f, 0.75f);
    glVertex2f( 0.45f, 0.76f);
    glVertex2f( 0.48f, 0.758f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.45f, 0.75f);
    glVertex2f( 0.46f, 0.75f);
    glVertex2f( 0.455f, 0.73f);
    glEnd();

///star 10

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.55f, 0.65f);
    glVertex2f( 0.55f, 0.66f);
    glVertex2f( 0.56f, 0.66f);
    glVertex2f( 0.56f, 0.65f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.55f, 0.65f);
    glVertex2f( 0.55f, 0.66f);
    glVertex2f( 0.53f, 0.66f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.55f, 0.66f);
    glVertex2f( 0.56f, 0.66f);
    glVertex2f( 0.555f, 0.68f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.55f, 0.65f);
    glVertex2f( 0.55f, 0.66f);
    glVertex2f( 0.58f, 0.658f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f( 0.55f, 0.65f);
    glVertex2f( 0.56f, 0.65f);
    glVertex2f( 0.555f, 0.63f);
    glEnd();


///star 11

glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.26f, 0.96f);
glVertex2f( 0.26f, 0.95f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.23f, 0.96f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.26f, 0.96f);
glVertex2f( 0.255f, 0.98f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.25f, 0.96f);
glVertex2f( 0.28f, 0.958f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.25f, 0.95f);
glVertex2f( 0.26f, 0.95f);
glVertex2f( 0.255f, 0.93f);
glEnd();


///star 12

glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.36f, 0.56f);
glVertex2f( 0.36f, 0.55f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.33f, 0.56f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.36f, 0.56f);
glVertex2f( 0.355f, 0.58f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.35f, 0.56f);
glVertex2f( 0.38f, 0.558f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.35f, 0.55f);
glVertex2f( 0.36f, 0.55f);
glVertex2f( 0.355f, 0.53f);
glEnd();


///star 13

glBegin(GL_QUADS);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.16f, 0.76f);
glVertex2f( 0.16f, 0.75f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.13f, 0.76f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.16f, 0.76f);
glVertex2f( 0.155f, 0.78f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.15f, 0.76f);
glVertex2f( 0.18f, 0.758f);
glEnd();



glBegin(GL_TRIANGLES);
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
glVertex2f( 0.15f, 0.75f);
glVertex2f( 0.16f, 0.75f);
glVertex2f( 0.155f, 0.73f);
glEnd();

}
}

void birds(){

    glPushMatrix();//birds
    if (night==false){

 glTranslatef(-position3 ,0.0f, 0.0f);

    glLineWidth(0.5);
int i1;

GLfloat mm=0.182f;
GLfloat nn=.804f;
GLfloat radiusmm =.009f;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(55, 55, 55);
glVertex2f(mm, nn); // center of circle
for(i1 = 0; i1 <= triangleAmount;i1++) {
glVertex2f(
mm + (radiusmm * cos(i1 * twicePi / triangleAmount)),
nn + (radiusmm * sin(i1 * twicePi / triangleAmount))
);
}
glEnd();
glBegin(GL_POLYGON);
glColor3ub(225, 200, 0 );
glVertex2f(0.1f,0.8f);
glVertex2f(0.11f,0.79f);
glVertex2f(0.12f,0.78f);
glVertex2f(0.16f,0.77f);
glVertex2f(0.19f,0.79f);
glVertex2f(0.201f,0.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(217, 200, 0);
glVertex2f(0.175f,0.8f);
glVertex2f(0.15f,0.8f);
glVertex2f(0.14f,0.84f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(235, 235, 0 );
glVertex2f(0.175f,0.8f);
glVertex2f(0.144f,0.8f);
glVertex2f(0.12f,0.83f);
glEnd();

/////2nd bird////

 GLfloat mmm=0.063f;
 GLfloat nnn=.804f;
 GLfloat radiusmmm =0.009f;
 int i4;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(55, 55,55);
glVertex2f(mmm, nnn); // center of circle
for( i4 = 0; i4 <= triangleAmount;i4++) {
glVertex2f(
mmm + (radiusmmm * cos(i4 * twicePi / triangleAmount)),
nnn + (radiusmmm * sin(i4 * twicePi / triangleAmount))
);
}
glEnd();


glBegin(GL_POLYGON);
glColor3ub(225, 200, 0 );
glVertex2f(-0.02f,0.8f);
glVertex2f(-0.01f,0.79f);
glVertex2f(0.0f,0.78f);
glVertex2f(0.04f,0.77f);
glVertex2f(0.07f,0.79f);
glVertex2f(0.081f,0.8f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 200,0);
glVertex2f(0.055f,0.8f);
glVertex2f(0.03f,0.8f);
glVertex2f(0.02f,0.84f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(235, 235, 0 );
glVertex2f(0.055f,0.8f);
glVertex2f(0.024f,0.8f);
glVertex2f(0.0f,0.83f);
glEnd();


/////3rd bird/////


GLfloat mmmm=-0.636f;
GLfloat nnnn=.804f;
GLfloat radiusmmmm =.009f;
int i3;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(55, 55, 55);
glVertex2f(mmmm,nnnn); // center of circle
for(i3 = 0; i3 <= triangleAmount;i3++) {
glVertex2f(
mmmm + (radiusmmmm * cos(i3 * twicePi / triangleAmount)),
nnnn + (radiusmmmm * sin(i3* twicePi / triangleAmount))
);
}
glEnd();


glBegin(GL_POLYGON);
glColor3ub(225, 200, 0 );
glVertex2f(-0.72f,0.8f);
glVertex2f(-0.71f,0.79f);
glVertex2f(-0.7f,0.78f);
glVertex2f(-0.66f,0.77f);
glVertex2f(-0.63f,0.79f);
glVertex2f(-0.619f,0.8f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 200, 0);
glVertex2f(-0.645f,0.8f);
glVertex2f(-0.67f,0.8f);
glVertex2f(-0.68f,0.84f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(235, 235,0 );
glVertex2f(-0.645f,0.8f);
glVertex2f(-0.676f,0.8f);
glVertex2f(-0.7f,0.83f);
glEnd();



////4th bird////
GLfloat mmmmm=-0.516f;
GLfloat nnnnn=.804f;
GLfloat radiusmmmmm =.009f;
int i5;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(55, 55,55);
glVertex2f(mmmmm, nnnnn); // center of circle
for(i5 = 0; i5 <= triangleAmount;i5++) {
glVertex2f(
mmmmm + (radiusmm * cos(i5 * twicePi / triangleAmount)),
nnnnn + (radiusmm * sin(i5 * twicePi / triangleAmount))
);
}
glEnd();


glBegin(GL_POLYGON);
glColor3ub(225, 200,0 );
glVertex2f(-0.6f,0.8f);
glVertex2f(-0.59f,0.79f);
glVertex2f(-0.58f,0.78f);
glVertex2f(-0.54f,0.77f);
glVertex2f(-0.51f,0.79f);
glVertex2f(-0.499f,0.8f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 200, 0);
glVertex2f(-0.525f,0.8f);
glVertex2f(-0.55f,0.8f);
glVertex2f(-0.56f,0.84f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(235, 235,0 );
glVertex2f(-0.525f,0.8f);
glVertex2f(-0.556f,0.8f);
glVertex2f(-0.58f,0.83f);
glEnd();

    glPopMatrix();
    }
}


void plane(){
    xpos=0.4f;
    ypos=0.85f;
    radius=0.04f;
glBegin(GL_TRIANGLE_FAN);

glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2d(xpos, ypos); // center of circle
for(int i = 0; i <= steps; i++)
{
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2d(
 xpos+ (radius * cos(i * angle)),
ypos + (radius * sin(i * angle))
);

}
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.4f,0.89f);
glVertex2f( 0.4f,0.81f);
glVertex2f( 0.53f,0.81f);
glVertex2f( 0.59f,0.89f);
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.53f,0.89f);
glVertex2f( 0.59f,0.89f);
glVertex2f( 0.64f,0.93f);
glVertex2f( 0.60f,0.93f);
glEnd();

glBegin(GL_QUADS);///...................
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
glVertex2f( 0.60f,0.93f);
glVertex2f( 0.64f,0.93f);
glVertex2f( 0.65f,0.95f);
glVertex2f( 0.61f,0.95f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f( 0.43f,0.81f);
glVertex2f( 0.46f,0.81f);
glVertex2f( 0.46f,0.83f);
glVertex2f( 0.43f,0.83f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f( 0.43f,0.82f);
glVertex2f( 0.47f,0.80f);
glVertex2f( 0.50f,0.83f);
glVertex2f( 0.49f,0.85f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.42f,0.84f);
glVertex2f( 0.44f,0.84f);
glVertex2f( 0.44f,0.86f);
glVertex2f( 0.42f,0.86f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.46f,0.84f);
glVertex2f( 0.48f,0.84f);
glVertex2f( 0.48f,0.86f);
glVertex2f( 0.46f,0.86f);
glEnd();

glBegin(GL_QUADS);///...................
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f( 0.50f,0.84f);
glVertex2f( 0.52f,0.84f);
glVertex2f( 0.52f,0.86f);
glVertex2f( 0.50f,0.86f);
glEnd();
}


void home()
{

   glPushMatrix(); //main building
   glColor3f(0.91, 0.76,0.65);
   glTranslated(0,0.4,0);
   glScaled(2,0.8,1);
   glutSolidCube(1);
   glColor3f(0.91, 0.76,0.65);
   glutWireCube(1);
   glPopMatrix();


   glPushMatrix(); //door
   if(night){
    glColor3f(1,1,0);
   }
   else{
    glColor3f(1,1,1);
   }


   glTranslated(0,0.2,0);
   glScaled(0.3,0.4,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //main building roof
   glColor3f(0,0,0);
   glTranslated(0,0.8,0);
   glScaled(2,0.02,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //room on floor
   glColor3f(0.91, 0.76,0.65);
   glTranslated(0,1.1,0);
   glScaled(1.4,0.6,1);
   glutSolidCube(1);
   glColor3f(0.65, 0.49,0.24);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //top room roof
   glColor3f(0,0,0);
   glTranslated(0,1.4,0);
   glScaled(2,0.02,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //top room window
   if(night){
    glColor3f(1,1,0);
   }
   else{
    glColor3f(1,1,1);
   }

   glTranslated(0,1.1,0);
   glScaled(0.4,0.3,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();
}


void train()
{
   glPushMatrix(); //Right Wheel Far
   glColor3f(0,0,0);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(angle,0,0,1);
   glutWireTorus (0,0,0,0);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
   glColor3f(0,0,0);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(angle,0,0,1);
   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Train BOX
   glColor3f(0,0.5,0.85);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix(); //Right Wheel Far
   glColor3f(0,0,0);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(angle,0,0,1);
   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
   glColor3f(0,0,0);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(angle,0,0,1);
   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   angle-=0.2;
}

void tree()
{
   glPushMatrix();
   	glColor3b(102,100,70);
   	glScaled(0.2,6,0.2);
  	glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
     	glColor3b(48,124,66);
     	glTranslated(0,2,0);
    	glutSolidSphere(1,8,8);
    	glColor3f(0,1,0);
    	glutWireSphere(1,8,8);
    	glPopMatrix();
}
void background()
{
    if(night){
       glEnable(GL_LIGHTING);
       GLfloat global_ambient2[] = {1.29,1.29,1.29, 0.1};
       glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
       glColor3f(0.0,0.1,0.0);
       glRecti(-3,-2,3,0); //green grass
       glDisable(GL_LIGHTING);

    }
    else
        glColor3f(0.25,0.58,0.38);;
        glRecti(-3,-2,3,0); //green grass

    if(night){
       glEnable(GL_LIGHTING);// Lighting Effect
       GLfloat global_ambient[] = {0.41,1.31,1.88, 0.1};
       glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
       glColor3f(0.627,0.125,0.941);
       glRecti(-3,0,3,2); //sky
       glDisable(GL_LIGHTING);

    }
    else{
        glColor3f(0.13,0.68,0.85);
  	    glRecti(-3,0,3,2); //sky
    }



   glPushMatrix();
   glTranslated (0.95f,0.85f,0.0f);
   Star();
   glPopMatrix();
   glPushMatrix();
   glTranslated (-0.95f,0.85f,0.0f);
   Star();
   glPopMatrix();


 //small trees
   glPushMatrix();
   glTranslated(1.7,0.6,0);
   glScaled(0.3,0.3,0.1);
   tree();
   glPopMatrix();
  	glPushMatrix();
   glTranslated(1.5,0.8,0);
   glScaled(0.3,0.3,0.1);
   tree();
   glPopMatrix();

   //big trees
   glPushMatrix();
     	glTranslated(-1.6,0.4,0);
     	glScaled(0.23,0.23,0.1);
     	tree();
    	glPopMatrix();
 	glPushMatrix();
     	glTranslated(-1.4,0.6,0);
     	glScaled(0.23,0.23,0.1);
     	tree();
    	glPopMatrix();

   home();

}



void renderScene (void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();



   glOrtho (-3,3,-2,2,-4,4);
   background ();
   glRotatef(10,1.0,1.0,0.0);



   ///Sun  ................

   glPushMatrix();
    glTranslated (0.95f,0.85f,0.0f);
   Sun(0.91f,0.85f,0.15f);
   glPopMatrix();




/// Cloud............................Start
   glPushMatrix();
   glTranslated (-0.65f,0.85f,0.0f);
   Cloud1();
   glPopMatrix();

   glPushMatrix();
   glTranslated (-0.85f,0.85f,0.0f);
   Cloud2();
   glPopMatrix();

   glPushMatrix();
   glTranslated (-0.15f,0.85f,0.0f);
   Cloud3();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(positionplane,0.0f, 0.0f);
    glTranslated (0.95f,0.9f,0.0f);
    plane();
   glPopMatrix();


   ///birds...............
       glPushMatrix();
       glTranslated (-1.35f,0.85f,0.0f);
       birds();
       glPopMatrix();


   glPushMatrix();
   glTranslated (0.35f,0.85f,0.0f);
   Cloud4();
   glPopMatrix();




   glPushMatrix ();

   glColor3f(0,0,0); //Rail
   glTranslated (0,-0.4,0);
   glScaled (9,0.1,0.1);
   glutWireCube(1);
   glPopMatrix();




   glTranslatef(x,0,0); // to move train
   glScaled(0.5,0.5,0.5);

   glPushMatrix();
   glTranslated (-2.4,0,0);
   train();
   glPopMatrix();

   glPushMatrix();
   glTranslated (0,0,0);
   train();
   glPopMatrix();

   glPushMatrix();
   glTranslated (2.4,0,0);
   train();
   glPopMatrix();
   if (x<6)
  	x+=0.002; //control train speed from here
   else
  	x=-6;

    glutSwapBuffers();
    glFlush();
   }

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(1000, 750);
   glutInitWindowPosition(50, 32);
   glutCreateWindow("...Project...");
   glutDisplayFunc(renderScene);
   glutIdleFunc (renderScene);
   glClearColor(1,1,1,1);

   glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
