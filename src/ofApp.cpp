#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(intSlider.setup("Hello", 0, 0, 300));
//    gui.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
//    gui.add(toggle.setup("toggle",true));
//    gui.add(button.setup("button"));
    gui.add(eye.set("eye", false));
    gui.add(pixel.set("pixel", false));
    gui.add(lips.set("lips", false));
    gui.add(flower.set("flower", true));
//    gui.add(friends.set("friends", false));
    
//    image.load("sunglasses.png");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    cam.setup(1024, 768);
  
    ofEnableAlphaBlending();

    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0);
    
    if( eye ){
        image.load("eye.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
            ofScale(scaleAmount, scaleAmount);
            image.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }

        
    }else{
        image.load("none.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
            ofScale(scaleAmount, scaleAmount);
            image.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }

    }
    
    if( pixel ){
        image2.load("sunglasses2.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image2.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image2.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
            ofScale(scaleAmount, scaleAmount);
            image2.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }

        
    }else{
        image2.load("none.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image2.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image2.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
            ofScale(scaleAmount, scaleAmount);
            image2.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }

    }
    
    if( flower ){
        image3.load("flower.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image2.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image3.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * -.40);
            ofScale(scaleAmount, scaleAmount);
            image3.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }
        
        
    }else{
        image3.load("none.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image3.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image3.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * -.40);
            ofScale(scaleAmount, scaleAmount);
            image3.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }
        
    }
    
    if( lips ){
        image4.load("lips.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image4.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image4.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .80);
            ofScale(scaleAmount, scaleAmount);
            image4.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }
        
        
    }else{
        image4.load("none.png");
        for(int i = 0; i < finder.size(); i++) {
            ofRectangle object = finder.getObjectSmoothed(i);
            image4.setAnchorPercent(.5, .5);
            float scaleAmount = .85 * object.width / image4.getWidth();
            ofPushMatrix();
            ofTranslate(object.x + object.width / 2., object.y + object.height * .80);
            ofScale(scaleAmount, scaleAmount);
            image4.draw(0, 0);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(object.getPosition());
            ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
            ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
            ofPopMatrix();
        }
        
    }

  
    
    gui.draw();
    
    }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
