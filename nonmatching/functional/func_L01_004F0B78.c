/* functional: medium. Vec4ED3B8* args as void* (type defined later in file); 267 diff words are scheduling/regalloc, instruction multiset equals retail except range-compare form for states 13/14 */
#include "vu0.h"
extern u8 D_001A4CD0[];
void func_L01_004F0B78(void) {
    extern void func_L01_00511B50(s32, void *, void *);
    extern f32 func_L01_00511408(void *);
    extern void func_L01_00511588(void *, void *, f32);
    extern f32 func_L01_005114B0(void *);
    extern void func_L01_00511508(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004F0AB0(void);
    extern void func_L01_004EF840(void);
    extern void func_L01_004F02D8(void);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_00511320(void *, void *);
    extern f32 func_L01_004F05F0(Q_004F05F0 *);
    vu0_v4 previous, temp, vertical;
    u8 *p = (u8 *)D_001A4C60;
    u8 *h = p - 0x80;
    s32 state;
    f32 magnitude, limit, dot;
    *(vu0_q *)&previous = *(vu0_q *)p;
    func_L01_00511B50(*(s32 *)(h + 0x538), p + 0x80, p + 0x10);
    state = *(s32 *)(h + 0x25C4);
    if (state == 20 || state == 95 || state == 92 || state == 162 || state == 134) {
        h = (u8 *)&D_001A4BE0;
        if (*(s16 *)(h + 0x1F0) == 0) {
            magnitude = func_L01_00511408(h + 0xF0);
            limit = *(f32 *)(h + 0x284) - 0.02f;
            if (limit < magnitude) func_L01_00511588(h + 0xF0, h + 0xF0, limit);
        }
        {
            u8 *velocity = D_001A4CD0;
            f32 component = func_L01_005114B0(velocity);
            if (component < 0.0f && component < -*(f32 *)(velocity + 0x24C)) {
                if (component < -*(f32 *)(velocity + 0x24C) - 0.1f)
                    component = -*(f32 *)(velocity + 0x24C) - 0.1f;
                if (component > 0.0f) component = 0.0f;
                func_L01_00511508(velocity, velocity, component);
            }
        }
        h = (u8 *)&D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 20) {
            magnitude = func_0038CEA8(h + 0xF0);
            limit = *(f32 *)(h + 0x284) - 0.02f;
            if (limit < magnitude) func_0038CE20((h + 0xF0), (h + 0xF0), limit / magnitude);
        }
    } else if (*(s32 *)(h + 0x25CC) == 15) {
        if (*(s16 *)(h + 0x1F0) == 0) {
            magnitude = func_0038CED8(h + 0xF0);
            limit = *(f32 *)(h + 0x284) - 0.02f;
            if (limit < magnitude) func_0038CFB8(h + 0xF0, h + 0xF0, limit);
        }
    } else if (*(s32 *)(h + 0x25CC) != 13 && *(s32 *)(h + 0x25CC) != 14 && state != 68 && *(s16 *)(h + 0x1F0) == 0) {
        magnitude = func_0038CEA8(h + 0xF0);
        limit = *(f32 *)(h + 0x284) - 0.02f;
        if (limit < magnitude) func_0038CF68(h + 0xF0, h + 0xF0, limit);
    }
    p = (u8 *)D_001A4C60;
    h = p - 0x80;
    vec_add_ab(p, p, p + 0x70);
    vec_add_ab(p, p, p + 0x960);
    qzero(p + 0x960);
    h[0x2A7] = 0;
    *(s32 *)(h + 0x28C) = 0;
    if (func_0038CEA8(p + 0x80) <= 0.00009999999747378752f) {
        func_L01_004F0AB0();
        func_L01_004EF840();
        vec_sub_ab(h + 0x110, p, &previous);
        func_L01_004F02D8();
    } else func_L01_004EF840();
    p = (u8 *)&D_001A4BE0 + 0x120;
    vec_sub_ba(p, p - 0xA0, &previous);
    *(vu0_q *)(p + 0x10) = *(vu0_q *)p;
    *(vu0_q *)(p + 0x20) = *(vu0_q *)p;
    func_0038CF68(p, p, 1.0f);
    dot = func_0038CE68(p, p - 0x30);
    if (dot < 0.0f) dot = 0.0f;
    func_0038CF68(p, p - 0x30, dot);
    *(vu0_q *)&temp = *(vu0_q *)(p - 0x30);
    func_L01_00511320(&temp, &temp);
    func_L01_00511320(p + 0x20, p + 0x20);
    func_0038CF68(p + 0x20, p + 0x20, 1.0f);
    dot = func_0038CE68(p + 0x20, &temp);
    if (dot < 0.0f) dot = 0.0f;
    func_0038CF68(p + 0x20, &temp, dot);
    *(vu0_q *)&vertical = *(vu0_q *)(p - 0x30);
    func_L01_00511588(&vertical, &vertical, 0.0f);
    func_L01_00511588(p + 0x10, p + 0x10, 0.0f);
    func_0038CF68(p + 0x10, p + 0x10, 1.0f);
    dot = func_0038CE68(p + 0x10, &vertical);
    if (dot < 0.0f) dot = 0.0f;
    func_0038CF68(p + 0x10, &vertical, dot);
    h = p - 0x120;
    *(f32 *)(h + 0x170) = func_0038CEA8(p);
    *(f32 *)(h + 0x174) = func_L01_00511408(p);
    *(vu0_q *)&temp = *(vu0_q *)p;
    *(f32 *)(h + 0x178) = func_L01_004F05F0((Q_004F05F0 *)&temp);
    *(f32 *)(h + 0x180) = func_L01_005114B0(p);
    if (*(f32 *)(h + 0x178) < 0.0f) *(f32 *)(h + 0x178) = 0.0f;
    *(vu0_q *)&temp = *(vu0_q *)(p - 0xA0);
    if (func_0038CEA8(p - 0x20) > 0.00009999999747378752f) {
        vec_add_ba(p - 0xA0, p - 0xA0, p - 0x20);
        { f32 saved_w = *(f32 *)(h + 0x10C);
          qzero(p - 0x20);
          *(f32 *)(h + 0x10C) = saved_w;
        }
        func_L01_004F0AB0();
        func_L01_004EF840();
        vec_sub_ab(h + 0x110, p - 0xA0, &previous);
        func_L01_004F02D8();
    }
    vec_sub_ba(h + 0x150, p - 0xA0, &temp);
    *(f32 *)(h + 0x184) = func_0038CEA8(p + 0x30);
    *(f32 *)(h + 0x15C) = *(f32 *)(h + 0x10C);
    *(f32 *)(h + 0x10C) = 0.0f;
    vec_sub_ba(h + 0x110, p - 0xA0, &previous);
    *(f32 *)(h + 0x17C) = 0.0f;
    if (*(f32 *)(h + 0x174) > 0.004000000189989805f) {
        *(f32 *)(h + 0x17C) = *(f32 *)(h + 0x118) / *(f32 *)(h + 0x174);
        if (*(f32 *)(h + 0x17C) > 0.5f) *(f32 *)(h + 0x17C) = 0.5f;
        else if (*(f32 *)(h + 0x17C) < -0.5f) *(f32 *)(h + 0x17C) = -0.5f;
    }
    h = (u8 *)&D_001A4BE0;
    if (*(f32 *)(h + 0x170) > 1.040000081062317f) {
        func_0038CE20((h + 0x110), (h + 0x110), 1.040000081062317f / *(f32 *)(h + 0x170));
        *(f32 *)(h + 0x170) = 1.040000081062317f;
    }
}
