#include <iostream>

class StudentMarks {
  enum { max_length = 100 };
  short marks[max_length]{0}; // массив оценок студента
  int count{0};               // количество оценок в массиве marks
public:
  StudentMarks(short *ms, int total) {
    count = (total > max_length) ? max_length : total;

    for (int i = 0; i < count; ++i)
      marks[i] = ms[i];
  }

  StudentMarks operator+(const StudentMarks &right) const {
    int total = this->count + right.count;
    short *ms = new short[total];

    for (int i = 0; i < this->count; ++i)
      ms[i] = this->marks[i];

    for (int i = 0; i < right.count; ++i)
      ms[this->count + i] = right.marks[i];

    StudentMarks res(ms, total);
    delete[] ms;
    return res;
  }

  StudentMarks operator+(short mark) const {
    int total = this->count + 1;
    short *ms = new short[total];

    for (int i = 0; i < this->count; ++i) {
      ms[i] = this->marks[i];
    }

    ms[this->count] = mark;

    StudentMarks res(ms, total);
    delete[] ms;
    return res;
  }

  const short *get_marks() const { return marks; }
  int get_count() const { return count; }
};

int main() {
  short m[] = {2, 2, 3, 2, 3};
  short k[] = {5, 4, 2};
  StudentMarks marks_1(m, sizeof(m) / sizeof(*m));
  StudentMarks marks_2(k, sizeof(k) / sizeof(*k));

  StudentMarks res_1 =
      marks_1 + marks_2; // res_1: marks = {2, 2, 3, 2, 3, 5, 4, 2}, count = 8
  StudentMarks res_2 =
      marks_1 + 4; // res_2: marks = {2, 2, 3, 2, 3, 4}, count = 6

  return 0;
}
