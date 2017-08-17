#include<GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"all.h"
#define f4 GLUT_BITMAP_TIMES_ROMAN_24
#define f5 GLUT_BITMAP_HELVETICA_12
double color1[][3]={{0.137255,0.656863,0.137255}/*0forestgreen*/,{0.498039,1.0,0.0}/*1medspringgreen*/,{0.65,.50,.039}/*2medwood*/,
					{.52,.37,.26}/*3darkwood*/,{0.88,0.70,0.40}/*4lightwood*/,{0.396078,0.9869,0.9}/*5water*/,{.20,.20,.20}/*6gray20*/,
					{.45,.45,.45}/*7gray45*/,{0.36,0.25,0.20}/*8darkbrown*/,{1.0,1.0,1.0}/*9white*/,{0.50,0.98740,0.40}/*10lightgreen*/,
					{0.309804,0.309804,0.184314}/*11DARKOLIVEGREEN*/,{.10,.10,.10}/*12gray10*/,{0.0,0.698039,1.0}/*13skyblue*/,
					{.8,.8,.8}/*14gray80*/,{0.184314,0.309804,0.309804}/*15darkslategrey*/,{0.81,0.71,0.23}/*16oldgold*/,
					{0.55,0.09,0.09}/*17scarlet*/,{0.0,0.0,0.0}/*18black*/,{0.957, 0.643, 0.376}/*19SandyBrown(skin)*/,
					{0.863, 0.078, 0.235}/*20CRIMSONRED*/,{0.729, 0.333, 0.827}/*21medorchid*/,{0.545, 0.000, 0.545}/*22darkmagenta*/,
					{1.000, 0.647, 0.000}/*23orange*/,{1.000, 0.549, 0.000}/*24darkorange*/,{0.529, 0.808, 0.980}/*25litskyblue*/,
					{0.118, 0.565, 1.000}/*26dodgerblue*/,{ 0.220, 0.220, 0.220 }/*27gray22*/,{.6,.6,.6}/*28gray60*/,/*29gray*/{0.752941,0.752941,0.752941},
					/*30gold*/{1.000, 0.843, 0.000},/*31orange*/{1.000, 0.647, 0.000},/*32wood*/{0.52,0.37,0.26},/*33orangered*/{1.000, 0.271, 0.000},
					/*34Turquoise*/{0.251, 0.878, 0.816},/*35cadetblue*/{0.373, 0.620, 0.627},/*36darkgoldenrod*/{0.722, 0.525, 0.043},
					/*37meddeepblue*/{0.000, 0.000, 0.804},/*38darkgreen*/{0.000, 0.392, 0.000}};

int flag=0;
int b1=0,b2=0,b3=0,b4=0,b5=0;
float pos1,pos2=250,pos3,pos4,p1,fi=500.0;
float cx1=0,cy1=30;
float c1=0.0,c2=200.0,c3=300,c4=480,c5=600,c6=480,k1=0.0,k2=100.0,k3=350.0;
int i,j=0,col=1,np=0,ap=0,wp=0,sp=0,hb=0;
double ry=400;
double r1=0,r2=0,r3=0,r4=0,r5=0,sv=0.5;
int win0,win1,win2,win3,win4,accept=0;
double scv=5,r=10;

/*<<<<<<<<<---------------------AIR POLLUTION---------------------->>>>>>>>*/
void slow()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(-10,-10);
	glVertex2f(-50,-10);
	glVertex2f(-50,-50);
	glVertex2f(-10,-50);
	glEnd();
}
void drawrain()
{
	glColor3dv(color1[5]);
	glBegin(GL_POLYGON);
	glVertex2f(10,15);
	glVertex2f(6,3);
	glVertex2f(7,2);
	glVertex2f(8,1);
	glVertex2f(10,0);
	glVertex2f(12,1);
	glVertex2f(13,2);
	glVertex2f(14,3);
	glEnd();
}
void rainmotion()
{	
	for(i=0;i<=1200;i+=75)
	{
		glPushMatrix();
		glTranslated(i,ry,0);	
		drawrain();
		glPopMatrix();
	}
	ry-=25;
	
	for(int j=0;j<=5000;j++)
	{
		glPushMatrix();
		glTranslated(j,0,0);
		glPopMatrix();
	}
	if(ry<0)
	{
		ry=1400;
		col=15;
	}
}

void drawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}

void drawsmoke()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glBegin(GL_POLYGON);
	glColor3dv(color1[12]);
	glVertex2f(60,10);
	glVertex2f(70,0);
	glVertex2f(100,0);
	glVertex2f(120,20);
	glVertex2f(120,40);
	glColor3dv(color1[14]);
	glVertex2f(100,60);
	glVertex2f(70,60);
	glVertex2f(60,50);
	glVertex2f(50,60);
	glVertex2f(20,60);
	glColor3dv(color1[12]);
	glVertex2f(0,40);
	glVertex2f(0,20);
	glVertex2f(20,0);
	glVertex2f(50,0);
    glEnd();
	glPopMatrix();
}

void carsmoke()
{
	
	glPushMatrix();
	glTranslated(500+r4,75,0);
	glScaled(0.03*sv,0.03*sv,0);
	drawsmoke();
	sv+=0.005;
	r4+=0.13;
	glPopMatrix();
	if(r4>200)
	{
		r4=0;
		sv=0;
	}
}

void drawcars(int x,int y,int col,float r)
{
	glColor3f(0.9,0.1,0.0);//red
	glBegin(GL_POLYGON);
	glVertex2f(60,10);
	glVertex2f(60,20);
	glVertex2f(80,20);
	glVertex2f(90,30);
	glVertex2f(110,30);
	glVertex2f(120,20);
	glVertex2f(140,20);
	glVertex2f(140,10);
	glEnd();
	drawCircle(x,y,col,r);
	drawCircle(x+40,y,col,r);
}
void cars()
{	glPushMatrix();
	glTranslated(400,75,0);
	drawcars(80,7,6,6.5);
	glPopMatrix();
}

void carmotion()
{  	
	glPushMatrix();
	glTranslated(k1,0,0);
	cars();
	carsmoke();
	k1-=0.023;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(k2,0,0);
	cars();carsmoke();
	k2-=0.053;

	glPopMatrix();
	glPushMatrix();
	glTranslated(k3,0,0);
	cars();carsmoke();
	k3-=0.13;
	glPopMatrix();
}


void strips(float dist)
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(20.0+dist,70.0);
	glVertex2f(20.0+dist,75.0);
	glVertex2f(60.0+dist,75.0);
	glVertex2f(60.0+dist,70.0);
	glEnd();
}
void land_road(int col1,int col2)
{	float d=0.0;
	for(int i=0;i<7;i++)
	{	strips(d);
		d+=70.0;
	}
	//greenland
	glPointSize(2.0);
	glPushMatrix();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,45);
	glVertex2f(500,45);
	glVertex2f(500,0);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3dv(color1[col2]);
	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(380,100);
	//glVertex2f(410,95);
	//glVertex2f(460,92);
	glVertex2f(500,100);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
}


