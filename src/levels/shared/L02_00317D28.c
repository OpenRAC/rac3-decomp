#include "common.h"

typedef struct { u8 p0[0x23]; u8 f23; u8 p24[0x10]; u16 f34; } E_00318E78;

typedef struct { char pad[0x10]; unsigned int kind; } B;
typedef struct { char pad[0x68]; B *b; } A;

typedef struct { u8 p0[0x23]; s8 f23; } E_00318CA8;
typedef struct { u8 p0[0x1200]; E_00318CA8 *e[3]; u8 pad[0x50 - 0xC]; } S_00318CA8;
typedef struct { u8 p0[0x25C0]; E_00318CA8 *g; } T_00318CA8;

/* localdecomp:start func_L02_00317D28 */
/* func_L02_00317D28 log:
 * v1: written from the PAL asm, with the NTSC-U draft (func_L02_00317890) as the skeleton: 580 diff.
 * $gp slots 0x1DC6B0-0x1DC6E8: section(".sdata") + .extern size hints (ps2as gave lui $at without): 361.
 * case 1 store order, case 3 x/y/z store order, divs row 2 0: 353.
 * case 4: the 0x21E0D8 table pointer in a local, set in the loop (loop.c hoists the full address): 108.
 * case 5: if/else around the two func_L01_0042B068 calls instead of ?: : 2.
 * case 4: life * 0.0004f at each argument instead of life *= 0.0004f: MATCH (needs -mvu0-use-vf0-vf2).
 */
#include "vu0.h"

typedef union { s32 i[24]; f32 f[24]; } V_00317D28;
typedef struct M_00317D28 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    u8 *data;
    u8 pad28[8];
    u8 opacity;
    u8 pad31[3];
    u16 flags;
    u8 pad36[0x32];
    V_00317D28 *vars;
    u8 pad6c[0xC];
    s32 color;
    u8 pad7c[0x1C];
    s32 f98;
    u8 pad9c[0x24];
    u8 matrix[0x20];
    vu0_v4 rot;
    u8 padf0[8];
    f32 angle;
} M_00317D28;

