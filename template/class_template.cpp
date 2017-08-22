#include "class_template.h"
template<typename T1, typename T2>
myClass<T1,T2>::myclass(T1 a, T2 b, double t):I(a),J(b),tr(t){}

template<typename T1, typename T2>
myClass<T1,T2>::show(){
cout<<I<<", "<<this->J<<"  "<<tr<<endl;
}
