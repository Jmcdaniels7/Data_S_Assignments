#ifndef SET_H
#define SET_H
#include "AVLTree.h"

template <class type>
class set
{
    public:
        void insert(const type&insertItem);
        type setFind(const type&item) const;
        type &operator[](const type&item);
        typename AVLTree<type>::Iterator begin() {return tree.begin();};
        // void deleteKey(const type&);
        
    //protected:
        AVLTree<type> tree;

};

template <class type>
void set<type>::insert(const type &insertItem)
{
    tree.insert(insertItem);
}

template <class type>
type set<type>::setFind(const type &item) const
{
    set<type> v(item);
    try
    {
        v = tree.find(v);
    }
    catch(std::out_of_range e)
    {
        throw std::out_of_range("Item is not in the set.");
    }
    return item;

}

template <class type>
type &set<type>::operator[](const type &item)
{
    set<type> v(item);
    typename AVLTree<type>::Iterator v2;

    v2 = tree.find(item);
    
    return item;
    
}

//for future reference maybe
/*template <class type>
typename AVLTree<type>::Iterator set<type>::begin()
{
    while (tree.hasNext())
    {
        tree.next();
    }
    return tree.begin();

}*/


#endif