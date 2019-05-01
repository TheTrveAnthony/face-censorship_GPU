
# include openCV
cv = `pkg-config --cflags --libs opencv`

cen : censure.cpp functions.cpp
		g++ $^ $(cv) -g -o $@ 