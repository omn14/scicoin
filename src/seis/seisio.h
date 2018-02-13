
#ifndef SEISIO_H
#define SEISIO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator> 
typedef unsigned char BYTE;

std::vector<BYTE> readSeis(const char* filename);

void writeSeis(std::vector<BYTE> seismic, const char* filename);

class inp{

	public:	
	inp(); //constructor
	int tall;
	std::vector<BYTE> seismic;		
};



#endif
