/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:19:39 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:47 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Transform.class.hpp"

Transform::Transform(){

    this->position = Vec3(0,0,0);
    this->rotation = Vec3(0,0,0);
    this->scale = Vec3(1,1,1);
    this->parent = NULL;
    
}

Transform::Transform(Vec3 pos, Vec3 rot, Vec3 scale): position(pos), rotation(rot), scale(scale) {
    this->parent = NULL;

}

Transform::Transform(Transform const & src){
    this->position = src.position;
    this->rotation = src.rotation;
    this->scale = src.scale;
    this->parent = src.parent;

}

Transform & Transform::operator=(Transform const & src){
    this->position = src.position;
    this->rotation = src.rotation;
    this->scale = src.scale;
    this->parent = src.parent;

    return *this;
}

Transform::~Transform(){}

void Transform::recalcTransform( void ){
    this->needCalculation = true;
}

void Transform::translate(Vec3 const & trans){
    this->position += trans;

}

void Transform::rotate(Vec3 const & rot){
    this->rotation += rot;

}

void Transform::scalate(Vec3 const & scale){
    this->scale.x *= scale.x;
    this->scale.y *= scale.y;
    this->scale.z *= scale.z;

}

Mat4 Transform::get_worldToLocal( void ){
        this->_updateMatrixW();
    return this->_worldToLocal;
}

Mat4 Transform::get_localToWorld( void ){
        this->_updateMatrixL();;
    return this->_localToWorld;
}

Vec3 & Transform::get_position( void ){
    return (this->position);
}
Vec3 & Transform::get_rotation( void ){
    return (this->rotation);
}
Vec3 & Transform::get_scale( void ){
    return (this->scale);
}

void Transform::_updateMatrixL(){
    Mat4 ret;
    ret.set_identity().translateInverse(this->position).rotateGlobalInverse(this->rotation);

    this->_localToWorld = ret;
}

void Transform::_updateMatrixW(){
    Mat4 ret;
    ret.set_identity().rotateGlobal(this->rotation).translate(this->position);

    this->_worldToLocal = ret;
}

