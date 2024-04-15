#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

namespace Graphics {
  class Table  {
  public:  
    void displayTable () {
      cout <<"Guide:       * Common    + Sometimes/Rarely    - NO"<< endl
           <<"========================================================"<< endl
           <<"|Symptoms                |  COVID-19  |  Cold  |  Flu  |"<< endl
           <<"|======================================================="<< endl
           <<"|Fever                   |      *     |    +   |   *   |"<< endl
           <<"|Cough                   |      *     |    +   |   *   |"<< endl
           <<"|Shortness of Breath     |      *     |    -   |   -   |"<< endl
           <<"|Runny Nose              |      +     |    *   |   +   |"<< endl
           <<"|Headaches               |      +     |    +   |   *   |"<< endl
           <<"|Sneezing                |      -     |    *   |   -   |"<< endl
           <<"|Fatigue                 |      +     |    +   |   *   |"<< endl
           <<"========================================================"<< endl;
  }
 };
}

namespace Program {
  class SymptomChecker {  
  public:
  int covid19 = 0, cold = 0, flu  = 0;   
    void symptomGenerator(int patients) {
      srand(time(nullptr));
      for (int i = 0; i < patients; i++) {
        int fever = rand() % 2;
        int cough = rand() % 2;
        int shortnessOfBreath = rand() % 2;
        int runnyNose = rand() % 2;
        int headaches = rand() % 2;
        int sneezing = rand() % 2;
        int fatigue = rand() % 2;
//Covid-19 check          
          if(fever == 1 && cough == 1 && shortnessOfBreath == 1 && sneezing == 0) {
            covid19++;
          }   
//Cold check
          if(shortnessOfBreath == 0 && runnyNose == 1 && sneezing == 1) {
            cold++;
          }
//Flu check
          if(fever == 1 && cough == 1 && shortnessOfBreath == 0 && headaches == 1 && sneezing == 0 && fatigue == 1) {
            flu++;
          }
   }      
  }     
 };  
}

int main(void)
{
int covid19, cold, flu, patients;
Graphics::Table newTable;
newTable.displayTable();

cout << "patient number?" << endl;
cin >> patients;

Program::SymptomChecker newSymptomChecker;
newSymptomChecker.symptomGenerator(patients);

cout << covid19 << endl;
cout << cold << endl;
cout << flu << endl;








return 0;
}