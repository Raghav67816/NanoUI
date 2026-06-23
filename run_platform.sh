#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SDL_DIR="$SCRIPT_DIR/lib/platform/sdl"
BUILD_DIR="$SDL_DIR/build"

echo "Building NanoUI SDL..."

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)

echo "Running NanoUI SDL..."
./NanoUI_SDL