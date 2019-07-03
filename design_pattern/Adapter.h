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

#include "PrintSequence.h"

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


class FibonacciGenerator {
    int n;
    int val[2];
public:
    FibonacciGenerator() : n(0) {
        val[0] = val[1] = 0;
    }
    int operator()() {
        int result = n > 2 ? val[0] + val[1] : n > 0 ? 1 : 0;
        ++n;
        val[0] = val[1];
        val[1] = result;
        return result;
    }
    int count() {
        return n;
    }
};

void test_FibonacciGenerator() {
    FibonacciGenerator f;
    for (int i = 0; i < 20; ++i) {
        cout << f.count() << ":" << f() << endl;
    }
}

class FibonacciAdapter {
    FibonacciGenerator f;
    int length;

public:
    explicit FibonacciAdapter(int size) : length(size) {
    }
    class iterator;
    friend class iterator;
    class iterator : public std::iterator<std::input_iterator_tag, FibonacciAdapter, ptrdiff_t> {
        FibonacciAdapter &ap;
    public:
        typedef int value_type;
        explicit iterator(FibonacciAdapter &a) : ap(a) {
        }
        bool operator==(iterator const&) const {
            return ap.f.count() == ap.length;
        }
        bool operator!=(iterator const& x) const {
            return !(*this == x);
        }
        int operator*() const {
            return ap.f();
        }
        iterator& operator++() {
            return *this;
        }
        iterator operator++(int) {
            return *this;
        }
    };
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator(*this);
    }
};

void test_FibonacciAdapter() {
    const int SZ = 20;
    FibonacciAdapter a1(SZ);
    cout << "accumulate: " << accumulate(a1.begin(), a1.end(), 0) << endl;

    FibonacciAdapter a2(SZ), a3(SZ);
    //_SCL_SECURE_NO_WARNINGS
    cout << "inner_product: " << inner_product(a2.begin(), a2.end(), a3.begin(), 0) << endl;

    FibonacciAdapter a4(SZ);
    int r1[SZ] = { 0 };
    int* end = partial_sum(a4.begin(), a4.end(), r1);
    print(r1, end, "partial_sum", " ");

    FibonacciAdapter a5(SZ);
    int r2[SZ] = { 0 };
    end = adjacent_difference(a5.begin(), a5.end(), r2);
    print(r2, end, "adjacent_difference", " ");
}

}//namespace adapter

#endif  //ADAPTER_H

