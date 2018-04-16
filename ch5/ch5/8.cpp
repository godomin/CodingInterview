#include <iostream>
#define BYTE 8
#define MASK1S 0xff
using namespace std;
char drawBit(char n, int start, int end) {
    char mask = MASK1S >> (BYTE+start-end-1);
    return n | mask;
}


void drawLine(char* screen, int width, int x1, int x2, int y) {
    int startScreen = x1 / BYTE;
    int startBit = x1 % BYTE;
    int endScreen = x2 / BYTE;
    int endBit = x2 % BYTE;
    drawBit(screen[startScreen], startBit, BYTE - 1);
    drawBit(screen[endScreen], 0, endBit);
    for(int i=startScreen+1; i<=endScreen; i++) {
        screen[i] |= MASK1S;
    }
}


int main() {
    char* screen = new char[100];
    int width;
    int y;
    int x1, x2;
    cin >> width >> y >> x1 >> x2;
    width /= BYTE;
    for(int i=0;i<width*y;i++) {
        string in;
        cin >> in;
        screen[i] = stoi(in, nullptr, 2);
    }
    
    drawLine(screen, width, x1, x2, y);
    
    for(int i=0;i<y;i++) {
        for(int j=0;j<width;j++) {
            cout << bitset<8>(screen[i*width+j]).to_string() << " ";
        }
        cout << endl;
    }
}
