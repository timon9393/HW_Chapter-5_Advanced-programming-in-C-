#include <iostream>
#include <Windows.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


TEST_CASE("Base test v.2", "[Base2]")
{
    List one;
    one.PushBack(5);
    
    SECTION("PushBack Test")
    {
        INFO("Не пройден тест на добавление нового элемента в конец списка");
        CHECK(one.Size() == 1);
        CHECK(one.Empty() == 0);
    }

    one.PushFront(7);

    SECTION("PushFront Test")
    {        
        INFO("Не пройден тест на добавление нового элемента в начало списка");
        CHECK(one.Size() == 2);
        CHECK(one.Empty() == 0);
    }

    one.PopBack();

    SECTION("PopBack Test")
    {        
        INFO("Не пройден тест на извлечение элемента из конца списка");
        CHECK(one.Size() == 1);
        CHECK(one.Empty() == 0);        
    }

    one.Clear();

    SECTION("Empty PopBack Test")
    {        
        INFO("Не пройден тест на извлечение элемента из конца пустого списка / не выброшено исключение");
        CHECK_THROWS(one.PopBack());
        CHECK(one.Size() == 0);
        CHECK(one.Empty() == 1);
    }

    one.PushBack(15);
    one.PushFront(19);

    SECTION("PopFront Test")
    {
        one.PopFront();
        INFO("Не пройден тест на извлечение элемента из начала списка");
        CHECK(one.Size() == 1);
        CHECK(one.Empty() == 0);        
    }

    one.Clear();

    SECTION("Empty PopFront Test")
    {        
        INFO("Не пройден тест на извлечение элемента из начала пустого списка / не выброшено исключение");
        CHECK_THROWS(one.PopFront());
        CHECK(one.Size() == 0);
        CHECK(one.Empty() == 1);
    }

    one.PushBack(1);
    one.PushFront(3);
    one.PushFront(5);
    one.PopBack();
    one.PushBack(120);
    one.PushBack(15);
    one.PushFront(7);
    one.PopFront();
    one.PopFront();
    one.PushFront(63);

    SECTION("Complex test")
    {
        INFO("Комплексный тест не пройден");
        CHECK(one.Size() == 4);
        CHECK(one.Empty() == 0);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    return Catch::Session().run();
}