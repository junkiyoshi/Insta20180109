#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(128);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	float noise_value;
	ofColor color;
	
	for (int y = ofGetHeight() * 0.1; y < ofGetHeight() * 0.9; y += 15) {
		color.setHsb(y % 255, 255, 255);
		ofSetColor(color);
		for (int x = ofGetWidth() * 0.1; x < ofGetWidth() * 0.9 - 1; x += 1) {
			noise_value = ofMap(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.003), 0, 1, -50, 50);
			ofDrawLine(x, y + noise_value, x + 1, y + noise_value);
		}
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}