#include "common.h"

/* localdecomp:start func_L39_00531FB0 */
#include "vu0.h"

typedef int u128_00531FB0 __attribute__((mode(TI)));

typedef struct {
    u8 *f0;
    u8 pad4[0x2C];
    f32 f30;
    s16 f34;
    u8 pad36[0x8];
    u8 f3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x1E];
    u8 f62;
    u8 pad63[0x17D];
    u8 f1E0[0x390];
    u8 f570[0x40];
    u128_00531FB0 f5B0;
    u8 pad5C0[0x30];
    u128_00531FB0 f5F0;
    u8 pad600[0xD0];
    u8 *f6D0;
    u8 pad6D4[0x8];
    f32 f6DC;
    u8 pad6E0[0x35];
    u8 f715;
    u8 pad716[0xA];
    u8 *f720;
    f32 f724;
    f32 f728;
    s32 f72C;
    s32 f730;
    f32 f734;
    f32 f738;
    f32 f73C;
    u8 pad740[0x8];
    s32 f748;
    u8 pad74C[0x10];
    s32 f75C;
    u8 pad760[0x18];
    s32 f778[4];
    s32 f788;
    s32 f78C;
    s32 f790[4];
    u8 pad7A0[0x14];
    s32 f7B4[7];
} P_00531FB0;

extern s32 *D_L39_00241120;
__asm__(".extern D_L39_0024BF5C, 4");
extern u8 *D_L39_0024BF5C;
extern s32 D_L39_002412DC;
extern f32 D_L39_0024AB30;
extern f32 D_L39_0024AB34;
extern u8 *D_L39_00241640;
extern u8 D_L39_00470260[];
extern u8 D_L39_004702EC[];
extern u8 D_L39_0024DE80[];

