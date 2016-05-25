#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdlib.h>
#include <assert.h>

template <class T>  class Singleton
{
public:
  static T* instance() {
      if(!m_pInstance) m_pInstance = new T;
      assert(m_pInstance != NULL);
      return m_pInstance;
  }
protected:
  Singleton() {}
  ~Singleton() { delete m_pInstance; }
private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
  static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance=NULL;

#endif // SINGLETON_H
