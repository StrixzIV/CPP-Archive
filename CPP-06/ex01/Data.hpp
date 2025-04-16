/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:09:32 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 12:11:06 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

// Example data struct: telemetry data
typedef struct Data {
	double x;
	double y;
	double z;
	double roll;
	double pitch;
	double yaw;
}	Data;

#endif
