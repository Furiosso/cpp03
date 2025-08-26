#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	protected:
		static const int	_defaultHitPoints = 100;
		static const int	_defaultEnergyPoints = 100;
		static const int	_defaultAttackDamage = 30;
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap(void);
		void	highFivesGuys(void);
};

#endif
