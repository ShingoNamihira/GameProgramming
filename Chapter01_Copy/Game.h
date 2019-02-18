#include <SDL/SDL.h>

using namespace std;

class Game {
public:
	Game();
	//�Q�[��������������
	bool Initialize();
	//�Q�[���I�[�o�[�܂ŃQ�[�����[�v�����s����
	void RunLoop();
	//�Q�[�����V���b�g�_�E������
	void Shutdown();

private:
	//�Q�[�����[�v�̂��߂̃w���p�[�֐��R
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//SDL�����E�B���h�E
	SDL_Window*mWindow;
	//�Q�[���̑��s���w������
	bool mIsRunning = true;
};