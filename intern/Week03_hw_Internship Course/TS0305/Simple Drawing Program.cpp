/************************************************************************
File:
        Simple Drawing Program.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/06
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/07
Description:
        A simple drawing program (fill the background with *), allow users
        to draw square, isosceles right triangle and lines on the console.
        (for figures, fill with Upper X)
************************************************************************/
#include <iostream> // For cin, cout
#include <vector> // For vector container to store canvas

using namespace std;

// Function to initialize the canvas
void initCanvas(vector<vector<char>>& canvas, int width, int height);

// Function to print the canvas
void printCanvas(vector<vector<char>>& canvas);

// Function to draw a square
void drawSquare(vector<vector<char>>& canvas);

// Function to draw an isosceles right triangle
void drawRightTriangle(vector<vector<char>>& canvas);

// Function to draw a line
void drawLine(vector<vector<char>>& canvas);

int main(void)
{
    vector<vector<char>> canvas; // Canvas to store the drawing

    int width, height;
    cin >> width >> height;

    // Initialize the canvas
    initCanvas(canvas, width, height);

    string command; // Variable to store the command, reusable.

    // Loop to get the command and draw the figure
    while (cin >> command)
    {
        if (command == "S")
        {
            drawSquare(canvas);
        }
        else if (command == "T")
        {
            drawRightTriangle(canvas);
        }
        else if (command == "L")
        {
            drawLine(canvas);
        }
        else if (command == "EXIT")
        {
            break;
        }

        cout << endl;
    }
}

// Intent : Initialize the canvas with the given width and height
// Pre : canvas is an empty 2D vector, width and height are positive integers.
// Post : canvas is filled with '*' by the given width and height.
void initCanvas(vector<vector<char>>& canvas, int width, int height)
//==================================================================
{
    canvas.resize(height); // Resize the canvas to the given height

    // Fill the canvas with '*' by the given width & height
    /************************************************************************/
    for (int i = 0; i < height; i++)
    {
        canvas[i].resize(width);

        for (int j = 0; j < width; j++)
        {
            canvas[i][j] = '*';
        }
    }
    /************************************************************************/
}

// Intent : Display the canvas
// Pre : nothing showed on the console screen.
// Post : show the canvas on the console screen.
void printCanvas(vector<vector<char>>& canvas)
//==================================================================
{
    // Display the whole canvas
    /************************************************************************/
    for (int i = 0; i < canvas.size(); i++)
    {
        for (int j = 0; j < canvas[i].size(); j++)
        {
            cout << canvas[i][j];
        }
        cout << endl;
    }
    /************************************************************************/
}

// Intent : Draw a square on the canvas
// Pre : canvas keeps the drawing.
// Post : Draw a square on the canvas by the given size, x, y.
void drawSquare(vector<vector<char>>& canvas)
//==================================================================
{
    int x, y, size; // Variables to store the size, x, y of the square

    cin >> size >> x >> y;

    // Check if the square is out of range
    /************************************************************************/
    if (x < 0 || x + size > canvas[0].size()
        || y < 0 || y + size > canvas.size())
    {
        cout << "Out of range." << endl;
        return;
    }
    /************************************************************************/

    // Draw the square
    /************************************************************************/
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            canvas[i][j] = 'X';
        }
    }
    /************************************************************************/

    printCanvas(canvas); // Display the canvas
}

// Intent : Draw an isosceles right triangle on the canvas
// Pre : canvas keeps the drawing.
// Post : Draw an isosceles right triangle on the canvas by the given size, x, y, direction.
void drawRightTriangle(vector<vector<char>>& canvas)
//==================================================================
{
    int x, y, size; // Variables to store the size, x, y of the triangle
    string dir; // Variable to store the direction of the triangle

    cin >> size >> x >> y >> dir;

    // Draw the triangle depends on the direction
    /************************************************************************/
    if (dir == "LU")
    {
        // Check if the triangle is out of range
        if (x >= canvas[0].size() || y >= canvas.size()
            || x - size + 1 < 0 || y - size + 1 < 0)
        {
            cout << "Out of range." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                canvas[y - i][x - j] = 'X';
            }
        }
    }
    else if (dir == "RU")
    {
        // Check if the triangle is out of range
        if (x < 0 || y >= canvas.size()
            || x + size - 1 >= canvas[0].size() || y - size + 1 < 0)
        {
            cout << "Out of range." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                canvas[y - i][x + j] = 'X';
            }
        }
    }
    else if (dir == "LD")
    {
        // Check if the triangle is out of range
        if (x >= canvas[0].size() || y < 0
            || x - size + 1 < 0 || y + size - 1 >= canvas.size())
        {
            cout << "Out of range." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                canvas[y + i][x - j] = 'X';
            }
        }
    }
    else if (dir == "RD")
    {
        // Check if the triangle is out of range
        if (x < 0 || y < 0
            || x + size - 1 >= canvas[0].size() || y + size - 1 >= canvas.size())
        {
            cout << "Out of range." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                canvas[y + i][x + j] = 'X';
            }
        }
    }
    /************************************************************************/

    printCanvas(canvas); // Display the canvas
}

// Intent : Draw a line on the canvas
// Pre : canvas keeps the drawing.
// Post : Draw a line on the canvas by the given x1, y1, x2, y2.
void drawLine(vector<vector<char>>& canvas)
//==================================================================
{
    int x1, y1, x2, y2; // Variables to store the x1, y1, x2, y2 of the line

    cin >> x1 >> y1 >> x2 >> y2;

    // Check if the line is out of range
    /************************************************************************/
    if (x1 < 0 || x1 >= canvas[0].size() || x2 < 0 || x2 >= canvas[0].size()
        || y1 < 0 || y1 >= canvas.size() || y2 < 0 || y2 >= canvas.size())
    {
        cout << "Out of range." << endl;
        return;
    }
    /************************************************************************/

    // Draw the line
    /************************************************************************/
    if (x1 == x2)
    {
        int n = max(y1, y2);

        for (int i = min(y1, y2); i <= n; i++)
        {
            canvas[i][x1] = 'X';
        }
    }
    else if (y1 == y2)
    {
        int n = max(x1, x2);

        for (int i = min(x1, x2); i <= n; i++)
        {
            canvas[y1][i] = 'X';
        }
    }
    else {
        int dx = x2 - x1, dy = y2 - y1; // Variables to store the dx, dy of the line
        double m = (double)dy / dx; // Variable to store the slope of the line

        // Since the slope will only be 1 or -1, we can simplify the code.
        if (m == 1)
        {
            for (int i = 0; i <= dx; i++)
            {
                canvas[y1 + i][x1 + i] = 'X';
            }
        }
        else {
            for (int i = 0; i <= dx; i++)
            {
                canvas[y1 - i][x1 + i] = 'X';
            }
        }
    }
    /************************************************************************/

    printCanvas(canvas); // Display the canvas
}