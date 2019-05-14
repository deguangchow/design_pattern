///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Adapter
///
///    \author   deguangchow
///    \version  1.0
///    \2019/05/14

#pragma once
#ifndef ADAPTER_H
#define ADAPTER_H

namespace adapter {

class  MediaPlayer {
public:
    virtual void play(string const& audioType, string const& fileName) = 0;
};

class AdvancedMediaPlayer {
public:
    virtual void playVlc(string const& fileName) const = 0;
    virtual void playMp4(string const& fileName) const = 0;
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    virtual void playVlc(string const& fileName) const {
        cout << "Playing vlc file. Name: " << fileName << endl;
    }
    virtual void playMp4(string const& fileName) const {
        //do nothing
    }
};

class Mp4Player : public AdvancedMediaPlayer {
    virtual void playVlc(string const& fileName) const {
        //do nothing
    }
    virtual void playMp4(string const& fileName) const {
        cout << "Playing mp4 file. Name: " << fileName << endl;
    }
};

class MediaAdapter : public MediaPlayer {
    AdvancedMediaPlayer* m_pAdvanceMediaPlayer;
public:
    explicit MediaAdapter(string const& audioType) {
        if (audioType == "vlc") {
            m_pAdvanceMediaPlayer = new VlcPlayer();
        } else if (audioType == "mp4") {
            m_pAdvanceMediaPlayer = new Mp4Player();
        }
    }
    ~MediaAdapter() {
        if (m_pAdvanceMediaPlayer) {
            delete m_pAdvanceMediaPlayer;
            m_pAdvanceMediaPlayer = nullptr;
        }
    }
    virtual void play(string const& audioType, string const& fileName) {
        if (audioType == "vlc") {
            m_pAdvanceMediaPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            m_pAdvanceMediaPlayer->playMp4(fileName);
        }
    }
};

class AudioPlayer : public MediaPlayer {
    std::unique_ptr<MediaAdapter> m_pMediaAdapter;
public:
    ~AudioPlayer() {
    }
    virtual void play(string const& audioType, string const& fileName) {
        if (audioType == "mp3") {
            cout << "Playing mp3 file. Name: " << fileName << endl;
        } else if (audioType == "vlc" || audioType == "mp4") {
            m_pMediaAdapter = std::make_unique<MediaAdapter>(audioType);
            m_pMediaAdapter->play(audioType, fileName);
        } else {
            cout << "Invalid media. " << audioType << " format not supported" << endl;
        }
    }
};

void test_adapter() {
    AudioPlayer audioPlayer;
    audioPlayer.play("mp3", "beyond the horizon.mp3");
    audioPlayer.play("mp4", "alone.mp4");
    audioPlayer.play("vlc", "far for away.vlc");
    audioPlayer.play("avi", "mind me.avi");
}

}//namespace adapter

#endif  //ADAPTER_H

