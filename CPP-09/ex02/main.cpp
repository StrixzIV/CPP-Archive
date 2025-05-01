/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:29:03 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/30 16:35:31 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 2) {
        return 1;
    }

    std::vector<std::string> args;

    for (int idx = 1; idx < argc; ++idx) {
        args.push_back(std::string(argv[idx]));
    }

    try {

        FJMI< std::deque<int>, std::deque<std::pair<int, int> > > deq(args);
        deq.merge_insertion_sort();
        deq.print_before_sort();
        deq.print_after_sort();
        deq.print_elasped();

        FJMI< std::vector<int>, std::vector<std::pair<int, int> > > vec(args);
        vec.merge_insertion_sort();
        vec.print_before_sort();
        vec.print_after_sort();
        vec.print_elasped();

    }

    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}
