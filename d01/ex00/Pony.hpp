
#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

typedef enum 	e_gender {
	MALE 	= 'M',
	FEMALE 	= 'F'
} 				t_gender;

class Pony {

public:
	
	Pony();
	Pony( std::string & name, std::string & color, t_gender gender );
	~Pony(void);

	void 		getname( std::string & name ) const;
	void		getcolor( std::string & color ) const;
	t_gender	getgender( void ) const;

	void 		setname( std::string & name );
	void 		setcolor( std::string & color );
	void 		setgender( t_gender gender );

private:
	std::string	_name;
	std::string	_color;
	t_gender	_gender;

};

#endif
