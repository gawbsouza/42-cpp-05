/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:00:51 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 19:32:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void )
{
    this->_name = "Unamed";
    this->_grade = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat( const Bureaucrat & ref )
{
    *this = ref;
}

Bureaucrat::Bureaucrat( const std::string & name, unsigned int grade ) throw(std::exception)
{
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat( void )
{
}

std::string Bureaucrat::getName( void ) const 
{
    return this->_name;
}

unsigned int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade( void ) throw(std::exception)
{
    if (this->getGrade() == HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    --this->_grade;
}

void Bureaucrat::decrementGrade( void ) throw(std::exception)
{
    if (this->getGrade() == LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    ++this->_grade;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat & ref )
{
    if (this != &ref) {
        this->_grade = ref._grade;
        this->_name = ref._name;
    }

    return *this;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const  throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what( void ) const  throw()
{
    return "Grade is too low";
}

std::ostream &  operator<<( std::ostream& out, const Bureaucrat & b ) {
	return out << b.getName() << ", bureaucrat grade " << b.getGrade();
}