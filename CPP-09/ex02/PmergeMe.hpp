/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:37:01 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/30 16:36:52 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <ctime>
# include <deque>
# include <vector>
# include <string>
# include <sstream>
# include <utility>
# include <iostream>
# include <algorithm>
# include <stdexcept>

template<typename T, typename U>
class FJMI {

    private:

        U pairs;

        T sorted;
        T unsorted;
        T insert_pos;
        const T sequence;

        double elasped;

        FJMI(const FJMI &base);
        FJMI &operator=(const FJMI &rhs);

        static const T set_sequence(std::vector<std::string> argv);
        static void merge_sort(typename U::iterator start, typename U::iterator end);
        static void merge(typename U::iterator start, typename U::iterator mid, typename U::iterator end);
        static T insert_sequence(size_t n);
        static int jacobsthal(size_t n);
        static typename T::iterator binary_search(int n, typename T::iterator left, typename T::iterator right);

        void make_sorted_pairs();
        void halfsort();
        void insertion_sort();

    protected:

        U &get_pairs();

        T &get_sorted();
        T &get_unsorted();
        T &get_insert_pos();
        const T &get_sequence() const;

    public:

        FJMI();
        FJMI(std::vector<std::string> argv);
        virtual ~FJMI();

        void merge_insertion_sort();
        void print_before_sort();
        void print_after_sort();

        void print_elasped();

};

// -----------------------------------------

template<typename T, typename U>
FJMI<T, U>::FJMI() {}

template<typename T, typename U>
FJMI<T, U>::FJMI(std::vector<std::string> argv) {
    this->sequence = set_sequence(argv);
}

template<typename T, typename U>
FJMI<T, U>::FJMI(const FJMI &base) {
    *this = base;
}

template<typename T, typename U>
FJMI<T, U> &FJMI<T, U>::operator=(const FJMI<T, U> &rhs) {
    (void) rhs;
    return *this;
}

template<typename T, typename U>
FJMI<T, U>::~FJMI() {}

template<typename T, typename U>
U &FJMI<T, U>::get_pairs() {
    return this->pairs;
}

template<typename T, typename U>
T &FJMI<T, U>::get_sorted() {
    return this->sorted;
}

template<typename T, typename U>
T &FJMI<T, U>::get_unsorted() {
    return this->unsorted;
}

template<typename T, typename U>
T &FJMI<T, U>::get_insert_pos() {
    return this->insert_pos;
}

template<typename T, typename U>
const T &FJMI<T, U>::get_sequence() const {
    return this->sequence;
}

template<typename T, typename U>
const T FJMI<T, U>::set_sequence(std::vector<std::string> argv) {

    int n;
    std::string arg;
    
    T sequence;

    for (size_t idx = 0; idx < argv.size(); idx++) {

        arg = argv[idx];
        
        if (arg.empty()) {
            throw std::runtime_error("Invalid args.");
        }

        std::istringstream iss(arg);

        if (!(iss >> n)) {
            throw std::runtime_error("Invalid args.");
        }

        if (n < 0) {
            throw std::runtime_error("Args value must be >= 0");
        }

        sequence.push_back(n);

    }

    return (sequence);

}

template<typename T, typename U>
void FJMI<T, U>::merge_insertion_sort() {

    clock_t start_timestamp = clock();

    if (get_sequence().size() == 1) {
        get_sorted() = get_sequence();
    }

    else {
        make_sorted_pairs(); // Step #1
        halfsort(); // Step # 2 + 3
        insertion_sort(); // Step #4
    }

    this->elasped = static_cast<double>(clock() - start_timestamp) / (CLOCKS_PER_SEC * 1000);

}

// Step #1
template<typename T, typename U>
void FJMI<T, U>::make_sorted_pairs() {

    typename T::const_iterator iter = get_sequence().begin();

    while (iter != get_sequence().end()) {

        int x = *iter;
        iter++;

        if (iter != get_sequence().end()) {

            int y = *iter;
            iter++;

            if (x < y) {
                std::swap(x, y);
            }

            get_pairs().push_back(std::make_pair(x, y));

        }

    }

}

// Step #2
template<typename T, typename U>
void FJMI<T, U>::merge(typename U::iterator start, typename U::iterator mid, typename U::iterator end) {

    U first_half(start, mid);
    U second_half(mid, end);

    typename U::iterator current = start;
    typename U::iterator first_iter = first_half.begin();
    typename U::iterator second_iter = second_half.begin();

    while (first_iter != first_half.end() && second_iter != second_half.end()) {

        if (first_iter->first <= second_iter->first) {
            *current = *first_iter++;
        }

        else {
            *current = *second_iter++;
        }

        current++;

    }

    while (first_iter != first_half.end()) {
        *current = *first_iter++;
    }

    while (second_iter != second_iter.end()) {
        *current = *second_iter++;
    }

}

