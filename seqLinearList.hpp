#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

template<typename T>
class LinearList{
private:
    T* buffer_;
    unsigned int size_;
    unsigned int capacity_;
    //int default_;
public:
    // Default Constructor
    // Creates a zero sized LinearList
    LinearList(){
        buffer_ = new T[100];
        size_=0;
        capacity_=100;
        fill(INT_MAX);
    };
    // Constuctor with size and default value as input
    LinearList(int isize, T ival){
        buffer_ = new T[isize];
        size_=0;
        capacity_=isize;
        fill(ival);
    };

    // Default Destructor
    ~LinearList(){
        delete[] buffer_;
    };

    // Accessing an element of the LinearList using operator
    inline T& operator[](const int& i){
        return buffer_[i];
    };

    // Return the element in the list at position k
    //inline T& at(const int& k){
    inline T& returnListElement(const int& k){
        return buffer_[k];
    };

    // Appending an element to the LinearList
    // The asymptotic time complexity of this function
    // should be O(1)
    void push_back(const T& item){
        buffer_[size_]=item;
        size_++;
    };

    // Returns true if LinearList is empty
    bool isEmpty(){
        return (size_==0) ? true:false;
    };

    // Returns the size of the LinearList
    unsigned int size(){
        return size_;
    };

    // Returns the capacity of the LinearList
    unsigned int capacity(){
        return capacity_;
    };

    // Fills all the elements with a default value
    void fill(const T& item){
        for(int i=0;i<capacity_;i++){
            buffer_[i]=item;
        }
    };

    // Resizes the LinearList
    void resize(const int& n){
        buffer_=(T*)realloc(buffer_,n);
	capacity_=n;
    };

    // Find the index of first occurence of an item in the list
    // Return size of list if item not found
    // 0-based indexing
    int find(const T& item){
        for(int i=0;i<size_;i++){
            if(buffer_[i]==item){
                return i;
            }
            else
                continue;
        }
        return size_;
    };

    // Remove all occurences of an item in the list
    void erase(const T& item){
        for(int j=0;j<size_;j++){
            if(buffer_[j]==item){
                for(int i=j;i<size_-1;i++){
                    buffer_[i]=buffer_[i+1];
                }
                --size_;
            }
            else
                continue;
        }
    };

    // Remove the item in the list at position pos i.e,pos-1
    void erase_pos(const int& pos){
        for(int i=pos-1;i<size_-1;i++){
            buffer_[i]=buffer_[i+1];
        }
        --size_;
    };

    // Insert item at position k i.e, at buffer_[k]
    void insert(const T& item, const int& k){
        for(int i=size_;i<k;i++){
            buffer_[i+1]=buffer_[i];
        }
        buffer_[k]=item;
        ++size_;
    };

    // Iterator class for LinearList
    // This should be used to traverse the LinearList
    // See std::vector<T>::iterator for more understanding
    // on how iterators work
    //template<typename *T>
    /*class iterator{
      private:
        T* elem_;
      public:
        iterator(){
            elem_=NULL;
        };
        iterator(T* ptr){
            elem_=ptr;
        };
        ~iterator(){
            delete[] elem_;
        };
    //own made function for returning iter value
        T* value(){
            return elem_;
        };
        T operator*(){  //T&
            return *elem_;
        };

        void operator=(T *ptr){
            elem_ = ptr;
        };
        void operator=(LinearList<T>::iterator iter){
            elem_=iter.value();
        };
        void operator++(){
            ++elem_;
        };
        void operator--(){
            --elem_;
        };
        bool operator!=(T* ptr){
            return (ptr==elem_) ? false:true;
        };
        bool operator==(T* ptr){
            return (ptr==elem_) ? true:false;
        };
        bool operator!=(LinearList<T>::iterator iter){
            return (iter==elem_) ? false:true;
        };
        bool operator==(LinearList<T>::iterator iter){
            return (iter==elem_) ? true:false;
        };
        iterator operator+(int i){
            elem_+=i;
        };
        iterator operator-(int i){
            elem_-=i;
        };
    };
    iterator begin(){
        return &buffer_[0];
    };
    iterator end(){
        return &buffer_[size_];
    };*/
};
#endif  /* _SEQ_LINEAR_LIST */
