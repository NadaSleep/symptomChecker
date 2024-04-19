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
  int covid19 = 0;   
  int cold = 0;
  int flu = 0;
  int patients = 0;

    void symptomGenerator(int patients) {
      srand(time(nullptr));
      for (int i = 0; i < patients; i++) {        
        bool fever = rand() % 2 == 1;
        bool cough = rand() % 2 == 1;
        bool shortnessOfBreath = rand() % 2 == 1;
        bool runnyNose = rand() % 2 == 1;
        bool headaches = rand() % 2 == 1;
        bool sneezing = rand() % 2 == 1;
        bool fatigue = rand() % 2 == 1;
//Covid-19 check          
          if(fever == true && cough == true && shortnessOfBreath == true && sneezing == false) {
            covid19++;
          }   
//Cold check
          if(shortnessOfBreath == false && runnyNose == true && sneezing == true) {
            cold++;
          }
//Flu check
          if(fever == true && cough == true && shortnessOfBreath == false && headaches == true && sneezing == false && fatigue == true) {
            flu++;
          }
        //fever = 0, cough = 0, shortnessOfBreath = 0, runnyNose = 0, headaches = 0, sneezing = 0, fatigue = 0;
   }      
  }     
 };  
}

int main(void)
{
int patients;
Graphics::Table newTable;
newTable.displayTable();

cout << "What is the number of patients?" << endl;
cin >> patients;

Program::SymptomChecker newSymptomChecker;
newSymptomChecker.symptomGenerator(patients);

cout <<"COVID-19: "<< newSymptomChecker.covid19 << endl;
cout <<"COLD: "<< newSymptomChecker.cold << endl;
cout <<"FLU: "<< newSymptomChecker.flu << endl;

return 0;
}