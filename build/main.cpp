#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Student {
  std::string m_first = "First";
  std::string m_last  = "Last";
  int         m_id    = 0; // default value
  float       m_avg   = 0;

  public:

  Student() {}
  
  Student(std::string first, std::string last, int id, float avg)
    : m_first (first),
      m_last  (last),
      m_id    (id),
      m_avg   (avg)
  {}

  int getAvg() const {
    return m_avg;
  }

  int getId() const {
    return m_id;
  }

  std::string getFirst() const {
    return m_first;
  }

  std::string getLast() const {
    return m_last;
  }

  void print() const {
    std::cout << m_first << " " << m_last << " " << m_id << " " << m_avg << " " << "\n";
  }


};

class Course {
  std::string m_name = "Course";
  std::vector<Student> m_students;

public:
  Course() {}
  Course(const std::string& name) : m_name(name) {} // good practice to pass strings by reference, to avoid copying them to the constructor

  void addStudent(const Student& s) {
    m_students.push_back(s);
  }
   
  const std::vector<Student>& getStudents() const {
    return m_students;
  }
 
  void loadFromFile(const std::string& fileName) {
    std::ifstream fileIn(fileName);

    // load string tokens from a file and print them to the screen
    std::string first, last;
    int id;
    float avg;

    while (fileIn >> first) {
      fileIn >> last >> id >> avg;
      addStudent(Student(first, last, id, avg));
    }
  }

  void print() const {
    for (auto& s : m_students) {
      s.print();
    }
  }
};

int main(int argc, char * argv[]) {
  

  Course c("COMP 4300");
  c.loadFromFile("students.txt");
  c.print();
  return 0;
}
 
