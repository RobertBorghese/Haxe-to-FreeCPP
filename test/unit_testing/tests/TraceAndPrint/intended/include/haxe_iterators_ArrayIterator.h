#pragma once

#include "_HaxeUtils.h"

namespace haxe::iterators {

template<typename T>
class ArrayIterator {
public:
	std::shared_ptr<std::deque<T>> array;
	
	int current;

	ArrayIterator(std::shared_ptr<std::deque<T>> array):
		_order_id(generate_order_id())
	{
		this->current = 0;
		this->array = array;
	}
	
	bool hasNext() {
		return this->current < (int)(this->array->size());
	}
	
	T next() {
		return (*this->array)[this->current++];
	}
	
	HX_COMPARISON_OPERATORS(ArrayIterator<T>)
};

}
