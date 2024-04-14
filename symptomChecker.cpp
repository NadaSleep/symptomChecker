#include <iostream>

using namespace std; 

namespace Graphics {
  class Table  {
  public:  
    void displayTable () {
      cout <<"Guide:       * Common    + Sometimes/Rarely    - NO"<< endl
           <<"======================================================="<< endl
           <<"Symptoms                |  COVID-19  |  Cold  |  Flu  |"<< endl
           <<"======================================================="<< endl
           <<"Fever                   |      *     |    +   |   *   |"<< endl
           <<"Cough                   |      *     |    +   |   *   |"<< endl
           <<"Shortness of Breath     |      *     |    -   |   -   |"<< endl
           <<"Runny Nose              |      +     |    *   |   +   |"<< endl
           <<"Headaches               |      +     |    +   |   *   |"<< endl
           <<"Sneezing                |      -     |    *   |   -   |"<< endl
           <<"Fatigue                 |      +     |    +   |   *   |"<< endl
           <<"======================================================="<< endl;
  }
 };
}



int main(void)
{
Graphics::Table newTable;
newTable.displayTable();










return 0;
}