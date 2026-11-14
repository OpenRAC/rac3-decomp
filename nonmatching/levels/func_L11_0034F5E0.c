/* near miss (level 11, Obani Moons): func_L11_0034F5E0, 0xD7C bytes, checked with --as ps2as
 * (the owning file needs @ps2as in config/levels/text_parts.txt: retail expands 210000.0f,
 * 0.02f etc. as inline lui/ori/mtc1 instead of the -G8 literal pool).
 * Round 3: 470-word difference (72 aligned); func_L01_004713C8 declared
 * with the three floats before its last int (fixes the mov.s $f14 / $t3 order). Round 2: 474-word difference, compiled code 0xD8C (867 insns) vs retail 0xD7C (863; still +4).
 * 793 of the 867 instructions are already identical.
 * What changed from the first draft (all read off retail's asm):
 *  - the second func_L01_0046FB40 call passes v->f38 raw, not v->f38 | 0x7F000000;
 *  - the first func_L01_004713C8 call in the v->f20 loop passes v->f38 raw;
 *  - the v->f28 loop's third float argument is v->f14 * 2100.0f (no * 210000.0f);
 *  - the second func_003C4840 in the v->f30 loop rotates around &m->q0, not &m->q1;
 *  - the v->f2C loop uses 0.020000001f / 0.040000003f (0x3CA3D70B / 0x3D23D70B);
 *  - D_L11_001E15C0 is reached through a block-local byte pointer, so the base
 *    (0x1E15C0) lands in a register and the loads use 0x140/0x144;
 *  - the guarded loops are do/while, which drops the duplicate loop-entry test;
 *  - a `head` variable for the first heading and `heading` for the rotated one;
 *  - the two j-loops reuse `r0` (retail keeps that result in $a1);
 *  - f38 | 0x7F000000 goes through a local so both stores share one value.
 * Remaining: register allocation of the vel.z temporary (retail $f21), the counter/&vel
 * register swap ($s5/$s6) in the first loop, rematerialisation of &vel/&m->q1 in loops 2-4,
 * the alignment nop before the v->f30 loop, and scheduling. No div.s/sqrt.s is present
 * (only integer div), so nothing for config/levels/divs_nops.txt.
 */


typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34F5E0;

typedef struct {
    s16 f0, f2, f4;
    u8 pad6[2];
    f32 f8, fC, f10, f14;
    s32 f18, f1C, f20, f24, f28, f2C, f30, f34, f38;
} V_34F5E0;

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x68 - 0x1C];
    V_34F5E0 *v;
    u8 pad6C[0xC0 - 0x6C];
    V4_34F5E0 q0;
    V4_34F5E0 q1;
} M_34F5E0;

__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern u8 D_L11_001E15C0[];
extern u8 *D_L11_0021E558[];
extern u8 *D_L11_0021E6C8[];
__asm__(".extern D_L11_001DD328, 4");
extern f32 D_L11_001DD328;
__asm__(".extern D_L11_001DD32C, 4");
extern f32 D_L11_001DD32C;
__asm__(".extern D_L11_001DD330, 4");
extern s32 D_L11_001DD330;

extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_L01_002F9578(f32, void *, void *, void *, s32, u8, u8, u8, u8);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern void func_00382760(void *, f32, f32, f32);

