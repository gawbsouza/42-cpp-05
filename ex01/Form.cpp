/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:16:03 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 21:20:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form( const std::string & name, unsigned int gradeToSign, unsigned int gradeToExecute) throw (std::exception)
{
    if (gradeToSign > Bureaucrat::LOWEST_GRADE || gradeToExecute > Bureaucrat::LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    
    if (gradeToSign < Bureaucrat::HIGHEST_GRADE || gradeToExecute < Bureaucrat::HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    
    this->_name = name;
    this->_isSigned = false;
    this->_gradeToSign = gradeToSign;
    this->_gradeToExecute = gradeToExecute;
}

Form::Form( void )
{
    this->_name = "Unamed";
    this->_isSigned = false;
    this->_gradeToSign = Bureaucrat::LOWEST_GRADE;
    this->_gradeToExecute = Bureaucrat::LOWEST_GRADE;
}

Form::Form( const Form & form)
{
    *this = form;
}

Form::~Form( void )
{
}

Form &Form::operator=(const Form & form)
{
    if (this != &form) {
        this->_name = form._name;
        this->_gradeToSign = form._gradeToSign;
        this->_gradeToExecute = form._gradeToExecute;
        this->_isSigned = form._isSigned;
    }
    return *this;
}

std::string Form::getName( void ) const
{
    return this->_name;
}

bool Form::isSigned( void ) const
{
    return this->_isSigned;
}

unsigned int Form::getGradeToSign( void ) const
{
    return this->_gradeToSign;   
}

unsigned int Form::getGradeToExecute( void ) const
{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat & bureaucrat) throw (std::exception)
{
    if (this->isSigned()) {
        throw AlreadySignedException();
    }

    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what( void ) const  throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what( void ) const  throw()
{
    return "Grade is too low";
}

const char *Form::AlreadySignedException::what( void ) const  throw()
{
    return "Form is already signed";
}

std::ostream &  operator<<( std::ostream& out, const Form & form ) {
	return out 
        << form.getName() << ", grade to sign " << form.getGradeToSign()
        << ", grade to execute " << form.getGradeToExecute()
        << ", " << (form.isSigned() ? "is" : "is not") << " signed";
}