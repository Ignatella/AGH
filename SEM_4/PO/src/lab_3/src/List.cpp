#include <List.h>

void List::print(std::string prefix) const
{
    std::cout << prefix << "[ ";

    for (int el : _v)
        std::cout << el << " ";

    std::cout << "]" << std::endl;
};

List List::filter(std::function<bool(int)> f) const
{
    List result;

    for (int val : _v)
    {
        if (f(val))
        {
            result.insert(val);
        }
    }

    return result;
}
