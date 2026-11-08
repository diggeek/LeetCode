# build
mkdir build && cd build <br>
cmake -DSANITIZER_MODE=MSAN ../ <br>
cmake --build ./ --target search_insert_position <br>
