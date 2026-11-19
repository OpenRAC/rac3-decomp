/* functional: high. Ported from the NTSC-U draft and re-read against the PAL assembly: PAL uses 100-frame fade (0x64), the PAL globals and callees, gp-relative flag at gp+0xD8C (D_001DD63C), and the id table at D_001E1410. Menu/mini-game screen update: on the first frame of the screen it sets up the camera, clears the id table and collects up to 5 active players; then handles the start button and the two sub-state helpers. */
/* localdecomp:start func_L03_0034AC40 */
typedef struct { u8 pad[0xC]; s32 camera; s32 ids[4]; } Vars_34AC40;
typedef struct { u8 pad[0x68]; Vars_34AC40 *vars; } Object_34AC40;
typedef struct { u8 pad[0x558]; u8 active; u8 rest[0x5C0-0x559]; } Player_34AC40;
typedef struct Moby_34AC40 { u8 pad[0x28]; struct Moby_34AC40 *next; u8 pad2[0xAA-0x2C]; s16 cls; u8 pad3[0xBC-0xAC]; u8 state; } Moby_34AC40;
typedef struct { u8 pad[0x1A4]; s32 buttons; } Pad_34AC40;
extern s32 func_L01_004561B8(void *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *), func_L01_003EB350(s32, void *);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_00392DF0(s32, s32);
extern s32 func_L03_0034AE68(void *, s32);
extern void func_L03_0034AED8(void *, void *);
extern u8 D_001E24C0[];
extern u8 *D_001DFA80;
typedef struct { u8 flag; u8 pad[15]; } Flag_34AC40;
extern Flag_34AC40 D_001427BB;
extern s32 D_001DD63C;
extern s32 D_001E1410[];
extern Player_34AC40 D_001CD0C0[];
extern Pad_34AC40 *D_001D52FC;
extern Moby_34AC40 *D_001DF9A8;
extern u8 *D_001DF99C;

void func_L03_0034AC40(Object_34AC40 *obj) {
    s32 count = 0;
    Vars_34AC40 *vars = obj->vars;
    if (func_L01_004561B8(obj)) {
        s32 i;
        func_L01_005003D0(0x74, 1);
        func_L01_003EB438(0, D_001E24C0, D_001E24C0 + 0x10, 1, 0x64, 0);
        func_L01_003EB3C0(0, D_001DFA80 + vars->camera * 0x80 + 0x70);
        func_L01_003EB350(0, D_001DFA80 + vars->camera * 0x80 + 0x30);
        D_001427BB.flag = 0;
        func_0039EC28(0, 3);
        D_001DD63C = 0;
        for (i = 3; i >= 0; i--) D_001E1410[i] = -1;
        for (i = 0; i < 8 && count < 5; i++) {
            if (D_001CD0C0[i].active) D_001E1410[count++] = i;
        }
        func_L01_00452560(0, 5, 0xE79, 1, 0, 0, 0);
    }
    if (D_001D52FC->buttons & 0x800) func_00392DF0(3, 1);
    if (func_L03_0034AE68(obj, 1) < 2) {
        Moby_34AC40 *m = D_001DF9A8;
        D_001DD63C = 1;
        while (m) {
            if (m->cls == 0x1B9B) m->state = 1;
            m = m->next;
        }
    }
    if (func_L03_0034AE68(obj, 0) < 2) {
        s32 i;
        for (i = 0; i < 4; i++) func_L03_0034AED8(obj, D_001DF99C + vars->ids[i] * 0x100);
        D_001DD63C = 0;
    }
}
/* localdecomp:end func_L03_0034AC40 */
