#ifndef STACK_H
#define STACK_H
#define MAX 10

typedef struct customer{
	char fullname[35];
	double payment;
}Item;

class Stack
{
	private:
		Item items[MAX];
		int top;
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item &item);
		bool pop(Item &item);
		
};
#endif

