#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;

    // N�� �Է� �ޱ�
    std::cout << "N�� �Է��ϼ���: ";
    std::cin >> N;

    // ���� �Է� �ޱ�
    std::cin.ignore();  // ���� ����
    std::cout << "1���� N������ ���� �̷���� ������ �Է��ϼ��� (�������� ����): ";
    std::string input;
    std::getline(std::cin, input);

    // �Էµ� ���ڿ��� �������� �����Ͽ� ���Ϳ� ����
    std::istringstream iss(input);
    std::vector<int> permutation;
    int num;

    while (iss >> num) {
        permutation.push_back(num);
    }

    // �Էµ� ���� ���
    std::cout << "�Էµ� ����: ";
    for (const auto& element : permutation) {
        std::cout << element << " ";
    }

    return 0;
}