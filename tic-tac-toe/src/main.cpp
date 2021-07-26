#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "render_window.h"
#include "rectangle.h"
#include "render_text.h"
#include "render_image.h"

int mouseX, mouseY;

// std::vector<int> spots;

bool doOnce[9] = {false};
bool X[9] = {false};
bool O[9] = {false};

bool gameOver = false;

int changeTurn(int randomNumber, int spot, SDL_Renderer* renderer)
{
	if (randomNumber == 0 && !doOnce[spot])
	{
		// Player 1 -> Player 2 turn
		std::cout << randomNumber << std::endl;
		doOnce[spot] = true;
		X[spot] = true;
		return 1;
	}

	if (randomNumber == 1 && !doOnce[spot])
	{
		// Player 2 -> Player 1 turn
		std::cout << randomNumber << std::endl;
		doOnce[spot] = true;
		O[spot] = true;
		return 0;
	}
}

bool checkWin(bool Player[], bool isPlayer1, SDL_Renderer* renderer)
{
	if ((Player[0] && Player[1] && Player[2]) || (Player[0] && Player[3] && Player[6]) || (Player[1] && Player[4] && Player[7]) || (Player[2] && Player[5] && Player[8]) || (Player[6] && Player[7] && Player[8]) || (Player[3] && Player[4] && Player[5]) || (Player[2] && Player[4] && Player[7]) || (Player[0] && Player[4] && Player[8]))
	{
		if (isPlayer1)
		{	
			return true;
		}
		else if (!isPlayer1)
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{

	srand((unsigned) time(0));
	int randomNumber = (rand() % 2) + 0;

	// Debug
	std::cout << randomNumber << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	render_window window;

	// If window was not created
	if (window.sdl_window == NULL) 
	{
		std::cout << "Could not find a window!" << std::endl;
	}

	while (1) 
	{ 
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			// If user clicks quit(the X on top right corner) then exit the program
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}
		// Need GetMouseState in here so we can keep track of mouseX and mouseY positions
		SDL_GetMouseState(&mouseX, &mouseY);

		// Output the value of mouseX and mouseY
		// std::cout << "X: " << mouseX << " | Y: " << mouseY << std::endl;  

		// Make the background color Black 
		SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
		SDL_RenderClear(window.renderer);

		// Main border of the game(the map)F
		Rectangle topbar(window.screen_width / 2 - 330,  window.screen_height / 2 - 350, 700, 25);
		topbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle bottombar(window.screen_width / 2 - 330, window.screen_height / 2 + 200, 700, 25);
		bottombar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle leftbar(window.screen_width / 2 - 330, window.screen_height / 2 - 330, 25, 550);
		leftbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle middleleftbar(window.screen_width / 2 - 100, window.screen_height / 2 - 350, 25, 550);
		middleleftbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle middlerightbar(window.screen_width / 2 + 125, window.screen_height / 2 - 350, 25, 550);
		middlerightbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle rightbar(window.screen_width / 2 + 350, window.screen_height / 2 - 350, 25, 575);
		rightbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle middletopbar(window.screen_width / 2 - 330, window.screen_height / 2 - 160, 700, 25);
		middletopbar.makeRect(window.renderer, 255, 255, 255, 255);

		Rectangle middlebottombar(window.screen_width / 2 - 330, window.screen_height / 2 + 20, 700, 25);
		middlebottombar.makeRect(window.renderer, 255, 255, 255, 255);

		render_text text;
		if (!gameOver)
		{
			switch(randomNumber)
			{
			case 0:
				text.changeText(window.renderer, "Turn: Player 1", window.screen_width / 2 - 50, 700);
				break;

			case 1:
				text.changeText(window.renderer, "Turn: Player 2", window.screen_width / 2 - 50, 700);
				break;

			default: 
				std::cout << "Something went wrong" << std::endl;
				break;
			}
		}

		if (SDL_GetMouseState(&mouseX, &mouseY) == 1)
		{
			if (mouseY <= 239 && mouseY >= 75 && mouseX >= 335 && mouseX <= 539 && !doOnce[0])
			{
				int number = changeTurn(randomNumber, 0, window.renderer);
				randomNumber = number;
				// std::cout << "Number: " << number << " | " << randomNumber << std::endl;
			}

			if (mouseY <= 239 && mouseY >= 75 && mouseX >= 565 && mouseX <= 764 && !doOnce[1])
			{
				int number = changeTurn(randomNumber, 1, window.renderer);
				randomNumber = number;
			}

			if (mouseY <= 239 && mouseY >= 75 && mouseX >= 790 && mouseX <= 989 && !doOnce[2])
			{
				int number = changeTurn(randomNumber, 2, window.renderer);
				randomNumber = number;
			}

			if (mouseY <= 420 && mouseY >= 265 && mouseX >= 335 && mouseX <= 539 && !doOnce[3])
			{
				int number = changeTurn(randomNumber, 3, window.renderer);
				randomNumber = number;
			}

			if (mouseY <= 420 && mouseY >= 265 && mouseX >= 565 && mouseX <= 764 && !doOnce[4])
			{
				int number = changeTurn(randomNumber, 4, window.renderer);
				randomNumber = number;
			}

			if (mouseY <= 420 && mouseY >= 265 && mouseX >= 790 && mouseX <= 989 && !doOnce[5])
			{
				int number = changeTurn(randomNumber, 5, window.renderer);
				randomNumber = number;
			}

			if (mouseY <= 598 && mouseY >= 445 && mouseX >= 335 && mouseX <= 539 && !doOnce[6])
			{
				int number = changeTurn(randomNumber, 6, window.renderer);
				randomNumber = number;
			}

			if (mouseY < 598 && mouseY >= 445 && mouseX >= 565 && mouseX <= 764 && !doOnce[7])
			{
				int number = changeTurn(randomNumber, 7, window.renderer);
				randomNumber = number;
			}

			if (mouseY < 598 && mouseY >= 445 && mouseX >= 790 && mouseX <= 989 && !doOnce[8])
			{
				int number = changeTurn(randomNumber, 8, window.renderer);
				randomNumber = number;
			}
		}

		// Construct X 
		render_image oX(window.renderer, 385, 100, true); // oneX
		render_image tX(window.renderer, 385 + 230, 100, true); // twoX
		render_image thX(window.renderer, 385 + 230 * 2, 100, true); // threeX

		render_image fX(window.renderer, 385, 300, true); // fourX
		render_image fiX(window.renderer, 385 + 230, 300, true); // fiveX
		render_image sX(window.renderer, 385 + 230 * 2, 300, true); // sixX

		render_image seX(window.renderer, 385, 475, true); // sevenX
		render_image eX(window.renderer, 385 + 230, 475, true); // eightX
		render_image nX(window.renderer, 385 + 230 * 2, 475, true); // nineX

		// Construct O
		render_image oO(window.renderer, 385, 100, false); // oneO
		render_image tO(window.renderer, 385 + 230, 100, false); // twoO
		render_image thO(window.renderer, 385 + 230 * 2, 100, false); // threeO

		render_image fO(window.renderer, 385, 300, false); // fourO
		render_image fiO(window.renderer, 385 + 230, 300, false); // fiveO
		render_image sO(window.renderer, 385 + 230 * 2, 300, false); // sixO

		render_image seO(window.renderer, 385, 475, false); // sevenO
		render_image eO(window.renderer, 385 + 230, 475, false); // eightO
		render_image nO(window.renderer, 385 + 230 * 2, 475, false); // nineO

		if (!gameOver)
		{ 
			for (int i = 0; i < 9; i++)
			{	
				if (X[i] && i == 0)
					oX.render(window.renderer);
				if (X[i] && i == 1)
					tX.render(window.renderer);
				if (X[i] && i == 2)
					thX.render(window.renderer);
				if (X[i] && i == 3)
					fX.render(window.renderer);
				if (X[i] && i == 4)
					fiX.render(window.renderer);
				if (X[i] && i == 5)
					sX.render(window.renderer);
				if (X[i] && i == 6)
					seX.render(window.renderer);
				if (X[i] && i == 7)
					eX.render(window.renderer);
				if (X[i] && i == 8)
					nX.render(window.renderer);

				if (O[i] && i == 0)
					oO.render(window.renderer);
				if (O[i] && i == 1)
					tO.render(window.renderer);
				if (O[i] && i == 2)
					thO.render(window.renderer);
				if (O[i] && i == 3)
					fO.render(window.renderer);
				if (O[i] && i == 4)
					fiO.render(window.renderer);
				if (O[i] && i == 5)
					sO.render(window.renderer);
				if (O[i] && i == 6)
					seO.render(window.renderer);
				if (O[i] && i == 7)
					eO.render(window.renderer);
				if (O[i] && i == 8)
					nO.render(window.renderer);
			}
		}


		bool checkPlayer1Win = checkWin(X, true, window.renderer);
		bool checkPlayer2Win = checkWin(O, false, window.renderer);

		if (checkPlayer1Win)
		{
			text.changeText(window.renderer, "Player 1 won", window.screen_width / 2 - 50, 700);
			gameOver = true;

		}
		else if(checkPlayer2Win)
		{
			text.changeText(window.renderer, "Player 2 won", window.screen_width / 2 - 50, 700);
			gameOver = true;
		}

		text.render(window.renderer);
		SDL_RenderPresent(window.renderer);
	}	

	// Clean up
	SDL_DestroyRenderer(window.renderer);
	SDL_DestroyWindow(window.sdl_window);

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	return 0;
}
