#include <iostream>
#include <ctime>

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
    int symptomGenerator(int patients) {
      for (int i = 0; i < patients; i++)
      int 
      




  }     
 };  
}












}


int main(void)
{
Graphics::Table newTable;
newTable.displayTable();










return 0;
}