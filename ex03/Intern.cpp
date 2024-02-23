/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:22:57 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 08:16:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern( void ) {}
Intern::~Intern( void ) {}

struct factory {
    std::string formName;
    AForm *(*create)(const std::string &);
};

AForm * ShrubberyCreationFormFactory(const std::string & target)
{
    return new ShrubberyCreationForm(target);
}

AForm * RobotomyRequestFormFactory(const std::string & target)
{
    return new RobotomyRequestForm(target);
}

AForm * PresidentialPardonFormFactory(const std::string & target)
{
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm( const std::string & formName, const std::string & target ) throw (std::exception)
{
    factory factories[3] = {
        {"ShrubberyCreationForm", ShrubberyCreationFormFactory},
        {"RobotomyRequestForm", RobotomyRequestFormFactory},
        {"PresidentialPardonForm", PresidentialPardonFormFactory}
    };

    for (int i = 0; i < 3; i++) {
        if (factories[i].formName.compare(formName) == 0) {
            std::cout << "Constructing object of " << formName << std::endl;
            return factories[i].create(target);
        }
    }

    throw Intern::InvalidClassNameException();
    return NULL;
}

const char *Intern::InvalidClassNameException::what( void ) const  throw()
{
    return "Invalid class name to construct object";
}