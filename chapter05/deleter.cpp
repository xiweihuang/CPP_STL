// 其他析构策略
#include <string>
#include <fstream>
#include <memory>
#include <stdio.h>

using namespace std;

class FileDeleter
{
public:
	FileDeleter (const string& fn) : filename(fn) {

	}

	void operator () (ofstream* fp) {
		printf("delete...\n");
		fp->close();
		remove(filename.c_str());
	}

private:
	string filename;
};

int main()
{
	shared_ptr<ofstream> fp(new ofstream("tmpfile.txt"), FileDeleter("tmpfile.txt"));
}