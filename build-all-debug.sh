cmake -S . -B build/debug \
      -G "Ninja" \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_C_STANDARD=23 \
      -DCMAKE_C_FLAGS="-std=c23" \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
      -DPH_BUILD_TEST=OFF \
      -DPH_BUILD_TOOL=OFF;

ln -sf build/debug/compile_commands.json;

cmake --build build/debug;

