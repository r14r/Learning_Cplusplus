# C++ Answers and Solutions

# C

---

## Question Set

- Q.1) Write a C++ program to declare a class Student containing data members roll_no and percentage. Accept this data for 2 objects and display the roll_no of the student having highest percentage. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Student {
      int roll_no;
      float percentage;
  public:
      void input() {
          std::cin >> roll_no >> percentage;
      }
      float getPercentage() { return percentage; }
      int getRollNo() { return roll_no; }
  };
  int main() {
      Student s1, s2;
      s1.input(); s2.input();
      if (s1.getPercentage() > s2.getPercentage())
          std::cout << s1.getRollNo();
      else
          std::cout << s2.getRollNo();
      return 0;
  }
  ```

- Q.2) Write a C++ program that:
  - a. Accepts an array of integers from the user.
  - b. Computes the square root of each element.
  - c. Throws and catches an exception if a negative number is encountered. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <cmath>
  int main() {
      int n;
      std::cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++) std::cin >> arr[i];
      for (int i = 0; i < n; i++) {
          try {
              if (arr[i] < 0) throw arr[i];
              std::cout << sqrt(arr[i]) << std::endl;
          } catch (int x) {
              std::cout << "Negative: " << x << std::endl;
          }
      }
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 1

- Q.1) Write a C++ program to create an inline function that returns the length of a given string. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <string>
  inline int strLength(const std::string& s) { return s.length(); }
  int main() {
      std::string s; std::getline(std::cin, s);
      std::cout << strLength(s);
      return 0;
  }
  ```

- Q.2) Write a C++ program to define a class Bus with the following specifications: Bus_No, Bus_Name, No_of_Seats, Starting_point, Destination. Write a menu driven program by using appropriate manipulators to:
  - a. Accept details of ‘n’ buses.
  - b. Display all bus details.
  - c. Display details of bus from specified starting and ending destination by user. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <iomanip>
  #include <vector>
  class Bus {
      int Bus_No, No_of_Seats;
      std::string Bus_Name, Starting_point, Destination;
  public:
      void input() {
          std::cin >> Bus_No >> Bus_Name >> No_of_Seats >> Starting_point >> Destination;
      }
      void display() {
          std::cout << std::setw(5) << Bus_No << std::setw(10) << Bus_Name
                    << std::setw(8) << No_of_Seats << std::setw(15) << Starting_point
                    << std::setw(15) << Destination << std::endl;
      }
      bool matchRoute(const std::string& s, const std::string& d) {
          return Starting_point == s && Destination == d;
      }
  };
  int main() {
      int n, choice;
      std::cin >> n;
      std::vector<Bus> buses(n);
      for (int i = 0; i < n; i++) buses[i].input();
      do {
          std::cin >> choice;
          if (choice == 1) for (auto& b : buses) b.display();
          else if (choice == 2) {
              std::string s, d; std::cin >> s >> d;
              for (auto& b : buses) if (b.matchRoute(s, d)) b.display();
          }
      } while (choice != 3);
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 2

- Q.1) Write a C++ program that reads Book.txt file and displays Books data on the screen. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <fstream>
  int main() {
      std::ifstream fin("Book.txt");
      std::string line;
      while (getline(fin, line)) std::cout << line << std::endl;
      fin.close();
      return 0;
  }
  ```

- Q.2) Write the definition for a class called ‘Point’ that has x & y as integer data members. Use copy constructor to copy one object to another. (Use Default and parameterized constructor to initialize the appropriate objects.) [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Point {
      int x, y;
  public:
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
      Point(const Point& p) : x(p.x), y(p.y) {}
      void display() { std::cout << x << " " << y << std::endl; }
  };
  int main() {
      Point p1(2,3), p2 = p1;
      p1.display(); p2.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 3

- Q.1) Write a program using unordered_map to store and display the names of 3 students with their roll numbers. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <unordered_map>
  int main() {
      std::unordered_map<int, std::string> students;
      for (int i = 0; i < 3; ++i) {
          int roll; std::string name;
          std::cin >> roll >> name;
          students[roll] = name;
      }
      for (auto& s : students)
          std::cout << s.first << " " << s.second << std::endl;
      return 0;
  }
  ```

