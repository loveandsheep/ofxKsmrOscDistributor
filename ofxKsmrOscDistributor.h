//
//	ofxKsmrOscDistributor.h
//  ofxKsmrOscDistributor
//
//  Created by Ovis aries on 2015/02/17.
//

#ifndef __ofxKsmrOscDistributor__
#define __ofxKsmrOscDistributor__

#include "ofMain.h"
#include "ofxOsc.h"

#define KSMR_OSC_TIP_MSG_STACK 128

class ofxKsmrOscTip;

class ofxKsmrOscDistributor{
public:
	ofxKsmrOscDistributor() {};
	~ofxKsmrOscDistributor() {};

	void setup(int receivePort);
	void update();

	void addReceiverTag(ofPtr<ofxKsmrOscTip> ptr);

	int currentPort;
private:

	vector<ofPtr<ofxKsmrOscTip> > receiverList;
	ofxOscReceiver receiver;

};

class ofxKsmrOscTip{
public:

	ofxKsmrOscTip(const string& addr_){
		addr.push_back(addr_);
	}
	ofxKsmrOscTip(){
	}

	void addAddress(const string& addr_){
		addr.push_back(addr_);
	}

	void addMessage(const ofxOscMessage& m){
		msg.push(m);

		while (msg.size() > KSMR_OSC_TIP_MSG_STACK){
			msg.pop();
		}
	}

	void getNextMessage(ofxOscMessage* m){
		m->copy(msg.front());
		msg.pop();
	}

	bool hasWaitingMessages() const {return (msg.size() > 0);};

	queue<ofxOscMessage> msg;
	vector<string> addr;

};

#endif /* defined(__ofxKsmrOscDistributor__) */
