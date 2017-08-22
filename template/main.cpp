#include <iostream>
using namespace std;
#include "class_template.h"

int main(){
  myClass<int ,int> class1(3,5,6.5);
  class1.show();
  myClass<int ,double> class2(3,4,6.5);
  class2.show();

  return 0;
}