- Q.2) Create class Person which contains data members as Passport_Id, Person_name, Nationality, Gender, Date_of_Birth, Date_of_Issue, Date_of_expiry. Write a C++ program to perform following member functions:
  - a. Enter details of all persons.
  - b. Display passport details of one person.
  - c. Display passport details of all persons.
  - (Use Function overloading and Array of object.) [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <string>
  class Person {
      std::string Passport_Id, Person_name, Nationality, Gender, DOB, DOI, DOE;
  public:
      void input() {
          std::cin >> Passport_Id >> Person_name >> Nationality >> Gender >> DOB >> DOI >> DOE;
      }
      void display() {
          std::cout << Passport_Id << " " << Person_name << " " << Nationality << " " << Gender
                    << " " << DOB << " " << DOI << " " << DOE << std::endl;
      }
      void display(const std::string& pid) {
          if (Passport_Id == pid) display();
      }
  };
  int main() {
      int n; std::cin >> n;
      Person arr[n];
      for (int i = 0; i < n; i++) arr[i].input();
      std::string pid; std::cin >> pid;
      for (int i = 0; i < n; i++) arr[i].display(pid);
      for (int i = 0; i < n; i++) arr[i].display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

*... (Continue in this format for all slips and questions as above, up to Slip 24, as in previous responses.)*

---

## Slip 4

- Q.1) Write a program to define a class Cube with following members – length, width, depth and volume(). Write code for the function volume which calculates volume of a cube. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Cube {
      float length, width, depth;
  public:
      void input() { std::cin >> length >> width >> depth; }
      float volume() { return length * width * depth; }
  };
  int main() {
      Cube c; c.input();
      std::cout << "Volume: " << c.volume();
      return 0;
  }
  ```

- Q.2) Write C++ program of Simple Calculator:
  - a. Implement a calculator with operations: +, −, *, /.
  - b. Throw an exception for division by zero or invalid operator. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  int main() {
      double a, b, result; char op;
      std::cin >> a >> op >> b;
      try {
          switch(op) {
              case '+': result = a + b; break;
              case '-': result = a - b; break;
              case '*': result = a * b; break;
              case '/':
                  if (b == 0) throw "Division by zero!";
                  result = a / b; break;
              default: throw "Invalid operator!";
          }
          std::cout << "Result: " << result;
      } catch(const char* msg) {
          std::cout << msg;
      }
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 5

- Q.1) Write a C++ program using class to calculate simple interest amount. (Use parameterized constructor with default value for rate.) [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class SimpleInterest {
      float principal, rate, time, interest;
  public:
      SimpleInterest(float p, float t, float r=5.0) {
          principal = p; time = t; rate = r;
          interest = (principal * rate * time) / 100;
      }
      void display() { std::cout << "Interest: " << interest; }
  };
  int main() {
      SimpleInterest si(1000, 2); // default rate
      si.display();
      return 0;
  }
  ```

- Q.2) Create a class Date with members as dd, mm, yyyy. Write a C++ program for overloading operators >> and << to accept and display a Date. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Date {
      int dd, mm, yyyy;
  public:
      friend std::istream& operator>>(std::istream& in, Date& d) {
          in >> d.dd >> d.mm >> d.yyyy;
          return in;
      }
      friend std::ostream& operator<<(std::ostream& out, const Date& d) {
          out << d.dd << "-" << d.mm << "-" << d.yyyy;
          return out;
      }
  };
  int main() {
      Date d; std::cin >> d; std::cout << d;
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 6

- Q.1) Design a base class Product (Product_Id, Product_Name, Price). Derive a class Discount (Discount_In_Percentage) from Product. A customer buys ‘n’ Products. Calculate total price, total discount and display bill using appropriate manipulators. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <iomanip>
  class Product {
  protected:
      int id; std::string name; float price;
  public:
      void input() { std::cin >> id >> name >> price; }
      float getPrice() { return price; }
  };
  class Discount : public Product {
      float discount;
  public:
      void input() {
          Product::input();
          std::cin >> discount;
      }
      float getDiscount() { return price * discount / 100; }
  };
  int main() {
      int n; std::cin >> n;
      Discount arr[n];
      float total = 0, totalDisc = 0;
      for(int i=0;i<n;i++) { arr[i].input(); total += arr[i].getPrice(); totalDisc += arr[i].getDiscount(); }
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Total: " << total << "\nDiscount: " << totalDisc << "\nBill: " << total-totalDisc;
      return 0;
  }
  ```

- Q.2) Write a C++ program that appends the contents of one file to another file. [20M]

  **Solution:**  

  ```cpp
  #include <fstream>
  #include <string>
  int main() {
      std::ifstream fin("file1.txt");
      std::ofstream fout("file2.txt", std::ios::app);
      std::string line;
      while (getline(fin, line)) fout << line << std::endl;
      fin.close(); fout.close();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 7

- Q.1) Write a program to define a class ‘Rectangle’ having data members length and breadth. Accept this data for one object and display area and perimeter of rectangle. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Rectangle {
      float length, breadth;
  public:
      void input() { std::cin >> length >> breadth; }
      float area() { return length * breadth; }
      float perimeter() { return 2 * (length + breadth); }
  };
  int main() {
      Rectangle r; r.input();
      std::cout << "Area: " << r.area() << "\nPerimeter: " << r.perimeter();
      return 0;
  }
  ```

- Q.2) Write a program for combining two strings also show the execution of dynamic constructor. For this declare a class ‘Mystring’ with data members as name and length. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <cstring>
  class Mystring {
      char* name;
      int length;
  public:
      Mystring(const char* s) {
          length = strlen(s);
          name = new char[length+1];
          strcpy(name, s);
      }
      Mystring(const Mystring& m) {
          length = m.length;
          name = new char[length+1];
          strcpy(name, m.name);
      }
      ~Mystring() { delete[] name; }
      Mystring combine(const Mystring& m) {
          char* temp = new char[length + m.length + 1];
          strcpy(temp, name); strcat(temp, m.name);
          Mystring result(temp);
          delete[] temp;
          return result;
      }
      void display() { std::cout << name << std::endl; }
  };
  int main() {
      Mystring s1("Hello"), s2("World");
      Mystring s3 = s1.combine(s2);
      s3.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 8

- Q.1) Write a program to declare a class Product containing data members product_code, name and price. Accept and display this information for 2 objects. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Product {
      int code; std::string name; float price;
  public:
      void input() { std::cin >> code >> name >> price; }
      void display() { std::cout << code << " " << name << " " << price << std::endl; }
  };
  int main() {
      Product p1, p2; p1.input(); p2.input();
      p1.display(); p2.display();
      return 0;
  }
  ```

