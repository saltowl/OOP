#pragma once
#include <string>
#include <fstream>
#include "Factorization.h"
#include <iostream>
#include "Exception.h"

class FileParser
{
public:
	FileParser(const std::string& in, const std::string& out);
	~FileParser() = default;

	void Work();

private:
	const std::string inFile, outFile;

	Factorization buf;

	void WriteFile(std::ofstream &ofs);
	void ReadFile(std::ifstream &ifs);
};