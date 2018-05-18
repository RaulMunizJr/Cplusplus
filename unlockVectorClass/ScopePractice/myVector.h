//
//  myVector.h
//  Assignment #6
//
//  Created by Raul Muniz on 2/16/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef myVector_h
#define myVector_h

template <class T>

class vector
{
public:
    typedef T* Iterator;
    vector();
    vector(int size);
    vector(int size, const T & initial);
    vector(const vector<T>& v);
    ~vector();
    void push_back(const T& value);
    void pop_back();
    int capacity() const;
    int size() const;
    void clear();
    bool empty() const;
    Iterator begin();
    Iterator end();
    T& front();
    T& back();
    void resize(int size);
    T & operator[](int index);
    vector<T> & operator = (const vector<T> &);
    
private:
    int count;
    int max_size;
    T *arr;
};

template<class T>
vector<T>::vector()
{
    max_size = 0;
    count = 0;
    arr = 0;
}

template<class T>
vector<T>::vector(const vector<T> & v)
{
    count = v.count;
    max_size = v.max_size;
    arr = new T[max_size];
    for (int i = 0; i < max_size; i++)
        arr[i] = v.arr[i];
}

template<class T>
vector<T>::vector(int size)
{
    count = size;
    max_size = size;
    arr = new T[max_size];
    for(int i = 0; i < max_size; i++)
        arr[i] = 0;
}

template <class T>
bool vector<T>:: empty() const
{
    return count == 0;
}

template<class T>
vector<T>::vector(int size, const T& initial)
{
    count = size;
    max_size = count;
    arr = new T [max_size];
    for (int i = 0; i < size; i++)
        arr[i] = initial;
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T> & v) {
    delete[] arr;
    count = v.count;
    max_size = v.max_size;
    arr = new T [max_size];
    for (unsigned int i = 0; i < count; i++)
        arr[i] = v.arr[i];
    return *this;
}

template<class T>
typename vector<T>::Iterator vector<T>::begin()
{
    return arr;
}

template<class T>
typename vector<T>::Iterator vector<T>::end()
{
    return arr + size();
}

template<class T>
T& vector<T>::front()
{
    return arr[0];
}

template<class T>
T& vector<T>::back()
{
    return arr[count - 1];
}

template<class T>
void vector<T>::push_back(const T & v)
{
    if (count >= max_size)
    {
        resize(count);
    }
    arr[count++] = v;
}

template<class T>
void vector<T>::pop_back()
{
    count--;
}

template<class T>
int vector<T>::size() const {
    return count;
}

template<class T>
void vector<T>::resize(int n)
{
    int newSize = n + (n / 2);
    T *newBuff = new T[newSize];
    for(int i = 0; i < newSize; i++)
    {
        if(i < size())
            newBuff[i] = arr[i];
        else
            newBuff[i] = 0;
    }
    
    delete [] arr;
    
    arr = new T[newSize];
    for(int i = 0; i < newSize; i++)
        arr[i] = newBuff[i];
    
    count = count;
    max_size = newSize;
}

template<class T>
T& vector<T>::operator[](int index)
{
    return arr[index];
}

template<class T>
int vector<T>::capacity()const
{
    return max_size;
}

template<class T>
vector<T>::~vector()
{
    delete[] arr;
}

template <class T>
void vector<T>::clear()
{
    max_size = 0;
    count = 0;
    arr = 0;
}
#endif /* myVector_h */
