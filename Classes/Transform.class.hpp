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

    Vec3 position;
    Vec3 rotation;
    Vec3 scale;

    Transform * parent;

    Mat4 get_worldToLocal( void );

    // fonctions membres

    void translate(Vec3 const & trans);
    void rotate(Vec3 const & rot);
    void scalate(Vec3 const & scale);

    private:

    Mat4    _worldToLocal;
    void    _updateMatrix();


    // fonctions non membres
};
