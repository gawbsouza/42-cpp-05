/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:24 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:10:31 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRY_H
# define SHRUBERRY_H

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    
private:
    
    static const unsigned int   SIGN_GRADE      = 145;
    static const unsigned int   EXECUTE_GRADE   = 137; 
       
    std::string                 _target;
    
public:

    ShrubberyCreationForm( void );
    ShrubberyCreationForm( const std::string & target );
    ShrubberyCreationForm( const ShrubberyCreationForm & ref);
    ~ShrubberyCreationForm ( void );

    void    doFormAction( void ) const;

    ShrubberyCreationForm & operator=( const ShrubberyCreationForm & ref );
};


#endif