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
	double maxScale = max(this->sceneDepth, max(this->sceneHeight, this->sceneWidth));

	if (maxScale == this->sceneDepth) {
		this->modelScale = fabs((ofGetWidth() / 1.5) / this->sceneDepth);
	}
	else if (maxScale == this->sceneWidth) {
		this->modelScale = fabs((ofGetWidth() / 1.5) / this->sceneWidth);
	}
	else {
		this->modelScale = fabs((ofGetHeight() / 1.5) / this->sceneHeight);
	}

	model.setScale(this->modelScale, this->modelScale, this->modelScale);
	
	glm::vec3 offset = (model.getSceneMaxModelSpace() + model.getSceneMinModelSpace()) / 2;
	cout << offset.x << ", " << offset.y << ", " << offset.z << endl;
	model.setPosition(-offset.x, -offset.y, -offset.z);

	rot = 0; 
	camera.setGlobalPosition(glm::vec3(800 * sin(rot), 300, 800 * cos(rot)));
	camera.setOrientation(glm::vec3(0, rot, 0));
	this->zoom = 1;
	ofLogNotice() << "setup done" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	otherlight.setPosition(glm::vec3(300, 500, -1200) * 3);

	// camera 
	camera.setGlobalPosition(glm::vec3(800 * sin(rot), 300, 800 * cos(rot)) * this->zoom);
	camera.setOrientation(glm::vec3(-22.5, rot * (180 / 3.1415), 0));

	light.setPosition(glm::vec3(800 * sin(rot), 300, 800 * cos(rot)) * 3);


	rot += 0.01;

	model.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.begin();
	camera.begin();

	ofSetColor(255);

	ofEnableDepthTest();

	ofEnableLighting(); 
	light.enable();
	//otherlight.enable();
	ofEnableSeparateSpecularLight(); 

	ofPushMatrix();
	model.drawFaces();
	ofPopMatrix();

	light.disable();
	//otherlight.disable();
	ofDisableLighting();
	ofDisableSeparateSpecularLight();

	camera.end();
	//cout << cam.getPosition().x << ", " << cam.getPosition().y << ", " << cam.getPosition().z << endl;
	//cam.end();
	ofDisableDepthTest();
}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {
	this->zoom += scrollY / 10.0;
	this->zoom = max(this->zoom, 0.1);
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

