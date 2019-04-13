

int maxArea(int* height, int heightSize) {
    int i,j;
    long long area;
    int h1, h2;
    int w, h;
    int max = 0;
    int i_prev = heightSize-1;
    int i_next = 0;
    while(i_prev - i_next >= 1) {
        h1 = height[i_next];
        h2 = height[i_prev];
        w = i_prev - i_next;
        if(h1<h2) {
            h = h1;
            i_next ++;
        } else {
            i_prev --;
            h = h2;
        }
        area = w*h;
        if(area > max) {
            max = area;
        }
    }
    return max;
}

