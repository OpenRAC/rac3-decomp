/* near miss (level 5, Daxx), opus pass 2026-11-13: 4 differences, with the file's flags (L05_0032ADD0.c is already -mvu0-use-vf0-vf2 @ps2as). Before it goes in, give the later blocks' typedefs tags so the forward declarations here can name them: "typedef struct V4_32B290 {...} V4_32B290;" (func_L05_0032B290) and "typedef struct S_32B630 {...} S_32B630;" (func_L05_0032B630); both blocks still match with the tags. Left: in state 2 retail loads v[5] into $a0 and the D_L05_001DFC80 base into $v1 (the base load sits in the beq delay slot, so it came before the -1 test), ours uses $v1/$v0; a local id, "e = base; e += id << 7" inside an inner if, and "v[5] * 0x80" gave 4 or 11. What fixed the rest: "case 0: break;" first (retail's compare tree tests 1, then < 2, then 2 and 3); four function-scope vectors reused by both halves of state 2 (retail's 0x40 bytes of locals); v++ in the state-1 loop; "m = base; m += *v << 8" there; separate counters for the two loops, v[j] in the second; the x18 == 0 call in an else branch (cross-jumped with state 1's); the bit test as "((x >> j) ^ 1) & 1". */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_0032ADD0 */
struct V4_32B290;
struct S_32B630;
__asm__(".extern D_L05_001DFB9C, 4");
__asm__(".extern D_L05_001DFC80, 4");
extern u8 *D_L05_001DFB9C;
extern u8 *D_L05_001DFC80;
extern vu0_v4 D_L05_001E2700;
void func_L05_0032B230(void *);
void func_L05_0032B290(u8 *, u8 *, struct V4_32B290 *, f32);
void func_L05_0032B320(u8 *, s32, s32);
void func_L05_0032B630(struct S_32B630 *);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C2880(void *);

void func_L05_0032ADD0(u8 *o) {
    vu0_v4 t;
    vu0_v4 c;
    vu0_v4 up;
    vu0_v4 w;
    s32 *v;
    u8 *m;
    s32 i;
    s32 j;
    f32 sc;

    v = *(s32 **)(o + 0x68);
    func_L05_0032B230(o);
    switch (o[0x20]) {
    case 0:
        break;
    case 1:
        if (func_L01_00456250(o) == 0) {
            return;
        }
        for (i = 0; i < 5; i++) {
            if (*v != -1) {
                m = D_L05_001DFB9C;
                m += *v << 8;
                *(u16 *)(m + 0x34) |= 0x100;
                func_L05_0032B630((struct S_32B630 *)m);
                func_L01_00456230(m, 1);
            }
            v++;
        }
        func_003A52A0(1, 0, o);
        func_L01_004450F0((s32)o, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(o) != 0 && v[5] != -1) {
            u8 *e = D_L05_001DFC80 + (v[5] << 7);

            vec_sub_ba(v + 8, e + 0x30, o + 0x10);
            *(f32 *)(v + 10) = 0.0f;
            func_0038CF68(v + 8, v + 8, 1.0f);
            vec_sub_ba(&t, &D_L05_001E2700, o + 0x10);
            t.z = 0.0f;
            func_0038CF68(&t, &t, 1.0f);
            if (func_0038CE68(v + 8, &t) > 0.707f) {
                func_0038CE90(&c, &t, v + 8);
                *(vu0_q *)&up = 0;
                up.z = 1.0f;
                if (c.z > 0.0f) {
                    func_0038CE90(&w, &up, &t);
                } else {
                    func_0038CE90(&w, &t, &up);
                }
                vec_add_ab(v + 8, &w, &t);
            }
            func_0038CF68(v + 8, v + 8, 0.13000001f);
            func_0038CE90(v + 12, v + 8, o + 0xE0);
        }
        if (((u8 *)v)[0x18] != 0) {
            sc = 0.03316126f;
            *(vu0_q *)&c = 0;
            c.x = *(f32 *)(v + 8);
            c.y = *(f32 *)(v + 9);
            t = c;
            *(vu0_q *)&c = *(vu0_q *)(v + 8);
            if (*(f32 *)(o + 0x18) > 15.5f) {
                func_L05_0032B290(o, o, (struct V4_32B290 *)&c, sc);
                if (*(f32 *)(o + 0x18) <= 19.5f && (((u8 *)v)[0x19] & 0x20) == 0) {
                    func_L05_0032B320(o, (s32)o, 5);
                }
            }
            for (j = 0; j < 5; j++) {
                vec_add_ab(&c, &c, &t);
                sc *= 0.85f;
                if (v[j] != -1) {
                    m = D_L05_001DFB9C + (v[j] << 8);
                    if (*(f32 *)(m + 0x18) <= 19.5f && (((((u8 *)v)[0x19] >> j) ^ 1) & 1)) {
                        func_L05_0032B320(o, (s32)m, j);
                    }
                    if (*(f32 *)(m + 0x18) <= 15.5f) {
                        if ((((u8 *)v)[0x19] >> j) & 1) {
                            ((u8 *)v)[0x18] &= ~(1 << j);
                            func_003C2880(m);
                        }
                    } else {
                        func_L05_0032B290(o, m, (struct V4_32B290 *)&c, sc);
                    }
                }
            }
            *(f32 *)(v + 10) -= 0.00392f;
            *(f32 *)(v + 8) *= 0.976f;
            *(f32 *)(v + 9) *= 0.976f;
            if (*(f32 *)(v + 10) < -0.19f) {
                *(f32 *)(v + 10) = -0.19f;
            }
        } else {
            func_L01_004450F0((s32)o, 3, -1);
        }
        break;
    case 3:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L05_0032ADD0 */
