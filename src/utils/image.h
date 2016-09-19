// Image reading code
#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>

class image {
	public:
		image(char *, int, int);
		int * read();
		double * read();
		double * read_normalized();
	private:
		int height;
		int width;
		char * filename;
		ifstream fil;
}

#endif
