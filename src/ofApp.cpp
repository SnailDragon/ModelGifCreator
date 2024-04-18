#include "ofApp.h"
#include "ofxAssimpModelLoader.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(30);

	string filePath = "C:\\Users\\tyler\\Desktop\\ASCENDSpring2024PayloadMockUp.obj";
	do {
		/*std::cout << "Enter file path: " << endl;
		std::cin >> filePath;*/
	}
	while (!this->model.load(filePath, ofxAssimpModelLoader::OPTIMIZE_DEFAULT));

	model.setRotation(0, -90, 1, 0, 0);
	model.setRotation(1, 180 - 45, 0, 0, 1);
	this->sceneDepth = (model.getSceneMaxModelSpace() - model.getSceneMinModelSpace()).z;
	this->sceneHeight = (model.getSceneMaxModelSpace() - model.getSceneMinModelSpace()).y;
	this->sceneWidth = (model.getSceneMaxModelSpace() - model.getSceneMinModelSpace()).x;
	cout << this->sceneHeight << " " << ofGetHeight() << endl;
	this->modelScale = fabs((ofGetHeight() / 2.0) / sceneHeight);
	model.setScale(this->modelScale, this->modelScale, this->modelScale);
	
	glm::vec3 offset = (model.getSceneMaxModelSpace() + model.getSceneMinModelSpace()) / 2;
	cout << offset.x << ", " << offset.y << ", " << offset.z << endl;
	model.setPosition(-offset.x, -offset.y, -offset.z);
	
	//model.setPosition(this->sceneWidth / 2.0, this->sceneHeight / 2.0, this->sceneDepth / 2.0);

	ofLogNotice() << "setup done" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// set model orientation
	
	//model.setScale(1, -1, 1);
	//model.setRotation(0, 180, 0, 1, 0); 

	//model.setPosition(0, -sceneHeight * 0.5, 0); model.getPosition() + 
	light.setPosition(glm::vec3(-300, -500, 1200) * 3);
	otherlight.setPosition(glm::vec3(300, 500, -1200) * 3);
	model.update();

	// rotate camera 
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	ofSetColor(255);

	ofEnableDepthTest();
	//ofDrawSphere(0, 0, 0, 50);
	//ofDrawSphere(light.getPosition().x, light.getPosition().y, light.getPosition().z, 50);
	//ofDrawSphere(otherlight.getPosition().x, otherlight.getPosition().y, otherlight.getPosition().z, 50);

	ofEnableLighting(); 
	light.enable();
	otherlight.enable();
	ofEnableSeparateSpecularLight(); 

	ofPushMatrix();
	model.drawFaces();
	ofPopMatrix();

	light.disable();
	otherlight.disable();
	ofDisableLighting();
	ofDisableSeparateSpecularLight();

	cam.end();
	ofDisableDepthTest();
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
