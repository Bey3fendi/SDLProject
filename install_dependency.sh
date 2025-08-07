#!/bin/bash

# Update package list
echo "Updating package list..."
sudo apt update

# Install SDL2 development package and pkg-config
echo "Installing SDL2 and pkg-config..."
sudo apt install -y libsdl2-dev pkg-config libsdl2-ttf-dev

# Verify installation
echo "Verifying SDL2 installation..."
pkg-config --modversion sdl2 && echo "SDL2 installed successfully!" || echo "Failed to detect SDL2."
