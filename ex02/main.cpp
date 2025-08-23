#include "FragTrap.hpp"

int main(void)
{
    // Crear objetos
    std::cout << "=== Creación de objetos ===" << std::endl;
    FragTrap pepe;
    FragTrap luis("Luis");

    // Probar highFivesGuys
    std::cout << "\n=== Probando highFivesGuys ===" << std::endl;
    pepe.highFivesGuys();
    luis.highFivesGuys();

    // Probar ataque
    std::cout << "\n=== Probando attack ===" << std::endl;
    luis.attack("EnemyBot");

    // Probar daño y reparación
    std::cout << "\n=== Probando takeDamage y beRepaired ===" << std::endl;
    luis.takeDamage(30);
    luis.beRepaired(20);

    // Probar constructor de copia
    std::cout << "\n=== Probando constructor de copia ===" << std::endl;
    FragTrap luis_copy(luis);
    luis_copy.attack("AnotherBot");

    // Probar operador de asignación
    std::cout << "\n=== Probando operador de asignación ===" << std::endl;
    FragTrap assign_test("AssignTest");
    assign_test = luis;
    assign_test.attack("YetAnotherBot");

    // Destrucción automática al salir del scope
    std::cout << "\n=== Fin del programa ===" << std::endl;
    return 0;
}