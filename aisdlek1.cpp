#include <cstddef>
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
};

template <class T>
Bilist<T>* insert(Bilist<T>* h, const T&v)
{
  return h -> next = add(h->next,v);
};

template <class T>
Bilist<T>* cut(Bilist<T>* h) noexcept
{
  if(!h)
  {
    return nullptr;
  }
  if (h -> next = h)
  {
    delete h;
    return nullptr;
  }
  Bilist<T>* ret = h -> next;
  Bilist<T>* tail = h -> prev;
  tail-> next = ret;
  ret -> next = tail;
  delete h;
  return ret;
};

template <class T>
Bilist<T>* erase(List<T>* h) noexcept
{
  if (!h || h->next == h)
  {
    return h;
  }
  return h -> next = cut (h -> next);
};

template <class T>
Bilist<T>* clear(Bilist<T>* h, Bilist<T>* e) noexcept
{
  while (h != e)
  {
    h = cut(h);
  }
  return h;
};
// массив конвертируется в список
template<class T>
Bilist<T>* insert(Bilist<T>* h, const T* arr, size_t n)
{
  for (size_t i = 0; i < n; ++i)
  {
    h = insert(h, arr[i]);
  }
  return h;
};

int main()
{}
