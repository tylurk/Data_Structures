#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Priority_queue.h  -- a priority_queue implemented as a heap

#include <vector>

using namespace std;

template <class T>
class Priority_queue {
public:
   Priority_queue() : c() { }
   Priority_queue(const Priority_queue & p): c(p.c) { }
   Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; }
   // vector destructor is automatically called when an obj of type Priority_queue is destroyed

   bool empty() { return c.empty(); }
   unsigned int size() { return c.size(); }
   void push(const T & x);
   void pop();
   T & top() { return c.front(); }
private:
   vector<T> c;
};

// swaps members of the heap that are being pushed in order to maintain itself as a heap (percoalte)
template<class Iterator>
void push_heap(Iterator start, Iterator stop)
{
   unsigned int pos = (stop - start) -1;
   unsigned int parent = (pos - 1)/ 2;

   while(pos > 0 and start[pos] > start[parent]){
      swap(start[pos], start[parent]);
      pos = parent;
      parent = (pos -1)/2;
   }
} // O(log(N))

// pushes x into the back of c, then calls push heap on c
template<class T>
void Priority_queue<T>::push(const T & x)
{
   c.push_back(x);
   push_heap(c.begin(),c.end());
} // O(log(N))

// makes elements into a heap
template <class Iterator>
void adjust_heap(Iterator start, unsigned heapsize, unsigned pos)
{
    while (pos < heapsize) {
      unsigned int childpos = pos * 2 + 1;
      if (childpos < heapsize) {
          if ((childpos + 1 < heapsize) and
            start[childpos + 1] > start [childpos])
               childpos++;

         if (start[pos] > start[childpos])
            return;
            else
            swap (start[pos], start[childpos]);
         }
      pos = childpos;
      }
} // O(N)...  Not sure

// makes the first element the last then calls adjust heap to clean up
template<class Iterator>
void pop_heap(Iterator start, Iterator stop)
{
   unsigned int lastpos = (stop - start) - 1;
   swap (start[0], start[lastpos]);
   adjust_heap(start,lastpos,0);
} // O(2log(N))

// calls pop_heap on c, then pops the back of c
template <class T>
void Priority_queue<T>::pop()
{
  pop_heap( c.begin(), c.end() );
  c.pop_back();
} // O(2log(N))

#endif
