#include <iostream>
#include <list>
using namespace std;


template <class T>
class LexCompere{
 public:
       int operator() (const T& p1, const T& p2) const
       {
             return p1 < p2;
       }
};

template <class E, template<class> class C>
class ListPriorityQueue{
public:
      int size() const;
      bool empty() const;
      void insert(const E& e);
      const E& min() const;
      void removeMin();
      void print();
private:
      list<E> L;
      C<E> isLess;
};

template< class E, template < class> class C>
int ListPriorityQueue<E,C>::size() const
{
      return L.size();
}

template<class E, template<class> class C>
bool ListPriorityQueue<E, C>::empty() const
{
      return L.empty();
}


template<class E, template<class> class C>
void ListPriorityQueue<E, C>::insert(const E& e)
{
      typename list<E>::iterator p;
      p = L.begin();

      while(p!=L.end() && !isLess(e, *p))
            ++p;
            L.insert(p, e);
}


template<class E, template<class> class C>
const E& ListPriorityQueue<E, C>::min() const
{
      L.front();
}

template<class E, template<class> class C>
void ListPriorityQueue <E,C>::removeMin()
{
      L.pop.front();
}


template<class E, template<class> class C>
void ListPriorityQueue<E, C>:: print()
{
      typename list<E>::iterator p;
      for(p = L.begin(); p!=L.end(); ++p)
            cout << '\t' << *p;
      cout << '\n';
}
int main(){
    ListPriorityQueue<int, LexCompere> pQ1;
    ListPriorityQueue<int, LexCompere> pQ2;
    pQ1.insert(666);
    pQ1.insert(543);
    pQ1.insert(45);
    pQ1.insert(45);
    pQ1.insert(1);
    pQ1.insert(3);
    pQ1.insert(5);
    pQ1.insert(1);
    pQ1.insert(43);
    pQ1.insert(22);
    pQ1.insert(4);
    cout << "pQ1: ";
    pQ1.print();
    cout<< endl;
    return 0;
}
