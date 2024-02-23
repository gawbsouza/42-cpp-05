/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:24 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:05:33 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_H
# define PRESIDENTIAL_H

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    
private:
    
    static const unsigned int   SIGN_GRADE      = 25;
    static const unsigned int   EXECUTE_GRADE   = 5;
       
    std::string                 _target;
    
public:

    PresidentialPardonForm( void );
    PresidentialPardonForm( const std::string & target );
    PresidentialPardonForm( const PresidentialPardonForm & ref );
    ~PresidentialPardonForm ( void );

    void    doFormAction( void ) const;

    PresidentialPardonForm & operator=( const PresidentialPardonForm & ref );
};


#endif