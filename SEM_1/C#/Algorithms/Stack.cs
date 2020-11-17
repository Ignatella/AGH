using System;
using System.Collections.Generic;
using System.Text;

namespace lesson_5.Algorithms
{
    class Stack<T>
    {
        private T[] Heap { get; }

        public int Count { get; private set; }

        public Stack(int length)
        {
            this.Heap = new T[length];
            this.Count = 0;
        }

        public T Pop()
        {
            if (Count == 0)
            {
                throw new InvalidOperationException("The stack is empty. Can not return value");
            }

            Count--;

            return Heap[Count];
        }

        public T Get()
        {
            if (Count == 0)
            {
                throw new InvalidOperationException("The stack is empty. Can not return value");
            }

            return Heap[Count - 1];
        }

        public void Add(T element)
        {
            if (Count == Heap.Length)
            {
                Console.WriteLine("The stack is full. Item can not be added");
                return;
            }

            Heap[Count] = element;

            Count++;
        }

        public void Clear()
        {
            Count = 0;
        }
    }
}
