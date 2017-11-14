/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:04:22 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:14 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Vec4;
class Vec2;

class Vec3{

    public:

    // Constructeurs, Destructeur

    Vec3(void);
    Vec3(Vec3 const & src);
    Vec3(Vec4 const & src);
    Vec3(float x, float y, float z);
    Vec3(Vec2 const & src, float z);
    ~Vec3(void);
    Vec3 & operator=(Vec3 const & src);
    Vec3 & operator=(Vec4 const & src);


    // attribus

    float x;
    float y;
    float z;

    // fonctions membres

    Vec3 operator+(Vec3 const & src) const;
    void operator+=(Vec3 const & src);
    Vec3 operator-(Vec3 const & src) const;
    void operator-=(Vec3 const & src);
    Vec3 operator*(float const & src) const;
    void operator*=(float const & src);
    Vec3 operator/(float const & src) const;
    void operator/=(float const & src);
    bool operator==(Vec3 const & rhs);
    float  & operator[](int const i);
    float dot(Vec3 const & vec);
    float magnitude();
    float sqrMagnitude();
    Vec3 & normalize();
    Vec3 cross(Vec3 const & vec);



    // fonctions non membres

    static Vec3 cross(Vec3 const & vec1, Vec3 const & vec2);
    static float dot(Vec3 const & vec1, Vec3 const & vec2);

};


std::ostream & operator<<(std::ostream & o, Vec3 const & i);
