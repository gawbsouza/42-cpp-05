/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:24 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/23 17:06:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOBY_H
# define ROBOTOBY_H

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    
private:
    
    static const unsigned int   SIGN_GRADE      = 72;
    static const unsigned int   EXECUTE_GRADE   = 45;
       
    std::string                 _target;
    
public:

    RobotomyRequestForm( void );
    RobotomyRequestForm( const std::string & target );
    RobotomyRequestForm( const RobotomyRequestForm & ref );
    ~RobotomyRequestForm ( void );

    void    doFormAction( void ) const;

    RobotomyRequestForm & operator=( const RobotomyRequestForm & ref );
};


#endif