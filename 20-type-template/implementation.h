#pragma once
#include <cstddef>
#include <utility>
#include <boost/optional.hpp>

template<typename T>
class container_wrapper{
public:
	container_wrapper() = default;

	container_wrapper(T arg) : _value(std::move(arg)){}
	
	std::size_t size() const{
		return _value.size();
	}
	
	container_wrapper(const container_wrapper &) = default;
	container_wrapper(container_wrapper &&) = default;
	container_wrapper & operator=(const container_wrapper &) = default;
	container_wrapper & operator=(container_wrapper &&) = default;
	

private:
T _value;
};


template<typename T>
class container_wrapper<boost::optional<T>>{
public:
	container_wrapper() = default;

	container_wrapper(boost::optional<T> arg) : _value(std::move(arg)){}
	
	std::size_t size() const{
		return _value ? 1 : 0;
	}
	
	container_wrapper(const container_wrapper &) = default;
	container_wrapper(container_wrapper &&) = default;
	container_wrapper & operator=(const container_wrapper &) = default;
	container_wrapper & operator=(container_wrapper &&) = default;
	

private:
	boost::optional<T> _value;
};
