#include "Console.h"



/******************************************************************************
*******************************************************************************/
Console::Console()
    : m_hScreenBuffer(NULL), 
      m_width(0), 
      m_height(0)
{
    setFullScreen();
}

/******************************************************************************
*******************************************************************************/
Console::Console(int x, int y, int width, int height)
    : m_hScreenBuffer(NULL),
      m_width(0),
      m_height(0)
{
    setWindowed(x, y, width, height);
}

/******************************************************************************
*******************************************************************************/
Console::~Console()
{
}

/******************************************************************************
*******************************************************************************/
void Console::clearScreen()
{
    for (int y = 0; y < m_height; y++)
    {
        write(0, y, ' ', m_width);
    }
}

/******************************************************************************
*******************************************************************************/
const int Console::height() const
{
    return m_height;
}

/******************************************************************************
*******************************************************************************/
bool Console::setFullScreen()
{
    // Get a handle to the console's window
    HWND hwnd = GetConsoleWindow();

    // Remove all of the chrome from the window (i.e. caption bar and frame)
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    DWORD styleToRemove = WS_CAPTION | WS_SYSMENU | WS_MINIMIZE | WS_MINIMIZEBOX | WS_MAXIMIZE | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_HSCROLL | WS_VSCROLL | WS_BORDER | WS_DLGFRAME | WS_SIZEBOX;
    DWORD newStyle = style & ~styleToRemove;

    // Get a handle to the screen buffer
    m_hScreenBuffer = ::GetStdHandle(STD_OUTPUT_HANDLE);

    // Get info about the console window's current font, in particular, its size
    CONSOLE_FONT_INFO cfi;
    ::GetCurrentConsoleFont(m_hScreenBuffer, FALSE, &cfi);
    COORD fontSize = ::GetConsoleFontSize(m_hScreenBuffer, cfi.nFont);

    // Get the width and height of the primary display monitor (pixels)
    int widthPxls = ::GetSystemMetrics(SM_CXSCREEN);
    int heightPxls = ::GetSystemMetrics(SM_CYSCREEN);
	m_consoleW = widthPxls;
	m_consoleH = heightPxls;

    // Calculate the width and height of the full screen window in terms of 
    // numbers of characters 
    m_width = widthPxls / fontSize.X;
    m_height = heightPxls / fontSize.Y + 1;

    // Set the size of the console window's scren buffer to match the computed
    // width and height (in characters)
    COORD bufferSize;
    bufferSize.X = m_width;
    bufferSize.Y = m_height;
    ::SetConsoleScreenBufferSize(m_hScreenBuffer, bufferSize);

    // Set the window's style so we can remove the chrome
    ::SetWindowLong(hwnd, GWL_STYLE, newStyle);
    ::SetWindowLong(hwnd, GWL_EXSTYLE, 0);

    // ...and show the window at the relevant size and position
    ::SetWindowPos(hwnd, NULL, 0, 0, widthPxls + 100, heightPxls + 100, SWP_FRAMECHANGED);

    return true;
}

/******************************************************************************
*******************************************************************************/
bool Console::setWindowed(int x, int y, int width, int height)
{
    // Get a handle to the console's window
    HWND hwnd = GetConsoleWindow();

    // Get a handle to the screen buffer
    m_hScreenBuffer = ::GetStdHandle(STD_OUTPUT_HANDLE);

    // Get info about the console window's current font, in particular, its size
    CONSOLE_FONT_INFO cfi;
    ::GetCurrentConsoleFont(m_hScreenBuffer, FALSE, &cfi);
    COORD fontSize = ::GetConsoleFontSize(m_hScreenBuffer, cfi.nFont);

    m_width = width;
    m_height = height;

    // Set the size of the console window's scren buffer to match the computed
    // width and height (in characters)
    COORD bufferSize;
    bufferSize.X = m_width;
    bufferSize.Y = m_height;
    ::SetConsoleScreenBufferSize(m_hScreenBuffer, bufferSize);

    // COmpute the width and height of the required window in pixels
    int widthPxls = (m_width + 2) * fontSize.X;
    int heightPxls = m_height * fontSize.Y;
	m_consoleW = widthPxls;
	m_consoleH = heightPxls;

    // Compute a RECT that will enlarge the windwo so that its drawble are 
    // (i.e. the client area) is large enough to exactly contain  the required
    // number of characters across and down
    RECT rc;
    rc.left = rc.top = 0;
    rc.right = widthPxls;
    rc.bottom = heightPxls;
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    ::AdjustWindowRect(&rc, style, FALSE);

	if (x = -1 && y == -1)
	{
		// Get the width and height of the primary display monitor (pixels)
		int screenWidthPxls = ::GetSystemMetrics(SM_CXSCREEN);
		int screenHeightPxls = ::GetSystemMetrics(SM_CYSCREEN);

		// calculate centre of screen for console
		int cx = (screenWidthPxls / 2) - (widthPxls / 2);
		int cy = (screenHeightPxls / 2) - (heightPxls / 2);

		// ...and show the window at the relevant size and position
		::SetWindowPos(hwnd, NULL, cx, cy, rc.right - rc.left, rc.bottom - rc.top, SWP_FRAMECHANGED);
	}
	else
	{
		// ...and show the window at the relevant size and position
		::SetWindowPos(hwnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_FRAMECHANGED);
	}
    return true;
}

/******************************************************************************
*******************************************************************************/
const int Console::width() const
{
    return m_width;

}

/******************************************************************************
*******************************************************************************/
void Console::write(int xPos, int yPos, char character, int numCharacters)
{
    if (m_hScreenBuffer)
    {
        COORD coord;
        coord.X = xPos;
        coord.Y = yPos;
        DWORD numWritten;
        ::FillConsoleOutputCharacter(m_hScreenBuffer, character, numCharacters, coord, &numWritten);
    }
}