void factory(int col1,int col2)
{ //building
	glPointSize(2.0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3dv(color1[col1]);
	glVertex2f(158.0,100.0);
	glVertex2f(165.0,170.0);
	glVertex2f(250.0,170.0);
	glVertex2f(255.0,125.0);
	glVertex2f(265.0,150.0);
	glVertex2f(265.0,125.0);
	glVertex2f(275.0,150.0);
	glVertex2f(275.0,125.0);
	glVertex2f(285.0,150.0);
	glVertex2f(285.0,100.0);
	glEnd();
	//Chimney1
	glShadeModel(GL_SMOOTH);
	glColor3dv(color1[col2]);
	glBegin(GL_POLYGON);
	glVertex2f(178.0,150.0);
	glVertex2f(180.0,300.0);
	glVertex2f(188.0,300.0);
	glVertex2f(190.0,150.0);
	glEnd();
	//Chimney2
	glBegin(GL_POLYGON);
	glVertex2f(196.0,150.0);
	glVertex2f(198.0,280.0);
	glVertex2f(206.0,280.0);
	glVertex2f(208.0,150.0);
	glEnd();
	//Chimney3
	glBegin(GL_POLYGON);
	glVertex2f(212.0,150.0);
	glVertex2f(214.0,260.0);
	glVertex2f(222.0,260.0);
	glVertex2f(224.0,150.0);
	glEnd();
	glPopMatrix();
}
void backdrop(int col)
{
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(0,0);
		glVertex2f(1200,0);
		glColor3dv(color1[col]);//0.0,0.698039,1.0
		glVertex2f(1200,700);
		glVertex2f(0,700);
		glEnd();

}
void house(int col1,int col2,int col3=3,int col4=3,int col5=4)
{	//windows
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(320.0,100.0);
	 glVertex2f(320.0,110.0);
	 glVertex2f(330.0,110.0);
	 glVertex2f(330.0,100.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(309.0,110.0);
	 glVertex2f(309.0,115.0);
	 glVertex2f(315.0,115.0);
	 glVertex2f(315.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(335.0,110.0);
	 glVertex2f(335.0,115.0);
	 glVertex2f(342.0,115.0);
	 glVertex2f(342.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(370.0,100.0);
	 glVertex2f(370.0,110.0);
	 glVertex2f(380.0,110.0);
	 glVertex2f(380.0,100.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(359.0,110.0);
	 glVertex2f(359.0,115.0);
	 glVertex2f(365.0,115.0);
	 glVertex2f(365.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(385.0,110.0);
	 glVertex2f(385.0,115.0);
	 glVertex2f(392.0,115.0);
	 glVertex2f(392.0,110.0);
	 glEnd();

	 //left house
	 glColor3dv(color1[col2]);
	 glBegin(GL_POLYGON);
	 glVertex2f(305.0,100.0);
	 glVertex2f(305.0,130.0);
	 glColor3dv(color1[col3]);
	 glVertex2f(345.0,130.0);
	 glVertex2f(345.0,100.0);
	 glEnd();
	 glColor3dv(color1[col4]);
	 glBegin(GL_POLYGON);
	 glVertex2f(300.0,130.0);
	 glColor3dv(color1[col5]);
	 glVertex2f(325.0,157.95);
	 glVertex2f(350.0,130.0);
	 glEnd();
	//righthouse
	 glColor3dv(color1[col2]);
	 glBegin(GL_POLYGON);
	 glVertex2f(355.0,100.0);
	 glVertex2f(355.0,130.0);
	 glColor3dv(color1[col3]);
	 glVertex2f(395.0,130.0);
	 glVertex2f(395.0,97.0);
	 glEnd();
	 glColor3dv(color1[col4]);
	 glBegin(GL_POLYGON);
	 glVertex2f(350.0,130.0);
	 glVertex2f(375.0,157.95); 
	 glColor3dv(color1[col5]);
	 glVertex2f(400.0,130.0);
	 glEnd();
	
}

void tree(float dist,int col2)
{
	glColor3dv(color1[col2]);
	glBegin(GL_POLYGON);
	glVertex2f(430.0+dist,80.0);
	glVertex2f(435.0+dist,100.0);
	glVertex2f(440.0+dist,150.0);
	glVertex2f(440.0+dist,150.0);
	glVertex2f(450.0+dist,110.0);
	glVertex2f(455.0+dist,75.0);
	glEnd();

}
void blackclouds2(int col1)
{
	drawCircle(10,450,col1,58);
	drawCircle(116,450,col1,58);
	drawCircle(220,450,col1,58);
	drawCircle(330,450,col1,58);
	drawCircle(430,450,col1,58);
	drawCircle(530,450,col1,58);
}
void blackclouds1()
{
	drawCircle(-38,392,27,58);
	drawCircle(60,392,27,58);
	drawCircle(160,392,27,58);
	drawCircle(215,352,27,40);
	drawCircle(210,300,27,10);
	drawCircle(220,280,27,8);
	drawCircle(270,392,27,58);
	drawCircle(380,392,27,58);
	drawCircle(480,392,27,58);

}

void drawcloud(int col1)
{
	drawCircle(100,110,col1,30);
	drawCircle(150,130,col1,40);
	drawCircle(130,90,col1,20);
	drawCircle(190,110,col1,31);
	drawCircle(168,90,col1,25);
}

void clouds(int high,int col1)
{
	glPushMatrix();
	glTranslated(400,high,0);
	drawcloud(col1);
	glPopMatrix();
}
void cloudmotion(int col1)
{  	glPushMatrix();
	glTranslated(c1,0,0);
	clouds(290,col1);
	c1-=0.08;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(c2,0,0);
	clouds(250,col1);
	c2-=0.08;

	glPopMatrix();
	glPushMatrix();
	glTranslated(c3,0,0);
	clouds(300,col1);
	c3-=0.08;
	glPopMatrix();

	glPushMatrix();
	glTranslated(c4,0,0);
	clouds(270,col1);
	c4-=0.08;
	glPopMatrix();
}
void smokemotion()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glScaled(-0.03*sv,0.06*sv,0);
	drawsmoke();
	sv+=0.009;
	r1+=0.0;
	glPopMatrix();
	if(r1>200)
	{
		r1=0;
		sv=0;
	}

	glPushMatrix();
	glTranslated(205,270,0);
	glScaled(-0.02*sv,0.04*sv,0);
	drawsmoke();
	sv+=0.009;
	r2+=0.00;
	glPopMatrix();
	if(r2>200)
	{
		r2=0;
		sv=0;
	}

	glPushMatrix();
	glTranslated(219,250,0);
	glScaled(-0.015*sv,0.05*sv,0);
	drawsmoke();
	sv+=0.009;
	r3+=0.0;
	glPopMatrix();
	if(r3>200)
	{
		r3=0;
		sv=0;
	}
}


void firstpage_A(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"AIR POLLUTION");
	backdrop(17);
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display1);
	}
    glutPostRedisplay();
	glFlush();

}
void lastpage_A()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,360,f4,17,"EFFECTS OF AIR POLLUTION");
	PrintText(40,320,f5,18,"1.It weakens the lungs to function well, leading to asthma attacks");
	PrintText(40,290,f5,18,"2.It causes irritation of eyes, nose, mouth and throat");
	PrintText(40,260,f5,18,"3.It causes respiratory symptoms such as coughing and wheezing");
	PrintText(40,230,f5,18,"4.It increases the chances of respiratory diseases such as bronchitis");
	PrintText(40,200,f5,18,"5.It is the main reason of headaches and dizziness");
	PrintText(40,170,f5,18,"6.It causes disruption of endocrine, reproductive and immune systems");
	PrintText(40,140,f5,18,"7.It creates cardiovascular problems");
	PrintText(40,110,f5,18,"8.It may cause cancer due to presence of carcinogenic contents in it");
	backdrop(17);
	if(ap)
	{
		ap=0;
		flag=0;
		window2();
	}
	glutPostRedisplay();
	glFlush();
}
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(11,12);
	house(12,3,17,15,16);
	tree(0.0,8);
	tree(45.0,3);
	cloudmotion(28);
	blackclouds2(7);
	backdrop(6);
	glPopMatrix();

	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(lastpage_A);
	}
    glutPostRedisplay();
	glFlush();
}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	blackclouds2(7);
	rainmotion();
	cloudmotion(28);
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	blackclouds1();
	land_road(10,12);
	house(9,3,4);
	drawCircle(440,150,10,30);
	tree(0.0,8);
	drawCircle(480,150,11,30);
	tree(45.0,3);
	backdrop(6);
	glPopMatrix();

	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display4);
	}
    glutPostRedisplay();
	glFlush();
}
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	cloudmotion(14);
	blackclouds2(7);
	land_road(0,12);
	house(9,3,4);
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);

	backdrop(13);
	if(ap)
	{
		
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display3);
	}
    glutPostRedisplay();
	glFlush();
}
void display1(void)
{	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(1,12);
	house(9,3,4);
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);
	cloudmotion(9);
	backdrop(13);//background gradient
	if(ap)
	{
		
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display2);
	}
    glutPostRedisplay();
	glFlush();
}
void APmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		ap=1;
	}
}
void APkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			ap=1;
		}
}
void airpollutioninit()
{	
	glutDisplayFunc(firstpage_A);
	glutMouseFunc(APmouse);
	glutKeyboardFunc(APkeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
/*<<<<<<<<<-----------------------NOISE POLLUTION--------------------------->>>>>>>>>*/
void PrintText(float x, float y, void* font,int col, char *string)
{
  int len;
  glColor3dv(color1[col]);
  glPointSize(5.0);
  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (int i = 0; i < len; i++) 
  {
    glutBitmapCharacter(font, string[i]);
  }
}

void NPwaves(float x,float y,int col1,float r,int index,int range)
{
	int i;
    double radius = r;    
    glColor3dv(color1[col1]);
    double Pib2 = 3.142/10;
    glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    //glVertex2f(x, y); // center of circle
    for (i =index ; i <= range; i++)   {
        glVertex2f((x + (radius * cos(i * Pib2 / 20))), (y + (radius * sin(i * Pib2 / 20))));
    }
    glEnd();
	glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    for (i = index; i <= range; i++)   {
        glVertex2f((x + ((radius*1.5) * cos(i * Pib2 / 20))), (y + ((radius*1.5) * sin(i * Pib2 / 20))));
    }
    glEnd();
	glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    for (i = index; i <= range; i++)   {
        glVertex2f((x + ((radius*2) * cos(i * Pib2 / 20))), (y + ((radius*2) * sin(i * Pib2 / 20))));
    }
    glEnd();//END
	 
}

void drawcircle(float x,float y,int col1,float r,float num, int index,int range)
{
    int i;
    double radius = r;    
    glColor3dv(color1[col1]);
    double NPi = (2.0* 3.142)/num;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    //glVertex2f(x, y); // center of circle
    for (i = index; i <=range; i++)   {
        glVertex2f((x + (radius * cos(i * NPi / 20))), (y + (radius * sin(i * NPi / 20))));
    }
    glEnd(); //END
}

void NPsounds(float x,float y,int col1,int col2,float r, int seg,float a,float b)
{
    int i;
    double radius = r;    
    double twoPi = 2.0 * 3.142;
	PrintText(a,b,f5,col2,"HONK");
	glColor3dv(color1[col1]);
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x,y);
    for (i = 0; i <= 55; i++)   
	{	
		if(i%2==0)
		{	if(i%4==0)
			    glVertex2f((x + ((radius*2) * cos(i * twoPi / seg))), (y + ((radius*2) * sin(i * twoPi / seg))));
			else
				glVertex2f((x + ((radius*1.79) * cos(i * twoPi / seg))), (y + ((radius*1.79) * sin(i * twoPi / seg))));
        }else
				glVertex2f((x + (radius * cos(i * twoPi / seg))), (y + (radius * sin(i * twoPi / seg))));
    }
    glEnd();
}
void NPCharacter(int ch)
{	
	glPushMatrix();
	glTranslated(190,0,0);
	//head
	drawcircle(128,176,18,9.5,20.0,30,150);
	drawcircle(128,176,19,9.5,1.0,0,20);
	glColor3f(0.957, 0.643, 0.376);
	glBegin(GL_POLYGON);
	glVertex2f(126.5,162);
	glVertex2f(126.5,176);
	glVertex2f(129.5,176);
	glVertex2f(129.5,162);
	glEnd();
	//Hands
	if(ch)
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(105,160);
		glVertex2f(122.5,180);
		glVertex2f(127.5,180);
		glVertex2f(111.5,160);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(150,160);
		glVertex2f(133.5,180);
		glVertex2f(128.5,180);
		glVertex2f(144.5,160);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(105,160);
		glVertex2f(110,165);
		glVertex2f(147,165);
		glVertex2f(150,160);
		glVertex2f(147,157);
		glVertex2f(110,157);
		glEnd();
	}else
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(116,135);
		glVertex2f(116,160);
		glVertex2f(120,160);
		glVertex2f(120,135);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(137,160);
		glVertex2f(141,160);
		glVertex2f(141,135);
		glVertex2f(137,135);
		glEnd();
	}
	//shirt
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(120,130);
	glVertex2f(120,160);
	glVertex2f(137,160);
	glVertex2f(137,130);
	glEnd();
	//legs
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(121,100);
	glVertex2f(121,140);
	glVertex2f(127,140);
	glVertex2f(127,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(129,100);
	glVertex2f(129,140);
	glVertex2f(135,140);
	glVertex2f(135,100);
	glEnd();
	glPopMatrix();
}
void NPwavemotion()
{
	
	glPushMatrix();
	glTranslated(230,170,0);
	glScaled(0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,0,100);
	scv+=0.00002;
	r+=0.45;
	glPopMatrix();

	glPushMatrix();
	glTranslated(160,210,0);
	glScaled(-0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,0,100);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();

	glPushMatrix();
	glTranslatef(170,290,0);
	glScaled(0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,20,120);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();

	glPushMatrix();
	glTranslatef(340,130,0);
	glScaled(0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,340,440);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();

	if(r>200)
	{
		r=.45;
		scv=5;
	}

}