extern void *D_001A71A0[];
extern u8 D_L02_0026F7A0[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern s32 D_L02_002CF1B0[];
extern s32 D_L02_001D6694;
extern s32 D_L02_001D673C;
extern u8 *D_L02_001DE99C;
extern vu0_v4 D_L02_001DE5D0 __attribute__((section(".sdata")));
extern vu0_v4 D_001A4C90;
extern f32 D_L02_001DE2D8;
extern u8 D_L02_0021E0D8[];
extern u8 D_001A71C5[];
extern u8 D_L02_001DC6B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6B0, 8");
extern s32 D_L02_001DC6B8 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6B8, 4");
extern s32 D_L02_001DC6BC __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6BC, 4");
extern s32 D_L02_001DC6C0 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6C0, 4");
extern f32 D_L02_001DC6C4 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6C4, 4");
extern f32 D_L02_001DC6C8 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6C8, 4");
extern f32 D_L02_001DC6CC __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6CC, 4");
extern f32 D_L02_001DC6D0 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6D0, 4");
extern f32 D_L02_001DC6D4 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6D4, 4");
extern f32 D_L02_001DC6D8 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6D8, 4");
extern f32 D_L02_001DC6DC __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6DC, 4");
extern f32 D_L02_001DC6E0 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6E0, 4");
extern f32 D_L02_001DC6E4 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6E4, 4");
extern f32 D_L02_001DC6E8 __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6E8, 4");

extern void func_L02_003BAAB0(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L02_00318910(A *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_L02_004E2118(void *, void *, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_00318F28(void *);
extern void func_L02_00318CA8(f32 *, f32);
extern void func_L02_00318A28(void *, void *);
extern s32 func_L01_00511A98(void);
extern void func_L02_004D36C0(s32, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L02_00319BB0(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L02_00318E78(void);
extern void func_L02_004D7540(s32);
extern void func_L01_00404A10_00317D28(void *, void *);
extern void func_L02_003189D8();
extern void func_L01_0042B068(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L02_00317D28(M_00317D28 *m) {
    vu0_v4 pos, temp;
    f32 matrix[12] __attribute__((aligned(16)));
    V_00317D28 *p = m->vars;
    V_00317D28 *q;

    switch (m->state) {
    case 0:
        m->opacity = 255;
        func_L02_003BAAB0(D_001A71A0[0], D_L02_0026F7A0);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1: {
        u8 *hero;
        if ((p->i[2] >= 0 && !(D_001BBC40[p->i[2] + D_001D545C * 16] & 0x80)) ||
            (p->i[3] >= 0 && (D_001BBC40[p->i[3] + D_001D545C * 16] & 0x80) && p->i[1] == -1)) {
            m->f98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            break;
        }
        m->flags &= 0xFFBE;
        m->flags |= *(u16 *)(m->data + 0x44) & 0x1000;
        m->f98 = *(s32 *)(m->data + 0x10);
        if (p->i[0] == -1) break;
        hero = D_001A4BE0;
        if (*(M_00317D28 **)(hero + 0x35C) != m || *(s16 *)(hero + 0x36E) != 0 ||
            *(s32 *)(hero + 0x25C4) == 20 || hero[0x25E4] != 0) break;
        if (!(func_0038CF38(&m->pos, hero + 0x80) < 0.5f) || *(s32 *)(hero + 0x25C4) == 128) break;
        func_L02_00318910((A *)m);
        if (!(*(s32 *)(D_001D52FC + 0x1A4) & 0x10) || D_L02_002CF1B0[0] != 12 || D_L02_001D6694 == 2) break;
        func_003A52A0(0, 0, m);
        *(u16 *)(*(u8 **)(hero + 0x25C0) + 0x34) |= 0x2000;
        func_L01_004450F0(m, 2, -1);
        p->f[0x44 / 4] = func_00382538();
        p->f[0x48 / 4] = 0.03490659f;
        p->f[0x4C / 4] = 0.8f;
        p->f[0x18 / 4] = 0.8f;
        p->f[0x1C / 4] = 1.0f;
        p->f[0x14 / 4] = 0.3f;
        p->f[0x54 / 4] = 1.0f;
        if (D_L02_001D673C) {
            vec_sub_ba(&pos, &m->pos, hero + 0x80);
            func_L02_004E2118(&m->pos, &pos, 0);
        } else {
            func_L01_00511A40(&m->pos, 0, m->angle);
        }
        func_L01_00446780((u8 *)m, (u8 *)&m->pos, 0x10000, 0, 1, 0, 1.5f, 20.0f, 1.0f);
        break;
    }
    case 2: {
        s32 n;
        func_L02_00318F28(m);
        func_L02_00318CA8(&p->f[0x54 / 4], -D_L02_001DC6E8);
        func_L02_00318A28(m, D_L02_001DC6B0);
        n = func_L01_00511A98();
        if (n == 2) {
            func_L02_004D36C0(0x74, 1);
            p->f[0x24 / 4] = 1.95f;
            func_L01_004450F0(m, 3, -1);
        } else if (n == 0) {
            func_L01_004450F0(m, 4, -1);
        }
        break;
    }
    case 3: {
        u8 *hero;
        u8 *target;
        vu0_v4 *targetpos;
        hero = D_001A4BE0;
        if (*(*(u8 **)(hero + 0x25C0) + 0x23) >= 13) {
            func_L02_00318CA8(&p->f[0x54 / 4], -D_L02_001DC6E8);
            func_L02_00318A28(m, D_L02_001DC6B0);
            func_L02_00318F28(m);
            break;
        }
        hero[0x25E5] = 1;
        if (p->i[0x28 / 4] >= 0) {
            func_L01_004450F0(m, 5, -1);
            break;
        }
        target = D_L02_001DE99C + p->i[0] * 256;
        if (p->i[1] != -1 && (D_001BBC40[p->i[3] + D_001D545C * 16] & 0x80)) {
            target = D_L02_001DE99C + p->i[1] * 256;
        }
        q = *(V_00317D28 **)(target + 0x68);
        targetpos = (vu0_v4 *)(target + 0x10);
        pos = *targetpos;
        if (p->i[0x50 / 4] == 1) {
            D_L02_001DE5D0.x = 200.0f;
            D_L02_001DE5D0.y = 400.0f;
            D_L02_001DE5D0.z = 200.0f;
            D_001A4C90 = D_L02_001DE5D0;
            func_003C5180(&m->pos, &temp, 0);
            func_L01_004515D8(m->matrix, &temp, matrix);
            func_003C5180(targetpos, &temp, 0);
            func_L01_004515D8(target + 0xC0, &temp, matrix);
        } else if (p->i[0x50 / 4] == 2) {
            D_L02_001DE5D0.x = 526.922f;
            D_L02_001DE5D0.y = 200.0f;
            D_L02_001DE5D0.z = 819.262f;
            D_001A4C90 = D_L02_001DE5D0;
            func_003C5180(&m->pos, &temp, 0);
            func_L01_004515D8(m->matrix, &temp, matrix);
            func_003C5180(targetpos, &temp, 0);
            func_L01_004515D8(target + 0xC0, &temp, matrix);
        }
        if (!D_L02_001D673C) {
            pos.z += 0.2f;
        } else {
            func_0038CF68(&temp, target + 0xE0, 0.75f);
            vec_add_ab(&pos, &temp, &pos);
        }
        func_L01_004F50C8(&pos, target + 0xF0, 0, 1);
        p->f[0x40 / 4] = 0.6f;
        if (p->i[0x28 / 4] < 0) D_L02_001DE2D8 = 0.6f;
        target[0x20] = 4;
        q->i[0x24 / 4] = 0;
        q->f[0x44 / 4] = p->f[0x44 / 4];
        q->f[0x48 / 4] = p->f[0x48 / 4];
        q->f[0x4C / 4] = p->f[0x4C / 4];
        q->f[0x14 / 4] = p->f[0x14 / 4];
        q->f[0x18 / 4] = p->f[0x18 / 4];
        q->f[0x1C / 4] = p->f[0x1C / 4];
        func_003A52A0(1, 0, target);
        func_L01_004450F0(m, 1, -1);
        p->f[0x24 / 4] = 1.95f;
        break;
    }
    case 4: {
        u8 *particle;
        f32 angle, step, size, life;
        s32 i, n, extra;
        u8 *fx;
        if (func_L01_004561B8(m)) {
            p->f[0x40 / 4] = 0.6f;
            angle = 0.0f;
            step = 6.2831855f / (f32)D_L02_001DC6B8;
            for (i = 0; i < D_L02_001DC6B8; i++) {
                *(vu0_q *)&temp = 0;
                extra = 0;
                temp.x = D_L02_001DC6DC * func_0038D0B0(angle);
                temp.y = D_L02_001DC6DC * func_0038D098(angle);
                temp.z = D_L02_001DC6E0;
                pos = temp;
                temp = m->pos;
                temp.z += func_003824E0(0.3f, 1.6f);
                pos.z = 0.0f;
                func_0038CF68(&pos, &pos, (D_L02_001DC6C4 + func_003824E0(-D_L02_001DC6C8, D_L02_001DC6C8)) * 0.020000001f);
                n = func_00382498(D_L02_001DC6BC, D_L02_001DC6C0);
                size = D_L02_001DC6CC + func_003824E0(-D_L02_001DC6D0, D_L02_001DC6D0);
                life = D_L02_001DC6D4 + func_003824E0(-D_L02_001DC6D8, D_L02_001DC6D8);
                {
                    s32 variant = func_00382468(2);
                    particle = func_L01_0046FB40(&temp, &pos, n, 0x108F10, variant ? -1 : 1, 64, 32,
                                                 size * 210000.0f, size * 210000.0f, life * 0.00040000002f, 0);
                }
                fx = D_L02_0021E0D8;
                if (particle) {
                    extra = particle[8] + 32;
                    particle[2] = **(u8 **)(fx + 0x164);
                }
                particle = func_L01_0046FB40(&temp, &pos, n, 0xF7F7F7, func_00382468(2) ? -1 : 1, 48, 48,
                                             size * D_L02_001DC6E4 * 210000.0f,
                                             size * D_L02_001DC6E4 * 210000.0f, life * 0.00040000002f, 0);
                if (particle) {
                    particle[2] = **(u8 **)(fx + 0x164);
                    particle[8] = extra;
                }
                angle = func_0038DAB8(angle, step);
            }
        }
        p->f[0x40 / 4] -= 0.075f;
        if (p->f[0x40 / 4] < 0.0f) p->f[0x40 / 4] = 0.0f;
        if (p->i[0x28 / 4] < 0) D_L02_001DE2D8 = p->f[0x40 / 4];
        if (p->f[0x24 / 4] < 1.95f && *((u8 *)D_001A71A0[0] + 0x23) < 110) {
            func_L02_00318CA8(&p->f[0x54 / 4], D_L02_001DC6E8);
            func_L02_00318A28(m, D_L02_001DC6B0);
            func_L02_00319BB0(m);
            func_003C4138(&p->f[0x24 / 4], 1.95f, 0.020000001f);
        } else {
            func_L02_00318E78();
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
    case 6:
        if (func_L01_004561B8(m)) p->i[0x2C / 4] = 0;
        p->f[0x2C / 4] += 0.02f;
        D_001A71C5[0] = 1;
        if (p->f[0x2C / 4] >= 1.2f) {
            func_L02_004D7540(0);
            func_L01_004450F0(m, 4, -1);
            p->i[0x24 / 4] = 0;
            func_003A52A0(1, 0, m);
        }
        func_L01_00404A10_00317D28(func_L02_003189D8, m);
        break;
    case 5: {
        u8 *target;
        if (func_L01_004561B8(m)) p->f[0x2C / 4] = 1.0f;
        p->f[0x2C / 4] -= 0.02f;
        D_001A71C5[0] = 1;
        if (p->f[0x2C / 4] <= -0.2f) {
            target = D_L02_001DE99C + p->i[0] * 256;
            target[0x20] = 6;
            func_L01_004450F0(m, 1, -1);
            p->f[0x24 / 4] = 1.95f;
            if (p->i[0x30 / 4] >= 0) {
                func_L01_0042B068(p->i[0x28 / 4], p->i[0x30 / 4]);
            } else {
                func_L01_0042B068(p->i[0x28 / 4], 0);
            }
            pos = *(vu0_v4 *)(target + 0x10);
            pos.z += 0.2f;
            func_L01_004F50C8(&pos, target + 0xF0, 0x74, 1);
            func_L01_004450F0(m, 1, -1);
        }
        func_L01_00404A10_00317D28(func_L02_003189D8, m);
        break;
    }
    }
    if (func_0038CAD0(&p->i[0x38 / 4])) p->i[0x38 / 4] = 50;
    m->color = func_0038DBD8(0x80B0B0B0, 0x80505050,
                             func_0038D0B0((f32)p->i[0x38 / 4] * 6.2831855f / 50.0f) * 0.5f + 0.5f);
}
/* localdecomp:end func_L02_00317D28 */
