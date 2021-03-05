#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>// for lexical_cast()
#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
//#  include <GL/glext.h> //deprecated
#pragma comment(lib, "glew32.lib")
#endif

#define PI 3.14159265
//#define N 5.0 // Number of vertices on the boundary of the disc.
static float N =100.0;
using namespace std;
string Read();
static float R = 40.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 30; // Number of vertices on circle.
static int numvertices =5;
string n,n1,n2,n3,n4,n5;

// Globals.
static int isWire = 0; // Is wireframe?
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{
   char *c;

   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Function to draw a disc with center at (X, Y, Z), radius R, parallel to the xy-plane.
void drawDisc(float R, float X, float Y, float Z)
{
   float t;
   int i;

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f( X, Y, Z);
      for(i = 0; i <= N; ++i)
	  {
         t = 2 * PI * i / N;
         glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
	  }
   glEnd();
}

// Drawing routine.
void drawScene(void)
{
  //se declaran variables a utilizar
   float angle;
   int x=X;
   int y=Y;
   int r=R;
   int i;
   //Se hace el cast a tipo flotante.
   float t = 0; // Angle parameter.
   float f = boost::lexical_cast<float>(n);
   float f1 = boost::lexical_cast<float>(n1);
   float f2 = boost::lexical_cast<float>(n2);
   float f3 = boost::lexical_cast<float>(n3);
   glClear(GL_COLOR_BUFFER_BIT);
   //Se imprime simplemente para saber si estan asignados los valores
   cout << " porcentajes ;" <<endl;
   cout << " "<<f <<endl;
   cout << " "<<f1 <<endl;
   cout << " "<<f2 <<endl;
   cout << " "<<f3 <<endl;
   //cout << " "<<n4 <<endl;
   //float w = static_cast <float> (f) / (static_cast <float> (RAND_MAX/1));
   //cout << ""<<f <<endl;
   glColor3f(0.0, 0.0, 0.0);

   // Draw a line loop with vertices at equal angles apart on a circle
   // with center at (X, Y) and radius R, The vertices are colored randomly.

   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
   //Se dibuja un primer circulo para poder usarlo de base.
   if (isWire) glPolygonMode(GL_FRONT, GL_LINE);else glPolygonMode(GL_FRONT, GL_FILL);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= N; ++i)
	  {
         angle = 2 * PI * i / N;
	        glColor3f(0,0,0);

         glVertex3f(50 + cos(angle) * 15.0, 50 + sin(angle) * 15.0, 0.0);
         glVertex3f(50 + cos(angle) * 20.0, 50 + sin(angle) * 20.0, 0.0);
	  }
   glEnd();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= f; ++i)
	  {
         angle = 2 * PI * i / N;
	        glColor3f(1,0,0);

          glVertex3f(50 + cos(angle) * 15.0, 50 + sin(angle) * 15.0, 0.0);
          glVertex3f(50 + cos(angle) * 20.0, 50 + sin(angle) * 20.0, 0.0);
	  }
   glEnd();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= f1; ++i)
	  {
         angle = 2 * PI * i / N;
	        glColor3f(0,1,0);
          //glVertex3f(30 , 30 , 0.0);
          glVertex3f(50 + cos(angle) * -15.0, 50 + sin(angle) * 15.0, 0.0);
          glVertex3f(50 + cos(angle) * -20.0, 50 + sin(angle) * 20.0, 0.0);
	  }
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= f2; ++i)
	  {
         angle = 2 * PI * i / N;
	        glColor3f(0,0,1);

         glVertex3f(50 + cos(angle) * 15.0, 50 + sin(angle) * -15.0, 0.0);
         glVertex3f(50 + cos(angle) * 20.0, 50 + sin(angle) * -20.0, 0.0);
	  }
   glEnd();
   glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= f3; ++i)
	  {
         angle = 2 * PI * i / N;
	        glColor3f(0,1,1);

         glVertex3f(50 + cos(angle) * -15.0, 50 + sin(angle) * -15.0, 0.0);
         glVertex3f(50 + cos(angle) * -20.0, 50 + sin(angle) * -20.0, 0.0);
	  }
   glEnd();
   // Write labels.
   char array[10];
   char array1[10];
   char array2[10];
   char array3[10];
   char array4[10];
   //se copian valores
   sprintf(array, "%.02f",f1);
   sprintf(array1, "%.02f",f);
   sprintf(array2, "%.02f",f2);
   sprintf(array3, "%.02f",f3);

   //se pasan a pantalla.
   glColor3f(0.0, 0.0, 0.0);
   glRasterPos3f(40.0, 50.0, 0.0);
   writeBitmapString((void*)font, "Porcentajes ");
   glRasterPos3f(10.0, 61.0, 0.0);
   writeBitmapString((void*)font, "Verde ");
   writeBitmapString((void*)font,array);
   glRasterPos3f(65.0, 65.0, 0.0);
   writeBitmapString((void*)font, "Rojo ");
   writeBitmapString((void*)font,array1);
   glRasterPos3f(70.0, 45.0, 0.0);
   writeBitmapString((void*)font, "Azul ");
   writeBitmapString((void*)font,array2);
   glRasterPos3f(10.0, 45.0, 0.0);
   writeBitmapString((void*)font, "Celeste ");
   writeBitmapString((void*)font,array3);
   /*
   glRasterPos3f(69.0, 51.0, 0.0);//cordenadas de pantalla
   writeBitmapString((void*)font, "Floating");
   glRasterPos3f(38.0, 6.0, 0.0);
   writeBitmapString((void*)font, "The real deal!");*/
   glFlush();
}

