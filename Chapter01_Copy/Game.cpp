#include "Game.h"

Game::Game()
{
}

bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		SDL_Log("SDLを初期化できません:%s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (第1章)",	//ウィンドウのタイトル
		100,	//ウィンドウ左上隅のx座標
		100,	//ウィンドウ左上隅のy座標
		1024,	//ウィンドウの幅(width)
		768,	//ウィンドウの高さ(height)
		0		//フラグ(設定しないときは0)
	);
	if (!mWindow) {
		SDL_Log("ウィンドウの作成に失敗しました:%s", SDL_GetError());
		return false;
	}
	return true;
}

void Game::RunLoop() {
	while (mIsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown() {
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::ProcessInput() {
	SDL_Event event;
	//キューにイベントがあれば繰り返す
	while (SDL_PollEvent(&event)) {
		//ここで各種のイベントを処理する
		switch (event.type) {
			case SDL_QUIT:
				mIsRunning = false;
				break;
		}
	}
	//キーボードの状態を取得する
	const Uint8* state = SDL_GetKeyboardState(NULL);
	//[ESC]キーが押されていても、ループを終える
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
}
void Game::UpdateGame() {
}
void Game::GenerateOutput() {
}