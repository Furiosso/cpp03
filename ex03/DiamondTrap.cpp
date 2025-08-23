# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), _name("Paco") {}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap(), _name(name)
{
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	ScavTrap::operator=(rhs);
	FragTrap::operator=(rhs);
	this->_name = rhs.getName();
	return *this;
}

DiamondTrap::~DiamondTrap(void) {}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}