void func_L11_0034F5E0(u8 *mb)
{
    M_34F5E0 *m = (M_34F5E0 *)mb;
    V_34F5E0 *v = m->v;
    V4_34F5E0 pos, vel, tmp;
    u8 *r0;
    f32 fa, fb, heading, vz;

    fa = D_L11_001DD328 * v->f14 * 210000.0f;
    fb = D_L11_001DD32C * v->f14 * 210000.0f;
    r0 = func_L01_0046FB40(&m->x, &D_L11_001D66B0, (D_L11_001DD330 * 5 + 2) / 6,
                           v->f38 | 0x7F000000, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L11_0021E6C8[0][0];
    }
    r0 = func_L01_0046FB40(&m->x, &D_L11_001D66B0, (D_L11_001DD330 * 5 + 2) / 6,
                           v->f38, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L11_0021E6C8[0][0];
    }
    {
        s32 j;
        for (j = 1; j >= 0; j--) {
            r0 = func_L01_0046FB40(&m->x, &D_L11_001D66B0, (D_L11_001DD330 * 5 + 2) / 6,
                                   v->f38 | 0x7F000000, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L11_0021E558[0x5C][5];
            }
        }
    }
    {
        s32 j;
        for (j = 1; j >= 0; j--) {
            r0 = func_L01_0046FB40(&m->x, &D_L11_001D66B0, (D_L11_001DD330 * 5 + 2) / 6,
                                   v->f38 | 0x7F000000, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L11_0021E558[0x5C][6];
            }
        }
    }
    if (v->f20 > 0) {
        s32 i, n, r;
        f32 head, heading, speed, mag;
        u8 *rr;
        u8 *hp = D_L11_001E15C0;
        i = 0;
        do {
            head = func_0038D160(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.6f, 1.0f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.z = 0.0f;
            vel.y = func_0038D0B0(heading) * mag;
            vz = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = vz * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, v->f38,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0058400002f, 1);
            rr = func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, v->f38 & 0xFFFFFF,
                                   -(r * 2), 0x30, 0x30, speed * 6.0f * 210000.0f,
                                   v->f14 * 0.02f * 210000.0f, 0.0058400002f, 0);
            if (rr != 0) {
                rr[2] = D_L11_0021E558[0x35][0];
            }
            i++;
        } while (i < v->f20);
    }
    if (v->f24 > 0) {
        s32 i, n, r;
        f32 head, heading, speed, mag;
        u8 *hp = D_L11_001E15C0;
        i = 0;
        do {
            head = func_0038D160(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.75f, 1.5f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.z = 0.0f;
            vel.y = func_0038D0B0(heading) * mag;
            vz = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = vz * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, v->f38 & 0xFFFFFF,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0058400002f, 5);
            i++;
        } while (i < v->f24);
    }
    if (v->f28 > 0) {
        s32 i, n, r;
        f32 head, heading, speed, mag;
        u8 *hp = D_L11_001E15C0;
        i = 0;
        do {
            head = func_0038D160(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.6f, 1.0f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.z = 0.0f;
            vel.y = func_0038D0B0(heading) * mag;
            vz = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = vz * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, v->f38 & 0xFFFFFF,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 2100.0f, 0.0058400002f, 3);
            i++;
        } while (i < v->f28);
    }
    if (v->f30 > 0) {
        s32 i;
        f32 speed, qa, qb;
        i = 0;
        do {
            u8 *rr;
            speed = func_003824E0(15.0f, 20.0f) * v->f14;
            func_0038CE20(&pos, &m->q0, speed * 0.020000001f);
            qa = func_L01_00443A18(0.2617994f, 1.3962634f);
            qb = func_L01_00443A18(0.2617994f, 1.3962634f);
            func_003C4840(&tmp, &m->q1, qa);
            func_0038D850(&vel, &pos, &tmp);
            func_003C4840(&tmp, &m->q0, qb);
            func_0038D850(&vel, &vel, &tmp);
            rr = func_L01_00470668(&m->x, &vel, (func_00382498(20, 35) * 5 + 2) / 6,
                                   0.0058400002f);
            if (rr != 0) {
                s32 flag = v->f38 | 0x7F000000;
                *(s32 *)(rr + 4) = flag;
                *(s32 *)(rr + 0xC) = flag;
            }
            i++;
        } while (i < v->f30);
    }
    if (v->f34 != 0) {
        *(u128_t *)&vel = 0;
        vel.z = v->f14 * 8.0f * 0.020000001f;
        pos = vel;
        func_L01_002F9578(v->f14 * 3.5f, mb, &m->x, &pos, 0xD,
                          v->f38, *(u8 *)((u8 *)v + 0x39), *(u8 *)((u8 *)v + 0x3A), 0x2D);
    }
    {
        s32 i, r;
        r = 1;
        func_L01_0044AF78(mb, &D_L11_001D66B0, &m->x, 0, 0, 0, -1, 0, 0, -1, 0, 0x1010001,
                          0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, v->f14 * 20.0f);
        i = 0;
        {
            u8 *hp = D_L11_001E15C0;
            heading = func_0038D160(*(f32 *)(hp + 0x140) - m->x,
                                    *(f32 *)(hp + 0x144) - m->y);
        }
    if (v->f2C > 0) {
        f32 speed, tilt, angle;
        do {
            u8 *rr;
            r = -r;
            pos.x = m->x + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            speed = func_003824E0(0.020000001f, 0.040000003f) * v->f14;
            tilt = func_L01_00443A18(0.0f, 1.3962634f);
            angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.5707964f));
            func_00382760(&vel, speed, angle, tilt);
            rr = func_L01_004669B0(0.0f, 1.0f, 1.01f, v->f14 * 1.5f * 210000.0f,
                                   &pos, r, &vel, v->f38 | 0x7F0000, 0);
            if (rr != 0) {
                u8 *q = rr + 0x20;
                rr[9] = 0x44;
                *(s16 *)(rr + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
                *(s32 *)(q + 4) = 3;
                q[0xA] = 0x40;
                *(f32 *)(q + 0x1C) = (func_00382498(1, 10) * 5 + 2) / 6;
                q[0xB] = rr[0xA];
            }
            i++;
        } while (i < v->f2C);
    }
    }
}
