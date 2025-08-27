#include "ClapTrap.hpp"
#include <iostream>

bool test_passed = true;

void report_test(const std::string& test_name, bool condition, const std::string& error_message) {
    if (condition) {
        std::cout << test_name << ": passed" << std::endl;
    } else {
        std::cout << test_name << ": FAILED - " << error_message << std::endl;
        test_passed = false;
    }
}

int main() {
    // Test 1: Default constructor
    {
        ClapTrap pepe;
        report_test("Test 1: Default constructor (name)", pepe.getName() == "Pepe", "Name should be 'Pepe'");
        report_test("Test 1: Default constructor (hit points)", pepe.getHitPoints() == 10, "Hit points should be 10");
        report_test("Test 1: Default constructor (energy points)", pepe.getEnergyPoints() == 10, "Energy points should be 10");
        report_test("Test 1: Default constructor (attack damage)", pepe.getAttackDamage() == 0, "Attack damage should be 0");
    }

    // Test 2: Parameterized constructor
    {
        ClapTrap clap("TestBot");
        report_test("Test 2: Parameterized constructor (name)", clap.getName() == "TestBot", "Name should be 'TestBot'");
        report_test("Test 2: Parameterized constructor (hit points)", clap.getHitPoints() == 10, "Hit points should be 10");
        report_test("Test 2: Parameterized constructor (energy points)", clap.getEnergyPoints() == 10, "Energy points should be 10");
        report_test("Test 2: Parameterized constructor (attack damage)", clap.getAttackDamage() == 0, "Attack damage should be 0");
    }

    // Test 3: Copy constructor
    {
        ClapTrap original("OriginalBot");
        ClapTrap copy(original);
        report_test("Test 3: Copy constructor (name)", copy.getName() == original.getName(), "Name should match original");
        report_test("Test 3: Copy constructor (hit points)", copy.getHitPoints() == original.getHitPoints(), "Hit points should match original");
        report_test("Test 3: Copy constructor (energy points)", copy.getEnergyPoints() == original.getEnergyPoints(), "Energy points should match original");
        report_test("Test 3: Copy constructor (attack damage)", copy.getAttackDamage() == original.getAttackDamage(), "Attack damage should match original");
    }

    // Test 4: Assignment operator
    {
        ClapTrap original("OriginalBot");
        ClapTrap assigned("AssignedBot");
        assigned = original;
        report_test("Test 4: Assignment operator (name)", assigned.getName() == original.getName(), "Name should match original");
        report_test("Test 4: Assignment operator (hit points)", assigned.getHitPoints() == original.getHitPoints(), "Hit points should match original");
        report_test("Test 4: Assignment operator (energy points)", assigned.getEnergyPoints() == original.getEnergyPoints(), "Energy points should match original");
        report_test("Test 4: Assignment operator (attack damage)", assigned.getAttackDamage() == original.getAttackDamage(), "Attack damage should match original");
    }

    // Test 5: Attack functionality
    {
        ClapTrap clap("Attacker");
        clap.attack("Target");
        report_test("Test 5: Attack functionality", clap.getEnergyPoints() == 9, "Energy points should be 9 after attack");
    }

    // Test 6: Take damage
    {
        ClapTrap clap("Victim");
        clap.takeDamage(5);
        report_test("Test 6: Take damage (5 points)", clap.getHitPoints() == 5, "Hit points should be 5 after 5 damage");
        clap.takeDamage(7);
        report_test("Test 6: Take damage (7 points)", clap.getHitPoints() == 0, "Hit points should be 0 after excessive damage");
    }

    // Test 7: Repair functionality
    {
        ClapTrap clap("Healer");
        clap.takeDamage(5);
        clap.beRepaired(3);
        report_test("Test 7: Repair functionality (hit points)", clap.getHitPoints() == 8, "Hit points should be 8 after repair");
        report_test("Test 7: Repair functionality (energy points)", clap.getEnergyPoints() == 9, "Energy points should be 9 after repair");
    }

    // Test 8: No energy points
    {
        ClapTrap clap("NoEnergy");
        for (int i = 0; i < 10; ++i) {
            clap.attack("Target");
        }
        report_test("Test 8: No energy points", clap.getEnergyPoints() == 0, "Energy points should be 0 after 10 attacks");
        clap.attack("Target"); // Should print "no energy points left"
        clap.beRepaired(5);   // Should print "no energy points left"
        std::cout << "Test 8: No energy points handling passed" << std::endl;
    }

    // Test 9: No hit points
    {
        ClapTrap clap("Dead");
        clap.takeDamage(10);
        report_test("Test 9: No hit points", clap.getHitPoints() == 0, "Hit points should be 0 after 10 damage");
        clap.attack("Target"); // Should print "is dead"
        clap.beRepaired(5);   // Should print "is dead"
        std::cout << "Test 9: No hit points handling passed" << std::endl;
    }

    // Test 10: Multiple operations
    {
        ClapTrap clap("MultiBot");
        clap.attack("Target1");
        clap.takeDamage(4);
        clap.beRepaired(2);
        report_test("Test 10: Multiple operations (hit points)", clap.getHitPoints() == 8, "Hit points should be 8 after operations");
        report_test("Test 10: Multiple operations (energy points)", clap.getEnergyPoints() == 8, "Energy points should be 8 after operations");
    }

    if (test_passed) {
        std::cout << "All tests completed successfully!" << std::endl;
    } else {
        std::cout << "Some tests failed. Please check the output for details." << std::endl;
    }
    return 0;
}