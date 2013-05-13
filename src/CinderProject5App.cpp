#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/GlslProg.h"

#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProject5App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
   
   gl::GlslProg mShader;
};

void CinderProject5App::setup()
{
   try {
		mShader = gl::GlslProg( loadResource( RES_VERT ), loadResource( RES_FRAG ) );
	}
	catch( gl::GlslProgCompileExc &exc ) {
		std::cout << "Shader compile error: " << std::endl;
		std::cout << exc.what();
	}
	catch( ... ) {
		std::cout << "Unable to load shader" << std::endl;
	}
}

void CinderProject5App::mouseDown( MouseEvent event )
{
}

void CinderProject5App::update()
{
}

void CinderProject5App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
   //resolution time
   mShader.bind();
   mShader.uniform( "resolution", Vec2f( getWindowWidth(), getWindowHeight() ) );
   mShader.uniform( "time", float(getElapsedSeconds()) );
   mShader.uniform( "mouse", getMousePos() );
   
   gl::drawSolidRect( getWindowBounds() );
}

CINDER_APP_NATIVE( CinderProject5App, RendererGl )
