#pragma once
#include <iostream>

class Counter {
public:
    Counter();
    Counter(int& count);
    void plus();
    void minus();
    int view();
private:
    int count = 1; // � ����� ����� ���� �������� ��������� �������� ��� ����������? ��� ��� �� �� ����� ������ � cpp �����?
};