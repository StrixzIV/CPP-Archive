/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:06:22 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:06:22 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal {

    private:
        std::string _type;

    public:

        Dog();
		Dog(const std::string &dog_type);
		Dog(const Dog &base);
		Dog &operator=(const Dog &lhs);
		~Dog();

        const std::string &getType() const;
        void setType(const std::string &dog_type);

        void makeSound() const;

};

#endif

