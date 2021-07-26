class render_window
{
public:
	const char* program_name = "Tic Tac Toe";
	int screen_width = 1280;
	int screen_height = 800;
	int screen_position_y = 50;
	int screen_position_x = 50;	
	SDL_Window* sdl_window;
	SDL_Renderer* renderer = NULL;
	SDL_Renderer* text_renderer = NULL;

	render_window()
	{
		// Create a window
		sdl_window = SDL_CreateWindow(program_name, screen_position_x, screen_position_y, screen_width, screen_height, 0);

		// Create Graphics Renderer
		renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

		// Create Text Renderer
		text_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
	}
};