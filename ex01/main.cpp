/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:15:26 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 08:41:51 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void formTests()
{
    std::cout << "=== Only Form Tests ===" << std::endl << std::endl;

    Form a;
    std::cout << a << std::endl;

    std::cout << std::endl;

    Form b("Commission", 10, 42);
    std::cout << b << std::endl;
    Form bb = b;
    std::cout << bb << std::endl;
    Form bbb(bb);
    std::cout << bbb << std::endl;
    
    std::cout << std::endl;
    
    try {
        Form c("Test", 0, 42);
    } catch (std::exception &e) {
        std::cout << "Error when creating form: " << e.what() << std::endl;
    }
    try {
        Form c("Test", 151, 42);
    } catch (std::exception &e) {
        std::cout << "Error when creating form: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try {
        Form c("Test", 10, 0);
    } catch (std::exception &e) {
        std::cout << "Error when creating form: " << e.what() << std::endl;
    }
    try {
        Form c("Test", 10, 155);
    } catch (std::exception &e) {
        std::cout << "Error when creating form: " << e.what() << std::endl;
    }

}

void formWithBureaucratTests()
{
    std::cout 
        << std::endl << "=== Form with Bureaucrat Tests ===" 
        << std::endl << std::endl;

    Bureaucrat lowGradeBureaucrat("Low Bureaucrat", 140);
    Bureaucrat highGradeBureaucrat("High Bureaucrat", 9);
    
    Form lowGradeForm("Low Form", 140, 140);
    Form highGradeForm("High Form", 10, 10);

    std::cout << lowGradeBureaucrat << std::endl;
    std::cout << highGradeBureaucrat << std::endl;
    std::cout << lowGradeForm << std::endl;
    std::cout << highGradeForm << std::endl;

    std::cout << std::endl;

    Form f;
    
    f = highGradeForm;  highGradeBureaucrat.signForm(f); std::cout << f << std::endl;
    f = lowGradeForm;   highGradeBureaucrat.signForm(f); std::cout << f << std::endl;

    std::cout << std::endl;

    f = highGradeForm;  lowGradeBureaucrat.signForm(f); std::cout << f << std::endl;
    f = lowGradeForm;   lowGradeBureaucrat.signForm(f); std::cout << f << std::endl;
    
    std::cout << std::endl;

    highGradeBureaucrat.signForm(f);
    lowGradeBureaucrat.signForm(f);
}

int main()
{
    formTests();
    formWithBureaucratTests();

    return 0;
}