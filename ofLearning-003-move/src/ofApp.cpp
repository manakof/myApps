#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int cols = 0; cols < 4; cols++) {
    ofPushMatrix();
    ofDrawCircle(30, 30, 30);
    ofDrawRectangle(5, 70, 50, 100);
    ofDrawCircle(95, 30, 30);
    ofDrawRectangle(70, 70, 50, 100);
    ofDrawCircle(45, 90, 15);
    ofDrawRectangle(30, 110, 30, 60);
    ofDrawCircle(80, 90, 15);
    ofDrawRectangle(65, 110, 30, 60);
    ofPopMatrix();

    ofTranslate(150, 0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
