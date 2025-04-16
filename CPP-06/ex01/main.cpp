/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:45:54 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:18 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

	Data telemetry;

	telemetry.x = 42.0;
	telemetry.y = 69.0;
	telemetry.z = 0.0;
	telemetry.roll = 90.0;
	telemetry.pitch = 45.0;
	telemetry.yaw = 210.0;

	uintptr_t serialized_value = Serializer::serialize(&telemetry);
	std::cout << "Serialized value -> 0x" << std::hex << serialized_value << std::endl;

	Data *deserialized_telemetry = Serializer::deserialize(serialized_value);

	std::cout << "Deserialized telemetry data:" << std::endl;
    std::cout << "x: " << deserialized_telemetry->x << std::endl;
    std::cout << "y: " << deserialized_telemetry->y << std::endl;
    std::cout << "z: " << deserialized_telemetry->z << std::endl;
    std::cout << "roll: " << deserialized_telemetry->roll << std::endl;
    std::cout << "pitch: " << deserialized_telemetry->pitch << std::endl;
    std::cout << "yaw: " << deserialized_telemetry->yaw << std::endl;

}
