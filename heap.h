#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
	/**
	 * @brief Construct a new Heap object
	 * @param m ary-ness of heap tree (default to 2)
	 * @param c binary predicate function/functor that takes two items
	 *          as an argument and returns a bool if the first argument has
	 *          priority over the second.
	 */
	Heap(int m=2, PComparator c = PComparator()) : m_(m), comp_(c)
	{
	}

	/**
	 * @brief Destroy the Heap object
	 */
	~Heap()
	{
	}

	/**
	 * @brief Push an item to the heap
	 * 
	 * @param item item to heap
	 */
	void push(const T& item)
	{
		heap_.push_back(item);
		trickleUp();
	}

	/**
	 * @brief Returns the top (priority) item
	 * @return T const& top priority item
	 * @throw std::underflow_error if the heap is empty
	 */
	T const & top() const
	{
		if(empty())
		{
			throw std::underflow_error("Heap is empty");  
		} 
		else 
		{
			return heap_[0];
		}
	}

	/**
	 * @brief Remove the top priority item
	 * @return void
	 * @throw std::underflow_error if the heap is empty
	 */
	void pop()
	{
		if(empty())
		{
			throw std::underflow_error("Heap is empty");  
		} 
		if (size() == 1)
		{
			heap_.pop_back();
			return;
		}
		T temp = heap_.back();
		heap_[0] = temp;
		heap_.pop_back();
	
		trickleDown();
	}

	/**
	 * @brief Returns true if the heap is empty
	 * @return
	 */
	bool empty() const
	{
		return heap_.size() == 0;
	}

	/**
	 * @brief Returns size of the heap
	 * @return 
	 */
	size_t size() const
	{
		return heap_.size();
	}

private:
	// Add whatever helper functions and data members you need below
	std::vector<T> heap_;
	int m_;
	PComparator comp_;

	void trickleDown()
	{
		if (empty()) return;

		int index = 0; 
		int best_child;

		// ensures parent node doesn't go out of bounds
		while (index < heap_.size() )
		{
			// finding the best child
			int first_child = (index * m_) + 1;
			if (first_child >= heap_.size())
			{
					return; 
			}
			best_child = first_child;

			// loop through all the children of the parent
			for (int i = 1; i < m_; i++)
			{
				int current_child = first_child + i;
				if (current_child < heap_.size() && comp_(heap_[current_child], heap_[best_child]))
				{
					best_child = current_child;
				}
			}

			// decide to swap child and parent
			if (comp_(heap_[best_child], heap_[index]))
			{
				std::swap(heap_[index], heap_[best_child]);
				index = best_child;
			}
			// node is in the right place
			else
			{
				return;
			}


		}
	}


	void trickleUp()
	{    
		// add the child to the end
		int child_index = heap_.size() - 1;
		int parent_index = (child_index - 1) / m_;

		// push the child up the heap until it is valid
		while (child_index > 0 && comp_(heap_[child_index], heap_[parent_index]))
		{
			std::swap(heap_[child_index], heap_[parent_index]);
			child_index = parent_index;
			parent_index = (child_index - 1) / m_;
		}
	}



};


#endif

