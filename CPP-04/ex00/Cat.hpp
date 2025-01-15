/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:50:25 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:50:25 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal {

    private:
        std::string _type;

    public:

        Cat();
		Cat(const std::string &cat_type);
		Cat(const Cat &base);
		Cat &operator=(const Cat &rhs);
		~Cat();

        const std::string &getType() const;
        void setType(const std::string &cat_type);

        void makeSound() const;

};

#endif

