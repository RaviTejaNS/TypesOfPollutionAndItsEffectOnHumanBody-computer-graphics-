/*<<<<<<<<-------------air pollution--------------->>>>>>>>>*/
extern void slow();
extern void drawrain();
extern void rainmotion();
extern void drawCircle(int l,int m,int col1,float r);
extern void drawsmoke();
extern void carsmoke();
extern void drawcars(int x,int y,int col,float r);
extern void cars();
extern void carmotion();
extern void strips(float dist);
extern void land_road(int col1,int col2);
extern void factory(int col1,int col2);
extern void backdrop(int col);
extern void house(int col1,int col2,int col3,int col4,int col5);
extern void tree(float dist,int col2);
extern void blackclouds2(int col1);
extern void blackclouds1();
extern void drawcloud(int col1);
extern void clouds(int high,int col1);
extern void cloudmotion(int col1);
extern void smokemotion();
extern void firstpage_A(void);
extern void lastpage_A();
extern void display4();
extern void display3();
extern void display2();
extern void display1(void);
extern void APmouse(int btn,int state,int x,int y);
extern void APkeys(unsigned char key,int x,int y);
extern void airpollutioninit();
/*<<<<<<<------------------Noise pollution------------->>>>>>>>*/

extern void PrintText(float x, float y, void* font,int col, char *string);
extern void NPwaves(float x,float y,int col1,float r,int index,int range);
extern void drawcircle(float x,float y,int col1,float r,float num, int index,int range);
extern void NPsounds(float x,float y,int col1,int col2,float r, int seg,float a,float b);
extern void NPCharacter(int ch);
extern void NPMisc();
extern void NPbackdrop(int col);
extern void NPdrawtruck();
extern void NPredcar(int x,int y,int col,int col2,float r);
extern void NPTruckmotion();
extern void NPCar(float x,float y,int col1,int col2);
extern void NPBuildings(int col1,int col2);
extern void NPLand(int col1,int col2);
extern void lastpage_N(void);
extern void firstpage_N(void);
extern void NPScene2(void);
extern void NPScene1(void);
extern void NPmouse(int btn,int state,int x,int y);
extern void NPkeys(unsigned char key,int x,int y);
extern void NoisePollutioninit();
extern void lastpage_W(void);
/*<<<<<<<<----------------water pollution---------------->>>>>>*/

extern void Wsky ();
extern void Wcircle(GLint x,GLint y,GLint r,int col1,int col2);
extern void Wsun();
extern void Wrays();
extern void Wgrass();
extern void Wunderground();
extern void Wpipe2();
extern void Wfactory();
extern void Wpipe();
extern void Wroads();
extern void Wcar(int x);
extern void Wcircles(int x,int y,int r,int col);
extern void Wbubble(int xc,int r, int y,int col);
extern void Wwater(int col);
extern void Wunderpipe1();
extern void Wstripesy(float dist);
extern void Wstripesx(float dist);
extern void Wstripesmall(int dist);
extern void Wstripes(int d,int d1,int d2);
extern void Whouse();
extern void WParc(float x,float y,int col1,float r,int index,int range);
extern void Wfish(int col,int x,int y);
extern void Wfishmotion(int ch);
extern void Wroads2();
extern void Wcar_dumpmotion();
extern void WDisplay2();
extern void WaterPollution();
extern void firstpage_W(void);
extern void WPmouse(int btn,int state,int x,int y);
extern void WPkeys(unsigned char key,int x,int y);
extern void waterpollutioninit();
/*<<<<<<<-----------soil pollution------------>>>>>>>*/
extern void FinalWindow();
extern void lastpage_S(void);
extern void Searth(int x,int y,int r);
extern void Scircle();
extern void Sbattery2();
extern void Sbattery1();
extern void Sbase();
extern void Strees();
extern void Sleaves(int x,int y,int r);
extern void Strl(GLint xc,GLint yc,int r);
extern void Sdustbin();
extern void S_oil();
extern void Sdrum1();
extern void Sdrum2();
extern void Ssymbol(int x,int y,int r);
extern void Strl1(GLint xc,GLint yc,int r);
extern void Sdanger1();
extern void Sdanger2();
extern void Ssatellite();
extern void cloud(int x,int y,int r);
extern void clouds(GLint xc,GLint yc,int r);
extern void Sbolt();
extern void Sclouds();
extern void SDisp2();
extern void SDisp1();
extern void Smouse(int btn,int state,int x,int y);
extern void Skeys(unsigned char key,int x,int y);
extern void firstpage_S();
extern void soilpollutioninit();
extern void FinalPage();
/*<<<<<<<-----------main window-------------->>>>>>>*/

extern void mouse(int btn,int state,int x,int y);
extern void keys(unsigned char key,int x,int y);
extern void lastpage_M(void);
extern void firstpage_M();
extern void reshape1(int w,int h);
extern void reshape2(int w,int h);
extern void mainwindow(GLint sizex,GLint sizey,GLint posx,GLint posy); 
extern void Main2Windowinit();
extern void HUMANBODY();
extern void window1();
extern void window2();
extern void window3();
extern void window4();
extern void MainWindowinit();
extern void FinalWindow();
extern void FinalPage();
/*<<<<<<<<<<<<<<-----------------human body------------------->>>>*/
extern void Hreshape(GLsizei width, GLsizei height);
extern void HinitGL();
extern void timer(int value);
extern void Hdisplay();
extern void Head();
extern void	Body();
extern void	Hands();
extern void	Pant();
extern void	Legs();
extern int flag;






