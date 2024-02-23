/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:16:03 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 21:53:16 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm( const std::string & name, unsigned int gradeToSign, unsigned int gradeToExecute) throw (std::exception)
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

AForm::AForm( void )
{
    this->_name = "Unamed";
    this->_isSigned = false;
    this->_gradeToSign = Bureaucrat::LOWEST_GRADE;
    this->_gradeToExecute = Bureaucrat::LOWEST_GRADE;
}

AForm::AForm( const AForm & form)
{
    *this = form;
}

AForm::~AForm( void )
{
}

AForm &AForm::operator=(const AForm & form)
{
    if (this != &form) {
        this->_name = form._name;
        this->_gradeToSign = form._gradeToSign;
        this->_gradeToExecute = form._gradeToExecute;
        this->_isSigned = form._isSigned;
    }
    return *this;
}

std::string AForm::getName( void ) const
{
    return this->_name;
}

bool AForm::isSigned( void ) const
{
    return this->_isSigned;
}

unsigned int AForm::getGradeToSign( void ) const
{
    return this->_gradeToSign;   
}

unsigned int AForm::getGradeToExecute( void ) const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat & bureaucrat) throw (std::exception)
{
    if (this->isSigned()) {
        throw AlreadySignedException();
    }

    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    
    this->_isSigned = true;
}

void AForm::execute( const Bureaucrat & executor ) const throw (std::exception)
{
    if (!this->isSigned()) {
        throw MustBeSignedException();
    }

    if (executor.getGrade() > this->_gradeToExecute) {
        throw GradeTooLowException();
    }

    this->doFormAction();
}

const char *AForm::GradeTooHighException::what( void ) const  throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what( void ) const  throw()
{
    return "Grade is too low";
}

const char *AForm::AlreadySignedException::what( void ) const  throw()
{
    return "Form is already signed";
}

const char *AForm::MustBeSignedException::what( void ) const  throw()
{
    return "Form must be signed";
}

std::ostream &  operator<<( std::ostream& out, const AForm & form ) {
	return out 
        << form.getName() << ", grade to sign " << form.getGradeToSign()
        << ", grade to execute " << form.getGradeToExecute()
        << ", " << (form.isSigned() ? "is" : "is not") << " signed";
}