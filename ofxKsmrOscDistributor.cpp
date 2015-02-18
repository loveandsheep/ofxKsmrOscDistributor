//
//	ofxKsmrOscDistributor.cpp
//  ofxKsmrOscDistributor
//
//  Created by Ovis aries on 2015/02/17.
//

#include "ofxKsmrOscDistributor.h"

void ofxKsmrOscDistributor::setup(int receivePort){

	receiver.setup(receivePort);
	currentPort = receivePort;

}

void ofxKsmrOscDistributor::update(){

	while (receiver.hasWaitingMessages()){
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		cout << "Dst catch :" << m.getAddress() << endl;
		for (int i = 0;i < receiverList.size();i++){

			for (int j = 0;j < receiverList[i]->addr.size();j++){
				string ad = receiverList[i]->addr[j];
                
				if (strncmp(m.getAddress().c_str(), ad.c_str(), ad.length()) == 0){
					receiverList[i]->addMessage(m);
					cout << "add " << m.getAddress() << endl;
				}

			}

		}

	}
}

void ofxKsmrOscDistributor::addReceiverTag(ofPtr<ofxKsmrOscTip> ptr){
    
    receiverList.push_back(ptr);
    
}