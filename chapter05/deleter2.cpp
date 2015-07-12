#include <memory>
#include <iostream>

using namespace std;

class SharedMemoryDetacher
{
public:
	void operator () (int* p) {
		cout << "unlink /tmp1234" << endl;
		if (shm_unlink("/tmp1234") != 0) {
			cerr << "OOPS: shm_unlink() failed" << endl;
		}
	}
};

shared_ptr<int> getSharedIntMemory(int num)
{
	void* mem;
	int shmfd = shm_open("/tmp1234", O_CREAT|O_RDWR, S_IRWXU|S_IRWXG);
	if (shmfd < 0) {
		thow string(strerror(errno));
	}
	
}