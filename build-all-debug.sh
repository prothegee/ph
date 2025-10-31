cmake -S . -B build/debug \
      -G "Ninja" \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_C_STANDARD=23 \
      -DCMAKE_C_FLAGS="-std=c23 -fPIC" \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
      -DPH_BUILD_TEST=ON \
      -DPH_BUILD_TOOL=ON;

ln -sf build/debug/compile_commands.json ./;

cmake --build build/debug;

