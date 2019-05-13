
# include openCV
cv = `pkg-config --cflags --libs opencv`

cen : censure.cpp func.cpp
		nvcc $^ $(cv) -g -o $@ 