void NPMisc()
{
	glColor3f(0.6 ,0.09, 0.09);//SCARLET
	glBegin(GL_POLYGON);
	glVertex2f(358,175);
	glVertex2f(358,185);
	glVertex2f(365,185);
	glVertex2f(365,175);
	glEnd();

	glColor3f(0.6 ,0.8,0.196078);//MIC
	glBegin(GL_POLYGON);
	glVertex2f(365,185);
	glVertex2f(380,195);
	glVertex2f(380,165);
	glVertex2f(365,175);
	glEnd();
	
	glColor3f(.10,.10,.10);//POLE
	glBegin(GL_POLYGON);
	glVertex2f(360,100);
	glVertex2f(360,200);
	glVertex2f(365,200);
	glVertex2f(365,100);
	glEnd();
	
}

void NPbackdrop(int col)
{
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(0,0);
		glVertex2f(1200,0);
		glColor3dv(color1[col]);//0.0,0.698039,1.0
		glVertex2f(1200,700);
		glVertex2f(0,700);
		glEnd();
}

void NPdrawtruck()
{	drawcircle(85,95,14,9,1.0,0,20);
	drawcircle(85,95,12,20,1.0,0,20);
	drawcircle(185,95,14,9,1.0,0,20);
	drawcircle(185,95,12,20,1.0,0,20);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(45,140);
	glVertex2f(63,170);
	glVertex2f(80,170);
	glVertex2f(80,140);
	glEnd();
	glColor3f(0.50,0.50,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(98,200);
	glVertex2f(98,210);
	glVertex2f(218,210);
	glVertex2f(218,200);
	glEnd();
	glColor3f(0.80,0.80,0.80);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(100,200);
	glVertex2f(215,200);
	glVertex2f(215,100);
	glEnd();
	glColor3f(0.50,0.50,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(40,110);
	glVertex2f(40,140);
	glVertex2f(65,180);
	glVertex2f(100,180);
	glVertex2f(100,110);
	glEnd();
	glColor3f(0.20,0.20,0.20);
	glBegin(GL_POLYGON);
	glVertex2f(35,100);
	glVertex2f(35,110);
	glVertex2f(100,110);
	glVertex2f(100,100);
	glEnd();
}

void NPredcar(int x,int y,int col,int col2,float r)
{
	drawCircle(x,y,col2,r-10);
	drawCircle(x,y,col,r);
	drawCircle(x+70,y,col2,r-10);
	drawCircle(x+70,y,col,r);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(95,40);
	glVertex2f(110,55);
	glVertex2f(120,55);
	glVertex2f(120,40);
	glEnd();
	glColor3f(0.9,0.1,0.0);//red
	glBegin(GL_POLYGON);
	glVertex2f(60,10);
	glVertex2f(60,40);
	glVertex2f(90,40);
	glVertex2f(110,60);
	glVertex2f(150,60);
	glVertex2f(170,40);
	glVertex2f(190,40);
	glVertex2f(190,10);
	glEnd();

}

void NPTruckmotion()
{  	
		if(c5<279)
		{   
			c5=278;
			glPushMatrix();
			NPsounds(420,140,20,9,16,24,410,140);
			glTranslated(c5,85,0);
			NPredcar(90,7,12,14,17);
			glPopMatrix();
		}
		glPushMatrix();
		glTranslated(c5,85,0);
		NPredcar(90,7,12,14,17);
		c5-=.18;
		glPopMatrix();

		if(c6<87)
		{   
			c6=86;
			glPushMatrix();
			glTranslated(c6,0,0);
			NPsounds(90,190,20,9,16,24,70,185);
			NPdrawtruck();
			glPopMatrix();
		}
		
		glPushMatrix();
		glTranslated(c6,0,0);
		NPdrawtruck();
		c6-=.3;
		glPopMatrix();
		
}
void NPCar(float x,float y,int col1,int col2)
{   glPushMatrix();
	glTranslated(x,y,0);
	drawcircle(30,138,9,8,1.0,0,20);
	drawcircle(90,138,9,8,1.0,0,20);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(16,115);
	glVertex2f(16,125);
	glVertex2f(104,125);
	glVertex2f(104,115);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(40,135);
	glVertex2f(40,140);
	glVertex2f(80,140);
	glVertex2f(80,135);
	glEnd();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(18,125);
	glVertex2f(18,140);
	glVertex2f(24,150);
	glVertex2f(96,150);
	glVertex2f(102,140);
	glVertex2f(102,125);
	glEnd();
	glColor3f(0.678431 ,0.917647 ,0.917647);//window
	glBegin(GL_POLYGON);
	glVertex2f(33,134);
	glVertex2f(38,173);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(80,173);
	glVertex2f(88,134);
	glEnd();
	glColor3dv(color1[col2]);//darkturqoise
	glBegin(GL_POLYGON);
	glVertex2f(24,130);
	glVertex2f(32,180);
	glVertex2f(86,180);
	glVertex2f(96,130);
	glEnd();
	glColor3f(0.0,0.0,0.0);//leftwheel
	glBegin(GL_POLYGON);
	glVertex2f(23,100);
	glVertex2f(23,130);
	glVertex2f(41,130);
	glVertex2f(41,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);//rightwheel
	glBegin(GL_POLYGON);
	glVertex2f(79,100);
	glVertex2f(79,130);
	glVertex2f(97,130);
	glVertex2f(97,100);
	glEnd();
	glPopMatrix();
}
void NPBuildings(int col1,int col2)
{	
	glColor3f(1.0,1.0,1.0);
	int i,j;
	for( i=0;i<31;i+=22)
	{	for( j=0;j<90;j+=22)
		{	glBegin(GL_POLYGON);
			glVertex2f(128+(float)i,110+(float)j);
			glVertex2f(128+(float)i,125+(float)j);
			glVertex2f(143+(float)i,125+(float)j);
			glVertex2f(143+(float)i,110+(float)j);
			glEnd();
		}
	}for( i=0;i<31;i+=22)
	{	for(j=0;j<90;j+=22)
		{	glBegin(GL_POLYGON);
			glVertex2f(176+(float)i,110+(float)j);
			glVertex2f(176+(float)i,125+(float)j);
			glVertex2f(191+(float)i,125+(float)j);
			glVertex2f(191+(float)i,110+(float)j);
			glEnd();
		}
	}for( i=0;i<31;i+=22)
	{	for( j=0;j<90;j+=22)
		{	glBegin(GL_POLYGON);
			glVertex2f(226+(float)i,110+(float)j);
			glVertex2f(226+(float)i,125+(float)j);
			glVertex2f(241+(float)i,125+(float)j);
			glVertex2f(241+(float)i,110+(float)j);
			glEnd();
		}
	}

	//building1
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(120,100);
	 glVertex2f(120,270);
	 glVertex2f(170,225);
	 glVertex2f(170,100);
	 glEnd();
	 //Chimney1
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(130,320);
	 glVertex2f(130,340);
	 glVertex2f(160,340);
	 glVertex2f(160,320);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(130,200);
	 glVertex2f(130,350);
	 glVertex2f(160,350);
	 glVertex2f(160,200);
	 glEnd();
	//building2
     glColor3f(0.258824,0.258824,0.435294);//cornflowerblue
	 glBegin(GL_POLYGON);
	 glVertex2f(170,100);
	 glVertex2f(170,270);
	 glVertex2f(220,225);
	 glVertex2f(220,100);
	 glEnd();
	 //Chimney2
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(180,320);
	 glVertex2f(180,340);
	 glVertex2f(210,340);
	 glVertex2f(210,320);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(180,200);
	 glVertex2f(180,350);
	 glVertex2f(210,350);
	 glVertex2f(210,200);
	 glEnd();
	 //building3
	 glColor3f( 1.0 ,0.498039, 0.0);//coral
	 glBegin(GL_POLYGON);
	 glVertex2f(220,100);
	 glVertex2f(220,270);
	 glVertex2f(270,225);
	 glVertex2f(270,100);
	 glEnd();
	 //Chimney3
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(230,360);
	 glVertex2f(230,380);
	 glVertex2f(260,380);
	 glVertex2f(260,360);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(230,200);
	 glVertex2f(230,400);
	 glVertex2f(260,400);
	 glVertex2f(260,200);
	 glEnd();

	 //House
	  glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(308,100);
	 glVertex2f(308,140);
	 glVertex2f(342,140);
	 glVertex2f(342,100);
	 glEnd();
	 glColor3f(1.0,0.25,0.0 );
	 glBegin(GL_POLYGON);
	 glVertex2f(290,100);
	 glVertex2f(290,170);
	 glVertex2f(360,170);
	 glVertex2f(360,100);
	 glEnd();
	 glColor3f(0.0,0.0,0.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(300,170);
	 glVertex2f(280,170);
	 glVertex2f(325,220);
	 glVertex2f(370,170);
	 glVertex2f(350,170);
	 glEnd();

	 //SUPERMARKET
	 PrintText(389,176,f5,18,"DONUT STOP");
	 glColor3f(.8,.8,.8);
	 glBegin(GL_POLYGON);
	 glVertex2f(385,170);
	 glVertex2f(385,200);
	 glVertex2f(500,200);
	 glVertex2f(500,170);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(400,90);
	 glVertex2f(400,130);
	 glVertex2f(430,130);
	 glVertex2f(430,90);
	 glEnd();
	 glColor3f(0.62352 ,0.372549 ,0.623529);//blueviolet
	 glBegin(GL_POLYGON);
	 glVertex2f(380,90);
	 glVertex2f(380,230);
	 glVertex2f(500,230);
	 glVertex2f(500,90);
	 glEnd();
	 
}

void NPLand(int col1,int col2)
{	float d=0.0;
	for(int i=0;i<7;i++)
	{	
		strips(d);
		d+=70.0;
	}
	//land
	glPointSize(2.0);
	glPushMatrix();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,40);
	glVertex2f(500,40);
	glVertex2f(500,0);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3f(.30,.30,.30);
	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(500,100);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
}
void lastpage_N(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,360,f4,17,"EFFECTS OF NOISE POLLUTION");
	PrintText(40,320,f5,18,"1.Noise beyond the permissible limits damages hearing");
	PrintText(40,290,f5,18,"2.It causes irritation in attitude");
	PrintText(40,260,f5,18,"3.It creates hypertension");
	PrintText(40,230,f5,18,"4.It affects mental sharpness");
	PrintText(40,200,f5,18,"5.It causes undue fatigue");
	backdrop(17);
	if(np)
	{
		np=0;
		flag=0;
		window3();
	}
    glutPostRedisplay();
	glFlush();
}
void firstpage_N(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"NOISE POLLUTION");
	backdrop(17);
	if(np)
	{
		glClearColor(0,0.6,0.8,0);
		np=0;
		glutDisplayFunc(NPScene1);
	}
    glutPostRedisplay();
	glFlush();
}
void NPScene2(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	NPsounds(30,220,19,20,20,24,10,215);
	NPsounds(90,190,20,9,16,16,70,185);
	NPTruckmotion();
	NPwavemotion();
	NPCharacter(1);
	NPMisc();
	NPCar(0,0,25,26);NPCar(20,0,23,24);NPCar(-30,0,21,22);
	NPLand(14,7);
	NPBuildings(17,3);
	NPbackdrop(13);
	if(np)
	{
		np=0;
		glutDisplayFunc(lastpage_N);
	}
	glutPostRedisplay();
	glFlush();
}
void NPScene1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	NPCharacter(0);
	NPMisc();
	NPCar(0,0,25,26);NPCar(20,0,23,24);NPCar(-30,0,21,22);
	NPLand(14,7);
	NPBuildings(17,3);
	NPbackdrop(13);
	if(np)
	{
		np=0;
		glutDisplayFunc(NPScene2);
	}
	glutPostRedisplay();
	glFlush();
}
void NPmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		np=1;
	}
}

void NPkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			np=1;
		}
}
void NoisePollutioninit()
{
	glutDisplayFunc(firstpage_N);
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(NPmouse);
	glutKeyboardFunc(NPkeys);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}

/*<<<<<<<<-----------------------------------------------------WATER POLLUTION---------------------------------->>>>>>>>>*/
void lastpage_W(void)
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,360,f4,17,"EFFECTS OF WATER POLLUTION ");
	PrintText(40,320,f5,18,"1.Rashes, ear ache, pink eye ");
	PrintText(40,290,f5,18,"2.Infections in respiratory system");
	PrintText(40,260,f5,18,"3.Hepatitis,gastroenteritis, diarrhea, vomiting, and stomach aches");
	PrintText(40,230,f5,18,"4.Hormonal problems which may hit reproductive and developmental processes");
	PrintText(40,200,f5,18,"5.Damage to the liver and kidney");
	PrintText(40,170,f5,18,"6.Parkinson’s disease");
	backdrop(17);
	if(wp)
	{
		wp=0;
		window4();
	}
    glutPostRedisplay();
	glFlush();
}

void Wsky ()
{
	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
	glVertex2f(260,340);
	glVertex2f(280,340);
	glVertex2f(340,340);
	glVertex2f(360,340);
	glVertex2f(420,340);
	glVertex2f(440,340);
	glVertex2f(499.9,340);
	glVertex2f(499.9,499.9);
	glVertex2f(260,499.9);
	glEnd();

	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,340);
	glVertex2f(19,340);
	glVertex2f(131,340);
	glVertex2f(260,340);
	glVertex2f(260,499.9);
	glVertex2f(0.1,499.9);
	glEnd();
}

