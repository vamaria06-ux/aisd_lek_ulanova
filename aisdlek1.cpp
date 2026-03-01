template <class T>
struct Bilist 
{
  T val;
  Bilist<T>* next;
  Bilist<T>* prev;
};
// неявный интерфейс
template <class T>
Bilist<T>* add(Bilist<T>* h, const T& v);
template <class T>
Bilist<T>* insert(Bilist<T>* h, const T& v);
template <class T>
Bilist<T>* cut(Bilist<T>* h) noexcept;
template <class T>
Bilist<T>* erase(Bilist<T>* h) noexcept;
template <class T>
Bilist<T>* clear(Bilist<T>* h, Bilist<T>* e) noexcept;
// упрощенный интерфейс

//
template <class T>
Bilist<T>* add(Bilist<T>* h, const T&v)
{
  Bilist<T>* node = new Bilist<T>{v,,nullptr,nullptr};
  if (!h)
  {
    node -> prev = node;
    node -> next = node;
    return node;
  }
  Bilist<T>* tail = h -> prev;
  node -> next = h;
  node -> prev = tail;
  tail -> next = node;
  h -> prev = node;
  return node;
}

int main()
{}
