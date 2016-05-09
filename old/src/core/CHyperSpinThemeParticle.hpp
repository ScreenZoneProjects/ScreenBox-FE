#pragma once

#include "CHyperSpinThemeMedia.hpp"

class CHyperSpinThemeParticle : public CHyperSpinThemeMedia
{
public:
	CHyperSpinThemeParticle();

private:
	bool m_bIsOn;

	float m_f32PPM;
	int m_i32EmitterX;
	int m_i32EmitterY;
	int m_i32EmitterWidth;
	int m_i32EmitterHeight;


};
