#include "common.h"

/* NTSC-U counterpart of func_L01_0041AB50 (src/levels/shared/L01_0041A910.c) */
typedef struct {
    s32 state;        
    s32 timer;        
    s32 half_width;   
    s32 half_height;  
    s32 x10;          
    s32 top;          
    s32 open_frames;  
    s32 close_frames; 
    s32 index;        
    s32 request;      
    s32 slot;         
    u8 pad2C[4];
    s32 ready;        
    s32 wait;         
    s16 hold;         
    s16 opened;       
    u8 cue[0xC];      
    s32 shown;        
} Help_0041A9A0;
typedef struct {
    char *text;
    s32 id;
    s32 voice;
    s16 next;
    u8 padE[2];
} HelpRow_0041A9A0;
extern Help_0041A9A0 D_L01_002E5F70;
extern HelpRow_0041A9A0 *D_L01_001DFD40_00418478;
extern s32 D_00143950[];

/* localdecomp:start func_L01_00418478 */
extern void func_L01_004182C8(void);
extern void func_L01_00419640(u16 id);

typedef struct {
    u16 count;        /* times shown */
    u8 p2[2];
    u32 time;         /* when last closed */
    u32 flags;        /* 0x80000000 | a bit per D_001D545C */
} Seen_0041AB50;
typedef struct {
    u8 p0[0x24];
    s32 w24;
    u8 p28[0x44];
    s32 w6C;
    s16 voice0;       /* 0x70: 7000 + the line playing */
    u8 p72[4];
    s16 state0;       /* 0x76 */
    u8 p78[0x1C];
    s32 w94;
    s16 voice1;       /* 0x98 */
    u8 p9A[4];
    s16 state1;       /* 0x9E: 3 once it has played */
} Snd_0041AB50;
typedef struct {
    u8 p0[4];
    union {
        u8 b;
        u16 h;
    } help;           /* 0x04: help voice on */
    u8 p6[0x1A];
} Settings_0041AB50;
typedef struct {
    u8 p0[0x1A0];
    u32 held;
    u32 pressed;      /* 0x1A4: 0x10 Triangle */
} Pad_0041AB50;
extern Seen_0041AB50 D_001A7E18[];
extern Snd_0041AB50 D_001CCFD0;
extern Pad_0041AB50 *D_001D52FC;
extern s32 D_001D545C;
extern s32 D_001D4C38;
extern s32 D_L01_001D6694_00418478;
typedef struct {
    u8 pad0[0x2648];
    s32 loaded[1];    /* 0x2648: per voice, non-zero once its line is loaded */
} Voices_0041AB50;
extern Voices_0041AB50 D_00160C40;
extern s32 func_0037DF28(s32);
extern s32 func_00388398(void *);
extern void func_0039DAE0(s32, s32);
extern void func_0039C710(void);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);

/* help_update: runs the help message: shown for its length x 7 frames after opening over 8,
   then closed over 8; Triangle skips to its closing. Voiced ones wait for their line. */
