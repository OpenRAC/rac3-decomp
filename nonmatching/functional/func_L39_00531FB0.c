/* functional: high. Same behaviour as retail; compiler scheduling/hoisting of the sda load differs, no divs_nops row so div.s nops differ. */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 f0;
    u8 flag;
    u8 pad2[0xE];
    u128_t v;
    u8 pad20[0x20];
} Ent_531FB0;

typedef struct {
    u8 *f0;
    u8 pad4[0x2C];
    f32 f30;
    u16 h34;
    u8 pad36[8];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x1E];
    u8 b62;
    u8 pad63[0x17D];
    Ent_531FB0 e[17];
    u8 pad620[0xB0];
    u8 *f6D0;
    u8 pad6D4[8];
    f32 f6DC;
    u8 pad6E0[0x35];
    u8 b715;
    u8 pad716[10];
    u8 *f720;
    f32 f724;
    f32 f728;
    s32 f72C;
    s32 f730;
    f32 f734;
    f32 f738;
    f32 f73C;
    u8 pad740[8];
    s32 f748;
    u8 pad74C[0x10];
    s32 f75C;
    u8 pad760[0x18];
    s32 f778;
    s32 f77C;
    s32 f780;
    s32 f784;
    s32 f788;
    u8 pad78C[4];
    s32 w790[4];
    u8 pad7A0[0x14];
    s32 ids[7];
} St_531FB0;

extern s32 *D_001D5A10_sda;
__asm__(".extern D_001D5A10_sda, 4");
extern u8 *D_001E084C_sda;
__asm__(".extern D_001E084C_sda, 4");
extern f32 D_001DF424_sda;
__asm__(".extern D_001DF424_sda, 4");
extern f32 D_001DF420_sda;
__asm__(".extern D_001DF420_sda, 4");
extern s8 *D_001D5F30_sda;
__asm__(".extern D_001D5F30_sda, 4");
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern u8 D_L39_0024DE80[];
extern u8 D_L39_00470260[];
extern u8 D_L39_004702EC[];

