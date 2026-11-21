/* PAL near miss (haiku-w2): 210 words differ with the file's flags; slot-loop and g/D address register choice, the 0xC00 table bases hoisted early (retail rebuilds the second base in the loop) and the block order of the first branch remain. */
#include "common.h"
/* localdecomp:start func_L01_004EAB10 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x8];
    u128_t rot;
    u8 padA0[0x54C];
    f32 yaw;
    f32 pitch;
    u8 pad5F4[0x4C];
    f32 targetYaw;
    u8 pad644[0x4];
    u8 * target;
    u8 pad64C[0xA4];
    Vec4 trans;
    Vec4 r;
    u8 pad710[0x768];
    u8 * slots[2];
    u8 padE80[0x4];
    s32 pending;
    u8 padE88[0x5AC];
    s16 lock;
    u8 pad1436[0x27A];
    s32 state;
    u8 pad16B4[0xF0C];
    u8 * moby;
    u8 pad25C4[0x8];
    s32 mode;
    u8 pad25D0[0x19];
    u8 active;
    u8 pad25EA[0x1];
    u8 flags;
    u8 pad25EC[0x8];
    u8 strafe;
    u8 pad25F5[0x23B];
    s32 anim;
    s32 item;
} H_004EAB10;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Buf_004EA7D8 D_L01_00255880[];
extern u8 D_L01_00255E80[];
extern u8 D_001A52A0[];
void func_L01_004EAB10(void) {
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_004E9238();
    extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);
    extern void func_L01_00439E10(u8 *, u8 *);
    extern f32 func_003C4138(f32 *, f32, f32);
    extern void func_L01_00439D70(M004E9888 *, s32 *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern s32 func_L01_004606E8(s32,s32,s32,s32);
    u128_t matrix[3];
    Vec4 v;
    s32 i;
    u8 *h;
    H_004EAB10 *g;
    u8 **slot;
    f32 angle;
    if (D_001A4BE0[0x25E9] && D_001A4BE0[0x25EB] && !func_L01_005119E0(-1))
        func_L01_004EAA80();
    g = (H_004EAB10 *)D_001A4BE0;
    for (i = 0; i < 2; i++) {
        if (g->slots[i]) {
            s32 item;
            *(u8 **)(g->slots[i] + 0x38) = D_L01_00255880[i].first;
            *(u8 **)(g->slots[i] + 0x3C) = D_L01_00255880[i].second;
            item = func_L01_004E9238(0);
            if (g->item == item) {
                Def_004EA7D8 *def = &D_L01_002C5600[D_001425C0[item]];
                s32 anim = def->held;
                if (g->mode == 12) anim = def->alternate;
                if ((g->slots[i])[0x23] != anim && anim != -1) {
                    g->anim = anim;
                    func_L01_0043A1E8(g->moby, g->slots[i], anim, 0, 7, 1);
                }
            }
            {
            u8 **current = &g->slots[i];
            slot = &g->slots[i];
            func_L01_00439E10(((H_004EAB10 *)&D_001A4BE0)->moby, *current);
            if (((H_004EAB10 *)&D_001A4BE0)->pending) {
                if (((H_004EAB10 *)&D_001A4BE0)->pending == 2)
                    func_003C4138((f32 *)(*current + 8), 0.0f, 0.3f);
                else
                    func_003C4138((f32 *)(*current + 8), 0.0f, 0.084000006f);
                if (*(f32 *)(*current + 8) == 0.0f) {
                    func_L01_00439D70((M004E9888 *)((H_004EAB10 *)&D_001A4BE0)->moby, (s32 *)slot);
                    return;
                }
            } else {
                func_003C4138((f32 *)(*current + 8), 1.0f, 0.24000001f);
                if (((*current)[5] & 2) && !((H_004EAB10 *)&D_001A4BE0)->flags) {
                    ((H_004EAB10 *)&D_001A4BE0)->pending = 1;
                    *(s32 *)(*current + 0x28) = 0;
                    ((H_004EAB10 *)&D_001A4BE0)->active = 0;
                    return;
                }
            }
            }
        }
    }
    h = (u8 *)g;
    if (*(s32 *)(h + 0x25CC) == 15) {
        u8 *p = *(u8 **)(h + 0x648);
        if (p) {
            f32 x = *(f32 *)(h + 0x80);
            f32 y = *(f32 *)(h + 0x84);
            *(u128_t *)(h + 0x700) = *(u128_t *)(h + 0x90);
            *(f32 *)(h + 0x708) = func_0038D160(*(f32 *)(p + 0x10) - x, *(f32 *)(p + 0x14) - y);
        }
        else {
            *(u128_t *)(h + 0x700) = *(u128_t *)(h + 0x90);
            *(f32 *)(h + 0x708) = func_0038DAB8(*(f32 *)(h + 0x5EC), *(f32 *)(h + 0x640));
        }
        *(f32 *)(h + 0x704) = -*(f32 *)(h + 0x5F0);
        h = D_001A52A0;
        func_0038D308(h, h + 0x40);
        qzero(h + 0x30);
        *(f32 *)(h + 0x30) = 1.0f;
        func_0038D000(h + 0x30, h + 0x30, h);
        return;
    }
    angle = 0.0f;
    if (*(s16 *)(h + 0x1434) == 0 && (*(s32 *)(h + 0x16B0) != 1 || !func_L01_004606E8(40,2,0,0)))
        { u8 *p = (u8 *)&D_L01_002F4540; f32 yaw = *(f32 *)(p + 0xF8); angle = func_0038DAB8(*(f32 *)(p + 0x1A8), yaw); }
    qzero(&v);
    v.f[2] = angle;
    func_0038D308(matrix, &v);
    h = D_001A52A0;
    func_0038D5F0(h, h, matrix);
    {
        u8 *hero = h - 0x6C0;
        u8 *m = *(u8 **)(hero + 0x25C0);
        *(u128_t *)(h) = *(u128_t *)(m + 0xC0);
        *(u128_t *)(h + 0x10) = *(u128_t *)(m + 0xD0);
        *(u128_t *)(h + 0x20) = *(u128_t *)(m + 0xE0);
        qzero(hero + 0x6F0);
        *(f32 *)(hero + 0x6F0) = 1.0f;
        func_0038D000(h + 0x30, h + 0x30, h);
        *(u128_t *)(hero + 0x700) = *(u128_t *)(hero + 0x90);
        if (!hero[0x25F4])
            *(f32 *)(hero + 0x708) = func_0038DAB8(*(f32 *)(hero + 0x708), angle);
    }
}
/* localdecomp:end func_L01_004EAB10 */
