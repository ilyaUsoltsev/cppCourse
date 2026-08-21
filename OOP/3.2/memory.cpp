#include <iostream>

enum type_memory {
  mem_none = -1,
  mem_corsair = 1,
  mem_adata = 2,
  mem_kingston = 3
};

class Memory {
  type_memory type{mem_none};
  unsigned volume;

public:
  Memory() : volume(0) {}
  Memory(unsigned vol) : volume(vol) {}
  Memory(unsigned vol, type_memory tp) : type(tp), volume(vol) {}

  friend void set_memory_data(Memory &mem, unsigned vol, type_memory tp);
  friend void get_memory_data(const Memory &mem, unsigned &vol,
                              type_memory &tp);
  friend Memory operator+(const Memory &m1, const Memory &m2);
};

void set_memory_data(Memory &mem, unsigned vol, type_memory tp) {
  mem.volume = vol;
  mem.type = tp;
}

void get_memory_data(const Memory &mem, unsigned &vol, type_memory &tp) {
  vol = mem.volume;
  tp = mem.type;
}

Memory operator+(const Memory &m1, const Memory &m2) {
  if (m1.type != m2.type)
    return m1;

  return Memory(m1.volume + m2.volume, m1.type);
}

int main() {
  Memory mem_1(8000, mem_adata);
  Memory mem_2(4000, mem_adata);

  Memory res = mem_1 + mem_2;

  // __ASSERT_TESTS__

  return 0;
}
