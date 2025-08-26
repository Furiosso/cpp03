# include "FragTrap.hpp"



FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_points = _defaultHitPoints;
	this->_energy_points = _defaultEnergyPoints;
	this->_attack_damage = _defaultAttackDamage;
	std::cout << "FragTrap Pepe has been created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = _defaultHitPoints;
	this->_energy_points = _defaultEnergyPoints;
	this->_attack_damage = _defaultAttackDamage;
	std::cout << "FragTrap " << name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Fragtrap " << this->_name << " has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " has been destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " says: \"Give me five!\"" << std::endl;
}