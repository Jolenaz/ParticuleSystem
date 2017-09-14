/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat2.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:02:52 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:49 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Mat2{

union matrix2{
    struct {
        float m00;
        float m01;
        float m10;
        float m11;
    };
    float       ml[4];
    float       mc[2][2];
};

public:

// Constructeurs, Destructeur

    Mat2(void);
    Mat2(Mat2 const & src);
    Mat2(float m00, float m01, float m10, float m11);
    virtual ~Mat2(void);
    Mat2 & operator=(Mat2 const & rhs);


// attribus

    union matrix2 value;
    

// fonctions membres

    Mat2    operator+(Mat2 const & rhs) const;
    void    operator+=(Mat2 const & rhs);
    Mat2    operator-(Mat2 const & rhs) const;
    void    operator-=(Mat2 const & rhs);
    Mat2    operator*(Mat2 const & rhs) const;
    void    operator*=(Mat2 const & rhs);
    Mat2    operator*(float const & rhs) const;
    void    operator*=(float const & rhs);
    Vec2    operator*(Vec2 rhs);
    Mat2    operator/(float const & rhs) const;
    void    operator/=(float const & rhs);
    bool    operator==(Mat2 const & rhs);
    
    void set_identity();
    void set_zero();
    Mat2 & transpos();

// fonctions non membres


};

std::ostream & operator<<(std::ostream & o, Mat2 const & i);
