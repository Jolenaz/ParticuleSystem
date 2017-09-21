/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat3.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:04:48 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:37 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Mat3{

union matrix3{
    struct {
        float m00;
        float m01;
        float m02;
        float m10;
        float m11;
        float m12;
        float m20;
        float m21;
        float m22;
    };
    float       ml[9];
    float       mc[3][3];
};

public:

// Constructeurs, Destructeur

    Mat3(void);
    Mat3(Mat3 const & src);
    ~Mat3(void);
    Mat3 & operator=(Mat3 const & rhs);


// attribus

    union matrix3 value;
    

// fonctions membres

    Mat3    operator+(Mat3 const & rhs) const;
    void    operator+=(Mat3 const & rhs);
    Mat3    operator-(Mat3 const & rhs) const;
    void    operator-=(Mat3 const & rhs);
    Mat3    operator*(Mat3 const & rhs) const;
    void    operator*=(Mat3 const & rhs);
    Mat3    operator*(float const & rhs) const;
    void    operator*=(float const & rhs);
    Vec3    operator*(Vec3 rhs);
    Mat3    operator/(float const & rhs) const;
    void    operator/=(float const & rhs);
    bool    operator==(Mat3 const & rhs);
    
    void set_identity();
    void set_zero();
    Mat3 & transpos();

// fonctions non membres


};

std::ostream & operator<<(std::ostream & o, Mat3 const & i);
