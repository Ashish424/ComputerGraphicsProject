//
// Created by Ashish Aapan on 09/11/15.
//

#include "TempCanvas.hpp"
#include <QDebug>
#include <opencv2/highgui.hpp>
//TODO diable these debug macros
#define DEBUG_CANVAS

#ifdef DEBUG_CANVAS
#include <QOpenGLContext>

#endif



#include "ApplicationLogic/L-Systems/LSystem.hpp"
#include "ApplicationLogic/L-Systems/Turtle.hpp"
#include "ApplicationLogic/L-Systems/Plant.hpp"
#include "ApplicationLogic/Shader.hpp"
#include "ApplicationLogic/utils/utilityFunctions.hpp"
TempCanvas::TempCanvas(QWidget *parent):QOpenGLWidget(parent)
{
  timer = new QTimer(this);
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(FixedUpdate()));
  timer->start(timestep);
  nextButton = new QPushButton(this);
  nextButton->setObjectName(QStringLiteral("NextButton"));
  nextButton->setText(QString("next"));
  QObject::connect(this->nextButton,SIGNAL(clicked(bool)),this,SLOT(clickedNext()));



}

TempCanvas::~TempCanvas()
{
}

void TempCanvas::resizeGL(int w, int h)
{
  glViewport(0,0,w,h);
  glOrtho(0,w,h,0,-1,1);
}

void TempCanvas::paintGL()
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
// Accept fragment if it closer to the camera than the former one
  //TODO see less equal vs less
  glDepthFunc(GL_LEQUAL);
  plant->update();




}


void TempCanvas::initializeGL()
{


  setupGlew();


  glOrtho(0,width(),height(),0,-1,1);
  glLoadIdentity();

#ifdef DEBUG_CANVAS
  QOpenGLContext *cont = context();
  qDebug() << "Context valid: " << cont->isValid();
  qDebug() << "Really used OpenGl: " << cont->format().majorVersion() << "." << cont->format().minorVersion();
  qDebug() << "OpenGl information: VENDOR:       " << (const char*)glGetString(GL_VENDOR);
  qDebug() << "                    RENDERDER:    " << (const char*)glGetString(GL_RENDERER);
  qDebug() << "                    VERSION:      " << (const char*)glGetString(GL_VERSION);
  qDebug() << "                    GLSL VERSION: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
  qDebug() << "endstuff\n";
#endif
  glClearColor(0.0f,0.0f,0.0f,1.0f);


  //TODO remove this
  //NO Cam here
  //use iden matrix for view matrix

  std::vector<TerrainDemo::ShaderDefinition>  indexVec;
  std::vector<std::string>  uniformsVec;


  //shader for plant testing
  indexVec.push_back(TerrainDemo::ShaderDefinition(GL_VERTEX_SHADER,"./shaders/TestShader/basicVertex.glsl"));
  indexVec.push_back(TerrainDemo::ShaderDefinition(GL_FRAGMENT_SHADER,"./shaders/TestShader/basicFrag.glsl"));

  //vector of uniforms for each shader in pair
  uniformsVec.push_back("model");
  uniformsVec.push_back("view");





  shad = new TerrainDemo::Shader(indexVec,uniformsVec);

  glm::vec3 pos = glm::vec3(-1.0/2,-0.8,0.0);
  glm::vec3 scale  = glm::vec3(1.0,1.0,1.0);
  glm::vec3 rot = glm::vec3(0.0,0.0,0.0);
  TransformData t1(pos,rot,scale);




  TerrainDemo::LSystem  sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_1);


  std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
//  printf("the generated string is  %s\n",gen->c_str());

  TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
  //TODO delete this plant
  this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


}
void TempCanvas::setupGlew() const {
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {

    qWarning("Failed to initialize GLEW\n");
  }
}

void TempCanvas::FixedUpdate() {




  this->repaint();



}

void TempCanvas::clickedNext() {
  glm::vec3 pos = glm::vec3(-1.0/2,-0.8,0.0);
  glm::vec3 scale  = glm::vec3(1.0,1.0,1.0);
  glm::vec3 rot = glm::vec3(0.0,0.0,0.0);
  TransformData t1(pos,rot,scale);
  this->NextPlant = 1+(this->NextPlant)%6;
  std::string h = "hello";
  TerrainDemo::Rules r1;
  r1["F"] = "F";
  TerrainDemo::LSystem  sys(h,r1, 0.0, 0.0, 0.0);
  if(NextPlant == 1){

    sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_1);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


  }
  else if(NextPlant == 2){

    sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_2);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


  }
  else if(NextPlant == 3){

    sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_3);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());



  }
  else if(NextPlant == 4){

     sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_4);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


  }
  else if(NextPlant == 5){

    sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_5);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


  }
  else if(NextPlant == 6){

    TerrainDemo::LSystem  sys = TerrainDemo::LSystem::getLsystem(TerrainDemo::PlantTypes::TESTPLANT_6);
    std::shared_ptr<std::string> gen = sys.getLSysString(sys.level,false);
    TerrainDemo::Turtle tur(gen, glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 0.0), sys.amount, sys.angle);
    this->plant = new TerrainDemo::Plant(nullptr,t1,shad,&TerrainDemo::updatePlantnShader1, tur.getEdges());


  }





}
