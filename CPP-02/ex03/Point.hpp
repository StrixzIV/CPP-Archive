/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:39:18 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 20:47:10 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	private:
		const Fixed _x;
		const Fixed _y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point &base);
		Point &operator=(const Point &lhs);
		~Point();

		Fixed get_x() const;
		Fixed get_y() const;

};

bool bsp(const Point point_a, const Point point_b, const Point point_c, const Point target_point);

#endif
