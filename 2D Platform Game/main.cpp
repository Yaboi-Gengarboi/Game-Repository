// 2D Platform Game
// main.cpp
// Justyn Durnford
// Created on 2021-02-22
// Last updated on 2021-02-24
// Main file.

#include <SFML/Graphics/Texture.hpp>
using sf::Texture;

#include <SFML/Graphics/Sprite.hpp>
using sf::Sprite;

#include "Jlib/Arithmetic.h"
using Jlib::arithmetic;

#include "Jlib/Matrix.h"
using Jlib::Matrix;

#include "Jlib/Point.h"
using Jlib::Point2u;
using Jlib::Point2f;

#include "Jlib/Vector.h"
using Jlib::Vector2f;

#include <cmath>
using std::fabsf;

#include <cstddef>
using std::size_t;

#include <cstdint>
using std::uint8_t;
using std::uint32_t;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include <string>
using std::string;

// Level properties.
Matrix<uint8_t> level_layout;

// Player properties.
Point2f player_position;
Vector2f player_velocity;
bool is_grounded = true;

// Camera properties.
Point2f camera_position;

template <arithmetic T> void clamp(T& value, T lower, T upper)
{
	if (value < lower)
	{
		value = lower;
		return;
	}

	if (value > upper)
	{
		value = upper;
		return;
	}
}

template <typename T> void read(ifstream& fin, T& var)
{
	fin >> var;

	if (fin.bad() || fin.eof())
		throw runtime_error("Error reading from file");
}

bool is_tile_solid(const Point2f& position)
{
	switch (level_layout(position.x, position.y))
	{
		case '#':
			return true;
			break;

		case '_':
			return false;
			break;

		default:
			return false;
			break;
	}

	return false;
}

void check_collision()
{
	if (player_velocity.x < 0) // Player is moving left.
	{
		if (is_tile_solid(player_position))
		{
			player_position.x = int(player_position.x + 1);
			player_velocity.x = 0;
		}
	}
	else if (player_velocity.x > 0) // Player is moving right.
	{
		if (is_tile_solid(player_position))
		{
			player_position.x = int(player_position.x);
			player_velocity.x = 0;
		}
	}

	is_grounded = false;

	if (player_velocity.y < 0) // Player is moving "up" (y = 0 is the top of the screen).
	{
		if (is_tile_solid(player_position))
		{
			player_position.y = (int)player_position.y + 1;
			player_velocity.y = 0;
		}
	}
	else if (player_velocity.y > 0) // Player is moving "down" (y = 0 is the top of the screen).
	{
		if (is_tile_solid(player_position))
		{
			player_position.y = (int)player_position.y;
			player_velocity.y = 0;
			is_grounded = true;
		}
	}
}

void update(float elapsed_time)
{
	// Apply gravity.
	player_velocity.y += 20.0f * elapsed_time;

	// Apply traction.
	if (is_grounded)
	{
		player_velocity.x -= 3.0f * player_velocity.x * elapsed_time;

		if (fabsf(player_velocity.x) < 0.01f)
			player_velocity.x = 0.0f;
	}

	// Clamp velocity.
	clamp(player_velocity.x, -10.0f, 10.0f);
	clamp(player_velocity.y, -100.0f, 100.0f);

	// Calculate potential new position.
	player_position.x += player_velocity.x * elapsed_time;
	player_position.y += player_velocity.y * elapsed_time;

	// Check for collisions.
	check_collision();

	// Set camera to the player's position.
	camera_position = player_position;
}

bool load_level(const string& file_dir)
{
	try
	{
		ifstream fin(file_dir);

		if (!fin.is_open())
			return false;

		size_t row = 0, col = 0;

		read(fin, col);
		read(fin, row);

		read(fin, player_position.x);
		read(fin, player_position.y);

		level_layout = Matrix<uint8_t>(row, col);

		for (size_t r = 0; r < row; ++r)
		{
			for (size_t c = 0; c < col; ++c)
				read(fin, level_layout.at(r, c));
		}
	}
	catch (...) { return false; }

	return true;
}

int main()
{
	if (!load_level("level.txt"))
	{
		cout << "ERROR: Could not read from file level.txt" << endl;
		return 1;
	}

	// DEBUG
	// Print out level.
	for (size_t r = 0; r < level_layout.rowSize(); ++r)
	{
		for (size_t c = 0; c < level_layout.colSize(); ++c)
			cout << level_layout.at(r, c);

		cout << endl;
	}

	return 0;
}