void Wcircle(GLint x,GLint y,GLint r,int col1,int col2)
{
	GLint i;
	glColor3dv(color1[col1]);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
		glColor3dv(color1[col2]);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Wsun()
{
int xc=240,yc=470,r=20;
Wcircle(xc,yc,r,30,31);
Wrays();
}

void Wrays()
{
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_LINE_STRIP);
	glVertex2f(230,450);
	glVertex2f(220,435);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(240,450);
	glVertex2f(240,432);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(250,450);
	glVertex2f(260,435);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(260,455);
	glVertex2f(270,445);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(220,455);
	glVertex2f(210,445);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(220,465);
	glVertex2f(205,465);
	glEnd();
		
	glBegin(GL_LINE_STRIP);
	glVertex2f(260,465);
	glVertex2f(275,465);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(260,475);
	glVertex2f(275,485);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(220,475);
	glVertex2f(205,485);
	glEnd();
     	
	glBegin(GL_LINE_STRIP);
	glVertex2f(230,485);
	glVertex2f(215,499.9);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(240,490);
	glVertex2f(240,499.9);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(250,485);
	glVertex2f(265,499.9);
	glEnd();
}

void Wgrass()
{
	glColor3f(0.196078,0.8,0.196078);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,339.9);
	glVertex2f(219.9,339.9);
	glVertex2f(219.9,249.9);
	glVertex2f(0.1,249.9);
	glEnd();

	glColor3f(0.196078,0.8,0.196078);
	glBegin(GL_POLYGON);
	glVertex2f(259.9,339.9);
	glVertex2f(499.9,339.9);
	glVertex2f(499.9,249.9);
	glVertex2f(259.9,249.9);
	glEnd();
}
void Wunderground()
{
	glColor3f(0.81,0.71,0.23);
	glBegin(GL_POLYGON);
	glVertex2f(260,250);
	glVertex2f(260,260);
	glVertex2f(499.9,260);
	glVertex2f(499.9,250);
	glEnd();
}
void Wpipe2()
{
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(307,259.9);
	glVertex2f(312,259.9);
	glVertex2f(312,249.9);
	glVertex2f(307,249.9);
	glEnd();
     
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(387,259.9);
	glVertex2f(392,259.9);
	glVertex2f(392,249.9);
	glVertex2f(387,249.9);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(467,259.9);
	glVertex2f(472,259.9);
	glVertex2f(472,249.9);
	glVertex2f(467,249.9);
	glEnd();
}

void Wfactory()
{
	// window
	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(30,352.5);
	glVertex2f(50,352.5);
	glColor3dv(color1[13]);
	glVertex2f(50,397.5);
	glVertex2f(30,397.5);	
	glEnd();

	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(70,352.5);
	glVertex2f(90,352.5);
	glColor3dv(color1[13]);
	glVertex2f(90,397.5);
	glVertex2f(70,397.5);
	glEnd();

	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(110,352.5);
	glVertex2f(125,352.5);
	glColor3dv(color1[13]);
	glVertex2f(125,397.5);
	glVertex2f(110,397.5);
	glEnd();

	//door
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(70,250);
	glVertex2f(90,250);
	glVertex2f(90,290);
	glVertex2f(70,290);
	glEnd();
   	 //base
	glColor3dv(color1[27]);
	glBegin(GL_POLYGON);
	glVertex2f(20,300);
	glVertex2f(130,300);
	glVertex2f(130,330);
	glVertex2f(20,330);
	glEnd();

     glColor3dv(color1[27]);
	glBegin(GL_POLYGON);
	glVertex2f(1,250);
	glVertex2f(150,250);
	glVertex2f(150,300);
	glVertex2f(1,300);
	glEnd();

	//body
	glColor3dv(color1[12]);
    glBegin(GL_POLYGON);
	glVertex2f(20,330);
	glVertex2f(20,420);
	glVertex2f(130,420);
	glVertex2f(130,330);
	glEnd();
	
    glColor3dv(color1[12]);
    glBegin(GL_LINE_LOOP);
	glVertex2f(20,330);
	glVertex2f(20,420);
	glVertex2f(130,420);
	glVertex2f(130,330);
	glEnd();

// Chimney
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f( 25,420);
	glVertex2f( 40,420);
	glVertex2f(40,480);
	glVertex2f(25,480);
	glEnd();
	
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(22,480);
	glVertex2f(43,480);
	glVertex2f(43,490);
	glVertex2f(22,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f( 55,420);
	glVertex2f(65,420);
	glVertex2f( 65,480);
	glVertex2f( 55,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(52,480);
	glVertex2f(68,480);
	glVertex2f(68,490);
	glVertex2f(52,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(85,420);
	glVertex2f(95,420);
	glVertex2f(95,480);
	glVertex2f(85,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(82,480);
	glVertex2f(98,480);
	glVertex2f(98,490);
	glVertex2f(82,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(110,420);
	glVertex2f(125,420);
	glVertex2f(125,480);
	glVertex2f(110,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(107,480);
	glVertex2f(128,480);
	glVertex2f(128,490);
	glVertex2f(107,490);
	glEnd();
}

void Wpipe()
{   // pipe
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(130,300);
	glVertex2f(160,300);
	glVertex2f(160,320);
	glVertex2f(130,320);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
    glBegin(GL_POLYGON);
	glVertex2f(150,320);
	glVertex2f(160,320);
	glVertex2f(160,250);
	glVertex2f(150,250);
	glEnd();
    
	glColor3f(0.556863,0.137255,0.137255);
    glBegin(GL_POLYGON);
	glVertex2f(260,260);
	glVertex2f(260,270);
	glVertex2f(499.9,270);
	glVertex2f(499.9,260);
	glEnd();
}

void Wroads()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(220,339.9);
	glVertex2f(260,339.9);
	glVertex2f(260,250);
	glVertex2f(220,250);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(499.9,250);
	glVertex2f(499.9,200);
	glVertex2f(0.1,200);
	glVertex2f(0.1,250);
	glEnd();
}

void Wcar(int x)
{	
		if(pos1<500)
	pos1+=1.0;
	if(pos1==500)
	pos1-=500;
	if(cx1<500)
	cx1+=0.5;
	if(cx1>=500)
	cx1-=500;
		//body of car//
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(10+x,220);
		glVertex2f(10+x,235);
		glVertex2f(60+x,235);
		glVertex2f(60+x,220);
		glEnd();
		//bars of car//
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(15+x,235);
		glVertex2f(20+x,245);
		glVertex2f(20+x,243);
		glVertex2f(17+x,235);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(20+x,245);
		glVertex2f(40+x,245);
		glVertex2f(40+x,243);
		glVertex2f(20+x,243);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(40+x,245);
		glVertex2f(45+x,235);
		glVertex2f(43+x,235);
		glVertex2f(40+x,243);		
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(28+x,243);
		glVertex2f(32+x,243);
		glVertex2f(32+x,235);
		glVertex2f(28+x,235);
		glEnd();

		//glass//
		glBegin(GL_POLYGON);
		glColor3f(0.9,0.9,0.9);
		glVertex2f(20+x,243);
		glVertex2f(40+x,243);
		glVertex2f(43+x,235);
		glVertex2f(17+x,235);
		glEnd();
}

void Wcircles(int x,int y,int r,int col)
{
	GLint i;
	glColor3dv(color1[col]);//darkgoldenrod
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Wbubble(int xc,int r, int y,int col)
{
 int yc=150+y;
 int i,n=40;
for(i=0;i<n;i+=3)
{
	Wcircles(xc,yc+i,r,col);
}
glEnd();
}

void Wwater(int col)
{
	glColor3dv(color1[col]);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,200);
    glVertex2f(499.9,200);
	glVertex2f(499.9,0.1);
	glVertex2f(0.1,0.1);
	glEnd();
}
void Wunderpipe1()
{
   	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(150,200);
	glVertex2f(160,200);
	glVertex2f(160,180);
	glVertex2f(150,180);
	glEnd();
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(150,180);
	glVertex2f(160,180);
	glVertex2f(170,170);
	glVertex2f(140,170);
	glVertex2f(150,180);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(370,200);
	glVertex2f(380,200);
	glVertex2f(380,180);
	glVertex2f(370,180);
	glEnd();

    glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(370,180);
	glVertex2f(380,180);
	glVertex2f(390,170);
	glVertex2f(360,170);
	glVertex2f(370,180);
	glEnd();


}
void Wstripesy(float dist)
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(238.5,330-dist);
	glVertex2f(241.5,330-dist);
	glVertex2f(241.5,300-dist);
	glVertex2f(238.5,300-dist);//dist=50
	glEnd();
}

void Wstripesx(float dist)
{	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(5+dist,223);
	glVertex2f(5+dist,227);
	glVertex2f(25+dist,227);
	glVertex2f(25+dist,223); //dist=40 
	glEnd();
}
void Wstripesmall(int dist)
{	glColor3f(1.0,1.0,1.0);
	//glPointSize(2.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(265+dist,275);
	glVertex2f(275+dist,275);
	glEnd();
}
void Wstripes(int d,int d1,int d2)
 {
	for(int i=0;i<2;i++)
	{	Wstripesy(d);
		d+=50;
	}
	for(i=0;i<=12;i++)
	{
		Wstripesx(d1);
		d1+=40;
	}
	for(i=0;i<=8;i++)
	{
		Wstripesmall(d2);
		d2+=20;
	}
 }

void Whouse()
{  
	 glColor3f(1,1,1);
	 glBegin(GL_POLYGON);
	 glVertex2f(300,290);
	 glVertex2f(300,325);
	 glVertex2f(320,325);
	 glVertex2f(320,290);
	 glEnd();
	
	 glColor3f(1,1,1);
	 glBegin(GL_POLYGON);
	 glVertex2f(460,290);
	 glVertex2f(460,325);
	 glVertex2f(480,325);
	 glVertex2f(480,290);
	 glEnd();
     
	 glColor3f(1,1,1);
	 glBegin(GL_POLYGON);
	 glVertex2f(380,290);
	 glVertex2f(380,325);
	 glVertex2f(400,325);
	 glVertex2f(400,290);
	 glEnd();

	glColor3f(0.52,0.39,0.39);
	glBegin(GL_POLYGON);
	glVertex2f(280,290);
	glVertex2f(340,290);
	glVertex2f(340,360);
	glVertex2f(280,360);
	glEnd();

	 glColor3f(0,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(275,360);
	 glVertex2f(310,410);
	 glVertex2f(345,360);
	 glVertex2f(275,360);
	 glEnd();
	
    glColor3f(0.52,0.39,0.39); 
  	glBegin(GL_POLYGON);
	glVertex2f(360,290);
	glVertex2f(420,290);
	glVertex2f(420,360);
	glVertex2f(360,360);
	glEnd();
     
	 glColor3f(0,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(355,360);
	 glVertex2f(390,410);
	 glVertex2f(425,360);
	 glVertex2f(355,360);
	 glEnd();
	        
	glColor3f(0.52,0.39,0.39);
	glBegin(GL_POLYGON);
	glVertex2f(440,290);
	glVertex2f(499,290);
	glVertex2f(499,360);
	glVertex2f(440,360);
	glEnd();
     
	 glColor3f(0,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(440,360);
	 glVertex2f(470,410);
	 glVertex2f(499,360);
	 glVertex2f(440,360);
	 glEnd();

}

void WParc(float x,float y,int col1,float r,int index,int range)
{
	int i;
    double radius = r;    
    glColor3dv(color1[col1]);
    double Pib2 = 3.142/10;
    glBegin(GL_POLYGON); //BEGIN CIRCLE
    for (i =index ; i <= range; i++)   {
        glVertex2f((x + (radius * cos(i * Pib2 / 20))), (y + (radius * sin(i * Pib2 / 20))));
    }
    glEnd();
}
void Wfish(int col,int x,int y)
{	
	Wcircle(240+x,63+y,2,9,9);
	WParc(250+x,50+y,col,22,35,165);
	WParc(250+x,75.5+y,col,22,240,360);
	glColor3dv(color1[col]); 
	glBegin(GL_POLYGON);
	glVertex2f(260+x,63+y);
	glVertex2f(280+x,70+y);
	glVertex2f(275+x,63+y);
	glVertex2f(280+x,56+y);
	glVertex2f(260+x,63+y);
	glEnd();
}
void Wfishmotion(int ch)
{	int col=31;
	
	if(fi<-550)
	{
		fi=450;		
	}
	if(ch)
		{
			if(fi<=300)
				col=32;
		
			if(fi<150)
				b1-=2;
			glPushMatrix();
			glTranslated(fi,b1,0);
			Wfish(col,0,0);
			fi-=.9;
			glPopMatrix();
			if(fi<100)
				b2-=2;
			glPushMatrix();
			glTranslated(fi,b2,0);
			Wfish(col,150,10);
			fi-=.02;
			glPopMatrix();
			if(fi<50)
				b3-=2;
			glPushMatrix();
			glTranslated(fi,b3,0);
			Wfish(col,100,30);
			fi-=.38;
			glPopMatrix();
			if(fi<-100)
				b4-=2;
			glPushMatrix();
			glTranslated(fi,b4,0);
			Wfish(col,-200,50);
			fi-=.03;
			glPopMatrix();
			if(fi<-150)
				b5-=2;
			glPushMatrix();
			glTranslated(fi,b5,0);
			Wfish(col,-100,20);
			fi-=.19;
			glPopMatrix();

			}
	else
	{
		if(fi<=-50)
		{	col=32;
		}	
	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,0,0);
	fi-=.9;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,150,10);
	fi-=.02;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,100,30);
	fi-=.38;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,-200,50);
	fi-=.03;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,-100,20);
	fi-=.19;
	glPopMatrix();
	glutPostRedisplay();
}
}
void Wroads2()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(260,270);
	glVertex2f(499.9,270);
	glVertex2f(499.9,280);
	glVertex2f(260,280);
	glEnd();

	glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(300,290);
	glVertex2f(320,290);
	glVertex2f(330,275);
	glVertex2f(290,275);
	glEnd();

    glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(380,290);
	glVertex2f(400,290);
	glVertex2f(410,275);
	glVertex2f(370,275);
	glEnd();

	glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(460,290);
	glVertex2f(480,290);
	glVertex2f(490,275);
	glVertex2f(450,275);
	glEnd();
}

void Wcar_dumpmotion()
{
	
	glPushMatrix();
	glTranslated(120,cy1,0);
	cy1-=.5;
	glPopMatrix();
	if(cy1<-120)
	{
		cy1=30;
	}
}


void WDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Wcar_dumpmotion();
	Wcar(cx1);
	Wsun();
	Wunderground();
	Wfactory();	
	Wstripes(0,0,0);
	Wroads();
	Whouse();
	Wroads2();
	Wpipe2();
	Wpipe();
	Wunderpipe1();
	Wgrass();
	Wbubble(155,5,cy1,18);
	Wbubble(375,5,cy1,36);
	Wfishmotion(1);
	Wwater(35);
	backdrop(13);
    if(wp)
	{
		wp=0;
		glutDisplayFunc(lastpage_W);
	}
	glutPostRedisplay();
	glFlush();
}


