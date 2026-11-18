/* PAL near miss (nm/b17-p2): the NTSC-U twin's draft (func_L01_0030EF98) ported to PAL: callees by PAL address, D_L01_002C5600, the
 * 50 Hz constants (0.040000003f, 0.080000006f, 0.020000001f = retail 0x3D23D70B/0x3DA3D70B/0x3CA3D70B). 5 diff words, but only with
 * `--mode S` (split addresses): retail's address pairs (lui/lui/addiu/addiu hoisted after the first call, map and tb in $s6/$s7) are
 * compiler-split hi/lo_sum pairs, so the file's `-mno-split-addresses` is wrong for this function (137 diff with it). The file's other
 * blocks are all assembly, so the whole line may change to `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (a line 939 other files
 * use); func_L01_003104B8 (a C block of the file) matches with split addresses too.
 * Left: in the `a2 == -1` branch retail has `lbu $v1,(v0); li $v0,0xF0; mult $a0,$v1,$v0; addu; lhu $a0,0x88($v1)`, ours
 * `li $v1,0xF0; lbu $v0; mult $a0,$v0,$v1; lhu $v0`: the li comes before the lbu (so the constant gets a different register) and the lhu
 * result lands in $v0 instead of the mult result's register. With separate locals for the index, the map value and the later
 * D_L01_001D673C copy ($a0/$v0/$v1 permute but never match). sched1 dump (tools/sched_explain.py logic, -fsched-verbose-5): after the call the
 * `li r=0xF0` and the `addu` become ready in the same cycle (the li depends on the call only), both issue on the two ALUs and the li is listed
 * second, so the order is addu, li, lbu and the constant overlaps the address register; retail's [addu, lbu, li] with c = $v0 needs the li to
 * be unavailable in that cycle (a second ALU insn with higher priority in the block, or a dependence), which no source form gave. Tried: nested subscripts, a u16/s32/u8 temp, a byte-offset form of
 * tb[t].w88, a pointer to the row, an explicit offset local, u32 index (all 5 or 6 diff). */
#include "common.h"
/* localdecomp:start func_L01_0030F288 */
typedef int s128_0030F288 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s32 i[0xA80]; u8 *ptr[0xA80]; s128_0030F288 q[0x2A0]; } Hero_0030F288;
typedef struct { u8 pad0[0x88]; u16 w88; u8 pad8A[0xF0 - 0x8A]; } RecF0_0030F288;
extern s32 D_L01_001D673C;
extern Hero_0030F288 D_001A4BE0;
extern u8 D_001425C0[];
extern RecF0_0030F288 D_L01_002C5600[];
extern s32 func_L01_00511950(s32);
extern f32 func_00382538(void);
extern void func_003C5180(void *, void *, s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004510A8(void *, void *, void *, s32, f32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 func_L01_00451580(void *);
extern void func_003C7C38(void *);
extern void func_L01_0044A7D0(void *);
extern void func_L01_0030EAE8(void);

u8 *func_L01_0030F288(void *a0, s32 a1, s32 a2, s32 a3) {
    RecF0_0030F288 *tb;
    u8 *map;
    f32 v20[4];
    f32 v30[4];
    f32 f20;
    u8 *r;
    u8 *s1;
    s32 t;

    func_L01_00511950(a1);
    map = D_001425C0;
    tb = D_L01_002C5600;
    *(s128_0030F288 *)v30 = 0;
    v30[2] = func_00382538();
    *(s128_0030F288 *)v20 = *(s128_0030F288 *)v30;
    if (D_L01_001D673C != 0) {
        func_003C5180(a0, v30, 1);
        v20[1] = func_0038D160(v30[2], func_0038CED8(v30));
        v20[2] = func_0038D160(v30[0], v30[1]);
    }
    func_L01_00443B88(v30, 0.040000003f, 0.080000006f);
    func_L01_004510A8(D_001A4BE0.ptr[0x25C0 / 4], v30, v30, 0, func_003824E0(4.0f, 8.0f) * 0.020000001f);
    f20 = func_003824E0(180.0f, 360.0f);
    r = func_L01_003F79D8(D_001A4BE0.ptr[0x25C0 / 4], 2, 0xCDB, 0, a0, v20, v30, 0xFF, f20,
                          func_003824E0(10.0f, 15.0f), 0xB4, 0, 0x80);
    if (r != 0) {
        r[0x20] = 1;
        *(void (**)(void))(r + 0x64) = func_L01_0030EAE8;
        s1 = *(u8 **)(r + 0x68);
        if (a2 == -1) {
            t = func_L01_00511950(a1); t = map[t];
            *(s32 *)(s1 + 0x60) = tb[t].w88;
        } else {
            *(s32 *)(s1 + 0x60) = a2;
        }
        t = D_L01_001D673C;
        *(s32 *)(s1 + 0x68) = a1;
        *(f32 *)(s1 + 0x6C) = (f32)a3;
        if (t != 0) {
            *(f32 *)(s1 + 0x74) = func_L01_00451580(r + 0x10);
        } else {
            *(f32 *)(s1 + 0x74) = *(f32 *)(r + 0x18);
        }
        func_003C7C38(r);
        func_L01_0044A7D0(r);
    }
    return r;
}
/* localdecomp:end func_L01_0030F288 */
