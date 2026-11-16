/* PAL near miss (Codex wave 7): near miss: 236 words differ with the file's flags.
 * Worker's note: 233 diff: build/codex/w343/func_L02_003A51F0.a4.log; reconstructed full state logic; remaining branch layout, mixed gp/lui reads, .lit4 loads for PAL 0x3D23D70B and 0x3D75C290 vs retail inline $at constants; fixed flags only
 */
#include "common.h"
/* localdecomp:start func_L02_003A51F0 */
typedef struct Data_003A51F0 { s32 trigger, destination, level, message, event, scene, other; } Data_003A51F0;
typedef struct Moby_003A51F0 {
    u8 pad0[0x20]; u8 state; u8 pad21[15]; u8 f30;
    u8 pad31[0x37]; Data_003A51F0 *data;
    u8 pad6C[0x2A]; u16 counter; u8 pad98[0x24]; u8 active;
} Moby_003A51F0;
typedef struct Hero_003A51F0 { u8 pad[0x1A4]; s32 state; } Hero_003A51F0;
extern s32 D_001D545C;
extern s32 D_001D545C_003A51F0;
__asm__(".extern D_001D545C, 16");
extern u8 *D_001D52FC;
extern u8 *D_001D52FC_003A51F0;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L02_002CF1B0[];
extern u8 D_001426F7[];
extern u8 D_001A4C60[];
extern f32 D_L02_001DE2D0;
extern f32 D_L02_001DE2D0_003A51F0;
__asm__(".extern D_L02_001DE2D0, 16");
extern u8 *D_L02_001DEA80[];
void func_L02_003A51F0(Moby_003A51F0 *m) {
    extern void func_L02_003C5DC0(s32);
    extern s32 func_00382380(void *, s32, s32);
    extern void func_L01_00452560(s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L01_003EC9E0(s32);
    extern void func_L01_00511A40(void *,f32,s32);
    extern void func_00392DF0(s32,s32);
    extern void func_003C4138(f32 *,f32,f32);
    extern void func_L01_0042B068(s32,s32);
    extern void func_L01_004F50C8(void *,void *,s32,s32);
    extern void func_L01_004A3610(void *,void *);
    extern void func_L01_00451F60(s32,s32,s32);
    extern s32 func_L01_003ECA10(s32);
    extern void func_L02_004D36C0(s32,s32);
    Data_003A51F0 *d = m->data;
    u8 *scene;
    void *pos, *rot;
    if (d->event != -1 && m->active == 0) {
        m->active = 1;
        func_L02_003C5DC0(d->event);
    }
    if (m->state == 0) {
        m->f30 = 0xFF;
        if (D_001D545C == 4) {
            if (func_00382380(D_001A4C60,d->trigger,0)) {
                func_L01_00452560(0,9,0xA48,1,0,0,0);
                if (*(s32 *)(D_001D52FC+0x1A4) == 16 && D_L02_002CF1B0[0] == 9)
                    func_L01_004450F0(m,1,-1);
            }
        } else if (D_001D545C == 8 || D_001D545C == 27 || D_001D545C == 28) {
            if (D_001D545C == 8 && d->level == 27 && D_001426F7[0] == 1) goto initial_done;
            if (!func_00382380(D_001A4C60,d->trigger,0)) goto initial_done;
            switch (d->message) {
            case 0: func_L01_00452560(0,9,0xC53,1,0,0,0); break;
            case 1: break;
            case 2: func_L01_00452560(0,9,0x850,1,0,0,0); break;
            case 3: func_L01_00452560(0,9,0xC54,1,0,0,0); break;
            default: func_L01_00452560(0,9,0x850,1,0,0,0); break;
            }
            if ((D_001D545C_003A51F0 == 27 && d->message == 1) ||
                (*(s32 *)(D_001D52FC_003A51F0+0x1A4) == 16 && D_L02_002CF1B0[0] == 9)) {
                if (d->destination == -1) {
                    if (D_001D545C == 28 && d->level == 8) D_001426F7[0] = 1;
                    if (d->level == 27) D_001426F7[0] = 1;
                    if (d->event != -1) {
                        func_L01_004450F0(m,3,-1);
                        func_L01_003EC9E0(d->event);
                    } else if (d->scene != -1) {
                        func_L01_004450F0(m,4,-1);
                        { u8 *intro = D_L02_001DEA80[0] + (d->scene << 7);
                        func_L01_00511A40(intro+0x30,*(f32 *)(intro+0x78),0); }
                    } else func_00392DF0(d->level,1);
                } else func_L01_004450F0(m,1,-1);
            }
        } else {
            if (func_00382380(D_001A4C60,d->trigger,0)) func_L01_004450F0(m,1,-1);
        }
    }
initial_done:;
    if (m->state == 1) {
        func_003C4138(&D_L02_001DE2D0,1.0f,0.04000000283122063f);
        if (D_L02_001DE2D0 == 1.0f) D_L02_001DE2D0 = 1.5f;
        if (D_L02_001DE2D0_003A51F0 >= 1.0f) {
            func_L01_0042B068(d->level,0);
            scene = D_L02_001DEA80[0] + (d->destination << 7);
            pos = scene+0x30;
            rot = scene+0x70;
            func_L01_004F50C8(pos,rot,0,1);
            func_L01_004A3610(pos,rot);
            if (D_001D545C == 2 && *(f32 *)(scene+0x38) < 50.0f)
                func_L01_00451F60(0xC7A,-1,0);
            func_L01_004450F0(m,2,-1);
        }
    }
    if (m->state == 2) {
        func_003C4138(&D_L02_001DE2D0,0.0f,0.04000000283122063f);
        if (D_L02_001DE2D0 <= 0.0f) {
            D_L02_001DE2D0 = 0.0f;
            func_L01_004450F0(m,0,-1);
        }
    }
    if (m->state == 3 && func_L01_003ECA10(d->event)) func_00392DF0(d->level,1);
    if (m->state == 4) {
        m->counter++;
        if (m->counter == 71) func_L02_004D36C0(0x69,1);
        if (m->counter >= 84) func_003C4138(&D_L02_001DE2D0,1.0f,0.06000000238418579f);
        if (m->counter == 108) func_00392DF0(d->level,1);
    }
}
/* localdecomp:end func_L02_003A51F0 */
