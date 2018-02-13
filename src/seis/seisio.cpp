#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "seisio.h" 
typedef unsigned char BYTE;

std::vector<BYTE> readSeis(const char* filename)
{
    // open the file:
    std::ifstream file(filename, std::ios::binary);

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<BYTE> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<BYTE>(file),
               std::istream_iterator<BYTE>());

    return vec;
}

void writeSeis(std::vector<BYTE> seismic, const char* filename){

	FILE* pFile;
	pFile = fopen(filename, "wb");

	std::cout << seismic.size() << std::endl;

	fwrite(&seismic[0], 1, seismic.size()*sizeof(BYTE), pFile);
	fclose(pFile);

}

inp::inp(){

	tall = 666;
	seismic = readSeis("plane.su");

}



