# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Pepe"), _hit_points(100), _energy_points(50), _attack_damage(20)
{
	std::cout << "ClapTrap Pepe has been created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(100), _energy_points(50), _attack_damage(20)
{
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) : _name(src.getName()), _hit_points(src.getHitPoints()), _energy_points(src.getEnergyPoints()), _attack_damage(getAttackDamage()) 
{
	std::cout << "Claptrap " << this->_name << " has been copied" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	this->_name = rhs.getName();
	this->_attack_damage = rhs.getAttackDamage();
	this->_energy_points = rhs.getEnergyPoints();
	this->_hit_points = rhs.getHitPoints();
	return *this;
}

std::string		ClapTrap::getName(void) const { return this->_name; }

unsigned int	ClapTrap::getHitPoints(void) const { return this->_hit_points; }

unsigned int	ClapTrap::getEnergyPoints(void) const { return this->_energy_points; }

unsigned int	ClapTrap::getAttackDamage(void) const { return this->_attack_damage; }

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points && this->_hit_points)
	{
		--(this->_energy_points);
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing "
		<< this->_attack_damage << " points of damage!" << std::endl;
		return ;
	}
	this->_check_points();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	(this->_hit_points) -= amount;
	if ((this->_hit_points) < 0)
		(this->_hit_points = 0);
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage resulting in a total of "
	<< this->_hit_points << " health points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points && this->_hit_points)
	{
		--(this->_energy_points);
		(this->_hit_points) += amount;
		std::cout << "ClapTrap " << this->_name << " has repaired itself with " << amount
		<< " health points resulting in a total amount of " << this->_hit_points << " health points" << std::endl;
		return ;
	}
	this->_check_points();
}

void	ClapTrap::_check_points(void)
{
	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	if (this->_energy_points == 0)
		std::cout << "ClapTrap " << this->_name << " has no energy points left" << std::endl;
}