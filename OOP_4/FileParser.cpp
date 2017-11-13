#include "FileParser.h"
#include <iostream>
#include "Exception.h"

using namespace std;

FileParser::FileParser(const string& in, const string& out) : inFile(in), outFile(out) {}

void FileParser::Work()
{
	ifstream ifs(inFile);
	ofstream ofs(outFile);

	while (ifs.good())
	{
		if (ifs.good())
		{
			uint64_t obj;
			ifs >> obj;
			Factorization f(obj);
			f.Calculation();

			if (!f.Check())
				throw WrongAnswer("The result of multiplication of prime divisors is not equal to the original value\n");

			if (ofs.good())
				ofs.write(f.Description().c_str(), f.Description().length());
			else
				throw IOException("IO error in " + outFile + '\n');
		}
		else
		{
			throw IOException("IO error in " + inFile + '\n');
		}
	}
	ifs.close();
	ofs.close();
}