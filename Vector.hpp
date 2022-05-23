#ifndef VECTOR
#define VECTOR

template <typename TYPE>
class Vector
{
public:
    typedef unsigned int dim_type;
    
    Vector() : _vector(nullptr), _dim(0), _freeSpace(0) {}

    Vector(int d) {
        try{
            _vector = new TYPE[d];
            _dim = d;
            _freeSpace = d;
        }
        catch(...){
            delete _vector;
            _dim = 0;
            _freeSpace = 0;
        }
    }

    Vector(const Vector &other) {
        try{
            _vector = new TYPE[other._dim];
            for(TYPE i = 0; i < other._dim; ++i){
                _vector[i] = other._vector[i];
            }
            _dim = other._dim;
            _freeSpace = other._freeSpace;
        }
        catch(...){
            delete _vector;
            _vector = nullptr;
            _dim = 0;
            _freeSpace = 0;
        }
    }

    Vector addElement(const TYPE &newElement){
        if(_freeSpace > 0){
            _vector[_dim - (_freeSpace + 1)] = newElement;
        }
        else{
            Vector tmp(*this);
            try{
                clear(*this);
                Vector newVector(tmp._dim * 2);
                for(dim_type i = 0; i < this._dim; ++i){
                    newVector._vector[i] = tmp._vector[i];
                }
                newVector._dim = tmp._dim;
                newVector._freeSpace = tmp._freeSpace;
                clear(tmp);
                return newVector;
            }
            catch(...){
                return tmp;
            }
        }
    }

    ~Vector() {
        delete _vector;
        _vector = nullptr;
        _freeSpace = 0;
        _dim = 0;
    };

    void clear(Vector &vector){
        delete vector._vector;
        vector._vector = nullptr;
        vector._dim = 0;
        vector._freeSpace = 0;
    }

    Vector &operator=(const Vector &other){
        try{
            const Vector tmp(other);
            return tmp;
        }
        catch(...){
            return *this;
        }
    }

private:
    TYPE *_vector;
    dim_type _dim, _freeSpace;
};

#endif