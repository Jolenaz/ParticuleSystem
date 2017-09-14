/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:03:54 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:09 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Vec2{

public:

// Constructeurs, Destructeur

    Vec2(void);
    Vec2(Vec2 const & src);
    Vec2(float x, float y);
    virtual ~Vec2(void);
    Vec2 & operator=(Vec2 const & src);


// attribus

    float x;
    float y;

// fonctions membres

    Vec2    operator+(Vec2 const & src) const;
    void    operator+=(Vec2 const & src);
    Vec2    operator-(Vec2 const & src) const;
    void    operator-=(Vec2 const & src);
    Vec2    operator*(float const & src) const;
    void    operator*=(float const & src);
    Vec2    operator/(float const & src) const;
    void    operator/=(float const & src);
    bool    operator==(Vec2 const & src);
    float   & operator[](int const i);
    float   dot(Vec2 const & vec);
    float   magnitude(void);
    float   sqrMagnitude(void);
    Vec2    & normalize();
    


// fonctions non membres

    static float dot(Vec2 const & vec1, Vec2 const & vec2);

};

std::ostream & operator<<(std::ostream & o, Vec2 const & i);
