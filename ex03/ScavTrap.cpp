#include "ScavTrap.hpp"

const int	ScavTrap::_defaultHitPoints = 100;
const int	ScavTrap::_defaultEnergyPoints = 50;
const int	ScavTrap::_defaultAttackDamage = 20;

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hit_points = _hit_points;
	this->_energy_points = _energy_points;
	this->_attack_damage = _attack_damage;
	std::cout << "ScavTrap Pepe has been created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = _defaultHitPoints;
	this->_energy_points = _defaultEnergyPoints;
	this->_attack_damage = _defaultAttackDamage;
	std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Scavtrap " << this->_name << " has been copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points && this->_hit_points)
	{
		--(this->_energy_points);
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing "
		<< this->_attack_damage << " points of damage!" << std::endl;
		return ;
	}
	this->_check_points();
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}