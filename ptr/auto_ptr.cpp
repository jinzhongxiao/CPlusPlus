#include <iostream>
using namespace std;
/*
我们看到当通过复构造函数,通过操作符=赋值后,原来的那个智能指针对象就失效了.只有新的智能指针对象可以有效使用了.用个专业点的说法叫所有权的转移.
被包装的指针指向的内存块就像是一份独享占用的财产,当通过复制构造,通过=赋值传给别的智能指针对象时,原有的对象就失去了对那块内存区域的拥有权.也
就是说任何时候只能有一个智能指针对象指向那块内存区域,不能有两个对象同时指向那块内存区域.

这样一来auto_ptr不能做为STL中容器的元素,为啥呢? 因为容器中经常存在值拷贝的情况嘛,把一个容器对象直接赋值给另一对象.完了之后两个容器对象可得
都能用啊.而如果是auto_ptr的话显然赋值后只能一个有用,另一个完全报废了.另外比如你有个变量auto_ptr<int> ap( new int(44) );  然后ap被放进
一个容器后,ap就报废不能用了.
*/
template<class T>
class my_auto_ptr{
  private:
    T* m_ptr;
    T* GetPtr(){
      T*tmp = m_ptr;
      m_ptr = 0;
      return tmp;
    }

  public:
    explicit my_auto_ptr(T *p=0):m_ptr(p){}
    ~my_auto_ptr(){delete m_ptr;}

    T& operator*(){return *m_ptr;}
    T* operator->(){return m_ptr;}

    my_auto_ptr(my_auto_ptr& mp){
      m_ptr = mp.GetPtr();
    }

    my_auto_ptr& operator=(my_auto_ptr& ap){
      if(ap!=this){
        delete m_ptr;
        m_ptr = ap.GetPtr();
      }
      return *this;
    }

    void reset(T* p){
      if(p!=m_ptr)
      delete m_ptr;
      m_ptr = p;
    }
};


struct Arwen{
  int age;
  Arwen(int gg):age(gg){};
};
int main(int argc, char ** argv){

  my_auto_ptr<Arwen> myPtr(new Arwen(24));
  int num = myPtr->age;
  cout<<num<<endl;;

  my_auto_ptr<Arwen> ptrOne(myPtr);
  num = ptrOne->age;
  cout<<num<<endl;;

  my_auto_ptr<Arwen> ptrTwo= ptrOne;
  cout<<num<<endl;;

  Arwen* pArwen = new Arwen(8);
  ptrTwo.reset(pArwen);
  num = ptrTwo->age;
  cout<<num<<endl;;

  return 0;
}
