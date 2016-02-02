/*
 * MultiPIDOutput.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Mackinnon Buck
 */

#include <MultiPIDOutput.h>

void MultiPIDOutput::AddTalon(uint8_t port, bool inverted)
{
	m_talons.push_back(new Talon(port));
	m_talons.back()->SetInverted(inverted);
}

void MultiPIDOutput::PIDWrite(float output)
{
	for (auto talon : m_talons)
		talon->Set(output);
}
