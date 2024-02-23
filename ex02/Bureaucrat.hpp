/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:50:17 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/15 06:53:05 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include "AForm.hpp"
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
    
private:

    std::string     _name;
    unsigned int    _grade;

public:

    static const unsigned int HIGHEST_GRADE = 1;
    static const unsigned int LOWEST_GRADE  = 150;

    Bureaucrat( void );
    Bureaucrat( const Bureaucrat & ref );
    Bureaucrat( const std::string & name, unsigned int grade ) throw(std::exception);
    ~Bureaucrat( void );

    std::string     getName( void ) const;
    unsigned int    getGrade( void ) const;
    void            incrementGrade( void ) throw(std::exception);
    void            decrementGrade( void ) throw(std::exception);

    void            signForm( AForm & form) const;
    void            executeForm( const AForm & form) const;

    Bureaucrat &    operator=( const Bureaucrat & ref );

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

};

std::ostream &  operator<<( std::ostream& out, const Bureaucrat & b );

#endif