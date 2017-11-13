#include "FileParser.h"

using namespace std;

FileParser::FileParser(const string& in, const string& out) : inFile(in), outFile(out) {}

void FileParser::Work()
{
	ifstream ifs(inFile);
	ofstream ofs(outFile);

	if (!ifs.good())
		throw IOException("IO error in " + inFile + '\n');

	if (!ofs.good())
		throw IOException("IO error in " + outFile + '\n');

	while (ifs.good())
	{
		ReadFile(ifs);
		WriteFile(ofs);
	}

	ifs.close();
	ofs.close();
}

void FileParser::ReadFile(ifstream &ifs)
{
	if (ifs.good())
	{
		uint64_t obj;
		ifs >> obj;
		Factorization f(obj);
		f.Calculation();

		if (!f.Check())
			throw WrongAnswer("The result of multiplication of prime divisors is not equal to the original value\n");

		buf = f;
	}
	else
		throw IOException("IO error in " + inFile + '\n');
}

void FileParser::WriteFile(ofstream &ofs)
{
	if (ofs.good())
		ofs.write(buf.Description().c_str(), buf.Description().length());
	else
		throw IOException("IO error in " + outFile + '\n');
}