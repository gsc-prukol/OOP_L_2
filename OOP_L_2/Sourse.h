#include <iostream>
#include <queue> 
#include "Data.h"
using namespace std;

class PartyQueue
{
	string surname, phone;
	Date date;
public:
	PartyQueue();
	PartyQueue(string & Surname, string & Phone, Date & Date);
	PartyQueue( const PartyQueue &  sourse);
	~PartyQueue();
	bool operator < (PartyQueue & right);
};
class QueueHousing
{
	priority_queue <PartyQueue> data;
public:
	QueueHousing() {};
	QueueHousing(PartyQueue * sourse, int n);
//	~QueueHousing();
	size_t longQueue() { return data.size(); }
	void push(PartyQueue & element) { data.push(element); }
	PartyQueue pop() { data.pop(); }
};