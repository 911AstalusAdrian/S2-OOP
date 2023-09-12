
#ifndef A45_911ASTALUSADRIAN_DYNAMIC_ARRAY_H
#define A45_911ASTALUSADRIAN_DYNAMIC_ARRAY_H
#endif //A45_911ASTALUSADRIAN_DYNAMIC_ARRAY_H
#pragma once

template <typename  TElem>

class DynamicArray{

private:
    TElem* elements;
    int length;
    int capacity;

public:
    DynamicArray(int capacity = 10);
    DynamicArray(const DynamicArray& otherArray);
    ~DynamicArray();
    void resizeArray();
    int findElem(const TElem& element);
    TElem getElem(int position);
    void add(TElem element);
    void remove(const TElem& element);
    void update(const TElem& element, const TElem& updatedElement);

    // TODO - check if needed (operator overload)
    //TElem& operator[](int index);
    DynamicArray& operator=(const  DynamicArray& initial_array);

    int arrayLength();
    int arrayCapacity();

};

template<typename TElem>
DynamicArray<TElem>::DynamicArray(int capacity) {
    this->capacity = capacity;
    this->length = 0;
    this->elements = new TElem[this->capacity];
}

template<typename TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray &otherArray) {
    capacity = otherArray.capacity;
    length  = otherArray.length;
    elements = new TElem[otherArray.capacity];
    for (int i=0; i<length; i++)
        elements[i] = otherArray.elements[i];
}

template<typename TElem>
DynamicArray<TElem>::~DynamicArray() {
    delete[] elements;
}

template<typename TElem>
void DynamicArray<TElem>::resizeArray() {
    TElem* newArray = new TElem[capacity * 2];
    for (int i=0; i<length;i++)
        newArray[i] = elements[i];
    capacity *= 2;
    delete[] elements;
    elements = newArray;
}

template<typename TElem>
int DynamicArray<TElem>::findElem(const TElem &element) {
    for (int i=0; i<length; i++)
        if(elements[i] == element)
            return i;
    return -1;
}

template<typename TElem>
void DynamicArray<TElem>::add(TElem element) {
    if (length == capacity)
        resizeArray();
    elements[length] = element;
    length++;
}

template<typename TElem>
void DynamicArray<TElem>::remove(const TElem &element) {
    int index = findElem(element);
    if (index != -1){
        for (int i=index; i<length-1; i++)
            elements[i] = elements[i+1];
        length -= 1;
    }
}

template<typename TElem>
void DynamicArray<TElem>::update(const TElem &element, const TElem &updatedElement) {
    int index = findElem(element);
    if (index != -1)
        elements[index] = updatedElement;
}

template<typename TElem>
int DynamicArray<TElem>::arrayLength() {
    return length;
}

template<typename TElem>
int DynamicArray<TElem>::arrayCapacity() {
    return capacity;
}

template<typename TElem>
TElem DynamicArray<TElem>::getElem(int position) {
//    if (position >= length)
//        return -1;
    return elements[position];
}

template<typename TElem>
DynamicArray<TElem> &DynamicArray<TElem>::operator=(const DynamicArray &initial_array) {
    int da_capacity = initial_array.capacity;
    int da_length = initial_array.length;
    DynamicArray<TElem> new_array = DynamicArray<TElem>(da_capacity);
    for(int i=0;i<da_length;i++)
        new_array.elements[i] = initial_array.elements[i];
    return new_array;
}
