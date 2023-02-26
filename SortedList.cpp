
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    int mid, first =0, last= length-1;
    while(first<=last){
        mid=(first+last)/2;
        if(someItem<info[mid])
            last=mid-1;
        else if(someItem>info[mid])
            first = mid+1;
        else
            return true;
    }
    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    if(IsFull())
        return;
    length++;
    for(int i =0; i< length; i++){
        if(info[i] > item){
            for(int j = length-1; j>=i;j--)
                info[j+1]=info[j];
            info[i] = item;
            return;
        }
    }info[length] = item;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    for(int i=0; i<length;i++){
        if(info[i] == item){
            if(i == length -1){
                length--;
                return;
            }for(int j = i+1; j< length;j++)
                info[j-1]=info[j];
            --length;
            return;
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

