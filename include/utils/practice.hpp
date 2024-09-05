#pragma once

extern bool record_init;
extern bool recording;
extern bool playback;
extern bool play_loop;
extern int maxFrames;
extern int currentFrame;
//extern Controller::InputBuffer inputBuf;

namespace Practice {
    void input_record_draw();
    void input_record_init();
    void input_record();
    void input_play();
    void input_main();
}