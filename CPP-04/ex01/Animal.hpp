/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:44:19 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:44:19 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal {

    protected:
        std::string _type;

    public:

        Animal();
		Animal(const std::string &animal_type);
		Animal(const Animal &base);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal();

        const std::string &getType() const;
        void setType(const std::string &animal_type);

        virtual Brain &getBrain() const = 0;
        virtual void makeSound() const;

};

#endif
