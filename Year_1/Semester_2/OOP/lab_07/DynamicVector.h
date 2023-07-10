//
// Created by Deea on 4/2/2023.
//

#ifndef LAB_6_DYNAMICVECTO_H
#define LAB_6_DYNAMICVECTO_H
#define INITIAL_CAPACITY 2

template <typename GenericElement>
        class IteratorVector;
template <typename GenericElement>
class DynamicVector{
private:
    GenericElement* genericElements;//this is the vector
    int size;
    int capacity;
    void ensureCapacity([[maybe_unused]] int factor=2);
public:
    //CONSTRUCTOR -implemented
    DynamicVector();
    //DESTRUCTOR - implemented
    ~DynamicVector();
    //COPY VECTOR -implemented
    DynamicVector(const DynamicVector& ot);
    //size

    /**OPERATORS*/
    /**asignare*/
    /*Assignment operator
     * dealocate current object and ensurecapacity for the new elements
     * copies all the elements of other*/
    DynamicVector& operator=(const DynamicVector& ot);
    /**
     * Move constructor
     */
    DynamicVector(DynamicVector &&ot) noexcept;
    //move assignment
    DynamicVector& operator=( DynamicVector&& ot) noexcept;
    //add to vector
    void push_back(const GenericElement& el);
    //get a certian element
    [[maybe_unused]] GenericElement& get(int poz) const;
    //set
    [[maybe_unused]] void set(int poz,const GenericElement& el);
    //size
    [[nodiscard]] int getSize() const noexcept;
    //delete function
    void erase(int position);
    //declare iterator as a friend class
    friend class IteratorVector<GenericElement>;
    //vector iterators
    IteratorVector<GenericElement> begin () const;
    //get last el
    IteratorVector<GenericElement> end() const;
    [[nodiscard]] bool empty() const noexcept;

    [[maybe_unused]] IteratorVector<GenericElement> iterator(){
        return IteratorVector(*this);
    };
    GenericElement& operator[](int poz) const;

};
/**OPERATOR SUBSCRIPTION*/
template<typename  GenericElement>
GenericElement &DynamicVector<GenericElement>::operator[](int poz) const {
    return  genericElements[poz];
}
/**CONSTRUCTOR*/
template<typename GenericElement>
DynamicVector<GenericElement>::DynamicVector():size(0),capacity(INITIAL_CAPACITY) {
    this->genericElements=new GenericElement[INITIAL_CAPACITY];

}
/*
 * COPY CONSTRUCTOR . We copy all elements from the ot to our current one
 */
/** COPY CONSTRUCTOR*/
template<typename GenericElement>
DynamicVector<GenericElement>::DynamicVector(const DynamicVector<GenericElement> &ot) {
    this->genericElements=new GenericElement[ot.capacity];
    //copy elements
    for (int i=0;i<ot.size;i++)
    {
        genericElements[i]=ot.genericElements[i];
    }
    size=ot.size;
    capacity=ot.capacity;
}

/*
 * Asignment operator.
 * Delete everything from the other
 * Copy all
 */
template<typename GenericElement>
bool DynamicVector<GenericElement>::empty() const noexcept {
    return size==0;
}
/*** ASSIGNMENT OPERATOR*/
template<typename GenericElement>
DynamicVector<GenericElement> &DynamicVector<GenericElement>::operator=(const DynamicVector<GenericElement> &ot) {

    if(this==&ot){
        return *this; //ele sunt egale deci nu are rost sa mai faci altceva
    }
    delete [] genericElements;
    genericElements=new GenericElement[ot.capacity];
    //copy all elements
    for (int i=0;i<ot.size;i++)
    {
        genericElements[i]=ot.genericElements[i];
    }
    size=ot.size;
    capacity=ot.capacity;
    return *this;

}
//DESTRUCTOR
template<typename GenericElement>
DynamicVector<GenericElement>::~DynamicVector(){
    delete[] genericElements;
    size=0;
    capacity=0;
}
template<typename GenericElement>
//MOVE CONSTRUCTOR
DynamicVector<GenericElement>::DynamicVector(DynamicVector &&ot) noexcept {
    //Copy data
    genericElements=ot.genericElements;
    size=ot.size;
    capacity=ot.capacity;

    //Release all from the ot
    ot.genericElements= nullptr;
    ot.size=0;
    ot.capacity=0;


}
//Move assignment
template<typename GenericElement>
DynamicVector<GenericElement>& DynamicVector<GenericElement>::operator=(DynamicVector<GenericElement>&& ot) noexcept
{
    if(this==&ot)
    {
        return *this;
    }
    delete [] genericElements;
    //copy all data from the other
    genericElements=ot.genericElements;
    size=ot.size;
    capacity=ot.capacity;

    //release all data from the other ofc because we moved them
    ot.genericElements= nullptr;
    ot.size=0;
    ot.capacity=0;
    return *this;
}

