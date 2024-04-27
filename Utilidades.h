#include "Encabezados.h"

template <typename T>
inline void gotoxy(T x, T y = Console::CursorTop) {
	Console::SetCursorPosition(x, y);
}

template <typename T>
inline void color(T color) {
	Console::ForegroundColor = ConsoleColor(color);
};

inline int getXCenter(string* s) {
	return ((Console::WindowWidth - s->length()) / 2);
}

template <typename T>
inline int getXCenter(T lengthX) {
	return ((Console::WindowWidth - lengthX) / 2);
}

template <typename T>
inline T getYCenter(T lengthY) {
	return ((Console::WindowHeight - lengthY) / 2);
}