- Q.2) Write a C++ program to merge two files into a single file using file handling. Assuming that a text file named FIRST.TXT contains some text written into it, write a function named vowelwords(), that reads the file FIRST.TXT and creates a new file named SECOND.TXT, to contain only those words from the file FIRST.TXT which start with a lower-case vowel (i.e., with 'a','e','i','o','u'). For example, if the file FIRST.TXT contains Carry umbrella and overcoat when it rains, then the file SECOND.TXT shall contain umbrella, and, overcoat, it. [20M]

  **Solution:**  

  ```cpp
  #include <fstream>
  #include <string>
  bool isVowel(char c) {
      return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
  }
  void vowelwords() {
      std::ifstream fin("FIRST.TXT");
      std::ofstream fout("SECOND.TXT");
      std::string word;
      while (fin >> word) {
          if (isVowel(word[0])) fout << word << " ";
      }
      fin.close(); fout.close();
  }
  int main() { vowelwords(); return 0; }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 9

- Q.1) Write a C++ program to create a class Mobile which contains data members as Mobile_Id, Mobile_Name, Mobile_Price. Create and initialize all values of Mobile object by using parameterized constructor. Display the values of Mobile object where Mobile_price should be right justified with a precision of two digits. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <iomanip>
  class Mobile {
      int id; std::string name; float price;
  public:
      Mobile(int i, std::string n, float p) : id(i), name(n), price(p) {}
      void display() {
          std::cout << id << " " << name << " " << std::right << std::setw(10)
                    << std::fixed << std::setprecision(2) << price << std::endl;
      }
  };
  int main() {
      Mobile m(1, "iPhone", 999.99);
      m.display();
      return 0;
  }
  ```

