//---------------------------------------------------------------------------
// RenderTest.cc
//---------------------------------------------------------------------------

#include "CC.h"
#include "system/ILowLevelSystem.h"
#include "graphics/ILowLevelGraphics.h"
#include "graphics/IVertexBuffer.h"
#include "graphics/IShaderProgram.h"

  using namespace CC;

  Game* game = NULL;

  class RenderUpdate : public IUpdateable
  {
    public:
      RenderUpdate()
      {
        // Add an action to exit when ESC key is pressed
        game->GetInput()->AddAction(new ActionKeyboard("ExitGame",
              ccKey(ccKey_ESCAPE), game->GetInput()));


        // Add Shader
        m_lowLevelGraphics = game->GetGraphics()->GetLowLevel();
        m_shaderProgram = m_lowLevelGraphics->CreateShaderProgram("../data/test.vert",
                                                                "../data/test.frag");
        m_shaderProgram->Compile();
        m_shaderProgram->Link();
        m_shaderProgram->Validate();
        m_shaderProgram->Bind();

        // Add a VBO
        m_vbo = m_lowLevelGraphics->CreateVertexBuffer();
        Vector3f vertex(0.0, 0.0, 0.0);
        m_vbo->AddVertex(vertex);
        m_vbo->Compile();
    }

    void Update()
    {
      if(game->GetInput()->BecameTriggered("ExitGame"))
      {
        game->Exit();
      }

      // Draw VBO
      m_vbo->Bind();
      m_vbo->Draw();
      m_vbo->UnBind();

      m_lowLevelGraphics->SwapBuffers();
    }

  private:
    ILowLevelGraphics* m_lowLevelGraphics;
    IVertexBuffer* m_vbo;
    IShaderProgram* m_shaderProgram;
};

int ccMain()
{
  // Create factories
  GameSetupFactory* setupFactory = new GameSetupFactory();

  // Init game
  ILowLevelGameSetup* gameSetup = setupFactory->CreateGameSetup();
  game = new Game(gameSetup, 800, 600);

  // Add update
  RenderUpdate renderUpdate;
  game->GetUpdater()->AddUpdate(&renderUpdate);

  // Run
  game->Run();

  return 0;
}
