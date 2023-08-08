#include <string>
#define MAX_ARR 200
using namespace std;
class Character{
    class Weapon{
        public:
            Weapon(int damage);
        private:
            int damage;
    };
    public:
        Character(const string&n, int h, int damage);
    private:
        string name;
        int health;
        Weapon weapon;
};
