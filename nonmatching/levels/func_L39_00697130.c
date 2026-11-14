/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_00694A20, the NTSC-U twin of func_L39_00697130, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/39_multiplayer_menu/L39_00695FC0.c's current line.
 * Worker's note: 513 diff; best func_L39_00694A20.check-01.log; FLAGS BLOCKER: permitted default assembler emits lit4 lwc1 for retail inline lui/ori/mtc1 floats (Matching-Patterns.md:139); no flags_alt; no forbidden flags tried; switch evidence func_L39_00694A20.switch.txt
 */
#include "common.h"

/* localdecomp:start func_L39_00694A20 */
typedef struct Widget_00694A20 Widget_00694A20;
typedef struct {
    u8 p0[0x1C];
    void (*set)(Widget_00694A20 *, s32, s32);
    u8 p20[0x10];
    void (*position)(Widget_00694A20 *, f32 *, f32 *);
    u8 p34[0x58];
    s32 (*index)(Widget_00694A20 *);
    u8 p90[8];
    char *(*text)(Widget_00694A20 *);
    void (*bounds)(Widget_00694A20 *, f32 *, f32 *);
    u8 pA0[0x18];
    void (*label)(Widget_00694A20 *, char *);
} VT_00694A20;
struct Widget_00694A20 { u8 p0[4]; s32 type; u8 p8[0x58]; VT_00694A20 *vt; };
typedef struct {
    u8 p0[0x110];
    Widget_00694A20 *widgets[18];
    u8 p158[0x290 - 0x158];
    s32 selected;
    u8 p294[0x2A8 - 0x294];
    u8 b2A8;
    u8 p2A9[7];
    s32 count;
    s32 ids[12];
    u8 p2E4[0x3BC - 0x2E4];
    s32 values[12];
    u8 p3EC[0x4C0 - 0x3EC];
    s32 target;
} Self_00694A20;
typedef struct { u8 p0[0x30]; s32 *p30; void *p34; void *p38; u8 p3C[12]; void *p48; void *p4C; void *p50; void *p54; } Service_00694A20;
typedef struct { u8 p0[0xD0]; void *pD0; u8 pD4[12]; void *pE0; void *pE4; u8 pE8[0x284-0xE8]; s32 state; s32 next; } UI_00694A20;
typedef struct { u8 p0[0x34]; s32 local_id; u8 p38[0x48]; u8 b80; } Network_00694A20;
extern Service_00694A20 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern Service_00694A20 *D_001E1FD0_sda;
extern UI_00694A20 *D_L39_00247A74;
__asm__(".extern D_L39_00247A74, 16");
extern UI_00694A20 *D_001DC1E4_sda;
extern char D_001A5ED0[];
extern Network_00694A20 D_001A5E50;
extern char D_L39_00248190[];
extern char D_L39_00248198[];
extern void func_L39_00695700(void *, s32);
extern void func_L39_00695470(void *);
extern void func_L39_006959C8(void *);
extern s32 func_L39_00695418(void *);
extern void func_L39_00687900(void *, s32, s32, f32, f32, f32, f32, u32);
extern s32 func_L39_006952A0(void *, s32);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_00685798(s32, s32, s32);
extern void func_L39_006B2920(void *, s32, s32);
extern s32 func_L39_006D97B0(void *, s32, s32 *);
extern void func_L39_006BA8F0(void *, s32);
extern char *func_001206F4(char *, char *);
extern char *func_0037DF98(s32);
extern void func_L39_00684930(void *, char *, char *, s32, s32, s32, s32);
extern s32 func_L39_006DAAA8(void *, char *, s32);
extern void func_L39_006D0730(void *, char *);
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_L39_00695C88(void *);
extern s32 func_L39_006D0790(void *, s32 *, s32 *);
extern void func_L39_006D7310(void *, s32, char *, s32);
extern void func_L39_006D0768(void *, s32, s32);
extern void func_L39_00688750(void *, s32, s32);
extern s32 func_L39_006D96D0(void *, s32, s32, s32 *);
extern s32 func_L39_00684D80(void *, char *, char *, s32);
extern s32 func_L39_006847C8(void *, char *, char *, s32, f32, s32);
extern void func_L39_006CC918(void *);
extern void func_L39_006CC290(void *, s32);
extern s32 func_L39_00684CE0(void *, char *, s32 *, s32, s32);
extern void func_L39_006CCAB0(void *, s32, s32);
extern void func_L39_006CDAA0(void *, s32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_00694A20(Self_00694A20 *s, s32 event) {
    char rename[16];
    char formatted[16];
    char message[128];
    char message2[256];
    s32 result_id, id1, id2, id3, id4, id5;
    f32 x1, y1, x2, y2;
    s32 *data = D_L39_0024D860->p38;
    s32 n;
    s32 answer;
    s32 i, index, arrows, first, last;
    Widget_00694A20 *w;
    func_L39_00695700(s, event);
    func_L39_00695470(s);
    func_L39_006959C8(s);
    if (func_L39_00695418(s)) return 1;
    n = s->count;
    if (n > 12) n = 12;
    if (n <= 0) n = 1;
    func_L39_00687900(s, 0, n, 0.274f, 0.245f, 0.048f, 0.32500002f, 0x331465B7);
    if (func_L39_006952A0(s, event)) return 1;
    if (func_L39_00688350(s, event)) return 1;
    if (event == 7) {
        func_L39_00685798(4, 0, 0);
        switch (s->selected) {
        case 1:
            if (s->target >= 0) {
                func_L39_006B2920(D_001DC1E4_sda->pD0, s->target, 1);
                D_L39_00247A74->state = 27;
            }
            return 1;
        case 9:
            if (data[0] != -1 && func_L39_006D97B0(D_001E1FD0_sda->p4C, data[0], &result_id)) {
                func_L39_006BA8F0(D_001DC1E4_sda->pE4, result_id);
                D_L39_00247A74->state = 32;
            }
            return 1;
        case 15:
            func_001206F4(rename, D_001A5ED0);
            func_L39_00684930(D_L39_00247A74, func_0037DF98(0x168F), rename, 0, 5, 0, 0);
            answer = 1;
            if (rename[0]) answer = func_L39_006DAAA8(D_L39_0024D860->p54, rename, 0);
            if (answer) {
                func_L39_006D0730(data, rename);
                func_00120D28(D_001A5ED0, rename, 5);
                D_001A5ED0[5] = 0;
                func_00120048(formatted, D_L39_00248190, rename);
                s->widgets[7]->vt->label(s->widgets[7], formatted);
                return 1;
            }
            return 1;
        case 10:
            D_L39_00247A74->state = 10;
            return 1;
        case 11:
            D_L39_00247A74->state = 7;
            return 1;
        case 12:
            func_L39_00695C88(s);
            return 1;
        case 13:
            id1 = -1;
            id2 = -1;
            if (func_L39_006D0790(data, &id1, &id2)) {
                func_00120048(message, D_L39_00248198, 0x4D, func_0037DF98(0x1733));
                func_L39_006D7310(D_L39_0024D860->p48, id2, message, 0);
            }
            func_L39_006D0768(data, -1, -1);
            s->widgets[12]->vt->set(s->widgets[12], 3, 0);
            s->widgets[13]->vt->set(s->widgets[13], 0, 0);
            s->widgets[14]->vt->set(s->widgets[14], 2, 0);
            s->widgets[8]->vt->label(s->widgets[8], func_0037DF98(0x1328));
            func_L39_00688750(s, 12, 0);
            return 1;
        case 14:
            if (func_L39_006D0790(data, &id3, &id4) && func_L39_006D96D0(D_001E1FD0_sda->p4C, id3, data[0], &id5)) {
                func_L39_006BA8F0(D_001DC1E4_sda->pE0, id5);
                D_L39_00247A74->state = 31;
            }
            return 1;
        case 16:
            answer = 0;
            if (s->count >= 2) {
                answer = func_L39_00684D80(D_L39_00247A74, func_0037DF98(0xFD2), func_0037DF98(0x1706), 0);
            }
            if (answer == 0) {
                if (func_L39_006847C8(D_L39_00247A74, func_0037DF98(0x1037), func_0037DF98(0x1031), 3, 0.6f, 0) == 1) {
                    func_00120048(message2, D_L39_00248198, 0x4D, func_0037DF98(0x1732));
                    for (i = 0; i < s->count; i++) {
                        if (s->ids[i] != D_001A5E50.local_id) {
                            func_L39_006D7310(D_001E1FD0_sda->p48, s->ids[i], message2, 1);
                        }
                    }
                    func_L39_006D0768(data, -1, -1);
                    func_L39_006CC918(data);
                    func_L39_006CC290(data, 0);
                    D_L39_00247A74->next = 8;
                }
            } else if (answer == 1) {
                index = func_L39_00684CE0(D_L39_00247A74, func_0037DF98(0x1707), s->values, s->count, 0);
                if (index >= 0) {
                    func_L39_006D0768(data, -1, -1);
                    func_L39_006CCAB0(data, s->ids[index], s->values[index]);
                    func_L39_006CC290(data, 0);
                    D_L39_00247A74->next = 6;
                }
            }
            D_001A5E50.b80 = 0;
            return 1;
        }
    }
    if (event == 8 && s->selected == 1 && s->target >= 0 && s->target != D_001E1FD0_sda->p30[0]) {
        func_00120048(rename, func_0037DF98(0x1038), s->widgets[1]->vt->text(s->widgets[1]));
        if (func_L39_006847C8(D_L39_00247A74, rename, func_0037DF98(0x1031), 3, 0.6f, 0) == 1) {
            func_L39_006CDAA0(D_L39_0024D860->p38, s->target);
            s->b2A8 = 1;
        }
        return 1;
    }
    if (s->selected == 1) {
        s->widgets[1]->vt->bounds(s->widgets[1], &x1, &y1);
        w = s->widgets[s->selected];
        index = w->vt->index(w);
        arrows = index > 0 ? 1 : 0;
        if (index < s->count - 1) arrows |= 2;
        func_L39_00687358(s, arrows, 3, 3, 0.274f, y1 - 0.001f, 0.32500002f, 0.032f, 0.04f, 1.0f);
        return 0;
    }
    w = s->widgets[s->selected];
    w->vt->position(w, &x2, &y2);
    first = -1;
    last = -1;
    for (i = 9; i < 17; i++) {
        s32 kind = s->widgets[i]->type;
        if (kind == 3 || kind == 4 || kind == 5) {
            last = i;
            if (first == -1) first = i;
        }
    }
    arrows = s->selected != first;
    if (s->selected != last) arrows |= 2;
    func_L39_00687358(s, arrows, 3, 3, x2, y2 + 0.0005f, 0.405f, 0.032f, 0.041f, 1.0f);
    return 0;
}
/* localdecomp:end func_L39_00694A20 */
