#ifndef FLATARRAY_H
#define FLATARRAY_H
#include <type_traits>
template <class T>

class FlatArray
{
public:
    T* array;
    int xsize;
    int ysize;
    int zsize;
    int pos = 0;

    FlatArray(T* container, int pos)
    {
        this->array = container;
        this->pos = pos;
    }

    const FlatArray& operator++()
    {
        ++pos;
        // although not strictly necessary for a range-based for loop
        // following the normal convention of returning a value from
        // operator++ is a good idea.
        return *this;
    }
    bool operator!=(const FlatArray& other) const
    {
        return pos != other.pos;
    }

    T& operator*() const
    {
        return this->array[pos];
    }

    FlatArray begin() const
    {
        return FlatArray(array, 0);
    }

    FlatArray end() const
    {
        return FlatArray(array, xsize * ysize * zsize - 1);
    }

    FlatArray(int xsize, int ysize, int zsize)
    {
        array = new T[xsize * ysize * zsize];
        this->xsize = xsize;
        this->ysize = ysize;
        this->zsize = zsize;
    }

    ~FlatArray()
    {

        delete[] array;
    }

    int conversion(int x, int y, int z)
    {
        return x + xsize * (y + z * ysize);
    }

    T getElement(int x, int y, int z)
    {
        return array[conversion(x, y, z)];
    }
    void setElement(int x, int y, int z, T t)
    {

        if(array[conversion(x, y, z)] == NULL) {
            array[conversion(x, y, z)] = t;
        } else {
            T spare = replaceElement(x, y, z, t);
            delete spare;
        }
    }
    T replaceElement(int x, int y, int z, T t)
    {
        T replace = array[conversion(x, y, z)];
        array[conversion(x, y, z)] = t;
        return replace;
    }
};

#endif // FLATARRAY_H
