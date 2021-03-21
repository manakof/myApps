#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    exp.setup(1280, 720, 30);
    exp.setFrameRange(100, 200);
    exp.setOutputDir("out");
    
    exp.setOverwriteSequence(true);
    exp.setAutoExit(true);
    
    exp.startExport();
}
ofEasyCam cam;
//--------------------------------------------------------------
void ofApp::update(){
    exp.begin(cam);
    ofClear(0);
    
    ofDrawBitmapString(ofToString(exp.getFrameNum()), 10, 20);
    
    exp.end();}

//--------------------------------------------------------------
void ofApp::draw(){
exp.draw(0, 0); 
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
