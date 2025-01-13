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
# include "Brain.hpp"

class Dog: public Animal {

    private:
        Brain *_brain;

    public:

        Dog();
		Dog(const Dog &base);
		Dog &operator=(const Dog &lhs);
		~Dog();

        const std::string &getType() const;
        void setType(const std::string &dog_type);

        Brain &getBrain() const;
        void setBrain(const Brain &brain);

        void makeSound() const;

};

#endif

