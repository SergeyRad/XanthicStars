#include "BlastEffect.h"


BlastEffect::BlastEffect(void)
{
	data();
}
BlastEffect::~BlastEffect(void)
{
}

void BlastEffect::data(void)
{
	load("boom1.png");
	setPosition(0, 0);
	data_frames(6,6);
	setFlag3(true);
	data_time_frame(0.025);
}
bool BlastEffect::behavior(float time)
{
	if(!shift_frame(time)) 
		return false;
	return true;
}
void BlastEffect::drawBlastEffect(sf::RenderWindow* window)
{
	window->draw(sprite);
}
