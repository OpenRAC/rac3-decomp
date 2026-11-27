#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_006B32A8);

/* localdecomp:start func_L39_006B32B0 */
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

void func_L39_006B32B0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, v, v, v, v, v, 0.5f, 0.3f, 1.0f, 1.0f, 0.0f);
}
/* localdecomp:end func_L39_006B32B0 */

LINKER_REMNANT("asm/levels", func_L39_006B3300);

/* localdecomp:start func_L39_006B3308 */
typedef struct H_006B3308 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006B3308;
typedef struct P_006B3308 {
    H_006B3308 h;
    u8 b48;
    s32 f4C;
} P_006B3308;
typedef struct T_006B3308 {
    H_006B3308 h;
    char text[0x50];
    u8 pad98[0x8];
} T_006B3308;
typedef struct S_006B3308 {
    H_006B3308 h;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} S_006B3308;
typedef struct M_006B3308 {
    H_006B3308 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_006B3308;

extern char D_L39_00248FC8[];
extern char D_L39_00248FD0[];
extern u8 D_L39_0047E438[];
extern void *func_L39_00688388(void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_00120D28(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689670(void *, void *);
__asm__(".extern D_001DD854_sda, 4");
extern f32 D_001DD854_sda;
__asm__(".extern D_001DD858_sda, 4");
extern f32 D_001DD858_sda;
__asm__(".extern D_001DD85C_sda, 4");
extern f32 D_001DD85C_sda;
__asm__(".extern D_001DD860_sda, 4");
extern f32 D_001DD860_sda;
__asm__(".extern D_001DD864_sda, 4");
extern f32 D_001DD864_sda;
__asm__(".extern D_001DD868_sda, 4");
extern f32 D_001DD868_sda;
__asm__(".extern D_001DD86C_sda, 4");
extern f32 D_001DD86C_sda;
__asm__(".extern D_001DD870_sda, 4");
extern f32 D_001DD870_sda;
__asm__(".extern D_001DD874_sda, 4");
extern f32 D_001DD874_sda;
__asm__(".extern D_001DD878_sda, 4");
extern f32 D_001DD878_sda;
__asm__(".extern D_001DD87C_sda, 4");
extern f32 D_001DD87C_sda;
__asm__(".extern D_001DD880_sda, 4");
extern f32 D_001DD880_sda;
__asm__(".extern D_001DD884_sda, 4");
extern f32 D_001DD884_sda;
__asm__(".extern D_001DD888_sda, 4");
extern f32 D_001DD888_sda;
__asm__(".extern D_001DD88C_sda, 4");
extern f32 D_001DD88C_sda;
__asm__(".extern D_001DD890_sda, 4");
extern f32 D_001DD890_sda;
__asm__(".extern D_001DD894_sda, 4");
extern f32 D_001DD894_sda;
__asm__(".extern D_001DD898_sda, 4");
extern f32 D_001DD898_sda;
__asm__(".extern D_001DD89C_sda, 4");
extern f32 D_001DD89C_sda;
__asm__(".extern D_001DD8A0_sda, 4");
extern f32 D_001DD8A0_sda;
__asm__(".extern D_001DD8A4_sda, 4");
extern f32 D_001DD8A4_sda;

static __inline__ void *item_006B3308(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_006B3308 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

static __inline__ void plain_006B3308(P_006B3308 *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    item_006B3308(it, name, x, y, w, h);
    it->h.type = 1;
}

static __inline__ void text_006B3308(T_006B3308 *it, s32 name, f32 x, f32 y, f32 w, f32 h, char *src) {
    item_006B3308(it, name, x, y, w, h);
    it->h.type = 7;
    if (src != 0) {
        func_00120D28((s32)it->text, (s32)src, 0x4F);
        it->text[0x4F] = 0;
    } else {
        it->text[0] = 0;
    }
}

void *func_L39_006B3308(void *arg0) {
    P_006B3308 it0;
    T_006B3308 it1;
    P_006B3308 it2, it3, it4, it5, it6, it7, it8, it9, it10;
    T_006B3308 it11, it12, it13, it14, it15, it16, it17, it18, it19, it20, it21;
    S_006B3308 it22, it23, it24, it25;
    M_006B3308 menu;
    S_006B3308 *p22, *p23, *p24, *p25;
    M_006B3308 *pm;
    s32 r;

    func_L39_00688388(arg0);
    *(void **)((u8 *)arg0 + 0x2A4) = (u8 *)arg0 + 0x2F4;
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E438;
    r = func_L39_005B43C8(0x39, 0x40);

    item_006B3308(&it0, (s32)D_L39_00248FC8, D_001DD854_sda, D_001DD858_sda, D_001DD85C_sda - D_001DD8A4_sda, D_001DD860_sda - D_001DD8A4_sda);
    it0.h.type = 4;
    it0.f4C = r;
    it0.b48 = 0;

    text_006B3308(&it1, (s32)D_L39_00248FD0, D_001DD864_sda, D_001DD868_sda, D_001DD86C_sda, D_001DD870_sda, D_L39_00248FD0);

    plain_006B3308(&it2, func_00381FF0(0x15D7), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * -2.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it3, func_00381FF0(0xF8D), D_001DD894_sda, D_001DD898_sda + -(D_001DD8A0_sda - D_001DD8A4_sda) / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it4, func_00381FF0(0x15CD), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * 0.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it5, func_00381FF0(0xF8F), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * 0.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it6, func_00381FF0(0xF90), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it7, func_00381FF0(0xF91), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it8, func_00381FF0(0xF92), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * 2.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it9, func_00381FF0(0xF93), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * 2.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);
    plain_006B3308(&it10, func_00381FF0(0xF94), D_001DD894_sda, D_001DD898_sda + (D_001DD8A0_sda - D_001DD8A4_sda) * 2.0f / 5.0f, D_001DD89C_sda - D_001DD8A4_sda, 0.05f);

    text_006B3308(&it11, func_00381FF0(0xF8A), D_001DD874_sda - D_001DD87C_sda * 0.5f + D_001DD8A4_sda, D_001DD878_sda + -(D_001DD880_sda - D_001DD8A4_sda) / 3.0f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it12, func_00381FF0(0x10FC), D_001DD874_sda - D_001DD87C_sda * 0.5f + D_001DD8A4_sda, D_001DD878_sda + (D_001DD880_sda - D_001DD8A4_sda) * 0.0f / 3.0f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it13, func_00381FF0(0xF67), D_001DD874_sda - D_001DD87C_sda * 0.5f + D_001DD8A4_sda, D_001DD878_sda + (D_001DD880_sda - D_001DD8A4_sda) / 3.0f, 0.2f, 0.05f, D_L39_00248FD0);

    text_006B3308(&it14, func_00381FF0(0x1101), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -3.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it15, func_00381FF0(0x160B), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -2.5f * 0.125f, 0.2f, 0.15f, D_L39_00248FD0);
    text_006B3308(&it16, func_00381FF0(0x12A4), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -1.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it17, func_00381FF0(0x1334), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -0.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it18, func_00381FF0(0x1335), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * 0.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it19, func_00381FF0(0x1336), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * 1.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it20, func_00381FF0(0x1337), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * 2.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);
    text_006B3308(&it21, func_00381FF0(0x133E), D_001DD884_sda - D_001DD88C_sda * 0.5f + D_001DD8A4_sda, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * 3.5f * 0.125f, 0.2f, 0.05f, D_L39_00248FD0);

    p22 = &it22;
    item_006B3308(p22, (s32)D_L39_00248FD0, D_001DD884_sda + (D_001DD88C_sda * 0.5f - D_001DD8A4_sda - 0.015f) - 0.0f, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -2.5f * 0.125f, 0.03f, 0.04f);
    it22.h.type = 12;
    p22->f58 = 0xED26;
    it22.f48 = 0.0f;
    it22.f50 = 0.0f;
    p22->f4C = 1.0f;
    p22->f54 = 1.0f;
    p22->f5C = 0x706EC8FF;
    p23 = &it23;
    item_006B3308(p23, (s32)D_L39_00248FD0, D_001DD884_sda + (D_001DD88C_sda * 0.5f - D_001DD8A4_sda - 0.015f) - 0.04f, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -2.5f * 0.125f, 0.03f, 0.04f);
    it23.h.type = 12;
    p23->f58 = 0xED26;
    it23.f48 = 0.0f;
    it23.f50 = 0.0f;
    p23->f4C = 1.0f;
    p23->f54 = 1.0f;
    p23->f5C = 0x706EC8FF;
    p24 = &it24;
    item_006B3308(p24, (s32)D_L39_00248FD0, D_001DD884_sda + (D_001DD88C_sda * 0.5f - D_001DD8A4_sda - 0.015f) - 0.08f, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -2.5f * 0.125f, 0.03f, 0.04f);
    it24.h.type = 12;
    p24->f58 = 0xED26;
    it24.f48 = 0.0f;
    it24.f50 = 0.0f;
    p24->f4C = 1.0f;
    p24->f54 = 1.0f;
    p24->f5C = 0x706EC8FF;
    p25 = &it25;
    item_006B3308(p25, (s32)D_L39_00248FD0, D_001DD884_sda + (D_001DD88C_sda * 0.5f - D_001DD8A4_sda - 0.015f) - 0.12f, D_001DD888_sda + (D_001DD890_sda - D_001DD8A4_sda) * -2.5f * 0.125f, 0.03f, 0.04f);
    it25.h.type = 12;
    p25->f58 = 0xED26;
    it25.f48 = 0.0f;
    it25.f50 = 0.0f;
    p25->f4C = 1.0f;
    p25->f54 = 1.0f;
    p25->f5C = 0x706EC8FF;

    pm = &menu;
    item_006B3308(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.f4C = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.f4C = 26;
    menu.items[0] = &it0;
    menu.items[1] = &it1;
    menu.items[2] = &it2;
    menu.items[3] = &it3;
    menu.items[4] = &it4;
    menu.items[5] = &it5;
    menu.items[6] = &it6;
    menu.items[7] = &it7;
    menu.items[8] = &it8;
    menu.items[9] = &it9;
    menu.items[10] = &it10;
    menu.items[11] = &it11;
    menu.items[12] = &it12;
    menu.items[18] = &it16;
    menu.items[17] = &it21;
    menu.items[19] = &it14;
    menu.items[20] = &it13;
    menu.items[13] = &it17;
    menu.items[14] = &it18;
    menu.items[15] = &it19;
    menu.items[16] = &it20;
    menu.items[21] = &it15;
    menu.items[22] = p22;
    menu.items[23] = p23;
    menu.items[24] = p24;
    menu.items[25] = p25;
    func_L39_00689670(arg0, pm);
    return arg0;
}
/* localdecomp:end func_L39_006B3308 */

LINKER_REMNANT("asm/levels", func_L39_006B41E0);