void WaterPollution()
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Wcar_dumpmotion();
	Wcar(cx1);
	Wsun();
	Wunderground();
	Wfactory();	
	Wstripes(0,0,0);
	Wroads();
	Whouse();
	Wroads2();
	Wpipe2();
	Wpipe();
	Wunderpipe1();
	Wgrass();
	Wbubble(155,5,cy1,18);
	Wbubble(375,5,cy1,36);
	Wfishmotion(0);
	Wwater(34);
	backdrop(13);
	if(wp)
	{
		wp=0;
		glutDisplayFunc(WDisplay2);
	}
	glutPostRedisplay();
	glFlush();
}

void firstpage_W(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"WATER POLLUTION");
	backdrop(17);
	if(wp)
	{
		glClearColor(0,0.6,0.8,0);
		wp=0;
		glutDisplayFunc(WaterPollution);
	}
    glutPostRedisplay();
	glFlush();
}
void WPmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		wp=1;
	}
}

void WPkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			wp=1;
		}
}
void waterpollutioninit()
{	
	glutDisplayFunc(firstpage_W);
	glutMouseFunc(WPmouse);
	glutKeyboardFunc(WPkeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
/*<<<<<<<<-------------------------------------soil pollution---------------------------->>>>>>>>>*/
void KEYSpage()
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(30,360,f4,18,"USE THE FOLLOWING KEYS TO SEE");
	PrintText(30,320,f4,18,"THE EFFECTS ON HUMAN BODY");
	PrintText(30,280,f4,18,"IN THE NEXT WINDOW");
	PrintText(30,240,f4,18,"'A' or 'a': For Air Pollution");
	PrintText(30,200,f4,18,"'N' or 'n': For Noise Pollution");
	PrintText(30,160,f4,18,"'W' or 'w': For Water Pollution");
	PrintText(30,120,f4,18,"'S' or 's': For Soil Pollution");
	PrintText(30,80,f4,18,"Other Keys: A Healthy Human Body");

	backdrop(17);
	if(sp)
	{	sp=0;
		flag=0;
		HUMANBODY();
	}
	glutPostRedisplay();
	glFlush();
}
void lastpage_S(void)
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,360,f4,17,"EFFECTS OF SOIL POLLUTION");
	PrintText(40,320,f5,18,"1.Direct contact with the polluted soil may cause cancer including leukemia");
	PrintText(40,290,f5,18,"2.Lead in soil is hazardous for young children and retards brain growth");
	PrintText(40,260,f5,18,"3.Mercury increases the risk of damage to the kidney");
	PrintText(40,230,f5,18,"4.Polluted land causes neuro muscular blockage");
	PrintText(40,200,f5,18,"5.It may depress the central nervous system of the human body");
	PrintText(40,170,f5,18,"6.It also causes headaches, nausea, fatigue, eye irritation and skin rash");
	backdrop(17);
	if(sp)
	{
		sp=0;
		flag=0;
		glutDisplayFunc(KEYSpage);
	}
    glutPostRedisplay();
	glFlush();
}
void Searth(int x,int y,int r)
{
	GLint i;
	glColor3f(0.878, 1.000, 1.000);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Scircle()
{
GLint xc=200,yc=150,r=120;
	Searth(xc,yc,r);
}

void Sbattery2()
{	
	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(115.5,93.5);
	glVertex2f(115.5,95.5);
	glVertex2f(121.5,95.5);
	glVertex2f(121.5,93.5);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(87.9,93.5);
	glVertex2f(87.9,95.5);
	glVertex2f(91.5,95.5);
	glVertex2f(91.5,93.5);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(117.5,91);
	glVertex2f(117.5,98);
	glVertex2f(119.5,98);
	glVertex2f(119.5,91);
	glEnd();

	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(114,80);
	glVertex2f(114,110);
	glVertex2f(123,110);
	glVertex2f(123,80);
	glEnd();
	
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(87,80);
	glVertex2f(87,110);
	glVertex2f(92,110);
	glVertex2f(92,80);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(85,80);
	glVertex2f(85,110);
	glVertex2f(125,110);
	glVertex2f(125,80);
	glEnd();
	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(125,92.5);
	glVertex2f(125,95.5);
	glVertex2f(127.5,95.5);
	glVertex2f(127.5,92.5);
	glEnd();
}
void Sbattery1()
{	//standing battery
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,82);
	glVertex2f(70,88);
	glVertex2f(100,88);
	glVertex2f(100,82);
	glEnd();
	//plus
	glColor3f(0.000, 0.000, 0.502);
	glBegin(GL_POLYGON);
	glVertex2f(83,119);
	glVertex2f(83,126);
	glVertex2f(87,126);
	glVertex2f(87,119);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(80,120.5);
    glVertex2f(80,123.5);
	glVertex2f(90,123.5);
	glVertex2f(90,120.5);
	glEnd();
	//yellowthick bar
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,118);
	glVertex2f(70,127);
	glVertex2f(100,127);
	glVertex2f(100,118);
	glEnd();

	glColor3f(0.000, 0.000, 0.502);
	glBegin(GL_POLYGON);
	glVertex2f(70,80);
	glVertex2f(70,130);
	glVertex2f(100,130);
	glVertex2f(100,80);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(83,130);
	glVertex2f(83,134);
	glVertex2f(87,134);
	glVertex2f(87,130);
	glEnd();
}

