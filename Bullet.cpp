#include "Bullet.h"
#include <stdio.h>
#include <conio2.h>
#include <constream>

using namespace std;
using namespace conio;

Bullet::Bullet(){ 
	inUse_ = false;
}

bool Bullet::isActive() {
	return inUse_;
}

void Bullet::init(const int position[2], const int velocity[2], const int color) {
	velocity_[0] = velocity[0];
	velocity_[1] = velocity[1];
	position_[0] = position[0];
	position_[1] = position[1];
	color_ = color;
	inUse_ = true;
}

void Bullet::draw() { 
	gotoxy(position_[0], position_[1]);
	textcolor(color_);
	puts(sprite);
}

void Bullet::die() {
	inUse_ = false;
}

void Bullet::move() { 
	if (!inUse_) {
		return;
	}
	
	position_[0] = position_[0] + velocity_[0];
	position_[1] = position_[1] + velocity_[1];
	
	if (position_[0] >= 117 || position_[1] >= 57 || position_[0] <= 2 || position_ [1] <=2) {
		die();
	} else {
		draw();
	}
}