- Q.2) Create a base class Shape. Derive three different classes Circle, Rectangle and Triangle from Shape class. Write a C++ program to calculate area of Circle, Rectangle and Triangle. (Use pure virtual function.) [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #define PI 3.14
  class Shape {
  public:
      virtual float area() = 0;
  };
  class Circle : public Shape {
      float r;
  public:
      Circle(float x) : r(x) {}
      float area() { return PI * r * r; }
  };
  class Rectangle : public Shape {
      float l, b;
  public:
      Rectangle(float x, float y) : l(x), b(y) {}
      float area() { return l * b; }
  };
  class Triangle : public Shape {
      float b, h;
  public:
      Triangle(float x, float y) : b(x), h(y) {}
      float area() { return 0.5 * b * h; }
  };
  int main() {
      Circle c(2); Rectangle r(2,3); Triangle t(3,4);
      std::cout << c.area() << " " << r.area() << " " << t.area();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 10

- Q.1) Create a class Person with data members name and age. Derive a class Student from Person that adds roll_no and marks. Display all information using a function. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Person {
  protected:
      std::string name;
      int age;
  public:
      void input() { std::cin >> name >> age; }
  };
  class Student : public Person {
      int roll_no;
      float marks;
  public:
      void input() {
          Person::input();
          std::cin >> roll_no >> marks;
      }
      void display() {
          std::cout << name << " " << age << " " << roll_no << " " << marks << std::endl;
      }
  };
  int main() {
      Student s; s.input(); s.display();
      return 0;
  }
  ```

- Q.2) Write a C++ program to read Item information such as Itemno, Itemname, Itemprice, Quantity of ‘n’ Items. Write the Item information using file handling. [20M]

  **Solution:**  

  ```cpp
  #include <fstream>
  #include <string>
  int main() {
      int n; std::cin >> n;
      std::ofstream fout("items.txt");
      for(int i=0;i<n;i++) {
          int no, qty; std::string name; float price;
          std::cin >> no >> name >> price >> qty;
          fout << no << " " << name << " " << price << " " << qty << std::endl;
      }
      fout.close();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 11

- Q.1) Write a C++ program to print area of circle, square using inline function. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #define PI 3.14
  inline float areaCircle(float r) { return PI * r * r; }
  inline float areaSquare(float s) { return s * s; }
  int main() {
      float r, s; std::cin >> r >> s;
      std::cout << "Circle: " << areaCircle(r) << "\nSquare: " << areaSquare(s);
      return 0;
  }
  ```

- Q.2) Write a C++ program to create a class Date which contains three data members as dd, mm, and yyyy. Create and initialize the object by using parameterized constructor and display date in dd Mon-yyyy format. (Input: 19-12-2025 Output: 19-Dec-2025.) Perform validation for month. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <string>
  class Date {
      int dd, mm, yyyy;
      static const std::string months[13];
  public:
      Date(int d, int m, int y) : dd(d), mm(m), yyyy(y) {}
      void display() {
          if(mm < 1 || mm > 12) std::cout << "Invalid month";
          else std::cout << dd << "-" << months[mm] << "-" << yyyy;
      }
  };
  const std::string Date::months[13] = {"", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  int main() {
      int d,m,y; std::cin >> d >> m >> y;
      Date dt(d,m,y); dt.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 12

- Q.1) Write a C++ program to calculate area of cone, sphere and circle by using function overloading. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <cmath>
  #define PI 3.14
  float area(float r) { return PI * r * r; } // Circle
  float area(float r, float h) { return PI * r * (r + sqrt(h*h + r*r)); } // Cone
  float area(float r, int dummy) { return 4 * PI * r * r; } // Sphere
  int main() {
      float r, h; std::cin >> r >> h;
      std::cout << "Circle: " << area(r) << "\nCone: " << area(r,h) << "\nSphere: " << area(r,1);
      return 0;
  }
  ```

- Q.2) Write a C++ program on Student Grading System:
  - a. Accept student data (name, marks).
  - b. Throw exceptions for:
    - Marks > 100 or < 0.
    - Empty name. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <string>
  int main() {
      std::string name; int marks;
      try {
          std::getline(std::cin, name);
          std::cin >> marks;
          if(name.empty()) throw "Empty name";
          if(marks < 0 || marks > 100) throw "Invalid marks";
          std::cout << name << " " << marks;
      } catch(const char* msg) {
          std::cout << msg;
      }
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 13

- Q.1) Write a program to find sum of numbers between 1 to n using constructor where value of n will be passed to the constructor. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Sum {
      int n, total;
  public:
      Sum(int x) : n(x), total(0) {
          for(int i=1;i<=n;i++) total += i;
      }
      void display() { std::cout << total; }
  };
  int main() {
      int n; std::cin >> n;
      Sum s(n); s.display();
      return 0;
  }
  ```

- Q.2) Create class College containing data members as College_Id, College_Name, Establishment_year, University_Name. Write a C++ program with following functions:
  - a. Accept n College details.
  - b. Display College details of specified University.
  - c. Display College details according to Establishment year.
  - (Use Array of Objects and Function Overloading.) [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <string>
  class College {
      int id, year;
      std::string name, uni;
  public:
      void input() { std::cin >> id >> name >> year >> uni; }
      void display() { std::cout << id << " " << name << " " << year << " " << uni << std::endl; }
      void display(const std::string& u) { if(uni == u) display(); }
      void display(int y) { if(year == y) display(); }
  };
  int main() {
      int n; std::cin >> n;
      College arr[n];
      for(int i=0;i<n;i++) arr[i].input();
      std::string u; int y; std::cin >> u >> y;
      for(int i=0;i<n;i++) arr[i].display(u);
      for(int i=0;i<n;i++) arr[i].display(y);
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 14

- Q.1) Write a C++ program to create an inline function to calculate the area of a rectangle with default value for width. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  inline float area(float l, float w=1) { return l * w; }
  int main() {
      float l, w; std::cin >> l >> w;
      std::cout << area(l, w);
      return 0;
  }
  ```

