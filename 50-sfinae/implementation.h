#pragma once


template<typename T>
struct has_type_typedef{

	template <typename U, typename = typename U::type>
	static void test(int);
	template <typename U>
	static char test(long);
public:
	static constexpr bool value = std::is_void<decltype(test<T>(0))>::value;
};

template<typename T>
struct has_member_variable{

	template <typename U>
	static auto test(int) -> decltype(std::declval<U>().member, void());
	template <typename U>	
	static char test(long);

public:
	static constexpr bool value = std::is_void<decltype(test<T>(0))>::value;
};

