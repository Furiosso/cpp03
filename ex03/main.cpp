#include "DiamondTrap.hpp"

// Función para ejecutar y mostrar resultados de las pruebas
void runTest(const std::string& testName, bool condition) {
    std::cout << "Test: " << testName << " -> " << (condition ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    // Test 1: Crear un DiamondTrap y verificar inicialización de atributos
    std::cout << "\n=== Test 1: Creación y atributos iniciales ===\n";
    DiamondTrap diamond("TestBot");
    
    //runTest("Nombre propio de DiamondTrap", diamond.getName() == "TestBot");
   // runTest("Nombre de ClapTrap", diamond.getClapTrapName() == "TestBot_clap_name");
    runTest("Puntos de vida (de FragTrap: 100)", diamond.getHitPoints() == 100);
    runTest("Puntos de energía (de ScavTrap: 50)", diamond.getEnergyPoints() == 50);
    runTest("Daño de ataque (de FragTrap: 30)", diamond.getAttackDamage() == 30);

    // Test 2: Verificar la función whoAmI()
    std::cout << "\n=== Test 2: Función whoAmI() ===\n";
    std::cout << "Ejecutando whoAmI():\n";
    diamond.whoAmI(); // Debe mostrar el nombre de DiamondTrap y el de ClapTrap

    // Test 3: Verificar la función attack() (heredada de ScavTrap)
    std::cout << "\n=== Test 3: Función attack() ===\n";
    std::cout << "Ejecutando attack():\n";
    diamond.attack("TargetDummy"); // Debe usar la versión de ScavTrap

    // Test 4: Verificar comportamiento de daño y reparación
    std::cout << "\n=== Test 4: Daño y reparación ===\n";
    diamond.takeDamage(20);
    runTest("Puntos de vida tras recibir 20 de daño (100 - 20 = 80)", diamond.getHitPoints() == 80);
    diamond.beRepaired(10);
    runTest("Puntos de vida tras reparar 10 (80 + 10 = 90)", diamond.getHitPoints() == 90);

    // Test 5: Verificar límite de energía (ScavTrap)
    std::cout << "\n=== Test 5: Límite de energía ===\n";
    DiamondTrap lowEnergyBot("LowEnergyBot");
    for (int i = 0; i < 50; ++i) {
        lowEnergyBot.attack("Dummy");
    }
    runTest("Sin energía tras 50 ataques", lowEnergyBot.getEnergyPoints() == 0);
    std::cout << "Intentando atacar sin energía:\n";
    lowEnergyBot.attack("Dummy"); // Debería indicar que no hay energía

    // Test 6: Verificar herencia virtual (instancia única de ClapTrap)
    std::cout << "\n=== Test 6: Herencia virtual ===\n";
    DiamondTrap virtualTest("VirtualBot");
    virtualTest.takeDamage(50);
    runTest("Puntos de vida consistentes tras daño (100 - 50 = 50)", virtualTest.getHitPoints() == 50);
    std::cout << "Verificando nombre en ClapTrap:\n";
    virtualTest.whoAmI(); // Debe mostrar un solo nombre de ClapTrap, confirmando una sola instancia

    // Test 7: Verificar comportamiento con copia
    std::cout << "\n=== Test 7: Constructor de copia ===\n";
    DiamondTrap copyBot(diamond);
    runTest("Nombre de copia", copyBot.getName() == diamond.getName());
    runTest("Puntos de vida de copia", copyBot.getHitPoints() == diamond.getHitPoints());

    // Test 8: Verificar comportamiento con asignación
    std::cout << "\n=== Test 8: Operador de asignación ===\n";
    DiamondTrap assignBot("AssignBot");
    assignBot = diamond;
    runTest("Nombre tras asignación", assignBot.getName() == diamond.getName());
    runTest("Puntos de vida tras asignación", assignBot.getHitPoints() == diamond.getHitPoints());

    return 0;
}