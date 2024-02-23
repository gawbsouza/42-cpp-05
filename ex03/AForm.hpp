/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:10:41 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/21 22:10:50 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H 
# define AFORM_H

# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    
private:
    
    std::string     _name;
    bool            _isSigned;
    unsigned int    _gradeToSign;
    unsigned int    _gradeToExecute;

protected:

    virtual void    doFormAction( void ) const = 0;

public:

    AForm( 
        const std::string & name, 
        unsigned int gradeToSign, 
        unsigned int gradeToExecute
    )   throw (std::exception);
    
    AForm( void );
    AForm( const AForm & form);
    virtual ~AForm( void );

    AForm &  operator=(const AForm & form);

    std::string     getName( void ) const;
    bool            isSigned( void ) const;
    unsigned int    getGradeToSign( void ) const;
    unsigned int    getGradeToExecute( void ) const;

    void            beSigned( const Bureaucrat & bureaucrat ) throw (std::exception); 
    void            execute( const Bureaucrat & executor ) const throw (std::exception);

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

    class MustBeSignedException : public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };
};

std::ostream &  operator<<( std::ostream& out, const AForm & form );

#endif