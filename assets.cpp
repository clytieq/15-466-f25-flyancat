#include "load_save_png.hpp"

#include <iostream>
#include <algorithm>

//void process_img() {
//
//}

int main(int argc, char** argv) {
	std::cout << "main() called\n" << std::endl;
	std::vector<std::string> filenames = { 
		//"character.png", 
		"ground.png"
	};
	try {
		for (std::string filename : filenames) {
			// load png parameters
			glm::uvec2* size = new glm::uvec2();
			std::vector< glm::u8vec4 >* data = new std::vector< glm::u8vec4 >();
			load_png(filename, size, data, LowerLeftOrigin);

			// tiles & palettes to save as png
			// implement 8x8 to start
			if (size->x == 8 && size->y == 8) {
				std::vector< glm::u8vec4 > *palette = new std::vector< glm::u8vec4 >(4);
				size_t i = 1;
				for (glm::u8vec4 pixel : *data) {
					if (std::find(palette->begin(), palette->end(), pixel) == palette->end()) {
						(*palette)[i] = pixel;
						i++;
						if (i >= 4) {
							break;
						}
					}
				}
				save_png("8x8palettetest.png", glm::uvec2(2,2), palette->data(), LowerLeftOrigin);
			}
			else {
				save_png("test.png", *size, data->data(), LowerLeftOrigin);
			}
		}

		std::cout << "pipeline finished\n" << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "bleh blah: " << e.what() << std::endl;
	}
	return 0;
}