// Initialization routine.
void setup(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   Read();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch(key)
   {
      case ' ':
         if (isWire == 0) isWire = 1;
         else isWire = 0;
         glutPostRedisplay();
         break;
      case '+':
        //N++;
        //numvertices++;
        //numVertices++;
        glutPostRedisplay();
        break;
      case '-':
      //N--;
      //numvertices--;
      //numVertices++;
      glutPostRedisplay();
      break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}
string Read()
{
  //se crea el fichero ifstream en este casos se llama ficheroentrada,
  //utilizamos la variable string frase para guardar temporalmente el valor
  //y asi poder asignarlo a nuestras variables globables.
  ifstream ficheroEntrada;
  string frase;
  //string n,n1,n2,n3,n4;
  char* ch = new char[11];
  ficheroEntrada.open ("practica01_sepulveda_lozada_angel_fernando_c001.txt");
  //ficheroEntrada.open ("practica01_sepulveda_lozada_angel_fernando_c002.txt");
  getline(ficheroEntrada, frase, '%');
  n=frase;
  getline(ficheroEntrada, frase, '%');
  n1=frase;
  getline(ficheroEntrada, frase, '%');
  n2=frase;
  getline(ficheroEntrada, frase, '%');
  n3=frase;
  getline(ficheroEntrada, frase, '%');
  n4=frase;
  ficheroEntrada.close();
  //cerramos el fichero.
/*
  cout << "Numeros: " << n << endl;
  cout << " "<<n1 <<endl;
  cout << " "<<n2 <<endl;
  cout << " "<<n3 <<endl;
  cout << " "<<n4 <<endl;*/
  //strcpy(ch, n);
  return n,n1,n2,n3,n4;
  //return 0;
  //int length, sl = 0;
  //char cadena[128];
  //wchar_t string[128];

  //ifstream fe("prueba.txt");

   // Leeremos mediante getline, si lo hiciéramos
   // mediante el operador << sólo leeríamos
   // parte de la cadena:
   //fe.getline(cadena, 128,',');
   //length = mbstowcs(string, cadena, 10);

   //wcpcpy(string,cadena);
   //cout << string << endl;

   //return 0;

}
// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
//   cout << "Interaction:" << endl;
//   cout << "Press the space bar to toggle between wirefrime and filled for the lower annulus." << endl;
}

// Main routine.
int main(int argc, char **argv)
{

   printInteraction();
   glutInit(&argc, argv);

   glutInitContextVersion(2, 1);
   //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("practica01.cpp");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);

   glewExperimental = GL_TRUE;
   glewInit();

   setup();

   glutMainLoop();
}
