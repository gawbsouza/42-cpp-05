/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:24:09 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:18:11 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void ShrubberyCreationFormTests()
{
    std::cout << "=== Shrubbery Creation Form Tests ===" << std::endl << std::endl;

    Bureaucrat highGradeBureaucrat("High Grade", 10);
    Bureaucrat lowGradeBureaucrat("Low Grade", 140);
    Bureaucrat veryLowGradeBureaucrat("Very Low Grade", 150);

    ShrubberyCreationForm form1("home");
    ShrubberyCreationForm form2 = form1;
    ShrubberyCreationForm form3(form2);

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << std::endl;

    veryLowGradeBureaucrat.signForm(form1);
    lowGradeBureaucrat.signForm(form1);
    highGradeBureaucrat.signForm(form2);

    std::cout << std::endl;

    veryLowGradeBureaucrat.executeForm(form1);
    lowGradeBureaucrat.executeForm(form1);
    highGradeBureaucrat.executeForm(form2);
    
    std::cout << std::endl;
}

void RobotomyRequestFormTests()
{
    std::cout << "=== Robotomy Request Form Tests ===" << std::endl << std::endl;

    Bureaucrat highGradeBureaucrat("High Grade", 10);
    Bureaucrat lowGradeBureaucrat("Low Grade", 70);
    Bureaucrat veryLowGradeBureaucrat("Very Low Grade", 150);

    RobotomyRequestForm form1("Gabriel");
    RobotomyRequestForm form2 = form1;
    RobotomyRequestForm form3(form2);

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << std::endl;

    veryLowGradeBureaucrat.signForm(form1);
    lowGradeBureaucrat.signForm(form1);
    highGradeBureaucrat.signForm(form2);

    std::cout << std::endl;

    veryLowGradeBureaucrat.executeForm(form1);
    lowGradeBureaucrat.executeForm(form1);

    std::cout << std::endl;
    
    highGradeBureaucrat.executeForm(form2);
    highGradeBureaucrat.executeForm(form2);
    highGradeBureaucrat.executeForm(form2);
    highGradeBureaucrat.executeForm(form2);
    
    std::cout << std::endl;
}

void PresidentialPardonFormTests()
{
    std::cout << "=== Presidential Pardon Form Tests ===" << std::endl << std::endl;

    Bureaucrat highGradeBureaucrat("High Grade", 5);
    Bureaucrat lowGradeBureaucrat("Low Grade", 24);
    Bureaucrat veryLowGradeBureaucrat("Very Low Grade", 150);

    PresidentialPardonForm form1("Gabriel");
    PresidentialPardonForm form2 = form1;
    PresidentialPardonForm form3(form2);

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << std::endl;

    veryLowGradeBureaucrat.signForm(form1);
    lowGradeBureaucrat.signForm(form1);
    highGradeBureaucrat.signForm(form2);

    std::cout << std::endl;

    veryLowGradeBureaucrat.executeForm(form1);
    lowGradeBureaucrat.executeForm(form1);
    highGradeBureaucrat.executeForm(form2);
}

int main()
{
    ShrubberyCreationFormTests();
    RobotomyRequestFormTests();
    PresidentialPardonFormTests();
    
    return 0;
}