/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:24:09 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:22:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat highGradeBureaucrat("High Grade", 5);
    Bureaucrat lowGradeBureaucrat("Low Grade", 150);
    AForm *form;
    
    form = Intern::makeForm("ShrubberyCreationForm", "Home");

    std::cout << *form << std::endl;

    highGradeBureaucrat.signForm(*form);
    lowGradeBureaucrat.executeForm(*form);
    highGradeBureaucrat.executeForm(*form);

    std::cout << std::endl;

    delete form;

    form = Intern::makeForm("RobotomyRequestForm", "Gabriel");

    std::cout << *form << std::endl;

    highGradeBureaucrat.signForm(*form);
    lowGradeBureaucrat.executeForm(*form);
    highGradeBureaucrat.executeForm(*form);

    std::cout << std::endl;

    delete form;

    form = Intern::makeForm("PresidentialPardonForm", "Gabriel");

    std::cout << *form << std::endl;

    highGradeBureaucrat.signForm(*form);
    lowGradeBureaucrat.executeForm(*form);
    highGradeBureaucrat.executeForm(*form);

    std::cout << std::endl;

    delete form;

    try {
        form = Intern::makeForm("WrongFormClassName", "Gabriel");
    } catch (std::exception &e) {
        std::cout << "Failed to construct object, cause: " << e.what() << std::endl;
    }

    return 0;
}