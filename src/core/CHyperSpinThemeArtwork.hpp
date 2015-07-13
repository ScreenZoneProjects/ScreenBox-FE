#pragma once

#include<QtGlobal>

#include "CHyperSpinThemeMedia.hpp"

class CHyperSpinThemeArtwork : CHyperSpinThemeMedia
{
public:
	CHyperSpinThemeArtwork();



private:
	float m_f32Width;
	float m_f32Height;

	float m_f32Rotation;
	float m_f32RotationPositionX;
	float m_f32RotationPositionY;
	// forceaspect
	float m_f32Delay;
	float m_f32Time;
	//int m_int32BShape;

	ERestingAnimation m_eRestingAnimation;
	EAnimationType m_eAnimationType;

};
