#include <iostream>

class Model {
public:
    void set_id(unsigned id) {
        this->id = id;
    }
private:
    unsigned id;
};

int main()
{
    Model* m = new Model();
    m->set_id(10);
    std::cout << m->id << std::endl;

    delete m;
    return 0;
}
