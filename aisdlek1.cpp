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
int main()
{}