template<typename T, typename U>
void FJMI<T, U>::merge_sort(typename U::iterator start, typename U::iterator end) {

    if (std::distance(start, end) > 1) {

        typename U::iterator mid = start;
        std::advance(mid, std::distance(start, end) / 2);

        FJMI<T, U>::merge_sort(start, mid);
        FJMI<T, U>::merge_sort(mid, end);
        FJMI<T, U>::merge(start, mid, end);

    }

}

// Step #3
template<typename T, typename U>
void FJMI<T, U>::halfsort() {

    // Step #2
    FJMI<T, U>::merge_sort(get_pairs().begin(), get_pairs().end());

    typename U::const_iterator iter = get_pairs().begin();
    get_sorted().push_back(iter->second);

    while (iter != get_pairs().end()) {
        get_sorted().push_back(iter->first);
        get_unsorted().push_back(iter->second);
        iter++;
    }

}

// Step #4
template<typename T, typename U>
void FJMI<T, U>::insertion_sort() {

    size_t n_inserted = 0;
    
    typename T::iterator to_insert;
    typename T::iterator real_pos;
    typename T::iterator last_pos;

    get_insert_pos() = insert_sequence(get_unsorted().size());

    for (
        typename T::iterator iter = get_insert_pos().begin();
        iter != get_insert_pos().end();
        iter++
    ) {

        to_insert = get_unsorted().begin();
        std::advance(to_insert, *iter - 1);

        last_pos = get_sorted().begin();
        std::advance(last_pos, *iter + n_inserted);

        n_inserted++;

        real_pos = FJMI<T, U>::binary_search(*to_insert, get_sorted().begin(), last_pos);
        get_sorted().insert(real_pos, *to_insert);

    }

    if (get_sequence().size() % 2 != 0) {
        int value = get_sequence().back();
        real_pos = FJMI<T, U>::binary_search(value, get_sorted().begin(), get_sorted().end());
        get_sorted().insert(real_pos, value);
    }

}

template<typename T, typename U>
int FJMI<T, U>::jacobsthal(size_t n) {

    if (n == 0 || n == 1) {
        return (n);
    }

    return jacobsthal(n - 1) + (2 * jacobsthal(n - 2));

}

template<typename T, typename U>
typename T::iterator FJMI<T, U>::binary_search(int n, typename T::iterator left, typename T::iterator right) {

    typename T::iterator mid;

    while (std::distance(left, right) > 1) {

        mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (n > *mid) {
            left = mid;
        }

        else {
            right = mid;
        }

    }

    if (n > *left) {
        typename T::iterator tmp = left;
        ++tmp;
        return tmp;
    }

    return left;

}

template<typename T, typename U>
T FJMI<T, U>::insert_sequence(size_t n) {

    T insert_seq;
    T jacobsthal_seq;

    int idx = 3;

    if (n == 0) {
        return insert_seq;
    }

    size_t value = FJMI<T, U>::jacobsthal(idx);

    while (value < n - 1) {
        jacobsthal_seq.push_back(value);
        value = FJMI<T, U>::jacobsthal(++idx);
    }

    size_t prev_jacobsthal_val = 1;

    for (
        typename T::const_iterator jacobsthal_val = jacobsthal_seq.begin();
        jacobsthal_val != jacobsthal_seq.end();
        jacobsthal_val++
    ) {

        prev_jacobsthal_val = *jacobsthal_val;
        insert_seq.push_back(*jacobsthal_val);

        for (size_t idx = *jacobsthal_val; idx > prev_jacobsthal_val; idx--) {
            insert_seq.push_back(idx);
        }

    }

    while (prev_jacobsthal_val++ < n) {
        insert_seq.push_back(prev_jacobsthal_val);
    }

    return insert_seq;

}

template<typename T, typename U>
void FJMI<T, U>::print_before_sort() {

    std::cout << "Before sorting: " << std::endl;

    for (
        typename T::const_iterator iter = get_sequence().begin();
        iter != get_sequence().end();
        iter++
    ) {
        std::cout << *iter << ", ";
    }

    std::cout << std::endl;

}

template<typename T, typename U>
void FJMI<T, U>::print_after_sort() {

    std::cout << "After sorting: " << std::endl;

    for (
        typename T::const_iterator iter = get_sorted().begin();
        iter != get_sorted().end();
        iter++
    ) {
        std::cout << *iter << ", ";
    }

    std::cout << std::endl;

}

template<typename T, typename U>
void FJMI<T, U>::print_elasped() {
    std::cout << "Time elasped: " << this->elasped << " seconds" << std::endl;
}

#endif
