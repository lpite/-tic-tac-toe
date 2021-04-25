#include "iostream"
#include "ctime"
using namespace std;
//перевіряє чи є по горизонталі, вертикалі або діагоналі лінія з 3 символів a
bool line3(char Mat[3][3], char a){
 if(Mat[0][0]==a){
  if(Mat[0][1]==a&&Mat[0][2]==a)return 1;
  if(Mat[1][0]==a&&Mat[2][0]==a)return 1;
  if(Mat[1][1]==a&&Mat[2][2]==a)return 1;
 }
 if(Mat[0][1]==a&&Mat[1][1]==a&&Mat[2][1]==a)return 1;
 if(Mat[0][2]==a){
  if(Mat[1][2]==a&&Mat[2][2]==a)return 1;
  if(Mat[1][1]==a&&Mat[2][0]==a)return 1;
 }
 if(Mat[1][0]==a&&Mat[1][1]==a&&Mat[1][2]==a)return 1;
 if(Mat[2][0]==a&&Mat[2][1]==a&&Mat[2][2]==a)return 1;
 return 0;
}
//перевіряє чи можна виграти гравцю a за 1 хід
//якщо можна, то записує координати виграшного ходу в змінні x і y
bool line2(char Mat[3][3],char a, int& x, int& y){
 for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++){
       if(Mat[i][j]=='_'){
        Mat[i][j]=a;
        if(line3(Mat,a)){
         Mat[i][j]='_';
         x=i;
         y=j;
         return 1;
        }
        Mat[i][j]='_';
       }
      }
      return 0;
}
void DeskGame(char Mat[3][3],char p1, int xr, int yc, bool P1Win, bool P2Win, bool Draw)
{
  char p2;
  if(p1=='x')p2='o';
  else if(p1=='o')p2='x';
  while (P1Win == false && P2Win == false && Draw == false)
  {
    cout<<"   X\n   ↓\nY→  1 2 3\n";
    for (int i = 0; i < 3; i++)
    {
      cout<<"   "<<i+1<<" ";
      for (int j = 0; j < 3; j++){
        cout << Mat[i][j];
        if(j<2)cout<<"|";
      }
      cout << endl;
    }
    cout << "\n    Player" << "\n";
    cout << "Enter position:\n";
    cout<<"X: ";
    cin >> xr;
    cout<<"Y: ";
    cin>> yc;
    Mat[xr - 1][yc - 1] = p1;
    system("cls");

    do
    {
      xr = rand() % 3;
      yc = rand() % 3;
    }while (Mat[xr][yc] != '_');
    Mat[xr][yc] = p2;
  }
}

int main()
{
  srand(time(NULL));
  char Mat[3][3] = {
    {'_','_','_'},
    {'_','_','_'},
    {'_','_','_'} };
  char xr, yc, a;
  bool P1Win = false, P2Win = false, Draw = false;
  cout << "\bHello" << "\n";
  cout << "Enter who're you (x/o): ";
  cin >> a;
  DeskGame(Mat,a, xr, yc, P1Win, P2Win, Draw);
}