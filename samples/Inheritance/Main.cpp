#include <iostream>


// Base class
class Shape
{
public:
    Shape(float x, float y) 
    {
        set(x, y);
    }
    Shape()
    {
        set(0,0);
    }
    virtual ~Shape() {}

    void set(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    const float x() const { return m_x;  }
    const float y() const { return m_y; }

    // 
    virtual void draw()
    {
        std::cout << "Shape\n";

        // Get a drawing context from OpenGL
    }

protected:

    float m_x;
    float m_y;

private:
};

// Circle 'inherits' from Shape
// Circle is 'derived from' from Shape
// Circle 'specializes' Shape
// Circle 'is-a' Shape
class Circle : public Shape
{
public:
    Circle(float x, float y) 
    {
        set(x, y);
    }
    ~Circle() {}

    virtual void draw()
    {
        Shape::draw();

        std::cout << "circle\n";

    }

private:
    float radius;


};

class Rectangle : public Shape
{
public:
    Rectangle(float x, float y)
    {
        set(x, y);
    }
    ~Rectangle() {}

    void draw()
    {
        std::cout << "rectangle\n";
    }

private:

    float length;
    float width;
};



void main()
{
    Shape *shapes[2];

    shapes[0] = new Circle(1,2);
    shapes[1] = new Rectangle(3, 4);

    // Draw all the shapes
    for (size_t i = 0; i < 2; i++)
    {
        shapes[i]->draw();
    }




    for (size_t i = 0; i < 2; i++)
    {
        delete shapes[i];
    }
}