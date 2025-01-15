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

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

    private:
        std::string _type;

    public:

        WrongCat();
		WrongCat(const std::string &cat_type);
		WrongCat(const WrongCat &base);
		WrongCat &operator=(const WrongCat &rhs);
		~WrongCat();

        const std::string &getType() const;
        void setType(const std::string &cat_type);

        void makeSound() const;

};

#endif

