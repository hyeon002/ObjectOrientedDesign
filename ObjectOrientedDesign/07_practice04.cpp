#include <iostream> 

// MediaPlayer Ŭ���� 
class MediaPlayer {
public:
	virtual void play(std::string audioType, std::string fileName) = 0;
};

// AdvanceMediaPlayer Ŭ���� 
class AdvancedMediaPlayer {
public:
	virtual void playVlc(std::string fileName) = 0;
	virtual void playMp4(std::string fileName) = 0;
};

// VIcPlayer Ŭ���� ( AdvanceMediaPlayer �ڽ� ) 
class VlcPlayer : public AdvancedMediaPlayer {
public:
	void playVlc(std::string fileName) {
		std::cout << "Playing vlc file. Name : " + fileName << std::endl;
	}

	void playMp4(std::string fileName) {
		//do nothing 
	}
};

// Mp4Player Ŭ���� ( AdvanceMediaPlayer �ڽ� )
class Mp4Player : public AdvancedMediaPlayer {
public:
	void playVlc(std::string fileName) {
		//do nothing 
	}

	void playMp4(std::string fileName) {
		std::cout << "Playing mp4 file. Name : " + fileName << std::endl;
	}
};

// MediaAdapter Ŭ���� ( MediaPlayer �ڽ� ) 
class MediaAdapter : public MediaPlayer {
	
public:
	AdvancedMediaPlayer* advancedMusicPlayer = NULL;

	MediaAdapter(std::string audioType) {
		if (!audioType.compare("vlc")) {
			advancedMusicPlayer = new VlcPlayer();
		}
		else if (!audioType.compare("mp4")) {
			advancedMusicPlayer = new Mp4Player();
		}
	}

	void play(std::string audioType, std::string fileName) {
		if (!audioType.compare("vlc")) {
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (!audioType.compare("mp4")) {
			advancedMusicPlayer->playMp4(fileName);
		}
	}
};

// AudioPlayer Ŭ���� ( MediaPlayer �ڽ� ) 
class AudioPlayer : public MediaPlayer {
public:

	MediaAdapter* mediaAdapter;

	void play(std::string audioType, std::string fileName) {
		if (!audioType.compare("mp3")) {
			std::cout << "Playing mp3 file. Name : " + fileName << std::endl;
		}
		else if (!audioType.compare("vlc") || !audioType.compare("mp4")) {
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, fileName);
		}
		else
			std::cout << "Invalid media. : " + audioType + " format not supported" << std::endl; 
	}
};

int main() {
	AudioPlayer* audiaPlayer = new AudioPlayer();

	audiaPlayer->play("mp3", "beyond the horizon.mp3");
	audiaPlayer->play("mp4", "alone.mp4");
	audiaPlayer->play("vlc", "far far away.vlc");
	audiaPlayer->play("avi", "mind me.avi");

	return 0;
}