/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:18:26 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 08:14:42 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include <string>

class Intern
{
    
private:

    Intern( void );
    ~Intern( void );
    
public:

    static AForm * makeForm( const std::string & formName, const std::string & target ) throw(std::exception);

    class InvalidClassNameException : public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };
};

#endif
