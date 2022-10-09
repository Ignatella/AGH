#include <iostream>

class AbstractBase
{
public:
     virtual AbstractBase& clone() const = 0;
     virtual AbstractBase& operator=(const AbstractBase& other) = 0;
     virtual ~AbstractBase() = default;
};

class IntWrapper: public AbstractBase
{
public:
    int val;

public:
    IntWrapper(int v) : val{v} { }
    
    IntWrapper& clone() const
    {
        IntWrapper* new_obj = new IntWrapper(val);
        return *new_obj;
    }

	IntWrapper& operator=(const AbstractBase& other) override
    {
        auto context = static_cast<const IntWrapper&>(other);
        val=context.val;
		return *this;
    }

    ~IntWrapper() override = default;
};

void swap(AbstractBase& a, AbstractBase& b)
{
    AbstractBase& tmp = a.clone();
    a = b;
    b = tmp;
    delete &tmp;
}

int main()
{
    IntWrapper a(3), b(4);

    std::cout << a.val << ", " << b.val << std::endl;  
    swap(a,b);
    std::cout << a.val << ", " << b.val << std::endl;

    return 0;
}