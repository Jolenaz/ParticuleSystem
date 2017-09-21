/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec4.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:04:43 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:05:18 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Vec3;

class Vec4{

public:

// Constructeurs, Destructeur

    Vec4(void);
    Vec4(Vec4 const & src);
    Vec4(float x, float y, float z, float w);
    Vec4(Vec3 const & src, float w);
    Vec4(Vec3 const & src);
    ~Vec4(void);
    Vec4 & operator=(Vec4 const & src);


// variables

    float x;
    float y;
    float z;
    float w;

// functions
    float  & operator[](int const i);
    bool    operator==(Vec4 const & rhs);

};

std::ostream & operator<<(std::ostream & o, Vec4 const & i);
