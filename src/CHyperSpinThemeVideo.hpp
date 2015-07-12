#pragma once

#include "CHyperSpinThemeMedia.hpp"

class CHyperSpinThemeVideo
{
public:
	CHyperSpinThemeVideo();

	enum EForceAspect
	{
		EForceAspect_None,
		EForceAspect_Horizontal,
		EForceAspect_Vertical,
		EForceAspect_Both
	};

private:
	float m_f32Width;
	float m_f32Height;
	float m_f32PositionX;
	float m_f32PositionY;
	float m_f32Rotation;
	float m_f32RotationPositionX;
	float m_f32RotationPositionY;
	bool m_bIsBelow;
	bool m_bIsOverlayBelow;
	float m_f32OverlayOffsetX;
	float m_f32OverlayOffsetY;

	float m_f32Delay;
	float m_f32Time;
	int m_int32BSize;
	int m_int32BSize2;
	int m_int32BSize3;
	int m_int32BColor;
	int m_int32BColor2;
	int m_int32BColor3;


	CHyperSpinThemeMedia::EStartingPosition m_eStartingPosition;
	CHyperSpinThemeMedia::EAnimationType m_eAnimationType;
	CHyperSpinThemeMedia::ERestingAnimation m_eRestingAnimation;

	bool m_bIsBelowWheel;
};
