#ifndef MYTINYSTL_TYPE_TRAITS_H
#define MYTINYSTL_TYPE_TRAITS_H

// 这个头文件用于提取类型信息
// use standard header for type_traits
#include <type_traits>

namespace mystl {

    // header struct
    template<class T, T val>
    struct m_integral_constant {
        static constexpr T
        value = val;
    };

    template<bool b>
    using m_bool_constant = m_integral_constant<bool, b>;

    typedef m_bool_constant<true> m_true_type
    typedef m_bool_constant<false> m_false_type

    /**************************************/
    // type_traits

    // is_pair

    // --- forward declaration begin
    template<class T1, class T2>
    struct pair;
    // --- forward declaration end

    template<class T>
    struct is_pair : mystl::m_false_type {
    };

    template<class T1, class T2>
    struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {
    };

} // namespace mystl

#endif
