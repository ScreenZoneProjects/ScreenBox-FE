#!/bin/sh

echo "FFmpeg build script for Mac OSX and Linux hosts"
echo "===============================================\n"

usedlibs='automake fdk-aac git lame libass libtool libvorbis libvpx opus sdl shtool texi2html theora wget x264 xvid yasm libopenjpeg'
configoptions='--prefix=../prebuilt --enable-gpl --enable-version3 --disable-static --enable-shared --disable-programs --disable-doc --enable-libmp3lame --enable-libopenjpeg --enable-libvorbis --enable-libvpx --enable-libx264 --enable-libxvid --disable-debug'
directory=$(dirname "$0")
platform='unknown'
unamestr=$(uname)
if [[ "$OSTYPE" == "darwin"* ]]; then
  platform='osx'
elif [[ "$OSTYPE" == 'linux' ]]; then
  platform='linux'
fi

if [[ "$platform" == 'unknown' ]]; then
  echo "Error: Can't find supported machine OS. Are you on Linux or OSX ?"
  exit 1
fi

rm -rf $directory/prebuilt/*
cd "$directory/FFmpeg"

if [[ "$platform" == 'osx' ]]; then
  brew install $usedlibs
else
  apt-get install $usedlibs
fi

./configure $configoptions

make -j4
sudo make install
