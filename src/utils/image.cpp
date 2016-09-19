#include "image_reader.h"



image_reader::image_reader(char * in_filename, int in_width, int in_height) {
	width = in_width;
	height = in_height;
	filename = in_filename;

}

int[] image_reader::read(char *) {
	image = new unsigned char* [height];

	for (int i = 0; i < height; i++) {
		image[i] = new unsigned char * [width];
	}
	fil = new ifstream;
	fil->open(filename, ios::in | ios::binary);
	fil->seekg(0, ios::beg);

}