void func_L01_00418478(void)
{
    s32 voice;

    if (D_L01_002E5F70.ready == 0) {
        if (D_001D545C >= 0) {
            D_L01_002E5F70.ready = 1;
            D_L01_002E5F70.wait = 120;
        } else {
            if (D_L01_002E5F70.wait == 0 && (D_001D52FC->held & 0xF000)) {
                D_L01_002E5F70.wait = 1;
            }
            if (D_L01_002E5F70.wait != 0) {
                if (++D_L01_002E5F70.wait >= 120) {
                    D_L01_002E5F70.ready = 1;
                }
            }
        }
    }
    if ((D_L01_001D6694_00418478 != 0 && D_L01_001D6694_00418478 != 7) || D_L01_002E5F70.ready == 0) {
        D_L01_002E5F70.request = -1;
        D_L01_002E5F70.state = 0;
        D_L01_002E5F70.timer = 0;
        return;
    }
    D_L01_002E5F70.timer++;
    if (((Settings_0041AB50 *)D_00143950)->help.b == 0) {
        /* voice off: stop its line */
        if (D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice == D_001CCFD0.voice1 - 7000
            || D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice == D_001CCFD0.voice0 - 7000) {
            if ((u16)D_001CCFD0.state0 != 6 && (u16)D_001CCFD0.state0 != 7) {
                D_001CCFD0.state0 = 5;
            }
            if ((u16)D_001CCFD0.state1 != 6 && (u16)D_001CCFD0.state1 != 7) {
                D_001CCFD0.state1 = 5;
            }
        }
    }
    switch (D_L01_002E5F70.state) {
    case 8:
        if (D_L01_002E5F70.hold != 0) {
            break;
        }
        if (D_L01_002E5F70.index >= 0) {
            if (D_L01_002E5F70.opened == 0) {
                if (func_00388398(D_L01_002E5F70.cue) == 0) {
                    break;
                }
                func_L01_004182C8();
                D_L01_002E5F70.opened++;
                break;
            }
            if (D_001A7E18[D_L01_002E5F70.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F70.slot].count++;
            }
        }
        {
            s32 t = D_001D4C38;
            if (D_001A7E18[D_L01_002E5F70.slot].time < t) {
                D_001A7E18[D_L01_002E5F70.slot].time = t;
            }
        }
        D_001A7E18[D_L01_002E5F70.slot].flags = D_001A7E18[D_L01_002E5F70.slot].flags | (1 << D_001D545C) | 0x80000000;
        D_L01_002E5F70.index = -1;
        D_L01_002E5F70.state = 0;
        D_L01_002E5F70.opened = 0;
        break;
    case 0:
        /* a text was asked for: open it (or its follow-up once it has been seen) */
        if (D_L01_002E5F70.request < 0) {
            break;
        }
        D_L01_002E5F70.index = func_0037DF28(D_L01_002E5F70.request);
        if (D_L01_001DFD40_00418478[D_L01_002E5F70.index].next >= 0 && D_001A7E18[D_L01_002E5F70.slot].count != 0) {
            D_L01_002E5F70.index = func_0037DF28(D_L01_001DFD40_00418478[D_L01_002E5F70.index].next);
        }
        /* func_L01_00419640 takes a u16; retail passes the word unconverted */
        ((void (*)(s32))func_L01_00419640)(D_L01_002E5F70.request);
        D_L01_002E5F70.request = -1;
        if (D_L01_002E5F70.index >= 0) {
            func_L01_004182C8();
        }
        break;
    case 1:
    case 2:
        /* opening: start its line */
        if (((Settings_0041AB50 *)D_00143950)->help.b != 0) {
            s32 v = D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice;
            if (v != -1 && D_00160C40.loaded[v] != 0 && D_001CCFD0.w6C == 0 && D_001CCFD0.w24 == -1
                && D_001CCFD0.w94 == 0) {
                func_0039DAE0(v + 7000, 0);
            }
        }
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F70.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F70.slot].count++;
            }
            {
                s32 t = D_001D4C38;
                if (D_001A7E18[D_L01_002E5F70.slot].time < t) {
                    D_001A7E18[D_L01_002E5F70.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F70.slot].flags = D_001A7E18[D_L01_002E5F70.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F70.state = 7;
            D_L01_002E5F70.timer = 0;
        } else if (D_L01_002E5F70.timer > 0) {
            if ((D_001CCFD0.state1 == 3 && D_001CCFD0.voice1 >= 7000)
                || (voice = D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice) == -1 || D_00160C40.loaded[voice] == 0
                || (voice != D_001CCFD0.voice1 - 7000 && voice != D_001CCFD0.voice0 - 7000)) {
                D_L01_002E5F70.state = 3;
                D_L01_002E5F70.timer = 0;
            }
        }
        break;
    case 3:
        func_L01_0044F2E8(0, 16, 0, 1, 0, 0, 0);
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F70.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F70.slot].count++;
            }
            {
                s32 t = D_001D4C38;
                if (D_001A7E18[D_L01_002E5F70.slot].time < t) {
                    D_001A7E18[D_L01_002E5F70.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F70.slot].flags = D_001A7E18[D_L01_002E5F70.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F70.state = 7;
            D_L01_002E5F70.timer = 0;
        } else if (D_L01_002E5F70.timer >= 8) {
            D_L01_002E5F70.timer = 0;
            D_L01_002E5F70.state = 4;
        }
        break;
    case 4:
        func_L01_0044F2E8(0, 16, 0, 1, 0, 0, 0);
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F70.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F70.slot].count++;
            }
            {
                s32 t = D_001D4C38;
                if (D_001A7E18[D_L01_002E5F70.slot].time < t) {
                    D_001A7E18[D_L01_002E5F70.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F70.slot].flags = D_001A7E18[D_L01_002E5F70.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F70.state = 6;
            D_L01_002E5F70.timer = 4 - D_L01_002E5F70.timer;
        } else if (D_L01_002E5F70.timer >= 4) {
            voice = D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice;
            if (voice == -1) {
                goto no_wait;
            }
            if (D_00160C40.loaded[voice] == 0 || voice == D_001CCFD0.voice1 - 7000 || voice == D_001CCFD0.voice0 - 7000
                || ((Settings_0041AB50 *)D_00143950)->help.b == 0) {
                /* its line is still playing */
                if (D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice != -1
                    && D_00160C40.loaded[D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice] != 0
                    && !(D_001CCFD0.state1 == 3 && D_001CCFD0.voice1 >= 7000)
                    && ((Settings_0041AB50 *)D_00143950)->help.b != 0) {
                    break;
                }
            no_wait:
                if (((Settings_0041AB50 *)D_00143950)->help.b != 0) {
                    voice = D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice;
                    if (voice == D_001CCFD0.voice1 - 7000 || voice == D_001CCFD0.voice0 - 7000) {
                        func_0039C710();
                    }
                }
                D_L01_002E5F70.state = 5;
                D_L01_002E5F70.timer = 0;
            } else {
                D_L01_002E5F70.timer = 0;
                D_L01_002E5F70.state = 5;
            }
        }
        break;
    case 5:
        /* shown: close after its time (or its line), or on Triangle */
        func_L01_0044F2E8(0, 16, 0, 1, 0, 0, 0);
        if ((D_L01_002E5F70.timer >= D_L01_002E5F70.shown
             && !(D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice != -1
                  && D_00160C40.loaded[D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice] != 0
                  && ((Settings_0041AB50 *)D_00143950)->help.b != 0))
            || (((Settings_0041AB50 *)D_00143950)->help.b != 0
                && (voice = D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice) != -1 && D_00160C40.loaded[voice] != 0
                && voice != D_001CCFD0.voice1 - 7000 && voice != D_001CCFD0.voice0 - 7000)
            || (D_001D52FC->pressed & 0x10)) {
            if (D_001A7E18[D_L01_002E5F70.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F70.slot].count++;
            }
            {
                s32 t = D_001D4C38;
                if (D_001A7E18[D_L01_002E5F70.slot].time < t) {
                    D_001A7E18[D_L01_002E5F70.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F70.slot].flags = D_001A7E18[D_L01_002E5F70.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F70.state = 6;
            D_L01_002E5F70.timer = 0;
        }
        break;
    case 6:
        if (((Settings_0041AB50 *)D_00143950)->help.h == 0 || D_L01_002E5F70.timer >= 4
            || (D_001D52FC->pressed & 0x10)) {
            D_L01_002E5F70.state = 7;
            D_L01_002E5F70.timer = 0;
        }
        break;
    case 7:
        /* closing: stop its line */
        func_L01_0044F2E8(0, 16, 0, 1, 0, 0, 0);
        if (D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice == D_001CCFD0.voice1 - 7000
            || D_L01_001DFD40_00418478[D_L01_002E5F70.index].voice == D_001CCFD0.voice0 - 7000) {
            if ((u16)D_001CCFD0.state0 != 6 && (u16)D_001CCFD0.state0 != 7) {
                D_001CCFD0.state0 = 5;
            }
            if ((u16)D_001CCFD0.state1 != 6 && (u16)D_001CCFD0.state1 != 7) {
                D_001CCFD0.state1 = 5;
            }
        }
        if (D_L01_002E5F70.timer >= 8) {
            if (D_L01_002E5F70.hold != 0) {
                D_L01_002E5F70.state = 8;
            } else {
                D_L01_002E5F70.state = 0;
                D_L01_002E5F70.index = -1;
            }
            D_L01_002E5F70.timer = 0;
        }
        break;
    }
}
/* localdecomp:end func_L01_00418478 */
