/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:18:07 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/05 16:49:02 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void read_filestream(std::ifstream &filestream, std::string &str) {

	char character;

	while (!filestream.eof() && (filestream >> std::noskipws >> character)) {
		str += character;
	}

}

int replace_input(char **argv, std::string &str) {
	
	int current_position;
	std::ofstream output_filestream;

	output_filestream.open((std::string(argv[1]) + ".replace").c_str());

	if (output_filestream.fail()) {
		return 1;
	}

	for (int idx = 0; idx < (int) str.size(); idx++) {

		current_position = str.find(argv[2], idx);

		if (current_position != -1 && current_position == idx) {
			output_filestream << argv[3];
			idx += std::string(argv[2]).size() - 1;
		}

		else {
			output_filestream << str[idx];
		}

	}

	output_filestream.close();
	return 0;

}

int main(int argc, char **argv) {

	std::string str;
	std::ifstream input_filestream;

	if (argc != 4) {
		std::cerr << "usage: " << argv[0] << " <file> <target> <replace>" << std::endl;
		return 1;
	}

	input_filestream.open(argv[1]);

	if (input_filestream.fail()) {
		std::cerr << "Error: " << argv[1] << ": " << "No such file or directory." << std::endl;
		return 1;
	}

	read_filestream(input_filestream, str);
	input_filestream.close();
	
	return (replace_input(argv, str));

}
