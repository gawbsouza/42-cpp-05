/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:19 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/22 06:55:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ): 
AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = "Undefined Target";
}

RobotomyRequestForm::RobotomyRequestForm( const std::string & target ): 
AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & ref ):
AForm("RobotomyRequestForm", SIGN_GRADE, EXECUTE_GRADE)
{
    *this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & ref)
{
    if (this != &ref)
    {
        this->_target = ref._target;
    }
    return *this;
}

void RobotomyRequestForm::doFormAction( void ) const
{
    std::cout << "Dzzz Dzzz Ziiiii Dziii" << std::endl;

    if (rand() % 2 != 1) {
        std::cout << "Robotomy failed" << std::endl;
        return;
    }

    std::cout << this->_target << " has been robotomized" << std::endl;

}