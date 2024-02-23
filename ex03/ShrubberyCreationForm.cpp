/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:19 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:14:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ): 
AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = "Undefined Target";
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target ): 
AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & ref ): 
AForm("ShrubberyCreationForm", SIGN_GRADE, EXECUTE_GRADE)
{
    *this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & ref )
{
    if (this != &ref)
    {
        this->_target = ref._target;
    }
    return *this;
}

void ShrubberyCreationForm::doFormAction( void ) const
{

    std::string fileName;
    std::ofstream fout;

    fileName = this->_target + "_shrubbery";
    fout.open(fileName.c_str(), std::ifstream::out);

    std::cout << "Creating a Tree..." << std::endl;
    
    if (!fout.good()) {
        std::cout 
            << "Error when opening output file (" << fileName << ")." 
            << std::endl;
        return;
    }
    
    fout
    << "       _-_" << std::endl
    << "    /~~   ~~\\" << std::endl
    << " /~~         ~~\\" << std::endl
    << "{               }" << std::endl
    << " \\  _-     -_  /" << std::endl
    << "   ~  \\\\ //  ~" << std::endl
    << "_- -   | | _- _" << std::endl
    << "  _ -  | |   -_" << std::endl
    << "      // \\\\";

    fout.close();
}