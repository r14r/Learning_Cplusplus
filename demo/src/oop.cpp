#include "demos.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {
class Person {
  public:
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {}

    void have_birthday() { ++age_; }

    [[nodiscard]] std::string description() const {
        return name_ + " is " + std::to_string(age_) + " years old.";
    }

  private:
    std::string name_;
    int age_;
};

enum class Colour { Red, Green, Blue };

class Shape {
  public:
    Shape(Colour colour) : colour_(colour) {}
    virtual ~Shape() = default;

    [[nodiscard]] Colour colour() const { return colour_; }
    [[nodiscard]] virtual double area() const = 0;

  private:
    Colour colour_;
};

class Rectangle : public Shape {
  public:
    Rectangle(double width, double height, Colour colour)
        : Shape(colour), width_(width), height_(height) {}

    [[nodiscard]] double area() const override { return width_ * height_; }

  private:
    double width_;
    double height_;
};

class Circle : public Shape {
  public:
    Circle(double radius, Colour colour)
        : Shape(colour), radius_(radius) {}

    [[nodiscard]] double area() const override { return 3.14159 * radius_ * radius_; }

  private:
    double radius_;
};

std::string to_string(Colour colour) {
    switch (colour) {
    case Colour::Red:
        return "red";
    case Colour::Green:
        return "green";
    case Colour::Blue:
        return "blue";
    }
    return "unknown";
}
} // namespace

void run_oop_demo() {
    print_section("2. Object-oriented programming");

    Person person{"Jordan", 30};
    std::cout << "Class -> " << person.description() << '\n';
    person.have_birthday();
    std::cout << "After birthday -> " << person.description() << '\n';

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0, Colour::Red));
    shapes.push_back(std::make_unique<Circle>(2.0, Colour::Green));

    std::cout << "Polymorphism ->";
    for (const auto &shape : shapes) {
        std::cout << " " << to_string(shape->colour()) << " area=" << shape->area();
    }
    std::cout << '\n';
}
