/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:55:02 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/06 21:10:27 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*

From the formula:

`A = \frac{|x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2)|}{2}`

*/
static float area_from_vertices(const Point &p_1, const Point &p_2, const Point &p_3) {

	float p_1xf = p_1.get_x().toFloat();
	float p_2xf = p_2.get_x().toFloat();
	float p_3xf = p_3.get_x().toFloat();

	float p_1yf = p_1.get_y().toFloat();
	float p_2yf = p_2.get_y().toFloat();
	float p_3yf = p_3.get_y().toFloat();

	return (std::abs(
		(p_1xf * (p_2yf - p_3yf))
		+ (p_2xf * (p_3yf - p_1yf))
		+ (p_3xf * (p_1yf - p_2yf))
	)) / 2.0f;

}

bool bsp(const Point point_a, const Point point_b, const Point point_c, const Point target_point) {

	float A_ABC = area_from_vertices(point_a, point_b, point_c);
	float A_TAB = area_from_vertices(target_point, point_a, point_b);
	float A_TBC = area_from_vertices(target_point, point_b, point_c);
	float A_TCA = area_from_vertices(target_point, point_c, point_a);

	if (A_TAB == 0 || A_TBC == 0 || A_TCA == 0) {
		return false;
	}

	return ((A_TAB + A_TBC + A_TCA) == A_ABC);

}