extern void func_003C2880(void *);
extern void func_L39_0061C1E0(void *, s32);
extern void func_L39_00668CD8(void *, void *, f32);
extern void func_L39_00530B00(void);
extern void func_L39_00530E18(void);
extern void func_L39_0052D348(void);
extern void func_L39_0052D9D0(void *);
extern void func_L39_0052EE60(void);
extern void func_L39_00530490(void);
extern void func_L39_0052D4E8(void);
extern void func_L39_00668C90(s32, void *, void *, void *, void *, void *, void *, void *);
extern s32 func_L39_00666FB8(s32, void *, u32, s32, s32, f32);
extern void func_L09_003CB6C0(void *);
extern void func_L01_0043A430(u8 *, s32, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L39_00531668(void *);

void func_L39_00531FB0(u8 *a0) {
    P_00531FB0 *p = *(P_00531FB0 **)(a0 + 0x68);
    u8 *q;
    s32 i;
    s32 n;
    s32 cnt;
    s32 m;
    f32 f;
    f32 v;
    f32 w;

    if (p->f62 == 1) {
        func_003C2880(a0);
        return;
    }
    q = p->f6D0;
    if (*D_L39_00241120 >= 2) {
        a0[0x62] = 0x10;
    }
    switch (a0[0x20]) {
    case 0: {
        u8 *pos = a0 + 0x10;
        s32 *arr = p->f790;
        s32 *ids = p->f7B4;
        s32 j;

        u8 *ents = D_L39_0024BF5C;
        s32 lvl;
        s32 h;
        s32 lvl2;

        for (i = 0; i < 7; i++) {
            if (ids[i] != -1) {
                u8 *e = ents + (ids[i] << 8);
                *(s32 *)(e + 0x98) = 0;
                *(u16 *)(e + 0x34) |= 0x41;
            }
        }
        lvl = D_L39_002412DC;
        p->f0 = *(u8 **)(a0 + 0x68) + 0x30;
        *(u16 *)(a0 + 0x34) |= 0x5020;
        if (lvl == 0x12) {
            f32 t = D_L39_0024AB34;
            p->f30 = t;
            p->f34 = t;
        } else if (lvl == 0x14) {
            f32 t = 200.0f;
            p->f30 = t;
            p->f34 = t;
        } else {
            f32 t = D_L39_0024AB30;
            p->f30 = t;
            p->f34 = t;
        }
        p->f3E = 3;
        p->f40 = 0.95f;
        *(s16 *)(a0 + 0x32) = 0x1FF;
        a0[0x30] = 0xFF;
        a0[0xBE] &= 0xE7;
        func_L39_0061C1E0(a0, -1);
        func_L39_00668CD8(a0, pos, 1.5f);
        func_L39_00668C90(0, func_L39_0052D9D0, func_L39_0052EE60, func_L39_00530490, func_L39_0052D4E8,
                          func_L39_00530B00, func_L39_00530E18, func_L39_0052D348);
        h = func_L39_00666FB8(0, a0, 0xFFFFFFFF, 0xBB8, 0x8000000, 1.5f);
        p->f6D0 = (u8 *)h;
        *(s32 *)(a0 + 0x90) = h;
        p->f778[0] = -1;
        p->f778[1] = -1;
        p->f778[2] = -1;
        p->f778[3] = -1;
        p->f788 = 2;
        for (i = 3; i >= 0; i--) {
            arr[i] = 0;
        }
        p->f75C = 0;
        lvl2 = D_L39_002412DC;
        p->f6DC = *(f32 *)(a0 + 0x18);
        if (lvl2 == 0x15CC || lvl2 == 0xBC2 || lvl2 == 0x18) {
            p->f715 = 0;
            p->f720 = D_L39_00470260;
        } else {
            p->f715 = 1;
            p->f720 = D_L39_004702EC;
        }
        func_L39_0052D9D0(a0);
        func_L09_003CB6C0(a0);
        *(u128_00531FB0 *)(p->f6D0 + 0x290) = *(u128_00531FB0 *)(a0 + 0x10);
        *(u128_00531FB0 *)(p->f6D0 + 0x2A0) = *(u128_00531FB0 *)(a0 + 0xF0);
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.75f;
        for (j = 0; j < 17; j++) {
            if (((u8 *)p)[0x1E1 + j * 0x40] == 0) {
                func_L01_0043A430(a0, j, (u8 *)p + 0x1E0 + j * 0x40);
            }
        }
        func_L01_004450F0(a0, 1, -1);
        if (p->f748 != 0) {
            if (*(s8 *)(D_L39_00241640 + 0x188) == 0) {
                p->f748 = 0;
            }
            if (p->f748 != 0) {
                break;
            }
        }
        a0[0xBC] = 8;
        break;
    }
    case 1:
        if (*(s32 *)(q + 0x2DC) == 0) {
            n = p->f72C;
            if (n >= 0) {
                if (n != 0x63) {
                    func_L01_003EB5E0(n, 0);
                }
                f = func_0038DB00(p->f724, *(f32 *)(a0 + 0xF8));
                m = fabs_asm(f);
                p->f738 = f;
                p->f72C = -1;
                cnt = (m * 5 + 2) / 6;
                p->f730 = cnt;
                p->f734 = p->f728 / (f32)cnt;
                p->f73C = fabs_asm(f / (f32)cnt);
            }
        }
        cnt = p->f730;
        if (cnt >= 0) {
            p->f730 = cnt - 1;
            v = p->f728;
            if (v > 0.0f) {
                p->f728 = v - p->f734;
                if (p->f728 < 0.0f) {
                    p->f728 = 0.0f;
                }
            } else if (v < 0.0f) {
                p->f728 = v - p->f734;
                if (p->f728 > 0.0f) {
                    p->f728 = 0.0f;
                }
            }
            func_0038D750(&p->f5B0, 1, p->f728);
            p->f5F0 = p->f5B0;
            p->f724 = func_0038DAB8(*(f32 *)(a0 + 0xF8), p->f738);
            w = p->f738;
            if (w > 0.0f) {
                p->f738 = w - p->f73C;
                if (p->f738 < 0.0f) {
                    p->f738 = 0.0f;
                }
            } else if (w < 0.0f) {
                p->f738 = w + p->f73C;
                if (p->f738 > 0.0f) {
                    p->f738 = 0.0f;
                }
            }
            f = func_0038DB00(p->f724, *(f32 *)(a0 + 0xF8));
            func_0038D750(p->f570, 2, f);
        }
        break;
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L39_0024DE80, a0 + 0x10) < 484.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x14;
        }
    }
    func_L39_00531668(a0);
}
/* localdecomp:end func_L39_00531FB0 */
