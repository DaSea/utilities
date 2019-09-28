/*
 * Copyright (C) 2016-08-29 Dasea
 *
 * Description: 测试用的头文件
 */
#ifndef __SCPP_ASSERT_H__
#define __SCPP_ASSERT_H__

#define SCPP_ASSERT(condition, msg)     \
    do {                                \
        if (!(condition)) {             \
            std::ostringstream s;       \
            s << msg;                   \
            SCPP_AssertErrorHandler(    \
                __FILE__, __LINE__,     \
                s.str().c_str());       \
        }                               \
    } while (0);


// 静态数组
template<typename T, unsigned int N>
class array {
public:
    array() {};
    explicit array(const T& initVal) {
        for (size_type i = 0; i < size(); ++i) {
            _data[i] = initVal;
        }
    }

    size_type size() const { return N; }

    T& operator[] (size_type index) {
        return _data[index];
    }

    const T& operator[] (size_type index) const {
        return _data[index];
    }

    T* begin() { return (_data); }
    const T* end() const { return (_data + N); }

private:
    T _data[N];
};
#endif // __SCPP_ASSERT_H__
