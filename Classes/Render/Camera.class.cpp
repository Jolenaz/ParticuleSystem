/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:19:31 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:33 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.class.hpp"

Camera::Camera(){
    this->fov = 50;
    this->near = 1;
    this->far = 100;
    this->ratio = 4.0f / 3.0f;
}

Camera::Camera(float fov, float near, float far, float ratio): fov(fov), near(near), far(far), ratio(ratio){
}

Camera::~Camera(){}

Camera::Camera(Camera const & src){
    this->fov =   src.fov;
    this->near =  src.near;
    this->far =   src.far;
    this->ratio = src.ratio;
}

Camera & Camera::operator=(Camera const & src){
    this->fov =   src.fov;
    this->near =  src.near;
    this->far =   src.far;
    this->ratio = src.ratio;
    return *this;
}

void Camera::_calcProjection()
{
    float tanFov = tanf(this->fov / 2.0f * M_PI / 180.0f);

    this->_projMat.set_identity();
    this->_projMat.value.m00 = 1.0f / (this->ratio * tanFov);
    this->_projMat.value.m11 = 1.0f / tanFov;
    this->_projMat.value.m22 = (this->near + this->far) / (this->near - this->far);
    this->_projMat.value.m23 = -1.0f;
    this->_projMat.value.m32 = 2.0f * this->near * this->far / (this->near - this->far);
    this->_projMat.value.m33 = 0.0f;
}

Mat4 Camera::get_projMat( void ){
    this->_calcProjection();
    return this->_projMat;
}
void Camera::translateCam(Vec3 trans){

    Vec4 trans4(trans, 0.0f);

    Vec3 newTrans( this->transform.get_worldToLocal() * trans4 );

    this->transform.translate(newTrans);

}

