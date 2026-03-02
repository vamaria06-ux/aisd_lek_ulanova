#include <cstddef>
#include <string>
#include <iostream>
template <class T>
struct Bilist 
{
  T val;
  Bilist<T>* next;
  Bilist<T>* prev;
};
// Задача 1 неявный интерфейс шаблона 
// Конструктор копирования
// Оператор присваивания
// Деструктор

// Задача 2 упрощенный интерфейс
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
template <class T, class F>
F traverse (F f, Bilist<T>* h, Bilist<T>* e);


// Задача 3  реализация упрощенного интерфейса
template <class T>
Bilist<T>* add(Bilist<T>* h, const T&v)
{
  Bilist<T>* node = new Bilist<T>{v,nullptr,nullptr};
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
  if (h -> next == h)
  {
    delete h;
    return nullptr;
  }
  Bilist<T>* ret = h -> next;
  Bilist<T>* tail = h -> prev;
  tail-> next = ret;
  ret -> prev = tail;
  delete h;
  return ret;
};

template <class T>
Bilist<T>* erase(Bilist<T>* h) noexcept
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
template <class T, class F>
F traverse (F f, Bilist<T>* h, Bilist<T>* e)
{
  if (!h) return f;
  f(h -> val);
  Bilist<T>* p = h -> next;
  while (p != h )
  {
    f(p -> val);
    p = p -> next;
  }
  return f;
};
struct sum
{
  std::string result = "";
  void operator() (char c)
  {
    result += c;
  }
};
//Задача 4  массив конвертируется в список
template<class T>
Bilist<T>* insert(Bilist<T>* h, const T* arr, size_t n)
{
  if (n == 0)  return h;
  h = add(h, arr[0]);

  Bilist<T>* p = h;

  for (size_t i = 1; i < n; ++i)
  {
    p = insert(p, arr[i]);
  }
  return h;
};


using n_t = Bilist<char>;
int main()
{
  n_t* a = add<char>(nullptr, 'A');
  n_t* head = a;

  n_t* b = insert(a,'B');
  n_t* c = insert(b,'C');

  sum s = traverse(sum{},head,head);
  std::cout << s.result << "\n";
  clear(head, head);

  char arr[] = {'a','b','c','d'};
  size_t n = 4;
  n_t* h = nullptr;
  h = insert(h, arr, n);
  sum su = traverse(sum{},h,h);
  std::cout << su.result << "\n";
  clear(h, h);


}
