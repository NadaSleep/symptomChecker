#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 
// namespace for classes that deal with the visual aspect
namespace Graphics {
// Base class
  class Table  {
  public:  
// Method that displays the table at the start of the program
    void displayTable () {
      cout <<"Guide:       * Common    + Sometimes/Rarely    - NO"<< endl
           <<"========================================================"<< endl
           <<"|Symptoms                |  COVID-19  |  COLD  |  FLU  |"<< endl
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

// Derived class created from the Table class
  class PercentVisual : public Table {
  public:
// Method used to display "+" for every percent
  void displayPercent(int percentNum) {
     int percentVisual = percentNum/1;
        for (int i = 0; i < percentVisual; i++) {
        cout<<"+";
   }
  }
 };
}

// namespace for classes that deal with numbers out of view of the user
namespace Program {
  class SymptomChecker {  
  public:
  int covid19 = 0;   
  int cold = 0;
  int flu = 0;
  int otherIllness = 0;
  int patients = 0;
// Method that randomly generates symptoms for patients
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
   }      
  }     
// Method that will return a percent for whichever illness
   int percent(int illness) {
      double percentNum = static_cast<double>(illness) / patients * 100;
      return static_cast<int>(percentNum);
  }
 };
} 
   


int main(void)
{
int patients;
// Creating an object from the Table class
Graphics::Table newTable;
newTable.displayTable();
// Taking input from the user for patient amount
cout << "What is the number of patients?" << endl;
cin >> patients;
// Creating an object from the SymptomChecker class
Program::SymptomChecker newSymptomChecker;
// Assigning value from user to patients of the SymptomChecker object
newSymptomChecker.patients = patients;
// Calling the symptomGenerator() method
newSymptomChecker.symptomGenerator(patients);
// Creating a variable for Other Illness which will be displayed
int otherIllness = patients - (newSymptomChecker.covid19 + newSymptomChecker.cold + newSymptomChecker.flu);
// Displayed section for patient symptoms
cout <<"--------------------------------"<< endl;
cout <<"Patient Symptoms:"<< endl;
cout <<"----------------"<< endl;
cout <<"COVID-19: " << newSymptomChecker.covid19 << endl;
cout <<"COLD: "<< newSymptomChecker.cold << endl;
cout <<"FLU: "<< newSymptomChecker.flu << endl;
cout <<"Other Illness: "<< otherIllness << endl;
cout <<"--------------------------------"<< endl;
// Creating an object from the PercentVisual class
Graphics::PercentVisual percentGraphics;
// Displayed section for illness percentage
cout <<"Percentage of each Illness:"<< endl;
cout <<"---------------------------"<< endl;
cout  <<"COVID-19:          "<<"["<<newSymptomChecker.percent(newSymptomChecker.covid19)<<"%"<<"]";percentGraphics.displayPercent(newSymptomChecker.covid19);
cout << endl <<"COLD:              "<<"["<<newSymptomChecker.percent(newSymptomChecker.cold)<<"%"<<"]";percentGraphics.displayPercent(newSymptomChecker.cold);
cout << endl <<"FLU:               "<<"["<<newSymptomChecker.percent(newSymptomChecker.flu)<<"%"<<"]";percentGraphics.displayPercent(newSymptomChecker.flu);
cout << endl <<"Other Illness:     "<<"["<<newSymptomChecker.percent(otherIllness)<<"%"<<"]";percentGraphics.displayPercent(otherIllness);

return 0;
}