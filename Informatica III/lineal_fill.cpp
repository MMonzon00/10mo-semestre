#include <iostream>

// Function to perform linear gradient fill
void linearGradientFill(char** canvas, int startX, int endX, int y, char startColor, char endColor) {
    for (int x = startX; x <= endX; ++x) {
        // Calculate the current color based on the gradient
        float gradient = (float)(x - startX) / (endX - startX);
        char currentColor = static_cast<char>(startColor + (endColor - startColor) * gradient);

        // Fill the pixel at (x, y) with the current color
        canvas[y][x] = currentColor;
    }
}

int main() {
    const int canvasWidth = 20;
    const int canvasHeight = 10;

    // Create a 2D array to represent the canvas
    char** canvas = new char*[canvasHeight];
    for (int i = 0; i < canvasHeight; ++i) {
        canvas[i] = new char[canvasWidth];
        // Initialize the canvas with a background color (e.g., ' ')
        for (int j = 0; j < canvasWidth; ++j) {
            canvas[i][j] = ' ';
        }
    }

    int startX = 3;
    int endX = 16;
    int y = 5;
    char startColor = 'A';
    char endColor = 'Z';

    // Perform the linear gradient fill
    linearGradientFill(canvas, startX, endX, y, startColor, endColor);

    // Print the canvas with the gradient fill
    for (int i = 0; i < canvasHeight; ++i) {
        for (int j = 0; j < canvasWidth; ++j) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }

    // Clean up the memory
    for (int i = 0; i < canvasHeight; ++i) {
        delete[] canvas[i];
    }
    delete[] canvas;

    return 0;
}