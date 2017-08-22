
/*
shared_ptr类型的智能指针可以做为STL容器的元素
*/
#include <vector>
#include <iostream>
//#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
//using namespace boost;
using namespace std;

template<class T>
class myshared_ptr{
private:
  typedef int count_type;
public:
  explicit myshared_ptr(T * p=0):px(p){
    pn = new count_type(1);
  }
  ~myshared_ptr(){

    if(--*pn == 0){
      delete px;
      delete pn;
    }
  }

  T& operator*(){return *px;}
  T* operator->(){return px;}
  myshared_ptr(myshared_ptr const & r):px(r.px), pn(r.pn){++*pn;}
  myshared_ptr & operator=(myshared_ptr const &r){
    if(this!=&r){
      pn = r.pn;
      px = r.px;
      ++*pn;

    }
    return *this;
  }
  void echo(){
    cout<<*pn<<endl;
  }
private:
  T* px;
  count_type* pn;

};
int main(int argc, char** argv){


    myshared_ptr<int> pos(new int(3));
    cout<<"pos的初始值:"<<*pos<<endl;
    cout<<"pos的计数值：";
    pos.echo();
    myshared_ptr<int> p1 = pos;
    cout<<"复制后，pos的计数值：";
    pos.echo();
    cout<<"复制后，p1的计数值：";
    p1.echo();

    myshared_ptr<int> p2(pos);
    cout<<"赋值后，pos的计数值：";
    pos.echo();
    cout<<"赋值后，p2的计数值：";
    p2.echo();

    p1.~myshared_ptr();

    cout<<"p1析构，pos, p1, p2的计数值："<<endl;;
    cout<<"pos计数值：";pos.echo();
    cout<<"p1计数值：";p1.echo();
    cout<<"p2计数值：";p2.echo();
    cout<<"p1再析构："<<endl;
    p1.~myshared_ptr();
    cout<<"pos计数值：";pos.echo();
    cout<<"p1计数值：";p1.echo();
    cout<<"p2计数值：";p2.echo();
    cout<<"pos = "<<*pos<<endl;
    cout<<"p1 = "<<*p1<<endl;
    cout<<"p2 = "<<*p2<<endl;
    p1.~myshared_ptr();
    cout<<"p1再析构，释放指针,得出的值!=3, 造成错误："<<endl;
    cout<<"pos = "<<*pos<<endl;
    cout<<"p1 = "<<*p1<<endl;
    cout<<"p2 = "<<*p2<<endl;
    //pos.echo();
    /*shared_ptr<int> p1 = pos;
    *p1 = 10;
    cout<<"sharedArray[5]经过赋值后的值:"<<*sharedArray[5]<<endl;
    cout<<"sharedArray[5]赋值后的引用计数为："<<p1.use_count()<<endl;
    shared_ptr<int> p2(sharedArray[5]);
    cout<<"p[2]复制和赋值后的引用计数为："<<p2.use_count()<<endl;
    cout<<"sharedArray[5]的地址："<<sharedArray[5]<<"，p1的地址："<<p1<<"，p2的地址："<<p2<<endl;
    *p2 = 5;
    cout<<"sharedArray[5]经过复制后的值:"<<*sharedArray[5]<<endl;
*/


  return 0;
}
