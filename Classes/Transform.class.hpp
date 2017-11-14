/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:10:23 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:10:29 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "joMath.hpp"

class Transform{
    public:

    // Constructeurs, Destructeur

    Transform(void);
    Transform(Vec3 pos, Vec3 rot, Vec3 scale);
    Transform(Transform const & src);
    virtual ~Transform(void);
    Transform & operator=(Transform const & src);

    // attribus



    Transform * parent;

    Mat4 get_worldToLocal( void );
    Mat4 get_localToWorld( void );

    Mat4 get_worldToLocalRigide( void );
    Mat4 get_localToWorldRigide( void );

    // fonctions membres

    void translate(Vec3 const & trans);
    void rotate(Vec3 const & rot);
    void scalate(Vec3 const & scale);

    Vec3 & get_position( void );
    Vec3 & get_rotation( void );
    Vec3 & get_scale( void );

    void recalcTransform( void );

    private:

    bool needCalculation;

    Vec3 position;
    Vec3 rotation;
    Vec3 scale;

    Mat4    _worldToLocal;
    Mat4    _localToWorld;
    void    _updateMatrixL();
    void    _updateMatrixW();

    Mat4    _worldToLocalRigide;
    Mat4    _localToWorldRigide;
    void    _updateMatrixLRigide();
    void    _updateMatrixWRigide();


    // fonctions non membres
};
