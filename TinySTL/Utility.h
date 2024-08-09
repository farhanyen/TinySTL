#ifndef _UTILITY_H_
#define _UTILITY_H_

namespace TinySTL {
    //************ [swap] ***************
    template<class T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    //*********** [pair] ****************
    template<class T1, class T2>
    struct pair {
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair() = default;

        template<class U, class V>
        pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

        pair(const first_type& a, const second_type& b) : first(a), second(b) {}

        pair& operator=(const pair& pr) {
            if (this != &pr) {
                first = pr.first;
                second = pr.second;
            }
            return *this;
        }

        void swap(pair& pr) {
            TinySTL::swap(first, pr.first);
            TinySTL::swap(second, pr.second);
        }

        // Friend functions using the same template parameters
        friend bool operator==(const pair& lhs, const pair& rhs) {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }

        friend bool operator!=(const pair& lhs, const pair& rhs) {
            return !(lhs == rhs);
        }

        friend bool operator<(const pair& lhs, const pair& rhs) {
            return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
        }

        friend bool operator<=(const pair& lhs, const pair& rhs) {
            return !(rhs < lhs);
        }

        friend bool operator>(const pair& lhs, const pair& rhs) {
            return rhs < lhs;
        }

        friend bool operator>=(const pair& lhs, const pair& rhs) {
            return !(lhs < rhs);
        }

        friend void swap(pair& x, pair& y) {
            x.swap(y);
        }
    };

    // ******* [make_pair] ************
    template<class U, class V>
    pair<U, V> make_pair(const U& u, const V& v) {
        return pair<U, V>(u, v);
    }
}

#endif // _UTILITY_H_