- Q.2) Design a two base classes Employee (Name, Designation) and Project(Project_Id, title). Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven program to:
  - a. Build a master table.
  - b. Display a master table.
  - c. Display Project details in the ascending order of duration. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>
  class Employee {
  protected:
      std::string name, desig;
  public:
      void input() { std::cin >> name >> desig; }
  };
  class Project {
  protected:
      int pid; std::string title;
  public:
      void input() { std::cin >> pid >> title; }
  };
  class Emp_Proj : public Employee, public Project {
      int duration;
  public:
      void input() { Employee::input(); Project::input(); std::cin >> duration; }
      void display() { std::cout << name << " " << desig << " " << pid << " " << title << " " << duration << std::endl; }
      int getDuration() const { return duration; }
  };
  int main() {
      int n; std::cin >> n;
      std::vector<Emp_Proj> arr(n);
      for(int i=0;i<n;i++) arr[i].input();
      std::sort(arr.begin(), arr.end(), [](const Emp_Proj& a, const Emp_Proj& b){ return a.getDuration() < b.getDuration(); });
      for(auto& e : arr) e.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 15

- Q.1) Write a program that counts the frequency of each character in a user-entered string using unordered_map. [10M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <unordered_map>
  int main() {
      std::string s; std::getline(std::cin, s);
      std::unordered_map<char, int> freq;
      for(char c : s) freq[c]++;
      for(auto& p : freq) std::cout << p.first << ": " << p.second << std::endl;
      return 0;
  }
  ```

- Q.2) Create a C++ class Employee with data members E_no, E_Name, Designation and Salary. Accept two employee’s information and display information of employee having maximum salary. (Use this pointer.) [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  class Employee {
      int no; std::string name, desig; float salary;
  public:
      void input() { std::cin >> no >> name >> desig >> salary; }
      void display() { std::cout << no << " " << name << " " << desig << " " << salary << std::endl; }
      float getSalary() { return this->salary; }
  };
  int main() {
      Employee e1, e2; e1.input(); e2.input();
      if(e1.getSalary() > e2.getSalary()) e1.display(); else e2.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 16

- Q.1) Write a C++ program to count the number of words in the given file. [10M]

  **Solution:**  

  ```cpp
  #include <fstream>
  #include <string>
  int main() {
      std::ifstream fin("file.txt");
      std::string word; int count = 0;
      while(fin >> word) count++;
      std::cout << count;
      fin.close();
      return 0;
  }
  ```

- Q.2) Create a Base class Flight containing protected data members as Flight_no, Flight_Name. Derive a class Route (Source, Destination) from class Flight. Also derive a class Reservation (Number_Of_Seats, Class, Fare, Travel_Date) from Route. Write a C++ program to perform following necessary functions:
  - a. Enter details of n reservations.
  - b. Display details of all reservations.
  - c. Display reservation details of a Business class. [20M]

  **Solution:**  

  ```cpp
  #include <iostream>
  #include <vector>
  class Flight {
  protected:
      int no; std::string name;
  public:
      void input() { std::cin >> no >> name; }
  };
  class Route : public Flight {
  protected:
      std::string src, dest;
  public:
      void input() { Flight::input(); std::cin >> src >> dest; }
  };
  class Reservation : public Route {
      int seats; std::string cls, date; float fare;
  public:
      void input() { Route::input(); std::cin >> seats >> cls >> fare >> date; }
      void display() { std::cout << no << " " << name << " " << src << " " << dest << " " << seats << " " << cls << " " << fare << " " << date << std::endl; }
      std::string getClass() { return cls; }
  };
  int main() {
      int n; std::cin >> n;
      std::vector<Reservation> arr(n);
      for(int i=0;i<n;i++) arr[i].input();
      for(auto& r : arr) r.display();
      for(auto& r : arr) if(r.getClass() == "Business") r.display();
      return 0;
  }
  ```

- Q.3) External Viva. [5M]

  **Solution:**  
  No code required.

- Q.4) Internal Evaluation. [15M]

  **Solution:**  
  No code required.

---

## Slip 17

- Q.1) Write a C++ program to define a class Product with data members: productCode, productName, and weight. Accept the details of a product from the user. If weight > 100, then throw an exception and display a proper error message. Otherwise, display the product details. [10M]

  **Solution:**  
  Use exception handling for weight validation.

  ```cpp
  #include <iostream>
  class Product {
      int code;
      std::string name;
      float weight;
  public:
      void input() {
          std::cin >> code >> name >> weight;
      }
      void display() {
          std::cout << code << " " << name << " " << weight << std::endl;
      }
      float getWeight() { return weight; }
  };
  int main() {
      Product p;
      p.input();
      try {
          if(p.getWeight() > 100) throw "Weight exceeds 100!";
          p.display();
      } catch(const char* msg) {
          std::cout << msg;
      }
      return 0;
  }
  ```

- Q.2) Create a class Distance with feet and inches as private members. Write a friend function to add two Distance objects. [20M]

  **Solution:**  
  Use a friend function for addition.

  ```cpp
  #include <iostream>
  class Distance {
      int feet, inches;
  public:
      Distance(int f=0, int i=0) : feet(f), inches(i) {}
      friend Distance add(Distance, Distance);
      void display() { std::cout << feet << " feet " << inches << " inches\n"; }
  };
  Distance add(Distance d1, Distance d2) {
      int f = d1.feet + d2.feet;
      int i = d1.inches + d2.inches;
      if(i >= 12) { f += i/12; i = i%12; }
      return Distance(f, i);
  }
  int main() {
      Distance d1(5,8), d2(3,9);
      Distance d3 = add(d1, d2);
      d3.display();
      return 0;
  }
  ```

---

## Slip 18

- Q.1) Write a C++ program to create a class Integer. Write a C++ program to implement necessary member functions to overload the operator unary pre and post decrement ‘--’ for an integer number. [10M]

  **Solution:**  
  Overload pre and post decrement operators.

  ```cpp
  #include <iostream>
  class Integer {
      int n;
  public:
      Integer(int x) : n(x) {}
      Integer& operator--() { --n; return *this; }
      Integer operator--(int) { Integer temp = *this; n--; return temp; }
      void display() { std::cout << n << std::endl; }
  };
  int main() {
      Integer a(10);
      --a; a.display();
      a--; a.display();
      return 0;
  }
  ```

- Q.2) Create a dictionary using unordered_map to store country-capital pairs. Allow the user to:
  - a. Add entries.
  - b. Search for capital by country name.
  - c. Display all entries. [20M]

  **Solution:**  
  Use unordered_map for dictionary.

  ```cpp
  #include <iostream>
  #include <unordered_map>
  int main() {
      std::unordered_map<std::string, std::string> dict;
      int n; std::cin >> n;
      for(int i=0;i<n;i++) {
          std::string country, capital;
          std::cin >> country >> capital;
          dict[country] = capital;
      }
      std::string search; std::cin >> search;
      if(dict.find(search) != dict.end())
          std::cout << dict[search] << std::endl;
      for(auto& p : dict)
          std::cout << p.first << " - " << p.second << std::endl;
      return 0;
  }
  ```

---

## Slip 19

- Q.1) Write a program that reads two integers and divides the first by the second. Use exception handling to catch division by zero. [10M]

  **Solution:**  
  Use try-catch for division.

  ```cpp
  #include <iostream>
  int main() {
      int a, b;
      std::cin >> a >> b;
      try {
          if(b == 0) throw "Division by zero!";
          std::cout << a / b;
      } catch(const char* msg) {
          std::cout << msg;
      }
      return 0;
  }
  ```

- Q.2) Create a Base class Train containing protected data members as Train_no, Train_Name. Derive a class Route (Route_id, Source, Destination) from Train class. Also derive a class Reservation (Number_of_Seats, Train_Class, Fare, Travel_Date) from Route. Write a C++ program to perform following necessary functions:
  - a. Enter details of ‘n’ reservations.
  - b. Display details of all reservations.
  - c. Display reservation details of a specified Train class. [20M]

  **Solution:**  
  Use multilevel inheritance and filter by class.

  ```cpp
  #include <iostream>
  #include <vector>
  class Train {
  protected:
      int no; std::string name;
  public:
      void input() { std::cin >> no >> name; }
  };
  class Route : public Train {
  protected:
      int rid; std::string src, dest;
  public:
      void input() { Train::input(); std::cin >> rid >> src >> dest; }
  };
  class Reservation : public Route {
      int seats; std::string tclass, date; float fare;
  public:
      void input() { Route::input(); std::cin >> seats >> tclass >> fare >> date; }
      void display() { std::cout << no << " " << name << " " << rid << " " << src << " " << dest << " " << seats << " " << tclass << " " << fare << " " << date << std::endl; }
      std::string getClass() { return tclass; }
  };
  int main() {
      int n; std::cin >> n;
      std::vector<Reservation> arr(n);
      for(int i=0;i<n;i++) arr[i].input();
      for(auto& r : arr) r.display();
      std::string cls; std::cin >> cls;
      for(auto& r : arr) if(r.getClass() == cls) r.display();
      return 0;
  }
  ```

---

## Slip 20

- Q.1) Create a C++ class Integer that contains one integer data member. Overload following binary operators (+, -, *, /). [10M]

  **Solution:**  
  Overload binary operators.

  ```cpp
  #include <iostream>
  class Integer {
      int n;
  public:
      Integer(int x=0) : n(x) {}
      Integer operator+(const Integer& b) { return Integer(n + b.n); }
      Integer operator-(const Integer& b) { return Integer(n - b.n); }
      Integer operator*(const Integer& b) { return Integer(n * b.n); }
      Integer operator/(const Integer& b) { return Integer(n / b.n); }
      void display() { std::cout << n << std::endl; }
  };
  int main() {
      Integer a(10), b(2);
      (a+b).display(); (a-b).display(); (a*b).display(); (a/b).display();
      return 0;
  }
  ```

- Q.2) Write a C++ program to create a base class Media with data members title and price. Derive two classes Book and Tape from Media. Use virtual functions to display details of each media. [20M]

  **Solution:**  
  Use virtual functions for polymorphism.

  ```cpp
  #include <iostream>
  class Media {
  protected:
      std::string title;
      float price;
  public:
      virtual void input() { std::cin >> title >> price; }
      virtual void display() = 0;
  };
  class Book : public Media {
      int pages;
  public:
      void input() { Media::input(); std::cin >> pages; }
      void display() { std::cout << title << " " << price << " " << pages << std::endl; }
  };
  class Tape : public Media {
      float time;
  public:
      void input() { Media::input(); std::cin >> time; }
      void display() { std::cout << title << " " << price << " " << time << std::endl; }
  };
  int main() {
      Book b; Tape t;
      b.input(); t.input();
      Media* m1 = &b; Media* m2 = &t;
      m1->display(); m2->display();
      return 0;
  }
  ```

---

## Slip 21

- Q.1) Write a C++ program to read a text file and count number of Uppercase Alphabets, Lowercase Alphabets, Digits and Spaces in it using File Handling. [10M]

  **Solution:**  
  Count character types from file.

  ```cpp
  #include <fstream>
  #include <cctype>
  int main() {
      std::ifstream fin("file.txt");
      char c; int up=0, low=0, dig=0, sp=0;
      while(fin.get(c)) {
          if(isupper(c)) up++;
          else if(islower(c)) low++;
          else if(isdigit(c)) dig++;
          else if(isspace(c)) sp++;
      }
      std::cout << up << " " << low << " " << dig << " " << sp;
      fin.close();
      return 0;
  }
  ```

- Q.2) Consider a class Point containing x and y coordinates. Write a C++ program to implement necessary functions to accept a point, to display a point and to find distance between two points using operator overloading (-). (Use friend function.) [20M]

  **Solution:**  
  Overload - operator as friend.

  ```cpp
  #include <iostream>
  #include <cmath>
  class Point {
      int x, y;
  public:
      void input() { std::cin >> x >> y; }
      void display() { std::cout << x << " " << y << std::endl; }
      friend float operator-(Point, Point);
  };
  float operator-(Point a, Point b) {
      return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
  }
  int main() {
      Point p1, p2; p1.input(); p2.input();
      std::cout << "Distance: " << (p1-p2);
      return 0;
  }
  ```

---

## Slip 22

- Q.1) Write a C++ program using function to count and display the number of lines not starting with alphabet ‘C’ in a text file. [10M]

  **Solution:**  
  Check first character of each line.

  ```cpp
  #include <fstream>
  #include <string>
  int main() {
      std::ifstream fin("file.txt");
      std::string line; int count=0;
      while(getline(fin, line)) {
          if(line.empty() || line[0]!='C') count++;
      }
      std::cout << count;
      fin.close();
      return 0;
  }
  ```

- Q.2) Write a program to design a class Complex to represent complex number. The Complex class should use an external function (use it as a friend function) to add two complex number. The function should return an object of type complex representing the sum of two complex numbers. [20M]

  **Solution:**  
  Use friend function for addition.

  ```cpp
  #include <iostream>
  class Complex {
      float re, im;
  public:
      Complex(float r=0, float i=0) : re(r), im(i) {}
      friend Complex add(Complex, Complex);
      void display() { std::cout << re << " + " << im << "i" << std::endl; }
  };
  Complex add(Complex a, Complex b) {
      return Complex(a.re + b.re, a.im + b.im);
  }
  int main() {
      Complex c1(1,2), c2(3,4);
      Complex c3 = add(c1, c2);
      c3.display();
      return 0;
  }
  ```

---

## Slip 23

- Q.1) Write a C++ program to create a class Number which contains two integer data members. Create and initialize the object by using default constructor, parameterized constructor. Write a member function to display maximum from given two numbers for all objects. [10M]

  **Solution:**  
  Use constructors and max function.

  ```cpp
  #include <iostream>
  class Number {
      int a, b;
  public:
      Number() : a(0), b(0) {}
      Number(int x, int y) : a(x), b(y) {}
      void displayMax() { std::cout << (a > b ? a : b) << std::endl; }
  };
  int main() {
      Number n1, n2(5,10);
      n1.displayMax(); n2.displayMax();
      return 0;
  }
  ```

- Q.2) Create a class Employee and use a friend function to calculate the average salary from an array of employees. [20M]

  **Solution:**  
  Use friend function for average.

  ```cpp
  #include <iostream>
  class Employee {
      float salary;
  public:
      void input() { std::cin >> salary; }
      friend float average(Employee[], int);
  };
  float average(Employee arr[], int n) {
      float sum=0;
      for(int i=0;i<n;i++) sum += arr[i].salary;
      return sum/n;
  }
  int main() {
      int n; std::cin >> n;
      Employee arr[n];
      for(int i=0;i<n;i++) arr[i].input();
      std::cout << "Average: " << average(arr, n);
      return 0;
  }
  ```

---

## Slip 24

- Q.1) Write a C++ program to create a class Employee having data members emp_id and emp_name and basic_salary. Accept this data for 5 variables and display the details of employee having salary > 5000. [10M]

  **Solution:**  
  Filter employees by salary.

  ```cpp
  #include <iostream>
  class Employee {
      int id; std::string name; float salary;
  public:
      void input() { std::cin >> id >> name >> salary; }
      void display() { std::cout << id << " " << name << " " << salary << std::endl; }
      float getSalary() { return salary; }
  };
  int main() {
      Employee arr[5];
      for(int i=0;i<5;i++) arr[i].input();
      for(int i=0;i<5;i++) if(arr[i].getSalary() > 5000) arr[i].display();
      return 0;
  }
  ```

- Q.2) Write a C++ program to create a class Student with data members roll_no, name and marks. Use a friend function to find and display the student with the highest marks among two students. [20M]

  **Solution:**  
  Use friend function for comparison.

  ```cpp
  #include <iostream>
  class Student {
      int roll_no; std::string name; float marks;
  public:
      void input() { std::cin >> roll_no >> name >> marks; }
      friend void highest(Student, Student);
  };
  void highest(Student a, Student b) {
      if(a.marks > b.marks)
          std::cout << a.roll_no << " " << a.name << " " << a.marks << std::endl;
      else
          std::cout << b.roll_no << " " << b.name << " " << b.marks << std::endl;
  }
  int main() {
      Student s1, s2; s1.input(); s2.input();
      highest(s1, s2);
      return 0;
  }
  ```
