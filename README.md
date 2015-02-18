# ofxKsmrOscDistributor
split OSC messages for multiple receiver(ofxKsmrOscTip) classes.

## Usage
setup distributor in your class like manager.

	ofxKsmrOscDistributor oscDst;
	Foo foo;
		
	void ofApp::setup(){
	
		//set receive port number
		oscDst.setup(12400);
		
		foo.setup(oscDst);
	}
	
and

	
	class Foo{
	public:
		ofPtr<ofxKsmrOscTip> receiver;
		
		void setup(ofxKsmrOscDistributor &dst){
			
			//create ofxKsmrOscTip instance
			receiver = ofPtr<ofxKsmrOscTip>(new ofxKsmrOscTip);
			
			//add Addresses which you want to receive
			receiver->addAddress("/ksmr/myAddress");
			
			//register to ofxKsmrOscDistributor
			dst.addReceiverTag(receiver);
			
		}
		
		void update(){
			
			while (receiver->hasWaitingMessage()){
				ofxOscMessage m;
				receiver->getNextMessage(&m);
				
				/*=== write like ofxOscReceiver ===*/
				
			}			
		
		}
		
	}
