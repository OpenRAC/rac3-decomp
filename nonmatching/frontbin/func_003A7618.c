/* Near miss of func_003A7618 with its file's own flags: tools/check.py reports 4 diff
   (the version it replaces: 164).
   What differs: Only the D_001D4BB4 read differs (4 words): retail emits `addiu $sp,-0x60; lui
   $v0,0x1d; lw $v0,0x4bb4($v0)` (load destination coalesced with the %hi register, placed
   right after the frame setup), ours emits `lui $v0,0x1d` before the frame setup and `lw
   $v1,0x4bb4($v0)` / `sw $v1,-0x7d00($gp)` (separate %hi register $v0, load in $v1). The other
   three globals (D_001D9BC8, D_001D52E0, D_001D5B94) now match byte for byte: PAL reaches them
   absolutely (lui + offset), not through $gp, and the D_001D52E0 byte has to be loaded into a
   local before the buf[] stores for the compiler to schedule it...
*/

/* US draft of func_003A7618 (rac3-uya-decomp func_003A21C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override).

   PAL differences found: D_001D4BB4, D_001D9BC8, D_001D52E0 and D_001D5B94 are read/written
   through absolute addresses in the retail (lui + lw/lbu/sw with an offset), not through $gp. */


/* localdecomp:start func_003A7618 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0;
extern S_225780_3A21C0 D_00225700_003A7618;
extern u8 D_00160C40_003A88B8[];
extern u8 D_00142BA0[];
extern u8 D_001A30B0[];
extern u8 D_00143A07[];
extern u8 D_001D52E0;
extern u8 D_13D208[];
extern s32 D_002275EC[];
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern s32 D_001D5B94;
extern s32 D_001D9BC8;
/* PAL reaches some of these globals without $gp (lui/addiu + lw/sw), the US build used
   $gp for all of them; the array form of the declaration is what makes the compiler
   address them absolutely, the constant addresses below do the same. */
extern s32 D_001D4BB4_00389240[];
extern void func_003A1C28(void);
extern s32 func_003A8770(s32);
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_0038A238(s32);
extern void func_003A92F0(s32);
extern s32 func_12C908(s32);
extern void func_00387F68();
extern void func_003912E8(void);
extern void func_003A91D0();
extern void func_003A9150();
extern void func_11F0A0(s32);
extern void func_003A5430(void);
extern long func_13CDF0_003A7618(s32);
extern s32 func_13CD28(s32, s32, s32, void *);
extern void func_003A87D8(s32, s32, s32, s32);
extern u32 func_003A8830(s32, u32);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_12A9F0(s32, s32);
extern void func_12D4D8(u8 *);
extern void func_003A9108(void);
s32 func_003A7618(s32 arg) {
    s32 idx;
    u8 *q;
    s32 arr;
    s32 x;
    s32 a;
    s32 b;
    s32 *e;
    s32 base;
    s32 hi;
    s32 lo;
    u8 buf[4];
    s32 t;
    s32 one;
    t = *(s32 *)D_001D4BB4_00389240;
    one = 1;
    D_001D4BB0 = t;
    func_003A1C28();
    D_001D5B94 = one;
    if (arg >= 0) {
        u32 *p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
        *p |= one << (arg & 0x1F);
    }
    idx = func_003A8770(arg);
    q = D_00160C40_003A88B8;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    D_001A30B0[0x43] |= 8;
    a = *(s32 *)(x + arr) + *(s32 *)(q + 4);
    b = *(s32 *)(D_00160C40_003A88B8 + x + 0xC);
    D_00225700_003A7618.f4C = 0;
    D_00225700_003A7618.f34 = 0;
    func_13CF80(2, 0, 0, 0, 0);
    func_0038A238(4);
    func_003A92F0(1);
    func_12C908(0);
    D_001D9BC8 = *(s32 *)0x1D9BC8 + 1;
    func_00387F68();
    func_003912E8();
    func_003A91D0();
    func_003A9150();
    func_11F0A0(0);
    func_003A5430();
    func_003A1C28();
    func_11F0A0(0);
    func_003A5430();
    func_003A1C28();
    func_13CDF0_003A7618(0);
    e = (s32 *)((idx << 4) + arr);
    base = D_002275EC[0] - 0x2C0000;
    hi = base - 0x1E0000;
    lo = hi - 0x8000;
    if (*e != 0) {
        u8 c = *(u8 *)0x1D52E0;
        buf[0] = 100;
        buf[1] = c;
        buf[2] = 0;
        func_13CDF0_003A7618(0);
        func_13CD28(*e + *(s32 *)(q + 4), 0x10, lo, buf);
        func_13CDF0_003A7618(0);
        D_00225700_003A7618.f4C = lo;
    } else {
        D_00225700_003A7618.f4C = 0;
    }
    D_00225700_003A7618.f34 = 0;
    func_003A87D8(base, 0x2C0000, hi, 0x1E0000);
    one = func_003AF890(a, b, (s32 (*)(s32, s32))func_003A8830, D_00143A07[0], 0) != 0;
    func_12C908(0);
    func_12A9F0(0, 0);
    func_12D4D8(D_13D208);
    func_003A9108();
    func_0038A238(4);
    *(s32 *)0x1D5B94 = 6;
    D_001A30B0[0x43] |= 0x10;
    return one;
}
/* localdecomp:end func_003A7618 */
