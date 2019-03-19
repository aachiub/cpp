
#include <cmath>
#include <limits>
#include <cfloat>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "Convert.hpp"

Convert::Convert( void ) {
    return ;
}

Convert::Convert( Convert const & src ) {
    *this = src;
    return ;
}

Convert::~Convert( void ) {
    return ;
}

Convert & Convert::operator = ( Convert const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}


void Convert::toTypes ( std::string & strVal ) {
    double dVal;

    // since std::stod( strVal ) crashes if only alphanums, this is used to convert strVal to double
    size_t sz = strVal.size();
    // need to avoid 'f' for float type but beware not to loose the in'f' one !
    bool resized = false;
    if ( sz > 1 && strVal.back() == 'f' && strVal[sz - 2] != 'n') {
        resized = true;
        strVal.resize( sz - 1 );
    }

    std::stringstream	iss( strVal );
    iss >> dVal;
    bool fail = !iss.eof() || iss.fail();

    if ( sz == 1 )
    {
        double c = strVal [ 0 ];
        this->_toChar( c, false );
    }
    else
        this->_toChar( dVal , fail || resized );

    this->_toInt( dVal, fail );

    int precision =  ( sz - strVal.find ( '.' ) );

    this->_toFloat( dVal, precision, fail );

    this->_toDouble( dVal, precision,  fail );
}

void Convert::_toChar(  double & dVal , bool fail) {

    try {
        std::cout << "char:\t";
        if ( fail || dVal < CHAR_MIN || dVal > CHAR_MAX )
            throw Convert::ImpossibleException();

        char c = static_cast< char > ( dVal );

        if ( !std::isprint( c ) )
            throw Convert::NonDisplayableException();

        std::cout << "'" << c << "'" << std::endl;
    }

    catch (std::exception &e) {
        std::cout << TXTRED << e.what() << TXTNORMAL << std::endl;
    }

 }

void Convert::_toInt(  double & dVal, bool fail ) {

    try {
        std::cout << "int:\t";
        
        if ( fail || std::isnan( dVal ) || dVal < INT_MIN || dVal > INT_MAX )
            throw Convert::ImpossibleException();
        
        std::cout << static_cast< int >( dVal ) << std::endl;
    }

    catch (std::exception &e) {
        std::cout << TXTRED << e.what() << TXTNORMAL << std::endl;
    }

}

void Convert::_toFloat(  double & dVal, int precision, bool fail ) {
    try {
        std::cout << "float:\t";
        
    if ( fail || ( !std::isnan( dVal ) && !std::isinf(dVal) && ( dVal > FLT_MAX || dVal < -FLT_MAX) ) )
//      if ( fail || std::isnan( dVal ) || dVal < - FLT_MAX || dVal > FLT_MAX  )
//      if ( fail || ( !std::isnan( dVal ) && !std::isinf( dVal ) && ( dVal < - FLT_MAX || dVal > FLT_MAX )))
            throw Convert::ImpossibleException();
    
        std::cout << std::fixed << std::setprecision( precision ) << static_cast< float >( dVal ) << "f" << std::endl;
    }
    
    catch (std::exception &e) {
        std::cout << TXTRED << e.what() << TXTNORMAL << std::endl;
    }
}

void Convert::_toDouble(  double & dVal, int precision, bool fail ) {
    try {
        std::cout << "double:\t";
    
        if ( fail )
            throw Convert::ImpossibleException();
        std::cout << std::fixed << std::setprecision( precision ) << dVal << std::endl;
    }
    
    catch (std::exception &e) {
        std::cout << TXTRED << e.what() << TXTNORMAL << std::endl;
    }
}


// Impossible conversion and Non displayable char Exceptions handling classes

Convert::ImpossibleException::ImpossibleException( void ) {
    return ;
}

Convert::ImpossibleException::ImpossibleException( Convert::ImpossibleException const & src ) {
    *this = src;
    return ;
}

Convert::ImpossibleException::~ImpossibleException( void )  throw() {
    return ;
}

Convert::ImpossibleException & Convert::ImpossibleException::operator = ( Convert::ImpossibleException const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

const char *Convert::ImpossibleException::what( void ) const throw() {
    return ( "\033[1;31mimpossible\033[0m" );
}


Convert::NonDisplayableException::NonDisplayableException( void ) {
    return ;
}


Convert::NonDisplayableException::NonDisplayableException( Convert::NonDisplayableException const & src ) {
    *this = src;
    return ;
}

Convert::NonDisplayableException::~NonDisplayableException( void )  throw() {
    return ;
}

Convert::NonDisplayableException & Convert::NonDisplayableException::operator = ( Convert::NonDisplayableException const & rhs ) {
    if ( this != &rhs  )
        *this = rhs;
    return *this;
}

const char *Convert::NonDisplayableException::what( void ) const throw() {
    return ( "\033[1;31mNon displayable\033[0m" );
}

