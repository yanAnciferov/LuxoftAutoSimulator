#include "Menu.h"

Menu::Menu() {
	xCursor_ = MENU_LEFT_MARGIN - 1;
	yCursor_ = MENU_TOP_MARGIN + 2;
}

void Menu::start() {

	Console::WindowFont();
	Console::SetColor(COLOR_WHITE, COLOR_GREEN);
	system("cls");
	Console::SetWindowSize(WINDOW_HEIGTH, WINDOW_WIDTH);
	Console::SetCursorVisible(false);


	Console::SetCursorPosition(MENU_LEFT_MARGIN, MENU_TOP_MARGIN);
	cout << "Chouse game mode:" << endl;
	Console::SetCursorPosition(MENU_LEFT_MARGIN, MENU_TOP_MARGIN + 2);
	cout << "Game with levels" << endl;
	Console::SetCursorPosition(MENU_LEFT_MARGIN, MENU_TOP_MARGIN + 3);
	cout << "A record" << endl;

	char key;
	while (true) {

		Console::SetCursorPosition(xCursor_, yCursor_);
		cout << ">";

		key = _getch();

		Console::SetCursorPosition(xCursor_, yCursor_);
		cout << " ";

		switch (static_cast<Keys>(key))
		{
		case KEYS_UPKEY:
			if (yCursor_ != MENU_TOP_MARGIN + 2) {
				yCursor_--;
			}
			break;

		case KEYS_DOWNKEY:
			if (yCursor_ != MENU_TOP_MARGIN + 3) {
				yCursor_++;
			}
			break;

		case KEYS_ENTER:
			if (yCursor_ == MENU_TOP_MARGIN + 3) {
				Game& game = GameForAScore();
				game.start();
			}
			else {
				Game& game = GameWithLavel();
				game.start();
			}
			return;
			break;

		case KEYS_ESC:
			return;
		default:
			break;
		}
	}


}
