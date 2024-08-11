#include "Core.h"
#include <iostream>

namespace Core
{
	SDL_Renderer* Game::Renderer = nullptr;

	void Game::Initialize(const char* title, int x, int y, int windowWidth, int windowHeight)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
			SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
			m_window = SDL_CreateWindow(title, x, y, windowWidth, windowHeight, window_flags);
			Renderer = SDL_CreateRenderer(m_window, -1, 0);

			if (Renderer)
			{
				SDL_SetRenderDrawColor(Renderer, 31, 31, 31, 255);
				std::cout << "Renderer created..." << std::endl;
				m_isRunning = true;
			}
			else
			{
				m_isRunning = false;
			}

			//Disable resize window
			SDL_SetWindowResizable(m_window, SDL_FALSE);
		}
	}
	void Game::Update()
	{
		if (!m_isRunning) return;
		HandleEvent();
	}
	void Game::Render()
	{
		if (!m_isRunning) return;
		
		SDL_SetRenderDrawColor(Renderer, 31, 31, 31, 255);
		SDL_RenderPresent(Renderer);
		SDL_RenderClear(Renderer);
	}
	bool Game::IsRunning()
	{
		return m_isRunning;
	}
	void Game::HandleEvent()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		}
	}
}
