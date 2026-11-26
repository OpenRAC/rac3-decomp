#include "common.h"

/* localdecomp:start func_L01_0041A910 */
extern s32 func_00381FF0_0041A910(s32);
extern s32 func_00382030_0041A910();
void func_L01_0041A910(void) {
    func_00381FF0_0041A910(func_00382030_0041A910());
}
/* localdecomp:end func_L01_0041A910 */

/* localdecomp:start func_L01_0041A938 */
typedef struct {
    s32 w0;
    u8 pad4[0x34];
    s16 h38;
    u8 pad3A[2];
    s32 w3C;
} S_0041A938;
extern S_0041A938 D_L01_002E5F30_0041A938;
extern void func_L01_0041A528(void);
void func_L01_0041A938(void) {
    if (D_L01_002E5F30_0041A938.h38 == 0) {
        D_L01_002E5F30_0041A938.h38 = 1;
        D_L01_002E5F30_0041A938.w3C = 50;
        func_L01_0041A528();
        if (D_L01_002E5F30_0041A938.w0 == 0) {
            D_L01_002E5F30_0041A938.w0 = 8;
        }
    }
}
/* localdecomp:end func_L01_0041A938 */

/* localdecomp:start func_L01_0041A990 */
extern s16 D_L01_002E5F68[];

void func_L01_0041A990(void) {
    D_L01_002E5F68[0] = 0;
}
/* localdecomp:end func_L01_0041A990 */

