#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
straightSegmentPolyline.addVertex(100,100);
straightSegmentPolyline.addVertex(150,150);
straightSegmentPolyline.addVertex(200,100);
straightSegmentPolyline.addVertex(250,150);
straightSegmentPolyline.addVertex(300,100);
straightSegmentPolyline.addVertex(150,150);



curvedSegmentPolyline.curveTo(350,100);
curvedSegmentPolyline.curveTo(350,100);
curvedSegmentPolyline.curveTo(400,150);
curvedSegmentPolyline.curveTo(450,100);
curvedSegmentPolyline.curveTo(500,150);
curvedSegmentPolyline.curveTo(550,100);
curvedSegmentPolyline.curveTo(550,100);


closedShapePolyline.addVertex(600,125);
closedShapePolyline.addVertex(700,100);
closedShapePolyline.addVertex(800,125);
closedShapePolyline.addVertex(700,125);
closedShapePolyline.close();

minDistance = 50;
leftMouseButtonPressed = false;

b.curveTo(100,100);
b.curveTo(300,100);
b.curveTo(700,700);
b.curveTo(900,100);

isSavingPDF = false;

}
//--------------------------------------------------------------
void ofApp::update(){
	if(leftMouseButtonPressed) {
		ofPoint mousePos(ofGetMouseX(),ofGetMouseY());	
		if(lastPoint.distance(mousePos)>=minDistance){
			currentPolyline.curveTo(mousePos);
			lastPoint = mousePos;
		}	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetLineWidth(2.0);
	ofSetColor(255,100,0);
	straightSegmentPolyline.draw();
	curvedSegmentPolyline.draw();
	closedShapePolyline.draw();

	ofSetColor(255);
	for(int i=0;i<polylines.size();i++){
		ofPolyline polyline = polylines[i];
		polyline.draw();

	vector <glm::vec3> vertices = polyline.getVertices();

//	for(int vertexIndex=0;vertexIndex<vertices.size();vertexIndex++){
//		glm::vec3 vertex = vertices[vertexIndex];
//		ofDrawCircle(vertex,5);		
//	}
/*
	for(int p=0;p<100;p+=10){
		ofVec3f point = polyline.getPointAtPercent(p/100.0);
		ofDrawCircle(point,5);
	}
	
        float normalLength = 50;
	for(int vertexIndex=0; vertexIndex<vertices.size();vertexIndex++){
		glm::vec3 vertex = vertices[vertexIndex];
		glm::vec3 normal = polyline.getNormalAtIndex(vertexIndex)* normalLength;
		ofDrawLine(vertex-normal/2,vertex+normal/2);

	}       
*/

if(isSavingPDF){
	ofBeginSaveScreenAsPDF("savedScreenshot_"+ofGetTimestampString()+".pdf");
}
	float normalLength = 50;
	for(int p=0;p<500;p+=1){
		ofVec3f point = polyline.getPointAtPercent(p/500.0);
		float floatIndex = polyline.getIndexAtPercent(p/500.0);
		ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex)*normalLength;
		ofSetColor(255,100);
		ofDrawLine(point-normal/2,point+normal/2);
	}
	}
	ofSetColor(255,100,0);
	currentPolyline.draw();

if(isSavingPDF){
	ofEndSaveScreenAsPDF();
	isSavingPDF = false;
}







b.draw();




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
if(key=='s'){
	isSavingPDF = true;
}
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
	if(button == OF_MOUSE_BUTTON_LEFT){
		leftMouseButtonPressed = true;
		currentPolyline.curveTo(x,y);
		currentPolyline.curveTo(x,y);
		lastPoint.set(x,y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(button == OF_MOUSE_BUTTON_LEFT){
		leftMouseButtonPressed = false;
		currentPolyline.curveTo(x,y);
		currentPolyline.simplify(0.75);
		polylines.push_back(currentPolyline);
		currentPolyline.clear();
	}
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
