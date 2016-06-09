/*	Name - Nikhil Gaud
 * 	username - ngaud
 */
#ifndef TRACKINGDEQUE_H
#define TRACKINGDEQUE_H
#include <iostream>
#include <deque>

template<typename T>
class TrackingDeque: public std::deque<T>
{
	public:
		TrackingDeque();
		void push_back(T);
		void push_front(T);
		~TrackingDeque();
	
	private:
		int max_size;
};

template<typename T>
TrackingDeque<T>::TrackingDeque() : max_size(0)
{

}

template<typename T>
TrackingDeque<T>::~TrackingDeque()
{
	std::cout << "--> " << max_size << " <--" << std::endl;
}

template<typename T>
void TrackingDeque<T>::push_back(T val)
{
	std::deque<T>::push_back(val);
	if(max_size < std::deque<T>::size())
	{
		max_size = std::deque<T>::size();
	}
}

template<typename T>
void TrackingDeque<T>::push_front(T val)
{
	std::deque<T>::push_front(val);
	if(max_size < std::deque<T>::size())
	{
		max_size = std::deque<T>::size();
	}
}

#endif
