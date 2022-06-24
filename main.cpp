#include <QCoreApplication>

class A
{
public:
    virtual ~A() {};
    virtual void set() = 0;
};

class B final : public A
{
    int* m_value;

public:
    explicit B()
      : m_value(new int(42))
    {}

    ~B()
    {
        delete m_value;
    }

    void set() override
    {
        delete m_value;
        m_value = new int(42);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    A* b = new B();
    b->set();
    delete b;
    return a.exec();
}
