/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:15:26 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 18:59:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat a;
    std::cout << a << std::endl;

    std::cout << std::endl;
    
    Bureaucrat b("Gabriel", 50);

    std::cout << b << std::endl;
    b.incrementGrade();
    b.incrementGrade();
    b.incrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    b.decrementGrade();
    b.decrementGrade();
    std::cout << b << std::endl;

    std::cout << std::endl;

    Bureaucrat bb(Bureaucrat("Jurema", 2));
    std::cout << bb << std::endl;

    Bureaucrat cc = bb;
    std::cout << cc << std::endl;

    std::cout << std::endl;

    try {
        Bureaucrat c("Jose", 0);
    } catch (std::exception & e) {
        std::cout << "Error when creating Bureaucrat (Jose): " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat d("Maria", 151);
    } catch (std::exception & e) {
        std::cout << "Error when creating Bureaucrat (Maria): " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    try {
        Bureaucrat e("Antonio", 1);
        e.incrementGrade();
    } catch (std::exception & e) {
        std::cout << "Error when creating Bureaucrat (Antonio): " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat f("Nastacia", 150);
        f.decrementGrade();
    } catch (std::exception & e) {
        std::cout << "Error when creating Bureaucrat (Nastacia): " << e.what() << std::endl;
    }

    return 0;
}