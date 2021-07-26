class Rectangle 
{
public:
	SDL_Rect rect;

	Rectangle(int xpos, int ypos, int width, int height)
	{
		rect.x = xpos;
		rect.y = ypos;
		rect.w = width;
		rect.h = height;
	}

	void makeRect(SDL_Renderer* renderer, int r, int g, int b, int a)
	{
		setColor(renderer, r, g, b, a);
		fillRect(renderer);
	}

	void clear(SDL_Renderer* renderer)
	{
		SDL_RenderClear(renderer);
	}

private:
	void setColor(SDL_Renderer* renderer, int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	void fillRect(SDL_Renderer* renderer)
	{
		SDL_RenderFillRect(renderer, &rect);
	}

	void setShow(SDL_Renderer* renderer)
	{ 
		SDL_RenderPresent(renderer);
	}
};
