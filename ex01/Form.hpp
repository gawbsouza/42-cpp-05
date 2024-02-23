/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:01:17 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 20:14:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
    
private:
    
    std::string     _name;
    bool            _isSigned;
    unsigned int    _gradeToSign;
    unsigned int    _gradeToExecute;

public:

    Form( 
        const std::string & name, 
        unsigned int gradeToSign, 
        unsigned int gradeToExecute
    )   throw (std::exception);
    
    Form( void );
    Form( const Form & form);
    ~Form( void );

    Form &  operator=(const Form & form);

    std::string     getName( void ) const;
    bool            isSigned( void ) const;
    unsigned int    getGradeToSign( void ) const;
    unsigned int    getGradeToExecute( void ) const;

    void            beSigned(const Bureaucrat & bureaucrat) throw (std::exception);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };

    class AlreadySignedException : public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };
};

std::ostream &  operator<<( std::ostream& out, const Form & form );

#endif