class StringBuffer {
  enum { max_size = 1024 };
  char *buffer{nullptr};
  int size{0};

public:
  StringBuffer(const char *str) {
    size = 0;
    while (str[size] != '\0' && size < max_size - 1)
      size++;

    buffer = new char[size + 1];
    for (int i = 0; i < size; ++i)
      buffer[i] = str[i];

    buffer[size] = '\0';
  }

  StringBuffer(const StringBuffer &other) : size(other.size) {
    buffer = new char[size + 1];
    for (int i = 0; i < size; ++i)
      buffer[i] = other.buffer[i];

    buffer[size] = '\0';
  }

  ~StringBuffer() { delete[] buffer; }

  const char *get_data() const { return buffer; }
  int get_size() const { return size; }

  StringBuffer &operator+=(const char *str) {
    int add_size = 0;
    while (str[add_size] != '\0' && size + add_size < max_size - 1)
      add_size++;

    char *new_buffer = new char[size + add_size + 1];
    for (int i = 0; i < size; ++i)
      new_buffer[i] = buffer[i];
    for (int i = 0; i < add_size; ++i)
      new_buffer[size + i] = str[i];

    size += add_size;
    new_buffer[size] = '\0';

    delete[] buffer;
    buffer = new_buffer;

    return *this;
  }
};

StringBuffer operator+(const char *str, const StringBuffer &sb) {
  int prefix_size = 0;
  while (str[prefix_size] != '\0')
    prefix_size++;

  int sb_size = sb.get_size();
  int total_size = prefix_size + sb_size;

  char *combined = new char[total_size + 1];
  int i = 0;
  for (; i < prefix_size; ++i)
    combined[i] = str[i];
  for (int j = 0; j < sb_size; ++i, ++j)
    combined[i] = sb.get_data()[j];
  combined[total_size] = '\0';

  StringBuffer result(combined);
  delete[] combined;
  return result;
}

int main() {
  StringBuffer str("Hello");
  StringBuffer str2{str};
  StringBuffer s1 = "World";
  StringBuffer s2 = "Hello, " + s1; // s2: "Hello, World"
  s2 += "!";                        // s2: "Hello, World!"
}
