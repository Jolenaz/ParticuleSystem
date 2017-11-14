/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:04:59 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:05 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Mat3;

class Mat4{

union matrix4{
    struct {
        float m00;
        float m01;
        float m02;
        float m03;
        float m10;
        float m11;
        float m12;
        float m13;
        float m20;
        float m21;
        float m22;
        float m23;
        float m30;
        float m31;
        float m32;
        float m33;
    };
    float       ml[16];
    float       mc[4][4];
};

public:

// Constructeurs, Destructeur

    Mat4(void);
    Mat4(Mat4 const & src);
    Mat4(Mat3 const & src);
    ~Mat4(void);
    Mat4 & operator=(Mat4 const & rhs);


// attribus

    union matrix4 value;
    

// fonctions membres

    Mat4    operator+(Mat4 const & rhs) const;
    void    operator+=(Mat4 const & rhs);
    Mat4    operator-(Mat4 const & rhs) const;
    void    operator-=(Mat4 const & rhs);
    Mat4    operator*(Mat4 const & rhs) const;
    Mat4    operator*(float const & rhs) const;
    void    operator*=(float const & rhs);
    Vec4    operator*(Vec4 rhs);
    Mat4    operator/(float const & rhs) const;
    void    operator/=(float const & rhs);
    bool    operator==(Mat4 const & rhs);
    
    Mat4 & set_identity();
    Mat4 & set_zero();
    Mat4 & transpos();

    Mat4    & rotateAround(Vec4 const & rotation); 
    Mat4    & rotateAround(Vec3 const & axe, float const & angle);
    Mat4    & rotateLocal(Vec3 const & angles);
    Mat4    & rotateGlobal(Vec3 const & angles);
    Mat4    & translate(Vec3 const & trans);
    Mat4    & scale(Vec3 const & scale);

    Mat4    & rotateAroundInverse(Vec4 const & rotation); 
    Mat4    & rotateAroundInverse(Vec3 const & axe, float const & angle);
    Mat4    & rotateLocalInverse(Vec3 const & angles);
    Mat4    & rotateGlobalInverse(Vec3 const & angles);
    Mat4    & translateInverse(Vec3 const & trans);
    Mat4    & scaleInverse(Vec3 const & scale);

// fonctions non membres


};

std::ostream & operator<<(std::ostream & o, Mat4 const & i);