void Sbase()
{
	glColor3f(0.941, 0.902, 0.549);
	glBegin(GL_POLYGON);
	glVertex2f(120,25);
	glVertex2f(120,45);
	glVertex2f(280,45);
	glVertex2f(280,25);
	glEnd();
}

void Strees()
{   //body
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(140,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(150,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(160,45);
	glEnd();

	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(180,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(190,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(200,45);
	glEnd();

    glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(220,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(230,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(240,45);
	glEnd();

    //branches 1
	 glColor3f(0.545, 0.271, 0.075);
	 glBegin(GL_POLYGON);
	 glVertex2f(145,100);
	 glVertex2f(146,115);
	 glVertex2f(120,145);
	 glVertex2f(145,100);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glVertex2f(185,100);
	 glVertex2f(186,115);
	 glVertex2f(160,145);
	 glVertex2f(185,100);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glVertex2f(225,100);
	 glVertex2f(226,115);
	 glVertex2f(200,145);
	 glVertex2f(225,100);
	 glEnd();
	
	  glBegin(GL_POLYGON);
	  glVertex2f(151,155);
	  glVertex2f(151,150);
	  glVertex2f(170,175);
	  glVertex2f(153,155);
	  glEnd();

	   glBegin(GL_POLYGON);
	  glVertex2f(191,155);
	  glVertex2f(191,150);
	  glVertex2f(210,175);
	  glVertex2f(191,155);
	  glEnd();
	  
	   glBegin(GL_POLYGON);
	  glVertex2f(231,155);
	  glVertex2f(231,150);
	  glVertex2f(250,175);
	  glVertex2f(231,155);
	  glEnd();

}

void Sleaves(int x,int y,int r)
{
	GLint i;
	glColor3f(0.486, 0.988, 0.000);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Strl(GLint xc,GLint yc,int r)
{
		Sleaves(xc,yc,r);
}

void Sdustbin()
{
	//stripes
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(75,180);
	glVertex2f(75,245);
	glVertex2f(85,245);
	glVertex2f(85,180);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(95,180);
	glVertex2f(95,245);
	glVertex2f(105,245);
	glVertex2f(105,180);
	glEnd();
	//cap
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(65,247);
	glVertex2f(60,250);
	glVertex2f(118,260);
	glVertex2f(113,255);
	glEnd();
	//cap1
	glColor3f(1.000, 0.549, 1.000);
	glBegin(GL_POLYGON);
	glVertex2f(84,255);
	glVertex2f(84,260);
	glVertex2f(88,260);
	glVertex2f(88,255);
	glEnd();
	//body
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,180);
	glVertex2f(70,245);
	glVertex2f(110,245);
	glVertex2f(110,180);
	glEnd();
}
void S_oil()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(280,80);
	glVertex2f(310,75);
	glVertex2f(350,80);
	glVertex2f(310,85);
	glEnd();
}
void Sdrum1()
{
	//stripes
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(299,135);
	glVertex2f(299,137.5);
	glVertex2f(331,137.5);
	glVertex2f(331,135);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,95);
	glVertex2f(300,97.5);
	glVertex2f(330,97.5);
	glVertex2f(330,95);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,120);
	glVertex2f(300,122.5);
	glVertex2f(330,122.5);
	glVertex2f(330,120);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(299,80);
	glVertex2f(299,82.5);
	glVertex2f(331,82.5);
	glVertex2f(331,80);
	glEnd();
	//body
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,80);
	glVertex2f(300,135);
	glVertex2f(330,135);
	glVertex2f(330,80);
	glEnd();
}
void Sdrum2()
{		
	S_oil();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(247,111.5);
	glVertex2f(251,111.5);
	glVertex2f(251,79);
	glVertex2f(247,79);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(270,110.5);
	glVertex2f(275,110.5);
	glVertex2f(275,80);
	glVertex2f(270,80);
	glEnd();
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,110.5);
	glVertex2f(250,110.5);
	glVertex2f(250,80);
	glVertex2f(300,80);
	glEnd();
}
void Ssymbol(int x,int y,int r)
{
	GLint i;
	glColor3f(0,0,0);
	glPointSize(0.1);
	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Strl1(GLint xc,GLint yc,int r)
{
	Ssymbol(xc,yc,r);
}

void Sdanger1()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(312,102);
	glVertex2f(318,102);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(307,113.5);
	glVertex2f(313,116.4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(317,116.4);
	glVertex2f(323,113.5);
	glEnd();
}
void Sdanger2()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(286,88.3);
	glVertex2f(290,88.3);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(296,98.5);
	glVertex2f(292,101.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(284,101.5);
	glVertex2f(280,98.5);
	glEnd();
}

void Ssatellite()
{
	glColor3f(0.184, 0.310, 0.310);
	glBegin(GL_POLYGON);
	glVertex2f(270,155);
	glVertex2f(340,155);
	glVertex2f(340,160);
	glVertex2f(270,160);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(285,160);
	glVertex2f(305,230);
	glVertex2f(325,160);
	glVertex2f(285,160);
	glEnd();
	//bars
	glBegin(GL_POLYGON);
	glVertex2f(287.5,170);
	glVertex2f(288.5,173);
	glVertex2f(321.5,173);
	glVertex2f(322.5,170);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(291.5,182);
	glVertex2f(292.5,185);
	glVertex2f(318,185);
	glVertex2f(319,182);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(295,194);
	glVertex2f(296,197);
	glVertex2f(314.5,197);
	glVertex2f(315.5,194);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(298.5,206);
	glVertex2f(299.5,209);
	glVertex2f(311,209);
	glVertex2f(312,206);
	glEnd();
	//stick
	glBegin(GL_POLYGON);
	glVertex2f(305,230);
	glVertex2f(280,228);
	glVertex2f(280,233);
	glVertex2f(332,236);
	glVertex2f(332,232);
	glVertex2f(305,230);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(285,160);
	glVertex2f(280,228);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(332,236);
	glVertex2f(338,248);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(332,234);
	glVertex2f(344,234);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(332,236);
	glVertex2f(331,252);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(332,233);
	glVertex2f(340,225);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(332,231);
	glVertex2f(333,218);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(331,252);
	glVertex2f(338,248);
	glVertex2f(344,234);
    glVertex2f(340,225);
	glVertex2f(333,218);
	glEnd();
}
void cloud(int x,int y,int r)
{
	GLint i;
	glColor3f(0.000, 0.545, 0.545);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void clouds(GLint xc,GLint yc,int r)
{
		cloud(xc,yc,r);
}
void Sbolt()
{
	glColor3f(0.000, 0.808, 0.820);
	glBegin(GL_POLYGON);
	glVertex2f(200,290);
	glVertex2f(210,290);
	glVertex2f(200,275);
	glVertex2f(190,275);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(195,275);
	glVertex2f(205,275);
	glVertex2f(195,260);
	glVertex2f(185,260);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(190,260);
	glVertex2f(200,260);
	glVertex2f(180,240);
	glEnd();
}
void Sclouds()
{
	Sbolt();
	cloud(200,260,15);
	cloud(180,265,15);
	cloud(190,275,15);
	cloud(220,265,15);
	cloud(210,275,15);
	cloud(68,185,5);
	cloud(65,180,5);
	cloud(73,178,5);
	cloud(110,178,5);
	cloud(118,180,5);
	cloud(115,185,5);
	cloud(185,230,3);
	cloud(200,235,3);
	cloud(170,240,3);
	cloud(215,230,3);
	cloud(225,240,3);
	cloud(200,220,3);
}
void SDisp2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();	
	glTranslated(25,40,0);
	glScaled(1.3,1.3,0);
	Sclouds();
	Ssatellite();
	Strl1(288,95,8);
	Sdanger2();
	Sdanger1();	
	Strl1(315,110,8);
	Sdrum2();
	Sdrum1();
	Sdustbin();
	Strees();
	Sbase();
	Sbattery2();
	Sbattery1();
	Scircle();
	glPopMatrix();
	backdrop(7);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(lastpage_S);
	}
	glutPostRedisplay();
	glFlush();
}
void SDisp1()
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();	
	glTranslated(25,40,0);
	glScaled(1.3,1.3,0);
	cloud(200,260,15);
	cloud(180,265,15);
	cloud(190,275,15);
	cloud(220,265,15);
	cloud(210,275,15);
	Ssatellite();
	Sdanger1();
	Strl1(315,110,8);
	Sdrum1();
	Sdustbin();
	Strl(240,150,15);
	Strl(235,155,15);
	Strl(245,170,15);
	Strl(200,155,15);
	Strl(225,150,15);
	Strl(210,140,15);
	Strl(225,170,20);
	Strl(160,155,15);
	Strl(185,150,15);
	Strl(170,140,15);
	Strl(185,170,20);
	Strl(120,155,15);
	Strl(145,150,15);
	Strl(130,140,15);
	Strl(145,170,20);
	Strees();
	Sbase();
	Sbattery1();
	Scircle();
	glPopMatrix();
	backdrop(37);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(SDisp2);
	}
	glutPostRedisplay();
	glFlush();
}

void Smouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		sp=1;
	}
}

void Skeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			sp=1;
		}
}

void firstpage_S()
{	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	PrintText(160,200,f4,17,"SOIL POLLUTION");
	backdrop(17);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(SDisp1);	
	}
    glutPostRedisplay();
	glFlush();
}
void soilpollutioninit()
{	
	glutDisplayFunc(firstpage_S);
	glutMouseFunc(Smouse);
	glutKeyboardFunc(Skeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
/*<<<<<<<<-------------------------------------------------------MAIN WINDOW------------------------------------------>>>>>>>>>>*/

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		j=1;
	}
}

void keys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}
	if(key==13 || key==32) //enter key value
		{
			j=1;
		}
}

void firstpage_M()
{	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	PrintText(230,175,f4,18,"Mr.Lokesh H.D");
	PrintText(165,410,f4,38,"SRI KRISHNA INSTITUTE OF TECHNOLOGY");
	PrintText(165,390,f4,18,"Department of Computer Science and Technology");
	PrintText(125,340,f4,18,"\"TYPES OF POLLUTION AND ITS EFFECTS ON HUMAN BODY\"");
	PrintText(235,270,f4,18,"Submitted by");
	PrintText(120,250,f4,18,"RudraGowda M.Patil");
	PrintText(120,230,f4,18,"1KT14CS068");
	PrintText(320,250,f4,18,"Subramanya H.P");
	PrintText(320,230,f4,18,"1KT14CS081");
	PrintText(220,200,f4,18,"Under the guidance of");
	PrintText(230,175,f4,18,"Mr.Lokesh H.D");

	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.863, 0.863);
	glVertex2f(0,0);
	glVertex2f(0,568);
	glVertex2f(125,568);
	glVertex2f(125,0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.686, 0.933, 0.933);
	glVertex2f(250,375);
	glVertex2f(200,340);
	glVertex2f(250,300);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.753, 0.753, 0.753);
	glVertex2f(250,300);
	glVertex2f(300,260);
	glVertex2f(250,225);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.753, 0.753, 0.753);
	glVertex2f(125,0);
	glVertex2f(125,568);
	glVertex2f(250,568);
	glVertex2f(250,0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.686, 0.933, 0.933);
	glVertex2f(250,0);
	glVertex2f(250,568);
	glVertex2f(375,568);
	glVertex2f(375,0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.878, 1.000, 1.000);
	glVertex2f(375,0);
	glVertex2f(375,568);
	glVertex2f(500,568);
	glVertex2f(500,0);
	glEnd();
	if(j)
	{
		j=0;
		glutDestroyWindow(win0);
		window1();
	}
    glutPostRedisplay();
	glFlush();
}
void FinalPage()
{	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	backdrop(13);
	PrintText(220,250,f4,17,"THANK YOU..!");
	glutPostRedisplay();
	glFlush();
}
void reshape1(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,450);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void reshape2(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void FinalWindow()
{	
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	win1=glutCreateWindow("win1");
	glutReshapeFunc(reshape1);
	glutDisplayFunc(FinalPage);
}

void Hmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		hb=1;
	}
}

void Hkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			hb=1;
		}
		switch(key)
		{
		case 'a':
		case 'A': flag=1;
					break;
		case 'n':
		case 'N': flag=2;
					break;
		case 'w':
		case 'W': flag=3;
					break;
		case 's':
		case 'S': flag=4;
					break;
		case 'e':
		case 'E': FinalWindow();
				
		default: flag=0;
		}
}

void Main2Windowinit()
{	
	glutReshapeFunc(Hreshape);
	HinitGL();
	glutIdleFunc(Hdisplay);
	glutDisplayFunc(Hdisplay);
	glutMouseFunc(Hmouse);
	glutTimerFunc(0, timer, 0);  
	glutKeyboardFunc(Hkeys);
	glutPostRedisplay();
	glutMainLoop();
}
void MainWindowinit()
{	
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutReshapeFunc(reshape1);
	glutDisplayFunc(firstpage_M);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,1.0);
	glutMainLoop();
}
void Introduction(GLint sizex,GLint sizey,GLint posx,GLint posy)
{
	glutInitWindowSize(sizex,sizey);//420,900
	glutInitWindowPosition(posx,posy);//474,0
	win0=glutCreateWindow("INTRODUCTION");
	MainWindowinit();
}
void HUMANBODY()
{	
	glutInitWindowSize(420,900);
	glutInitWindowPosition(474,0);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("HUMAN BODY");
	Main2Windowinit();
}
void window1()
{	
	glutInitWindowSize(450,350);
	glutInitWindowPosition(0,0);
	win1=glutCreateWindow("Air Pollution");
	glutReshapeFunc(reshape1);
	airpollutioninit();
}
void window2()
{	
	glutInitWindowSize(450,350);
	glutInitWindowPosition(910,0);
	win2=glutCreateWindow("Noise Pollution");
	glutReshapeFunc(reshape1);
	NoisePollutioninit();
}
void window3()
{	
	glutInitWindowSize(450,350);
	glutInitWindowPosition(0,340);
	win3=glutCreateWindow("Water Pollution");
	glutReshapeFunc(reshape2);
	waterpollutioninit();
}
void window4()
{	
	glutInitWindowSize(450,350);
	glutInitWindowPosition(910,340);
	win4=glutCreateWindow("Soil Pollution");
	glutReshapeFunc(reshape2);
	soilpollutioninit();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	Introduction(1366,768,0,0);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}