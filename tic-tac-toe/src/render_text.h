	// TODO: 
// Make the render_text class more robust and dynamic 
// so we can use it more effectively


class render_text
{
public:

	TTF_Font* textFont = TTF_OpenFont("res/arial.ttf", 25);
	SDL_Color textColor = {255, 255, 255};
	SDL_Texture* texture = nullptr; 
	SDL_Surface* surface = nullptr; 
	int tw = 100, th = 100;
	SDL_Rect dstrect;
	const char* text = "Hello World!";

	void changeText(SDL_Renderer* renderer, const char* label_text, int posx, int posy)
	{ 
		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);
		}

		if (surface != nullptr)
		{
			SDL_FreeSurface(surface);
		}

		text = label_text;
		surface = TTF_RenderText_Solid(textFont, text, textColor);
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_QueryTexture(texture, NULL, NULL, &tw, &th);
		dstrect = {posx, posy, tw, th};	
	}

	void render(SDL_Renderer* renderer)
	{
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	}
};