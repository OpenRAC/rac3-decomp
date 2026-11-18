#include "common.h"

/* localdecomp:start func_L13_003C4F60 */
extern u8 D_001A71C4[];
extern s32 D_00142660[];
extern u8 D_001A30B0[];
extern f32 D_L13_001DEB70[] __attribute__((section(".sdata")));
extern f32 D_L13_001DEB80[] __attribute__((section(".sdata")));
extern f32 D_L13_001DEB90[] __attribute__((section(".sdata")));
extern void func_L13_003C5430(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L13_003C54F8(void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L13_003C56A0(void *);
extern f32 func_L03_00435A08(f32 *, f32 *, f32, f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_003A4F28(s32);
extern void func_L13_003C5838(void *);
extern void func_L13_003C59E8(void *);
extern void func_003C2880(void *);
extern f32 func_0038DB48(f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L13_003C4F60(u8 *o) {
    u8 *s;
    u8 *p;
    u8 *q;
    u8 *q1;
    u8 *q2;
    u8 *e;
    s32 i;
    s32 id;
    s32 n;
    s32 c;
    s32 r;
    s32 b;
    s32 id2;
    f32 *pa;
    f32 *pb;
    f32 *pc;
    f32 *ta;
    f32 *tb;
    f32 *tc;
    f32 sum;
    f32 fl;
    f32 ang;

    s = *(u8 **)(o + 0x68);
    *(s32 *)(s + 0x254) = D_001A71C4[0] == 1;
    switch (o[0x20]) {
    case 0:
        func_L13_003C5430(o);
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        q = func_L01_00447490(o, 0x10000, 0);
        if (q != 0 && (q = *(u8 **)(q + 0x20)) != 0) {
            n = *(s16 *)(q + 0xAA);
            if (n == 0x47 || (n == 0x57 && *(s32 *)(s + 0x254) != 0)) {
                n = D_00142660[0];
                if (n >= 10) {
                    D_00142660[0] = n - 10;
                    func_L01_004450F0(o, 2, -1);
                    func_003A52A0(0, 0, o);
                }
            }
        }
        if (*(s32 *)(s + 0x260) != 0) {
            c = (s[0x266] << 16) | (s[0x265] << 8) | s[0x264];
            r = func_0038DBD8(c, 0x80A0A0A0, func_0038D0B0(*(f32 *)(s + 0x258)) * 0.35f + 0.35f);
            b = (r >> 16) & 0xFF;
            func_L01_0043B9E8(o, r & 0xFF, (r >> 8) & 0xFF, b);
        }
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            func_L13_003C54F8(o);
            *(f32 *)(s + 0x21C) = 1.5707964f;
            *(s32 *)(s + 0x22C) = 0x25;
            func_L01_0043B9E8(o, s[0x264], s[0x265], s[0x266]);
        }
        func_L01_00448890(s + 0x20C, s + 0x23C, 0, *(f32 *)(s + 0x21C), 0.008377581f, 0.012566371f, 0.62831855f);
        if (func_0038CAD0(s + 0x22C) != 0) {
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(o) != 0) {
            *(s32 *)(s + 0x21C) = 0;
            func_L13_003C56A0(o);
            *(s32 *)(s + 0x22C) = 0x32;
            id = *(s32 *)(s + 0x268);
            if (id == -1 || (e = D_001A30B0 + id * 0x80, *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
                *(s32 *)(s + 0x268) = func_003A52A0(1, 4, o);
            }
        }
        p = s + 0x22C;
        func_L03_00435A08((f32 *)(s + 0x20C), (f32 *)(s + 0x23C), *(f32 *)(s + 0x21C), 3.0f, 0.85f);
        sum = 0.0f;
        tc = D_L13_001DEB90;
        tb = D_L13_001DEB80;
        ta = D_L13_001DEB70;
        for (i = 0; i < 3; i++) {
            sum += func_003C41A0((f32 *)(s + 0x200) + i, (f32 *)(s + 0x230) + i, *((f32 *)(s + 0x210) + i), ta[i], tb[i], tc[i]);
        }
        if (func_0038CAD0(p) != 0 && sum < 0.004363323f) {
            id2 = *(s32 *)(s + 0x268);
            if (id2 != -1) {
                e = D_001A30B0 + id2 * 0x80;
                if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                    func_003A4F28(id2);
                }
            }
            *(s32 *)(s + 0x268) = -1;
            func_L13_003C5838(o);
            if (*(s32 *)(s + 0x250) != 0) {
                func_L13_003C59E8(o);
                func_003C2880(o);
                return;
            }
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
    i = 0;
    q1 = s + 0x180;
    q2 = s + 0x258;
    for (; i < 3; i++) {
        f32 x = *(f32 *)(s + 0x200 + i * 4);
        if (i == 1) {
            x = -x;
        }
        *(f32 *)(s + i * 0x80 + 0x68) = func_0038DB48(x);
        func_L01_0044E850(o, s + i * 0x80, i, 0.25132743f, 0.25132743f);
    }
    *(f32 *)(s + 0x1E0) = func_0038DB48(*(f32 *)(s + 0x20C));
    func_L01_0044E850(o, q1, 3, 0.25132743f, 0.25132743f);
    func_L01_00451DB8(o, q2, 0x80A0A0A0, 0x80505050, *(f32 *)(s + 0x25C));
    o[0xA8] = 0xFF;
}
/* localdecomp:end func_L13_003C4F60 */
