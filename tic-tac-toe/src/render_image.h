class render_image 
{

SDL_Surface* surface = nullptr;
SDL_Texture* texture = nullptr;
SDL_Rect imageRect;

int iw = 100, ih = 100;


public:
	render_image(SDL_Renderer* renderer, int posx, int posy, bool X)
	{
		if (X)
			surface = IMG_Load("res/X.png");

		if (!X)
			surface = IMG_Load("res/O.png");

		texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_FreeSurface(surface);

		imageRect = {posx, posy, iw, ih};

		// SDL_RenderPresent(renderer);
	}

 	void render(SDL_Renderer* renderer)
 	{
		SDL_RenderCopy(renderer, texture, NULL, &imageRect);
 	}
};