#pragma once
#include <SDL.h>
#include <SDL_image.h>

namespace Core
{
	class Game
	{
		public:
			void Initialize(const char* title, int x, int y, int windowWidth, int windowHeight);
			void Update();
			void Render();
			bool IsRunning();
			static SDL_Renderer* Renderer;
		private:

			void HandleEvent();

			bool m_isRunning;
			SDL_Window* m_window;
	};
}
