/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:19 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/22 06:55:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): 
AForm("PresidentialPardonForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = "Undefined Target";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string & target ): 
AForm("PresidentialPardonForm", SIGN_GRADE, EXECUTE_GRADE)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & ref):
AForm("PresidentialPardonForm", SIGN_GRADE, EXECUTE_GRADE)
{
    *this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
}

void PresidentialPardonForm::doFormAction( void ) const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & ref )
{
    if (this != &ref) {
        this->_target = ref._target;
    }
    return *this;
}