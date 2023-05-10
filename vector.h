#ifndef VECTOR_INCLUDED_H
#define VECTOR_INCLUDED_H
#include <iostream>


template<typename T>
class vector {
    public:
        vector() :
            m_size(0),
            m_capacity(2)
        {
            m_data = new T[m_capacity];
        }

        ~vector()
        {
            delete[] m_data;
        }

        auto size() { return m_size; }  

        template<typename ... Args>
        void emplace_back(Args&&... args)
        {
            if (m_size >= m_capacity) {
                realloc();
            }

            new(&m_data[m_size]) T(std::forward<Args>(args)...);
            m_size++;
        }


        void push_back(const T& data) {
            if (m_size >= m_capacity) {
                realloc();
            }

            m_data[m_size] = data;
            m_size++;
        }

        void push_back(T&& data) {
             if (m_size >= m_capacity) {
                realloc();
            }

            m_data[m_size] = std::move(data);
            m_size++;
        }

        const T& operator[](size_t index) {
            if(index >= m_size) {

            }

            return m_data[index];
        }

    private:
        T* m_data;
        size_t m_size;
        long m_capacity;
    
    private:
        void realloc() {
            int newCapacity = m_capacity + (m_capacity / 2);

            auto* temp = new T[newCapacity];

            for(auto i=0; i < m_size; i++) {
                temp[i] = std::move(m_data[i]);
            }

            delete[] m_data;
            m_data = temp;
            m_capacity = newCapacity;
        }
};


#endif