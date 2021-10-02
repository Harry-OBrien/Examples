#include <iostream>
#include <string>

std::string strikethrough(const std::string& text) {
  std::string result;
  for (auto ch : text) {
    result.append(u8"\u0336");
    result.push_back(ch);
  }
  return result;
}

int main() {
  std::cout << strikethrough("strikethrough") << std::endl;
}