/* localdecomp:start func_L01_0041A9A0 */
typedef struct {
    s32 state;        /* 0x00: 1 while open */
    s32 timer;        /* 0x04 */
    s32 half_width;   /* 0x08 */
    s32 half_height;  /* 0x0C */
    s32 x10;          /* 0x10 */
    s32 top;          /* 0x14 */
    s32 open_frames;  /* 0x18 */
    s32 close_frames; /* 0x1C */
    s32 index;        /* 0x20: row in the help table */
    s32 request;      /* 0x24: text asked for, or -1 */
    s32 slot;         /* 0x28: its D_001A7E18 record */
    u8 pad2C[4];
    s32 ready;        /* 0x30 */
    s32 wait;         /* 0x34 */
    s16 hold;         /* 0x38 */
    s16 opened;       /* 0x3A */
    u8 cue[0xC];      /* 0x3C */
    s32 shown;        /* 0x48: frames the text shows */
} Help_0041A9A0;
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA;
    u16 width;        /* 0x0C */
    u16 height;       /* 0x0E */
    s16 f10;
    u16 flags;        /* 0x12 */
    s16 f14, f16, f18, f1A;
} TextBox_0041A9A0;
typedef struct {
    char *text;
    s32 id;
    s32 voice;
    s16 next;
    u8 padE[2];
} HelpRow_0041A9A0;
extern Help_0041A9A0 D_L01_002E5F30;
extern HelpRow_0041A9A0 *D_L01_001DFCC0;
extern s32 D_00143950[];
extern s32 D_001D55C4;
extern s32 D_001D4BC4;
__asm__(".extern D_L01_001D67E0, 8");
extern s32 D_L01_001D67E0[2];
extern void func_003A5348(s32, s32, s32);
extern void func_003910C0(TextBox_0041A9A0 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038E150(s32);
extern long func_00389598(s32);
extern void func_003911F0(TextBox_0041A9A0 *, unsigned long, char *, s32, long, s32, unsigned long, f32);
extern s32 func_0011B868(char *);

/* help_open: opens a help message: its box 60 lines above the screen's bottom, drawn in
   (255, 204, 102). */
void func_L01_0041A9A0(void) {
    Help_0041A9A0 *help = &D_L01_002E5F30;
    TextBox_0041A9A0 box;
    char *text;
    s32 bottom;
    s32 depth;
    s32 top;
    s32 reach;
    u8 *settings = (u8 *)D_00143950; /* +0: language, +4: help sound on */

    help->state = 1;
    help->timer = 0;
    if (*(u16 *)(settings + 4) != 0) {
        /* the help sound */
        func_003A5348(0, 1, 0);
    }
    text = D_L01_001DFCC0[help->index].text;
    depth = 0x100;
    func_003910C0(&box, 0xF0, 0x1E0, 0x2C, 0x1D4, depth, 0x168, 0x10, 7);
    box.flags |= 0x20;
    box.f18 = 2;
    box.f1A = 2;
    func_0038E150(1);
    /* RGBA (255, 204, 102, 0x80) */
    func_003911F0(&box, 0x8066CCFF, text, -1, func_00389598(1), D_001D55C4, 0x80000000, 1.0f);
    help->half_width = ((s16)box.width >> 1) + 10;
    help->half_height = ((s16)box.height >> 1) + 5;
    help->x10 = depth;
    help->top = D_L01_001D67E0[D_00143950[0]]; /* per language */
    help->open_frames = 8;
    help->close_frames = 8;
    help->shown = 0;
    /* shown for 7 frames a character */
    if (text != 0) {
        help->shown = func_0011B868(text) * 7;
    }
    /* 60 lines above the screen's bottom, and at least 12 from it */
    bottom = D_001D4BC4;
    top = bottom - 60;
    help->top = top;
    if (top + help->half_height > bottom - 12) {
        reach = help->half_height + 12;
        help->top = bottom - reach;
    }
}
/* localdecomp:end func_L01_0041A9A0 */

/* localdecomp:start func_L01_0041AB50 */
extern void func_L01_0041A9A0(void);
extern void func_L01_0041BD48(u16 id);

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
extern s32 D_L01_001D6694;
extern s32 *func_L01_0041A678(void);
extern s32 func_00381F80(s32);
extern s32 func_0038CAD0(void *);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

/* help_update: runs the help message: shown for its length x 7 frames after opening over 8,
   then closed over 8; Triangle skips to its closing. Voiced ones wait for their line. */
void func_L01_0041AB50(void)
{
    s32 *loaded;
    s32 voice;

    if (D_L01_002E5F30.ready == 0) {
        if (D_001D545C >= 0) {
            D_L01_002E5F30.ready = 1;
            D_L01_002E5F30.wait = 100;
        } else {
            if (D_L01_002E5F30.wait == 0 && (D_001D52FC->held & 0xF000)) {
                D_L01_002E5F30.wait = 1;
            }
            if (D_L01_002E5F30.wait != 0) {
                if (++D_L01_002E5F30.wait >= 100) {
                    D_L01_002E5F30.ready = 1;
                }
            }
        }
    }
    if ((D_L01_001D6694 != 0 && D_L01_001D6694 != 7) || D_L01_002E5F30.ready == 0) {
        D_L01_002E5F30.request = -1;
        D_L01_002E5F30.state = 0;
        D_L01_002E5F30.timer = 0;
        return;
    }
    D_L01_002E5F30.timer++;
    loaded = func_L01_0041A678();
    if (((Settings_0041AB50 *)D_00143950)->help.b == 0) {
        /* voice off: stop its line */
        if (D_L01_001DFCC0[D_L01_002E5F30.index].voice == D_001CCFD0.voice1 - 7000
            || D_L01_001DFCC0[D_L01_002E5F30.index].voice == D_001CCFD0.voice0 - 7000) {
            if ((u16)D_001CCFD0.state0 != 6 && (u16)D_001CCFD0.state0 != 7) {
                D_001CCFD0.state0 = 5;
            }
            if ((u16)D_001CCFD0.state1 != 6 && (u16)D_001CCFD0.state1 != 7) {
                D_001CCFD0.state1 = 5;
            }
        }
    }
    switch (D_L01_002E5F30.state) {
    case 8:
        if (D_L01_002E5F30.hold != 0) {
            break;
        }
        if (D_L01_002E5F30.index >= 0) {
            if (D_L01_002E5F30.opened == 0) {
                if (func_0038CAD0(D_L01_002E5F30.cue) == 0) {
                    break;
                }
                func_L01_0041A9A0();
                D_L01_002E5F30.opened++;
                break;
            }
            if (D_001A7E18[D_L01_002E5F30.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F30.slot].count++;
            }
        }
        {
            s32 t = (D_001D4C38 * 5 + 2) / 6;
            if (D_001A7E18[D_L01_002E5F30.slot].time < t) {
                D_001A7E18[D_L01_002E5F30.slot].time = t;
            }
        }
        D_001A7E18[D_L01_002E5F30.slot].flags = D_001A7E18[D_L01_002E5F30.slot].flags | (1 << D_001D545C) | 0x80000000;
        D_L01_002E5F30.index = -1;
        D_L01_002E5F30.state = 0;
        D_L01_002E5F30.opened = 0;
        break;
    case 0:
        /* a text was asked for: open it (or its follow-up once it has been seen) */
        if (D_L01_002E5F30.request < 0) {
            break;
        }
        D_L01_002E5F30.index = func_00381F80(D_L01_002E5F30.request);
        if (D_L01_001DFCC0[D_L01_002E5F30.index].next >= 0 && D_001A7E18[D_L01_002E5F30.slot].count != 0) {
            D_L01_002E5F30.index = func_00381F80(D_L01_001DFCC0[D_L01_002E5F30.index].next);
        }
        /* func_L01_0041BD48 takes a u16; retail passes the word unconverted */
        ((void (*)(s32))func_L01_0041BD48)(D_L01_002E5F30.request);
        D_L01_002E5F30.request = -1;
        if (D_L01_002E5F30.index >= 0) {
            func_L01_0041A9A0();
        }
        break;
    case 1:
    case 2:
        /* opening: start its line */
        if (((Settings_0041AB50 *)D_00143950)->help.b != 0) {
            s32 v = D_L01_001DFCC0[D_L01_002E5F30.index].voice;
            if (v != -1 && loaded[v] != 0 && D_001CCFD0.w6C == 0 && D_001CCFD0.w24 == -1
                && D_001CCFD0.w94 == 0) {
                func_003A2B68(v + 7000, 0);
            }
        }
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F30.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F30.slot].count++;
            }
            {
                s32 t = (D_001D4C38 * 5 + 2) / 6;
                if (D_001A7E18[D_L01_002E5F30.slot].time < t) {
                    D_001A7E18[D_L01_002E5F30.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F30.slot].flags = D_001A7E18[D_L01_002E5F30.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F30.state = 7;
            D_L01_002E5F30.timer = 0;
        } else if (D_L01_002E5F30.timer > 0) {
            if ((D_001CCFD0.state1 == 3 && D_001CCFD0.voice1 >= 7000)
                || (voice = D_L01_001DFCC0[D_L01_002E5F30.index].voice) == -1 || loaded[voice] == 0
                || (voice != D_001CCFD0.voice1 - 7000 && voice != D_001CCFD0.voice0 - 7000)) {
                D_L01_002E5F30.state = 3;
                D_L01_002E5F30.timer = 0;
            }
        }
        break;
    case 3:
        func_L01_00452560(0, 16, 0, 1, 0, 0, 0);
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F30.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F30.slot].count++;
            }
            {
                s32 t = (D_001D4C38 * 5 + 2) / 6;
                if (D_001A7E18[D_L01_002E5F30.slot].time < t) {
                    D_001A7E18[D_L01_002E5F30.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F30.slot].flags = D_001A7E18[D_L01_002E5F30.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F30.state = 7;
            D_L01_002E5F30.timer = 0;
        } else if (D_L01_002E5F30.timer >= 8) {
            D_L01_002E5F30.timer = 0;
            D_L01_002E5F30.state = 4;
        }
        break;
    case 4:
        func_L01_00452560(0, 16, 0, 1, 0, 0, 0);
        if (D_001D52FC->pressed & 0x10) {
            if (D_001A7E18[D_L01_002E5F30.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F30.slot].count++;
            }
            {
                s32 t = (D_001D4C38 * 5 + 2) / 6;
                if (D_001A7E18[D_L01_002E5F30.slot].time < t) {
                    D_001A7E18[D_L01_002E5F30.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F30.slot].flags = D_001A7E18[D_L01_002E5F30.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F30.state = 6;
            D_L01_002E5F30.timer = 4 - D_L01_002E5F30.timer;
        } else if (D_L01_002E5F30.timer >= 4) {
            voice = D_L01_001DFCC0[D_L01_002E5F30.index].voice;
            if (voice == -1) {
                goto no_wait;
            }
            if (loaded[voice] == 0 || voice == D_001CCFD0.voice1 - 7000 || voice == D_001CCFD0.voice0 - 7000
                || ((Settings_0041AB50 *)D_00143950)->help.b == 0) {
                /* its line is still playing */
                if (D_L01_001DFCC0[D_L01_002E5F30.index].voice != -1
                    && loaded[D_L01_001DFCC0[D_L01_002E5F30.index].voice] != 0
                    && !(D_001CCFD0.state1 == 3 && D_001CCFD0.voice1 >= 7000)
                    && ((Settings_0041AB50 *)D_00143950)->help.b != 0) {
                    break;
                }
            no_wait:
                if (((Settings_0041AB50 *)D_00143950)->help.b != 0) {
                    voice = D_L01_001DFCC0[D_L01_002E5F30.index].voice;
                    if (voice == D_001CCFD0.voice1 - 7000 || voice == D_001CCFD0.voice0 - 7000) {
                        func_003A1798();
                    }
                }
                D_L01_002E5F30.state = 5;
                D_L01_002E5F30.timer = 0;
            } else {
                D_L01_002E5F30.timer = 0;
                D_L01_002E5F30.state = 5;
            }
        }
        break;
    case 5:
        /* shown: close after its time (or its line), or on Triangle */
        func_L01_00452560(0, 16, 0, 1, 0, 0, 0);
        if ((D_L01_002E5F30.timer >= (D_L01_002E5F30.shown * 5 + 2) / 6
             && !(D_L01_001DFCC0[D_L01_002E5F30.index].voice != -1
                  && loaded[D_L01_001DFCC0[D_L01_002E5F30.index].voice] != 0
                  && ((Settings_0041AB50 *)D_00143950)->help.b != 0))
            || (((Settings_0041AB50 *)D_00143950)->help.b != 0
                && (voice = D_L01_001DFCC0[D_L01_002E5F30.index].voice) != -1 && loaded[voice] != 0
                && voice != D_001CCFD0.voice1 - 7000 && voice != D_001CCFD0.voice0 - 7000)
            || (D_001D52FC->pressed & 0x10)) {
            if (D_001A7E18[D_L01_002E5F30.slot].count <= 0xFFFE) {
                D_001A7E18[D_L01_002E5F30.slot].count++;
            }
            {
                s32 t = (D_001D4C38 * 5 + 2) / 6;
                if (D_001A7E18[D_L01_002E5F30.slot].time < t) {
                    D_001A7E18[D_L01_002E5F30.slot].time = t;
                }
            }
            D_001A7E18[D_L01_002E5F30.slot].flags = D_001A7E18[D_L01_002E5F30.slot].flags | (1 << D_001D545C) | 0x80000000;
            D_L01_002E5F30.state = 6;
            D_L01_002E5F30.timer = 0;
        }
        break;
    case 6:
        if (((Settings_0041AB50 *)D_00143950)->help.h == 0 || D_L01_002E5F30.timer >= 4
            || (D_001D52FC->pressed & 0x10)) {
            D_L01_002E5F30.state = 7;
            D_L01_002E5F30.timer = 0;
        }
        break;
    case 7:
        /* closing: stop its line */
        func_L01_00452560(0, 16, 0, 1, 0, 0, 0);
        if (D_L01_001DFCC0[D_L01_002E5F30.index].voice == D_001CCFD0.voice1 - 7000
            || D_L01_001DFCC0[D_L01_002E5F30.index].voice == D_001CCFD0.voice0 - 7000) {
            if ((u16)D_001CCFD0.state0 != 6 && (u16)D_001CCFD0.state0 != 7) {
                D_001CCFD0.state0 = 5;
            }
            if ((u16)D_001CCFD0.state1 != 6 && (u16)D_001CCFD0.state1 != 7) {
                D_001CCFD0.state1 = 5;
            }
        }
        if (D_L01_002E5F30.timer >= 8) {
            if (D_L01_002E5F30.hold != 0) {
                D_L01_002E5F30.state = 8;
            } else {
                D_L01_002E5F30.state = 0;
                D_L01_002E5F30.index = -1;
            }
            D_L01_002E5F30.timer = 0;
        }
        break;
    }
}
/* localdecomp:end func_L01_0041AB50 */

/* localdecomp:start func_L01_0041B600 */
void func_L01_0041B600(void) {

}
/* localdecomp:end func_L01_0041B600 */

/* localdecomp:start func_L01_0041B608 */
typedef struct {
    u8 p0[4];
    u16 h4;
} SettingsH_0041B608;
typedef struct {
    u8 p0[5];
    u8 b5;
} SettingsB_0041B608;
typedef struct {
    s32 state;        /* 0x00 */
    s32 timer;        /* 0x04 */
    s32 half_width;   /* 0x08 */
    s32 half_height;  /* 0x0C */
    s32 x10;          /* 0x10 */
    s32 top;          /* 0x14 */
    s32 open_frames;  /* 0x18 */
    s32 close_frames; /* 0x1C */
    s32 index;        /* 0x20 */
    s32 request;      /* 0x24 */
    s32 slot;         /* 0x28 */
    u8 pad2C[4];
    s32 ready;        /* 0x30 */
    s32 wait;         /* 0x34 */
    s16 hold;         /* 0x38 */
    s16 opened;       /* 0x3A */
    s32 w3C;          /* 0x3C */
    s32 yoff;         /* 0x40 */
    s32 yoff_timer;   /* 0x44 */
    s32 shown;        /* 0x48 */
} Help_0041B608;
typedef struct {
    char *text;
    s32 id;
    s32 voice;
    s16 next;
    s16 icon;
} HelpRow_0041B608;

extern s32 D_L01_001D6520;
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_0038FA18(TextBox_0041A9A0 *, unsigned long, char *, s32, unsigned long, f32, f32);
extern void func_L01_0041B600(void);

void func_L01_0041B608(void) {
    TextBox_0041A9A0 box;

    ((Help_0041B608 *)&D_L01_002E5F30)->yoff_timer--;
    if (((Help_0041B608 *)&D_L01_002E5F30)->yoff_timer < 0) {
        ((Help_0041B608 *)&D_L01_002E5F30)->yoff_timer = 0;
    }
    if (((Help_0041B608 *)&D_L01_002E5F30)->yoff_timer == 0) {
        ((Help_0041B608 *)&D_L01_002E5F30)->yoff = 0;
    }
    if (D_L01_002E5F30.state == 0) {
        return;
    }
    if (D_L01_002E5F30.ready == 0) {
        return;
    }
    if (((SettingsH_0041B608 *)D_00143950)->h4 == 0) {
        return;
    }
    switch (D_L01_002E5F30.state) {
    case 1:
        if (((SettingsB_0041B608 *)D_00143950)->b5 != 0) {
            D_L01_002E5F30.open_frames = 8;
            D_L01_002E5F30.close_frames = 8;
            func_0038C3B0(D_L01_002E5F30.top - D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.top + D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.x10 - D_L01_002E5F30.open_frames,
                          D_L01_002E5F30.x10 + D_L01_002E5F30.open_frames, 0x60, 0x600E5092);
            func_L01_00436020(0x33, 0x332299DE,
                              (f32)(D_L01_002E5F30.top - D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.top + D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.x10 - D_L01_002E5F30.open_frames),
                              (f32)(D_L01_002E5F30.x10 + D_L01_002E5F30.open_frames));
        } else {
            func_L01_0041B600();
        }
        break;
    case 2:
        func_L01_0041B600();
        break;
    case 3:
        if (((SettingsB_0041B608 *)D_00143950)->b5 != 0) {
            s32 t = D_L01_002E5F30.timer;
            if (t > 8) {
                t = 8;
            }
            if (t < 0) {
                t = 0;
            }
            D_L01_002E5F30.open_frames = ((D_L01_002E5F30.half_width - 0x20) * t) / 8 + 0x20;
            D_L01_002E5F30.close_frames = ((D_L01_002E5F30.half_height - 0x20) * t) / 8 + 0x20;
            func_0038C3B0(D_L01_002E5F30.top - D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.top + D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.x10 - D_L01_002E5F30.open_frames,
                          D_L01_002E5F30.x10 + D_L01_002E5F30.open_frames, 0x60, 0x600E5092);
            func_L01_00436020(0x33, 0x332299DE,
                              (f32)(D_L01_002E5F30.top - D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.top + D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.x10 - D_L01_002E5F30.open_frames),
                              (f32)(D_L01_002E5F30.x10 + D_L01_002E5F30.open_frames));
        } else {
            func_L01_0041B600();
        }
        break;
    case 4:
    case 5:
    case 6:
        if (((SettingsB_0041B608 *)D_00143950)->b5 != 0) {
            s32 off = 0;
            s32 flag = 0;
            s32 icon_h = 0x3D;
            char *text;
            switch (((HelpRow_0041B608 *)D_L01_001DFCC0)[D_L01_002E5F30.index].icon) {
            case 0x1DC:
            case 0xB0E:
            case 0x150E:
            case 0x166A:
            case 0x1736:
                flag = 1;
                break;
            }
            if (flag != 0) {
                s32 border = 2;
                off = 0xA;
                if (D_L01_002E5F30.half_height + 0xA < border + 0x20) {
                    off = (border + 0x20) - D_L01_002E5F30.half_height;
                }
                D_L01_002E5F30.half_width = 0xD4;
            }
            D_L01_002E5F30.open_frames = D_L01_002E5F30.half_width;
            D_L01_002E5F30.close_frames = D_L01_002E5F30.half_height;
            func_0038C3B0(D_L01_002E5F30.top - D_L01_002E5F30.half_height + ((Help_0041B608 *)&D_L01_002E5F30)->yoff - off,
                          D_L01_002E5F30.top + D_L01_002E5F30.half_height + ((Help_0041B608 *)&D_L01_002E5F30)->yoff + off,
                          D_L01_002E5F30.x10 - D_L01_002E5F30.half_width,
                          D_L01_002E5F30.x10 + D_L01_002E5F30.half_width,
                          0x60, 0x600E5092);
            func_L01_00436020(0x33, 0x332299DE,
                              (f32)(D_L01_002E5F30.top - D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff - off),
                              (f32)(D_L01_002E5F30.top + D_L01_002E5F30.close_frames + ((Help_0041B608 *)&D_L01_002E5F30)->yoff + off),
                              (f32)(D_L01_002E5F30.x10 - D_L01_002E5F30.open_frames),
                              (f32)(D_L01_002E5F30.x10 + D_L01_002E5F30.open_frames));
            /* In multiplayer (func_L39_0059B428) the player count adjusts the text box
               coordinates for 2- and 4-player splitscreen; in single-player it is constant 1. */
            {
                s32 num_players = 1;
                s32 y0 = 0xF0;
                s32 y1 = 0x1E0;
                s32 x0 = 0x2C;
                s32 x1 = 0x1D4;
                s32 cx = 0x100;
                if (num_players == 2) {
                    y0 = 0;
                } else if (num_players == 4) {
                    y0 = 1;
                }
                text = D_L01_001DFCC0[D_L01_002E5F30.index].text;
                if (((HelpRow_0041B608 *)D_L01_001DFCC0)[D_L01_002E5F30.index].icon > 0) {
                    func_003910C0(&box, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + y0, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + y1,
                                  0x70, x1, 0x70, D_L01_002E5F30.top + ((Help_0041B608 *)&D_L01_002E5F30)->yoff, 0x10, 2);
                } else {
                    func_003910C0(&box, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + y0, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + y1,
                                  x0, x1, cx, D_L01_002E5F30.top + ((Help_0041B608 *)&D_L01_002E5F30)->yoff, 0x10, 3);
                }
            }
            box.f18 = 2;
            box.f1A = 2;
            box.flags |= 0x20;
            if (((HelpRow_0041B608 *)D_L01_001DFCC0)[D_L01_002E5F30.index].icon > 0) {
                switch (((HelpRow_0041B608 *)D_L01_001DFCC0)[D_L01_002E5F30.index].icon) {
                case 0x1DC:
                    func_0038B4D0(0x32, D_L01_002E5F30.top - (icon_h / 2) + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                                  0x38, icon_h, 0, 0, 0x40, 0x40, (long)(s32)0x80808080, func_00389598(0x5C));
                    break;
                case 0xB0E:
                    func_0038B4D0(0x32, D_L01_002E5F30.top - (icon_h / 2) + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                                  0x38, icon_h, 0, 0, 0x40, 0x40, (long)(s32)0x80808080, func_00389598(0x61));
                    break;
                case 0x150E:
                    func_0038B4D0(0x32, D_L01_002E5F30.top - (icon_h / 2) + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                                  0x38, icon_h, 0, 0, 0x40, 0x40, (long)(s32)0x80808080, func_00389598(0x5D));
                    break;
                case 0x166A:
                    func_0038B4D0(0x32, D_L01_002E5F30.top - (icon_h / 2) + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                                  0x38, icon_h, 0, 0, 0x40, 0x40, (long)(s32)0x80808080, func_00389598(0x62));
                    break;
                case 0x1736:
                    func_0038B4D0(0x32, D_L01_002E5F30.top - (icon_h / 2) + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                                  0x38, icon_h, 0, 0, 0x40, 0x40, (long)(s32)0x80808080, func_00389598(0x5E));
                    break;
                default:
                    func_003910C0(&box, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + 0xF0, ((Help_0041B608 *)&D_L01_002E5F30)->yoff + 0x1E0,
                                  0x2C, 0x1D4, 0x100, D_L01_002E5F30.top + ((Help_0041B608 *)&D_L01_002E5F30)->yoff, 0x10, 3);
                    box.f18 = 2;
                    box.f1A = 2;
                    box.flags |= 0x20;
                    break;
                }
            }
            if (D_L01_002E5F30.state == 4) {
                D_L01_001D6520 = 1;
            } else {
                D_L01_001D6520 = 2;
            }
            func_0038E150(1);
            func_0038FA18(&box, 0x8066CCFFUL, text, -1, 0x80000000UL, 1.0f, 1.0f);
        } else {
            func_L01_0041B600();
        }
        break;
    case 7:
        if (((SettingsB_0041B608 *)D_00143950)->b5 != 0) {
            s32 t = D_L01_002E5F30.timer;
            s32 c, w, h;
            if (t > 8) {
                t = 8;
            }
            if (t < 0) {
                t = 0;
            }
            c = (8 - t) * 12;
            w = D_L01_002E5F30.open_frames - ((D_L01_002E5F30.open_frames - 8) * t) / 8;
            h = D_L01_002E5F30.close_frames - ((D_L01_002E5F30.close_frames - 8) * t) / 8;
            func_0038C3B0(D_L01_002E5F30.top - h + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.top + h + ((Help_0041B608 *)&D_L01_002E5F30)->yoff,
                          D_L01_002E5F30.x10 - w, D_L01_002E5F30.x10 + w, c, 0x600E5092);
            func_L01_00436020(c, 0x332299DE,
                              (f32)(D_L01_002E5F30.top - h + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.top + h + ((Help_0041B608 *)&D_L01_002E5F30)->yoff),
                              (f32)(D_L01_002E5F30.x10 - w),
                              (f32)(D_L01_002E5F30.x10 + w));
        } else {
            func_L01_0041B600();
        }
        break;
    }
}
/* localdecomp:end func_L01_0041B608 */

LINKER_REMNANT("asm/levels", func_L01_0041BD40);

/* localdecomp:start func_L01_0041BD48 */
extern s32 D_001D5598;
extern u16 D_001A8EC8[];

void func_L01_0041BD48(u16 id) {
    s32 i;

    for (i = 0; D_001A8EC8[i] != id && i < D_001D5598; i++) {
    }
    if (i < D_001D5598) {
        for (; i < D_001D5598 - 1; i++) {
            D_001A8EC8[i] = D_001A8EC8[i + 1];
        }
        D_001A8EC8[i] = 0;
        D_001D5598--;
    }
    D_001A8EC8[D_001D5598++] = id;
}
/* localdecomp:end func_L01_0041BD48 */

LINKER_REMNANT("asm/levels", func_L01_0041BE18);

/* localdecomp:start func_L01_0041BE20 */
void func_L01_0041BE20(void) {

}
/* localdecomp:end func_L01_0041BE20 */

/* localdecomp:start func_L01_0041BE28 */
extern u8 D_L01_001DFCF2;
extern u8 D_L01_001DFCF3;
extern s16 D_L01_001DFCC8;
extern s16 D_L01_001DFCE0;
void func_L01_0041BE28(s32 id,s32 value)
{
 s32 i;
 if(D_L01_001DFCF2<9){
  for(i=D_L01_001DFCF2-1;i>=0;i--){
   if((&D_L01_001DFCC8)[(D_L01_001DFCF3+i)%9]==id)return;
  }
  (&D_L01_001DFCC8)[(D_L01_001DFCF3+D_L01_001DFCF2)%9]=id;
  (&D_L01_001DFCE0)[(D_L01_001DFCF3+D_L01_001DFCF2)%9]=value;
  D_L01_001DFCF2++;
 }
}
/* localdecomp:end func_L01_0041BE28 */

/* localdecomp:start func_L01_0041BF08 */
extern u8 D_L01_001DFCF2;
extern u8 D_L01_001DFCF3;
extern s16 D_L01_001DFCE0;
extern s16 D_L01_001DFCC8;
extern s32 func_L01_0041A5B0(s32 a0, s32 a1);
void func_L01_0041BF08(void) {
    if (D_L01_001DFCF2 != 0) {
        if (func_L01_0041A5B0((&D_L01_001DFCC8)[D_L01_001DFCF3], (&D_L01_001DFCE0)[D_L01_001DFCF3]) != 0) {
            D_L01_001DFCF2 = D_L01_001DFCF2 - 1;
            D_L01_001DFCF3 = (D_L01_001DFCF3 + 1) % 9;
        }
    }
}
/* localdecomp:end func_L01_0041BF08 */