//ALTE OPERATII
template<typename GenericElement>
void DynamicVector<GenericElement>::erase(int position)
{
    this->size--;
    for (int i = position; i < this->size; i++) {
        this->genericElements[i] = this->genericElements[i + 1];
    }
}
template<typename GenericElement>
void DynamicVector<GenericElement>::push_back(const GenericElement &el) {
    ensureCapacity();
    genericElements[size++]=el;
}

//getter
template<typename GenericElement>
[[maybe_unused]] GenericElement &DynamicVector<GenericElement>::get(int poz) const {
    return genericElements[poz];
}

//set

template<typename GenericElement>
[[maybe_unused]] void DynamicVector<GenericElement>::set(int poz, const GenericElement &el) {
    genericElements[poz]=el;
}

//size
template<typename GenericElement>
int DynamicVector<GenericElement>::getSize() const noexcept {
    return size;
}

//ensure capacity

template<typename GenericElement>
void DynamicVector<GenericElement>::ensureCapacity([[maybe_unused]] int factor) {
    if(size<capacity){
        return; //stim sigur ca avem destul spatiu
    }
    capacity*=2;
    auto* aux=new GenericElement[capacity];
    //copiem totul in vectorul now
    for(int i=0;i<size;i++)
    {
        aux[i]=genericElements[i];
    }
    delete [] genericElements;
    genericElements=aux;
}

template<typename GenericElement>
//begin for iterator
IteratorVector<GenericElement> DynamicVector<GenericElement>::begin() const {
    return IteratorVector<GenericElement>(*this);
}

template<typename GenericElement>
//begin for iterator
IteratorVector<GenericElement> DynamicVector<GenericElement>::end() const {
    return IteratorVector<GenericElement>(*this,size);
}

template <typename GenericElement>
class IteratorVector{
    private:
        const DynamicVector<GenericElement>& vector; //referinta la vectorul dinamic
        int poz=0; //prima pozitie o sa fie chiar 0
    public:
        explicit IteratorVector(const DynamicVector<GenericElement>& v) ;
        IteratorVector(const DynamicVector<GenericElement>& v,int poz)noexcept;

    [[maybe_unused]] [[nodiscard]] bool valid()const;//inca se poate itera
        GenericElement& element() const; //get element
        void next();//to go to the next iterator
        GenericElement& operator*();//ca sa simulam pointer
        IteratorVector& operator++();//iterare continua
        //verificare egalitate
        bool operator==(const IteratorVector& ot ) noexcept;
         bool operator!=(const IteratorVector& ot ) noexcept;


    };
//functions implemented
template <typename GenericElement>
IteratorVector<GenericElement>::IteratorVector(const DynamicVector<GenericElement>& vec) : vector(vec){}

template <typename GenericElement>
IteratorVector<GenericElement>::IteratorVector(const DynamicVector<GenericElement> &v, int poz) noexcept: vector{v},poz{poz} {}
template <typename GenericElement>
[[maybe_unused]] bool IteratorVector<GenericElement>::valid() const {
    return poz<vector.size;
}
template <typename GenericElement>
GenericElement &IteratorVector<GenericElement>::element() const {
    return vector.genericElements[poz];
}

template <typename GenericElement>
void IteratorVector<GenericElement>::next() {
    poz++;
}

template <typename GenericElement>
GenericElement &IteratorVector<GenericElement>::operator*() {
    return element();
}

template <typename GenericElement>
IteratorVector<GenericElement> &IteratorVector<GenericElement>::operator++() {
    next();
    return *this;
}

template <typename GenericElement>
bool IteratorVector<GenericElement>:: operator==(const IteratorVector<GenericElement>& ot) noexcept
{
    return ot.poz==poz;
}

template <typename GenericElement>
bool IteratorVector<GenericElement>:: operator!=(const IteratorVector<GenericElement>& ot) noexcept
{
    return !(*this == ot);
}




#endif //LAB_6_DYNAMICVECTO_H
