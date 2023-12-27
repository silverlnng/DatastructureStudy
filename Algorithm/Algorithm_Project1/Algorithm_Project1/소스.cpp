#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;

    // N값 입력 받기
    std::cout << "N을 입력하세요: ";
    std::cin >> N;

    // 순열 입력 받기
    std::cin.ignore();  // 버퍼 비우기
    std::cout << "1부터 N까지의 수로 이루어진 순열을 입력하세요 (공백으로 구분): ";
    std::string input;
    std::getline(std::cin, input);

    // 입력된 문자열을 공백으로 구분하여 벡터에 저장
    std::istringstream iss(input);
    std::vector<int> permutation;
    int num;

    while (iss >> num) {
        permutation.push_back(num);
    }

    // 입력된 순열 출력
    std::cout << "입력된 순열: ";
    for (const auto& element : permutation) {
        std::cout << element << " ";
    }

    return 0;
}