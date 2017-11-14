/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:11:02 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:11:06 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"
#include "Transform.class.hpp" 

class Camera{
    public:

    // Constructeurs, Destructeur

    Camera(void);
    Camera(float fov, float near, float far, float ratio);
    Camera(Camera const & src);
    virtual ~Camera(void);
    Camera & operator=(Camera const & src);

    float     fov;
    float     near;
    float     far;
    float     ratio;

    Mat4 get_projMat( void );
    Transform transform;
    void translateCam(Vec3 trans);

    // attribus
    private:

    Mat4 _projMat;

    void _calcProjection();


    // fonctions membres

    // fonctions non membres
};