extern void func_003C2880(void *);
extern void func_L39_0061C1E0(void *, s32, s32);
extern void func_L39_00668CD8(void *, void *, f32);
extern void func_L39_00668C90(s32, void *, void *, void *, void *, void *, void *, void *);
extern u8 *func_L39_00666FB8(s32, void *, u32, s32, s32, f32);
extern void func_L39_0052D9D0(void *);
extern void func_L09_003CB6C0(void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L39_00531668(void *);
extern void func_L39_00530B00(void);
extern void func_L39_00530E18(void);
extern void func_L39_0052D348(void);
extern void func_L39_0052EE60(void);
extern void func_L39_00530490(void);
extern void func_L39_0052D4E8(void);

void func_L39_00531FB0(u8 *o) {
    St_531FB0 *st;
    u8 *m;
    u8 *pos;
    s32 i;
    s32 id;
    s32 lvl;
    s32 n;
    f32 f;
    f32 a;
    f32 b;
    f32 k;
    f32 g2;

    st = *(St_531FB0 **)(o + 0x68);
    if (st->b62 == 1) {
        func_003C2880(o);
        return;
    }
    if (*D_001D5A10_sda >= 2) {
        o[0x62] = 0x10;
    }
    if (o[0x20] == 0) {
        pos = o + 0x10;
        for (i = 0; i < 7; i++) {
            id = st->ids[i];
            if (id != -1) {
                m = D_001E084C_sda + (id << 8);
                *(u16 *)(m + 0x34) |= 0x41;
                *(s32 *)(m + 0x98) = 0;
            }
        }
        (*(St_531FB0 **)(o + 0x68))->f0 = (u8 *)*(St_531FB0 **)(o + 0x68) + 0x30;
        *(u16 *)(o + 0x34) |= 0x5020;
        lvl = D_L39_002412DC;
        if (lvl == 0x12) {
            f = D_001DF424_sda;
        } else if (lvl == 0x14) {
            f = 200.0f;
        } else {
            f = D_001DF420_sda;
        }
        st->f30 = f;
        st->h34 = (s32)f;
        st->b3E = 3;
        st->f40 = 0.95f;
        *(u16 *)(o + 0x32) = 0x1FF;
        o[0x30] = 0xFF;
        o[0xBE] &= 0xE7;
        k = 1.5f;
        func_L39_0061C1E0(o, -1, 0xFF);
        func_L39_00668CD8(o, pos, k);
        func_L39_00668C90(0, func_L39_0052D9D0, func_L39_0052EE60, func_L39_00530490, func_L39_0052D4E8, func_L39_00530B00, func_L39_00530E18, func_L39_0052D348);
        m = func_L39_00666FB8(0, o, 0xFFFFFFFF, 0xBB8, 0x8000000, k);
        st->f6D0 = m;
        *(u8 **)(o + 0x90) = m;
        st->f784 = -1;
        st->f788 = 2;
        st->f778 = -1;
        st->f77C = -1;
        st->f780 = -1;
        for (i = 3; i >= 0; i--) {
            st->w790[i] = 0;
        }
        st->f75C = 0;
        lvl = D_L39_002412DC;
        st->f6DC = *(f32 *)(o + 0x18);
        if (lvl == 0x15CC || lvl == 0xBC2 || lvl == 0x18) {
            st->b715 = 0;
            st->f720 = D_L39_00470260;
        } else {
            st->b715 = 1;
            st->f720 = D_L39_004702EC;
        }
        func_L39_0052D9D0(o);
        func_L09_003CB6C0(o);
        *(u128_t *)(st->f6D0 + 0x290) = *(u128_t *)(o + 0x10);
        *(u128_t *)(st->f6D0 + 0x2A0) = *(u128_t *)(o + 0xF0);
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 0.75f;
        for (i = 0; i < 17; i++) {
            if (st->e[i].flag == 0) {
                func_L01_0043A430(o, i, &st->e[i]);
            }
        }
        func_L01_004450F0(o, 1, -1);
        if (st->f748 != 0) {
            if (D_001D5F30_sda[0x188] == 0) {
                st->f748 = 0;
            }
            if (st->f748 != 0) {
                goto tail;
            }
        }
        o[0xBC] = 8;
    } else if (o[0x20] == 1) {
        if (*(s32 *)(st->f6D0 + 0x2DC) == 0) {
            id = st->f72C;
            if (id >= 0) {
                if (id != 0x63) {
                    func_L01_003EB5E0(id, 0);
                }
                a = func_0038DB00(st->f724, *(f32 *)(o + 0xF8));
                b = st->f728;
                n = (s32)fabs_asm(a);
                st->f738 = a;
                st->f72C = -1;
                n = (n * 5 + 2) / 6;
                st->f730 = n;
                st->f734 = b / (f32)n;
                st->f73C = fabs_asm(a / (f32)n);
            }
        }
        n = st->f730;
        if (n >= 0) {
            st->f730 = n - 1;
            f = st->f728;
            if (0.0f < f) {
                g2 = f - st->f734;
                st->f728 = g2;
                if (g2 < 0.0f) {
                    st->f728 = 0.0f;
                }
            } else if (f < 0.0f) {
                g2 = f - st->f734;
                st->f728 = g2;
                if (0.0f < g2) {
                    st->f728 = 0.0f;
                }
            }
            func_0038D750(&st->e[15].v, 1, st->f728);
            st->e[16].v = st->e[15].v;
            st->f724 = func_0038DAB8(*(f32 *)(o + 0xF8), st->f738);
            f = st->f738;
            if (0.0f < f) {
                g2 = f - st->f73C;
                st->f738 = g2;
                if (g2 < 0.0f) {
                    st->f738 = 0.0f;
                }
            } else if (f < 0.0f) {
                g2 = f + st->f73C;
                st->f738 = g2;
                if (0.0f < g2) {
                    st->f738 = 0.0f;
                }
            }
            func_0038D750(&st->e[14].v, 2, func_0038DB00(st->f724, *(f32 *)(o + 0xF8)));
        }
    }
tail:
    if (o[0x31] != 0) {
        if (func_L01_0040E548(D_L39_0024DE80, o + 0x10) < 484.0f) {
            func_L01_004472C0(o);
            o[0x6F] = 0x14;
        }
    }
    func_L39_00531668(o);
}
