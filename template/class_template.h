#ifndef CLASS_TEMPLATE_HH
#define CLASS_TEMPLATE_HH


//模板类的方法实现须在头文件中实现
template<typename T1, typename T2>
class myClass{

private:

     T1 I;

     T2 J;

     double tr;

public:

     myClass(T1 a, T2 b, double t):I(a),J(b),tr(t){}//Constructor

     void show(){
cout<<I<<", "<<this->J<<"  "<<tr<<endl;
}

};
#endif
