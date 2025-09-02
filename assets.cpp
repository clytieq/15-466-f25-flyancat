#include "load_save_png.hpp"

#include <iostream>

void init_assets() {
	std::vector<std::string> filenames = {
		"assets\\character.png",
	};
	glm::uvec2* size = new glm::uvec2();
	std::vector< glm::u8vec4 >* data = new std::vector< glm::u8vec4 >();

	load_png(filenames[0], size, data, LowerLeftOrigin);

	save_png("assets/test.png", *size, data->data(), LowerLeftOrigin);
	std::cout << "init_assets() finished\n" << std::endl;
}

int main(int argc, char** argv) {
	std::cout << "main() called\n" << std::endl;
	try {
		init_assets();
	}
	catch (const std::runtime_error& e) {
		std::cerr << "bleh blah: " << e.what() << std::endl;
	}
	return 0;
}