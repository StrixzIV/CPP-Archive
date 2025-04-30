/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:48:08 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/29 12:35:59 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <sstream>
# include <iostream>

class RPN {

    private:

        int result;
        std::stack<int> values;

        bool is_valid_ops(const char c);

        void read_ops(const char c);
        void eval_ops(const std::string &expression);

    public:

        RPN(const std::string &expression);
        RPN(const RPN &base);
        RPN &operator=(const RPN &rhs);
        ~RPN();

        class InvalidExpressionException: public std::exception {
            
            public:
                virtual const char *what() const throw();
        
        };

        class DivisionByZeroException: public std::exception {

            public:
                virtual const char *what() const throw();

        };

};

#endif
