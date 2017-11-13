#pragma once
#include <string>
#include <fstream>
#include "Factorization.h"

class FileParser
{
public:
	FileParser(const std::string& in, const std::string& out);
	~FileParser() = default;

	void Work();
private:
	const std::string inFile, outFile;
};