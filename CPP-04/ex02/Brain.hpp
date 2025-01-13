/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:42:20 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/13 22:18:40 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

	private:
		std::string _ideas[100];

	public:

		Brain();
		Brain(const Brain &base);
		Brain &operator=(const Brain &lhs);
		~Brain();

		const std::string &get_idea(const int &idx) const;
		void set_idea(const std::string &idea, const int idx);

};

#endif
