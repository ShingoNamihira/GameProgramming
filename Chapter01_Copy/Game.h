#include <SDL/SDL.h>

using namespace std;

class Game {
public:
	Game();
	//ゲームを初期化する
	bool Initialize();
	//ゲームオーバーまでゲームループを実行する
	void RunLoop();
	//ゲームをシャットダウンする
	void Shutdown();

private:
	//ゲームループのためのヘルパー関数軍
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//SDLが作るウィンドウ
	SDL_Window*mWindow;
	//ゲームの続行を指示する
	bool mIsRunning = true;
};