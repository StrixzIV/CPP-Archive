/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <strixz.self@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:44:09 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/11 01:44:09 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal {

    protected:
        std::string _type;

    public:

        WrongAnimal();
		WrongAnimal(const std::string &animal_type);
		WrongAnimal(const WrongAnimal &base);
		WrongAnimal &operator=(const WrongAnimal &lhs);
		virtual ~WrongAnimal();

        const std::string &getType() const;
        void setType(const std::string &animal_type);

        void makeSound() const;

};

#endif
