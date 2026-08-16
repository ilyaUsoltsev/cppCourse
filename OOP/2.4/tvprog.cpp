#include <iostream>
#include <string>

class Item {
    std::string name; // название программы
    unsigned short duration; // длительность в минутах
public:
    Item(const char* name = "", unsigned short duration = 0) : name(name), duration(duration) {
    }
    std::string& get_name() {
        return name;
    }

    unsigned short get_duration() {
        return duration;
    }
};

class TVProg {
    enum {
        max_length = 100
    };
    Item items[max_length]; // программы 
    int count{ 0 };  // число программ
public:
    TVProg() {
    }
    TVProg(const Item* ar, int size) {
        count = (size > max_length) ? max_length : size;
        for (int i = 0; i < count; ++i) {
            items[i] = ar[i];
        }
    }
    void append(const Item& it) {
        if (count < max_length) {
            items[count++] = it;
        }
    }
    void append(const Item* lst, int length) {
        for (int i = 0; i < length && count < max_length; ++i) {
            items[count++] = lst[i];
        }
    }
    Item* get_list() {
        return items;
    }
    int get_count() {
        return count;
    }
};

int main(void)
{
    //     В функции main создайте объект класса TVProg в виде переменной tv и занесите следующие программы передач:

    // Новости, 20
    // Модный приговор, 50
    // Жить здорово!, 60
    // Информационный канал, 15
    // Новости, 15
    // Давай поженимся!, 70
    TVProg tv;
    tv.append(Item("Новости", 20));
    tv.append(Item("Модный приговор", 50));
    tv.append(Item("Жить здорово!", 60));
    tv.append(Item("Информационный канал", 15));
    tv.append(Item("Новости", 15));
    tv.append(Item("Давай поженимся!", 70));

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
