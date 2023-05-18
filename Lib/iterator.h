#ifndef MYTINYSTL_ITERATOR_H
#define MYTINYSTL_ITERATOR_H

// 这个头文件用于迭代器设计，包含了一些模板结构体与全局函数，
#include <cstddef>

#include "type_traits.h"

namespace mystl {

    // 五种迭代器类型
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_iterator_tag : public bidirectional_iterator_tag {};
}

#endif
