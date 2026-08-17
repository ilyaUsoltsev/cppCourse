class Operator {
    long a{ 0 }, b{ 0 }, c{ 0 };
public:
    Operator* create_copy()
    {
        Operator* ptr_obj = new Operator(*this);
        return ptr_obj;
    }
    Operator() = default;
private:
    Operator(const Operator& other) = default;
};
