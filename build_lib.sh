SUPERPROJECT_PWD="$(pwd)"
BUILD_DIR="$SUPERPROJECT_PWD/lib/build"

echo "Updating FFmpeg library submodules..."
cd $SUPERPROJECT_PWD/lib/FFmpeg
git submodule update --init

echo "Updating QtAV submodules..."
cd $SUPERPROJECT_PWD/lib/QtAV
git submodule update --init

echo "Building FFmpeg library..."
cd $SUPERPROJECT_PWD/lib/QtAV/tools/build_ffmpeg
export FFSRC=$SUPERPROJECT_PWD/lib/FFmpeg
./build_ffmpeg.sh

echo "Building QtAV and its SDK..."
mkdir -p $BUILD_DIR && cd $BUILD_DIR
export CPATH=$SUPERPROJECT_PWD/lib/QtAV/tools/build_ffmpeg/sdk/include:$CPATH
export LIBRARY_PATH=$SUPERPROJECT_PWD/lib/QtAV/tools/build_ffmpeg/sdk/lib:$LIBRARY_PATH
qmake $SUPERPROJECT_PWD/lib/QtAV/QtAV.pro
rm -f $BUILD_DIR/.qmake.cache
qmake $SUPERPROJECT_PWD/lib/QtAV/QtAV.pro -r "CONFIG+=recheck"

make -j 4

echo "Putting SDK libraries in Qt installation directory..."
sudo chmod +x sdk_*.sh
./sdk_uninstall.sh
./sdk_install.sh

exit 0
