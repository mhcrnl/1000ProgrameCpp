#include <iostream>
using namespace std;

class Apero {
public:
  Apero() { cout << "L'heure de l'apéro à sonné !" << endl; }
  ~Apero() { cout << "À table !" << endl; }
  void bis() const { cout << "Encore une ?" << endl; }
};

int main() {
  Apero bic;
  cout << "Super !" << endl;
  bic.bis();
  cout << "Non merci." << endl;
  return 0;
}
